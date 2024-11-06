#
# Copyright (c) 2020-2024 The Johns Hopkins University Applied Physics
# Laboratory LLC.
#
# This file is part of the C code generator for AMP (CAMP) under the
# DTN Management Architecture (DTNMA) reference implementaton set from APL.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#     http://www.apache.org/licenses/LICENSE-2.0
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Portions of this work were performed for the Jet Propulsion Laboratory,
# California Institute of Technology, sponsored by the United States Government
# under the prime contract 80NM0018D0004 between the Caltech and NASA under
# subcontract 1658085.
#
''' This module creates the c file for the public version of the ADM.
'''

import os
from typing import TextIO
from camp.generators.lib import campch
from camp.generators.lib import camputil as cu
from camp.generators.lib import campsettings as cs
from camp.generators.base import AbstractWriter, CHelperMixin
from ace import models, typing, lookup


class Writer(AbstractWriter, CHelperMixin):

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.adm_name = self.adm.norm_name.lower().replace('-', '_')
        self._g_var_idx = "g_" + self.adm.norm_name.lower() + "_idx"

    def file_path(self) -> str:
        # Interface for AbstractWriter
        return os.path.join(self.out_path, "agent", f"adm_{self.adm.norm_name}_agent.c")

    def write(self, outfile: TextIO):
        # Interface for AbstractWriter
        campch.write_c_file_header(outfile, f"adm_{self.adm.norm_name}_agent.c")
        self.write_includes(outfile)

        #outfile.write("vec_idx_t {}[11];\n\n".format(self._g_var_idx))

        self.write_init_function(outfile)

        #write helpers
        self.write_set_type_function(outfile)
        self.write_add_param_function(outfile)
        self.write_init_constant_helper_function(outfile)
        self.write_init_edd_helper_function(outfile)
        self.write_init_var_helper_function(outfile)
        self.write_init_control_helper_function(outfile)

        #write init for objects
        self.write_init_constant_function(outfile)
        self.write_init_edd_function(outfile)
        #self.write_init_op_function(outfile) TODO: relook at when oper implemented in refda amm
        self.write_init_var_function(outfile)
        self.write_init_control_function(outfile)
        #self.write_init_tables_function(outfile) TODO: relook at when tblt implemented in refda amm

    #
    # Writes all of the #includes for this c file
    #
    # c_file is an open file descriptor to be written to
    # name is the name provided by get_adm_names()
    # retriever is the Retriever class instance for this data
    #
    def write_includes(self, outfile):
        files = [
            #"ion.h",
            #"platform.h",
            f"adm_{self.adm.norm_name}.h",
            #"shared/utils/utils.h",
            #"shared/primitives/report.h",
            #"shared/primitives/blob.h",
            f"adm_{self.adm.norm_name}_impl.h",
            #"agent/rda.h",
            "refda/agent.h",
            "refda/register.h",
            "refda/valprod.h",
            "refda/reporting.h",
            "cace/ari/text.h",
            "cace/util/logging.h",
            "cace/util/defs.h"
        ]
        outfile.write(campch.make_includes(files))

        # Adds #includes calls for all of the adms in the "uses"
        # construct of the ADM
#        files = campch.get_uses_h_files(retriever)
#        c_file.write(campch.make_includes(files))

    #
    # Constructs and writes the main init function for the agent file
    #
    # c_file is an open file descriptor to write to
    # name is the name returned by the call to get_adm_names()
    # retriever is the Retriever class instance for this ADM
    #
    def write_init_function(self, outfile):
        campch.write_init_function(outfile, self.adm, self._g_var_idx, False)
        

    #FIXME: when obj is custom type, sets obj to type typedef - how to get custom typedef obj id as int?
    #whether ari is reference vs literal may become more important depending on context
    def get_type_enum(self, obj):
        enum_template = 'ARI_TYPE_{0}'
        if hasattr(obj, 'init_ari'): #const, var
            ari = obj.init_ari
        elif hasattr(obj.typeobj, 'type_ari'): #edd
            ari = obj.typeobj.type_ari
        else: #tblt, union
            #print('Unhandled type for obj: ', obj, type(obj.typeobj))
            return enum_template.format('NULL')
        
        if hasattr(ari, 'type_id'): #literal
            if ari.type_id >= 17 and ari.type_id <=19: #container
                type_enum = enum_template.format(ari.type_id.name)
            else:
                type_enum = enum_template.format(ari.value.name)
        else: #reference
            obj = lookup.dereference(ari, lookup.object_session(self.adm))
            type_enum = obj.enum
        #print(obj.name, ari)
        #if hasattr(obj, 'enum'): print('\t', obj.enum)
        return type_enum

    #TODO: UPDATE DESCRIPTION
    #
    # Builds a template for the
    # ```
    # adm_add_...(adm_build_ari(...), ...)
    # ```
    # calls with passed collection type and adm name. Should be formatted in the calling
    # function with:
    # return_str.format([0|1](for whether params are present or not), ari_name, ari_amp_type, item[name], item[description])
    #
    # The intention behind this function is to only have to construct these parts once for each
    # collection. Subset of formatted values that need to be substituted for_each_ item in the
    # collection is much smaller.
    #
    # Only trivially different than the function of the same name in create_mgr_c.py
    #
    def make_std_meta_adm_build_template(self, coll, has_func=False):
        add_type = cs.get_sname(coll).lower()
        template = f"\n\t{self.adm_name}_init_{add_type}_helper(agent, adm, obj, " + "\"{0}\", {1}, {2}"
        template += ", {3});" if has_func else ");"
        return template

    def make_set_type_call(self, type):
        return f"\n\t{self.adm_name}_set_type(agent, {type}, type_enum);"

    def write_set_type_function(self, outfile):
        init_funct_string = (
            "void {0}_set_type(refda_agent_t *agent, amm_type_t *type, const ari_type_t type_enum)"
            "\n{{"
            "\n{1}\n"
            "\n}}"
            "\n\n")
        body = "\n\tconst amm_type_t *amm_type = amm_type_get_builtin(type_enum);\
                \n\tif (amm_type == NULL ){ //not found within builtin types"+\
                f"\n\t\tamm_type = refda_agent_get_typedef(agent, {cu.make_enum_name_from_str(self.adm.norm_name).replace('-', '_')}, type_enum);"+\
                "\n\t}\
                \n\tamm_type_set_use_direct(type, amm_type);"
        outfile.write(init_funct_string.format(self.adm_name, body))

    def write_init_container_template(self, ctype, body):
        return (
            "\n\t{"
            f"\n\t\tari_{ctype}_t {ctype}init;"
            f"\n\t\tari_{ctype}_init(&{ctype}init);"
            "\n\t\t{"
            f"\n\t\t\tari_t *item;"
            f"{body}"
            "\n\t\t}"
            f"\n\t\tari_set_{ctype}(&(objdata->value), &{ctype}init)"
            "\n\t}"
        )
    
    #TODO: verify support for am and tbl
    def write_container_body_template(self, ctype):
        if ctype == 'ac':
            c = 'list'
        elif ctype == 'am':
            c = 'tree'
        else: #tbl?
            c = None 
        return (
            f"\n\t\t\titem = ari_{c}_push_back_new({ctype}init.items);"
            f"\n\t\t\tari_set_objref_path_intid(item, {cu.make_enum_name_from_str(self.adm.norm_name).replace('-', '_')}" + ", {0}, {1});"
        )

    def make_add_param_template(self):
        return f"\n\t\t{self.adm_name}_add_param(agent, obj, \""+ "{0}\", {1});"

    def write_add_param_function(self, outfile):
        init_funct_string = (
            f"void {self.adm_name}_add_param(refda_agent_t *agent, cace_amm_obj_desc_t *obj, const char *name, const ari_type_t type_enum)"
            "\n{{"
            "{0}"
            "\n}}"
            "\n\n")
        body = f"\n\tcace_amm_formal_param_t *fparam = refda_register_add_param(obj, name);"+\
                self.make_set_type_call("&(fparam->typeobj)")
        outfile.write(init_funct_string.format(body))

    def write_init_constant_helper_function(self, outfile):
        coll = cs.CONST
        add_type = cs.get_sname(coll).lower()
        ttype = "_" + cs.get_sname(coll).replace("-","_")
        init_funct_string = (
            "refda_amm_const_desc_t *{0}_init{1}_helper(refda_agent_t *agent, cace_amm_obj_ns_t *adm, cace_amm_obj_desc_t *obj, const char *name, const ari_type_t type_enum, const int64_t obj_enum)"
            "\n{{"
            "\n{2}"
            "\n}}"
            "\n\n")
        body = f"\n\trefda_amm_{add_type}_desc_t *objdata = ARI_MALLOC(sizeof(refda_amm_{add_type}_desc_t));\
                \n\trefda_amm_{add_type}_desc_init(objdata);\
                \n\tamm_type_set_use_direct(&(objdata->value), amm_type_get_builtin(type_enum));\
                \n\tobj = refda_register_{add_type}(adm, cace_amm_obj_id_withenum(name, obj_enum), objdata);\
                \n\treturn objdata;\
                \n"

        outfile.write(init_funct_string.format(self.adm_name, ttype, body))

    #
    # Constructs and writes the init_constants function
    #
    # c_file is an open file descriptor to write to,
    # name is the value returned from get_adm_names()
    #
    def write_init_constant_function(self, outfile):
        body = ""
        add_str_template = self.make_std_meta_adm_build_template(cs.CONST)
        for obj in self.adm.const:
            type_enum = self.get_type_enum(obj)
            ace_type = eval(f"typing.StructType.{type_enum.rsplit('_', 1)[1]}")
            body += "\n\trefda_amm_const_desc_t *objdata = " + add_str_template.format(obj.name.lower(), type_enum, obj.enum)[2:]
            if  ace_type >= 17 or ace_type <= 19:
                #print(obj.name, type_enum, ace_type, ace_type.name.lower())
                ctype = ace_type.name.lower()
                cbody_template = self.write_container_body_template(ctype)
                cbody = ""
                for item in obj.init_ari.value:
                    #print('\t', item)
                    item_obj = lookup.dereference(item, lookup.object_session(self.adm))
                    item_type_enum = self.get_type_enum(item_obj)
                    cbody += cbody_template.format(item_type_enum, item_obj.enum)
                body += self.write_init_container_template(ctype, cbody)
            #TODO: params?
        campch.write_formatted_init_function(outfile, self.adm_name, cs.CONST, body)

    #
    # Constructs and writes the helper function for init_edd
    #
    # c_file is an open file descriptor to write to
    # name is the value returned from get_adm_names()
    #
    def write_init_edd_helper_function(self, outfile):
        coll = cs.EDD
        add_type = cs.get_sname(coll).lower()
        ttype = "_" + cs.get_sname(coll).replace("-","_")
        init_funct_string = (
            "void {0}_init{1}_helper(refda_agent_t *agent, cace_amm_obj_ns_t *adm, cace_amm_obj_desc_t *obj, const char *name, const ari_type_t type_enum, int64_t obj_enum, refda_amm_edd_produce_f prod_func)"
            "\n{{"
            "\n{2}"
            "\n}}"
            "\n\n")

        body = f"\n\trefda_amm_{add_type}_desc_t *objdata = ARI_MALLOC(sizeof(refda_amm_{add_type}_desc_t));\
                \n\trefda_amm_{add_type}_desc_init(objdata);"+\
                self.make_set_type_call("&(objdata->prod_type)")+\
                f"\n\tobjdata->produce = prod_func;\
                \n\tobj = refda_register_{add_type}(adm, cace_amm_obj_id_withenum(name, obj_enum), objdata);\
                \n"
                
        outfile.write(init_funct_string.format(self.adm_name, ttype, body))


    #
    # Constructs and writes the init_edd function
    #
    # c_file is an open file descriptor to write to
    # name is the value returned from get_adm_names()
    #
    def write_init_edd_function(self, outfile):
        body = ""
        add_str_template = self.make_std_meta_adm_build_template(cs.EDD, has_func=True)

        for obj in self.adm.edd:
            _,fname,_ = campch.make_collect_function(self.adm, obj)
            type_enum = self.get_type_enum(obj)
            body += add_str_template.format(obj.name.lower(), type_enum, obj.enum, fname)

            if obj.parameters and obj.parameters.items:
                body += "\n\t{"
                p_str_template = self.make_add_param_template()
                for p in obj.parameters.items:
                    type_enum = self.get_type_enum(p)
                    body += p_str_template.format(p.name.lower(), type_enum)
                body += "\n\t}"

        campch.write_formatted_init_function(outfile, self.adm_name, cs.EDD, body)


    #
    # Constructs and writes the init_operators function
    #
    # c_file is an open file descriptor to write to,
    # name is the value returned from get_adm_names()
    # operators is a list of operators to add
    #
    def write_init_op_function(self, outfile):
        body = ""
        adm_add_op_template = "\n\t"

        for obj in self.adm.oper:
            body += adm_add_op_template.format()

        campch.write_formatted_init_function(outfile, self.adm_name, cs.OP, body)

    #
    def write_init_var_helper_function(self, outfile):
        coll = cs.VAR
        add_type = cs.get_sname(coll).lower()
        ttype = "_" + cs.get_sname(coll).replace("-","_")
        init_funct_string = (
            "refda_amm_const_desc_t *{0}_init{1}_helper(refda_agent_t *agent, cace_amm_obj_ns_t *adm, cace_amm_obj_desc_t *obj, const char *name, const ari_type_t type_enum, const int64_t obj_enum)"
            "\n{{"
            "\n{2}"
            "\n}}"
            "\n\n")
        body = f"\n\trefda_amm_{add_type}_desc_t *objdata = ARI_MALLOC(sizeof(refda_amm_{add_type}_desc_t));\
                \n\trefda_amm_{add_type}_desc_init(objdata);\
                \n\tamm_type_set_use_direct(&(objdata->value), amm_type_get_builtin(type_enum));\
                \n\tobj = refda_register_{add_type}(adm, cace_amm_obj_id_withenum(name, obj_enum), objdata);\
                \n\treturn objdata;\
                \n"

        outfile.write(init_funct_string.format(self.adm_name, ttype, body))
    #
    # Writes the init_variables body
    #
    def write_init_var_function(self, outfile):
        body = ""
        add_str_template = self.make_std_meta_adm_build_template(cs.VAR)
        for obj in self.adm.var:
            type_enum = self.get_type_enum(obj)
            ace_type = eval(f"typing.StructType.{type_enum.rsplit('_', 1)[1]}")
            body += "\n\trefda_amm_const_desc_t *objdata = " + add_str_template.format(obj.name.lower(), type_enum, obj.enum)[2:]
            if  ace_type >= 17 or ace_type <= 19:
                #print(obj.name, type_enum, ace_type, ace_type.name.lower())
                ctype = ace_type.name.lower()
                cbody_template = self.write_container_body_template(ctype)
                cbody = ""
                for item in obj.init_ari.value:
                    #print('\t', item)
                    item_obj = lookup.dereference(item, lookup.object_session(self.adm))
                    item_type_enum = self.get_type_enum(item_obj)
                    cbody += cbody_template.format(item_type_enum, item_obj.enum)
                body += self.write_init_container_template(ctype, cbody)
            #TODO: params?
        campch.write_formatted_init_function(outfile, self.adm_name, cs.VAR, body)


    #
    # 
    def write_init_control_helper_function(self, outfile):
        coll = cs.CTRL
        add_type = cs.get_sname(coll).lower()
        ttype = "_" + cs.get_sname(coll).replace("-","_")
        init_funct_string = (
            "void {0}_init{1}_helper(refda_agent_t *agent, cace_amm_obj_ns_t *adm, cace_amm_obj_desc_t *obj, const char *name, const ari_type_t type_enum, int64_t obj_enum, refda_amm_edd_produce_f prod_func)"
            "\n{{"
            "\n{2}"
            "\n}}"
            "\n\n")
        body = f"\n\trefda_amm_{add_type}_desc_t *objdata = ARI_MALLOC(sizeof(refda_amm_{add_type}_desc_t));\
                \n\trefda_amm_{add_type}_desc_init(objdata);"+\
                f"\n\tobjdata->execute = prod_func;\
                \n\tobj = refda_register_{add_type}(adm, cace_amm_obj_id_withenum(name, obj_enum), objdata);\
                \n"
                
        outfile.write(init_funct_string.format(self.adm_name, ttype, body))

    #
    # Constructs and writes the init_controls function
    #
    # c_file is an open file descriptor to write to,
    # name is the value returned from get_adm_names()
    # controls is a list of controls to add
    #
    def write_init_control_function(self, outfile):
        body = ""
        add_str_template = self.make_std_meta_adm_build_template(cs.CTRL, True)

        for obj in self.adm.ctrl:
            _,fname,_ = campch.make_control_function(self.adm, obj)

            type_enum = self.get_type_enum(obj.result) if obj.result else 'ARI_TYPE_NULL'
            body += add_str_template.format(obj.name.lower(), type_enum, obj.enum, fname)

            if obj.parameters and obj.parameters.items:
                body += "\n\t{"
                p_str_template = self.make_add_param_template()
                for p in obj.parameters.items:
                    type_enum = self.get_type_enum(p)
                    body += p_str_template.format(p.name.lower(), type_enum)
                body += "\n\t}"

        campch.write_formatted_init_function(outfile, self.adm_name, cs.CTRL, body)

    #
    # Constructs and writes the init tables function
    #
    # c_file is an open file descriptor to write to
    # name is the name returned by the call to get_adm_names()
    # retriever is the Retriever class instance for this ADM
    #
    def write_init_tables_function(self, outfile):
        campch.write_init_tables_function(outfile, self.adm, self._g_var_idx, False)


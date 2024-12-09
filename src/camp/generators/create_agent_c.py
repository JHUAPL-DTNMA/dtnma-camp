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
        self.adm_name = cu.yang_to_c(self.adm.norm_name).lower()
        self._g_var_idx = "g_" + self.adm_name + "_idx"

    def file_path(self) -> str:
        # Interface for AbstractWriter
        return os.path.join(self.out_path, "agent", f"adm_{self.adm_name}_agent.c")

    def write(self, outfile: TextIO):
        # Interface for AbstractWriter
        campch.write_c_file_header(outfile, f"adm_{self.adm_name}_agent.c")
        self.write_includes(outfile)

        self.write_init_function(outfile)

        #write helpers
        self.write_set_type_function(outfile)
        self.write_add_param_function(outfile)

        #write init for objects
        self.write_init_constant_function(outfile)
        self.write_init_edd_function(outfile)
        self.write_init_op_function(outfile) #TODO: relook at when oper implemented in refda amm
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
            #f"adm_{self.adm.norm_name}.h",
            #"shared/utils/utils.h",
            #"shared/primitives/report.h",
            #"shared/primitives/blob.h",
            f"adm_{self.adm_name}_impl.h",
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

    def is_container(self, type_enum):
        return type_enum == typing.StructType.AC or type_enum == typing.StructType.AM or type_enum == typing.StructType.AC

    def get_ari_type(self, ari):
        if hasattr(ari, 'type_id'):
            if not ari.type_id:
                return None
            if self.is_container(ari.type_id): #container
                return ari.type_id
            else:
                return ari.value.name
        else: #reference
            obj = lookup.dereference(ari, lookup.object_session(self.adm))
            return obj

    def get_type_enum(self, obj):
        enum_template = 'ARI_TYPE_{0}'
        if hasattr(obj.typeobj, 'type_ari'): #edd
            ari = obj.typeobj.type_ari
        else: #tblt, union
            return enum_template.format('NULL')
        
        ari_type = self.get_ari_type(ari)
        ari_type = ari_type.name if isinstance(ari_type, typing.StructType) else ari_type
        type_enum = enum_template.format(ari_type) if isinstance(ari_type, str) else ari_type.enum
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
                \n\tif (amm_type == NULL){ //not found within builtin types"+\
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
            f"\n\t\t{campch.get_cace_func_name(ctype)}(&(objdata->value), &{ctype}init)"
            "\n\t}"
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

    #
    def deal_with_parameters(self, obj):
        body = ""
        if obj.parameters and obj.parameters.items:
                body += "\n\t{"
                p_str_template = self.make_add_param_template()
                for p in obj.parameters.items:
                    type_enum = self.get_type_enum(p)
                    body += p_str_template.format(p.name.lower(), type_enum)
                body += "\n\t}"
        return body

    #TODO: params?
    #recurse? AC of ACs
    #need to check type of obj and separately type of init_ari for container
        #this is because of typedefs like rptt
        #or should I include rptt in is_container and for new typedefs they use union with AC
    def deal_with_container(self, ctype, ari):
        if ctype == typing.StructType.AC:
            c = 'list'
        elif ctype == typing.StructType.AM:
            c = 'tree'
        else: #tbl?
            c = None 
        body = ""
        if ctype and self.is_container(ctype):
                ctype = ctype.name.lower()
                cbody = ""
                for item in ari.value:
                    cbody += f"\n\t\t\titem = ari_{c}_push_back_new({ctype}init.items);"
                    item_type_enum = self.get_ari_type(item)
                    if isinstance(item_type_enum, str): #non-container literal
                        cbody += f"\n\t\t\t{campch.get_cace_func_name(item_type_enum.rsplit('_', 1)[1])}(item, {item.value});"
                    elif isinstance(item_type_enum, typing.StructType): #container
                        pass
                    elif item_type_enum: #ref
                        item_obj = lookup.dereference(item, lookup.object_session(self.adm))
                        cbody += f"\n\t\t\tari_set_objref_path_intid(item, {cu.make_enum_name_from_str(self.adm.norm_name).replace('-', '_')}, ARI_TYPE_{type(item_type_enum).__name__.upper()}, {item_obj.enum});"

                body += self.write_init_container_template(ctype, cbody)
        return body

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
        self.write_init_constant_helper_function(outfile)
        
        body = ""
        add_str_template = self.make_std_meta_adm_build_template(cs.CONST)
        for obj in self.adm.const:
            type_enum = self.get_type_enum(obj)
            body += "\n\trefda_amm_const_desc_t *objdata = " + add_str_template.format(obj.name.lower(), type_enum, obj.enum)[2:]
            val_type = self.get_ari_type(obj.init_ari)
            if isinstance(val_type, models.Typedef): #value is typedef ari?
                pass
            elif self.is_container(val_type):
                body += self.deal_with_container(val_type, obj.init_ari)
            else:
                obj_type = type_enum.rsplit('_', 1)[1] if isinstance(type_enum, str) else type_enum.name
                body += "\n\t{\n\t\t"+f"{campch.get_cace_func_name(obj_type)}(&(objdata->value), {obj.init_value})"+"\n\t}"
            body += self.deal_with_parameters(obj)
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
        self.write_init_edd_helper_function(outfile)

        body = ""
        add_str_template = self.make_std_meta_adm_build_template(cs.EDD, has_func=True)

        for obj in self.adm.edd:
            _,fname,_ = campch.make_collect_function(self.adm, obj)
            type_enum = self.get_type_enum(obj)
            body += add_str_template.format(obj.name.lower(), type_enum, obj.enum, fname)

            body += self.deal_with_parameters(obj)

        campch.write_formatted_init_function(outfile, self.adm_name, cs.EDD, body)


    #
    def write_init_op_helper_function(self, outfile):
        coll = cs.OP
        add_type = cs.get_sname(coll).lower()
        ttype = "_" + cs.get_sname(coll).replace("-","_")
        init_funct_string = (
            "void {0}_init{1}_helper(refda_agent_t *agent, cace_amm_obj_ns_t *adm, cace_amm_obj_desc_t *obj, const char *name, const ari_type_t type_enum, int64_t obj_enum, int (*evaluate)(const refda_amm_oper_desc_t *obj, refda_eval_ctx_t *ctx))"
            "\n{{"
            "\n{2}"
            "\n}}"
            "\n\n")
        body = f"\n\trefda_amm_{add_type}_desc_t *objdata = ARI_MALLOC(sizeof(refda_amm_{add_type}_desc_t));\
                \n\trefda_amm_{add_type}_desc_init(objdata);"+\
                self.make_set_type_call("&(objdata->res_type)")+\
                f"\n\tobjdata->evaluate = evaluate;\
                \n\tobj = refda_register_{add_type}(adm, cace_amm_obj_id_withenum(name, obj_enum), objdata);\
                \n"
                
        outfile.write(init_funct_string.format(self.adm_name, ttype, body))

    #
    # Constructs and writes the init_operators function
    #
    # c_file is an open file descriptor to write to,
    # name is the value returned from get_adm_names()
    # operators is a list of operators to add
    #
    def write_init_op_function(self, outfile):
        self.write_init_op_helper_function(outfile)

        body = ""
        add_str_template = self.make_std_meta_adm_build_template(cs.OP, has_func=True)

        for obj in self.adm.oper:
            _,fname,_ = campch.make_operator_function(self.adm, obj)
            type_enum = self.get_type_enum(obj.result)
            body += add_str_template.format(obj.name.lower(), type_enum, obj.enum, fname)

            #TODO: relook at when operand types are handled
            """
            if obj.operands and obj.operands.items:
                body += "\n\t{"
                p_str_template = f"\n\t\t{self.adm_name}_add_operand();"
                for p in obj.operands.items:
                    type_enum = self.get_type_enum(p)
                    body += p_str_template.format(p.name.lower(), type_enum)
                body += "\n\t}"
            """

            body += self.deal_with_parameters(obj)


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
    # for each variable creates a lyst for its postfix-expr and writes
    # its appropriate adm_add_var function
    #
    def write_init_var_function(self, outfile):
        self.write_init_var_helper_function(outfile)

        body = ""
        add_str_template = self.make_std_meta_adm_build_template(cs.VAR)
        for obj in self.adm.var:
            type_enum = self.get_type_enum(obj)
            body += "\n\trefda_amm_const_desc_t *objdata = " + add_str_template.format(obj.name.lower(), type_enum, obj.enum)[2:]
            if obj.init_ari:
                val_type = self.get_ari_type(obj.init_ari)
                if isinstance(val_type, models.Typedef): #value is typedef ari?
                    pass
                elif self.is_container(val_type):
                    body += self.deal_with_container(val_type, obj.init_ari)
                else:
                    obj_type = type_enum.rsplit('_', 1)[1] if isinstance(type_enum, str) else type_enum.name
                    body += "\n\t{\n\t\t"+f"{campch.get_cace_func_name(obj_type)}(&(objdata->value), {obj.init_value})"+"\n\t}"
        campch.write_formatted_init_function(outfile, self.adm_name, cs.VAR, body)


    #
    # 
    def write_init_control_helper_function(self, outfile):
        coll = cs.CTRL
        add_type = cs.get_sname(coll).lower()
        ttype = "_" + cs.get_sname(coll).replace("-","_")
        init_funct_string = (
            "void {0}_init{1}_helper(refda_agent_t *agent, cace_amm_obj_ns_t *adm, cace_amm_obj_desc_t *obj, const char *name, const ari_type_t type_enum, int64_t obj_enum, int (*execute)(const refda_amm_ctrl_desc_t *obj, refda_exec_ctx_t *ctx))"
            "\n{{"
            "\n{2}"
            "\n}}"
            "\n\n")
        body = f"\n\trefda_amm_{add_type}_desc_t *objdata = ARI_MALLOC(sizeof(refda_amm_{add_type}_desc_t));\
                \n\trefda_amm_{add_type}_desc_init(objdata);"+\
                self.make_set_type_call("&(objdata->res_type)")+\
                f"\n\tobjdata->execute = execute;\
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
        self.write_init_control_helper_function(outfile)

        body = ""
        add_str_template = self.make_std_meta_adm_build_template(cs.CTRL, True)

        for obj in self.adm.ctrl:
            _,fname,_ = campch.make_control_function(self.adm, obj)

            type_enum = self.get_type_enum(obj.result) if obj.result else 'ARI_TYPE_NULL'
            body += add_str_template.format(obj.name.lower(), type_enum, obj.enum, fname)
            body += self.deal_with_parameters(obj)

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


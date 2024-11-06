
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

import os
import re
import datetime
import ace.models
from . import campsettings as cs
from . import camputil as cu


##################### FUNCTIONS FOR COMMENTS AND HEADERS #####################

#
# Writes the standard c file header to the file
#
# fd: open file descriptor to write to
# filepath: the path to the of the file, where the basename will be included
# as part of the header
#
def write_c_file_header(fd, filepath):
    _write_file_header(fd, filepath, "c")

#
# Writes the standard .h file header to the file
#
# fd: open file descriptor to write to
# filepath: the path to the of the file, where the basename will be included
# as part of the header
#
def write_h_file_header(fd, filepath):
    _write_file_header(fd, filepath, "header")

#
# Writes the standard file header to the file
#
# fd: open file descriptor to write to
# filepath: the path to the of the file, where the basename will be included
# as part of the header
# modifier: string indicating type of file this is ('c' or 'header' are common values)
#
def _write_file_header(fd, filepath, modifier):
    standard_header = """\
/****************************************************************************
 **
 ** File Name: {0}
 **
 ** Description: TODO
 **
 ** Notes: TODO
 **
 ** Assumptions: TODO
 **
 ** Modification History:
 **  YYYY-MM-DD  AUTHOR           DESCRIPTION
 **  ----------  --------------   --------------------------------------------
 **  {1}  AUTO             Auto-generated {2} file
 **
 ****************************************************************************/

"""
    fd.write(standard_header.format(os.path.basename(filepath), str(datetime.datetime.now().date()), modifier))



#################### FUNCTIONS FOR #INCLUDES ###########################

#
# Given a list of files, creates the string neccessary to #include all of
# them in a .[ch] file
# Returns the completed string.
#
def make_includes(files):
    out = ""
    for f in files:
        out += "\n#include \"{}\"".format(f)
    out += "\n\n"

    return out

#
# Returns a list of the .h files that need to be included for the 'uses'
# construct in the JSON to work.
# name expected for #include declarations.
# Returns a list of correctly-formatted files, to be passed to make_includes()
#
def get_uses_h_files(retriever):
    uses = retriever.get_uses()
    formatted_uses = [f.lower().replace("/", "_") for f in uses]
    files = ["adm_{}.h".format(f) for f in formatted_uses]
    return files



############################ C-BASED UNTAINTING FUNCTIONS ##################################

#
# Takes the passed string, and adds c comment characters to make it
# print(well as a multi-line comment in a c file)
#
def multiline_comment_format(tainted):
    comment_width = 100

    # replace any comment-ending characters with empty string
    tainted = re.sub(r'\*/', '', tainted)

    # replace newline with newline + comment character
    tainted = re.sub('\\n', '\\n *', tainted)

    # split the lines every x characters to wrap
    tainted_list = tainted.splitlines()
    untainted = []
    for line in tainted_list:
        while len(line) > comment_width:
            left, right = line[:comment_width], line[comment_width:]
            untainted.append("\n * " + left)
            line = right
        untainted.append("\n * " + line)

    # Add opening and closing comment characters
    untainted = ("/*" + "".join(untainted) + "\n */")
    return untainted

#
# Helper function to make and return a string for wide comment headers
#
# name is the string to be put in the comment header
# if c_open is True, adds opening comment indicator (/*) to beginning of returned string
# if c_close is True, adds closing comment indicator (*/) to end of returned string
# When c_open == c_close == True, returns:
# ```
# /*
#  * +-----------+
#  * |    name   +
#  * +-----------+
#  */
# ```
# spaced to 112 characters-wide
#
def make_formatted_comment_header(name, c_open, c_close):
    width_sans_ends = 93

    # This is the `* +---[...]---+` string that can be found at the beginning and end
    envelope_str = "\n * +" + ('-' * width_sans_ends) + "+\n"

    name_len = len(name)
    # This is the `* |   name    +` string to be surrounded by envelope str
    white_space  = (" " * int((width_sans_ends - len(name) ) / 2))

    content_str  = " * |" + white_space + name + white_space
    if(name_len % 2 == 0) :
        content_str +=" "
    content_str += "+"


    out = envelope_str + content_str + envelope_str

    if c_open :
        out = "\n/*" + out
    if c_close:
        out += " */\n"
    return out



############################# FUNCTIONS SHARED BY IMPL_C and IMPL_H ###############################

#
# Makes and returns the basename, fullname, and signature tuple for the edd
# collect functions; where basename = edd_<edd-name> and fullname = <name>_<basename>
#
def make_collect_function(adm, edd):
    basename = "get_{}".format(edd.name.lower().replace('-', '_'))
    fullname = "{0}_{1}".format(adm.norm_name.lower().replace('-', '_'), basename.replace('-', '_'))
    signature = "void {}(const refda_amm_edd_desc_t *obj _U_, refda_valprod_ctx_t *ctx)".format(fullname)
    return basename, fullname, signature

#
# Makes and returns the basename, fullname, and signature tuple for the constant
# function; where basename = <keyword>_<const-name> and fullname = <name>_<basename>
#
def make_constant_function(adm, const):
    keyword = "get"
    basename = "{0}_{1}".format(keyword, const.name.lower())
    fullname = "{0}_{1}".format(adm.norm_name.lower().replace('-', '_'), basename.replace('-', '_'))
    signature = "void {}(const refda_amm_const_desc_t *obj _U_, refda_valprod_ctx_t *ctx)".format(fullname)
    return basename, fullname, signature

#
# Makes and returns the basename, fullname, and signature tuple for the control
# functions; where basename = <keyword>_<control-name> and fullname = <name>_<basename>
#
def make_control_function(adm, control):
    keyword = cs.get_sname(cs.CTRL)
    basename = "{0}_{1}".format(keyword, control.name.lower())
    fullname = "{0}_{1}".format(adm.norm_name.lower().replace('-', '_'), basename.replace('-', '_'))
    signature = "int {}(const refda_amm_ctrl_desc_t *obj _U_, refda_exec_ctx_t *ctx)".format(fullname)
    return basename, fullname, signature

#
# Makes and returns the basename, fullname, and signature tuple for the operator
# functions; where basename = <keyword>_<op-name> and fullname = <name>_<basename>
#
def make_operator_function(adm, op):
    keyword = cs.get_sname(cs.OP)
    basename = "{0}_{1}".format(keyword, op.name.lower())
    fullname = "{0}_{1}".format(adm.norm_name.lower().replace('-', '_'), basename.replace('-', '_'))
    signature = "void {}()".format(fullname)
    return basename, fullname, signature

#
# Makes and returns the basename, fullname, and signature tuple for the table
# functions; where basename = tbl_<tbl-name> and fullname = <name>_<basename>
#
def make_table_function(adm, tbl):
    keyword = cs.get_sname(cs.TBLT)
    basename = "{0}_{1}".format(keyword, tbl.name.lower())
    fullname = "{0}_{1}".format(adm.norm_name.lower().replace('-', '_'), basename.replace('-', '_'))
    signature = "void {}()".format(fullname)
    return basename, fullname, signature



##################### FUNCTIONS SHARED BY CREATE_MGR.PY AND CREATE_AGENT.PY ###################

#
# Makes the adm_build_ari(..) template for the passed collection type and
# g_*_idx
# Caller should format the template with returned_str.format([0|1](whether params are present), ari_name)
#
# standalone is a boolean whether or not the call needs to stand alone. If False, the call should be used
# as an argument to another function.
#
def make_adm_build_ari_template(coll, g_var_idx, standalone):
    amp_type = cs.get_amp_type(coll)
    idx_type = cs.get_adm_idx(coll)

    template = "adm_build_ari("+amp_type+", {0}, " + g_var_idx + "["+idx_type+"], {1})"
    if standalone:
        template = "\n\tid = " + template + ";"
    return template

#
# Writes an init function to the passed c_file.
# name is the name returned by a call to initialize_names,
# coll is the collection to make the init function for. Can be None
# body is the body of the function.
#
def write_formatted_init_function(c_file, name, coll, body):
    ttype = None
    if coll is not None:
        ttype = "_" + cs.get_sname(coll).replace("-","_")
    else:
        ttype = ""

    if coll != None:
        init_funct_string = (
            "void {0}_init{1}(refda_agent_t *agent, cace_amm_obj_ns_t *adm, cace_amm_obj_desc_t *obj)"
            "\n{{"
            "\n{2}"
            "\n}}"
            "\n\n")
    else:
        init_funct_string = (
            "int {0}_init{1}(refda_agent_t *agent)"
            "\n{{"
            "\n{2}"
            "\n}}"
            "\n\n")

    c_file.write(init_funct_string.format(name, ttype, body))


# Builds a template for the
# ```
# meta_add_...
# ```
# calls with passed collection type and adm name. Should be formatted in the calling
# function with:
# return_str.format(ari_amp_type, item[name], item[description])
#
# The intention behind this function is to only have to construct these parts once for each
# collection. Only a subset of values that need to be substituted for_each_ item in the
# collection, formatting ones related to coll and name here.
#
def make_std_meta_add_coll_template(coll, name):
    enum_name = cu.make_enum_name_from_str(name)
    coll_name = 'cnst' if coll == cs.META else cs.get_sname(coll).lower()
    return "meta_add_" + coll_name + "({0}, id, " + enum_name + ", \"{1}\", \"{2}\");\n"

#
# Writes the init_tables funtion for the passed adm name and
# retriever class instance.
#
def write_init_tables_function(c_file, adm, g_var_idx, mgr):
    body = ""
    tbl_decl_str        = "\n\ttblt_t *def = NULL;"
    tbl_create_template = "\n\tdef = tblt_create({0}, {1});"

    build_ari_template = make_adm_build_ari_template(cs.TBLT, g_var_idx, False)
    enum_name = cu.make_enum_name_from_str(adm.norm_name)

    add_tblt_str      = "\n\tadm_add_tblt(def);"
    meta_add_template = "\n\tmeta_add_tblt(def->id, " + enum_name + ", \"{0}\", \"{1}\");"
    add_col_template  = "\n\ttblt_add_col(def, {0}, \"{1}\");"

    added_table = False

    for obj in adm.tblt:
        # Preliminaries
        ari = cu.make_ari_name(adm.norm_name, cs.TBLT, obj)
        tbl_name    = obj.name
        description = obj.description or ''

        cols = obj.columns.items if obj.columns else []
        cols_str = ""

        # Format the templates needed for the tables function
        tbl_build_ari_str = build_ari_template.format("0", ari)

        # The appearance of this template depends on whether this is the mgr code or not
        if mgr:
            tbl_create_str = tbl_create_template.format(tbl_build_ari_str, "NULL")
        else:
            tbl_create_str = tbl_create_template.format(tbl_build_ari_str, ari.lower())

        # Add to the cols string for each column present
        for col in cols:
            c_amp_type = cu.make_amp_type_name_from_str(col.type)
            cols_str += add_col_template.format(c_amp_type, col.name)

        # Add formatted strings to the body
        body += "\n\n\t/* {} */\n".format(tbl_name.upper())
        body += tbl_create_str
        body += cols_str
        body += add_tblt_str

        added_table = True

        # If this the the mgr code generation, also need to call meta_add function
        if mgr:
            body += meta_add_template.format(tbl_name, description)

    # tbl variable is only declared if needed; in order to avoid C compiler warnings for unused variable
    if added_table:
        body = tbl_decl_str + body

    write_formatted_init_function(c_file, adm.norm_name.replace('-', '_'), cs.TBLT, body)

#
# Writes the init function to c_file
#
def write_init_function(c_file, adm: ace.models.AdmModule, g_var_idx: str, mgr: bool):
    enum_name = cu.make_enum_name_from_str(adm.norm_name).replace('-', '_')
    
    adm_register        = f'\tCHKERR1(agent);\n\
                            \n\tcace_amm_obj_ns_t *adm = cace_amm_obj_store_add_ns(&(agent->objs), "{adm.norm_name}", true, {enum_name});\n'
    adm_obj_lock        = "\n\tif (pthread_mutex_lock(&(agent->objs_mutex))){\n\t\treturn 2;\n\t}\n"
    init_obj_pointer    = "\n\t\tcace_amm_obj_desc_t *obj;"
    init_decl_template = "static void " + adm.norm_name.replace('-', '_') + "_init_{0}(refda_agent_t *agent, cace_amm_obj_ns_t *adm, cace_amm_obj_desc_t *obj);\n"
    init_call_template = "\n\t\t" + adm.norm_name.replace('-', '_') + "_init_{0}(agent, adm, obj);"
    adm_obj_unlock      = "\n\tif (pthread_mutex_unlock(&(agent->objs_mutex))){\n\t\treturn 2;\n\t}\n"

    # order of init functions matters
    obj_types = {
        #cs.META: 'mdat',
        cs.CONST: 'const',
        cs.EDD: 'edd',
        cs.OP: 'oper',
        cs.VAR: 'var',
        cs.CTRL: 'ctrl',
        #cs.TBLT: 'tblt', TODO: Add back once implemented
    }

    init_decls = ""
    init_calls = ""
    if not mgr:
        init_calls = "\n\t\t" + adm.norm_name.replace('-', '_') + "_setup();"

    for coll, attrname in obj_types.items():
        init_decls += init_decl_template.format(cs.get_sname(coll).lower())

        # only generate NN's for elements that appear in the ADM
        #if getattr(adm, attrname):  adm_register += vdb_add_template.format(cs.get_adm_idx(coll), g_var_idx)

        init_calls += init_call_template.format(cs.get_sname(coll).lower())

    body = adm_register + adm_obj_lock + "\n\tif (adm)\n\t{" + init_obj_pointer + init_calls + "\n\t}\n" + adm_obj_unlock

    c_file.write(init_decls + "\n")
    write_formatted_init_function(c_file, adm.norm_name.replace('-', '_'), None, body)

def make_cplusplus_open():
    ''' Open an "extern C" block for C++ inclusion. '''
    return """\
#ifdef __cplusplus
extern "C" {
#endif

"""

def make_cplusplus_close():
    ''' Close  an "extern C" block for C++ inclusion. '''
    return """\

#ifdef __cplusplus
}
#endif
"""

#
# Copyright (c) 2020-2025 The Johns Hopkins University Applied Physics
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
import io
import logging
import ace.models
import jinja2
import math
import textwrap
from typing import Union, Optional
import ace
from ace.typing import BUILTINS
from ace import models, ari, ari_text
from ace.lookup import dereference, ORM_TYPE
from datetime import datetime, timedelta, timezone

LOGGER = logging.getLogger(__name__)

AdmEntity = Union[models.AdmModule, models.AdmObjMixin]
''' Either an ADM itself or an AMM object defined within one. '''


def yang_to_c(identifier):
    ''' Translates a valid YANG identifier to a valid C99 symbol name.
    '''
    return identifier.replace('_', '__').replace('-', '_').replace('.', '_p_')


def yang_to_sql(identifier):
    ''' Translates a valid YANG identifier to a valid SQL symbol name.
    '''
    if identifier:
        return identifier.replace('-', '_').replace('.', '_p_')
    return ""


def update_jinja_env(env:jinja2.Environment, admset, sym_prefix:str):
    ''' Set state of a jinja environment for ADM implementation
    source generation.
    '''
    REVERSE_MAP = {val: key for key, val in ORM_TYPE.items()}

    def amm_obj_type(obj:models.AdmObjMixin) -> ari.StructType:
        return REVERSE_MAP[type(obj)]

    def cpp_header(adm:models.AdmModule) -> str:
        ''' Get the header name for a module.
        The symbol prefix is not part of the file name.
        '''
        return yang_to_c(adm.module_name).lower() + '.h'

    def cpp_guard(adm:models.AdmModule) -> str:
        ''' Get the header guard for a module.
        '''
        return '_'.join([sym_prefix, yang_to_c(adm.module_name), 'H_']).upper()

    def cpp_enum(value:AdmEntity) -> str:
        ''' Map from ORM and YANG names into C preprocessor define name.
        '''
        if isinstance(value, ari.StructType):
            return 'CACE_ARI_TYPE_' + value.name
        elif isinstance(value, models.AdmModule):
            module = value
            parts = ['adm']
        elif isinstance(value, models.AdmObjMixin):
            module = value.module
            parts = ['objid', amm_obj_type(value).name, yang_to_c(value.name)]
        return '_'.join([sym_prefix, yang_to_c(module.module_name), 'enum'] + parts).upper()

    def c_func(value:AdmEntity, suffix:Optional[str]=None) -> str:
        ''' Map from ORM and YANG names into C function symbol name.
        '''
        if isinstance(value, models.AdmModule):
            parts = [yang_to_c(value.module_name)]
        elif isinstance(value, models.AdmObjMixin):
            parts = list(map(yang_to_c, [value.module.module_name, amm_obj_type(value).name, value.name]))
        if suffix:
            parts.append(suffix)
        return '_'.join([sym_prefix] + parts).lower()

    def c_comment(value:str) -> str:
        ''' Wrap a multi-line text value as a C multiline comment.
        Indentation outside or inside is done with a separate filter.
        '''
        newl = env.newline_sequence
        lines = value.strip(newl).split(newl)
        buf = '/* ' + lines.pop(0)
        for line in lines:
            buf += newl + ' *'
            if line:
                buf += ' ' + line
        buf += newl + ' */'
        return buf

    def c_bool(value) -> str:
        ''' Enforce a boolean value in C99 source.
        '''
        return 'true' if bool(value) else 'false'

    def c_int(value) -> str:
        ''' Enforce an integer value in C source.
        '''
        return f'{int(value):d}'

    def c_float(value) -> str:
        ''' Enforce an floating point value in C source.
        '''
        return f'{float(value):e}'

    def c_str(value:str) -> str:
        ''' Enforce an escaped text string in C source.
        '''
        return '"' + str(value).replace('\\', '\\\\').replace('"', '\\"').replace("'", "\\'") \
            .replace("\a", "\\a").replace("\b", "\\b").replace("\f", "\\f").replace("\n", "\\n") \
            .replace("\r", "\\r").replace("\t", "\\t").replace("\v", "\\v") + '"'

    def c_bytes_init(value:bytes) -> str:
        ''' Encode a byte string as a sequence of uint8_t values
        within an array initializer.
        '''
        return '{' + ', '.join([hex(part) for part in value]) + '}'

    def rewrap(value:str, prefix:str='\n'):
        ''' Unwrap and re-wrap text along word bounaries.
        '''
        return prefix.join(textwrap.wrap(value))

    def as_text(ari:ari.ARI) -> str:
        ''' Encode an ARI as text form URI.
        '''
        enc = ari_text.Encoder()
        buf = io.StringIO()
        enc.encode(ari, buf)
        return buf.getvalue()

    def as_timepoint(value:datetime) -> str:
        diff = value - ari.DTN_EPOCH
        tv_sec = diff.seconds + 24 * 60 * 60 * diff.days
        tv_nsec = 1000 * diff.microseconds  # Convert to nanoseconds
        return f"{{{tv_sec}, {tv_nsec}}}"

    def as_timedelta(value:timedelta) -> str:
        tv_sec = value.seconds + 24 * 60 * 60 * value.days
        tv_nsec = 1000 * value.microseconds  # Convert to nanoseconds
        return f"{{{tv_sec}, {tv_nsec}}}"

    def ref_text(obj:models.AdmObjMixin) -> str:
        ''' Create a text reference for an AMM object.
        '''
        return f'./{amm_obj_type(obj).name}/{obj.norm_name}'

    def deref(ari:ari.ARI) -> models.AdmObjMixin:
        ''' Dereference an ARI into an AMM object.
        '''
        LOGGER.debug('deref from %s', ari)
        return dereference(ari, admset.db_session())

    def ari_builtin(ari:ari.ARI, typename:str) -> bool:
        typeobj = BUILTINS[typename]
        got = typeobj.get(ari)
        return got is not None

    def sql_name(value:str) -> str:
        ''' valid sql name
        '''
        return  yang_to_sql(value).lower()

    def sql_var_name(obj:ace.models.AdmObjMixin) -> str:
        ''' formatting a name to be a sql variable
        '''
        if obj:
            return yang_to_sql(obj.__tablename__).lower() + "_" + yang_to_sql(obj.name).lower()
        return "None"

    def sql_string(value:str) -> str:
        ''' escape string and add quotes for sql
        '''
        if value:
            return  '\'' + value.replace('\\', '\\\\').replace("'", ' `').replace('\n', ' ') + '\''
        else:
            return '\'\''

    env.globals |= {
        'ari': ace.ari,
        'typing': ace.typing,
    }
    env.filters |= {
        'cpp_header': cpp_header,
        'cpp_guard': cpp_guard,
        'cpp_enum': cpp_enum,
        'c_func': c_func,
        'c_comment': c_comment,
        'c_bool': c_bool,
        'c_int': c_int,
        'c_float': c_float,
        'c_str': c_str,
        'c_bytes_init': c_bytes_init,
        'rewrap': rewrap,
        'as_text': as_text,
        'as_timepoint': as_timepoint,
        'as_timedelta': as_timedelta,
        'ref_text': ref_text,
        'deref': deref,
        'sql_name': sql_name,
        'sql_string': sql_string,
        'sql_var_name': sql_var_name,

    }
    env.tests |= {
        'instance': isinstance,
        'ari_builtin': ari_builtin,
    }


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
import io
import logging
import jinja2
import textwrap
import typing
from typing import Union, Optional
import ace
from ace.typing import BUILTINS
from ace import models, ari, ari_text
from ace.lookup import dereference, ORM_TYPE

LOGGER = logging.getLogger(__name__)

AdmEntity = Union[models.AdmModule, models.AdmObjMixin]
''' Either an ADM itself or an AMM object defined within one. '''


def yang_to_c(identifier):
    ''' Translates a valid YANG identifier to a valid C99 symbol name.
    '''
    return identifier.replace('_', '__').replace('-', '_').replace('.', '_p_')


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
        return yang_to_c(adm.name).lower() + '.h'

    def cpp_guard(adm:models.AdmModule) -> str:
        ''' Get the header guard for a module.
        '''
        return '_'.join([sym_prefix, yang_to_c(adm.name), 'H_']).upper()

    def cpp_enum(value:AdmEntity) -> str:
        ''' Map from ORM and YANG names into C preprocessor define name.
        '''
        if isinstance(value, ari.StructType):
            return 'ARI_TYPE_' + value.name
        elif isinstance(value, models.AdmModule):
            module = value
            parts = ['adm']
        elif isinstance(value, models.AdmObjMixin):
            module = value.module
            parts = ['objid', amm_obj_type(value).name, yang_to_c(value.name)]
        return '_'.join([sym_prefix, yang_to_c(module.name), 'enum'] + parts).upper()

    def c_func(value:AdmEntity, suffix:Optional[str]=None) -> str:
        ''' Map from ORM and YANG names into C function symbol name.
        '''
        if isinstance(value, models.AdmModule):
            parts = [yang_to_c(value.name)]
        elif isinstance(value, models.AdmObjMixin):
            parts = list(map(yang_to_c, [value.module.name, amm_obj_type(value).name, value.name]))
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
        return '"' + value.replace('\\', '\\\\') + '"'

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
        'rewrap': rewrap,
        'as_text': as_text,
        'ref_text': ref_text,
        'deref': deref,
    }
    env.tests |= {
        'instance': isinstance,
        'ari_builtin': ari_builtin,
    }

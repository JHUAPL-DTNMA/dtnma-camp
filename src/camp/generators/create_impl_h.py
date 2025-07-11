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
''' This module creates the h file for the implementation version of the ADM.
'''

import os
import jinja2
from typing import TextIO
from camp.generators.lib.campch import yang_to_c, update_jinja_env
from camp.generators.lib.campch_roundtrip import H_Scraper
from camp.generators.base import AbstractWriter, CHelperMixin


class Writer(AbstractWriter, CHelperMixin):
    ''' The common header file writer.
    '''

    def __init__(self, admset, adm, out_path, scrape: bool):
        super().__init__(admset, adm, out_path)

        self.c_norm_name = yang_to_c(self.adm.norm_name)

        full_path = self.file_path()
        scrape_src = full_path if scrape and os.path.exists(full_path) else None
        self._scraper = H_Scraper(scrape_src)

    def file_path(self) -> str:
        # Interface for AbstractWriter
        return os.path.join(self.out_path, f"{self.c_norm_name}.h")

    def write(self, outfile: TextIO):
        # Interface for AbstractWriter
        SELFDIR = os.path.dirname(__file__)

        self._tmpl_env = jinja2.Environment(
            loader=jinja2.FileSystemLoader(os.path.join(SELFDIR, 'data')),
            keep_trailing_newline=True
        )
        update_jinja_env(self._tmpl_env, self.admset, sym_prefix='refda_adm')

        keys = dict(
            adm=self.adm,
            scraper=self._scraper,
        )
        try:
            tmpl = self._tmpl_env.get_template('agent.h.jinja')
        except Exception as err:
            raise RuntimeError('Failed to load template "agent.h.jinja"') from err
        tmpl.stream(**keys).dump(outfile)

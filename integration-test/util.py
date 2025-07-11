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
''' Shared test fixture utilities.
This module must be in the same directory as the
anms-adms and dtnma-tools repos.
'''
import argparse
import os
from typing import Tuple
from camp.tools.camp import run

_util_path = os.path.dirname(os.path.abspath(__file__))

ADMS_DIR = os.path.join(_util_path, "deps", "adms")
''' ADM storage path. '''
DTNMA_TOOLS_DIR = os.path.join(_util_path, "deps", "dtnma-tools")
''' DTNMA agent source path. '''


def _good_file(name: str) -> bool:
    ''' Determine if a file path is an ADM to load.
    '''
    path = os.path.join(ADMS_DIR, name)
    if not os.path.isfile(path):
        return False

    _, ext = os.path.splitext(name)
    return ext == ".yang"


def adm_files() -> Tuple[str]:
    ''' Get a list of available ADMs from the test directory.
    These are file names only, which are under :obj:`ADMS_DIR` parent dir.
    '''
    paths = [name for name in os.listdir(ADMS_DIR)]
    return tuple(sorted(filter(_good_file, paths)))


def run_camp(filepath, outpath, only_sql, only_ch, scrape=False) -> int:
    """
    Generates sql files by running CAmp on :obj:`filepath`.
    Resulting sql files are stored in :obj:`outpath`.

    :return: Exit code, with zero being success.
    """
    args = argparse.Namespace()
    args.admfile = filepath
    args.out = outpath
    args.only_sql = only_sql
    args.only_ch = only_ch
    args.scrape = scrape
    return run(args)

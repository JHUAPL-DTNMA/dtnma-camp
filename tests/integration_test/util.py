''' Shared test fixture utilities.
This module must be in the same directory as the
anms-adms and dtnma-tools repos.
'''
import argparse
import os
from typing import Tuple
from camp.tools.camp import run

_util_path = os.path.dirname(os.path.abspath(__file__))

ADMS_DIR = os.path.join(_util_path, "anms-adms")
''' ADM storage path. '''
DTNMA_TOOLS_DIR = os.path.join(_util_path, "dtnma-tools")
''' DTNMA agent source path. '''

def _good_file(path: str) -> bool:
    ''' Determine if a file path is an ADM to load.
    '''
    if not os.path.isfile(path):
        return False

    _, filename = os.path.split(path)
    ext = os.path.splitext(filename)[1]
    return ext == ".json" and not filename == "index.json"

def adm_files() -> Tuple[str]:
    ''' Get a list of available ADMs from the test directory.
    '''
    paths = [
        os.path.join(ADMS_DIR, name)
        for name in os.listdir(ADMS_DIR)
    ]
    return tuple(filter(_good_file, paths))

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

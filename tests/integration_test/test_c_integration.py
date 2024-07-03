import pytest
import os
import ace
import shutil

from .util import _run_camp

ADMS_DIR = os.path.join("tests", "adms")  # TODO may move to util if same
OUT_DIR = os.path.join("tests", "dtnma-tools", "src")
ADM_SET = ace.AdmSet()

@pytest.mark.parametrize("adm", ["amp_agent.json"])
def test_adms(adm):

    filepath = os.path.join(ADMS_DIR, adm)  # input file full filepath

    # if camp-generated files already exist, find where they are is so we know to scrap from 
    # and output to
    # agent.c, impl.c, impl.h generally in the same place
    norm_name = ADM_SET.load_from_file(filepath).norm_name
    impl = "adm_{name}_impl.c".format(name=norm_name)
    outdir = _find_dir(impl, OUT_DIR)
    
    # run camp
    exitcode = _run_camp(filepath, outdir, only_sql=False, only_ch=True, scrape=True)
    assert 0 == exitcode

    # may need to move the mgr or shared files
    # okay to directly move bc these files don't get scraped
    mgr = os.path.join(outdir, "mgr", "adm_{name}_mgr.c".format(name=norm_name))
    shared = os.path.join(outdir, "shared", "adm", "adm_{name}.h".format(name=norm_name))
    _move_file(mgr, OUT_DIR)
    _move_file(shared, OUT_DIR)
    print(mgr)
    print("SHARED " + shared)

    print(adm)
    print(filepath)
    print("EXISTING FILE NAMER " + impl)
    print("FOUND AT " + outdir)


def _find_dir(name, dir):
    """
    If the generated C file already exists in dir, returns the directory in which the generated
    C files should be placed (as it should be passed to CAmp--takes into account that CAmp creates
    directories as well). If the file is not found, returns dir.
    (Based on the structure of the DTNMA tools repo's src folder)
    """
    for root, _, files in os.walk(dir):
        if name in files:
            existing_file = os.path.join(root, name)
            return os.path.abspath(os.path.join(existing_file, os.pardir, os.pardir))

    return dir


def _move_file(fullpath, dir):
    """
    If the file at fullpath already exists elsewhere in dir_to_look,
    moves and replaces the file to its other location in dir_to_look
    """
    name = os.path.split(fullpath)[1]
    print(name) # TODO remove

    for root, _, files in os.walk(dir):
        if name in files:
            existing_file = os.path.join(root, name)
            if fullpath != existing_file:
                shutil.move(fullpath, existing_file)

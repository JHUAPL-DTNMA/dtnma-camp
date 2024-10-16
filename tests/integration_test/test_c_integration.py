import pytest
import os
import ace
import shutil
import subprocess
from .util import ADMS_DIR, DTNMA_TOOLS_DIR, adm_files, run_camp


OUT_DIR = os.path.join(DTNMA_TOOLS_DIR, "src")

@pytest.fixture(autouse=True)
def setup():
    """
    Restores the dtnma-tools repository
    @pre: DTNMA_TOOLS_DIR is a git working copy
    """
    subprocess.check_call(["git", "restore", "."], cwd=DTNMA_TOOLS_DIR)
    

@pytest.mark.parametrize("adm", adm_files())
def test_adms(adm):
    """
    Compiles each adm in ADMS_DIR against the dtnma-tools repo
    @pre: DTNMA_TOOLS_DIR is a git working copy, tests should be run from home directory of camp repo
    """
    if adm == 'amp_agent.json' or adm == 'ion_bpsec_admin.json':
        pytest.xfail("ADM with known issue")
    # input file full filepath
    filepath = os.path.join(ADMS_DIR, adm)

    # if camp-generated files already exist, find where they are is so we can scrape if possible
    # assumes the impl.c and the impl.h files (which get scraped) live in the same directory.
    # also must be under folder named /agent for camp to correctly scrape, otherwise it
    adm_set = ace.AdmSet()
    # generates a new file
    norm_name = adm_set.load_from_file(filepath).norm_name
    impl = "adm_{name}_impl.c".format(name=norm_name)
    outdir = _find_dir(impl, OUT_DIR)

    # run camp
    exitcode = run_camp(filepath, outdir, only_sql=False, only_ch=True, scrape=True)
    assert 0 == exitcode

    # may need to move files around anyway
    mgr = os.path.join(outdir, "mgr", "adm_{name}_mgr.c".format(name=norm_name))
    shared = os.path.join(outdir, "shared", "adm", "adm_{name}.h".format(name=norm_name))
    agent = os.path.join(outdir, "agent", "adm_{name}_agent.c".format(name=norm_name))
    impl_c = os.path.join(outdir, "agent", "adm_{name}_impl.c".format(name=norm_name))
    impl_h = os.path.join(outdir, "agent", "adm_{name}_impl.h".format(name=norm_name))
    _move_file(mgr, OUT_DIR)
    _move_file(shared, OUT_DIR)
    _move_file(agent, OUT_DIR)
    _move_file(impl_c, OUT_DIR)
    _move_file(impl_h, OUT_DIR)

    # compile here
    assert 0 == subprocess.call(["./build.sh", "check"], cwd=DTNMA_TOOLS_DIR)


def _find_dir(name, dir):
    """
    If the generated C file already exists in dir, returns the directory in which the generated
    C files should be placed (as it should be passed to CAmp--takes into account that CAmp creates
    directories as well). If the file is not found, returns dir.
    (Based on the structure of the dtnma-tools repo's src folder)
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
    for root, _, files in os.walk(dir):
        if name in files:
            existing_file = os.path.join(root, name)
            if fullpath != existing_file:
                shutil.move(fullpath, existing_file)

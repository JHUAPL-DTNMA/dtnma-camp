import logging
import os
import pytest
import shutil
import subprocess
import ace
from camp.generators.lib.campch import yang_to_c
from .util import ADMS_DIR, DTNMA_TOOLS_DIR, adm_files, run_camp

OUT_DIR = os.path.join(DTNMA_TOOLS_DIR, "src")

LOGGER = logging.getLogger(__name__)


def cleanup():
    subprocess.check_call(["git", "restore", "."], cwd=DTNMA_TOOLS_DIR)
    subprocess.check_call(["git", "clean", "-fd"], cwd=DTNMA_TOOLS_DIR)


@pytest.fixture(autouse=True)
def setup():
    """
    Restores the dtnma-tools repository
    @pre: DTNMA_TOOLS_DIR is a git working copy
    """
    cleanup()


@pytest.mark.parametrize("adm", adm_files())
def test_adms(adm):
    """
    Compiles each adm in ADMS_DIR against the dtnma-tools repo
    @pre: DTNMA_TOOLS_DIR is a git working copy, tests should be run from home directory of camp repo
    """

    # input file full filepath
    filepath = os.path.join(ADMS_DIR, adm)

    # if camp-generated files already exist, find where they are is so we can scrape if possible
    # assumes the impl.c and the impl.h files (which get scraped) live in the same directory.
    # also must be under folder named /agent for camp to correctly scrape, otherwise it
    adm_set = ace.AdmSet()
    # generates a new file
    norm_name = adm_set.load_from_file(filepath).norm_name
    filename = f"{yang_to_c(norm_name)}.c"
    LOGGER.info('Looking for implementation source %s', filename)
    outdir = _find_dir(filename, OUT_DIR)
    if outdir is None:
        pytest.skip('No existing source')
    LOGGER.info('Found at %s', outdir)

    # run camp
    exitcode = run_camp(filepath, outdir, only_sql=False, only_ch=True, scrape=True)
    assert 0 == exitcode

    # verify the generated source compiles
    assert 0 == subprocess.check_call(["./build.sh"], cwd=DTNMA_TOOLS_DIR)
    # and is fully internally consistent
    # assert 0 == subprocess.check_call(["./build.sh", "check"], cwd=DTNMA_TOOLS_DIR)


def _find_dir(name, dir):
    """
    If the generated C file already exists in dir, returns the directory in which the generated
    C files should be placed. If the file is not found, returns None.
    """
    for root, _, files in os.walk(dir):
        if name in files:
            return root

    return None

import logging
import os
import psycopg2
import pytest
import tempfile
import ace
from camp.generators.lib.campch import yang_to_sql
from .util import ADMS_DIR, adm_files, run_camp

LOGGER = logging.getLogger(__name__)


@pytest.fixture(scope="session", autouse=True)
def setup():
    """
    Connects to the ADMS library session. Cleans up connections once done.
    @pre: IP Address of the library session should be stored in env var $PGHOST,
          username and password should be stored in env vars $PGUSER and
          $PGPASSWORD, respectively
    @yields tuple of (connection object, AdmSet())
    """

    # setup: connect to ANMS library
    conn = psycopg2.connect(
            host=os.environ["PGHOST"],
            port=int(os.environ.get("PGPORT", 5432)),
            user=os.environ["PGUSER"],
            password=os.environ["PGPASSWORD"]
    )
    cursor = conn.cursor()

    # reusable objects that the tests will need
    yield conn,

    # teardown: close connections
    conn.close()


@pytest.mark.parametrize("adm", adm_files())
def test_adms(setup, adm):
    """
    Integration test for an ADM found in the ADMS_DIR folder
    Resulting sql files will be placed in ADMS_DIR/amp-sql/Agent_Scripts and executed in the anms library.
    """

    conn = setup[0]

    # input file full filepath
    filepath = os.path.join(ADMS_DIR, adm)

    # output to temporary
    adm_set = ace.AdmSet()
    norm_name = adm_set.load_from_file(filepath).norm_name
    filename = f"{yang_to_sql(norm_name)}.sql"
    LOGGER.info('Expecting SQL source %s', filename)

    outdir = tempfile.TemporaryDirectory()

    # run camp
    exitcode = run_camp(filepath, outdir.name, only_sql=True, only_ch=False)
    assert 0 == exitcode

    # verify the generated source executes
    file_path = os.path.join(outdir.name, filename)
    with open(file_path, "r") as srcfile:
        script = srcfile.read()
        LOGGER.info('Generated script:\n%s', script)

        try:
            with conn.cursor() as curs:
                curs.execute(script)
        finally:
            conn.rollback()

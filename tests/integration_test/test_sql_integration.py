import psycopg2
import os
import ace
import pytest
import camp

from .util import ADMS_DIR, adm_files, run_camp, normalize_filename

@pytest.fixture(scope="session", autouse=True)
def setup():
    """
    Connects to the ADMS library session. Cleans up connections once done.
    @pre: IP Address of the library session should be stored in env var $PGHOST,
          username and password should be stored in env vars $PGSQL_USERNAME and
          $PGSQL_PASSWORD, respectively
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
    yield cursor,

    # teardown: close connections
    cursor.close()
    conn.close()


@pytest.mark.parametrize("adm", adm_files())
def test_adms(setup, adm):
    """
    Integration test for an ADM found in the ADMS_DIR folder
    Resulting sql files will be placed in ADMS_DIR/amp-sql/Agent_Scripts and executed in the anms library.
    """
    cursor = setup[0]

    # input file full filepath
    filepath = os.path.join(ADMS_DIR, adm)

    # run camp
    exitcode = run_camp(filepath, ADMS_DIR, only_sql=True, only_ch=False)
    assert 0 == exitcode

    # execute sql
    adm_set = ace.AdmSet()
    norm_name = normalize_filename(adm_set.load_from_file(filepath).norm_name)
    sql_file = os.path.join(ADMS_DIR, "amp-sql", "Agent_Scripts", 'adm_{name}.sql'.format(name=norm_name))
    with open(sql_file, "r") as f:
        cursor.execute(f.read())
        cursor.execute("rollback")

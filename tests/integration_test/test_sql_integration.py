import psycopg2
import os
import ace
import pytest

from .util import ADMS_DIR, adm_files, run_camp
from camp.generators.lib.camputil import yang_to_sql

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

    if adm == 'ietf-amm.yang':  # doesn't have unique enum 
        pytest.xfail("ADM with known issue")

    cursor = setup[0]

    # input file full filepath
    filepath = os.path.join(ADMS_DIR, adm)

    # run camp
    exitcode = run_camp(filepath, ADMS_DIR, only_sql=True, only_ch=False)
    assert 0 == exitcode

    # execute sql
    adm_set = ace.AdmSet()
    norm_name = yang_to_sql(adm_set.load_from_file(filepath).norm_name)
    sql_file = os.path.join(ADMS_DIR, "amp-sql", "Agent_Scripts", 'adm_{name}.sql'.format(name=norm_name))
    with open(sql_file, "r") as f:

        # TODO Karen remove debug
        content = f.read()
        print(content)

        cursor.execute(content)
        cursor.execute("rollback")

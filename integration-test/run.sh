#!/bin/bash
# Execute CAMP with real ADMs and real targets.
# The only argument to this script is the test mode, either "c" or "sql".
#
set -e

SELFDIR=$(realpath $(dirname "${BASH_SOURCE[0]}"))
cd ${SELFDIR}/..

if [[ -z "$1" ]]
then
    echo "Usage: $0 {c|sql}"
    exit 1
fi

echo "Installing virtualenv..."
python3 -m venv ./build/venv
source ./build/venv/bin/activate

echo "Installing dependencies..."
if [[ ! -d ${SELFDIR}/deps/adms ]]
then
    git clone --branch main https://github.com/JHUAPL-DTNMA/dtnma-adms.git ${SELFDIR}/deps/adms
fi

if [[ ! -d ${SELFDIR}/deps/dtnma-ace ]]
then
    git clone --branch main https://github.com/JHUAPL-DTNMA/dtnma-ace.git ${SELFDIR}/deps/dtnma-ace
fi
pip3 install ${SELFDIR}/deps/dtnma-ace

if [[ ! -d ${SELFDIR}/deps/dtnma-tools ]]
then
    git clone --branch main https://github.com/JHUAPL-DTNMA/dtnma-tools.git ${SELFDIR}/deps/dtnma-tools
    pushd ${SELFDIR}/deps/dtnma-tools
    git submodule update --init --recursive
    popd
fi

if [[ "$1" = "c" ]]
then
    pushd ${SELFDIR}/deps/dtnma-tools
    git pull
    ./deps.sh
    popd
    if [[ ! -d ${SELFDIR}/deps/dtnma-tools/build ]]
    then
        pushd ${SELFDIR}/deps/dtnma-tools
        ./prep.sh -DTEST_MEMCHECK=OFF -DTEST_COVERAGE=OFF \
            -DBUILD_DOCS_API=OFF -DBUILD_DOCS_MAN=OFF
        ./build.sh
        # verification that the initial build is good
        ./build.sh check
        popd
    fi
    PYTEST_ARGS="${SELFDIR}/test_c_integration.py"
elif [[ "$1" = "sql" ]]
then
    DOCKER=${DOCKER:-docker}
    COMPOSE_ARGS="-f ${SELFDIR}/sql-compose.yml"
    ${DOCKER} compose ${COMPOSE_ARGS} build
    ${DOCKER} compose ${COMPOSE_ARGS} up --detach --force-recreate --remove-orphans

    export PGHOST="localhost"
    # all other PG* test environment is passed through this script

    PYTEST_ARGS="${SELFDIR}/test_sql_integration.py"
else
    echo "Unknown test type \"$1\"" >/dev/stderr
    exit 1
fi

echo "Running tests..."
pip3 install '.[test]'
TESTEXIT=0
python3 -m pytest -v --cov=camp --log-level=info ${PYTEST_ARGS} || TESTEXIT=$?

if [[ "$1" = "sql" ]]
then
    ${DOCKER} compose ${COMPOSE_ARGS} down --rmi local --volumes
    ${DOCKER} compose ${COMPOSE_ARGS} rm --force --volumes
fi

exit ${TESTEXIT}

#!/bin/bash
##
## Copyright (c) 2020-2024 The Johns Hopkins University Applied Physics
## Laboratory LLC.
##
## This file is part of the C code generator for AMP (CAMP) under the
## DTN Management Architecture (DTNMA) reference implementaton set from APL.
##
## Licensed under the Apache License, Version 2.0 (the "License");
## you may not use this file except in compliance with the License.
## You may obtain a copy of the License at
##     http://www.apache.org/licenses/LICENSE-2.0
## Unless required by applicable law or agreed to in writing, software
## distributed under the License is distributed on an "AS IS" BASIS,
## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
## See the License for the specific language governing permissions and
## limitations under the License.
##
## Portions of this work were performed for the Jet Propulsion Laboratory,
## California Institute of Technology, sponsored by the United States Government
## under the prime contract 80NM0018D0004 between the Caltech and NASA under
## subcontract 1658085.
##

# Apply copyright and license markings to source files.
#
# Requires installation of:
#  pip3 install licenseheaders
# Run as:
#  ./apply_license.sh {--dry} {-vv}
#
set -e

SELFDIR=$(realpath $(dirname "${BASH_SOURCE[0]}"))

LICENSEOPTS="${LICENSEOPTS} --tmpl ${SELFDIR}/apply_license.tmpl"
LICENSEOPTS="${LICENSEOPTS} --years 2020-$(date +%Y)"
# Excludes only apply to directory (--dir) mode and not file mode
#LICENSEOPTS="${LICENSEOPTS} --exclude *.yml *.yaml *.min. "


# Specific paths
if [ "$#" -gt 0 ]
then
    echo "Applying markings to selected $@ ..."
    licenseheaders ${LICENSEOPTS} --dir $@
    exit 0
fi

echo "Applying markings to source..."
licenseheaders ${LICENSEOPTS} --dir ${SELFDIR}

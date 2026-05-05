#
# Copyright (c) 2020-2026 The Johns Hopkins University Applied Physics
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
import logging
import re
from typing import Dict, List, Optional, Set

LOGGER = logging.getLogger(__name__)


class Scraper(object):
    ''' Class to handle scraping files, and writing custom tags and code to
    newly-generated files.
    '''

    GENSRC_START = re.compile(r'/\*\s+START GENERATED SOURCE HERE\s+\*/')
    ''' Top of generated lines '''
    GENSRC_STOP = re.compile(r'/\*\s+STOP GENERATED SOURCE HERE\s+\*/')
    ''' Bottom of generated lines '''

    CUSTOM_INCLUDES_START = re.compile(r'/\*\s+START CUSTOM INCLUDES HERE\s+\*/')
    ''' Top of includes '''
    CUSTOM_INCLUDES_STOP = re.compile(r'/\*\s+STOP CUSTOM INCLUDES HERE\s+\*/')
    ''' Bottom of includes '''

    def __init__(self, filename: Optional[str]):
        self.filename = filename
        self.extra_top: List[str] = []
        self.extra_bottom: List[str] = []
        self.includes: List[str] = ["/*             NONE             */\n"]

    def _find_extra_lines(self, lines: List[str]) -> None:
        ''' Pop extra content at start and end of the file.
        Only specific extra lines are removed.
        Either or both of the markers can be present in the file.

        :param lines: lines to search and pop from.
        '''
        self.extra_top = []
        self.extra_bottom = []

        start_ix = None
        for line_ix, line in enumerate(lines):
            if self.GENSRC_START.search(line) is not None:
                start_ix = line_ix
                break

        LOGGER.info('generated start at %s', start_ix)
        if start_ix is not None:
            self.extra_top = lines[:start_ix]
            del lines[:(start_ix + 1)]

        stop_ix = None
        for line_ix, line in enumerate(lines):
            if self.GENSRC_STOP.search(line) is not None:
                stop_ix = line_ix
                break

        LOGGER.info('generated stop at %s', stop_ix)
        if stop_ix is not None:
            self.extra_bottom = lines[(stop_ix + 1):]
            del lines[stop_ix:]

    def _find_custom_includes_in_queue(self, lines: List[str]) -> None:
        '''
        Pops items off of the passed queue (list) structure, searching
        for the custom includes tags. Returns all lines encompassed in these tags
        NOTICE: since this is treating lines as a queue, it will evaluate lines in
        reverse order (popping off the end of the list).

        :param lines: lines to search and pop from.
        '''
        self.includes = []

        # find the start
        while lines:
            line = lines.pop(0)
            if self.CUSTOM_INCLUDES_START.search(line) is not None:
                break

        # Append until we find the end
        while lines:
            line = lines.pop(0)
            if self.CUSTOM_INCLUDES_STOP.search(line) is not None:
                break
            self.includes.append(line)

class C_Scraper(Scraper):
    ''' C-file scraper class is a child of the Scraper class '''

    CUSTOM_FUNCTIONS_START = re.compile(r'/\*\s+START CUSTOM FUNCTIONS HERE\s+\*/')
    ''' Top of local functions '''
    CUSTOM_FUNCTIONS_STOP = re.compile(r'/\*\s+STOP CUSTOM FUNCTIONS HERE\s+\*/')
    ''' Bottom of local functions '''

    #
    # Pops items off of the passed queue (list) structure, searching
    # for the custom functions tags. Returns all lines encompassed in these tags
    #
    # lines: lines to search
    #
    # NOTICE: since this is treating lines as a queue, it will evaluate lines in
    # reverse order (popping off the end of the list).
    #
    def _find_custom_functions_in_queue(self, lines: List[str]) -> None:
        self.functions = []

        # find the start
        while lines:
            line = lines.pop(0)
            if self.CUSTOM_FUNCTIONS_START.search(line) is not None:
                break

        # Append until we find the end
        while lines:
            line = lines.pop(0)
            if self.CUSTOM_FUNCTIONS_STOP.search(line) is not None:
                break
            self.functions.append(line)

    CUSTOM_PREINIT_START = re.compile(r'/\*\s+START CUSTOM PRE-INIT HERE\s+\*/')
    ''' Top of pre-init '''
    CUSTOM_PREINIT_STOP = re.compile(r'/\*\s+STOP CUSTOM PRE-INIT HERE\s+\*/')
    ''' Bottom of pre-init '''
    CUSTOM_POSTINIT_START = re.compile(r'/\*\s+START CUSTOM POST-INIT HERE\s+\*/')
    ''' Top of post-init '''
    CUSTOM_POSTINIT_STOP = re.compile(r'/\*\s+STOP CUSTOM POST-INIT HERE\s+\*/')
    ''' Bottom of post-init '''

    def _find_custom_init_in_queue(self, lines: List[str]) -> None:
        self.pre_init_lines = []
        # find the pre-init block
        start_ix = None
        stop_ix = None
        for line_ix, line in enumerate(lines):
            if self.CUSTOM_PREINIT_START.search(line) is not None:
                start_ix = line_ix
            elif self.CUSTOM_PREINIT_STOP.search(line) is not None:
                stop_ix = line_ix
                break
        LOGGER.info('pre-init between %s and %s', start_ix, stop_ix)
        if start_ix is not None and stop_ix is not None:
            self.pre_init_lines = lines[(start_ix + 1):stop_ix]
            del lines[start_ix:(stop_ix + 1)]

        self.post_init_lines = []
        # find the post-init block
        start_ix = None
        stop_ix = None
        for line_ix, line in enumerate(lines):
            if self.CUSTOM_POSTINIT_START.search(line) is not None:
                start_ix = line_ix
            elif self.CUSTOM_POSTINIT_STOP.search(line) is not None:
                stop_ix = line_ix
                break
        LOGGER.info('post-init between %s and %s', start_ix, stop_ix)
        if start_ix is not None and stop_ix is not None:
            self.post_init_lines = lines[(start_ix + 1):stop_ix]
            del lines[start_ix:(stop_ix + 1)]

    #
    # Helper function that returns the indicator and custom tag used by the custom bodies.
    # TODO: This is split out differently than the others and is not ideal because of how
    # the scraper deals with multi-line tags. Try to simplify.
    #
    def _get_custom_body_pieces(self):
        indicator = "* +-------------------------------------------------------------------------+"
        marker = '|{} CUSTOM FUNCTION {} BODY'
        return indicator, marker

    #
    # Returns a tuple of the (indicator, start marker, end marker) strings for use with a
    # regex search for custom function bodies.
    #
    def _get_custom_body_re_markers(self):
        indicator, marker = self._get_custom_body_pieces()

        marker = '\\* \\' + marker
        function_string_matcher = '(.+)'

        return (
            indicator,
            re.compile(marker.format('START', function_string_matcher)),
            re.compile(marker.format('STOP', function_string_matcher))
        )

    CALLBACK_FUNCTIONS_STOP = re.compile(r'/\*\s+STOP CALLBACK FUNCTIONS HERE\s+\*/')
    ''' End of callback block '''

    #
    # Pops items off of the passed queue (list) structure, searching
    # for the function custom body tags. Returns all dictonary of key:value pairs for
    # lines encompassed in these tags, where the key is the function name, and value
    # is the list of custom lines for that function
    #
    # lines: lines to search
    #
    # NOTICE: since this is treating lines as a queue, it will evaluate lines in
    # reverse order (popping off the end of the list).
    #
    def _find_func_custom_body_in_queue(self, lines: List[str]) -> None:
        self.func_bods = {}

        func: Optional[str] = None

        indicator, start_re, end_re = self._get_custom_body_re_markers()

        # While lines remain in the queue, pop one off and evaluate it
        while lines:
            line = lines.pop(0)
            clean_line = line.strip()

            if self.CALLBACK_FUNCTIONS_STOP.search(line) is not None:
                # end of all callbacks
                break

            # If we're inside one of the custom function bodies
            # keep appending until end
            if func is not None:

                # Append to this function's dictionary entry until you reach
                # another indicator with an end tag
                if clean_line == indicator:
                    line = lines.pop(0)
                    clean_line = line.strip()

                    if end_re.search(clean_line) is not None:
                        self.func_bods[func].pop()
                        func = None
                    else:
                        continue
                else:
                    func_lines = self.func_bods.setdefault(func, [])
                    func_lines.append(line)

            # Check if this line is the start of a new custom function body
            else:
                s = start_re.search(clean_line)
                if s is not None:
                    func = s.group(1)

        LOGGER.info('Collected bodies from functions: %s', ' '.join(self.func_bods.keys()))

    #
    # Returns a tuple of the custom body's start and end markers
    #
    def _make_custom_body_markers(self, function):
        indicator, marker = self._get_custom_body_pieces()

        template = ("    /*\n"
                    "     {0}\n"
                    "     * {1}\n"
                    "     {0}\n"
                    "     */\n")

        start_marker = marker.format("START", function)
        end_marker = marker.format("STOP", function)

        return (
            template.format(indicator, start_marker),
            template.format(indicator, end_marker)
        )

    #
    # Write the standard 'CUSTOM' tag for the body of a standard function
    #
    # file: open file descriptor to write to
    # function: function name
    # custom: array of lines to add as custom function body content (from scraping)
    # if custom is empty, will just write the tags for custom content to the file
    #
    def write_custom_body(self, function: str) -> str:
        custom = self.func_bods.get(function, [])
        self.func_bods_used.add(function)

        start, end = self._make_custom_body_markers(function)

        return start + ''.join(custom) + end

    def funcs_unused(self) -> Set[str]:
        ''' Get a set of function names which were scraped but not written.
        '''
        return set(self.func_bods.keys()) - self.func_bods_used

    #
    # Constructor for the C_Scraper Class
    #
    # In the function custom bodies dictionary, the name of the function serves
    # as the key, and the value is a list of strings that make up the custom body
    # of that function.
    #
    def __init__(self, filename: Optional[str]):
        super().__init__(filename)
        self.functions: List[str] = ["/*             NONE              */\n"]
        self.pre_init_lines: List[str] = []
        self.post_init_lines: List[str] = []
        self.func_bods: Dict[str, str] = dict()
        self.func_bods_used: Set[str] = set()

        if self.filename is None:
            return

        LOGGER.info("Scraping source from %s", self.filename)

        src: List[str] = []
        # Insert each line into a list
        try:
            with open(self.filename) as infile:
                src = infile.readlines()
        except IOError:
            LOGGER.exception("Failed to open %s for scraping", self.filename)
        LOGGER.info('Read %d lines', len(src))

        self._find_extra_lines(src)
        self._find_custom_includes_in_queue(src)
        self._find_custom_functions_in_queue(src)
        self._find_func_custom_body_in_queue(src)
        self._find_custom_init_in_queue(src)

        LOGGER.info("DONE")

        # Sanity Check. If scraping was requested and returned nothing, let the user know
        if len(self.includes) == 0 and len(self.functions) == 0 and len(self.func_bods) == 0:
            LOGGER.warning("No custom input found to scrape in %s", self.filename)


class H_Scraper(Scraper):
    ''' H-file scraper class is a child of the Scraper class. '''

    def __init__(self, filename: Optional[str]):
        super().__init__(filename)

        if self.filename is None:
            return

        LOGGER.info("Scraping source from %s", self.filename)

        src: List[str] = []
        # Insert each line into a list
        try:
            with open(self.filename) as infile:
                src = infile.readlines()
        except IOError:
            LOGGER.exception("Failed to open %s for scraping", self.filename)
        LOGGER.info('Read %d lines', len(src))

        self._find_extra_lines(src)
        self._find_custom_includes_in_queue(src)

        LOGGER.info("DONE")

        # Sanity Check. If scraping was requested and returned nothing, let the user know
        if len(self.includes) == 0:
            LOGGER.warning("No custom input found to scrape in %s", self.filename)

/*
 * Copyright (c) 2020-2026 The Johns Hopkins University Applied Physics
 * Laboratory LLC.
 *
 * This file is part of the C code generator for AMP (CAMP) under the
 * DTN Management Architecture (DTNMA) reference implementaton set from APL.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *     http://www.apache.org/licenses/LICENSE-2.0
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * Portions of this work were performed for the Jet Propulsion Laboratory,
 * California Institute of Technology, sponsored by the United States Government
 * under the prime contract 80NM0018D0004 between the Caltech and NASA under
 * subcontract 1658085.
 */

/** @file
 * This is the compilation unit for the implementation of the
 * ADM module "ietf-dtnma-agent" for the C-language reference DA.
 * This contains definitions of every AMM object instance in the ADM and
 * file-local callback functions for all EDDs, CTRLs, and OPERs.
 */

#include "ietf_dtnma_agent.h"
#include "refda/agent.h"
#include "refda/register.h"
#include "refda/edd_prod_ctx.h"
#include "refda/ctrl_exec_ctx.h"
#include "refda/oper_eval_ctx.h"
#include <cace/amm/semtype.h>
#include <cace/ari/text.h>
#include <cace/util/logging.h>
#include <cace/util/defs.h>

/*   START CUSTOM INCLUDES HERE  */
/*             TODO              */
/*   STOP CUSTOM INCLUDES HERE  */

/*   START CUSTOM FUNCTIONS HERE */
/*             TODO              */
/*   STOP CUSTOM FUNCTIONS HERE  */


/* Name: sw-vendor
 * Description:
 *   The vendor for this Agent implementation.
 *
 * Parameters: none
 *
 * Produced type: use of ari:/ARITYPE/TEXTSTR
 */
static void refda_adm_ietf_dtnma_agent_edd_sw_vendor(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_sw_vendor BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_sw_vendor BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: sw-version
 * Description:
 *   The version for this Agent implementation.
 *
 * Parameters: none
 *
 * Produced type: use of ari:/ARITYPE/TEXTSTR
 */
static void refda_adm_ietf_dtnma_agent_edd_sw_version(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_sw_version BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_sw_version BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: capability
 * Description:
 *   A table to indicate the ADM capability of the sending agent.
 *
 * Parameters: none
 *
 * Produced type: TBLT with 6 columns:
 *   - Index 0, name "org-name", type use of ari:/ARITYPE/TEXTSTR
 *   - Index 1, name "org-enum", type use of ari:/ARITYPE/VAST
 *   - Index 2, name "model-name", type use of ari:/ARITYPE/TEXTSTR
 *   - Index 3, name "model-enum", type use of ari:/ARITYPE/VAST
 *   - Index 4, name "revision", type use of ari:/ARITYPE/TEXTSTR
 *   - Index 5, name "features", type ulist of use of ari:/ARITYPE/TEXTSTR
 */
static void refda_adm_ietf_dtnma_agent_edd_capability(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_capability BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_capability BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: num-msg-rx
 * Description MISSING
 *
 * Parameters: none
 *
 * Produced type: use of ari://ietf/amm-base/TYPEDEF/counter64
 */
static void refda_adm_ietf_dtnma_agent_edd_num_msg_rx(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_msg_rx BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_msg_rx BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: num-msg-rx-failed
 * Description MISSING
 *
 * Parameters: none
 *
 * Produced type: use of ari://ietf/amm-base/TYPEDEF/counter64
 */
static void refda_adm_ietf_dtnma_agent_edd_num_msg_rx_failed(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_msg_rx_failed BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_msg_rx_failed BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: num-msg-tx
 * Description MISSING
 *
 * Parameters: none
 *
 * Produced type: use of ari://ietf/amm-base/TYPEDEF/counter64
 */
static void refda_adm_ietf_dtnma_agent_edd_num_msg_tx(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_msg_tx BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_msg_tx BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: num-msg-tx-failed
 * Description MISSING
 *
 * Parameters: none
 *
 * Produced type: use of ari://ietf/amm-base/TYPEDEF/counter64
 */
static void refda_adm_ietf_dtnma_agent_edd_num_msg_tx_failed(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_msg_tx_failed BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_msg_tx_failed BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: last-msg-rx-time
 * Description MISSING
 *
 * Parameters: none
 *
 * Produced type: use of ari:/ARITYPE/TP
 */
static void refda_adm_ietf_dtnma_agent_edd_last_msg_rx_time(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_last_msg_rx_time BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_last_msg_rx_time BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: num-exec-started
 * Description MISSING
 *
 * Parameters: none
 *
 * Produced type: use of ari://ietf/amm-base/TYPEDEF/counter64
 */
static void refda_adm_ietf_dtnma_agent_edd_num_exec_started(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_exec_started BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_exec_started BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: num-exec-succeeded
 * Description MISSING
 *
 * Parameters: none
 *
 * Produced type: use of ari://ietf/amm-base/TYPEDEF/counter64
 */
static void refda_adm_ietf_dtnma_agent_edd_num_exec_succeeded(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_exec_succeeded BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_exec_succeeded BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: num-exec-failed
 * Description MISSING
 *
 * Parameters: none
 *
 * Produced type: use of ari://ietf/amm-base/TYPEDEF/counter64
 */
static void refda_adm_ietf_dtnma_agent_edd_num_exec_failed(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_exec_failed BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_num_exec_failed BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: exec-running
 * Description MISSING
 *
 * Parameters: none
 *
 * Produced type: TBLT with 3 columns:
 *   - Index 0, name "pid", type use of ari:/ARITYPE/UVAST
 *   - Index 1, name "target", type use of ari://ietf/amm-base/TYPEDEF/any
 *   - Index 2, name "state", type use of ari:/ARITYPE/BYTE
 */
static void refda_adm_ietf_dtnma_agent_edd_exec_running(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_exec_running BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_exec_running BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: odm-list
 * Description:
 *   A table of ODM within the agent.
 *
 * Parameters: none
 *
 * Produced type: TBLT with 5 columns:
 *   - Index 0, name "org-name", type use of ari://ietf/amm-base/TYPEDEF/id-text
 *   - Index 1, name "org-enum", type use of ari://ietf/amm-base/TYPEDEF/id-int
 *   - Index 2, name "model-name", type use of ari://ietf/amm-base/TYPEDEF/id-text
 *   - Index 3, name "model-enum", type use of ari://ietf/amm-base/TYPEDEF/id-int
 *   - Index 4, name "revision", type use of ari:/ARITYPE/TEXTSTR
 */
static void refda_adm_ietf_dtnma_agent_edd_odm_list(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_odm_list BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_odm_list BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: typedef-list
 * Description:
 *   A table of TYPEDEF within the agent.
 *
 * Parameters list:
 *   - Index 0, name "include-adm", type use of ari:/ARITYPE/BOOL
 *
 * Produced type: TBLT with 1 columns:
 *   - Index 0, name "obj", type use of ari:/ARITYPE/TYPEDEF
 */
static void refda_adm_ietf_dtnma_agent_edd_typedef_list(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_typedef_list BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_typedef_list BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: const-list
 * Description:
 *   A table of CONST within the agent.
 *
 * Parameters list:
 *   - Index 0, name "include-adm", type use of ari:/ARITYPE/BOOL
 *
 * Produced type: TBLT with 2 columns:
 *   - Index 0, name "obj", type use of ari:/ARITYPE/CONST
 *   - Index 1, name "type", type use of ari://ietf/amm-semtype/TYPEDEF/semtype
 */
static void refda_adm_ietf_dtnma_agent_edd_const_list(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_const_list BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_const_list BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: var-list
 * Description:
 *   A table of VAR within the agent.
 *
 * Parameters list:
 *   - Index 0, name "include-adm", type use of ari:/ARITYPE/BOOL
 *
 * Produced type: TBLT with 2 columns:
 *   - Index 0, name "obj", type use of ari:/ARITYPE/VAR
 *   - Index 1, name "type", type use of ari://ietf/amm-semtype/TYPEDEF/semtype
 */
static void refda_adm_ietf_dtnma_agent_edd_var_list(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_var_list BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_var_list BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: sbr-list
 * Description:
 *   A table of SBR within the agent.
 *
 * Parameters list:
 *   - Index 0, name "include-adm", type use of ari:/ARITYPE/BOOL
 *
 * Produced type: TBLT with 7 columns:
 *   - Index 0, name "obj", type use of ari:/ARITYPE/SBR
 *   - Index 1, name "action", type use of ari://ietf/amm-base/TYPEDEF/MAC
 *   - Index 2, name "condition", type use of ari://ietf/amm-base/TYPEDEF/EXPR
 *   - Index 3, name "min-interval", type use of ari:/ARITYPE/TD
 *   - Index 4, name "max-count", type use of ari:/ARITYPE/UVAST
 *   - Index 5, name "init-enabled", type use of ari:/ARITYPE/BOOL
 *   - Index 6, name "enabled", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_edd_sbr_list(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_sbr_list BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_sbr_list BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: tbr-list
 * Description:
 *   A table of TBR within the agent.
 *
 * Parameters list:
 *   - Index 0, name "include-adm", type use of ari:/ARITYPE/BOOL
 *
 * Produced type: TBLT with 7 columns:
 *   - Index 0, name "obj", type use of ari:/ARITYPE/TBR
 *   - Index 1, name "action", type use of ari://ietf/amm-base/TYPEDEF/MAC
 *   - Index 2, name "start-time", type use of ari://ietf/amm-base/TYPEDEF/TIME
 *   - Index 3, name "period", type use of ari:/ARITYPE/TD
 *   - Index 4, name "max-count", type use of ari:/ARITYPE/UVAST
 *   - Index 5, name "init-enabled", type use of ari:/ARITYPE/BOOL
 *   - Index 6, name "enabled", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_edd_tbr_list(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_tbr_list BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_edd_tbr_list BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: if-then-else
 * Description:
 *   Evaluate an expression and follow one of two branches of further
 *   evaluation.
 *
 * Parameters list:
 *   - Index 0, name "condition", type use of ari://ietf/amm-base/TYPEDEF/eval-tgt
 *   - Index 1, name "on-truthy", type union of 2 types (use of ari://ietf/amm-base/TYPEDEF/exec-tgt, use of ari:/ARITYPE/NULL)
 *   - Index 2, name "on-falsy", type union of 2 types (use of ari://ietf/amm-base/TYPEDEF/exec-tgt, use of ari:/ARITYPE/NULL)
 *
 * Result name "branch", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_ctrl_if_then_else(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_if_then_else BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_if_then_else BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: catch
 * Description:
 *   Attempt to execute a target, and if there is some failure catch it and
 *   execute an alternative target.
 *
 * Parameters list:
 *   - Index 0, name "try", type use of ari://ietf/amm-base/TYPEDEF/exec-tgt
 *   - Index 1, name "on-failure", type union of 2 types (use of ari://ietf/amm-base/TYPEDEF/exec-tgt, use of ari:/ARITYPE/NULL)
 *
 * Result name "try-success", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_ctrl_catch(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_catch BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_catch BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: wait-for
 * Description:
 *   This control causes the execution to pause for a given amount of time.
 *   This is intended to be used within a macro to separate controls in
 *   time.
 *
 * Parameters list:
 *   - Index 0, name "duration", type use of ari:/ARITYPE/TD
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_wait_for(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_wait_for BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_wait_for BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: wait-until
 * Description:
 *   This control causes the execution to pause until a specific absolute
 *   time point. This is intended to be used within a macro to separate
 *   controls in time or as a first macro item to delay execution after the
 *   time of reception.
 *
 * Parameters list:
 *   - Index 0, name "time", type use of ari:/ARITYPE/TP
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_wait_until(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_wait_until BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_wait_until BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: wait-cond
 * Description:
 *   This control causes the execution to pause until a condition
 *   expression evaluates to truthy. This is intended to be used within a
 *   macro to separate controls in time or as a first macro item to delay
 *   execution until the condition is met.
 *
 * Parameters list:
 *   - Index 0, name "condition", type use of ari://ietf/amm-base/TYPEDEF/eval-tgt
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_wait_cond(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_wait_cond BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_wait_cond BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: inspect
 * Description:
 *   Produce a result value to inspect the agent state. This does not
 *   perform any EXPR evaluation or RPTT handling.
 *
 * Parameters list:
 *   - Index 0, name "ref", type use of ari://ietf/amm-base/TYPEDEF/VALUE-OBJ
 *
 * Result name "val", type use of ari://ietf/amm-base/TYPEDEF/any
 */
static void refda_adm_ietf_dtnma_agent_ctrl_inspect(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_inspect BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_inspect BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: report-on
 * Description:
 *   Agent-wide control to generate a report from a report template (RPTT)
 *   value. The parameter is a single RPTT list that would be produced by
 *   an object. If used for more than one-shot diagnostics, defining a RPTT
 *   (e.g. in a CONST within an ODM) is more efficient because the RPTT
 *   value would not need be present in the EXECSET or corresponding
 *   RPTSET.
 *
 * Parameters list:
 *   - Index 0, name "template", type use of ari://ietf/amm-base/TYPEDEF/rpt-tgt
 *   - Index 1, name "destinations", type ulist of use of ari://ietf/network-base/TYPEDEF/endpoint-or-uri
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_report_on(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_report_on BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_report_on BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: ensure-odm
 * Description:
 *   Ensure a specific ODM is present. The referenced organization and
 *   model identifiers SHALL either not already exist or exist with the
 *   exact combination given by these parameters
 *
 * Parameters list:
 *   - Index 0, name "org-name", type use of ari://ietf/amm-base/TYPEDEF/id-text
 *   - Index 1, name "org-id", type use of ari://ietf/amm-base/TYPEDEF/id-int
 *   - Index 2, name "model-name", type use of ari://ietf/amm-base/TYPEDEF/id-text
 *   - Index 3, name "model-id", type use of ari://ietf/amm-base/TYPEDEF/id-int
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_ensure_odm(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_odm BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_odm BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: obsolete-odm
 * Description:
 *   Mark a specific ODM as obsolete if it is present.
 *
 * Parameters list:
 *   - Index 0, name "odm-ns", type use of ari:/ARITYPE/NAMESPACE
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_obsolete_odm(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_obsolete_odm BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_obsolete_odm BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: var-reset
 * Description:
 *   Modify a VAR state to its default value.
 *
 * Parameters list:
 *   - Index 0, name "target", type use of ari:/ARITYPE/VAR
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_var_reset(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_var_reset BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_var_reset BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: var-store
 * Description:
 *   Modify a VAR state to a specific value.
 *
 * Parameters list:
 *   - Index 0, name "target", type use of ari:/ARITYPE/VAR
 *   - Index 1, name "value", type use of ari://ietf/amm-base/TYPEDEF/any
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_var_store(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_var_store BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_var_store BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: ensure-const
 * Description:
 *   Ensure a specific CONST is present in an ODM. If an object already
 *   exists with the same identifiers, type, and value this control will do
 *   nothing and succeed. If an object already exists in the same namespace
 *   with either of the object identifiers this control will fail.
 *
 * Parameters list:
 *   - Index 0, name "namespace", type use of ari:/ARITYPE/NAMESPACE
 *   - Index 1, name "obj-name", type use of ari://ietf/amm-base/TYPEDEF/id-text
 *   - Index 2, name "obj-enum", type use of ari://ietf/amm-base/TYPEDEF/id-int
 *   - Index 3, name "type", type use of ari://ietf/amm-semtype/TYPEDEF/semtype
 *   - Index 4, name "value", type use of ari://ietf/amm-base/TYPEDEF/any
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_ensure_const(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_const BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_const BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: obsolete-const
 * Description:
 *   Mark a specific CONST as obsolete if it is present in an ODM.
 *
 * Parameters list:
 *   - Index 0, name "obj", type use of ari:/ARITYPE/CONST
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_obsolete_const(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_obsolete_const BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_obsolete_const BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: ensure-var
 * Description:
 *   Ensure a specific VAR is present in an ODM. If an object already
 *   exists with the same identifiers, type, and init-value this control
 *   will do nothing and succeed. If an object already exists in the same
 *   namespace with either of the object identifiers (but not both), or the
 *   type or is different, this control will fail. That means that this
 *   control can change only the initial value of a pre-existing VAR
 *   object.
 *
 * Parameters list:
 *   - Index 0, name "namespace", type use of ari:/ARITYPE/NAMESPACE
 *   - Index 1, name "obj-name", type use of ari://ietf/amm-base/TYPEDEF/id-text
 *   - Index 2, name "obj-enum", type use of ari://ietf/amm-base/TYPEDEF/id-int
 *   - Index 3, name "type", type use of ari://ietf/amm-semtype/TYPEDEF/semtype
 *   - Index 4, name "init-value", type use of ari://ietf/amm-base/TYPEDEF/any
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_ensure_var(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_var BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_var BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: obsolete-var
 * Description:
 *   Mark a specific VAR as obsolete if it is present in an ODM.
 *
 * Parameters list:
 *   - Index 0, name "obj", type use of ari:/ARITYPE/VAR
 *
 * Result: none
 */
static void refda_adm_ietf_dtnma_agent_ctrl_obsolete_var(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_obsolete_var BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_obsolete_var BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: ensure-sbr
 * Description:
 *   Ensure that a state-based rule with the given identifiers exists
 *   within an ODM.
 *
 * Parameters list:
 *   - Index 0, name "namespace", type use of ari:/ARITYPE/NAMESPACE
 *   - Index 1, name "obj-name", type use of ari://ietf/amm-base/TYPEDEF/id-text
 *   - Index 2, name "obj-enum", type use of ari://ietf/amm-base/TYPEDEF/id-int
 *   - Index 3, name "action", type use of ari://ietf/amm-base/TYPEDEF/MAC
 *   - Index 4, name "condition", type use of ari://ietf/amm-base/TYPEDEF/EXPR
 *   - Index 5, name "min-interval", type use of ari:/ARITYPE/TD
 *   - Index 6, name "max-count", type use of ari:/ARITYPE/UVAST
 *   - Index 7, name "init-enabled", type use of ari:/ARITYPE/BOOL
 *
 * Result name "res", type use of ari:/ARITYPE/UINT
 */
static void refda_adm_ietf_dtnma_agent_ctrl_ensure_sbr(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_sbr BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_sbr BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: ensure-tbr
 * Description:
 *   Ensure that a time-based rule with the given identifiers exists within
 *   an ODM.
 *
 * Parameters list:
 *   - Index 0, name "namespace", type use of ari:/ARITYPE/NAMESPACE
 *   - Index 1, name "obj-name", type use of ari://ietf/amm-base/TYPEDEF/id-text
 *   - Index 2, name "obj-enum", type use of ari://ietf/amm-base/TYPEDEF/id-int
 *   - Index 3, name "action", type use of ari://ietf/amm-base/TYPEDEF/MAC
 *   - Index 4, name "start-time", type use of ari://ietf/amm-base/TYPEDEF/TIME
 *   - Index 5, name "period", type use of ari:/ARITYPE/TD
 *   - Index 6, name "max-count", type use of ari:/ARITYPE/UVAST
 *   - Index 7, name "init-enabled", type use of ari:/ARITYPE/BOOL
 *
 * Result name "res", type use of ari:/ARITYPE/UINT
 */
static void refda_adm_ietf_dtnma_agent_ctrl_ensure_tbr(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_tbr BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_tbr BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: ensure-rule-enabled
 * Description:
 *   Ensure rule is enabled or disabled.
 *
 * Parameters list:
 *   - Index 0, name "obj-id", type union of 2 types (use of ari:/ARITYPE/SBR, use of ari:/ARITYPE/TBR)
 *   - Index 1, name "enabled", type use of ari:/ARITYPE/BOOL
 *
 * Result name "res", type use of ari:/ARITYPE/UINT
 */
static void refda_adm_ietf_dtnma_agent_ctrl_ensure_rule_enabled(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_rule_enabled BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_ensure_rule_enabled BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: reset-rule-enabled
 * Description:
 *   Reset rule enabled to initial setting.
 *
 * Parameters list:
 *   - Index 0, name "obj-id", type union of 2 types (use of ari:/ARITYPE/SBR, use of ari:/ARITYPE/TBR)
 *
 * Result name "res", type use of ari:/ARITYPE/UINT
 */
static void refda_adm_ietf_dtnma_agent_ctrl_reset_rule_enabled(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_reset_rule_enabled BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_reset_rule_enabled BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: obsolete-rule
 * Description:
 *   Mark a specific SBR or TBR as obsolete if it is present in an ODM.
 *
 * Parameters list:
 *   - Index 0, name "obj-id", type union of 2 types (use of ari:/ARITYPE/SBR, use of ari:/ARITYPE/TBR)
 *
 * Result name "success", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_ctrl_obsolete_rule(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_obsolete_rule BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_ctrl_obsolete_rule BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: negate
 * Description:
 *   Negate a value. This is equivalent to multiplying by -1 but a shorter
 *   expression.
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/NUMERIC
 */
static void refda_adm_ietf_dtnma_agent_oper_negate(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_negate BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_negate BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: add
 * Description:
 *   Add two numeric values. The operands are cast to the least compatible
 *   numeric type before the arithmetic.
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/any
 */
static void refda_adm_ietf_dtnma_agent_oper_add(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_add BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_add BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: sub
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/any
 */
static void refda_adm_ietf_dtnma_agent_oper_sub(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_sub BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_sub BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: multiply
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/any
 */
static void refda_adm_ietf_dtnma_agent_oper_multiply(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_multiply BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_multiply BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: divide
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/any
 */
static void refda_adm_ietf_dtnma_agent_oper_divide(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_divide BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_divide BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: remainder
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/NUMERIC
 */
static void refda_adm_ietf_dtnma_agent_oper_remainder(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_remainder BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_remainder BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: bit-not
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/INTEGER
 */
static void refda_adm_ietf_dtnma_agent_oper_bit_not(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bit_not BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bit_not BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: bit-and
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/INTEGER
 */
static void refda_adm_ietf_dtnma_agent_oper_bit_and(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bit_and BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bit_and BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: bit-or
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/INTEGER
 */
static void refda_adm_ietf_dtnma_agent_oper_bit_or(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bit_or BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bit_or BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: bit-xor
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari://ietf/amm-base/TYPEDEF/INTEGER
 */
static void refda_adm_ietf_dtnma_agent_oper_bit_xor(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bit_xor BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bit_xor BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: bool-not
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_bool_not(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bool_not BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bool_not BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: bool-and
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_bool_and(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bool_and BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bool_and BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: bool-or
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_bool_or(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bool_or BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bool_or BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: bool-xor
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_bool_xor(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bool_xor BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_bool_xor BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: compare-eq
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_compare_eq(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_eq BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_eq BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: compare-ne
 * Description MISSING
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_compare_ne(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_ne BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_ne BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: compare-gt
 * Description:
 *   Compare two numbers by value. The result is true if the left value is
 *   greater than the right value. The operands are cast to the least
 *   compatible numeric type before the comparison.
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_compare_gt(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_gt BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_gt BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: compare-ge
 * Description:
 *   Compare two numbers by value. The result is true if the left value is
 *   greater than or equal to the right. The operands are cast to the least
 *   compatible numeric type before the comparison.
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_compare_ge(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_ge BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_ge BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: compare-lt
 * Description:
 *   Compare two operands by value. The result is true if the left value is
 *   less than the right. The operands are cast to the least compatible
 *   numeric type before the comparison.
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_compare_lt(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_lt BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_lt BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: compare-le
 * Description:
 *   Compare two operands by value. The result is true if the left value is
 *   less than or equal to the right. The operands are cast to the least
 *   compatible numeric type before the comparison.
 *
 * Parameters: none
 *
 * Result name "result", type use of ari:/ARITYPE/BOOL
 */
static void refda_adm_ietf_dtnma_agent_oper_compare_le(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_le BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_compare_le BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: tbl-filter
 * Description:
 *   Filter a table first by rows and then by columns.
 *
 * Parameters list:
 *   - Index 0, name "row-match", type use of ari://ietf/amm-base/TYPEDEF/EXPR
 *   - Index 1, name "columns", type ulist of use of ari:/ARITYPE/UVAST
 *
 * Result name "out", type use of ari:/ARITYPE/TBL
 */
static void refda_adm_ietf_dtnma_agent_oper_tbl_filter(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_tbl_filter BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_tbl_filter BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: list-get
 * Description:
 *   Retrieve an item from the given list.
 *
 * Parameters list:
 *   - Index 0, name "index", type use of ari://ietf/amm-base/TYPEDEF/INTEGER
 *
 * Result name "out", type use of ari://ietf/amm-base/TYPEDEF/any
 */
static void refda_adm_ietf_dtnma_agent_oper_list_get(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_list_get BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_list_get BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: map-get
 * Description:
 *   Retrieve an item from the given map.
 *
 * Parameters list:
 *   - Index 0, name "key", type use of ari://ietf/amm-base/TYPEDEF/primitive
 *
 * Result name "out", type use of ari://ietf/amm-base/TYPEDEF/any
 */
static void refda_adm_ietf_dtnma_agent_oper_map_get(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_map_get BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_ietf_dtnma_agent_oper_map_get BODY
	 * +-------------------------------------------------------------------------+
	 */
}

int refda_adm_ietf_dtnma_agent_init(refda_agent_t *agent)
{
    CHKERR1(agent);
    CACE_LOG_DEBUG("Registering ADM: " "ietf-dtnma-agent");
    REFDA_AGENT_LOCK(agent, REFDA_AGENT_ERR_LOCK_FAILED);

    cace_amm_obj_ns_t *adm = cace_amm_obj_store_add_ns(
        &(agent->objs), cace_amm_idseg_ref_withenum("ietf", 1),
        cace_amm_idseg_ref_withenum("dtnma-agent", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_ADM), "2025-07-03");
    if (adm)
    {
        cace_amm_obj_desc_t *obj;
        (void)obj;

        /**
         * Register CONST objects
         */
        { // For ./CONST/hello
            refda_amm_const_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_const_desc_t));
            refda_amm_const_desc_init(objdata);
            // constant value:
            {
                cace_ari_ac_t acinit;
                cace_ari_ac_init(&acinit);
                {
                    cace_ari_t *item = cace_ari_list_push_back_new(acinit.items);
                    // reference to ari://ietf/dtnma-agent/EDD/sw-vendor
                    cace_ari_set_objref_path_intid(item, 1, 1, CACE_ARI_TYPE_EDD, 0);
                }
                {
                    cace_ari_t *item = cace_ari_list_push_back_new(acinit.items);
                    // reference to ari://ietf/dtnma-agent/EDD/sw-version
                    cace_ari_set_objref_path_intid(item, 1, 1, CACE_ARI_TYPE_EDD, 1);
                }
                {
                    cace_ari_t *item = cace_ari_list_push_back_new(acinit.items);
                    // reference to ari://ietf/dtnma-agent/EDD/capability
                    cace_ari_set_objref_path_intid(item, 1, 1, CACE_ARI_TYPE_EDD, 2);
                }
                cace_ari_set_ac(&(objdata->value), &acinit);
            }

            obj = refda_register_const(adm, cace_amm_idseg_ref_withenum("hello", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CONST_HELLO), objdata);
            // no parameters
        }

        /**
         * Register EDD objects
         */
        { // For ./EDD/sw-vendor
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/TEXTSTR
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TEXTSTR);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_sw_vendor;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("sw-vendor", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_SW_VENDOR), objdata);
            // no parameters
        }
        { // For ./EDD/sw-version
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/TEXTSTR
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TEXTSTR);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_sw_version;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("sw-version", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_SW_VERSION), objdata);
            // no parameters
        }
        { // For ./EDD/capability
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                // table template
                cace_amm_semtype_tblt_t *semtype = cace_amm_type_set_tblt_size(&(objdata->prod_type), 6);
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 0);
                    m_string_set_cstr(col->name, "org-name");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/TEXTSTR
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TEXTSTR);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 1);
                    m_string_set_cstr(col->name, "org-enum");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/VAST
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_VAST);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 2);
                    m_string_set_cstr(col->name, "model-name");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/TEXTSTR
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TEXTSTR);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 3);
                    m_string_set_cstr(col->name, "model-enum");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/VAST
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_VAST);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 4);
                    m_string_set_cstr(col->name, "revision");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/TEXTSTR
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TEXTSTR);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 5);
                    m_string_set_cstr(col->name, "features");
                    {
                        // uniform list
                        cace_amm_semtype_ulist_t *semtype_d1 = cace_amm_type_set_ulist(&(col->typeobj));
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/TEXTSTR
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TEXTSTR);
                            cace_amm_type_set_use_ref_move(&(semtype_d1->item_type), &typeref);
                        }
                    }
                }
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_capability;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("capability", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_CAPABILITY), objdata);
            // no parameters
        }
        { // For ./EDD/num-msg-rx
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/counter64
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 12);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_num_msg_rx;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("num-msg-rx", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_NUM_MSG_RX), objdata);
            // no parameters
        }
        { // For ./EDD/num-msg-rx-failed
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/counter64
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 12);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_num_msg_rx_failed;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("num-msg-rx-failed", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_NUM_MSG_RX_FAILED), objdata);
            // no parameters
        }
        { // For ./EDD/num-msg-tx
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/counter64
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 12);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_num_msg_tx;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("num-msg-tx", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_NUM_MSG_TX), objdata);
            // no parameters
        }
        { // For ./EDD/num-msg-tx-failed
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/counter64
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 12);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_num_msg_tx_failed;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("num-msg-tx-failed", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_NUM_MSG_TX_FAILED), objdata);
            // no parameters
        }
        { // For ./EDD/last-msg-rx-time
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/TP
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TP);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_last_msg_rx_time;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("last-msg-rx-time", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_LAST_MSG_RX_TIME), objdata);
            // no parameters
        }
        { // For ./EDD/num-exec-started
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/counter64
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 12);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_num_exec_started;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("num-exec-started", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_NUM_EXEC_STARTED), objdata);
            // no parameters
        }
        { // For ./EDD/num-exec-succeeded
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/counter64
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 12);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_num_exec_succeeded;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("num-exec-succeeded", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_NUM_EXEC_SUCCEEDED), objdata);
            // no parameters
        }
        { // For ./EDD/num-exec-failed
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/counter64
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 12);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &typeref);
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_num_exec_failed;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("num-exec-failed", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_NUM_EXEC_FAILED), objdata);
            // no parameters
        }
        { // For ./EDD/exec-running
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                // table template
                cace_amm_semtype_tblt_t *semtype = cace_amm_type_set_tblt_size(&(objdata->prod_type), 3);
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 0);
                    m_string_set_cstr(col->name, "pid");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/UVAST
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UVAST);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 1);
                    m_string_set_cstr(col->name, "target");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-base/TYPEDEF/any
                        cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 2);
                    m_string_set_cstr(col->name, "state");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/BYTE
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BYTE);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);

                        cace_amm_semtype_cnst_t *cnst;
                        {
                            // Constraint: IntegerEnums(values={0: 'waiting', 1: 'running'})
                            cnst = cace_amm_semtype_cnst_array_push_new(((cace_amm_semtype_use_t *)(&(col->typeobj))->as_semtype)->constraints);
                            cace_amm_semtype_cnst_init(cnst);
                            // FIXME unhandled constraint IntegerEnums(values={0: 'waiting', 1: 'running'})
                        }
                    }
                }
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_exec_running;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("exec-running", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_EXEC_RUNNING), objdata);
            // no parameters
        }
        { // For ./EDD/odm-list
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                // table template
                cace_amm_semtype_tblt_t *semtype = cace_amm_type_set_tblt_size(&(objdata->prod_type), 5);
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 0);
                    m_string_set_cstr(col->name, "org-name");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-base/TYPEDEF/id-text
                        cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 25);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 1);
                    m_string_set_cstr(col->name, "org-enum");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-base/TYPEDEF/id-int
                        cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 26);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 2);
                    m_string_set_cstr(col->name, "model-name");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-base/TYPEDEF/id-text
                        cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 25);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 3);
                    m_string_set_cstr(col->name, "model-enum");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-base/TYPEDEF/id-int
                        cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 26);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 4);
                    m_string_set_cstr(col->name, "revision");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/TEXTSTR
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TEXTSTR);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_odm_list;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("odm-list", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_ODM_LIST), objdata);
            // no parameters
        }
        { // For ./EDD/typedef-list
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                // table template
                cace_amm_semtype_tblt_t *semtype = cace_amm_type_set_tblt_size(&(objdata->prod_type), 1);
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 0);
                    m_string_set_cstr(col->name, "obj");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/TYPEDEF
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TYPEDEF);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_typedef_list;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("typedef-list", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_TYPEDEF_LIST), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "include-adm");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
                cace_ari_set_bool(&(fparam->defval), false);
            }
        }
        { // For ./EDD/const-list
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                // table template
                cace_amm_semtype_tblt_t *semtype = cace_amm_type_set_tblt_size(&(objdata->prod_type), 2);
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 0);
                    m_string_set_cstr(col->name, "obj");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/CONST
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_CONST);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 1);
                    m_string_set_cstr(col->name, "type");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-semtype/TYPEDEF/semtype
                        cace_ari_set_objref_path_intid(&typeref, 1, 24, CACE_ARI_TYPE_TYPEDEF, 25);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_const_list;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("const-list", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_CONST_LIST), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "include-adm");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
                cace_ari_set_bool(&(fparam->defval), false);
            }
        }
        { // For ./EDD/var-list
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                // table template
                cace_amm_semtype_tblt_t *semtype = cace_amm_type_set_tblt_size(&(objdata->prod_type), 2);
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 0);
                    m_string_set_cstr(col->name, "obj");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/VAR
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_VAR);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 1);
                    m_string_set_cstr(col->name, "type");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-semtype/TYPEDEF/semtype
                        cace_ari_set_objref_path_intid(&typeref, 1, 24, CACE_ARI_TYPE_TYPEDEF, 25);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_var_list;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("var-list", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_VAR_LIST), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "include-adm");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
                cace_ari_set_bool(&(fparam->defval), false);
            }
        }
        { // For ./EDD/sbr-list
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                // table template
                cace_amm_semtype_tblt_t *semtype = cace_amm_type_set_tblt_size(&(objdata->prod_type), 7);
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 0);
                    m_string_set_cstr(col->name, "obj");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/SBR
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_SBR);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 1);
                    m_string_set_cstr(col->name, "action");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-base/TYPEDEF/MAC
                        cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 21);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 2);
                    m_string_set_cstr(col->name, "condition");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-base/TYPEDEF/EXPR
                        cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 18);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 3);
                    m_string_set_cstr(col->name, "min-interval");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/TD
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TD);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 4);
                    m_string_set_cstr(col->name, "max-count");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/UVAST
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UVAST);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 5);
                    m_string_set_cstr(col->name, "init-enabled");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/BOOL
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 6);
                    m_string_set_cstr(col->name, "enabled");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/BOOL
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_sbr_list;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("sbr-list", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_SBR_LIST), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "include-adm");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
                cace_ari_set_bool(&(fparam->defval), false);
            }
        }
        { // For ./EDD/tbr-list
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                // table template
                cace_amm_semtype_tblt_t *semtype = cace_amm_type_set_tblt_size(&(objdata->prod_type), 7);
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 0);
                    m_string_set_cstr(col->name, "obj");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/TBR
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TBR);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 1);
                    m_string_set_cstr(col->name, "action");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-base/TYPEDEF/MAC
                        cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 21);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 2);
                    m_string_set_cstr(col->name, "start-time");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/amm-base/TYPEDEF/TIME
                        cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 5);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 3);
                    m_string_set_cstr(col->name, "period");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/TD
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TD);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 4);
                    m_string_set_cstr(col->name, "max-count");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/UVAST
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UVAST);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 5);
                    m_string_set_cstr(col->name, "init-enabled");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/BOOL
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
                {
                    cace_amm_named_type_t *col = cace_amm_named_type_array_get(semtype->columns, 6);
                    m_string_set_cstr(col->name, "enabled");
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/BOOL
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                        cace_amm_type_set_use_ref_move(&(col->typeobj), &typeref);
                    }
                }
            }
            // callback:
            objdata->produce = refda_adm_ietf_dtnma_agent_edd_tbr_list;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("tbr-list", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_EDD_TBR_LIST), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "include-adm");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
                cace_ari_set_bool(&(fparam->defval), false);
            }
        }

        /**
         * Register CTRL objects
         */
        { // For ./CTRL/if-then-else
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_if_then_else;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("if-then-else", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_IF_THEN_ELSE), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "condition");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/eval-tgt
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 16);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "on-truthy");
                {
                    // union
                    cace_amm_semtype_union_t *semtype = cace_amm_type_set_union_size(&(fparam->typeobj), 2);
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 0);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // reference to ari://ietf/amm-base/TYPEDEF/exec-tgt
                            cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 19);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 1);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/NULL
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_NULL);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                }
                cace_ari_set_null(&(fparam->defval));
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "on-falsy");
                {
                    // union
                    cace_amm_semtype_union_t *semtype = cace_amm_type_set_union_size(&(fparam->typeobj), 2);
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 0);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // reference to ari://ietf/amm-base/TYPEDEF/exec-tgt
                            cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 19);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 1);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/NULL
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_NULL);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                }
                cace_ari_set_null(&(fparam->defval));
            }
        }
        { // For ./CTRL/catch
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_catch;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("catch", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_CATCH), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "try");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/exec-tgt
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 19);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "on-failure");
                {
                    // union
                    cace_amm_semtype_union_t *semtype = cace_amm_type_set_union_size(&(fparam->typeobj), 2);
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 0);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // reference to ari://ietf/amm-base/TYPEDEF/exec-tgt
                            cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 19);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 1);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/NULL
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_NULL);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                }
                cace_ari_set_null(&(fparam->defval));
            }
        }
        { // For ./CTRL/wait-for
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_wait_for;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("wait-for", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_WAIT_FOR), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "duration");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/TD
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TD);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/wait-until
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_wait_until;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("wait-until", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_WAIT_UNTIL), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "time");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/TP
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TP);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/wait-cond
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_wait_cond;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("wait-cond", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_WAIT_COND), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "condition");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/eval-tgt
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 16);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/inspect
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/any
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_inspect;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("inspect", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_INSPECT), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "ref");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/VALUE-OBJ
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 9);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/report-on
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_report_on;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("report-on", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_REPORT_ON), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "template");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/rpt-tgt
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 22);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "destinations");
                {
                    // uniform list
                    cace_amm_semtype_ulist_t *semtype = cace_amm_type_set_ulist(&(fparam->typeobj));
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // reference to ari://ietf/network-base/TYPEDEF/endpoint-or-uri
                        cace_ari_set_objref_path_intid(&typeref, 1, 26, CACE_ARI_TYPE_TYPEDEF, 3);
                        cace_amm_type_set_use_ref_move(&(semtype->item_type), &typeref);
                    }
                }
                {
                    cace_ari_ac_t acinit;
                    cace_ari_ac_init(&acinit);
                    cace_ari_set_ac(&(fparam->defval), &acinit);
                }
            }
        }
        { // For ./CTRL/ensure-odm
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_ensure_odm;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("ensure-odm", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_ENSURE_ODM), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "org-name");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-text
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 25);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "org-id");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-int
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 26);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "model-name");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-text
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 25);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);

                    cace_amm_semtype_cnst_t *cnst;
                    {
                        // Constraint: TextPattern(pattern='!.+')
                        cnst = cace_amm_semtype_cnst_array_push_new(((cace_amm_semtype_use_t *)(&(fparam->typeobj))->as_semtype)->constraints);
                        cace_amm_semtype_cnst_init(cnst);
                        cace_amm_semtype_cnst_t cnst;
                        cace_amm_semtype_cnst_init(&cnst);
                        cace_amm_semtype_cnst_set_textpat(&cnst, "!.+");
                    }
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "model-id");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-int
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 26);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);

                    cace_amm_semtype_cnst_t *cnst;
                    {
                        // Constraint: NumericRange(ranges=[-inf,-1])
                        cnst = cace_amm_semtype_cnst_array_push_new(((cace_amm_semtype_use_t *)(&(fparam->typeobj))->as_semtype)->constraints);
                        cace_amm_semtype_cnst_init(cnst);
                        cace_amm_range_size_t *range = cace_amm_semtype_cnst_set_range_int64(cnst);
                        {
                            cace_amm_range_intvl_int64_t intvl;
                            cace_amm_range_intvl_int64_set_infinite(&intvl);
                            cace_amm_range_intvl_int64_set_max(&intvl, -1);
                            cace_amm_range_intvl_int64_seq_push(range->intvls, intvl);
                        }
                    }
                }
            }
        }
        { // For ./CTRL/obsolete-odm
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_obsolete_odm;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("obsolete-odm", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_OBSOLETE_ODM), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "odm-ns");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/NAMESPACE
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_NAMESPACE);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/var-reset
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_var_reset;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("var-reset", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_VAR_RESET), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "target");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/VAR
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_VAR);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/var-store
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_var_store;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("var-store", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_VAR_STORE), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "target");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/VAR
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_VAR);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "value");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/ensure-const
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_ensure_const;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("ensure-const", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_ENSURE_CONST), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "namespace");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/NAMESPACE
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_NAMESPACE);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-name");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-text
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 25);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-enum");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-int
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 26);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "type");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-semtype/TYPEDEF/semtype
                    cace_ari_set_objref_path_intid(&typeref, 1, 24, CACE_ARI_TYPE_TYPEDEF, 25);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "value");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/obsolete-const
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_obsolete_const;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("obsolete-const", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_OBSOLETE_CONST), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/CONST
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_CONST);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/ensure-var
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_ensure_var;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("ensure-var", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_ENSURE_VAR), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "namespace");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/NAMESPACE
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_NAMESPACE);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-name");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-text
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 25);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-enum");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-int
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 26);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "type");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-semtype/TYPEDEF/semtype
                    cace_ari_set_objref_path_intid(&typeref, 1, 24, CACE_ARI_TYPE_TYPEDEF, 25);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "init-value");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/obsolete-var
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // no result type
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_obsolete_var;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("obsolete-var", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_OBSOLETE_VAR), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/VAR
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_VAR);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/ensure-sbr
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/UINT
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UINT);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_ensure_sbr;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("ensure-sbr", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_ENSURE_SBR), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "namespace");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/NAMESPACE
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_NAMESPACE);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-name");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-text
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 25);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-enum");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-int
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 26);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "action");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/MAC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 21);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "condition");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/EXPR
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 18);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "min-interval");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/TD
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TD);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "max-count");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/UVAST
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UVAST);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "init-enabled");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/ensure-tbr
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/UINT
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UINT);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_ensure_tbr;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("ensure-tbr", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_ENSURE_TBR), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "namespace");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/NAMESPACE
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_NAMESPACE);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-name");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-text
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 25);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-enum");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/id-int
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 26);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "action");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/MAC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 21);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "start-time");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/TIME
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 5);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "period");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/TD
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TD);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "max-count");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/UVAST
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UVAST);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "init-enabled");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/ensure-rule-enabled
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/UINT
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UINT);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_ensure_rule_enabled;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("ensure-rule-enabled", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_ENSURE_RULE_ENABLED), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-id");
                {
                    // union
                    cace_amm_semtype_union_t *semtype = cace_amm_type_set_union_size(&(fparam->typeobj), 2);
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 0);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/SBR
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_SBR);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 1);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/TBR
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TBR);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "enabled");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./CTRL/reset-rule-enabled
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/UINT
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UINT);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_reset_rule_enabled;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("reset-rule-enabled", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_RESET_RULE_ENABLED), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-id");
                {
                    // union
                    cace_amm_semtype_union_t *semtype = cace_amm_type_set_union_size(&(fparam->typeobj), 2);
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 0);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/SBR
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_SBR);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 1);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/TBR
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TBR);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                }
            }
        }
        { // For ./CTRL/obsolete-rule
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->execute = refda_adm_ietf_dtnma_agent_ctrl_obsolete_rule;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("obsolete-rule", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_CTRL_OBSOLETE_RULE), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "obj-id");
                {
                    // union
                    cace_amm_semtype_union_t *semtype = cace_amm_type_set_union_size(&(fparam->typeobj), 2);
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 0);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/SBR
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_SBR);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                    {
                        cace_amm_type_t *choice = cace_amm_type_array_get(semtype->choices, 1);
                        {
                            cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                            // use of ari:/ARITYPE/TBR
                            cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TBR);
                            cace_amm_type_set_use_ref_move(choice, &typeref);
                        }
                    }
                }
            }
        }

        /**
         * Register OPER objects
         */
        { // For ./OPER/negate
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 1);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "val");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_negate;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("negate", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_NEGATE), objdata);
            // no parameters
        }
        { // For ./OPER/add
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/any
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_add;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("add", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_ADD), objdata);
            // no parameters
        }
        { // For ./OPER/sub
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/any
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_sub;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("sub", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_SUB), objdata);
            // no parameters
        }
        { // For ./OPER/multiply
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/any
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_multiply;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("multiply", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_MULTIPLY), objdata);
            // no parameters
        }
        { // For ./OPER/divide
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/any
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_divide;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("divide", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_DIVIDE), objdata);
            // no parameters
        }
        { // For ./OPER/remainder
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_remainder;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("remainder", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_REMAINDER), objdata);
            // no parameters
        }
        { // For ./OPER/bit-not
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 1);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "val");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_bit_not;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("bit-not", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_BIT_NOT), objdata);
            // no parameters
        }
        { // For ./OPER/bit-and
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_bit_and;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("bit-and", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_BIT_AND), objdata);
            // no parameters
        }
        { // For ./OPER/bit-or
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_bit_or;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("bit-or", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_BIT_OR), objdata);
            // no parameters
        }
        { // For ./OPER/bit-xor
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_bit_xor;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("bit-xor", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_BIT_XOR), objdata);
            // no parameters
        }
        { // For ./OPER/bool-not
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 1);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "val");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_bool_not;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("bool-not", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_BOOL_NOT), objdata);
            // no parameters
        }
        { // For ./OPER/bool-and
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_bool_and;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("bool-and", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_BOOL_AND), objdata);
            // no parameters
        }
        { // For ./OPER/bool-or
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_bool_or;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("bool-or", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_BOOL_OR), objdata);
            // no parameters
        }
        { // For ./OPER/bool-xor
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/BOOL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_bool_xor;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("bool-xor", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_BOOL_XOR), objdata);
            // no parameters
        }
        { // For ./OPER/compare-eq
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_compare_eq;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("compare-eq", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_COMPARE_EQ), objdata);
            // no parameters
        }
        { // For ./OPER/compare-ne
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/any
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_compare_ne;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("compare-ne", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_COMPARE_NE), objdata);
            // no parameters
        }
        { // For ./OPER/compare-gt
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_compare_gt;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("compare-gt", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_COMPARE_GT), objdata);
            // no parameters
        }
        { // For ./OPER/compare-ge
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_compare_ge;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("compare-ge", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_COMPARE_GE), objdata);
            // no parameters
        }
        { // For ./OPER/compare-lt
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_compare_lt;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("compare-lt", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_COMPARE_LT), objdata);
            // no parameters
        }
        { // For ./OPER/compare-le
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "left");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                m_string_set_cstr(operand->name, "right");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/NUMERIC
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 3);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/BOOL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_BOOL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_compare_le;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("compare-le", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_COMPARE_LE), objdata);
            // no parameters
        }
        { // For ./OPER/tbl-filter
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 1);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "in");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/TBL
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TBL);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // use of ari:/ARITYPE/TBL
                cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_TBL);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_tbl_filter;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("tbl-filter", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_TBL_FILTER), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "row-match");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/EXPR
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 18);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "columns");
                {
                    // uniform list
                    cace_amm_semtype_ulist_t *semtype = cace_amm_type_set_ulist(&(fparam->typeobj));
                    {
                        cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                        // use of ari:/ARITYPE/UVAST
                        cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_UVAST);
                        cace_amm_type_set_use_ref_move(&(semtype->item_type), &typeref);
                    }
                }
            }
        }
        { // For ./OPER/list-get
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 1);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "in");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/AC
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_AC);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/any
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_list_get;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("list-get", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_LIST_GET), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "index");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/INTEGER
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 1);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
        { // For ./OPER/map-get
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 1);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                m_string_set_cstr(operand->name, "in");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // use of ari:/ARITYPE/AM
                    cace_ari_set_aritype(&typeref, CACE_ARI_TYPE_AM);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &typeref);
                }
            }
            // result type:
            {
                cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                // reference to ari://ietf/amm-base/TYPEDEF/any
                cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 8);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &typeref);
            }
            // callback:
            objdata->evaluate = refda_adm_ietf_dtnma_agent_oper_map_get;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("map-get", REFDA_ADM_IETF_DTNMA_AGENT_ENUM_OBJID_OPER_MAP_GET), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "key");
                {
                    cace_ari_t typeref = CACE_ARI_INIT_UNDEFINED;
                    // reference to ari://ietf/amm-base/TYPEDEF/primitive
                    cace_ari_set_objref_path_intid(&typeref, 1, 25, CACE_ARI_TYPE_TYPEDEF, 4);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &typeref);
                }
            }
        }
    }
    REFDA_AGENT_UNLOCK(agent, REFDA_AGENT_ERR_LOCK_FAILED);
    return 0;
}

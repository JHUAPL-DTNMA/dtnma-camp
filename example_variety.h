/** @file
 * This is the header for the implementation of the
 * ADM module "example-variety" for the C-language reference DA.
 * This contains defines for each enumeration in the ADM and
 * declarations of module-level initialization functions.
 */

#ifndef REFDA_ADM_EXAMPLE_VARIETY_H_
#define REFDA_ADM_EXAMPLE_VARIETY_H_

#include "refda/agent.h"
#include <cace/util/defs.h>

/*   START CUSTOM INCLUDES HERE  */
/*             TODO              */
/*   STOP CUSTOM INCLUDES HERE  */

#ifdef __cplusplus
extern "C" {
#endif

/// Enumeration of the ADM itself
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_ADM 9999

/*
 * Enumerations for TYPEDEF objects
 */
/// For ./TYPEDEF/counter32
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_TYPEDEF_COUNTER32 26

/*
 * Enumerations for CONST objects
 */
/// For ./CONST/const1
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_CONST_CONST1 0
/// For ./CONST/showall
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_CONST_SHOWALL 1

/*
 * Enumerations for VAR objects
 */
/// For ./VAR/var_uvast_val
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_VAR_VAR__UVAST__VAL 0

/*
 * Enumerations for EDD objects
 */
/// For ./EDD/edd_uvast
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_EDD_EDD__UVAST 0
/// For ./EDD/edd_uvast_param
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_EDD_EDD__UVAST__PARAM 1
/// For ./EDD/edd_tp
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_EDD_EDD__TP 2
/// For ./EDD/endpoint_active
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_EDD_ENDPOINT__ACTIVE 3

/*
 * Enumerations for CTRL objects
 */
/// For ./CTRL/get
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_CTRL_GET 2
/// For ./CTRL/set
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_CTRL_SET 3

/*
 * Enumerations for OPER objects
 */
/// For ./OPER/add
#define REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_OPER_ADD 0

/** Initializer for the ADM module example-variety.
 * @param[in,out] agent The agent to register this namespace and its
 * objects within.
 * @return Zero upon success.
 */
int refda_adm_example_variety_init(refda_agent_t *agent);

#ifdef __cplusplus
}
#endif

#endif /* REFDA_ADM_EXAMPLE_VARIETY_H_ */

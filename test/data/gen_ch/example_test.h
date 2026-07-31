/*  START GENERATED SOURCE HERE */
/** @file
 * This is the header for the implementation of the
 * ADM module "example-test" for the C-language reference DA.
 * This contains defines for each enumeration in the ADM and
 * declarations of module-level initialization functions.
 */

#ifndef REFDA_ADM_EXAMPLE_TEST_H_
#define REFDA_ADM_EXAMPLE_TEST_H_

#include "refda/agent.h"

#include "cace/util/defs.h"

/*   START CUSTOM INCLUDES HERE */
/*             NONE             */
/*   STOP CUSTOM INCLUDES HERE  */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Defines for the ADM itself
 */
/// Text name of the organization
#define REFDA_ADM_EXAMPLE_TEST_ORG_NAME "example"
/// Enumeration of the organization
#define REFDA_ADM_EXAMPLE_TEST_ORG_ENUM 65535
/// Text name of the model
#define REFDA_ADM_EXAMPLE_TEST_MODEL_NAME "test"
/// Enumeration of the model
#define REFDA_ADM_EXAMPLE_TEST_MODEL_ENUM 9999
/// Revision date for the model
#define REFDA_ADM_EXAMPLE_TEST_MODEL_REVISION "2024-11-21"
/// @deprecated use REFDA_ADM_EXAMPLE_TEST_MODEL_ENUM directly
#define REFDA_ADM_EXAMPLE_TEST_ENUM_ADM REFDA_ADM_EXAMPLE_TEST_MODEL_ENUM

/*
 * Enumerations for TYPEDEF objects
 */
/// For ./TYPEDEF/counter32
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_TYPEDEF_COUNTER32 26
/// For ./TYPEDEF/gauge32
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_TYPEDEF_GAUGE32 27
/// For ./TYPEDEF/counter64
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_TYPEDEF_COUNTER64 28
/// For ./TYPEDEF/gauge64
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_TYPEDEF_GAUGE64 29

/*
 * Enumerations for CONST objects
 */
/// For ./CONST/const1
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_CONST_CONST1 0
/// For ./CONST/showall
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_CONST_SHOWALL 1

/*
 * Enumerations for VAR objects
 */
/// For ./VAR/var_uvast_val
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_VAR_VAR__UVAST__VAL 0

/*
 * Enumerations for EDD objects
 */
/// For ./EDD/edd_uvast
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_EDD_EDD__UVAST 0
/// For ./EDD/edd_uvast_param
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_EDD_EDD__UVAST__PARAM 1
/// For ./EDD/edd_ac_param
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_EDD_EDD__AC__PARAM 4
/// For ./EDD/edd_am_param
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_EDD_EDD__AM__PARAM 5
/// For ./EDD/edd_tbl_param
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_EDD_EDD__TBL__PARAM 6
/// For ./EDD/edd_tp
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_EDD_EDD__TP 2
/// For ./EDD/endpoint_active
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_EDD_ENDPOINT__ACTIVE 3

/*
 * Enumerations for CTRL objects
 */
/// For ./CTRL/get
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_CTRL_GET 2
/// For ./CTRL/set
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_CTRL_SET 3

/*
 * Enumerations for OPER objects
 */
/// For ./OPER/add
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_OPER_ADD 0
/// For ./OPER/compare-lt
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_OPER_COMPARE_LT 1

/*
 * Enumerations for SBR objects
 */
/// For ./SBR/sbr1
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_SBR_SBR1 8
/// For ./SBR/sbr2
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_SBR_SBR2 9

/*
 * Enumerations for TBR objects
 */
/// For ./TBR/tbr_rule
#define REFDA_ADM_EXAMPLE_TEST_ENUM_OBJID_TBR_TBR__RULE 30

/** Initializer for the ADM module example-test.
 * @param[in,out] agent The agent to register this namespace and its
 * objects within.
 * @return Zero upon success.
 */
int refda_adm_example_test_init(refda_agent_t *agent);

#ifdef __cplusplus
} /* extern C */
#endif

#endif /* REFDA_ADM_EXAMPLE_TEST_H_ */
/*  STOP GENERATED SOURCE HERE */

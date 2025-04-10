/** @file
 * This is the compilation unit for the implementation of the
 * ADM module "example-variety" for the C-language reference DA.
 * This contains definitions of every AMM object instance in the ADM and
 * file-local callback functions for all EDDs, CTRLs, and OPERs.
 */

#include "example_variety.h"
#include "refda/agent.h"
#include "refda/register.h"
#include "refda/edd_prod_ctx.h"
#include "refda/ctrl_exec_ctx.h"
#include "refda/oper_eval_ctx.h"
#include "refda/reporting.h"
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


/* Name: edd_uvast
 * Description:
 *   Example UVAST EDD.
 *
 * Parameters: none
 *
 * Produced type: use of ari:/ARITYPE/UVAST
 */
static void refda_adm_example_variety_edd_edd__uvast(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_example_variety_edd_edd__uvast BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_example_variety_edd_edd__uvast BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: edd_uvast_param
 * Description:
 *   Example UVAST EDD with parameters.
 *
 * Parameters list:
 *  * Index 0, name "text", type: use of ari:/ARITYPE/TEXTSTR
 *  * Index 1, name "ulist", type: ulist of use of ari:/ARITYPE/UINT
 *  * Index 2, name "dlist", type: FIXME unhandled type DiverseList(parts=[])
 *
 * Produced type: use of ari:/ARITYPE/UVAST
 */
static void refda_adm_example_variety_edd_edd__uvast__param(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_example_variety_edd_edd__uvast__param BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_example_variety_edd_edd__uvast__param BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: edd_tp
 * Description:
 *   Example TP EDD: current system time.
 *
 * Parameters: none
 *
 * Produced type: use of ari:/ARITYPE/TP
 */
static void refda_adm_example_variety_edd_edd__tp(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_example_variety_edd_edd__tp BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_example_variety_edd_edd__tp BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: endpoint_active
 * Description:
 *   Is the given endpoint active? (0=no)
 *
 * Parameters list:
 *  * Index 0, name "endpoint_name", type: use of ari:/ARITYPE/TEXTSTR
 *
 * Produced type: use of ari:/ARITYPE/UVAST
 */
static void refda_adm_example_variety_edd_endpoint__active(refda_edd_prod_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_example_variety_edd_endpoint__active BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_example_variety_edd_endpoint__active BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: get
 * Description:
 *   Get a single MIB value from the agent.
 *
 * Parameters list:
 *  * Index 0, name "object", type: use of ari:/ARITYPE/OBJECT
 *
 * Result name "data", type: use of ari:/ARITYPE/BYTESTR
 */
static void refda_adm_example_variety_ctrl_get(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_example_variety_ctrl_get BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_example_variety_ctrl_get BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: set
 * Description:
 *   Set a single MIB value in the agent.
 *
 * Parameters list:
 *  * Index 0, name "object", type: use of ari:/ARITYPE/OBJECT
 *  * Index 1, name "data", type: use of ari:/ARITYPE/BYTESTR
 *
 * Result name "errorcode", type: use of ari:/ARITYPE/BYTE
 */
static void refda_adm_example_variety_ctrl_set(refda_ctrl_exec_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_example_variety_ctrl_set BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_example_variety_ctrl_set BODY
	 * +-------------------------------------------------------------------------+
	 */
}


/* Name: add
 * Description:
 *   Add two uvast values. The operands are cast to the least compatible
 *   numeric type before the arithmetic.
 *
 * Parameters: none
 *
 * Result name "result", type: use of ari:/ARITYPE/UVAST
 */
static void refda_adm_example_variety_oper_add(refda_oper_eval_ctx_t *ctx)
{
	/*
	 * +-------------------------------------------------------------------------+
	 * |START CUSTOM FUNCTION refda_adm_example_variety_oper_add BODY
	 * +-------------------------------------------------------------------------+
	 */
	/*
	 * +-------------------------------------------------------------------------+
	 * |STOP CUSTOM FUNCTION refda_adm_example_variety_oper_add BODY
	 * +-------------------------------------------------------------------------+
	 */
}

int refda_adm_example_variety_init(refda_agent_t *agent)
{
    CHKERR1(agent);
    CACE_LOG_DEBUG("Registering ADM: " "example-variety");
    REFDA_AGENT_LOCK(agent, REFDA_AGENT_ERR_LOCK_FAILED);

    cace_amm_obj_ns_t *adm = cace_amm_obj_store_add_ns(
        &(agent->objs), cace_amm_idseg_ref_withenum("example", 65535),
        cace_amm_idseg_ref_withenum("variety", REFDA_ADM_EXAMPLE_VARIETY_ENUM_ADM), "2024-11-21");
    if (adm)
    {
        cace_amm_obj_desc_t *obj;

        /**
         * Register TYPEDEF objects
         */
        { // For ./TYPEDEF/counter32
            refda_amm_typedef_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_typedef_desc_t));
            refda_amm_typedef_desc_init(objdata);
            // named type:
            {
                cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                cace_ari_set_aritype(&name, CACE_ARI_TYPE_UINT);
                cace_amm_type_set_use_ref_move(&(objdata->typeobj), &name);
            }

            obj = refda_register_typedef(adm, cace_amm_idseg_ref_withenum("counter32", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_TYPEDEF_COUNTER32), objdata);
            // no parameters possible
        }

        /**
         * Register CONST objects
         */
        { // For ./CONST/const1
            refda_amm_const_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_const_desc_t));
            refda_amm_const_desc_init(objdata);
            // constant value:
            cace_ari_set_int(&(objdata->value), 31);

            obj = refda_register_const(adm, cace_amm_idseg_ref_withenum("const1", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_CONST_CONST1), objdata);
            // no parameters
        }
        { // For ./CONST/showall
            refda_amm_const_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_const_desc_t));
            refda_amm_const_desc_init(objdata);
            // constant value:
            {
                cace_ari_ac_t acinit0;
                cace_ari_ac_init(&acinit0);
                {
                    cace_ari_t *item0 = cace_ari_list_push_back_new(acinit0.items);
                    // ari://example/variety/CONST/const1
                    cace_ari_set_objref_path_intid(item0, 65535, 9999, CACE_ARI_TYPE_CONST, 0);
                }
                cace_ari_set_ac(&(objdata->value), &acinit0);
            }

            obj = refda_register_const(adm, cace_amm_idseg_ref_withenum("showall", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_CONST_SHOWALL), objdata);
            // no parameters
        }

        /**
         * Register VAR objects
         */
        { // For ./VAR/var_uvast_val
            refda_amm_var_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_var_desc_t));
            refda_amm_var_desc_init(objdata);
            // stored value type:
            {
                cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                cace_ari_set_aritype(&name, CACE_ARI_TYPE_UVAST);
                cace_amm_type_set_use_ref_move(&(objdata->val_type), &name);
            }
            // initial value:
            cace_ari_set_int(&(objdata->value), 34);

            obj = refda_register_var(adm, cace_amm_idseg_ref_withenum("var_uvast_val", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_VAR_VAR__UVAST__VAL), objdata);
            // no parameters
        }

        /**
         * Register EDD objects
         */
        { // For ./EDD/edd_uvast
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                cace_ari_set_aritype(&name, CACE_ARI_TYPE_UVAST);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &name);
            }
            // callback:
            objdata->produce = refda_adm_example_variety_edd_edd__uvast;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("edd_uvast", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_EDD_EDD__UVAST), objdata);
            // no parameters
        }
        { // For ./EDD/edd_uvast_param
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                cace_ari_set_aritype(&name, CACE_ARI_TYPE_UVAST);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &name);
            }
            // callback:
            objdata->produce = refda_adm_example_variety_edd_edd__uvast__param;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("edd_uvast_param", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_EDD_EDD__UVAST__PARAM), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "text");
                {
                    cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                    cace_ari_set_aritype(&name, CACE_ARI_TYPE_TEXTSTR);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &name);
                }
                cace_ari_set_tstr(&(fparam->defval), "\"value\"", true);
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "ulist");
                {
                    cace_amm_semtype_ulist_t *semtype = cace_amm_type_set_ulist(&(fparam->typeobj));
                    {
                        cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                        cace_ari_set_aritype(&name, CACE_ARI_TYPE_UINT);
                        cace_amm_type_set_use_ref_move(&(semtype->item_type), &name);
                    }
                    cace_amm_range_intvl_size_set_min(&(semtype->size), 1);
                    cace_amm_range_intvl_size_set_max(&(semtype->size), 2);
                }
                cace_ari_set_tstr(&(fparam->defval), "test", true);
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "dlist");
                
                // FIXME unhandled type DiverseList(parts=[])
                {
                    cace_ari_ac_t acinit0;
                    cace_ari_ac_init(&acinit0);
                    {
                        cace_ari_t *item0 = cace_ari_list_push_back_new(acinit0.items);
                        cace_ari_set_tstr(item0, "start", true);
                    }
                    {
                        cace_ari_t *item0 = cace_ari_list_push_back_new(acinit0.items);
                        cace_ari_set_int(item0, 0);
                    }
                    {
                        cace_ari_t *item0 = cace_ari_list_push_back_new(acinit0.items);
                        cace_ari_set_int(item0, 5);
                    }
                    {
                        cace_ari_t *item0 = cace_ari_list_push_back_new(acinit0.items);
                        cace_ari_set_tstr(item0, "end", true);
                    }
                    cace_ari_set_ac(&(fparam->defval), &acinit0);
                }
            }
        }
        { // For ./EDD/edd_tp
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                cace_ari_set_aritype(&name, CACE_ARI_TYPE_TP);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &name);
            }
            // callback:
            objdata->produce = refda_adm_example_variety_edd_edd__tp;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("edd_tp", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_EDD_EDD__TP), objdata);
            // no parameters
        }
        { // For ./EDD/endpoint_active
            refda_amm_edd_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_edd_desc_t));
            refda_amm_edd_desc_init(objdata);
            // produced type
            {
                cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                cace_ari_set_aritype(&name, CACE_ARI_TYPE_UVAST);
                cace_amm_type_set_use_ref_move(&(objdata->prod_type), &name);
            }
            // callback:
            objdata->produce = refda_adm_example_variety_edd_endpoint__active;

            obj = refda_register_edd(adm, cace_amm_idseg_ref_withenum("endpoint_active", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_EDD_ENDPOINT__ACTIVE), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "endpoint_name");
                {
                    cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                    cace_ari_set_aritype(&name, CACE_ARI_TYPE_TEXTSTR);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &name);
                }
            }
        }

        /**
         * Register CTRL objects
         */
        { // For ./CTRL/get
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                cace_ari_set_aritype(&name, CACE_ARI_TYPE_BYTESTR);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &name);
            }
            // callback:
            objdata->execute = refda_adm_example_variety_ctrl_get;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("get", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_CTRL_GET), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "object");
                {
                    cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                    cace_ari_set_aritype(&name, CACE_ARI_TYPE_OBJECT);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &name);
                }
                cace_ari_set_tstr(&(fparam->defval), "hello", true);
            }
        }
        { // For ./CTRL/set
            refda_amm_ctrl_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_ctrl_desc_t));
            refda_amm_ctrl_desc_init(objdata);
            // result type
            {
                cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                cace_ari_set_aritype(&name, CACE_ARI_TYPE_BYTE);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &name);
            }
            // callback:
            objdata->execute = refda_adm_example_variety_ctrl_set;

            obj = refda_register_ctrl(adm, cace_amm_idseg_ref_withenum("set", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_CTRL_SET), objdata);
            // parameters:
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "object");
                {
                    cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                    cace_ari_set_aritype(&name, CACE_ARI_TYPE_OBJECT);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &name);
                }
            }
            {
                cace_amm_formal_param_t *fparam = refda_register_add_param(obj, "data");
                {
                    cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                    cace_ari_set_aritype(&name, CACE_ARI_TYPE_BYTESTR);
                    cace_amm_type_set_use_ref_move(&(fparam->typeobj), &name);
                }
            }
        }

        /**
         * Register OPER objects
         */
        { // For ./OPER/add
            refda_amm_oper_desc_t *objdata = CACE_MALLOC(sizeof(refda_amm_oper_desc_t));
            refda_amm_oper_desc_init(objdata);
            // operands:
            cace_amm_named_type_array_resize(objdata->operand_types, 2);
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 0);
                string_set_str(operand->name, "left");
                {
                    cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                    cace_ari_set_aritype(&name, CACE_ARI_TYPE_UVAST);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &name);
                }
            }
            {
                cace_amm_named_type_t *operand = cace_amm_named_type_array_get(objdata->operand_types, 1);
                string_set_str(operand->name, "right");
                {
                    cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                    cace_ari_set_aritype(&name, CACE_ARI_TYPE_UVAST);
                    cace_amm_type_set_use_ref_move(&(operand->typeobj), &name);
                }
            }
            // result type:
            {
                cace_ari_t name = CACE_ARI_INIT_UNDEFINED;
                cace_ari_set_aritype(&name, CACE_ARI_TYPE_UVAST);
                cace_amm_type_set_use_ref_move(&(objdata->res_type), &name);
            }
            // callback:
            objdata->evaluate = refda_adm_example_variety_oper_add;

            obj = refda_register_oper(adm, cace_amm_idseg_ref_withenum("add", REFDA_ADM_EXAMPLE_VARIETY_ENUM_OBJID_OPER_ADD), objdata);
            // no parameters
        }

    }
    REFDA_AGENT_UNLOCK(agent, REFDA_AGENT_ERR_LOCK_FAILED);
    return 0;
}

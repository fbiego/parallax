/**
 * @file wd_parallax_gen.h
 *
 */

#ifndef WD_PARALLAX_GEN_H
#define WD_PARALLAX_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "src/core/lv_obj_class_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/src/core/lv_obj_class_private.h"
#endif

#include "../../parallax_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a wd_parallax object
 * @param parent pointer to an object, it will be the parent of the new wd_parallax
 * @return pointer to the created wd_parallax
 */
lv_obj_t * wd_parallax_create(lv_obj_t * parent);
/**
 * Subject to write back the title of the selected item
 * @param obj   pointer to a wd_parallax
 * @param bind_title  Subject to write back the title of the selected item
 */
void wd_parallax_bind_title(lv_obj_t * wd_parallax, lv_subject_t * bind_title);

/**
 * Subject to write back the description of the selected item
 * @param obj   pointer to a wd_parallax
 * @param bind_description  Subject to write back the description of the selected item
 */
void wd_parallax_bind_description(lv_obj_t * wd_parallax, lv_subject_t * bind_description);

/**
 * wd_parallax item
 * @param obj   pointer to a wd_parallax
 * @param icon  Foreground icon
 * @param background  Background icon
 */
lv_obj_t * wd_parallax_add_item(lv_obj_t * wd_parallax, const void * icon, const void * background);

/**
 * Title of the item
 * @param obj   pointer to a wd_parallax
 * @param item  item
 * @param title  Title of the item
 */
void wd_parallax_set_item_title(lv_obj_t * wd_parallax, lv_obj_t * item, const char * title);

/**
 * Description of the item
 * @param obj   pointer to a wd_parallax
 * @param item  item
 * @param description  Description of the item
 */
void wd_parallax_set_item_description(lv_obj_t * wd_parallax, lv_obj_t * item, const char * description);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_PARALLAX_GEN_H*/
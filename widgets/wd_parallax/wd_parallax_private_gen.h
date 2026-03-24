/**
 * @file wd_parallax_private_gen.h
 *
 */

#ifndef WD_PARALLAX_PRIVATE_H
#define WD_PARALLAX_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl_private.h"
#endif
#include "wd_parallax.h"

/*********************
 *      DEFINES
 *********************/

#ifndef WD_PARALLAX_USER_DATA
#define WD_PARALLAX_USER_DATA
#endif

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    lv_subject_t * bind_title;
    lv_subject_t * bind_description;
    WD_PARALLAX_USER_DATA
} wd_parallax_t;

extern const lv_obj_class_t wd_parallax_class;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_parallax_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_PARALLAX_PRIVATE_H*/
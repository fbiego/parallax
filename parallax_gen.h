/**
 * @file parallax_gen.h
 */

#ifndef PARALLAX_GEN_H
#define PARALLAX_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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



/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

extern lv_font_t * MS_Bold_20;

extern lv_font_t * MS_Regular_16;

/*----------------
 * Images
 *----------------*/

extern const void * foodnotes_logo;
extern const void * fortepan_logo;
extern const void * mo_logo;
extern const void * sketch_logo;
extern const void * ustream_logo;
extern const void * youate_logo;
extern const void * foodnotes_bg;
extern const void * fortepan_bg;
extern const void * mo_bg;
extern const void * sketch_bg;
extern const void * ustream_bg;
extern const void * youate_bg;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_title;
extern lv_subject_t subject_description;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void parallax_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "screens/main_gen.h"
#include "widgets/wd_parallax/wd_parallax_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*PARALLAX_GEN_H*/
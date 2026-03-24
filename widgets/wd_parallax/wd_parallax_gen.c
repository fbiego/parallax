/**
 * @file wd_parallax_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_parallax_private_gen.h"
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "src/core/lv_obj_class_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/src/core/lv_obj_class_private.h"
#endif
#include "../../parallax.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void wd_parallax_constructor_hook(lv_obj_t * obj);
void wd_parallax_destructor_hook(lv_obj_t * obj);
void wd_parallax_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_parallax_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_parallax_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_parallax_event(const lv_obj_class_t * class_p, lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_parallax_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_parallax_constructor,
    .destructor_cb = wd_parallax_destructor,
    .event_cb = wd_parallax_event,
    .instance_size = sizeof(wd_parallax_t),
    .editable = 1,
    .name = "wd_parallax"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * wd_parallax_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_parallax_class, parent);
    lv_obj_class_init_obj(obj);

    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/
static void wd_parallax_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_parallax_t * widget = (wd_parallax_t *)obj;
    static lv_style_t style_main;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_width(&style_main, lv_pct(100));
        lv_style_set_height(&style_main, lv_pct(100));
        lv_style_set_bg_opa(&style_main, 0);
        lv_style_set_pad_column(&style_main, 20);
        lv_style_set_layout(&style_main, LV_LAYOUT_FLEX);
        lv_style_set_flex_track_place(&style_main, LV_FLEX_ALIGN_CENTER);

        style_inited = true;
    }
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scroll_snap_x(obj, LV_SCROLL_SNAP_START);

    lv_obj_add_style(obj, &style_main, 0);


    wd_parallax_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_parallax_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_parallax_destructor_hook(obj);
}

static void wd_parallax_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_parallax_class, e);
    if(res != LV_RESULT_OK) return;

    wd_parallax_event_hook(e);
}


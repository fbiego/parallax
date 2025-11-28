/**
 * @file main_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "main_gen.h"
#include "parallax.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * main_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_cont;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_main);
        lv_style_set_bg_color(&style_main, lv_color_hex(0xffffff));

        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, 200);
        lv_style_set_height(&style_cont, 70);
        lv_style_set_pad_all(&style_cont, 5);
        lv_style_set_pad_row(&style_cont, 0);
        lv_style_set_radius(&style_cont, 0);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&style_cont, LV_FLEX_FLOW_COLUMN);
        lv_style_set_bg_color(&style_cont, lv_color_hex(0x2dcf6d));
        lv_style_set_text_color(&style_cont, lv_color_hex(0xffffff));
        lv_style_set_shadow_color(&style_cont, lv_color_hex(0x000000));
        lv_style_set_shadow_opa(&style_cont, 200);
        lv_style_set_shadow_width(&style_cont, 20);
        lv_style_set_shadow_spread(&style_cont, 1);

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
    lv_obj_set_name_static(lv_obj_0, "main_#");

    lv_obj_add_style(lv_obj_0, &style_main, 0);
    lv_obj_t * wd_parallax_0 = wd_parallax_create(lv_obj_0);
    lv_obj_set_width(wd_parallax_0, 460);
    lv_obj_set_x(wd_parallax_0, 20);
    wd_parallax_bind_title(wd_parallax_0, &subject_title);
    wd_parallax_bind_description(wd_parallax_0, &subject_description);
    lv_obj_t * wd_parallax_item_0 = wd_parallax_add_item(wd_parallax_0, sketch_logo, sketch_bg);
    wd_parallax_set_item_title(wd_parallax_0, wd_parallax_item_0, "Sketch");
    wd_parallax_set_item_description(wd_parallax_0, wd_parallax_item_0, "Web design and development, 2018-22");
    lv_obj_t * wd_parallax_item_1 = wd_parallax_add_item(wd_parallax_0, fortepan_logo, fortepan_bg);
    wd_parallax_set_item_title(wd_parallax_0, wd_parallax_item_1, "Fortepan");
    wd_parallax_set_item_description(wd_parallax_0, wd_parallax_item_1, "Web design and development, 2019-21");
    lv_obj_t * wd_parallax_item_2 = wd_parallax_add_item(wd_parallax_0, youate_logo, youate_bg);
    wd_parallax_set_item_title(wd_parallax_0, wd_parallax_item_2, "Ate Food Journal");
    wd_parallax_set_item_description(wd_parallax_0, wd_parallax_item_2, "Brand & product design, 2017");
    lv_obj_t * wd_parallax_item_3 = wd_parallax_add_item(wd_parallax_0, foodnotes_logo, foodnotes_bg);
    wd_parallax_set_item_title(wd_parallax_0, wd_parallax_item_3, "Foodnotes");
    wd_parallax_set_item_description(wd_parallax_0, wd_parallax_item_3, "Brand & product design, 2016");
    lv_obj_t * wd_parallax_item_4 = wd_parallax_add_item(wd_parallax_0, mo_logo, mo_bg);
    wd_parallax_set_item_title(wd_parallax_0, wd_parallax_item_4, "Slowmographer");
    wd_parallax_set_item_description(wd_parallax_0, wd_parallax_item_4, "Brand & product design, 2016");
    lv_obj_t * wd_parallax_item_5 = wd_parallax_add_item(wd_parallax_0, ustream_logo, ustream_bg);
    wd_parallax_set_item_title(wd_parallax_0, wd_parallax_item_5, "Ustream");
    wd_parallax_set_item_description(wd_parallax_0, wd_parallax_item_5, "Product design, 2011-16");
    
    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_x(lv_obj_1, 5);
    lv_obj_set_y(lv_obj_1, 230);
    lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_add_style(lv_obj_1, &style_cont, 0);
    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_0, &subject_title, NULL);
    lv_obj_set_style_text_font(lv_label_0, MS_Bold_20, 0);
    
    lv_obj_t * lv_label_1 = lv_label_create(lv_obj_1);
    lv_label_bind_text(lv_label_1, &subject_description, NULL);
    lv_obj_set_width(lv_label_1, lv_pct(100));
    lv_obj_set_style_text_font(lv_label_1, MS_Regular_16, 0);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_obj_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


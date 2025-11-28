/**
 * @file wd_parallax_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_parallax_gen.h"

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "src/lvgl_private.h"
#else
    #include "lvgl/src/lvgl_private.h"
#endif

#if LV_USE_XML

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void * wd_parallax_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = wd_parallax_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create wd_parallax");
        return NULL;
    }

    return item;
}

void wd_parallax_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq("bind_title", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_parallax bind_title", value);
                continue;
            }
            wd_parallax_bind_title(item, subject);
        }

        if(lv_streq("bind_description", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject == NULL) {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_parallax bind_description", value);
                continue;
            }
            wd_parallax_bind_description(item, subject);
        }
    }
}

void * wd_parallax_item_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = lv_xml_state_get_parent(state);

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create wd_parallax-item");
        return NULL;
    }
    const char * icon = lv_xml_get_value_of(attrs, "icon");
    const char * bg = lv_xml_get_value_of(attrs, "background");
    return wd_parallax_add_item(item, lv_xml_get_image(&state->scope, icon), lv_xml_get_image(&state->scope, bg));
}

void wd_parallax_item_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{
    void * parent_item = lv_xml_state_get_parent(state);
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];

        if(lv_streq(name, "title")) {
            wd_parallax_set_item_title(parent_item, item, value);
        }
        if(lv_streq(name, "description")) {
            wd_parallax_set_item_description(parent_item, item, value);
        }
    }
}

void wd_parallax_register(void)
{
    lv_xml_register_widget("wd_parallax", wd_parallax_xml_create, wd_parallax_xml_apply);
    lv_xml_register_widget("wd_parallax-item", wd_parallax_item_xml_create, wd_parallax_item_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */
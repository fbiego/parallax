/**
 * @file wd_parallax.c
 *
 */

/*********************
 *      INCLUDES
 *********************/

#include "wd_parallax_private_gen.h"
#include "parallax.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    char *title;
    char *description;
} wd_parallax_item_data_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void wd_parallax_item_event(lv_event_t * e);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_parallax_constructor_hook(lv_obj_t * obj)
{

}

void wd_parallax_destructor_hook(lv_obj_t * obj)
{

}

void wd_parallax_event_hook(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = (lv_obj_t *)lv_event_get_target(e);
    wd_parallax_t * widget = (wd_parallax_t *)obj;

    if (code == LV_EVENT_SCROLL) 
    {
        int32_t scroll_x = lv_obj_get_scroll_x(obj);
        int32_t count = lv_obj_get_child_count(obj);

        int32_t screen_w = lv_obj_get_width(obj);

        for (int32_t i = 0; i < count; i++) {
            lv_obj_t * cont = lv_obj_get_child(obj, i);
            if (!cont) continue;
            lv_obj_t * bg = lv_obj_get_child(cont, 0);
            if (!bg) continue;

            int32_t cont_w = lv_obj_get_width(cont);
            int32_t bg_w = lv_obj_get_width(bg);

            /* Extra scrollable space of background relative to container */
            int32_t extra = bg_w - cont_w;
            if (extra <= 0) continue; // nothing to parallax

            /* Calculate container center position relative to scroll */
            int32_t cont_center = lv_obj_get_x(cont) + cont_w / 2;
            int32_t widget_center = scroll_x + screen_w / 2;

            // -1.0 = left edge, 0.0 = center, +1.0 = right edge
            float ratio = (float)(cont_center - widget_center) / (float)(screen_w / 2);

            /* Clamp ratio */
            if (ratio < -1.0f) ratio = -1.0f;
            if (ratio > 1.0f) ratio = 1.0f;

            /* Apply parallax offset */
            int32_t offset = -(int32_t)(ratio * (extra / 2));

            lv_obj_set_x(bg, offset);
        }

    }
    if (code == LV_EVENT_SCROLL_END)
    {
        int32_t scroll_x = lv_obj_get_scroll_x(obj);
        lv_obj_t * first = lv_obj_get_child(obj, 0);
        if(!first) return;

        int32_t page_w = lv_obj_get_width(first);

        /* Round to nearest page index */
        int32_t index = (scroll_x + page_w / 2) / page_w;

        /* Get the snapped item */
        lv_obj_t * item = lv_obj_get_child(obj, index);
        if (!item) return;

        /* Get the data of the snapped item */
        wd_parallax_item_data_t * data = (wd_parallax_item_data_t *)lv_obj_get_user_data(item);
        if (!data) return;

        /* Write the title and description back to the attached subjects if available */
        if (widget->bind_title) {
            lv_subject_copy_string(widget->bind_title, data->title ? data->title : "");
        }
        
        if (widget->bind_description) {
            lv_subject_copy_string(widget->bind_description, data->description ? data->description : "");
        }

        
    }

}

void wd_parallax_bind_title(lv_obj_t * wd_parallax, lv_subject_t * bind_title)
{
    wd_parallax_t * widget = (wd_parallax_t *)wd_parallax;
    widget->bind_title = bind_title;
}

void wd_parallax_bind_description(lv_obj_t * wd_parallax, lv_subject_t * bind_description)
{
    wd_parallax_t * widget = (wd_parallax_t *)wd_parallax;
    widget->bind_description = bind_description;
}

lv_obj_t * wd_parallax_add_item(lv_obj_t * wd_parallax, const void * icon, const void * background)
{
    /* Create the item container */
    lv_obj_t * item = lv_obj_create(wd_parallax);
    lv_obj_remove_style_all(item);
    lv_obj_set_size(item, 320, lv_pct(100)); /* Width should be less than bg image width */
    lv_obj_remove_flag(item, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_add_event_cb(item, wd_parallax_item_event, LV_EVENT_ALL, NULL);

    wd_parallax_item_data_t * data = lv_malloc(sizeof(wd_parallax_item_data_t));
    data->title = NULL;
    data->description = NULL;

    lv_obj_set_user_data(item, data);

    /* Add the background image */
    lv_obj_t * bg_obj = lv_image_create(item);
    lv_image_set_src(bg_obj, background);
    lv_obj_set_align(bg_obj, LV_ALIGN_CENTER);

    /* Add the foreground icon */
    lv_obj_t * icon_obj = lv_image_create(item);
    lv_image_set_src(icon_obj, icon);
    lv_obj_set_align(icon_obj, LV_ALIGN_CENTER);
    return item;
}


void wd_parallax_set_item_title(lv_obj_t * wd_parallax, lv_obj_t * item, const char * title)
{
    wd_parallax_item_data_t * data = (wd_parallax_item_data_t *)lv_obj_get_user_data(item);
    if (!data) return;

    if (data->title) lv_free(data->title);

    data->title = lv_strdup(title);
}

void wd_parallax_set_item_description(lv_obj_t * wd_parallax, lv_obj_t * item, const char * description)
{
    wd_parallax_item_data_t * data = (wd_parallax_item_data_t *)lv_obj_get_user_data(item);
    if (!data) return;

    if (data->description) lv_free(data->description);

    data->description = lv_strdup(description);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void wd_parallax_item_event(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    if (code == LV_EVENT_DELETE) {
        wd_parallax_item_data_t * data = (wd_parallax_item_data_t *)lv_obj_get_user_data(obj);
        if (data) {
            if (data->title) lv_free(data->title);
            if (data->description) lv_free(data->description);
            lv_free(data);
        }
    }
}
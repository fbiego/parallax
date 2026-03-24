/**
 * @file parallax_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "parallax_gen.h"

#if LV_USE_XML
#include "widgets/wd_parallax/wd_parallax_private_gen.h"
#endif /* LV_USE_XML */

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

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Fonts
 *----------------*/

lv_font_t * MS_Bold_20;
extern lv_font_t MS_Bold_20_data;
lv_font_t * MS_Regular_16;
extern lv_font_t MS_Regular_16_data;

/*----------------
 * Images
 *----------------*/

const void * foodnotes_logo;
extern const void * foodnotes_logo_data;
const void * fortepan_logo;
extern const void * fortepan_logo_data;
const void * mo_logo;
extern const void * mo_logo_data;
const void * sketch_logo;
extern const void * sketch_logo_data;
const void * ustream_logo;
extern const void * ustream_logo_data;
const void * youate_logo;
extern const void * youate_logo_data;
const void * foodnotes_bg;
extern const void * foodnotes_bg_data;
const void * fortepan_bg;
extern const void * fortepan_bg_data;
const void * mo_bg;
extern const void * mo_bg_data;
const void * sketch_bg;
extern const void * sketch_bg_data;
const void * ustream_bg;
extern const void * ustream_bg_data;
const void * youate_bg;
extern const void * youate_bg_data;

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Subjects
 *----------------*/

lv_subject_t subject_title;
lv_subject_t subject_description;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void parallax_init_gen(const char * asset_path)
{
    char buf[256];


    /*----------------
     * Fonts
     *----------------*/

    /* get font 'MS_Bold_20' from a C array */
    MS_Bold_20 = &MS_Bold_20_data;
    /* get font 'MS_Regular_16' from a C array */
    MS_Regular_16 = &MS_Regular_16_data;


    /*----------------
     * Images
     *----------------*/
    foodnotes_logo = &foodnotes_logo_data;
    fortepan_logo = &fortepan_logo_data;
    mo_logo = &mo_logo_data;
    sketch_logo = &sketch_logo_data;
    ustream_logo = &ustream_logo_data;
    youate_logo = &youate_logo_data;
    foodnotes_bg = &foodnotes_bg_data;
    fortepan_bg = &fortepan_bg_data;
    mo_bg = &mo_bg_data;
    sketch_bg = &sketch_bg_data;
    ustream_bg = &ustream_bg_data;
    youate_bg = &youate_bg_data;

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Subjects
     *----------------*/
    static char subject_title_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_title_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_title,
                           subject_title_buf,
                           subject_title_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Sketch"
                          );
    static char subject_description_buf[UI_SUBJECT_STRING_LENGTH];
    static char subject_description_prev_buf[UI_SUBJECT_STRING_LENGTH];
    lv_subject_init_string(&subject_description,
                           subject_description_buf,
                           subject_description_prev_buf,
                           UI_SUBJECT_STRING_LENGTH,
                           "Web design and development, 2018-22"
                          );

    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */
    wd_parallax_register();

    /* Register fonts */
    lv_xml_register_font(NULL, "MS_Bold_20", MS_Bold_20);
    lv_xml_register_font(NULL, "MS_Regular_16", MS_Regular_16);

    /* Register subjects */
    lv_xml_register_subject(NULL, "subject_title", &subject_title);
    lv_xml_register_subject(NULL, "subject_description", &subject_description);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "foodnotes_logo", foodnotes_logo);
    lv_xml_register_image(NULL, "fortepan_logo", fortepan_logo);
    lv_xml_register_image(NULL, "mo_logo", mo_logo);
    lv_xml_register_image(NULL, "sketch_logo", sketch_logo);
    lv_xml_register_image(NULL, "ustream_logo", ustream_logo);
    lv_xml_register_image(NULL, "youate_logo", youate_logo);
    lv_xml_register_image(NULL, "foodnotes_bg", foodnotes_bg);
    lv_xml_register_image(NULL, "fortepan_bg", fortepan_bg);
    lv_xml_register_image(NULL, "mo_bg", mo_bg);
    lv_xml_register_image(NULL, "sketch_bg", sketch_bg);
    lv_xml_register_image(NULL, "ustream_bg", ustream_bg);
    lv_xml_register_image(NULL, "youate_bg", youate_bg);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/
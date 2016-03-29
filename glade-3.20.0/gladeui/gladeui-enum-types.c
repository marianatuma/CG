
/* Generated data (by glib-mkenums) */

#include <gladeui/glade.h>
#include <gladeui/gladeui-enum-types.h>

/* enumerations from "glade-cursor.h" */
GType
glade_cursor_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GLADE_CURSOR_SELECTOR, "GLADE_CURSOR_SELECTOR", "selector" },
            { GLADE_CURSOR_ADD_WIDGET, "GLADE_CURSOR_ADD_WIDGET", "add-widget" },
            { GLADE_CURSOR_RESIZE_TOP_LEFT, "GLADE_CURSOR_RESIZE_TOP_LEFT", "resize-top-left" },
            { GLADE_CURSOR_RESIZE_TOP_RIGHT, "GLADE_CURSOR_RESIZE_TOP_RIGHT", "resize-top-right" },
            { GLADE_CURSOR_RESIZE_BOTTOM_LEFT, "GLADE_CURSOR_RESIZE_BOTTOM_LEFT", "resize-bottom-left" },
            { GLADE_CURSOR_RESIZE_BOTTOM_RIGHT, "GLADE_CURSOR_RESIZE_BOTTOM_RIGHT", "resize-bottom-right" },
            { GLADE_CURSOR_RESIZE_LEFT, "GLADE_CURSOR_RESIZE_LEFT", "resize-left" },
            { GLADE_CURSOR_RESIZE_RIGHT, "GLADE_CURSOR_RESIZE_RIGHT", "resize-right" },
            { GLADE_CURSOR_RESIZE_TOP, "GLADE_CURSOR_RESIZE_TOP", "resize-top" },
            { GLADE_CURSOR_RESIZE_BOTTOM, "GLADE_CURSOR_RESIZE_BOTTOM", "resize-bottom" },
            { GLADE_CURSOR_DRAG, "GLADE_CURSOR_DRAG", "drag" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GladeCursorType"), values);
    }
    return etype;
}

/* enumerations from "glade-debug.h" */
GType
glade_debug_flag_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GLADE_DEBUG_REF_COUNTS, "GLADE_DEBUG_REF_COUNTS", "ref-counts" },
            { GLADE_DEBUG_WIDGET_EVENTS, "GLADE_DEBUG_WIDGET_EVENTS", "widget-events" },
            { GLADE_DEBUG_COMMANDS, "GLADE_DEBUG_COMMANDS", "commands" },
            { GLADE_DEBUG_PROPERTIES, "GLADE_DEBUG_PROPERTIES", "properties" },
            { GLADE_DEBUG_VERIFY, "GLADE_DEBUG_VERIFY", "verify" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GladeDebugFlag"), values);
    }
    return etype;
}

/* enumerations from "glade-editable.h" */
GType
glade_editor_page_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GLADE_PAGE_GENERAL, "GLADE_PAGE_GENERAL", "general" },
            { GLADE_PAGE_COMMON, "GLADE_PAGE_COMMON", "common" },
            { GLADE_PAGE_PACKING, "GLADE_PAGE_PACKING", "packing" },
            { GLADE_PAGE_ATK, "GLADE_PAGE_ATK", "atk" },
            { GLADE_PAGE_QUERY, "GLADE_PAGE_QUERY", "query" },
            { GLADE_PAGE_SIGNAL, "GLADE_PAGE_SIGNAL", "signal" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GladeEditorPageType"), values);
    }
    return etype;
}

/* enumerations from "glade-palette.h" */
GType
glade_item_appearance_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GLADE_ITEM_ICON_AND_LABEL, "GLADE_ITEM_ICON_AND_LABEL", "icon-and-label" },
            { GLADE_ITEM_ICON_ONLY, "GLADE_ITEM_ICON_ONLY", "icon-only" },
            { GLADE_ITEM_LABEL_ONLY, "GLADE_ITEM_LABEL_ONLY", "label-only" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GladeItemAppearance"), values);
    }
    return etype;
}

/* enumerations from "glade-project.h" */
GType
glade_pointer_mode_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GLADE_POINTER_SELECT, "GLADE_POINTER_SELECT", "select" },
            { GLADE_POINTER_ADD_WIDGET, "GLADE_POINTER_ADD_WIDGET", "add-widget" },
            { GLADE_POINTER_DRAG_RESIZE, "GLADE_POINTER_DRAG_RESIZE", "drag-resize" },
            { GLADE_POINTER_MARGIN_EDIT, "GLADE_POINTER_MARGIN_EDIT", "margin-edit" },
            { GLADE_POINTER_ALIGN_EDIT, "GLADE_POINTER_ALIGN_EDIT", "align-edit" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GladePointerMode"), values);
    }
    return etype;
}

GType
glade_support_mask_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GLADE_SUPPORT_OK, "GLADE_SUPPORT_OK", "ok" },
            { GLADE_SUPPORT_DEPRECATED, "GLADE_SUPPORT_DEPRECATED", "deprecated" },
            { GLADE_SUPPORT_MISMATCH, "GLADE_SUPPORT_MISMATCH", "mismatch" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GladeSupportMask"), values);
    }
    return etype;
}

GType
glade_project_model_columns_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GLADE_PROJECT_MODEL_COLUMN_ICON_NAME, "GLADE_PROJECT_MODEL_COLUMN_ICON_NAME", "column-icon-name" },
            { GLADE_PROJECT_MODEL_COLUMN_NAME, "GLADE_PROJECT_MODEL_COLUMN_NAME", "column-name" },
            { GLADE_PROJECT_MODEL_COLUMN_TYPE_NAME, "GLADE_PROJECT_MODEL_COLUMN_TYPE_NAME", "column-type-name" },
            { GLADE_PROJECT_MODEL_COLUMN_OBJECT, "GLADE_PROJECT_MODEL_COLUMN_OBJECT", "column-object" },
            { GLADE_PROJECT_MODEL_COLUMN_MISC, "GLADE_PROJECT_MODEL_COLUMN_MISC", "column-misc" },
            { GLADE_PROJECT_MODEL_COLUMN_WARNING, "GLADE_PROJECT_MODEL_COLUMN_WARNING", "column-warning" },
            { GLADE_PROJECT_MODEL_N_COLUMNS, "GLADE_PROJECT_MODEL_N_COLUMNS", "n-columns" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GladeProjectModelColumns"), values);
    }
    return etype;
}

GType
glade_verify_flags_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GLADE_VERIFY_VERSIONS, "GLADE_VERIFY_VERSIONS", "versions" },
            { GLADE_VERIFY_DEPRECATIONS, "GLADE_VERIFY_DEPRECATIONS", "deprecations" },
            { GLADE_VERIFY_UNRECOGNIZED, "GLADE_VERIFY_UNRECOGNIZED", "unrecognized" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GladeVerifyFlags"), values);
    }
    return etype;
}

/* enumerations from "glade-property.h" */
GType
glade_property_state_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GFlagsValue values[] = {
            { GLADE_STATE_NORMAL, "GLADE_STATE_NORMAL", "normal" },
            { GLADE_STATE_CHANGED, "GLADE_STATE_CHANGED", "changed" },
            { GLADE_STATE_UNSUPPORTED, "GLADE_STATE_UNSUPPORTED", "unsupported" },
            { GLADE_STATE_SUPPORT_DISABLED, "GLADE_STATE_SUPPORT_DISABLED", "support-disabled" },
            { 0, NULL, NULL }
        };
        etype = g_flags_register_static (g_intern_static_string ("GladePropertyState"), values);
    }
    return etype;
}

/* enumerations from "glade-signal-model.h" */
GType
glade_signal_model_columns_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GLADE_SIGNAL_COLUMN_NAME, "GLADE_SIGNAL_COLUMN_NAME", "column-name" },
            { GLADE_SIGNAL_COLUMN_SHOW_NAME, "GLADE_SIGNAL_COLUMN_SHOW_NAME", "column-show-name" },
            { GLADE_SIGNAL_COLUMN_HANDLER, "GLADE_SIGNAL_COLUMN_HANDLER", "column-handler" },
            { GLADE_SIGNAL_COLUMN_OBJECT, "GLADE_SIGNAL_COLUMN_OBJECT", "column-object" },
            { GLADE_SIGNAL_COLUMN_SWAP, "GLADE_SIGNAL_COLUMN_SWAP", "column-swap" },
            { GLADE_SIGNAL_COLUMN_AFTER, "GLADE_SIGNAL_COLUMN_AFTER", "column-after" },
            { GLADE_SIGNAL_COLUMN_TOOLTIP, "GLADE_SIGNAL_COLUMN_TOOLTIP", "column-tooltip" },
            { GLADE_SIGNAL_COLUMN_SIGNAL, "GLADE_SIGNAL_COLUMN_SIGNAL", "column-signal" },
            { GLADE_SIGNAL_COLUMN_DETAIL, "GLADE_SIGNAL_COLUMN_DETAIL", "column-detail" },
            { GLADE_SIGNAL_N_COLUMNS, "GLADE_SIGNAL_N_COLUMNS", "n-columns" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GladeSignalModelColumns"), values);
    }
    return etype;
}

/* enumerations from "glade-utils.h" */
GType
glade_util_file_dialog_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GLADE_FILE_DIALOG_ACTION_OPEN, "GLADE_FILE_DIALOG_ACTION_OPEN", "open" },
            { GLADE_FILE_DIALOG_ACTION_SAVE, "GLADE_FILE_DIALOG_ACTION_SAVE", "save" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GladeUtilFileDialogType"), values);
    }
    return etype;
}

GType
glade_ui_message_type_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GLADE_UI_INFO, "GLADE_UI_INFO", "info" },
            { GLADE_UI_WARN, "GLADE_UI_WARN", "warn" },
            { GLADE_UI_ERROR, "GLADE_UI_ERROR", "error" },
            { GLADE_UI_ARE_YOU_SURE, "GLADE_UI_ARE_YOU_SURE", "are-you-sure" },
            { GLADE_UI_YES_OR_NO, "GLADE_UI_YES_OR_NO", "yes-or-no" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GladeUIMessageType"), values);
    }
    return etype;
}

/* enumerations from "glade-widget-adaptor.h" */
GType
glade_create_reason_get_type (void)
{
    static GType etype = 0;
    if (G_UNLIKELY(etype == 0)) {
        static const GEnumValue values[] = {
            { GLADE_CREATE_USER, "GLADE_CREATE_USER", "user" },
            { GLADE_CREATE_COPY, "GLADE_CREATE_COPY", "copy" },
            { GLADE_CREATE_LOAD, "GLADE_CREATE_LOAD", "load" },
            { GLADE_CREATE_REBUILD, "GLADE_CREATE_REBUILD", "rebuild" },
            { GLADE_CREATE_REASONS, "GLADE_CREATE_REASONS", "reasons" },
            { 0, NULL, NULL }
        };
        etype = g_enum_register_static (g_intern_static_string ("GladeCreateReason"), values);
    }
    return etype;
}



/* Generated data ends here */


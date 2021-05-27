#pragma once

// All the logic forSSD1306 OLED update loop lives in this file.
// Make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // Vertical orientation for both screens.
    return OLED_ROTATION_270;
}

void render_space(void) { oled_write_P(PSTR("     "), false); }

void render_mod_status_gui_alt(uint8_t modifiers) {
    static const char PROGMEM gui_off_1[] = {0x80, 0x81, 0};
    static const char PROGMEM gui_off_2[] = {0xa0, 0xa1, 0};
    static const char PROGMEM gui_on_1[]  = {0x88, 0x89, 0};
    static const char PROGMEM gui_on_2[]  = {0xa8, 0xa9, 0};

    static const char PROGMEM alt_off_1[] = {0x82, 0x83, 0};
    static const char PROGMEM alt_off_2[] = {0xa2, 0xa3, 0};
    static const char PROGMEM alt_on_1[]  = {0x8a, 0x8b, 0};
    static const char PROGMEM alt_on_2[]  = {0xaa, 0xab, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc0, 0};
    static const char PROGMEM off_off_2[] = {0xc1, 0};
    static const char PROGMEM on_off_1[]  = {0xc2, 0};
    static const char PROGMEM on_off_2[]  = {0xc3, 0};
    static const char PROGMEM off_on_1[]  = {0xc4, 0};
    static const char PROGMEM off_on_2[]  = {0xc5, 0};
    static const char PROGMEM on_on_1[]   = {0xc6, 0};
    static const char PROGMEM on_on_2[]   = {0xc7, 0};

    if (modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_1, false);
    } else {
        oled_write_P(gui_off_1, false);
    }

    if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
        oled_write_P(on_on_1, false);
    } else if (modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_1, false);
    } else if (modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if (modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_1, false);
    } else {
        oled_write_P(alt_off_1, false);
    }

    if (modifiers & MOD_MASK_GUI) {
        oled_write_P(gui_on_2, false);
    } else {
        oled_write_P(gui_off_2, false);
    }

    if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
        oled_write_P(on_on_2, false);
    } else if (modifiers & MOD_MASK_GUI) {
        oled_write_P(on_off_2, false);
    } else if (modifiers & MOD_MASK_ALT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if (modifiers & MOD_MASK_ALT) {
        oled_write_P(alt_on_2, false);
    } else {
        oled_write_P(alt_off_2, false);
    }
}

void render_mod_status_ctrl_shift(uint8_t modifiers) {
    static const char PROGMEM ctrl_off_1[] = {0x84, 0x85, 0};
    static const char PROGMEM ctrl_off_2[] = {0xa4, 0xa5, 0};
    static const char PROGMEM ctrl_on_1[]  = {0x8c, 0x8d, 0};
    static const char PROGMEM ctrl_on_2[]  = {0xac, 0xad, 0};

    static const char PROGMEM shift_off_1[] = {0x86, 0x87, 0};
    static const char PROGMEM shift_off_2[] = {0xa6, 0xa7, 0};
    static const char PROGMEM shift_on_1[]  = {0xc8, 0xc9, 0};
    static const char PROGMEM shift_on_2[]  = {0xca, 0xcb, 0};

    // fillers between the modifier icons bleed into the icon frames
    static const char PROGMEM off_off_1[] = {0xc0, 0};
    static const char PROGMEM off_off_2[] = {0xc1, 0};
    static const char PROGMEM on_off_1[]  = {0xc2, 0};
    static const char PROGMEM on_off_2[]  = {0xc3, 0};
    static const char PROGMEM off_on_1[]  = {0xc4, 0};
    static const char PROGMEM off_on_2[]  = {0xc5, 0};
    static const char PROGMEM on_on_1[]   = {0xc6, 0};
    static const char PROGMEM on_on_2[]   = {0xc7, 0};

    if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_1, false);
    } else {
        oled_write_P(ctrl_off_1, false);
    }

    if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
        oled_write_P(on_on_1, false);
    } else if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_1, false);
    } else if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_1, false);
    } else {
        oled_write_P(off_off_1, false);
    }

    if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_1, false);
    } else {
        oled_write_P(shift_off_1, false);
    }

    if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(ctrl_on_2, false);
    } else {
        oled_write_P(ctrl_off_2, false);
    }

    if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
        oled_write_P(on_on_2, false);
    } else if (modifiers & MOD_MASK_CTRL) {
        oled_write_P(on_off_2, false);
    } else if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(off_on_2, false);
    } else {
        oled_write_P(off_off_2, false);
    }

    if (modifiers & MOD_MASK_SHIFT) {
        oled_write_P(shift_on_2, false);
    } else {
        oled_write_P(shift_off_2, false);
    }
}

void render_paw(void) {
    static const char PROGMEM paw[] = {0x8e, 0x8f, 0x90, 0x91, 0x92, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0};
    oled_write_P(paw, false);
}

void render_qr(void) {
    // clang-format off
    static const char PROGMEM qr[] = {
        0x93, 0x94, 0x95, 0x96, 0x97,
        0xb3, 0xb4, 0xb5, 0xb6, 0xb7,
        0xd3, 0xd4, 0xd5, 0xd6, 0xd7,
        0x98, 0x99, 0x9a, 0x9b, 0x9c, 0,
    };
    // clang-format on
    oled_write_P(qr, false);
    oled_write_P(PSTR("don't"), false);
}

void render_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    if (layer_state_is(_LOWER)) {
        oled_write_P(PSTR("LOWER"), false);
    } else if (layer_state_is(_RAISE)) {
        oled_write_P(PSTR("RAISE"), false);
    } else {
        oled_write_P(PSTR("MAIN "), false);
    }
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_paw();
        render_space();
        render_space();
        render_layer_state();
        render_space();
        render_space();
        render_mod_status_gui_alt(get_mods() | get_oneshot_mods());
        render_mod_status_ctrl_shift(get_mods() | get_oneshot_mods());
    } else {
        render_paw();
        render_space();
        render_space();
        render_qr();
    }
}

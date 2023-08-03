#include QMK_KEYBOARD_H
#include "layers.h"

extern keymap_config_t keymap_config;

#ifdef PROTOCOL_LUFA
#    include "lufa.h"
#    include "split_util.h"
#endif

#include "oled.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK (actually colemak-dh)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BcSp |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  `   |
 * |------+------+------+------+------+------|   ,   |    |    .  |------+------+------+------+------+------|
 * |   [  |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   '  |   \  |   /  |  ]   |
 * `-----------------------------------------/ LShift/     \ NAVI \-----------------------------------------'
 *                   | LCtl | LAlt |  Meh | /[Space]/       \[Entr]\  | MOUS | RAlt | LGUI |
 *                   |      |      |      |/       /         \      \ |      |[Caps]|      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_COLEMAK] = LAYOUT( \
   KC_ESC, KC_1, KC_2,    KC_3,    KC_4,          KC_5,                                    KC_6,      KC_7,            KC_8,    KC_9,    KC_0,    KC_EQL,  \
   KC_TAB, KC_Q, KC_W,    KC_F,    KC_P,          KC_B,                                    KC_J,      KC_L,            KC_U,    KC_Y,    KC_SCLN, KC_MINS, \
  KC_BSPC, KC_A, KC_R,    KC_S,    KC_T,          KC_G,                                    KC_M,      KC_N,            KC_E,    KC_I,    KC_O,    KC_GRV,  \
  KC_LBRC, KC_Z, KC_X,    KC_C,    KC_D,          KC_V,        KC_COMM,  KC_DOT,           KC_K,      KC_H,            KC_QUOT, KC_BSLS, KC_SLSH, KC_RBRC, \
                       KC_LCTL, KC_LALT, LCTL(KC_LSFT), LSFT_T(KC_SPC),  LT(_NAVI,KC_ENT), MO(_MOUSE), RALT_T(KC_CAPS), KC_LGUI \
),

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BcSp |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  `   |
 * |------+------+------+------+------+------|   ,   |    |    .  |------+------+------+------+------+------|
 * |   [  |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   '  |   \  |   /  |  ]   |
 * `-----------------------------------------/ LShift/     \ NAVI \-----------------------------------------'
 *                   | LCtl | LAlt |  Meh | /[Space]/       \[Entr]\  | MOUS | RAlt | LGUI |
 *                   |      |      |      |/       /         \      \ |      |[Caps]|      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
   KC_ESC, KC_1, KC_2,    KC_3,    KC_4,          KC_5,                                    KC_6,       KC_7,            KC_8,    KC_9,    KC_0,    KC_EQL,  \
   KC_TAB, KC_Q, KC_W,    KC_E,    KC_R,          KC_T,                                    KC_Y,       KC_U,            KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_BSPC, KC_A, KC_S,    KC_D,    KC_F,          KC_G,                                    KC_H,       KC_J,            KC_K,    KC_L,    KC_SCLN, KC_GRV,  \
  KC_LBRC, KC_Z, KC_X,    KC_C,    KC_V,          KC_B,        KC_COMM,  KC_DOT,           KC_N,       KC_M,            KC_QUOT, KC_BSLS, KC_SLSH, KC_RBRC, \
                       KC_LCTL, KC_LALT, LCTL(KC_LSFT), LSFT_T(KC_SPC),  LT(_NAVI,KC_ENT), MO(_MOUSE), RALT_T(KC_CAPS), KC_LGUI \
),

/* Gaming layout
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   `  |   1  |   2  |   3  |   4  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   6  |   7  |   Q  |   W  |   E  |   R  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | BcSp | Shift|   A  |   S  |   D  |   F  |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|   G   |    |    .  |------+------+------+------+------+------|
 * |   5  | Ctrl |   Z  |   X  |   C  |   V  |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \ UTIL \-----------------------------------------'
 *                   |  Tab | LAlt |  Meh | / Space /       \[Entr]\  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_GAME] = LAYOUT( \
   KC_ESC,  KC_GRV, KC_1,   KC_2,    KC_3,          KC_4,                            _______, _______, _______, _______, _______, _______, \
     KC_6,    KC_7, KC_Q,   KC_W,    KC_E,          KC_R,                            _______, _______, _______, _______, _______, _______, \
  KC_BSPC, KC_LSFT, KC_A,   KC_S,    KC_D,          KC_F,                            _______, _______, _______, _______, _______, _______, \
     KC_5, KC_LCTL, KC_Z,   KC_X,    KC_C,          KC_V,   KC_G,  _______,          _______, _______, _______, _______, _______, _______, \
                          KC_TAB, KC_LALT, LCTL(KC_LSFT), KC_SPC,  LT(_NAVI,KC_ENT), _______, _______, _______ \
),

/* NAVI
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | MAIN |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | PrScr|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | PgUp |      | F11  |                    |  F12 |      |  Up  |      | |<<  | Break|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  |      | Home | PgDn | End  |      |-------.    ,-------|      | Left | Down | Rght |  ||  |WinBrk|
 * |------+------+------+------+------+------|Ctr+Sh |    | LOCK  |------+------+------+------+------+------|
 * | Ins  |      |      |LC+Ins|      |LS+Ins|-------|    |-------|      |      |      |      |  >>| |      |
 * `-----------------------------------------/ LShift/     \      \-----------------------------------------'
 *                   | LCtl | LAlt |  Meh | /[Space]/       \      \  | C-DH | QWER | GAME |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_NAVI] = LAYOUT( \
  DF(_COLEMAK),   KC_F1,   KC_F2,   KC_F3,        KC_F4,        KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_PSCR,       \
       _______, _______, _______, KC_PGUP,      _______,       KC_F11,                       KC_F11,  _______, KC_UP,   _______, KC_MPRV, KC_PAUS,       \
        KC_DEL, _______, KC_HOME, KC_PGDN,       KC_END,      _______,                       _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_MPLY, RGUI(KC_PAUS), \
        KC_INS, _______, _______, LCTL(KC_INS), _______, LSFT(KC_INS), _______,  DF(_NAVI),  _______, _______, _______, _______, KC_MNXT, _______,       \
                                       KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,    _______,  COLEMAK, QWERTY,  GAME \
),

/* MOUSE
 *                __ wheel control __                                     __ cursor control __
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | MAIN | MAc0 | MAc1 | MAc2 |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | MWUp |      |      |                    |      |  M1  | MUp  |  M2  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | MWLt | MWDn | MWRt |      |-------.    ,-------|      | MLft | MDn  | MRgt |  M1  |      |
 * |------+------+------+------+------+------|       |    | LOCK  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |  M4  |  M3  |  M5  |      |      |
 * `-----------------------------------------/ Lshift/     \      \-----------------------------------------'
 *                   | LCtl | LAlt |  Meh | /[Space]/       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_MOUSE] = LAYOUT( \
  DF(_COLEMAK), KC_ACL0, KC_ACL1, KC_ACL2, _______, _______,                       _______, _______, _______, _______, _______, _______, \
       _______, _______, _______, KC_WH_U, _______, _______,                       _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, \
       _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______,                       _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, _______, \
       _______, _______, _______, _______, _______, _______, _______,  DF(_MOUSE), _______, KC_BTN4, KC_BTN3, KC_BTN5, _______, _______, \
                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  _______,    _______, _______, _______ \
),

/* ADJUST (never used actually, saved from original config)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _NAVI, _MOUSE, _ADJUST); }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                layer_clear();
                layer_on(_COLEMAK);
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                layer_clear();
                layer_on(_QWERTY);
            }
            return false;
        case GAME:
            if (record->event.pressed) {
                layer_clear();
                layer_on(_GAME);
            }
            return false;
    }
    return true;
}

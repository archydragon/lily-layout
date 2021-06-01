#pragma once

#include QMK_KEYBOARD_H

enum lily_layers {
    _COLEMAK = 0,
    _QWERTY,
    _GAME,
    _UTIL,
    _PAGE,
    _ADJUST,
};

enum lily_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    GAME,
};

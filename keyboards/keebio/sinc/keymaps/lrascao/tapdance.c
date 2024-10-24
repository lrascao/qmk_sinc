//https://docs.qmk.fm/feature_layouts#tips-for-making-layouts-keyboard-agnostic
#include QMK_KEYBOARD_H

#include <version.h>
#include "keymap.h"
#include "tapdance.h"

// Tap Dance definitions
// https://docs.qmk.fm/#/feature_tap_dance
tap_dance_action_t tap_dance_actions[] = {
    [TD_PAREN_LCBRACE] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_LEFT_CURLY_BRACE),
    [TD_PAREN_RCBRACE] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_RIGHT_CURLY_BRACE),
};

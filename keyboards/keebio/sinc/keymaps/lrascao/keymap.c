#include QMK_KEYBOARD_H
#include <version.h>
#include "keymap.h"
#include "tapdance.h"
#include "oled.h"

// https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    KC_MUTE,            KC_ESC,    _______________FUNC_LEFT_______________,                          _______________FUNC_RIGHT______________,                                        KC_MPLY,  KC_MUTE,
    KC_1,  KC_2,        KC_ESC,    ______________NUMBER_LEFT______________,                          ______________NUMBER_RIGHT_____________,  KC_SLASH, KC_EQUAL,  _______, KC_BSPC,          KC_PGUP,
    KC_3,  KC_4,        KC_TAB,    _______________QWERTY_L1_______________,                          _______________QWERTY_R1_______________,  KC_LBRC, KC_RBRC,    KC_BSLS,                   KC_PGDN,
    KC_5,  KC_6,        KC_LCTL,   _______________QWERTY_L2_______________,                          _______________QWERTY_R2_______________,  KC_SCLN, KC_GRV, _______, KC_ENT,               KC_HOME,
    KC_7,  KC_8,        SC_LSPO,   KC_GRV, _______________QWERTY_L3_______________,                  _______________QWERTY_R3_______________,  KC_COMM, KC_DOT,  KC_MINUS, SC_RSPC, _______,   KC_END,
    KC_9,  KC_0,        KC_LCTL,   KC_LOWR, KC_LALT, KC_LGUI, _______, KC_SPC,                       _______,           KC_SPC,  KC_RGUI,  _______, KC_RCTL, KC_LEFT, KC_DOWN,                 KC_RASE
  ),

  [_LOWER] = LAYOUT_wrapper(
    RGB_TOG,             QK_REBOOT, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______,  KC_PSCR, KC_MUTE,
    RGB_HUI, RGB_HUD,    _______,   ______________NUMBER_LEFT______________,                    _______, _______, _______, _______,  _______, _______,  _______, _______,                 KC_VOLU,
    RGB_SAI, RGB_SAD,    _______,   _______, _______, _______, _______, KC_LPRN,                KC_RPRN, _______, _______, _______, _______,  _______, _______, _______,                  KC_VOLD,
    RGB_VAI, RGB_VAD,    _______,   _______, _______, _______, _______, KC_LCBR,                KC_RCBR, _______, _______, _______,  _______, _______, _______, _______,                  KC_MPRV,
    RGB_MOD, RGB_RMOD,   _______,   _______, _______, _______, _______, _______, KC_LBRC,       KC_RBRC, _______, _______, QK_LEAD,  _______, _______, _______,                           KC_MNXT,
    _______, _______,    _______,   _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______, _______,                            _______
  ),

  [_RAISE] = LAYOUT_wrapper(
    _______,           QK_BOOT,   _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______,
    RGB_TOG, _______,  _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______, _______, _______,                   _______,
    KC_VRSN, _______,  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______,  _______, _______, _______,                  _______,
    _______, _______,  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______,  _______, _______, _______, _______,                  _______,
    _______, _______,  _______, _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______,  _______, _______, _______,                           _______,
    _______, _______,  _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______, _______,                            _______
  )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
#ifdef CONSOLE_ENABLE
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
#endif

  /* rgblight_disable(); */
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 

    switch (keycode) {
        case KC_VRSN:  // Prints firmware version
            if (record->event.pressed) {
#ifdef OLED_ENABLE
                oled_write_P(PSTR(QMK_VERSION), false);
#endif
            }
            break;
    }

  return true;
}

// leader callbacks
// https://docs.qmk.fm/features/leader_key
void leader_start_user(void) {
    oled_leader(true);
}

void leader_end_user(void) {
    oled_leader(false);
}


// Look, this is the worst fucking hack that ever was, thank this guy for it:
// https://github.com/qmk/qmk_firmware/issues/24457#issuecomment-2392385966
#ifdef ENCODER_MAP_ENABLE
#   include "encoder.c"
#endif
#ifdef COMBO_ENABLE
#   include "combo.c"
#endif
#ifdef TAP_DANCE_ENABLE
#   include "tapdance.c"
#endif

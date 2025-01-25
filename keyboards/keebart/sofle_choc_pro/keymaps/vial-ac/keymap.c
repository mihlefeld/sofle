// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include "keycodes.h"
#include "transaction_id_define.h"
#include "via.h"
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keymap_russian.h"
#include "quantum_keycodes.h"
#include "process_tap_dance.h"
#include "action_layer.h"
#include "rgb_matrix.h"
#include "features/achordion.h"

#define _NOT 0
#define _QWE _NOT + 1
#define _RUS _QWE + 1
#define _GAR _RUS + 1
#define _GAL _GAR + 1
#define _SPE _GAL + 1
#define _NAV _SPE + 1
#define _MOS _NAV + 1
#define _FUN _MOS + 1
#define _SWT 15

#define SW_ESC LT(_SWT,KC_ESC)
#define SW_GRV LT(_SWT,KC_GRV)
#define HS(x) LSFT_T(x)
#define HC(x) LCTL_T(x)
#define HA(x) LALT_T(x)
#define HG(x) LGUI_T(x)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | CAPS  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LALT | LCMD | LGUI | /Enter  /       \Space \  | RGUI | DEL  | RALT | RCTL |
 *            |      |      |      |  LT1 |/       /         \      \ | LT2  |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NOT] = LAYOUT_split_4x6_5(
 SW_ESC,  _______,  _______,  _______,  _______,  _______,                    _______, _______,  _______,  _______,  _______,   SW_GRV,
 KC_CAPS,     DE_Z,     DE_Y,     KC_U,     KC_A,    KC_Q,                       KC_P,     KC_B,     KC_M,     KC_L,     KC_F,     KC_J,
MO(_SPE), HS(KC_C), HC(KC_S), HA(KC_I), HG(KC_E),    KC_O,                       KC_D, HG(KC_T), HA(KC_N), HC(KC_R), HS(KC_H), MO(_SPE),
 _______,     KC_V,     KC_X,  DE_UDIA,  DE_ADIA, DE_ODIA, KC_MUTE, KC_MPLY,     KC_W,     KC_G,  DE_COMM,   DE_DOT,     KC_K,    DE_SS,
           KC_MPRV,  RGB_SAD, MO(_FUN), MO(_NAV),  KC_SPC,                   MO(_NAV), MO(_MOS), MO(_FUN),  RGB_SAI,  KC_MNXT
),
[_QWE] = LAYOUT_split_4x6_5(
 _______,  _______,  _______,  _______,  _______, _______,                   _______,  _______,  _______,  _______,     _______,  _______,
  KC_TAB,     KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,                      KC_Y,     KC_U,     KC_I,     KC_O,        KC_P,  KC_BSPC,
MO(_SPE), HS(KC_A), HC(KC_S), HA(KC_D), HG(KC_F),    KC_G,                      KC_H, HG(KC_J), HA(KC_K), HC(KC_L), HS(DE_ODIA), MO(_SPE),
 KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,    KC_B, _______, _______,    KC_N,     KC_M,  DE_COMM,   DE_DOT,     DE_MINS,  KC_RSFT,
           _______,  _______,  _______,  _______, _______,                   _______,  _______,  _______,  _______,     _______
),
[_RUS] = LAYOUT_split_4x6_5(
 _______,   _______,     _______,   _______,  _______, _______,                   _______,  _______,   _______,   _______,    _______,      _______,
   RU_YO,   RU_SHTI,      RU_TSE,      RU_U,    RU_KA,   RU_IE,                     RU_EN,   RU_GHE,    RU_SHA,   RU_SHCH,      RU_ZE,        RU_HA,
MO(_SPE), HS(RU_EF), HC(RU_YERU), HA(RU_VE), HG(RU_A),   RU_PE,                     RU_ER, HG(RU_O), HA(RU_EL), HC(RU_DE), HS(RU_ZHE),LT(_SPE,RU_E),
 _______,     RU_YA,      RU_CHE,     RU_ES,    RU_EM,    RU_I, _______, _______,   RU_TE,  RU_SOFT,     RU_BE,     RU_YU,     RU_DOT,      RU_HARD,
            _______,     _______,   _______,  _______, _______,                   _______,  _______,   _______,   _______,    _______
),
[_GAR] = LAYOUT_split_4x6_5(
_______,  KC_ESC,    KC_1,   KC_2,         KC_3,    KC_4,                   _______,     _______,     _______,    _______,    _______,    _______,
   KC_T,  KC_TAB,    KC_Q,   KC_W,         KC_E,    KC_R,                      KC_Y,        KC_U,        KC_I,       KC_O,       KC_P,    KC_BSPC,
   KC_G, KC_LSFT,    KC_A,   KC_S,         KC_D,    KC_F,                      KC_H,        KC_J,        KC_K,       KC_L,    DE_ODIA,     KC_ENT,
   KC_B, KC_LCTL,    KC_Z,   KC_X,         KC_C,    KC_V, _______, _______,    KC_N,        KC_M,     KC_COMM,     KC_DOT,   KC_SLASH,    KC_RSFT,
         _______, KC_LALT, KC_ENT,LT(_FUN,KC_G),  KC_SPC,                   _______,     _______,     _______,    _______,    _______
),
[_GAL] = LAYOUT_split_4x6_5(
_______,  _______, _______, _______, _______, _______,                     KC_4,         KC_3,    KC_2,    KC_1, KC_ESCAPE, _______,
KC_BSPC,     KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                     KC_R,         KC_E,    KC_W,    KC_Q,    KC_TAB,    KC_T,
 KC_ENT,  DE_ODIA,    KC_L,    KC_K,    KC_J,    KC_H,                     KC_F,         KC_A,    KC_S,    KC_D,   KC_LSFT,    KC_G,
KC_RSFT, KC_SLASH,  KC_DOT, KC_COMM,    KC_M,    KC_N, _______, _______,   KC_V,         KC_C,    KC_X,    KC_Z,  KC_SLASH, KC_RSFT,
          _______, _______, _______, _______, _______,                   KC_SPC,LT(_FUN,KC_G), _______, KC_LALT,   _______
),
[_SPE] = LAYOUT_split_4x6_5(
    _______,   _______,   _______,    _______,    _______,    _______,                       _______,     _______,     _______,    _______,    _______,    _______,
    DE_TILD,   DE_EURO,   DE_UNDS,    DE_LBRC,    DE_RBRC,     DE_DEG,                       DE_EXLM,     DE_LABK,     DE_RABK,     DE_EQL,    DE_AMPR,      DE_AT,
    _______,   DE_BSLS,   DE_SLSH,    DE_LCBR,    DE_RCBR,    DE_ASTR,                       DE_QUES,     DE_LPRN,     DE_RPRN,    DE_MINS,    DE_COLN,    _______,
    _______,   DE_HASH,    DE_DLR,    DE_PIPE,    DE_TILD,     DE_GRV,    _______,   _______,DE_PLUS,     DE_PERC,     DE_DQUO,    DE_QUOT,    DE_SCLN,    _______,
                 _______, _______, _______, _______, _______,                                       _______, _______,  _______,  _______, _______
),
[_NAV] = LAYOUT_split_4x6_5(
    _______,   _______,   _______,    _______,     _______,    _______,                       _______,     _______,     _______,    _______,    _______,    _______,
    _______,   KC_PGUP,   KC_BSPC,      KC_UP,      KC_DEL,    KC_PGDN,                   KC_KP_SLASH,     KC_KP_7,     KC_KP_8,    KC_KP_9,KC_KP_ASTERISK,KC_BSPC,
    _______,   KC_HOME,   KC_LEFT,    KC_DOWN,    KC_RIGHT,     KC_END,                   KC_KP_MINUS,     KC_KP_4,     KC_KP_5,    KC_KP_6,     DE_DOT,  KC_ENTER,
    _______,    KC_ESC,    KC_TAB,     KC_INS,      KC_ENT,   _______,    _______,  _______, _______,     KC_KP_1,     KC_KP_2,    KC_KP_3,    DE_COMM, KC_NUM_LOCK,
                 _______, _______, _______, _______, KC_LCTL,                                KC_KP_0,    KC_SPACE,     _______,    _______, _______
),
[_MOS] = LAYOUT_split_4x6_5(
    _______,   _______,   _______,    _______,    _______,    _______,                       _______,     _______,     _______,    _______,    _______,    _______,
    _______,   _______,   MS_WHLU,      MS_UP,    MS_WHLD,    _______,                       _______,     _______,     _______,    _______,    _______,    _______,
    _______,   MS_WHLL,   MS_LEFT,    MS_DOWN,    MS_RGHT,    MS_WHLR,                       _______,     MS_BTN1,     MS_BTN3,    MS_BTN3,    _______, _______,
    _______,  _______,   _______,    _______,    _______,    _______,    _______,   _______,_______,     _______,     _______, _______,  _______, _______,
                 _______, _______, _______, _______, _______,    _______, _______,  _______,  _______, _______
),
[_FUN] = LAYOUT_split_4x6_5(
    _______,   _______,   _______,    _______,    _______,    _______,                       _______,     _______,     _______,    _______,    _______,    _______,
    _______,     KC_F1,     KC_F2,      KC_F3,      KC_F4,    _______,                       _______,       KC_F4,       KC_F3,      KC_F2,      KC_F1,      _______,
    _______,     KC_F5,     KC_F6,      KC_F7,      KC_F8,    _______,                       _______,       KC_F8,       KC_F7,      KC_F6,      KC_F5,      _______,
    _______,     KC_F9,    KC_F10,     KC_F11,     KC_F12,    _______,    _______,   _______,_______,      KC_F12,      KC_F11,     KC_F10,      KC_F9,      _______,
                 _______, _______, _______, _______, _______,    _______, _______,  _______,  _______, _______
),
[_SWT] = LAYOUT_split_4x6_5(
    _______,   _______,   _______,    _______,    _______,    _______,                         _______,     _______,     _______,    _______,    _______,    _______,
    _______,   _______,   _______,    _______,    _______,    _______,                         _______,     _______,     _______,    _______,    _______,    _______,
    _______,   _______,   _______,    _______,   DF(_NAV),    _______,                         _______,    DF(_NAV),     _______,    _______,    _______,    _______,
    _______,   _______,   _______,    _______,    _______,    _______,    _______,   _______,  _______,     _______,     _______,    _______,    _______,    _______,
              DF(_GAL),  DF(_GAR),   DF(_RUS),   DF(_QWE),   DF(_NOT),                        DF(_NOT),    DF(_QWE),    DF(_RUS),   DF(_GAR),    DF(_GAL)
)
};

void housekeeping_task_user(void) {
    achordion_task();
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case SW_ESC:
    case SW_GRV:
      return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    bool opposite = achordion_opposite_hands(tap_hold_record, other_record); // true if oppoite hands
    bool thumbs_exception = other_record->event.key.row == 4 || other_record->event.key.row == 9; // true if thumb keys
    uint8_t other_base = other_keycode & 0xFF;
    bool copy_paste_exception = (
        other_base == KC_C
     || other_base == KC_V
     || other_base == DE_Z
     || other_base == DE_Y
     || other_base == KC_X
     || other_base == KC_A
     || other_base == KC_K
     );
    return opposite || thumbs_exception || copy_paste_exception;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    // Your macros ...

    return true;
}

void set_color_hsv(int l) {
    uint8_t hue = rgb_matrix_get_hue();
    uint8_t sat = rgb_matrix_get_sat();
    uint8_t val = rgb_matrix_get_val();
    HSV hsv = {(hue + l * 50) % 256, sat, val};
    RGB rgb = hsv_to_rgb_nocie(hsv);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_user() {
    int layer = get_highest_layer(default_layer_state);
    if (get_highest_layer(layer_state) == _SWT) {
        return false;
    }

    if (layer <= _GAL) {
        set_color_hsv(layer);
    }
    return false;
}

void set_color(int i, int k) {
    uint8_t hue = rgb_matrix_get_hue();
    uint8_t sat = rgb_matrix_get_sat();
    uint8_t val = rgb_matrix_get_val();
    HSV hsv = {(hue + k * 50) % 256, sat, val};
    RGB rgb = hsv_to_rgb_nocie(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        if(get_highest_layer(layer_state) == _SWT) {
            if (i == 31) {
                set_color(i, 0);
            } else if (i == 32) {
                set_color(i, 1);
            } else if (i == 41) {
                set_color(i, 2);
            } else if (i == 42) {
                set_color(i, 3);
            } else if (i == 51) {
                set_color(i, 4);
            }
            else if (i == 1) {
                set_color(i, 0);
            } else if (i == 2) {
                set_color(i, 1);
            } else if (i == 11) {
                set_color(i, 2);
            } else if (i == 12) {
                set_color(i, 3);
            } else if (i == 21) {
                set_color(i, 4);
            } else {
                rgb_matrix_set_color(i, RGB_OFF);
            }
        }
    }
    return false;
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_NOT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(RGB_HUD, RGB_HUI) },
    [_QWE] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_RUS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_GAR] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_GAL] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_SPE] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_NAV] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_MOS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_FUN] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_SWT] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_layers {
//   _COLEMAK = 0,
	 _QWERTY = 0,
     _LOWER = 1,
     _UPPER = 2,
	 _ADJUST = 3
};

// #define KC_QWTR DF(_QWERTY)
// #define KC_COLM DF(_COLEMAK)

#define KC_CAD LCTL(LALT(KC_DEL))
#define RB_TOG RGB_TOG
#define RB_MOD RGB_MOD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* COLEMAK
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                   ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ ESC  │   1  │   2  │   3  │   4  │   5  │                   │   6  │   7  │   8  │   9  │   0  │ Bspc │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   F  │   P  │   B  │                   │   J  │   L  │   U  │   Y  │   O  │  - _ │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │LShift│   A  │   R  │   S  │   T  │   G  │                   │   M  │   N  │   E  │   I  │  ' " │RShift│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐     ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ LCTR │   Z  │   X  │   C  │   D  │   V  │ RGui │     │Enter │   K  │   H  │  , < │  . > │  / ? │  \ | │
 * └──────┴──────┴──────┴────┬─┴────┬─┴────┬─┴────┬─┘     └─┬────┴─┬────┴─┬────┴─┬────┴──────┴──────┴──────┘
 *                           │ LOWER│ LAlt │ Caps │         │Space │ RAlt │UPPER │
 *                           └──────┴──────┴──────┘         └──────┴──────┴──────┘
 */

/*
  [_COLEMAK] = LAYOUT(
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                           KC_J,    KC_L,    KC_U,    KC_Y,    KC_O,    KC_MINS,
     KC_LSFT, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                           KC_M,    KC_N,    KC_E,    KC_I,    KC_QUOT, KC_RSFT,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_LGUI,      KC_ENT,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                    TL_LOWR, KC_LALT, KC_CAPS,                KC_SPC,  KC_RALT,  TL_UPPR
  ),
  
*/  
  
/* QWERTY - This is the reference for the other layers.
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                   ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ ESC  │   1  │   2  │   3  │   4  │   5  │                   │   6  │   7  │   8  │   9  │   0  │ Bspc │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │                   │   Y  │   U  │   I  │   O  │   P  │  - _ │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │LShift│   A  │   S  │   D  │   F  │   G  │                   │   H  │   J  │   K  │   L  │  ' " │RShift│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐     ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ LCTR │   Z  │   X  │   C  │   V  │   B  │ RGui │     │Enter │   N  │   M  │  , < │  . > │  / ? │  \ | │
 * └──────┴──────┴──────┴────┬─┴────┬─┴────┬─┴────┬─┘     └─┬────┴─┬────┴─┬────┴─┬────┴──────┴──────┴──────┘
 *                           │ LOWER│ LAlt │ Caps │         │Space │ RAlt │UPPER │
 *                           └──────┴──────┴──────┘         └──────┴──────┴──────┘
 */
  
  [_QWERTY] = LAYOUT(
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_RSFT,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_LGUI,        KC_ENT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                    TL_LOWR, KC_LALT, KC_CAPS,                KC_SPC,  KC_RALT,  TL_UPPR
  ),

/* LOWER - Lower layer
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                   ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │                   │      │      │      │      │      │ C+A+D│
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │   {  │   }  │                   │      │      │   Up │      │      │   +  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │   [  │   ]  │                   │      │ Left │ Down │ Right│      │   =  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐     ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │     │      │      │      │   ;  │   :  │      │      │
 * └──────┴──────┴──────┴────┬─┴────┬─┴────┬─┴────┬─┘     └─┬────┴─┬────┴─┬────┴─┬────┴──────┴──────┴──────┘
 *                           │      │      │      │         │      │      │      │
 *                           └──────┴──────┴──────┘         └──────┴──────┴──────┘
 */

  [_LOWER] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_CAD,
     _______, _______, _______, _______, KC_LCBR, KC_RCBR,                            _______, _______, KC_UP,   _______, _______, KC_PLUS,
     _______, _______, _______, _______, KC_LBRC, KC_RBRC,                            _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_EQL,
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_SCLN, KC_COLN, _______, _______,
                                    _______, _______, _______,                    _______, _______, _______
  ),

/* UPPER - Upper layer
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                   ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │  F1  │   F2 │   F3 │   F4 │   F5 │   F6 │                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │  F7  │   F8 │   F9 │  F10 │  F11 │  F12 │                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐     ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ RGBT │ RGBM │      │      │      │ PTRS │      │     │      │      │      │      │      │      │      │
 * └──────┴──────┴──────┴────┬─┴────┬─┴────┬─┴────┬─┘     └─┬────┴─┬────┴─┬────┴─┬────┴──────┴──────┴──────┘
 *                           │      │      │      │         │      │      │      │
 *                           └──────┴──────┴──────┘         └──────┴──────┴──────┘
 */
  
  [_UPPER] = LAYOUT(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              _______, _______, _______, _______, _______, _______,
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                             _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     RB_TOG,  RB_MOD,  _______, _______, _______, KC_PSCR, _______,          _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  ),

/* ADJUST - Adjust layer for miscellaneous matter such as EEEPROM and reset
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                   ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │ Boot │                   │ Boot │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐     ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │     │      │      │      │      │      │      │      │
 * └──────┴──────┴──────┴────┬─┴────┬─┴────┬─┴────┬─┘     └─┬────┴─┬────┴─┬────┴─┬────┴──────┴──────┴──────┘
 *                           │      │      │      │         │      │      │      │
 *                           └──────┴──────┴──────┘         └──────┴──────┴──────┘
 */
  
  [_ADJUST] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, QK_BOOT,                            QK_BOOT, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  )
  
};

/* bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
			case _ADJUST:
				rgb_matrix_enable_noeeprom()
                rgb_matrix_mode_noeeprom(RGB_MATRIX_EFFECT_SOLID_COLOR);
				rgb_matrix_sethsv_noeeprom(HSV_WHITE); // white
                break;
			case _UPPER:
				rgb_matrix_enable_noeeprom()
				rgb_matrix_mode_noeeprom(RGB_MATRIX_EFFECT_SOLID_COLOR);
				rgb_matrix_sethsv_noeeprom(HSV_GOLD); // gold
                break;
			case _LOWER:
				rgb_matrix_enable_noeeprom()
                rgb_matrix_mode_noeeprom(RGB_MATRIX_EFFECT_SOLID_COLOR);
				rgb_matrix_sethsv_noeeprom(HSV_BLUE); // blue
                break;
            case _QWERTY:
				rgb_matrix_enable_noeeprom()
                rgb_matrix_mode_noeeprom(RGB_MATRIX_EFFECT_SOLID_COLOR);
				rgb_matrix_sethsv_noeeprom(HSV_MAGENTA); // magenta
                break;
            default:
				rgb_matrix_disable_noeeprom();
                break;
        }
    }
    return false;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
    }
    return false;
}
*/

/*

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state); 

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t led_index = g_led_config.matrix_co[row][col]; // Get the LED index for the key position

                if (index >= led_min && index < led_max && index != NO_LED &&
                    keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {

                    switch (layer) {
                        case _ADJUST: // Or use your layer name, e.g., _ADJUST
                            rgb_matrix_mode_noeeprom(RGB_MATRIX_EFFECT_SOLID_COLOR);
							rgb_matrix_sethsv_noeeprom(HSV_WHITE); // WHITE
                            break;

                        case _UPPER: // Or use your layer name, e.g., _UPPER
                            rgb_matrix_mode_noeeprom(RGB_MATRIX_EFFECT_SOLID_COLOR);
							rgb_matrix_sethsv_noeeprom(HSV_GOLD); // GOLD
                            break;

                        case _LOWER: // Or use your layer name, e.g., _LOWER
                            rgb_matrix_mode_noeeprom(RGB_MATRIX_EFFECT_SOLID_COLOR);
							rgb_matrix_sethsv_noeeprom(HSV_MAGENTA); // MAGENTA
                            break;

                        default:
                            break;
                    }
                }
            }
        }
    }
    return false;
}

*/
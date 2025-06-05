// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/*
typedef union {
  uint32_t raw;
  struct {
    bool     rgb_layer_change :1;
  };
} user_config_t;

user_config_t user_config;
*/

enum my_keycodes {
  FOO = SAFE_RANGE,
  RGB_LYR
};

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
#define KC_CSE LCTL(LSFT(KC_ENT))
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
 * │ Tab  │   Q  │   W  │   E  │   R  │   T  │                   │   Y  │   U  │   I  │   O  │   P  │ Enter│
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │LShift│   A  │   S  │   D  │   F  │   G  │                   │   H  │   J  │   K  │   L  │  ' " │RShift│
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐     ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ LCTR │   Z  │   X  │   C  │   V  │   B  │  / ? │     │  \ | │   N  │   M  │  , < │  . > │  - _ │ RGui │
 * └──────┴──────┴──────┴────┬─┴────┬─┴────┬─┴────┬─┘     └─┬────┴─┬────┴─┬────┴─┬────┴──────┴──────┴──────┘
 *                           │ LOWER│ LAlt │Space │         │Space │ RAlt │UPPER │
 *                           └──────┴──────┴──────┘         └──────┴──────┴──────┘
 */
  
  [_QWERTY] = LAYOUT(
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_ENT,
     KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_RSFT,
     KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_SLSH,       KC_BSLS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS, KC_RGUI,
                                    TL_LOWR, KC_LALT, KC_SPC,                KC_SPC,  KC_RALT,  TL_UPPR
  ),

/* LOWER - Lower layer
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                   ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │                   │      │      │      │      │      │ C+A+D│
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │   {  │   }  │                   │      │   +  │   Up │   =  │      │ C+S+E│
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │   [  │   ]  │                   │      │ Left │ Down │ Right│      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐     ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │     │      │      │      │   ;  │   :  │      │      │
 * └──────┴──────┴──────┴────┬─┴────┬─┴────┬─┴────┬─┘     └─┬────┴─┬────┴─┬────┴─┬────┴──────┴──────┴──────┘
 *                           │      │      │      │         │ Caps │      │      │
 *                           └──────┴──────┴──────┘         └──────┴──────┴──────┘
 */

  [_LOWER] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_CAD,
     _______, _______, _______, _______, KC_LCBR, KC_RCBR,                            _______, KC_PLUS, KC_UP,   KC_EQL,  _______, KC_CSE,
     _______, _______, _______, _______, KC_LBRC, KC_RBRC,                            _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_SCLN, KC_COLN, _______, _______,
                                    _______, _______, _______,                    KC_CAPS, _______, _______
  ),

/* UPPER - Upper layer
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                   ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │  F1  │   F2 │   F3 │   F4 │   F5 │   F6 │                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │  F7  │   F8 │   F9 │  F10 │  F11 │  F12 │                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐     ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │ RGBT │ RGBM │  LYR │      │      │ PTRS │      │     │      │      │      │      │      │      │      │
 * └──────┴──────┴──────┴────┬─┴────┬─┴────┬─┴────┬─┘     └─┬────┴─┬────┴─┬────┴─┬────┴──────┴──────┴──────┘
 *                           │      │      │      │         │      │      │      │
 *                           └──────┴──────┴──────┘         └──────┴──────┴──────┘
 */
  
  [_UPPER] = LAYOUT(
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                              _______, _______, _______, _______, _______, _______,
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                             _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     RB_TOG,  RB_MOD,  RGB_LYR, _______, _______, KC_PSCR, _______,          _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  ),

/* ADJUST - Adjust layer for miscellaneous matter such as EEEPROM and reset
 * ┌──────┬──────┬──────┬──────┬──────┬──────┐                   ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │      │      │      │      │                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │ Boot │                   │ Boot │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                   ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │EEPROM│                   │      │      │      │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┐     ┌──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │      │      │      │      │     │      │      │      │      │      │      │      │
 * └──────┴──────┴──────┴────┬─┴────┬─┴────┬─┴────┬─┘     └─┬────┴─┬────┴─┬────┴─┬────┴──────┴──────┴──────┘
 *                           │      │      │      │         │      │      │      │
 *                           └──────┴──────┴──────┘         └──────┴──────┴──────┘
 */
  
  [_ADJUST] = LAYOUT(
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, QK_BOOT,                            QK_BOOT, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, EE_CLR,                             _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
                                    _______, _______, _______,                   _______, _______, _______
  )
  
};

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_GOLD);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
		
        // Get the active layer
        uint8_t layer = get_highest_layer(layer_state|default_layer_state);

        // Pick a color based on the active layer, using HSV values.
        hsv_t hsv = {36, 255, 255}; // GOLD
		
        switch(layer) {
            case _ADJUST:
				hsv = (hsv_t){0, 255, 255}; // RED
                break;
            case _UPPER:
				hsv = (hsv_t){106, 255, 255}; // SPRINGGREEN
                break;
			case _LOWER:
				hsv = (hsv_t){191, 255, 255}; // PURPLE
                break;
            default:
				hsv = (hsv_t){36, 255, 255}; // GOLD
                break;
        }
		
		if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
		}
		
		rgb_t rgb = hsv_to_rgb(hsv); // Conversion from hsv to rgb.

        // Set the color of all keys that are not transparent to the color picked above
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
					rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b); // Values for RGB instead of HSV
                }
            }
        }
        
    }
    return false;
}
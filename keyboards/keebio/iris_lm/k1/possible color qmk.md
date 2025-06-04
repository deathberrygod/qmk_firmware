#include QMK_KEYBOARD_H // Essential for QMK functions and macros
// Make sure you have RGB_MATRIX_ENABLE = yes in rules.mk
// And #define RGB_MATRIX_ENABLE in config.h

// 1. Define your HSV colors for each layer
// You can adjust these values (0-255 for H, S, V)
#define LAYER_0_HUE 0   // Red
#define LAYER_1_HUE 85  // Green
#define LAYER_2_HUE 170 // Blue
#define LAYER_3_HUE 255 // Magenta (or another color)

// Common saturation and value if you want them consistent
#define LAYER_SATURATION 255 // Full saturation
#define LAYER_VALUE      255 // Full brightness

// Your layer enums (make sure these match your keymap.c)
enum {
    _BASE = 0,
    _FN1,
    _FN2,
    _FN3,
    // Add more layers as needed
};

// This function is called by QMK to update RGB Matrix indicators
// led_min and led_max define the range of LEDs this instance should handle (useful for split keyboards)
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // 2. Determine the active layer
    uint8_t layer = get_highest_layer(layer_state);

    // Declare an RGB struct to hold the color for the current layer
    RGB layer_color_rgb;

    // 3. Use a switch statement to select the color based on the layer
    switch (layer) {
        case _BASE:
            layer_color_rgb = hsv_to_rgb(HSV(LAYER_0_HUE, LAYER_SATURATION, LAYER_VALUE));
            break;
        case _FN1:
            layer_color_rgb = hsv_to_rgb(HSV(LAYER_1_HUE, LAYER_SATURATION, LAYER_VALUE));
            break;
        case _FN2:
            layer_color_rgb = hsv_to_rgb(HSV(LAYER_2_HUE, LAYER_SATURATION, LAYER_VALUE));
            break;
        case _FN3:
            layer_color_rgb = hsv_to_rgb(HSV(LAYER_3_HUE, LAYER_SATURATION, LAYER_VALUE));
            break;
        default:
            // Optional: Set a default color for undefined layers or if no layer is active (layer 0 usually handles this)
            layer_color_rgb = hsv_to_rgb(HSV(0, 0, 0)); // Black/off
            break;
    }

    // Now, iterate through all possible key matrix positions
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col_offset < MATRIX_COLS; ++col) {
            // Get the physical LED index from the matrix coordinates
            // g_led_config.matrix_co is a 2D array mapping (row, col) to a linear LED index
            uint8_t index = g_led_config.matrix_co[row][col];

            // 4. Apply that color to each non-transparent key.
            // Check if the current index is valid for this side of the split keyboard (if applicable)
            // and if it's a valid LED (not NO_LED)
            if (index >= led_min && index < led_max && index != NO_LED) {
                // Check if the keycode at this (row, col) on the *current* active layer
                // is NOT transparent (KC_TRNS).
                // If it's KC_TRNS, it means the key "falls through" to a lower layer.
                // We only want to light up keys that are *actually defined* on this layer.
                if (keymap_key_to_keycode(layer, (keypos_t){.row = row, .col = col}) != KC_TRNS) {
                    // Set the LED color for this specific key
                    rgb_matrix_set_color(index, layer_color_rgb.r, layer_color_rgb.g, layer_color_rgb.b);
                } else {
                    // If the key is transparent (KC_TRNS) on the active layer, turn its LED off
                    // This is crucial to prevent "ghost" lights from lower layers
                    rgb_matrix_set_color(index, 0, 0, 0); // Black/off
                }
            }
        }
    }

    // Return false to allow other RGB Matrix effects (like animations) to run.
    // If you return true, you would fully control the LEDs and no other effects would run.
    // For a pure layer indicator, returning false is often desired if you want
    // the base layer to have an animation and then switch to solid on function layers.
    // However, if you want *only* the solid color per layer and no other effects,
    // you might consider returning true, or explicitly setting rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR)
    // at the start of this function and then returning true.
    return false;
}
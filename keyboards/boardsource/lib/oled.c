// Copyright 2024 jack (@waffle87)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "oled.h"

void render_layer_state(void) {
    uint8_t current_layer = get_highest_layer(layer_state);

    switch (current_layer) {
        case 0:
            oled_write_raw_P(layer0_img, sizeof(layer0_img));
            break;
        case 1:
            oled_write_raw_P(layer1_img, sizeof(layer1_img));
            break;
        case 2:
            oled_write_raw_P(layer2_img, sizeof(layer2_img));
            break;
        case 3:
            oled_write_raw_P(layer3_img, sizeof(layer3_img));
            break;
/*        case 5:  // _GMLAY0 - Gaming layer
            oled_write_raw_P(layer5_img, sizeof(layer5_img));
            break;
        case 11:  // _LAYERS - Layers menu
            oled_write_raw_P(layer11_img, sizeof(layer11_img));
            break;
        case 12:  // _KTIMER - Timer layer
            oled_write_raw_P(layer12_img, sizeof(layer12_img));
            break;
        default:
            // Fallback for any other layers
            oled_write_P(PSTR("Layer\n"), false);
            char layer_str[4];
            snprintf(layer_str, sizeof(layer_str), "%d\n", current_layer);
            oled_write(layer_str, false);
            break;
*/
    }
}

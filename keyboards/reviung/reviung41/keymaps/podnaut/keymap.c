/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "users/podnaut/keymaps/34k.h"

#define LAYOUT_3x12_5_wrapper(...) LAYOUT_reviung41(__VA_ARGS__)
#define LAYOUT_3x12_5_base( \
    K01, K02, K03, K04, K05,  K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15,  K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25,  K26, K27, K28, K29, K2A, \
                   K34, K35,  K37, K36                 \
    ) \
    LAYOUT_reviung41( \
        KC_TRNS, K01, K02, K03, K04, K05,         K06, K07, K08, K09, K0A, KC_TRNS, \
        KC_TRNS, K11, K12, K13, K14, K15,         K16, K17, K18, K19, K1A, KC_TRNS, \
        KC_TRNS, K21, K22, K23, K24, K25,         K26, K27, K28, K29, K2A, KC_TRNS, \
                                K34, K35, USFUNC, K37, K36                          \
    )
#define LAYOUT_3x12_5_base_wrapper(...)       LAYOUT_3x12_5_base(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_3x12_5_base_wrapper(QWERTY_3x10_4),
  [_CLMKdh] = LAYOUT_3x12_5_base_wrapper(CLMKdh_3x10_4),
  [_LOMODS] = LAYOUT_3x12_5_wrapper(MODS41_3x12_5),
  [_NAVNUM] = LAYOUT_3x12_5_base_wrapper(NAVNUM_3x10_4),
  [_USFUNC] = LAYOUT_3x12_5_base_wrapper(USFUNC_3x10_4),
  [_LAYERS] = LAYOUT_3x12_5_base_wrapper(LAYERS_3x10_4),
  [_GAMING] = LAYOUT_3x12_5_base_wrapper(GAMING_3x10_4),
  [_SCRAFT] = LAYOUT_3x12_5_base_wrapper(SCRAFT_3x10_4),
  [_CTLGR1] = LAYOUT_3x12_5_base_wrapper(CTLGR1_3x10_4),
  [_CTLGR2] = LAYOUT_3x12_5_base_wrapper(CTLGR2_3x10_4),
  [_CAMGR1] = LAYOUT_3x12_5_base_wrapper(CAMGR1_3x10_4),
  [_CAMGR2] = LAYOUT_3x12_5_base_wrapper(CAMGR2_3x10_4),
};
// clang-format on

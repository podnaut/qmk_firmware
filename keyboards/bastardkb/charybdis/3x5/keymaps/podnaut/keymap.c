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

#define LAYOUT_charybdis_3x5_wrapper(...) LAYOUT_charybdis_3x5(__VA_ARGS__)
#define LAYOUT_charybdis_3x5_base( \
    K01, K02, K03, K04, K05,  K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15,  K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25,  K26, K27, K28, K29, K2A, \
                   K34, K35,  K37, K36                 \
    ) \
    LAYOUT_charybdis_3x5 ( \
       K01, K02, K03, K04, K05   , K06, K07, K08, K09, K0A, \
       K11, K12, K13, K14, K15   , K16, K17, K18, K19, K1A, \
       K21, K22, K23, K24, K25   , K26, K27, K28, K29, K2A, \
                 K34, K35, FN2MON, K36, K37                 \
    )
#define LAYOUT_charybdis_3x5_base_wrapper(...)       LAYOUT_charybdis_3x5_base(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHAS] = LAYOUT_charybdis_3x5_base_wrapper(QWERTY_3x10_4),
  [_FNLAY0] = LAYOUT_charybdis_3x5_base_wrapper(LEFT_NAVIGATION_RIGHT_NUMBERS_3x10_4),
  [_FNLAY1] = LAYOUT_charybdis_3x5_base_wrapper(UTILITY_SYMBOLS_FUNCTIONS_3x10_4),
  [_FNLAY2] = LAYOUT_charybdis_3x5_base_wrapper(BKB_MOUSE_3x10_4),
  [_GMLAY0] = LAYOUT_charybdis_3x5_base_wrapper(WASD_GAMES_3x10_4),
  [_GMLAY1] = LAYOUT_charybdis_3x5_base_wrapper(STARCRAFT_3x10_4),
  [_GMLAY2] = LAYOUT_charybdis_3x5_base_wrapper(CONTROL_GROUP_1_3x10_4),
  [_GMLAY3] = LAYOUT_charybdis_3x5_base_wrapper(CONTROL_GROUP_2_3x10_4),
  [_LAYERS] = LAYOUT_charybdis_3x5_base_wrapper(LAYERS_3x10_4),
  [_KTIMER] = LAYOUT_charybdis_3x5_base_wrapper(KTIMER_3x10_4),
};
// clang-format on

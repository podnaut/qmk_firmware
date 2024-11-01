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

#define LAYOUT_dilemma(...) LAYOUT_split_3x5_2(__VA_ARGS__)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_ALPHAS] = LAYOUT_dilemma(QWERTY_3x10_4),
  [_FNLAY0] = LAYOUT_dilemma(LEFT_NAVIGATION_RIGHT_NUMBERS_3x10_4),
  [_FNLAY1] = LAYOUT_dilemma(UTILITY_SYMBOLS_FUNCTIONS_3x10_4),
  [_FNLAY2] = LAYOUT_dilemma(BKB_MOUSE_3x10_4),
  [_GMLAY0] = LAYOUT_dilemma(WASD_GAMES_3x10_4),
  [_GMLAY1] = LAYOUT_dilemma(STARCRAFT_3x10_4),
  [_GMLAY2] = LAYOUT_dilemma(CONTROL_GROUP_1_3x10_4),
  [_GMLAY3] = LAYOUT_dilemma(CONTROL_GROUP_2_3x10_4),
  [_LAYERS] = LAYOUT_dilemma(LAYERS_3x10_4),
  [_KTIMER] = LAYOUT_dilemma(KTIMER_3x10_4),
};
// clang-format on



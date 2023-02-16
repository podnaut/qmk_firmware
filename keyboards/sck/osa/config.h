/*
Copyright 2019 jrfhoutx

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


/* key matrix size */
#define MATRIX_ROWS 10
#define MATRIX_COLS 8

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6, B0, B1, B2, B3, B7 }
#define MATRIX_COL_PINS { B4, D7, D5, D3, D2, D0, D1, B5 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

   #define RGB_DI_PIN D4
   #ifdef RGB_DI_PIN
   #define RGBLED_NUM 9
   #define RGBLIGHT_HUE_STEP 10
   #define RGBLIGHT_SAT_STEP 17
   #define RGBLIGHT_VAL_STEP 17
   #define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
   #define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
   #endif

#define LED_NUM_LOCK_PIN C7
#define LED_CAPS_LOCK_PIN C6
#define LED_SCROLL_LOCK_PIN B6

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

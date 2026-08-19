/* Copyright 2020 Snipeye
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

static uint32_t key_timer = 0;
static bool key_trigger = false;
enum custom_keycodes {
    KEY_TIMER = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case KEY_TIMER:
            if (record->event.pressed) {
                key_trigger ^= true;
                tap_code(KC_LGUI);
                _delay_ms(250);
                tap_code(KC_LGUI);
            }
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (timer_elapsed32(key_timer) > 1500) { // 1.5 seconds
        key_timer = timer_read32();  // resets timer
        if (key_trigger) tap_code(KC_BTN1); // send left mouse button click if enabled
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [0] = LAYOUT(
            KEY_TIMER
          )
};

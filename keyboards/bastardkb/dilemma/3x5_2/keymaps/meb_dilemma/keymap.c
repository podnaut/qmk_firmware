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

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUM_NAV,
    LAYER_NUM_SYM_FUNC,

};

// tap dances

void kc_q_esc(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code(KC_Q);
            break;
        case 2:
            tap_code(KC_ESC);
    }
}

void kc_a_tab(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code(KC_A);
            break;
        case 2:
            tap_code(KC_TAB);
    }
}

void home_ctrl_left(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(LCTL(KC_LEFT));
            break;
        case 2:
            tap_code(KC_HOME);
    }
}

void end_ctrl_right(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(LCTL(KC_RIGHT));
            break;
        case 2:
            tap_code(KC_END);
    }
}

enum tap_dances {
    TD_KCQESC = 0,
    TD_KCATAB,
    TD_HOMCLT,
    TD_ENDCRT
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_KCQESC] = ACTION_TAP_DANCE_FN(kc_q_esc),
    [TD_KCATAB] = ACTION_TAP_DANCE_FN(kc_a_tab),
    [TD_HOMCLT] = ACTION_TAP_DANCE_FN(home_ctrl_left),
    [TD_ENDCRT] = ACTION_TAP_DANCE_FN(end_ctrl_right),

};
// convenience keycodes

#define KCQESC TD(TD_KCQESC)
#define KCATAB TD(TD_KCATAB)
#define KCZSFT LSFT_T(KC_Z)
#define PIPSFT LSFT_T(KC_PIPE)
#define CTLDEL LCTL_T(KC_DEL)
#define ENTLAY LT(LAYER_NUM_NAV,KC_ENT)

#define SLHSFT RSFT_T(KC_SLSH)
#define SPCLAY LT(LAYER_NUM_NAV,KC_SPC)
#define ALTBSP LALT_T(KC_BSPC)
#define ALTKC0 LALT_T(KC_0)

#define DRHOLD LT(LAYER_NUM_SYM_FUNC, KC_ENT) 
#define DLHOLD LT(LAYER_NUM_SYM_FUNC, KC_SPC)

#define CTLKCZ LCTL(KC_Z)
#define CTLKCY LCTL(KC_Y)
#define SFTTAB LSFT(KC_TAB)
#define HOMCLT TD(TD_HOMCLT)
#define ENDCRT TD(TD_ENDCRT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KCQESC,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KCATAB,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KCZSFT,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, SLHSFT ,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                   CTLDEL,  ENTLAY,     SPCLAY,    ALTBSP
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),
/*
  [LAYER_BASE] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
        KCQESC,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KCATAB,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I, KC_O   ,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
        KCZSFT,    KC_X,    KC_C,    KC_D,    KC_V,       KC_K,    KC_H, KC_COMM,  KC_DOT, SLHSFT ,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                   CTLDEL,  ENTLAY,     SPCLAY,    ALTBSP
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),
*/
  [LAYER_NUM_NAV] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       HOMCLT ,KC_UP  , ENDCRT ,KC_PLUS, KC_LPRN,      KC_RPRN, KC_7   , KC_8   , KC_9   , KC_TAB ,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LEFT,KC_DOWN,KC_RIGHT, KC_EQL, KC_LCBR,      KC_RCBR, KC_4   , KC_5   , KC_6   , KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       PIPSFT ,KC_UNDS, KC_COLN,KC_MINS, KC_LBRC,      KC_LBRC, KC_1   , KC_2   , KC_3   , SFTTAB ,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                KC_TRNS, DRHOLD ,      DLHOLD , ALTKC0
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUM_SYM_FUNC] = LAYOUT_split_3x5_2(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,    KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,    KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                                  KC_CAPS, KC_NO,      KC_NO  , KC_TRNS
  //                            ╰──────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on


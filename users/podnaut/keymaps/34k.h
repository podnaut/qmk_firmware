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

#pragma once

#include "quantum.h"
#include "features/custom_shift_keys.h"

#ifdef CREDS
    #include "creds.c"
#endif

/*---------------------------------------------------------------------------------------------------------------------------------------------------
Definitions, enumerations, and custom functions======================================================================================================
---------------------------------------------------------------------------------------------------------------------------------------------------*/

// Layers--------------------------------------------------------------------------------------------------------------------------------------------

enum layers {
    _ALPHAS = 0,
    _MDLAY0,
    _FNLAY0,
    _FNLAY1,
    _FNLAY2,

#ifdef LAYERTHUMBS
    _FNLAY3,
    _FNLAY4,
#endif

    _GMLAY0,
    _GMLAY1,
    _GMLAY2,
    _GMLAY3,
    _GMLAY4,
    _GMLAY5,
    _LAYERS,

#ifdef KEYTIMER
    _KTIMER,
#endif

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    _MSAUTO,
#endif
};

#define MD0TOG TG(_MDLAY0)

// Generic base thumbs shortcuts.
#define FN0ENT LT(_FNLAY0, KC_ENT)
#define FN0SPC LT(_FNLAY0, KC_SPC)
#define FN1MON MO(_FNLAY1)
#define FN2MON MO(_FNLAY2)

// Layer thumb shortcuts.
#define FN0DEL LT(_FNLAY0, KC_DEL)
#define FN1ENT LT(_FNLAY1, KC_ENT)
#define FN2SPC LT(_FNLAY2, KC_SPC)
#define FN3BSP LT(_FNLAY3, KC_BSPC)

// Other layer shortcuts.
#define LAYERS MO(_LAYERS)
//#define KTTOGG TG(_KTIMER)
#define GM0TOG TG(_GMLAY0)
#define GM3TOG TG(_GMLAY3)
#define GM4SPC LT(_GMLAY4, KC_SPC)
#define GM4ENT LT(_GMLAY4, KC_ENT)
#define GM5ENT LT(_GMLAY5, KC_ENT)

/*
#define GM3MON MO(_GMLAY3)
#define GM4MON MO(_GMLAY4)
*/

// Enumerate custom keycodes-------------------------------------------------------------------------------------------------------------------------

enum custom_keycodes {
    CTLDEL = SAFE_RANGE,
    KTSTRT,
    KTPLUS,
    KTMINS,
    KTPRNT,
    KTTOGG,
    SLLINE,
    DLLINE,
    CTLINE,
    SLWORD,
    GCHATE,
    //PRKMAP,

    #ifdef CREDS
        PBPASS,
        PPEMAI,
        PWEMAI,
        PPPHON,
        PWPHON,
        PADDRE,
        PFNAME,
    #endif
};

// Tap dances----------------------------------------------------------------------------------------------------------------------------------------

void td_media_fn(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code16(KC_MPLY);
            break;
        case 2:
            tap_code16(KC_MNXT);
            break;
        case 3:
            tap_code16(KC_MPRV);}
};

void dance_home_finished(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_LCTL);
            register_code(KC_LEFT);
            break;
        case 2:
            register_code(KC_HOME);
    }
};

void dance_home_reset (tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            unregister_code(KC_LCTL);
            unregister_code(KC_LEFT);
            break;
        case 2:
            unregister_code(KC_HOME);
    }
};

void dance_end_finished (tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_LCTL);
            register_code(KC_RIGHT);
            break;
        case 2:
            register_code(KC_END);
    }
};

void dance_end_reset (tap_dance_state_t *state, void *user_data) {

    switch (state->count) {
        case 1:
            unregister_code(KC_LCTL);
            unregister_code(KC_RIGHT);
            break;
        case 2:
            unregister_code(KC_END);
    }
};

void esc_alt_tab(tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            tap_code(KC_ESC);
            break;
        case 2:
            tap_code16(LCTL(LALT(KC_TAB)));
    }
};

void dance_ctl_num_finished (tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_LCTL);
            break;
        case 2:
            layer_on(_GMLAY1);
    }
};

void dance_ctl_num_reset (tap_dance_state_t *state, void *user_data) {

    switch (state->count) {
        case 1:
            unregister_code(KC_LCTL);
            break;
        case 2:
            layer_off(_GMLAY1);
    }
};

void r_t_finished (tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_R);
            break;
        case 2:
            register_code(KC_T);
    }
};

void r_t_reset (tap_dance_state_t *state, void *user_data) {

    switch (state->count) {
        case 1:
            unregister_code(KC_R);
            break;
        case 2:
            unregister_code(KC_T);
    }
};

void f_g_finished (tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_F);
            break;
        case 2:
            register_code(KC_G);
    }
};

void f_g_reset (tap_dance_state_t *state, void *user_data) {

    switch (state->count) {
        case 1:
            unregister_code(KC_F);
            break;
        case 2:
            unregister_code(KC_G);
    }
};

void v_b_finished (tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1:
            register_code(KC_V);
            break;
        case 2:
            register_code(KC_B);
    }
};

void v_b_reset (tap_dance_state_t *state, void *user_data) {

    switch (state->count) {
        case 1:
            unregister_code(KC_V);
            break;
        case 2:
            unregister_code(KC_B);
    }
};

enum tap_dances {
    TD_MEDIA = 0,
    TD_QESC,
    TD_ATAB,
    TD_HOMCLT,
    TD_ENDCRT,
    TD_EATAB,
    TD_CTLNUM,
    TD_R_T,
    TD_F_G,
    TD_V_B,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_MEDIA] = ACTION_TAP_DANCE_FN(td_media_fn),
    [TD_QESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_ATAB] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB),
    [TD_HOMCLT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_home_finished, dance_home_reset),
    [TD_ENDCRT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_end_finished, dance_end_reset),
    [TD_EATAB] = ACTION_TAP_DANCE_FN(esc_alt_tab),
    [TD_CTLNUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_ctl_num_finished, dance_ctl_num_reset),
    [TD_R_T] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r_t_finished, r_t_reset),
    [TD_F_G] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, f_g_finished, f_g_reset),
    [TD_V_B] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, v_b_finished, v_b_reset),


};

#define MEDIA TD(TD_MEDIA)
#define QESC TD(TD_QESC)
#define ATAB TD(TD_ATAB)
#define HOMCLT TD(TD_HOMCLT)
#define ENDCRT TD(TD_ENDCRT)
#define EATAB TD(TD_EATAB)
#define CTLNUM TD(TD_CTLNUM)

// Custom Shift Keys---------------------------------------------------------------------------------------------------------------------------------

const custom_shift_key_t custom_shift_keys[] = {
  {KC_LCBR , KC_LBRC},
  {KC_RCBR, KC_RBRC},
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

// Convenience macros--------------------------------------------------------------------------------------------------------------------------------

#define ALT_BSP LALT_T(KC_BSPC)
#define GUI_N_0 LGUI_T(KC_0)
#define SFTZ LSFT_T(KC_Z)
#define SFTSPC LSFT_T(KC_SPC)
#define SFTSLSH LSFT_T(KC_SLSH)
#define SFTBSLS LSFT_T(KC_BSLS)
#define CTL_DEL LCTL_T(KC_DEL)
#define COMMB KC_COMM

#ifdef COMMAMOUSE
    #define COMMA LT(FN2MON, KC_COMM)
#else
    #define COMMA KC_COMM
#endif

#ifdef LAYERTHUMBS
    #define __________________________________________QWERTY_BOTTOM_ALPHAS__________________________________________ KC_LSFT,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_RSFT,
    #define __________________________________________CLMKDH_BOTTOM_ALPHAS__________________________________________ KC_LSFT,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H, KC_COMM,  KC_DOT, KC_RSFT,,
    #define ____________BASE_THUMBS___________ FN0DEL, FN1ENT, FN2SPC, FN3BSP
#else
    #define __________________________________________QWERTY_BOTTOM_ALPHAS__________________________________________ SFTZ,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   COMMA,  KC_DOT, SFTSLSH,
    #define __________________________________________CLMKDH_BOTTOM_ALPHAS__________________________________________ SFTZ,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,   COMMA,  KC_DOT, SFTSLSH,
    #define ____________BASE_THUMBS___________ CTL_DEL, FN0ENT, FN0SPC, ALT_BSP
#endif

#define ___x___ KC_NO
#define _______ KC_TRNS

/*---------------------------------------------------------------------------------------------------------------------------------------------------
Layouts and layers: =================================================================================================================================
---------------------------------------------------------------------------------------------------------------------------------------------------*/

// Alpha Layouts----------------------------------------------------------------------------------------------------------------------------------

// QWERTY layout.
// clang-format off
#define QWERTY_3x10_4                                                                                           \
       QESC,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
       ATAB,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, \
       __________________________________________QWERTY_BOTTOM_ALPHAS__________________________________________ \
                                        ____________BASE_THUMBS___________                                      \
// clang-format on

// COLEMAK-dh layout.
// clang-format off
#define COLEMAK_DH_3x10_4                                                                                       \
       QESC,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, \
       ATAB,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O, \
       __________________________________________CLMKDH_BOTTOM_ALPHAS__________________________________________ \
                                        ____________BASE_THUMBS___________                                      \
// clang-format on

// Function Layers---------------------------------------------------------------------------------------------------------------------------------

#define BKB_MOUSE_3x10_4                                                                                        \
   S_D_RMOD, S_D_MOD,DPI_RMOD, DPI_MOD, _______,                   ___x___, ___x___, ___x___, ___x___, ___x___, \
    SNIPING, KC_BTN3, KC_BTN2, KC_BTN1, _______,                   ___x___, ___x___, ___x___, ___x___, ___x___, \
    _______, _______, _______, _______, _______,                   ___x___, ___x___, ___x___, ___x___, ___x___, \
                                        _______, _______, ___x___, ___x___                                      \
// clang-format on

// Auto mouse layer.
// clang-format off

#define AUTO_MOUSE_3x10_4                                                                                       \
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, \
    KC_LSFT, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_LSFT, \
    KC_BTN2, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_BTN1, \
                                        _______, _______, _______, _______                                      \
// clang-format on

// Left navigation, right numbers layer.
// clang-format off
#define LEFT_NAVIGATION_RIGHT_NUMBERS_3x10_4                                                                    \
      EATAB,  HOMCLT,   KC_UP,  ENDCRT, KC_LPRN,                   KC_RPRN,    KC_7,    KC_8,    KC_9, KC_PIPE, \
     KC_TAB, KC_LEFT, KC_DOWN,KC_RIGHT, KC_LCBR,                   KC_RCBR,    KC_4,    KC_5,    KC_6, KC_SCLN, \
     SFTSPC, KC_UNDS, KC_COLN, KC_MINS,KC_EQUAL,                   KC_PLUS,    KC_1,    KC_2,    KC_3, SFTBSLS, \
                                         CTLDEL,  FN1MON,  FN1MON, GUI_N_0                                      \
// clang-format on

// Utility, symbols, and functions layer.
// clang-format off
#define UTILITY_SYMBOLS_FUNCTIONS_3x10_4                                                                        \
    KC_CAPS,  KC_GRV, KC_TILD, KC_PGUP, KC_PGDN,                   KC_MUTE, KC_VOLD, KC_VOLU,   MEDIA,  LAYERS, \
    KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, \
                                         KC_F11, ___x___, ___x___,  KC_F12                                      \
// clang-format on

// Layer navigation layer.
// clang-format off
#define LAYERS_3x10_4                                                                                           \
     KTTOGG, _______, _______, _______, _______,                    GM0TOG,  MD0TOG, _______, _______, _______, \
     PADDRE,  PPEMAI,  PPPHON,  PBPASS,  PWEMAI,                    GM3TOG, _______, _______, _______, _______, \
     SLLINE,  CTLINE,  DLLINE,  SLWORD, _______,                   QK_BOOT, _______, _______, _______, _______, \
                                         KTMINS, _______, _______,  KTPLUS                                      \
// clang-format on

// Key timer layer.
// clang-format off
#define KTIMER_3x10_4                                                                                           \
     KTTOGG, ___x___, ___x___, ___x___, ___x___,                   ___x___, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, ___x___,                   ___x___, ___x___, ___x___, ___x___, ___x___, \
    ___x___, ___x___, ___x___, ___x___, ___x___,                   ___x___, ___x___, ___x___, ___x___, ___x___, \
                                         KTMINS,  KTPRNT,  KTSTRT,  KTPLUS                                      \
// clang-format on

// Gaming Layers------------------------------------------------------------------------------------------------------------------------------------

// Generic gaming layout.
// clang-format off
#define WASD_GAMES_3x10_4                                                                                       \
       KC_ESC,  KC_Q,    KC_W,    KC_E, TD(TD_R_T),                   _______, _______, _______, _______,   MEDIA, \
       KC_TAB,  KC_A,    KC_S,    KC_D, TD(TD_F_G),                   _______, _______, _______, _______, _______, \
      KC_LSFT,  KC_Z,    KC_X,    KC_C, TD(TD_V_B),                   _______, _______, _______, _______,  GCHATE, \
                                            CTLNUM,  KC_SPC, _______,  GM0TOG                                      \
// clang-format on

// Generic gaming numbers.
// clang-format off
#define WASD_NUMBERS_3x10_4                                                                                       \
      _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, \
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   _______, _______, _______, _______, _______, \
         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                   _______, _______, _______, _______, _______, \
                                          _______, _______, _______, _______                                      \
// clang-format on

// Generic gaming chat.
// clang-format off
#define WASD_CHAT_3x10_4                                                                                        \
         QESC,    KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
         ATAB,    KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,    KC_L, KC_QUOT, \
         SFTZ,    KC_X,    KC_C,    KC_V,    KC_B,                    KC_N,    KC_M,   COMMA,  KC_DOT,  GCHATE, \
                                          CTL_DEL, GCHATE, FN0SPC, ALT_BSP                                      \
// clang-format on

// Starcraft layout.
// clang-format off
#define STARCRAFT_3x10_4                                                                                        \
       QESC,    KC_W,    KC_E,    KC_R,    KC_T,                   _______, _______, _______, _______, _______, \
       ATAB,    KC_S,    KC_D,    KC_F,    KC_G,                   _______, _______, _______, _______, _______, \
       SFTZ,    KC_X,    KC_C,    KC_V,    KC_B,                   _______, _______, _______, _______,   MEDIA, \
                                         GM5ENT,  GM4SPC, _______, _______                                      \
// clang-format on

// Control group layer 1.
// clang-format off
#define CONTROL_GROUP_1_3x10_4                                                                                  \
    S(KC_4), S(KC_3), S(KC_2), S(KC_1), KC_BSPC,                   _______, _______, _______, _______, _______, \
       KC_4,    KC_3,    KC_2,    KC_1,    KC_9,                   _______, _______, _______, _______, _______, \
    C(KC_4), C(KC_3), C(KC_2), C(KC_1), KC_LCTL,                   _______, _______, _______, _______, _______, \
                                         KC_TAB, _______, _______, _______                                      \
// clang-format on

// Control group layer 2.
// clang-format off
#define CONTROL_GROUP_2_3x10_4                                                                                  \
    S(KC_8), S(KC_7), S(KC_6), S(KC_5),  KC_DEL,                   _______, _______, _______, _______, _______, \
       KC_8,    KC_7,    KC_6,    KC_5,    KC_0,                   _______, _______, _______, _______, _______, \
    C(KC_8), C(KC_7), C(KC_6), C(KC_5),  KC_ESC,                   _______, _______, _______, _______, _______, \
                                        _______, _______, _______, _______                                      \
// clang-format on

/*
// Camera group layer 1.
// clang-format off
#define CAMERA_GROUP_1_3x10_4                                                                                   \
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, \
      KC_F4,   KC_F3,   KC_F2,   KC_F1, _______,                   _______, _______, _______, _______, _______, \
   C(KC_F4),C(KC_F3),C(KC_F2),C(KC_F1), _______,                   _______, _______, _______, _______, _______, \
                                        _______, _______, _______, _______                                      \
// clang-format on

// Camera group layer 2.
// clang-format off
#define CAMERA_GROUP_2_3x10_4                                                                                   \
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, \
      KC_F8,   KC_F7,   KC_F6,   KC_F5, _______,                   _______, _______, _______, _______, _______, \
   C(KC_F8),C(KC_F7),C(KC_F6),C(KC_F5), _______,                   _______, _______, _______, _______, _______, \
                                        _______, _______, _______, _______                                      \
// clang-format on
*/

// Other Layouts-------------------------------------------------------------------------------------------------------------------------------------

// 41 key mods layer (Reviung41).
// clang-format off
#define MODS41_3x12_5                                                                                                  \
      KC_ESC, KC_Q, _______, _______, _______, _______,          _______, _______, _______, _______, _______, KC_BSPC, \
      KC_TAB, KC_A, _______, _______, _______, _______,          _______, _______, _______, _______, _______,  KC_ENT, \
     KC_LSFT, KC_Z, _______, _______, _______, _______,          _______, _______, _______, _______, KC_SLSH, KC_LSFT, \
                                      KC_LALT, _______, _______, _______, KC_LGUI                                      \
// clang-format on

// 42 key mods layer (Corne, etc.).
// clang-format off
#define MODS42_3x12_6                                                                                                           \
      KC_ESC, KC_Q, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, KC_BSPC, \
      KC_TAB, KC_A, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,  KC_ENT, \
     KC_LSFT, KC_Z, _______, _______, _______, _______,                   _______, _______, _______, _______, KC_SLSH, KC_LSFT, \
                                      KC_LALT, _______, _______, _______, _______, KC_LGUI                                      \
// clang-format on

// 48 key mods layer (Planck, etc.).
// clang-format off
#define MODS48_4x12                                                                                             \
      KC_ESC,   KC_Q, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, \
      KC_TAB,   KC_A, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_ENT, \
     KC_LSFT,   KC_Z, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, KC_LSFT, \
     KC_HOME, KC_END, KC_LGUI, KC_LALT, _______, _______, _______, _______, KC_LGUI, KC_LCTL, KC_PGUP, KC_PGDN  \
// clang-format on

// 50 key mods layer (Rebound).
// clang-format off
#define MODS50_4x12_2                                                                                                    \
      KC_ESC,   KC_Q, _______, _______, _______, _______,          _______, _______, _______, _______, _______, KC_BSPC, \
      KC_TAB,   KC_A, _______, _______, _______, _______,          _______, _______, _______, _______, _______,  KC_ENT, \
     KC_LSFT,   KC_Z, _______, _______, _______, _______,   KC_NO, _______, _______, _______, _______, KC_SLSH, KC_LSFT, \
     KC_HOME, KC_END, KC_LGUI, KC_LALT, _______, _______,   KC_NO, _______, _______, KC_LGUI, KC_LCTL, KC_PGUP, KC_PGDN  \
// clang-format on

// 58 key mods layer (Lily58).
// clang-format off
#define MODS58_4x12_10                                                                                                              \
     KC_TILD,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
      KC_ESC,   KC_Q, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, KC_BSPC, \
      KC_TAB,   KC_A, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,  KC_ENT, \
     KC_LSFT,   KC_Z, _______, _______, _______, _______, MEDIA, TO(_GMLAY0), _______, _______, _______, _______, KC_SLSH, KC_LSFT, \
                      KC_LGUI, KC_LALT, _______, _______,                     _______, _______, KC_LGUI, KC_LCTL                    \

// 58 key gaming layer (Lily58).
// clang-format off
#define GAME58_4x12_10                                                                                                               \
     KC_TILD,   KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
      KC_ESC,   KC_Q, _______, _______, _______,  _______,                     _______, _______, _______, _______, _______, KC_BSPC, \
      KC_TAB,   KC_A, _______, _______, _______,  _______,                     _______, _______, _______, _______, _______,  KC_ENT, \
     KC_LSFT,   KC_Z, _______, _______, _______,  _______, MEDIA, TO(_ALPHAS), _______, _______, _______, _______, KC_SLSH, KC_LSFT, \
                      ___x___, KC_LALT, KC_LCTL, KC_SPACE,                    KC_SPACE, _______, KC_LGUI, KC_LCTL                    \

// 60 key mods layer (Preonic, etc.).
// clang-format off
#define MODS60_4x12                                                                                             \
     KC_TILD,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
      KC_ESC,   KC_Q, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSPC, \
      KC_TAB,   KC_A, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_ENT, \
     KC_LSFT,   KC_Z, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, KC_LSFT, \
     KC_HOME, KC_END, KC_LGUI, KC_LALT, _______, _______, _______, _______, KC_LGUI, KC_LCTL, KC_PGUP, KC_PGDN  \
// clang-format on

/*---------------------------------------------------------------------------------------------------------------------------------------------------
Pointing device misc config==========================================================================================================================
---------------------------------------------------------------------------------------------------------------------------------------------------*/


#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    void pointing_device_init_user(void) {
        set_auto_mouse_enable(true);
    };
#endif

#ifdef NAVNUMSCROLLING
bool set_scrolling = false;

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = -mouse_report.y;
        mouse_report.x = mouse_report.y = 0;
    } else {
        mouse_report.x = mouse_report.x;
        mouse_report.y = mouse_report.y;
    }

    return mouse_report;
};
#endif

/*---------------------------------------------------------------------------------------------------------------------------------------------------
Timer function======================================================================================================================================
---------------------------------------------------------------------------------------------------------------------------------------------------*/

static uint32_t key_timer = 0;
static bool ktimer_on = false;
int KTSTRT_hours_int = 0;
int KTSTRT_minutes_int = 0;
int KTSTRT_seconds_int = 0;
char KTSTRT_hours_char[5];
char KTSTRT_minutes_char[5];
char KTSTRT_seconds_char[5];

void matrix_scan_user(void) {
    if (timer_elapsed32(key_timer) > 1000) {
        key_timer = timer_read32();

        if (ktimer_on) {
            tap_code16(KC_BTN1);

            if (KTSTRT_seconds_int>0){
                KTSTRT_seconds_int--;
            } else if (KTSTRT_minutes_int>0){
                KTSTRT_seconds_int=60;
                KTSTRT_minutes_int--;
            } else if (KTSTRT_hours_int>0){
                KTSTRT_minutes_int=60;
                KTSTRT_hours_int--;
            } else if (KTSTRT_seconds_int <= 0 && KTSTRT_minutes_int <= 0 && KTSTRT_hours_int <= 0 ){
                ktimer_on=false;
                layer_off(_KTIMER);

                return;
            }


        }
    }
};

void print_timer(void) {
    itoa(KTSTRT_hours_int, KTSTRT_hours_char, 10);
    itoa(KTSTRT_minutes_int, KTSTRT_minutes_char, 10);
    itoa(KTSTRT_seconds_int, KTSTRT_seconds_char, 10);

//    tap_code16(LCTL(KC_A));
//    tap_code(KC_BSPC);

//    SEND_STRING("Time Remaining: ");
//    SEND_STRING("\n");

    if(KTSTRT_hours_int <= 9){
        SEND_STRING("0");
    }

    send_string(KTSTRT_hours_char);
    SEND_STRING(":");

    if(KTSTRT_minutes_int <= 9){
        SEND_STRING("0");
    }

    send_string(KTSTRT_minutes_char);
    SEND_STRING(":");

    if(KTSTRT_seconds_int <= 9){
        SEND_STRING("0");
    }

    send_string(KTSTRT_seconds_char);
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------
Custom keycode behaviors=============================================================================================================================
---------------------------------------------------------------------------------------------------------------------------------------------------*/

bool process_record_user(uint16_t keycode, keyrecord_t *record){
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }

    switch (keycode){
        #ifdef NAVNUMSCROLLING
            case FN1ENT:
            case FN2SPC:
            case FN0ENT:
            case FN0SPC:
                if(record->event.pressed){
                    set_scrolling = true;
                    pointing_device_set_cpi(100);
                } else {
                    set_scrolling = false;
                    pointing_device_set_cpi(charybdis_get_pointer_default_dpi());
                }

                return false;
        #endif //NAVNUM SCROLLING

        case CTLDEL:
            if(record->event.pressed){
                tap_code16(C(KC_DEL));
            }

            return false;

        case KTTOGG:
            if (record->event.pressed) {
                ktimer_on = false;

                if(KTSTRT_seconds_int <= 0 && KTSTRT_minutes_int <= 0 && KTSTRT_hours_int <= 0 ){
                    KTSTRT_hours_int = 4;
                }

                layer_invert(_KTIMER);
            }

            return false;

        case KTSTRT:
            if (record->event.pressed) {
                ktimer_on = !ktimer_on;
            }

            return false;

        case KTPLUS:
            if (record->event.pressed) {
                if (KTSTRT_hours_int > 0 || KTSTRT_minutes_int >= 50){
                    KTSTRT_hours_int++;
                } else {
                    KTSTRT_minutes_int=KTSTRT_minutes_int+10;
                }
            }

            return false;

        case KTMINS:
            if (record->event.pressed) {
                if (KTSTRT_hours_int > 0){
                    if (KTSTRT_hours_int == 1){
                        KTSTRT_minutes_int = 50;
                    }

                    KTSTRT_hours_int--;
                } else if (KTSTRT_minutes_int >= 10) {
                    KTSTRT_minutes_int=KTSTRT_minutes_int-10;
                } else {
                    ktimer_on=false;
                    layer_off(_KTIMER);
                }
            }

            return false;

        case KTPRNT:
            if (record->event.pressed) {
                print_timer();
            }

            return false;

        case SLLINE:
            if (record->event.pressed) {
                tap_code(KC_HOME);
                tap_code16(LSFT(KC_END));
            }

            return false;

        case DLLINE:
            if (record->event.pressed) {
                tap_code(KC_HOME);
                tap_code16(LSFT(KC_END));
                tap_code(KC_BSPC);
            }

            return false;

        case CTLINE:
            if (record->event.pressed) {
                tap_code(KC_HOME);
                tap_code16(LSFT(KC_END));
                tap_code16(LCTL(KC_X));
            }

            return false;

        case SLWORD:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_LEFT));
                tap_code16(LSFT(LCTL(KC_RIGHT)));
            }

            return false;

        case GCHATE:
            if (record->event.pressed) {
                tap_code(KC_ENT);
                layer_invert(_GMLAY2);
            }

            return false;

/*        case PRKMAP:
            if (record->event.pressed) {
                send_string(keymap_string);
            }

            return false;*/

        #ifdef CREDS
            case PBPASS:
                if (record->event.pressed) {
                    send_string(pass_string);
                }

                return false;

            case PPEMAI:
                if (record->event.pressed) {
                    send_string(personal_email);
                }

                return false;

            case PWEMAI:
                if (record->event.pressed) {
                    send_string(work_email);
                }

                return false;

            case PPPHON:
                if (record->event.pressed) {
                    send_string(personal_phone);
                }

                return false;

            case PWPHON:
                if (record->event.pressed) {
                    send_string(work_phone);
                }

                return false;

            case PADDRE:
                if (record->event.pressed) {
                    send_string(address);
                }

                return false;

            case PFNAME:
                if (record->event.pressed) {
                    send_string(full_name);
                }

                return false;
        #endif //CREDS
    }

    return true;
};

/*---------------------------------------------------------------------------------------------------------------------------------------------------
Custom tapping terms=================================================================================================================================
---------------------------------------------------------------------------------------------------------------------------------------------------*/

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFTZ:
        case SFTSLSH:
        case CTL_DEL:
            return 125;
        default:
            return TAPPING_TERM;
    }
};

/*
Copyright 2023 Forrest Cahoon <forrest.cahoon@gmail.com>

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

#include QMK_KEYBOARD_H
#include "tweedle.h"

enum layer {
    _QWERTY,
    _PG, // for "programming"
};

enum custom_keycodes {
    PG_AMP = SAFE_RANGE,
    PG_ARRO,
    PG_STAR,
    PG_ENDC,
    PG_EQEQ,
    PG_EQL,
    PG_LBRK,
    PG_LPAR,
    PG_MINS,
    PG_NEEQ,
    PG_RBRK,
    PG_RPAR,
    PG_SLAS,
    PG_VBAR,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [_QWERTY] = LAYOUT(
//     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐                   ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_BSPC,
//     ├────────┴────────┼────────┼────────┼────────┼────────┼────────┤                   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  KC_BSLS,
//     ├─────────────────┼────────┼────────┼────────┼────────┼────────┤                   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        KC_CAPS,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
//     ├─────────────────┼────────┼────────┼────────┼────────┼────────┼────────┐ ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,   KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
//     └─────────────────┴────────┴────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┴────────┴─────────────────┘
                                            KC_LCTL, KC_SPC,  MO(1),   KC_LALT,   KC_RALT, MO(1),   KC_SPC,  KC_RCTL
//                                         └────────┴────────┴────────┴────────┤ ├────────┴────────┴────────┴────────┘
        ),


    [_PG] = LAYOUT(
//     ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐                   ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, KC_F1  , KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
//     ├────────┴────────┼────────┼────────┼────────┼────────┼────────┤                   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______,          _______, PG_SLAS, PG_LPAR, PG_RPAR, PG_NEEQ,                     _______, KC_HOME, KC_UP,   KC_PGUP, KC_INS,  KC_LBRC, KC_RBRC,
//     ├─────────────────┼────────┼────────┼────────┼────────┼────────┤                   ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        _______,          PG_ENDC, PG_VBAR, PG_LBRK, PG_RBRK, PG_EQEQ,                     _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_BSPC,
//     ├─────────────────┼────────┼────────┼────────┼────────┼────────┼────────┐ ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┴────────┤
        _______,          _______, PG_MINS, PG_EQL,  PG_STAR, PG_ARRO, _______,   _______, _______, KC_END,  KC_DOWN, KC_PGDN, KC_DEL,  _______,
//     └─────────────────┴────────┴────────┼────────┼────────┼────────┼────────┤ ├────────┼────────┼────────┼────────┼────────┴────────┴─────────────────┘
                                            _______, _______, _______, _______,   _______, _______, _______, _______
//                                         └────────┴────────┴────────┴────────┤ ├────────┴────────┴────────┴────────┘
        )
};
// clang-format on

const key_override_t pg_lbrk_none  = ko_make_with_layers_and_negmods(0, PG_LBRK, KC_LEFT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_lbrk_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_LBRK, KC_LEFT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_lpar_none  = ko_make_with_layers_and_negmods(0, PG_LPAR, KC_LEFT_PAREN, ~0, ~0);
const key_override_t pg_lpar_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_LPAR, KC_LEFT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rbrk_none  = ko_make_with_layers_and_negmods(0, PG_RBRK, KC_RIGHT_CURLY_BRACE, ~0, ~0);
const key_override_t pg_rbrk_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_RBRK, KC_RIGHT_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_rpar_none  = ko_make_with_layers_and_negmods(0, PG_RPAR, KC_RIGHT_PAREN, ~0, ~0);
const key_override_t pg_rpar_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_RPAR, KC_RIGHT_ANGLE_BRACKET, ~0, ~MOD_MASK_SHIFT);

const key_override_t pg_slas_none  = ko_make_with_layers_and_negmods(0, PG_SLAS, KC_SLASH, ~0, ~0);
const key_override_t pg_slas_shift = ko_make_with_layers_and_negmods(MOD_MASK_SHIFT, PG_SLAS, KC_BACKSLASH, ~0, ~MOD_MASK_SHIFT);

// clang-format off
const key_override_t **key_overrides = (const key_override_t *[]){
    &pg_lbrk_none, &pg_lbrk_shift,
    &pg_lpar_none, &pg_lpar_shift,
    &pg_rbrk_none, &pg_rbrk_shift,
    &pg_rpar_none, &pg_rpar_shift,
    &pg_slas_none, &pg_slas_shift,
    NULL};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    uint8_t std_mods     = get_mods();
    uint8_t oneshot_mods = get_oneshot_mods();
    uint8_t all_mods     = std_mods | oneshot_mods;
    bool    shift_on     = all_mods & MOD_MASK_SHIFT;
    bool    ctrl_on      = all_mods & MOD_MASK_CTRL;

    // None of our special keycodes use ALT or GUI mods (so far), so we
    // check once here at the top and let other code handle it if any of
    // these are set.
    if (all_mods & (MOD_MASK_ALT | MOD_MASK_GUI)) return true;

    switch (keycode) {
        case PG_AMP:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("&") : SEND_STRING("&&");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_ARRO:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("->") : SEND_STRING("=>");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_ENDC:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                SEND_STRING(SS_TAP(X_END));
                if (!shift_on) SEND_STRING(";");
                if (!ctrl_on) SEND_STRING(SS_TAP(X_ENTER));
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_EQEQ:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("==") : SEND_STRING("===");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_EQL:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("+") : SEND_STRING("=");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_MINS:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("_") : SEND_STRING("-");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_NEEQ:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("!=") : SEND_STRING("!==");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_STAR:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("?") : SEND_STRING("*");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
        case PG_VBAR:
            if (record->event.pressed) {
                clear_mods();
                clear_oneshot_mods();
                if (!ctrl_on) SEND_STRING(" ");
                shift_on ? SEND_STRING("|") : SEND_STRING("||");
                if (!ctrl_on) SEND_STRING(" ");
                set_mods(std_mods);
                set_oneshot_mods(oneshot_mods);
                return false;
            }
            break;
    }
    return true;
}

// I have only one encoder on my Tweedle, so there's no detection of which encoder is used here.
// When _PG mode is on, the encoder switches Windows desktops. Otherwise, it acts as a scroll wheel.
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_PG)) {
        if (!clockwise) {
            tap_code16(LCTL(LGUI(KC_RIGHT)));
        } else {
            tap_code16(LCTL(LGUI(KC_LEFT)));
        }

    } else {
        if (!clockwise) {
            tap_code(KC_MS_WH_DOWN);
        } else {
            tap_code(KC_MS_WH_UP);
        }
    }
    return false;
}

/* Copyright 2020 MudkipMao
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
#include "nazu.h"
#include "keymap_colemak.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wk(
             KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_DEL, //16
            KC_PGUP,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,         //15
           KC_PGDN,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,          //14
                      TD_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,           //14
                      KC_LCTL, KC_LGUI, LALT_F4,     KC_SPC,       MO(_FN1),                     KC_SPC,           KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT //11
    ),
    [_MACOS] = LAYOUT_wk(
             KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_DEL,
            KC_PGUP,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
           KC_PGDN,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
                      TD_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
                      KC_LCTL, KC_LALT, KC_LGUI,     KC_SPC,       MO(_FN1),                     KC_SPC,           KC_RGUI, KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN1] = LAYOUT_wk(
             QK_BOOT, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           XXXXXXX, XXXXXXX,
            KC_QWTY,  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           KC_MAC,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
                      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_VOLU,
                      _______, _______, _______,     KC_MPLY,      MO(_FN1),                     KC_MUTE,          _______, _______,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN2] = LAYOUT_wk(
             _______, _______, _______, _______, _______, KC_F4,   _______, _______,    _______, _______, _______, _______, _______, _______,          _______, _______,
            _______,  _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______,
           _______,   _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,          _______,
                      _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
                      _______, _______, _______,     _______,      MO(_FN1),                     KC_MUTE,          _______, _______,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
};

/* Copyright 2023 Tom Sennewald (@beelzebubi)
 * SPDX-License-Identifier: GPL-2.0-or-later
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

#include "nazu.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wk_bs(
             KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_DEL,
            KC_PGUP,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
           KC_PGDN,   KC_HYPR, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
                      TD_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
                      KC_LCTL, KC_LGUI, KC_LALT,     KC_SPACE,     MO(_FN1),                     KC_SPACE,         KC_R2,   KC_R1,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_COLEMAK] = LAYOUT_wk_bs(
             KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_DEL,
            KC_PGUP,  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
           KC_PGDN,   KC_HYPR, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,                   KC_ENT,
                      TD_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
                      KC_LCTL, KC_LGUI, KC_LALT,     KC_SPACE,     MO(_FN1),                     KC_SPACE,         KC_R2,   KC_R1,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_COLEMAK_DH] = LAYOUT_wk_bs(
             KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_DEL,
            KC_PGUP,  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
           KC_PGDN,   KC_HYPR, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,                   KC_ENT,
                      TD_CAPS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
                      KC_LCTL, KC_LGUI, KC_LALT,     KC_SPACE,     MO(_FN1),                     KC_SPACE,         KC_R2,   KC_R1,            KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN1] = LAYOUT_wk_bs(
             QK_BOOT, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           XXXXXXX, XXXXXXX,
            KC_SWAP,  _______, QWERTY,  COLEMAK, CLMKDH,  XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           KC_NORM,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
                      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_VOLU,
                      _______, _______, _______,     KC_MPLY,      XXXXXXX,                      KC_MUTE,          _______, _______,          KC_MPRV, KC_VOLD, KC_MNXT
    ),
};


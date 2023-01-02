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
// #include "nazu.h"
#include "quantum.h"
#include "version.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY = 0,    // QWERTY layout for WIN or UNIX
    _COLEMAK_DH,    // Colemak DHS layout
    _MACOS,         // QWERTY layout for MacOS
    _FN1,           //
    _FN2,           //
    _MEDIA,         //
    _LOWER,         //
    _RAISE,         //
    _ADJUST,        //
};
enum userspace_custom_keycodes {
    KC_QWERTY = SAFE_RANGE,   // change to QWERTY layer
    KC_COLEMAK_DH,                // change to COLEMAK layer
    KC_MAC,                 // change to MACOS layer
    KC_EMOM,                // shortcut for emoji picker in MACOS
    KC_EMOW,                // shortcut for emoji picker in WINDOWS
    LALT_F4,                // shortcut for LALT+F4
    KC_CAD,
    KC_SWAP,                // SWAP to MACOS mods
    KC_NORM,                // UNSWAP MACOS mods
};


#ifdef TAP_DANCE_ENABLE
enum tap_dance {
    TD_WIN,
    TD_ESC,
    TD_RCTL,
    TD_LSFT_CAPS,
};
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};
#   define TD_TESC TD(TD_ESC)
#   define TD_TWIN TD(TD_WIN)
#   define TD_TCTL TD(TD_RCTL)
#   define TD_CAPS TD(TD_LSFT_CAPS)
#else // TAP_DANCE_ENABLE
#   define TD_TESC KC_ESC
#   define TD_TWIN KC_LGUI
#   define TD_TCTL KC_LCTL
#   define TD_CAPS KC_LSFT
#endif // TAP_DANCE_ENABLE

#define LALT_F4 LM(_FN2, MOD_LALT)
#define QWERTY KC_QWERTY
#define DVORAK KC_DVORAK
// #define COLEMAK KC_COLEMAK
#define CLMKDH KC_COLEMAK_DH
#define MACOS KC_MAC
#define EN_MAC KC_SWAP
#define DS_MAC KC_NORM

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_wk(
             KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_DEL,
            KC_PGUP,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
           KC_PGDN,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
                      TD_CAPS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
                      KC_LCTL, KC_LGUI, LALT_F4,     KC_SPC,       MO(_FN1),                     KC_SPC,           KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_COLEMAK_DH] = LAYOUT_wk(
             KC_ESC,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,      KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_DEL,
            KC_PGUP,  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
           KC_PGDN,   KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,                   KC_ENT,
                      TD_CAPS, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
                      KC_LCTL, KC_LGUI, LALT_F4,     KC_SPC,       MO(_FN1),                     KC_SPC,           KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT
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
            KC_HOME,  _______, QWERTY,  CLMKDH,  MACOS,   XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
           KC_END,    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
                      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_VOLU,
                      _______, _______, _______,     KC_MPLY,      XXXXXXX,                      KC_MUTE,          _______, _______,          KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [_FN2] = LAYOUT_wk(
             _______, _______, _______, _______, _______, KC_F4,   _______, _______,    _______, _______, _______, _______, _______, _______,          _______, _______,
            _______,  _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______,
           _______,   _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______,          _______,
                      _______, _______, _______, _______, _______, _______,             _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______,     _______,      _______,                      _______,          _______, _______,          _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        // case KC_COLEMAK:
        //     if (record->event.pressed) {
        //         set_single_persistent_default_layer(_COLEMAK);
        //     }
        //     return false;
        case KC_COLEMAK_DH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK_DH);
            }
            return false;
        case KC_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MACOS);
            }
            return false;
        // case KC_SWAP:
        //     if (record->event.pressed) {
        //         // register_code(RCG_SWP);
        //         // register_code(RAG_SWP);
        //         register_code(LAG_SWP);
        //     } else {
        //         // unregister_code(RCG_SWP);
        //         // unregister_code(RAG_SWP);
        //         unregister_code(LAG_SWP);
        //     }
        //     return false;
        // case KC_NORM:
        //     if (record->event.pressed) {
        //         // register_code(RCG_NRM);
        //         // register_code(RAG_NRM);
        //         register_code(LAG_NRM);
        //     } else {
        //         // unregister_code(RCG_NRM);
        //         // unregister_code(RAG_NRM);
        //         unregister_code(LAG_NRM);
        //     }
        //     return false;
        // case KC_EMOM:
        //     if (record->event.pressed) {
        //         register_mods(mod_config(MOD_LCTL));
        //         register_mods(mod_config(MOD_LALT));
        //         register_code(KC_SPACE);
        //     } else {
        //         unregister_mods(mod_config(MOD_LCTL));
        //         unregister_mods(mod_config(MOD_LALT));
        //         unregister_code(KC_SPACE);
        //     }
        //     return false;
        // case KC_EMOW:
        //     if (record->event.pressed) {
        //         register_mods(mod_config(MOD_LGUI));
        //         register_code(KC_DOT);
        //     } else {
        //         unregister_mods(mod_config(MOD_LGUI));
        //         unregister_code(KC_DOT);
        //     }
        //     return false;
    }
    return true;
}

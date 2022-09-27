/*
Copyright 2020 Álvaro "Gondolindrim" Volpato <alvaro.volpato@usp.br>

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
#include "keymap_german.h"
#include "keymap_colemak.h"

enum layers {
  _QWERTZ,
  _COLEMAK,
  _MACOS,
  _FN1,
  _FN2,
};

enum custom_keycodes {
    KC_QWTZ = SAFE_RANGE,     // change to QWERTZ layer
    KC_CLMK,                 // change to COLEMAK layer
    KC_MAC,                 // change to MACOS layer
    KC_EMOM,                // shortcut for emoji picker in MACOS
    KC_EMOW,                // shortcut for emoji picker in WINDOWS
    LALT_F4,                // shortcut for LALT+F4
};

enum {
    TD_LSFT_CAPS,
};

#define TD_CAPS TD(TD_LSFT_CAPS)
#define KC_EMOM LCTL(LALT(KC_SPACE))
#define KC_EMOW LGUI(KC_DOT)
#define LALT_F4 LM(_FN2, MOD_LALT)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * QWERTZ
   * ,-----------------------------------------------------------------------------------------------,
   * |  ^  | 1 ! | 2 @ | 3 # | 4 $ | 5 % | 6 ^ | 7 & | 8 * | 9 ( | 0 ) | - _ | = + | Backspace | Del |
   * |-----------------------------------------------------------------------------------------------|
   * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Z  |  U  |  I  |  O  |  P  |  Ü  | + * |   \ |  |PgUp |
   * |-----------------------------------------------------------------------------------------|-----|
   * |   Caps  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Ö  |  Ä  |    Enter    |PgDwn|
   * |-----------------------------------------------------------------------------------------------|
   * | Shift | < > |  Y  |  X  |  C  |  V  |  B  |  N  |  M  | , ; | . : | - _ |  Shift  | Up  | End |
   * |-----------------------------------------------------------------------------------------------|
   * | LCtl  | LGUI  | LAlt  |            Space                  |RAlt | FN1 |RCtl |Left |Down |Right|
   * `-----------------------------------------------------------------------------------------------´
   */
	[_QWERTZ] = LAYOUT_all(
    KC_ESC,   DE_1,     DE_2,     DE_3,     DE_4,     DE_5,     DE_6,     DE_7,     DE_8,     DE_9,     DE_0,     DE_SS,    DE_ACUT,            KC_BSPC,  KC_DEL,
    KC_TAB,   DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     DE_Z,     DE_U,     DE_I,     DE_O,     DE_P,     DE_UDIA,  DE_PLUS,  KC_BSLS,            KC_PGUP,
    KC_CAPS,  DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     DE_ODIA,  DE_ADIA,            KC_ENT,             KC_PGDN,
    KC_LSFT,            DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     DE_COMM,  DE_DOT,   DE_MINS,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  LALT_F4,                                KC_SPC,                                 KC_RALT,  MO(_FN1),           KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

  /*
   * Colemak
   * ,-----------------------------------------------------------------------------------------------,
   * |  `  | 1 ! | 2 @ | 3 # | 4 $ | 5 % | 6 ^ | 7 & | 8 * | 9 ( | 0 ) | - _ | = + | Backspace | Del |
   * |-----------------------------------------------------------------------------------------------|
   * |  Tab   |  Q  |  W  |  F  |  P  |  B  |  J  |  L  |  U  |  Y  | ; : | [ { | ] } |   \ |  |PgUp |
   * |-----------------------------------------------------------------------------------------|-----|
   * |Backspace|  A  |  R  |  S  |  T  |  G  |  M  |  N  |  E  |  I  |  O  | ' " |    Enter    |PgDwn|
   * |-----------------------------------------------------------------------------------------------|
   * |    Shift    |  Z  |  X  |  C  |  D  |  V  |  K  |  H  | , < | . > | / ? |  Shift  | Up  | End |
   * |-----------------------------------------------------------------------------------------------|
   * | LCtl  | LGUI  | LAlt  |            Space                  |RAlt | FN1 |RCtl |Left |Down |Right|
   * `-----------------------------------------------------------------------------------------------´
   */
	[_COLEMAK] = LAYOUT_all(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,             KC_BSPC,  KC_DEL,
    KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    KC_BSPC,  KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_M,     KC_N,     KC_E,     KC_I,     KC_O,     KC_QUOT,            KC_ENT,             KC_PGDN,
    TD_CAPS,            KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,     KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  LALT_F4,                                KC_SPC,                                 KC_RALT,  MO(_FN1),           KC_LEFT,  KC_DOWN,  KC_RGHT
),

  /*
   * MACOS
   * ,-----------------------------------------------------------------------------------------------,
   * |  ^  | 1 ! | 2 @ | 3 # | 4 $ | 5 % | 6 ^ | 7 & | 8 * | 9 ( | 0 ) | - _ | = + | Backspace | Del |
   * |-----------------------------------------------------------------------------------------------|
   * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Z  |  U  |  I  |  O  |  P  |  Ü  | + * |   \ |  |PgUp |
   * |-----------------------------------------------------------------------------------------|-----|
   * |   Caps  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Ö  |  Ä  |    Enter    |PgDwn|
   * |-----------------------------------------------------------------------------------------------|
   * |    Shift    |  Y  |  X  |  C  |  V  |  B  |  N  |  M  | , ; | . : | - _ |  Shift  | Up  | End |
   * |-----------------------------------------------------------------------------------------------|
   * | LCtl  | LAlt  | LGUI  |            Space                  |RGUI |RAlt | FN1 |Left |Down |Right|
   * `-----------------------------------------------------------------------------------------------´
   */
	[_MACOS] = LAYOUT_all(
    KC_ESC,   DE_1,     DE_2,     DE_3,     DE_4,     DE_5,     DE_6,     DE_7,     DE_8,     DE_9,     DE_0,     DE_SS,    DE_ACUT,            KC_BSPC,  KC_DEL,
    KC_TAB,   DE_Q,     DE_W,     DE_E,     DE_R,     DE_T,     DE_Z,     DE_U,     DE_I,     DE_O,     DE_P,     DE_UDIA,  DE_PLUS,  KC_BSLS,            KC_PGUP,
    KC_CAPS,  DE_A,     DE_S,     DE_D,     DE_F,     DE_G,     DE_H,     DE_J,     DE_K,     DE_L,     DE_ODIA,  DE_ADIA,            KC_ENT,             KC_PGDN,
    KC_LSFT,            DE_Y,     DE_X,     DE_C,     DE_V,     DE_B,     DE_N,     DE_M,     DE_COMM,  DE_DOT,   DE_MINS,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RALT,  MO(_FN1),           KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

	[_FN1] = LAYOUT_all(
    KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,             RESET,    KC_MUTE,
    _______,  KC_QWTZ,  KC_CLMK,  KC_MAC,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
    _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            KC_VOLU,  XXXXXXX,
    _______,  _______,  _______,                                KC_MPLY,                                _______,  XXXXXXX,            KC_MPRV,  KC_VOLD,  KC_MNXT
  ),

	[_FN2] = LAYOUT_all(
    _______,  _______,  _______,  _______,  KC_F4,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,            _______,  _______,  _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWTZ:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTZ);
            }
            return false;
        case KC_CLMK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MACOS);
            }
            return false;
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

/* Tap Dance definitions */
#ifdef TAP_DANCE_ENABLE

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

#endif

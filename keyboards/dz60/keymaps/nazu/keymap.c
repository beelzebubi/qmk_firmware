
#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keymap_colemak.h"

enum layers {
  _QWERTZ,
  _COLEMAK,
  _FN1,
  _FN2,
};

enum custom_keycodes {
    KC_QWTZ = SAFE_RANGE,     // change to QWERTZ layer
    KC_CLMK,                 // change to COLEMAK layer
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* ISO 60
   *
   * ,-----------------------------------------------------------------------------------------.
   * | Esc | 1 ! | 2 " | 3 § | 4 $ | 5 % | 6 & | 7 / | 8 ( | 9 ) | 0 = | ß ? | ´ ` | Backspace |
   * |-----------------------------------------------------------------------------------------|
   * | Tab    |  Q  |  W  |  E  |  R  |  T  |  Z  |  U  |  I  |  O  |  P  |  Ä  | + * | Enter  |
   * |----------------------------------------------------------------------------------       |
   * |   Caps  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  Ö  |  Ü  | # ' |       |
   * |-----------------------------------------------------------------------------------------|
   * | Shift | < > |  Y  |  X  |  C  |  V  |  B  |  N  |  M  | , ; | . : | - _ | Shift   | FN2 |
   * |-----------------------------------------------------------------------------------------|
   * | LCtl  | LGUI  | LAlt  |            Space                  | RAlt  |  FN1  | App  | RCtl |
   * `-----------------------------------------------------------------------------------------'
   */

  [_QWERTZ] = LAYOUT_60_iso_bs_rshift(
    KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,    DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,   DE_ACUT, KC_BSPC,
    KC_TAB,  DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,    DE_Z,    DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA, DE_PLUS,
    KC_CAPS, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,    DE_H,    DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA, DE_HASH, KC_ENT,
    KC_LSFT, DE_LABK, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    DE_N,    DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT, MO(_FN2),
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FN1),KC_APP,  KC_LCTL
  ),


  /*
   * Colemak
   * ,-----------------------------------------------------------------------------------------.
   * | Esc | 1 ! | 2 @ | 3 # | 4 $ | 5 % | 6 ^ | 7 & | 8 * | 9 ( | 0 ) | - _ | = + | Backspace |
   * |-----------------------------------------------------------------------------------------|
   * | Tab    |  Q  |  W  |  F  |  P  |  B  |  J  |  L  |  U  |  Y  | ; : | [ { | ] } | Enter  |
   * |----------------------------------------------------------------------------------       |
   * |Backspace|  A  |  R  |  S  |  T  |  G  |  M  |  N  |  E  |  I  |  O  | ' " |  #  |       |
   * |-----------------------------------------------------------------------------------------|
   * | Shift |  Z  |  X  |  C  |  D  |  V  | \ | |  K  |  H  | , < | . > | / ? | Shift   | FN2 |
   * |-----------------------------------------------------------------------------------------|
   * | LCtl  | LGUI  | LAlt  |            Space                  | RAlt  |  FN1  | App  | RCtl |
   * `-----------------------------------------------------------------------------------------'
   */
  [_COLEMAK] = LAYOUT_60_iso_bs_rshift(
    // KC_ESC,  CM_1,    CM_2,    CM_3,    CM_4,    CM_5,    CM_6,    CM_7,    CM_8,    CM_9,    CM_0,    CM_MINS, CM_EQL,  KC_BSPC,
    // KC_TAB,  CM_Q,    CM_W,    CM_F,    CM_P,    CM_B,    CM_J,    CM_L,    CM_U,    CM_Y,    CM_SCLN, CM_LBRC, CM_RBRC,
    // KC_CAPS, CM_A,    CM_R,    CM_S,    CM_T,    CM_G,    CM_M,    CM_N,    CM_E,    CM_I,    CM_O,    CM_QUOT, CM_HASH, KC_ENT,
    // KC_LSFT, CM_Z,    CM_X,    CM_C,    CM_D,    CM_V,    CM_BSLS, CM_K,    CM_H,    CM_COMM, CM_DOT,  CM_SLSH, KC_RSFT, MO(_FN2),
    // KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FN1),KC_APP,  KC_LCTL
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    CM_MINS, CM_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, CM_LBRC, CM_RBRC,
    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    CM_QUOT, CM_HASH, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    CM_BSLS, KC_K,    KC_H,    CM_COMM, CM_DOT,  CM_SLSH, KC_RSFT, MO(_FN2),
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(_FN1),KC_APP,  KC_LCTL
  ),

  /*
   * FN1
   * ,-----------------------------------------------------------------------------------------.
   * |  ^  | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 |   DEL     |
   * |-----------------------------------------------------------------------------------------|
   * | Tab    |RGBTg|RGBMd|Hue +|Hue -|Sat +|Sat -|Val +|Val -|     |Print|ScLck|Pause| Enter  |
   * |----------------------------------------------------------------------------------       |
   * |  Caps   |     |     |     |     |     |     |     |     |     | Ins |     |     |       |
   * |-----------------------------------------------------------------------------------------|
   * | Shift |     |     |     |BL - |BL TG|BL + |     |     |     |     |     | Shift   | FN2 |
   * |-----------------------------------------------------------------------------------------|
   * | LCtl  | LGUI  | LAlt  |            Space                  | RAlt  |  FN1  | App  | RCtl |
   * `-----------------------------------------------------------------------------------------'
   */
  [_FN1] = LAYOUT_60_iso_bs_rshift(
    DE_CIRC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  BL_TOGG, BL_INC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______,                            _______,                   _______, _______, _______, _______
  ),

  /*
   * FN2
   * ,-----------------------------------------------------------------------------------------.
   * |RESET|QWRTZ|COLMK|     |     |     |     |Prev |Play |Next |Mute |VolDn|VolUp|   DEL     |
   * |-----------------------------------------------------------------------------------------|
   * | Tab    |     |     |     |     |     |     |     |     |     |     |     |     | Enter  |
   * |----------------------------------------------------------------------------------       |
   * |  Caps   |     |     |     |     |     |Left |Down | Up  |Right|     |     |     |       |
   * |-----------------------------------------------------------------------------------------|
   * | Shift |     |     |     |     |     |     |     |     |     |     |     | Shift   |     |
   * |-----------------------------------------------------------------------------------------|
   * | LCtl  | LGUI  | LAlt  |            Space                  | RAlt  | RGUI  | App  | RCtl |
   * `-----------------------------------------------------------------------------------------'
   */
  [_FN2] = LAYOUT_60_iso_bs_rshift(
    RESET,   KC_QWTZ, KC_CLMK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______,                            _______,                   _______, _______, _______, _______
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
    }
    return true;
}

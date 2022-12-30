
#include QMK_KEYBOARD_H
#include "nazu.h"
#include "keymap_german.h"
#include "keymap_colemak.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
   * QWERTZ
   * ,-----------------------------------------------------------------------------------------------,
   * |  ^  | 1 ! | 2 @ | 3 # | 4 $ | 5 % | 6 ^ | 7 & | 8 * | 9 ( | 0 ) | - _ | = + | Backspace | Del |
   * |-----------------------------------------------------------------------------------------------|
   * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \ |  |PgUp |
   * |-----------------------------------------------------------------------------------------|-----|
   * |   Caps  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  | ; : | ' " |    Enter    |PgDwn|
   * |-----------------------------------------------------------------------------------------------|
   * |    Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  | , < | . > | / ? |  Shift  | Up  | End |
   * |-----------------------------------------------------------------------------------------------|
   * | LCtl  | LGUI  | LAlt  |            Space                  |RAlt | FN1 |     |Left |Down |Right|
   * `-----------------------------------------------------------------------------------------------´
   */
	[_QWERTY] = LAYOUT_65_ansi_blocker(
    KC_ESC,   ________________NUMBER_LEFT________________,     ________________NUMBER_RIGHT_______________,  KC_MINS,  KC_EQL,             KC_BSPC,  KC_DEL,   // 15
    KC_TAB,   _________________QWERTY_L1_________________,     _________________QWERTY_R1_________________,  KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,  // 15
    KC_CAPS,  _________________QWERTY_L2_________________,     _________________QWERTY_R2_________________,                      KC_ENT,             KC_PGDN,  // 14
    TD_CAPS,  _________________QWERTY_L3_________________,     _________________QWERTY_R3_________________,  KC_RSFT,            KC_UP,    KC_END,   // 14
    KC_LCTL,  KC_LGUI,  LALT_F4,                                KC_SPC,                                 KC_RALT,  MO(_FN1),           KC_LEFT,  KC_DOWN,  KC_RGHT   // 9
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
   * | LCtl  | LGUI  | LAlt  |            Space                  |RAlt | FN1 |     |Left |Down |Right|
   * `-----------------------------------------------------------------------------------------------´
   */
	[_COLEMAK_DH] = LAYOUT_65_ansi_blocker(
    KC_ESC,   ________________NUMBER_LEFT________________,     ________________NUMBER_RIGHT_______________,  KC_MINS,  KC_EQL,             KC_BSPC,  KC_DEL,
    KC_TAB,   ______________COLEMAK_MOD_DH_L1____________,     ______________COLEMAK_MOD_DH_R1____________,  KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    KC_BSPC,  ______________COLEMAK_MOD_DH_L2____________,     ______________COLEMAK_MOD_DH_R2____________,                      KC_ENT,             KC_PGDN,
    TD_CAPS,  ______________COLEMAK_MOD_DH_L3____________,     ______________COLEMAK_MOD_DH_R3____________,            KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LGUI,  LALT_F4,                                KC_SPC,                                 KC_RALT,  MO(_FN1),      KC_LEFT,  KC_DOWN,  KC_RGHT
),

  /*
   * MACOS
   * ,-----------------------------------------------------------------------------------------------,
   * |  ^  | 1 ! | 2 @ | 3 # | 4 $ | 5 % | 6 ^ | 7 & | 8 * | 9 ( | 0 ) | - _ | = + | Backspace | Del |
   * |-----------------------------------------------------------------------------------------------|
   * |  Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |   \ |  |PgUp |
   * |-----------------------------------------------------------------------------------------|-----|
   * |   Caps  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  | ; : | ' " |    Enter    |PgDwn|
   * |-----------------------------------------------------------------------------------------------|
   * |    Shift    |  Z  |  X  |  C  |  V  |  B  |  N  |  M  | , < | . > | - ? |  Shift  | Up  | End |
   * |-----------------------------------------------------------------------------------------------|
   * | LCtl  | LAlt  | LGUI  |            Space                  |RGUI | FN1 |     |Left |Down |Right|
   * `-----------------------------------------------------------------------------------------------´
   */
	[_MACOS] = LAYOUT_65_ansi_blocker(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,             KC_BSPC,  KC_DEL,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN,
    TD_CAPS,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,    KC_END,
    KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RALT,  MO(_FN1),           KC_LEFT,  KC_DOWN,  KC_RGHT
  ),

	[_FN1] = LAYOUT_65_ansi_blocker(
    KC_GRV,   ________________________FUNC_LEFT________________________,  ________________________FUNC_RIGHT_______________________,            QK_BOOT,  KC_MUTE,
    _______,  QWERTY,   COLEMAKDH,MACOS,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,            XXXXXXX,
    _______,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,            KC_VOLU,  XXXXXXX,
    _______,  _______,  _______,                                KC_MPLY,                                _______,  XXXXXXX,            KC_MPRV,  KC_VOLD,  KC_MNXT
  ),

	[_FN2] = LAYOUT_65_ansi_blocker(
    _______,  _______,  _______,  _______,  KC_F4,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
    _______,  _______,  _______,                                _______,                                _______,  _______,            _______,  _______,  _______
  ),
};

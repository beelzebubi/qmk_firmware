 /* Copyright 2017 F_YUUCHI
  * Copyright 2020 Drashna Jaelre <@drashna>
  * Copyright 2020 Ben Roesner (keycapsss.com)
  * Copyright 2021 HellSingCoder
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
#include "keymap_german.h"
#include "keymap_colemak.h"


extern uint8_t is_master;

enum layers {
    _QWERTZ,
    _COLEMAK,
    _NEO,
    _GAMING,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// clang-format off
enum custom_keycodes {
    KC_QWRZ = SAFE_RANGE,     // change to QWERTZ layer
    KC_CLMK,                 // change to COLEMAK layer
    // KC_NEO,                     // change to NEO layer
    // KC_GAMING,                  // change to GAMING layer
    KC_LOWER,                   // change to LOWER layer
    KC_RAISE,                   // change to RAISE layer
    KC_ADJUST,                  // change to ADJUST layer
    // KC_PRVWD,                   // previous window
    // KC_NXTWD,                   // next window
    // KC_LSTRT,                   // home
    // KC_LEND,                    // end
    // KC_DLINE,                   // delete line
    KC_BSPC_DEL,                //
    KC_LAYER,                   //
};

enum {
    TD_LSFT_CAPS,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define TD_CAPS TD(TD_LSFT_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTZ
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  SS  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |  UE  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  OE  |  AE  |
 * |------+------+------+------+------+------|   #   |    |   +   |------+------+------+------+------+------|
 * |LShift|   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Enter /        \Space \ |RAISE |BackSP| RAlt |
 *                   |      |      |      |/      /          \      \|      |      |      |
 *                   `--------------------'------´            `------'--------------------´
 */

 [_QWERTZ] = LAYOUT(
  KC_ESC,  DE_1,   DE_2,   DE_3,    DE_4,    DE_5,                     DE_6,   DE_7,    DE_8,    DE_9,    DE_0,    DE_SS,
  KC_TAB,  DE_Q,   DE_W,   DE_E,    DE_R,    DE_T,                     DE_Z,   DE_U,    DE_I,    DE_O,    DE_P,    DE_UDIA,
  KC_LCTL, DE_A,   DE_S,   DE_D,    DE_F,    DE_G,                     DE_H,   DE_J,    DE_K,    DE_L,    DE_ODIA, DE_ADIA,
  TD_CAPS, DE_Y,   DE_X,   DE_C,    DE_V,    DE_B,  DE_HASH,  DE_PLUS, DE_N,   DE_M,    DE_COMM, DE_DOT,  DE_MINS, KC_RSFT,
                           KC_LALT, KC_LGUI, LOWER, KC_SPC,   KC_ENT,  RAISE,  KC_BSPC, KC_RALT
),
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTRL|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Enter /        \ Space\ |RAISE |BackSP| RAlt |
 *                   |      |      |      |/      /          \      \|      |      |      |
 *                   `--------------------'------´            `------'--------------------´
 */

[_COLEMAK] = LAYOUT(
  KC_ESC,  CM_1,   CM_2,    CM_3,    CM_4,     CM_5,                    CM_6,    CM_7,    CM_8,    CM_9,    CM_0,    CM_MINS,
  KC_TAB,  KC_Q,   KC_W,    KC_F,    KC_P,     KC_B,                    KC_J,    KC_L,    KC_U,    KC_Y,    CM_SCLN, CM_BSLS,
  KC_LCTL, KC_A,   KC_R,    KC_S,    KC_T,     KC_G,                    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    CM_QUOT,
  TD_CAPS, KC_Z,   KC_X,    KC_C,    KC_D,     KC_V,  CM_LBRC, CM_RBRC, KC_K,    KC_H,    CM_COMM, CM_DOT,  CM_SLSH, KC_RSFT,
                            KC_LALT, KC_LGUI,  LOWER, KC_SPC,  KC_ENT,  RAISE,   KC_BSPC, KC_RALT
),
/*
 * NEO
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   X  |   V  |   L  |   C  |   W  |                    |   K  |   H  |   G  |   F  |   Q  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   U  |   I  |   A  |   E  |   O  |-------.    ,-------|   S  |   N  |   R  |   T  |   D  |  Y   |
 * |------+------+------+------+------+------|  MUTE |    |  -    |------+------+------+------+------+------|
 * |LShift|   [  |   ;  |   '  |   P  |   Z  |-------|    |-------|   B  |   M  |   ,  |   .  |   J  |RShift|
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Enter /        \Space \ |RAISE |BackSP| RGUI |
 *                   |      |      |      |/      /          \      \|      |      |      |
 *                   `--------------------'------´            `------'--------------------´
 *
 *
 *[_NEO] = LAYOUT(
 *  KC_GRV,            KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_EQL,
 *  KC_ESC,            KC_X,   KC_V,    KC_L,    KC_C,    KC_W,                      KC_K,    KC_H,    KC_G,    KC_F,    KC_Q,  KC_BSPC,
 *  KC_TAB,            KC_U,   KC_I,    KC_A,    KC_E,    KC_O,                      KC_S,    KC_N,    KC_R,    KC_T,    KC_D,  KC_QUOT,
 *  TD(TD_LSFT_CAPS),  KC_LBRC,KC_SCLN, KC_QUOT, KC_P,    KC_Z,  KC_MUTE, KC_MINS,   KC_B,    KC_M,    KC_COMM, KC_DOT, KC_SLSH,KC_RSFT,
 *                                      KC_LALT, KC_LGUI, LOWER, KC_SPC,   KC_ENT,  RAISE,  KC_BSPC, KC_RALT
 *),
 */
/*
 * GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   -   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space /        \Enter \ |RAISE |BackSP| RGUI |
 *                   |      |      |      |/      /          \      \|      |      |      |
 *                   `--------------------'------´            `------'--------------------´
 *
 *
 * [_GAMING] = LAYOUT(
 *  KC_ESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
 *  KC_TAB,  KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
 *  KC_LCTRL,KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
 *  KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_MINS, KC_RBRC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
 *                            KC_LALT, KC_LGUI, LOWER, KC_SPC,  KC_ENT,  RAISE,   KC_BSPC, KC_RGUI
 *),
 */
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   @  |   $  |   %  |   ?  | PgUp |                    | HOME |   {  |   }  |   <  |   >  | PrnSc|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   ^  |   _  |   =  |   ~  | PgDn |-------.    ,-------|  END |   (  |   )  |   [  |   ]  |      |
 * |------+------+------+------+------+------|       |    |   |   |------+------+------+------+------+------|
 * |LShift|      |      |   ;  |   :  |      |-------|    |-------|   ´  |   '  |   "  |      |      |RShift|
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Enter /        \Space \ |RAISE |Delete| RGUI |
 *                   |      |      |      |/      /          \      \|      |      |      |
 *                   `--------------------'------´            `------'--------------------´
 */
[_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,      KC_F4,   KC_F5,      KC_F6,                        KC_F7,   KC_F8,      KC_F9,      KC_F10,     KC_F11,    KC_F12,
  _______, S(KC_2), S(KC_4),    S(KC_5), S(KC_SLSH), KC_PGUP,                      KC_HOME, S(KC_LBRC), S(KC_RBRC), S(KC_COMM), S(KC_DOT), KC_PSCR,
  _______, S(KC_6), S(KC_MINS), KC_EQL,  S(KC_GRV),  KC_PGDN,                      KC_END,  S(KC_9),    S(KC_0),    KC_LBRC,    KC_RBRC,   XXXXXXX,
  _______, XXXXXXX, XXXXXXX,    KC_SCLN, S(KC_SCLN), XXXXXXX, XXXXXXX, S(KC_BSLS), KC_GRV,  KC_QUOT,    S(KC_QUOT), XXXXXXX,    XXXXXXX,   _______,
                                _______, _______,    _______, _______, _______,    _______, KC_DEL,     _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |  Up  |      |      |                    |   .  |   7  |   8  |   9  |   /  |   *  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |      | Left | Down |Right |      |-------.    ,-------|   ,  |   4  |   5  |   6  |   +  |   -  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |      |RShift|
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Enter /        \Space \ |RAISE |BackSP| RGUI |
 *                   |      |      |      |/      /          \      \|      |      |      |
 *                   `--------------------'------´            `------'--------------------´
 */
[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,                     KC_DOT,  KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_PAST,
  _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                     KC_COMM, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PMNS,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  KC_P0,   KC_P1,   KC_P2,   KC_P3,   XXXXXXX, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------------.                     ,-----------------------------------------------.
 * | RESET |       |       |       |        |       |                    |RGB TG |  HUE+ |  SAT+ |  VAL+ |       |       |
 * |-------+-------+-------+-------+--------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |       | QWERTZ|       |COLEMAK |       |                    | MODE  |  HUE- |  SAT- |  VAL- |       |       |
 * |-------+-------+-------+-------+--------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |        |       |-------.    ,-------|       | MUTE  | VOLDO |  VOLUP|       |       |
 * |-------+-------+-------+-------+--------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |        |       |-------|    |-------|       | PREV  | PLAY  |  NEXT |       |       |
 * `------------------------------------------------/      /      \      \-----------------------------------------------'
 *                    |  LAlt  |  LGUI  | LOWER  | /Enter /        \Space \ |  RAISE | BackSP |  RGUI  |
 *                    |        |        |        |/      /          \      \|        |        |        |
 *                    `--------------------------'------´            `------'--------------------------´
 */
  [_ADJUST] = LAYOUT(
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_QWRZ, XXXXXXX, KC_CLMK, XXXXXXX,                    RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                               _______, _______,    _______,  _______, _______, _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

/* 32 * 32 logo */
static void render_logo(void) {
    /* 32 * 32 heart pirates logo */

/*    static const char PROGMEM heart_pirate_logo[] = {
            0x00,0x00,0x00,0x00,
            0x00,0x00,0x00,0x00,
            0x00,0x1F,0xF8,0x00,
            0x00,0x01,0x80,0x00,
            0x00,0x01,0x80,0x00,
            0x02,0x0F,0xF0,0x40,
            0x04,0x38,0x1C,0x20,
            0x08,0x60,0x06,0x10,
            0x08,0x80,0x01,0x10,
            0x19,0x00,0x00,0xF8,
            0x36,0x78,0x1E,0x68,
            0x26,0xFC,0x3F,0x64,
            0x24,0xFC,0x3F,0x24,
            0x64,0xFC,0x3F,0x24,
            0x04,0x7C,0x3E,0x20,
            0x04,0x38,0x1C,0x20,
            0x04,0x00,0x80,0x20,
            0x04,0x00,0x00,0x20,
            0x07,0xFF,0xFF,0xE0,
            0x24,0xC9,0x93,0x24,
            0x26,0x08,0x10,0x24,
            0x26,0x08,0x10,0x6C,
            0x1F,0x88,0x11,0xF8,
            0x19,0x88,0x11,0x98,
            0x08,0xC8,0x13,0x10,
            0x04,0x78,0x1E,0x20,
            0x06,0x1D,0xB8,0x60,
            0x00,0x07,0xE0,0x00,
            0x00,0x01,0x80,0x00,
            0x00,0x19,0x98,0x00,
            0x00,0x07,0xE0,0x00,
            0x00,0x00,0x00,0x00
        };
    oled_write_raw_P(heart_pirate_logo, sizeof(heart_pirate_logo));*/


    static const char PROGMEM hell_logo[] = {
            0x00, 0x80, 0xc0, 0xc0,
            0x60, 0x60, 0x30, 0x30,
            0x18, 0x1c, 0x0c, 0x00,
            0x00, 0x00, 0x00, 0x80,
            0xe0, 0x78, 0x1e, 0x06,
            0x00, 0x0c, 0x1c, 0x18,
            0x30, 0x30, 0x60, 0x60,
            0xc0, 0xc0, 0x80, 0x00,
            0x01, 0x03, 0x07, 0x06,
            0x0c, 0x0c, 0x18, 0x18,
            0x30, 0x70, 0x60, 0x00,
            0xc0, 0xf0, 0x3c, 0x0f,
            0x03, 0x00, 0x00, 0x00,
            0x00, 0x60, 0x70, 0x30,
            0x18, 0x18, 0x0c, 0x0c,
            0x06, 0x07, 0x03, 0x01,
            0x00, 0xf8, 0xf8, 0x80,
            0x80, 0x80, 0xf8, 0xf8,
            0x00, 0x80, 0xc0, 0xc0,
            0x40, 0xc0, 0xc0, 0x80,
            0x00, 0xf8, 0xf8, 0x00,
            0xf8, 0xf8, 0x00, 0x08,
            0x38, 0x08, 0x00, 0x38,
            0x08, 0x30, 0x08, 0x38,
            0x00, 0x1f, 0x1f, 0x01,
            0x01, 0x01, 0x1f, 0x1f,
            0x00, 0x0f, 0x1f, 0x1a,
            0x12, 0x1a, 0x1b, 0x0b,
            0x00, 0x1f, 0x1f, 0x00,
            0x1f, 0x1f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00
        };
    oled_write_raw_P(hell_logo, sizeof(hell_logo));

}

/* 32 * 14 os logos */
static const char PROGMEM windows_logo[] = {
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xbc,
    0xbc, 0xbe, 0xbe, 0x00,
    0xbe, 0xbe, 0xbf, 0xbf,
    0xbf, 0xbf, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x07,
    0x07, 0x0f, 0x0f, 0x00,
    0x0f, 0x0f, 0x1f, 0x1f,
    0x1f, 0x1f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

static const char PROGMEM mac_logo[] = {
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xc0,
    0xf0, 0xf8, 0xf8, 0xf8,
    0xf0, 0xf6, 0xfb, 0xfb,
    0x38, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01,
    0x07, 0x0f, 0x1f, 0x1f,
    0x0f, 0x0f, 0x1f, 0x1f,
    0x0f, 0x06, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

/* Smart Backspace Delete */

bool            shift_held = false;
static uint16_t held_shift = 0;

/* KEYBOARD PET START */

/* settings */
#define MIN_WALK_SPEED      10
#define MIN_RUN_SPEED       40

/* advanced settings */
#define ANIM_FRAME_DURATION 200  // how long each frame lasts in ms
#define ANIM_SIZE           96   // number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
uint8_t current_wpm = 0;
led_t   led_usb_state;

bool isSneaking = false;
bool isJumping  = false;
bool showedJump = true;

/* logic */
static void render_luna(int LUNA_X, int LUNA_Y) {
    /* Sit */
    static const char PROGMEM sit[2][ANIM_SIZE] =
    {/* 'sit1', 32x22px */
       {
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0xe0, 0x1c,
           0x02, 0x05, 0x02, 0x24,
           0x04, 0x04, 0x02, 0xa9,
           0x1e, 0xe0, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0xe0, 0x10,
           0x08, 0x68, 0x10, 0x08,
           0x04, 0x03, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x02, 0x06, 0x82,
           0x7c, 0x03, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x01, 0x02,
           0x04, 0x0c, 0x10, 0x10,
           0x20, 0x20, 0x20, 0x28,
           0x3e, 0x1c, 0x20, 0x20,
           0x3e, 0x0f, 0x11, 0x1f,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
       },

       /* 'sit2', 32x22px */
       {
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0xe0, 0x1c,
           0x02, 0x05, 0x02, 0x24,
           0x04, 0x04, 0x02, 0xa9,
           0x1e, 0xe0, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0xe0, 0x90, 0x08,
           0x18, 0x60, 0x10, 0x08,
           0x04, 0x03, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x02, 0x0e, 0x82,
           0x7c, 0x03, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x01, 0x02,
           0x04, 0x0c, 0x10, 0x10,
           0x20, 0x20, 0x20, 0x28,
           0x3e, 0x1c, 0x20, 0x20,
           0x3e, 0x0f, 0x11, 0x1f,
           0x00, 0x00, 0x00, 0x00,
           0x00, 0x00, 0x00, 0x00
        }
    };

    /* Walk */
    static const char PROGMEM walk[2][ANIM_SIZE] =
    {/* 'walk1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x80, 0x40, 0x20,
            0x10, 0x90, 0x90, 0x90,
            0xa0, 0xc0, 0x80, 0x80,
            0x80, 0x70, 0x08, 0x14,
            0x08, 0x90, 0x10, 0x10,
            0x08, 0xa4, 0x78, 0x80,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x07, 0x08, 0xfc,
            0x01, 0x00, 0x00, 0x00,
            0x00, 0x80, 0x00, 0x00,
            0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x08,
            0x18, 0xea, 0x10, 0x0f,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03,
            0x1c, 0x20, 0x20, 0x3c,
            0x0f, 0x11, 0x1f, 0x03,
            0x06, 0x18, 0x20, 0x20,
            0x3c, 0x0c, 0x12, 0x1e,
            0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00
        },

        /* 'walk2', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x80, 0x40,
            0x20, 0x20, 0x20, 0x40,
            0x80, 0x00, 0x00, 0x00,
            0x00, 0xe0, 0x10, 0x28,
            0x10, 0x20, 0x20, 0x20,
            0x10, 0x48, 0xf0, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x1f, 0x20, 0xf8,
            0x02, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x01,
            0x03, 0x00, 0x00, 0x00,
            0x00, 0x01, 0x00, 0x10,
            0x30, 0xd5, 0x20, 0x1f,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x3f,
            0x20, 0x30, 0x0c, 0x02,
            0x05, 0x09, 0x12, 0x1e,
            0x02, 0x1c, 0x14, 0x08,
            0x10, 0x20, 0x2c, 0x32,
            0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00
        }
    };

    /* Run */
    static const char PROGMEM run[2][ANIM_SIZE] =
    {/* 'run1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00,
            0xe0, 0x10, 0x08, 0x08,
            0xc8, 0xb0, 0x80, 0x80,
            0x80, 0x80, 0x80, 0x80,
            0x80, 0x40, 0x40, 0x3c,
            0x14, 0x04, 0x08, 0x90,
            0x18, 0x04, 0x08, 0xb0,
            0x40, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x01, 0x02, 0xc4, 0xa4,
            0xfc, 0x00, 0x00, 0x00,
            0x00, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x80,
            0xc8, 0x58, 0x28, 0x2a,
            0x10, 0x0f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x0e, 0x09, 0x04,
            0x04, 0x04, 0x04, 0x02,
            0x03, 0x02, 0x01, 0x01,
            0x02, 0x02, 0x04, 0x08,
            0x10, 0x26, 0x2b, 0x32,
            0x04, 0x05, 0x06, 0x00,
            0x00, 0x00, 0x00, 0x00
        },

        /* 'run2', 32x22px */
        {
            0x00, 0x00, 0x00, 0xe0,
            0x10, 0x10, 0xf0, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x80,
            0x80, 0x80, 0x78, 0x28,
            0x08, 0x10, 0x20, 0x30,
            0x08, 0x10, 0x20, 0x40,
            0x80, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x03,
            0x04, 0x08, 0x10, 0x11,
            0xf9, 0x01, 0x01, 0x01,
            0x01, 0x01, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x01,
            0x10, 0xb0, 0x50, 0x55,
            0x20, 0x1f, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x01, 0x02, 0x0c,
            0x10, 0x20, 0x28, 0x37,
            0x02, 0x1e, 0x20, 0x20,
            0x18, 0x0c, 0x14, 0x1e,
            0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00
        }
    };

    /* Bark */
    static const char PROGMEM bark[2][ANIM_SIZE] =
    {/* 'bark1', 32x22px */
        {
            0x00, 0xc0, 0x20, 0x10,
            0xd0, 0x30, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x80, 0x80, 0x40,
            0x3c, 0x14, 0x04, 0x08,
            0x90, 0x18, 0x04, 0x08,
            0xb0, 0x40, 0x80, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08,
            0x10, 0x11, 0xf9, 0x01,
            0x01, 0x01, 0x01, 0x01,
            0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x80, 0xc8, 0x48, 0x28,
            0x2a, 0x10, 0x0f, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x01,
            0x02, 0x0c, 0x10, 0x20,
            0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26,
            0x2b, 0x32, 0x04, 0x05,
            0x06, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00
        },

        /* 'bark2', 32x22px */
        {
            0x00, 0xe0, 0x10, 0x10,
            0xf0, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x80, 0x80, 0x40,
            0x40, 0x2c, 0x14, 0x04,
            0x08, 0x90, 0x18, 0x04,
            0x08, 0xb0, 0x40, 0x80,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x03, 0x04, 0x08,
            0x10, 0x11, 0xf9, 0x01,
            0x01, 0x01, 0x01, 0x01,
            0x01, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x80, 0xc0, 0x48,
            0x28, 0x2a, 0x10, 0x0f,
            0x20, 0x4a, 0x09, 0x10,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x01,
            0x02, 0x0c, 0x10, 0x20,
            0x28, 0x37, 0x02, 0x02,
            0x04, 0x08, 0x10, 0x26,
            0x2b, 0x32, 0x04, 0x05,
            0x06, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00
        }};

    /* Sneak */
    static const char PROGMEM sneak[2][ANIM_SIZE] =
    {/* 'sneak1', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x80, 0x40,
            0x40, 0x40, 0x40, 0x80,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xc0, 0x40,
            0x40, 0x80, 0x00, 0x80,
            0x40, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x1e, 0x21, 0xf0, 0x04,
            0x02, 0x02, 0x02, 0x02,
            0x03, 0x02, 0x02, 0x04,
            0x04, 0x04, 0x03, 0x01,
            0x00, 0x00, 0x09, 0x01,
            0x80, 0x80, 0xab, 0x04,
            0xf8, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x03, 0x1c,
            0x20, 0x20, 0x3c, 0x0f,
            0x11, 0x1f, 0x02, 0x06,
            0x18, 0x20, 0x20, 0x38,
            0x08, 0x10, 0x18, 0x04,
            0x04, 0x02, 0x02, 0x01,
            0x00, 0x00, 0x00, 0x00
        },

        /* 'sneak2', 32x22px */
        {
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x80, 0x40,
            0x40, 0x40, 0x80, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0xe0, 0xa0,
            0x20, 0x40, 0x80, 0xc0,
            0x20, 0x40, 0x80, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x3e, 0x41, 0xf0, 0x04,
            0x02, 0x02, 0x02, 0x03,
            0x02, 0x02, 0x02, 0x04,
            0x04, 0x02, 0x01, 0x00,
            0x00, 0x00, 0x04, 0x00,
            0x40, 0x40, 0x55, 0x82,
            0x7c, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x3f, 0x20,
            0x30, 0x0c, 0x02, 0x05,
            0x09, 0x12, 0x1e, 0x04,
            0x18, 0x10, 0x08, 0x10,
            0x20, 0x28, 0x34, 0x06,
            0x02, 0x01, 0x01, 0x00,
            0x00, 0x00, 0x00, 0x00
        }};

    /* animation */
    void animate_luna(void) {
        /* jump */
        if (isJumping || !showedJump) {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y + 2);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y - 1);

            showedJump = true;
        } else {
            /* clear */
            oled_set_cursor(LUNA_X, LUNA_Y - 1);
            oled_write("     ", false);

            oled_set_cursor(LUNA_X, LUNA_Y);
        }

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if (led_usb_state.caps_lock) {
            oled_write_raw_P(bark[abs(1 - current_frame)], ANIM_SIZE);

        } else if (isSneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(sit[abs(1 - current_frame)], ANIM_SIZE);

        } else if (current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);

        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    /* animation timer */
    if (timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
        anim_timer = timer_read32();
        if(timer_elapsed32(anim_sleep) < OLED_TIMEOUT) {
            animate_luna();
        }
    }

    /* this fixes the screen on and off bug*/
    if (current_wpm > 0) {
        oled_on();
        anim_sleep = timer_read32();
    } else if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
        oled_off();
    }
}

/* KEYBOARD PET END */

static void print_logo_narrow(void) {
    render_logo();

    /* wpm counter */
    // char wpm_str[5];
    // wpm_str[4] = '\0';
    // wpm_str[3] = '0' + current_wpm % 10;
    // wpm_str[2] = '0' + ( current_wpm /= 10) % 10;
    // wpm_str[1] = '0' + current_wpm / 10;
    // wpm_str[0] = ' ';
    oled_set_cursor(0,13);
    char wpm_str[10]; // if not working, maybe moving it to line ~20ish
    sprintf(wpm_str, "       WPM: %03d", get_current_wpm());
    oled_write(wpm_str, false);
    // oled_write_P(PSTR("  wpm"), false);
}

static void print_status_narrow(void) {
    /* Print current mode */
    oled_set_cursor(0, 0);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_raw_P(mac_logo, sizeof(mac_logo));
    } else {
        oled_write_raw_P(windows_logo, sizeof(windows_logo));
    }

    oled_set_cursor(0, 3);

    switch (get_highest_layer(default_layer_state)) {
      /*case _QWERTY:
            oled_write("QWRTY", false);
            break; */
        case _QWERTZ:
            oled_write("QWRTZ", false);
            break;
        case _COLEMAK:
            oled_write("CLMAK", false);
            break;
        case _NEO:
            oled_write("NEO  ", false);
            break;
        case _GAMING:
            oled_write("GAMES", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 5);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 6);

    switch (get_highest_layer(layer_state)) {
        // case _QWERTY:
            // oled_write("QWRTY", false);
            // break;
        case _QWERTZ:
            oled_write("QWRTZ", false);
            break;
        case _COLEMAK:
            oled_write("Clmak ", false);
            break;
        case _NEO:
            oled_write("Neo  ", false);
            break;
        case _GAMING:
            oled_write("Games", false);
            break;
        case _RAISE:
            oled_write("Raise", false);
            break;
        case _LOWER:
            oled_write("Lower", false);
            break;
        case _ADJUST:
            oled_write("Adj  ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* caps lock */
    oled_set_cursor(0, 8);
    oled_write("CPSLK", led_usb_state.caps_lock);

    /* KEYBOARD PET RENDER START */

    render_luna(0, 13);

    /* KEYBOARD PET RENDER END */
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */

    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    /* KEYBOARD PET VARIABLES END */

    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        print_logo_narrow();
    }
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWRZ:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTZ);
            }
            return false;
        case KC_CLMK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
//        case KC_NEO:
//            if (record->event.pressed) {
//                set_single_persistent_default_layer(_NEO);
//            }
//            return false;
//        case KC_GAMING:
//            if (record->event.pressed) {
//                set_single_persistent_default_layer(_GAMING);
//            }
//            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
//        case KC_PRVWD:
//            if (record->event.pressed) {
//                if (keymap_config.swap_lctl_lgui) {
//                    register_mods(mod_config(MOD_LALT));
//                    register_code(KC_LEFT);
//                } else {
//                    register_mods(mod_config(MOD_LCTL));
//                    register_code(KC_LEFT);
//                }
//            } else {
//                if (keymap_config.swap_lctl_lgui) {
//                    unregister_mods(mod_config(MOD_LALT));
//                    unregister_code(KC_LEFT);
//                } else {
//                    unregister_mods(mod_config(MOD_LCTL));
//                    unregister_code(KC_LEFT);
//                }
//            }
//            break;
//        case KC_NXTWD:
//            if (record->event.pressed) {
//                if (keymap_config.swap_lctl_lgui) {
//                    register_mods(mod_config(MOD_LALT));
//                    register_code(KC_RIGHT);
//                } else {
//                    register_mods(mod_config(MOD_LCTL));
//                    register_code(KC_RIGHT);
//                }
//            } else {
//                if (keymap_config.swap_lctl_lgui) {
//                    unregister_mods(mod_config(MOD_LALT));
//                    unregister_code(KC_RIGHT);
//                } else {
//                    unregister_mods(mod_config(MOD_LCTL));
//                    unregister_code(KC_RIGHT);
//                }
//            }
//            break;
//        case KC_LSTRT:
//            if (record->event.pressed) {
//                if (keymap_config.swap_lctl_lgui) {
//                    /* CMD-arrow on Mac, but we have CTL and GUI swapped */
//                    register_mods(mod_config(MOD_LCTL));
//                    register_code(KC_LEFT);
//                } else {
//                    register_code(KC_HOME);
//                }
//            } else {
//                if (keymap_config.swap_lctl_lgui) {
//                    unregister_mods(mod_config(MOD_LCTL));
//                    unregister_code(KC_LEFT);
//                } else {
//                    unregister_code(KC_HOME);
//                }
//            }
//            break;
//        case KC_LEND:
//            if (record->event.pressed) {
//                if (keymap_config.swap_lctl_lgui) {
//                    /* CMD-arrow on Mac, but we have CTL and GUI swapped */
//                    register_mods(mod_config(MOD_LCTL));
//                    register_code(KC_RIGHT);
//                } else {
//                    register_code(KC_END);
//                }
//            } else {
//                if (keymap_config.swap_lctl_lgui) {
//                    unregister_mods(mod_config(MOD_LCTL));
//                    unregister_code(KC_RIGHT);
//                } else {
//                    unregister_code(KC_END);
//                }
//            }
//            break;
//        case KC_DLINE:
//            if (record->event.pressed) {
//                register_mods(mod_config(MOD_LCTL));
//                register_code(KC_BSPC);
//            } else {
//                unregister_mods(mod_config(MOD_LCTL));
//                unregister_code(KC_BSPC);
//            }
//            break;
//        case KC_COPY:
//            if (record->event.pressed) {
//                register_mods(mod_config(MOD_LCTL));
//                register_code(KC_C);
//            } else {
//                unregister_mods(mod_config(MOD_LCTL));
//                unregister_code(KC_C);
//            }
//            return false;
//        case KC_PASTE:
//            if (record->event.pressed) {
//                register_mods(mod_config(MOD_LCTL));
//                register_code(KC_V);
//            } else {
//                unregister_mods(mod_config(MOD_LCTL));
//                unregister_code(KC_V);
//            }
//            return false;
//        case KC_CUT:
//            if (record->event.pressed) {
//                register_mods(mod_config(MOD_LCTL));
//                register_code(KC_X);
//            } else {
//                unregister_mods(mod_config(MOD_LCTL));
//                unregister_code(KC_X);
//            }
//            return false;
//            break;
//        case KC_UNDO:
//            if (record->event.pressed) {
//                register_mods(mod_config(MOD_LCTL));
//                register_code(KC_Z);
//            } else {
//                unregister_mods(mod_config(MOD_LCTL));
//                unregister_code(KC_Z);
//            }
//            return false;

        /* Smart Backspace Delete */

        case KC_RSFT:
        case KC_LSFT:
            shift_held = record->event.pressed;
            held_shift = keycode;
            break;
        case KC_BSPC_DEL:
            if (record->event.pressed) {
                if (shift_held) {
                    unregister_code(held_shift);
                    register_code(KC_DEL);
                } else {
                    register_code(KC_BSPC);
                }
            } else {
                unregister_code(KC_DEL);
                unregister_code(KC_BSPC);
                if (shift_held) {
                    register_code(held_shift);
                }
            }
            return false;

            /* LAYER */

        case KC_LAYER:
            if (record->event.pressed) {
                if (shift_held) {
                    if (record->event.pressed) {
                        if (get_highest_layer(default_layer_state) == _QWERTZ) {
                            set_single_persistent_default_layer(_GAMING);
                        } else if (get_highest_layer(default_layer_state) == _GAMING) {
                            set_single_persistent_default_layer(_QWERTZ);
                        }
                    }
                } else {
                    layer_on(_LOWER);
                    update_tri_layer(_LOWER, _RAISE, _ADJUST);
                }
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

            /* KEYBOARD PET STATUS START */

        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;

            /* KEYBOARD PET STATUS END */
    }
    return true;
}

/* Tap Dance definitions */
#ifdef TAP_DANCE_ENABLE

qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

#endif

/* RGB Matrix related code */
#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { { // underlight fehlt noch...
    // Key Matrix to LED Index
//   {     11,     10,      9,      8,      7,      6, NO_LED, NO_LED,      5,      4,      3,      2,      1,      0},
//   {     23,     22,     21,     20,     19,     18, NO_LED, NO_LED,     17,     16,     15,     14,     13,     12},
//   {     35,     34,     33,     32,     31,     30, NO_LED, NO_LED,     29,     28,     27,     26,     25,     24},
//   {     49,     48,     47,     46,     45,     44,     43,     42,     41,     40,     39,     38,     37,     36},
//   { NO_LED, NO_LED, NO_LED,     57,     56,     55,     54,     53,     52,     51,     50, NO_LED, NO_LED, NO_LED},

//   {     11,     10,      9,      8,      7,      6,                      5,      4,      3,      2,      1,      0},
//   {     23,     22,     21,     20,     19,     18,                     17,     16,     15,     14,     13,     12},
//   {     35,     34,     33,     32,     31,     30,                     29,     28,     27,     26,     25,     24},
//   {     49,     48,     47,     46,     45,     44,     43,     42,     41,     40,     39,     38,     37,     36},
//   {                             57,     56,     55,     54,     53,     52,     51,     50                        },

    {  0,  1,  2,  3,  4,  5 },
    {  6,  7,  8,  9, 10, 11 },
    { 12, 13, 14, 15, 16, 17 },
    { 18, 19, 20, 21, 22, 23 },
    { NO_LED, 24, 25, 26, 27, 28 },
    { 29, 30, 31, 32, 33, 34 },
    { 35, 36, 37, 38, 39, 40 },
    { 41, 42, 43, 44, 45, 46 },
    { 47, 48, 49, 50, 51, 52 },
    { NO_LED, 53, 54, 55, 56, 57 },
}, {
    // LED Index to Physical Position
    {   0,   0 }, {  16,   0 }, {  32,   0 }, {  48,   0 }, {  64,   0 }, {  80,   0 },
    {   0,  16 }, {  16,  16 }, {  32,  16 }, {  48,  16 }, {  64,  16 }, {  80,  16 },
    {   0,  32 }, {  16,  32 }, {  32,  32 }, {  48,  32 }, {  64,  32 }, {  80,  32 },
    {   0,  48 }, {  16,  48 }, {  32,  48 }, {  48,  48 }, {  64,  48 }, {  80,  48 },
                  {  48,  64 }, {  64,  64 }, {  80,  64 }, {  96,  64 }, {  96,  48 },
    { 128,   0 }, { 144,   0 }, { 160,   0 }, { 176,   0 }, { 192,   0 }, { 224,   0 },
    { 128,  16 }, { 144,  16 }, { 160,  16 }, { 176,  16 }, { 192,  16 }, { 224,  16 },
    { 128,  32 }, { 144,  32 }, { 160,  32 }, { 176,  32 }, { 192,  32 }, { 224,  32 },
    { 128,  48 }, { 144,  48 }, { 160,  48 }, { 176,  48 }, { 192,  48 }, { 224,  48 },
                  { 128,  64 }, { 144,  64 }, { 160,  64 }, { 112,  64 }, { 112,  48 },
}, {
    // LED Index to Flag (1 - modifier, 2 - underglow, 4 - key backlight)
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
       1, 1, 1, 1, 1,
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
       1, 1, 1, 1, 1,
} };

#endif

/* Rotary encoder related code */
#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Encoder on master side
    if(IS_LAYER_ON(_RAISE)) { // on Raise layer
      // Cursor control
      if (clockwise) {
          tap_code(KC_MNXT);
      } else {
          tap_code(KC_MPRV);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_VOLU);
      } else {
          tap_code(KC_VOLD);
      }
    }
  }
  else if (index == 1) { // Encoder on slave side
    if(IS_LAYER_ON(_LOWER)) { // on Lower layer
      //
      if (clockwise) {
          tap_code(KC_RIGHT);
      } else {
          tap_code(KC_LEFT);
      }
    }
    else {
      if (clockwise) {
          tap_code(KC_DOWN);
      } else {
          tap_code(KC_UP);
      }
    }
  }
    return true;
}
#endif // ENCODER_ENABLE

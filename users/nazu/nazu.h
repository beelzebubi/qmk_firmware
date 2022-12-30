#pragma once

#include "quantum.h"
#include "version.h"

enum layers {
    _QWERTY = 0,    // QWERTY layout for WIN or UNIX
    _COLEMAK,       // Colemak layout
    _MACOS,         // QWERTY layout for MacOS
    _FN1,           //
    _FN2,           //
};

enum cust_keys {
    KC_QWTY = SAFE_RANGE,     // change to QWERTY layer
    KC_CLMK,                 // change to COLEMAK layer
    KC_MAC,                 // change to MACOS layer
    KC_EMOM,                // shortcut for emoji picker in MACOS
    KC_EMOW,                // shortcut for emoji picker in WINDOWS
    LALT_F4,                // shortcut for LALT+F4
    KC_CAD,
};

enum tap_dance {
    TD_WIN,
    TD_ESC,
    TD_RCTL,
    TD_LSFT_CAPS,
};

//Aliases for longer keycodes
#define KC_CAD	LALT(LCTL(KC_DEL))
#define CA_QUOT LCA(KC_QUOT)
#define CA_SCLN LCA(KC_SCLN)
#define KC_CTLE LCTL_T(KC_ESC)
#define LT_SPCF LT(_FN1_60, KC_SPC)
#define LT_BPCF LT(_FN1_60, KC_BSPC)
#define TD_TESC TD(TD_ESC)
#define TD_TWIN TD(TD_WIN)
#define TD_TCTL TD(TD_RCTL)
#define CA_COPY LCTL(KC_C)
#define CA_PSTE LCTL(KC_V)
#define TD_CAPS TD(TD_LSFT_CAPS)
#define KC_EMOM LALT(LCTL(KC_SPACE))
#define KC_EMOW LGUI(KC_DOT)
#define LALT_F4 LM(_FN2, MOD_LALT)

// define a type containing as many tapdance states as you need
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP
} td_state_t;

// function to determine the current tapdance state
int cur_dance (qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void ctl_copy_finished (qk_tap_dance_state_t *state, void *user_data);
void ctl_copy_reset (qk_tap_dance_state_t *state, void *user_data);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
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

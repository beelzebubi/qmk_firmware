#pragma once

#include QMK_KEYBOARD_H

#include "keyrecords/wrappers.h"
#include "keyrecords/process_records.h"
#include "quantum.h"
#include "version.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY = 0,    // QWERTY layout for WIN or UNIX
    _COLEMAK,       // Colemak lazout
    _COLEMAK_DH,    // Colemak DHS layout
    _MACOS,         // QWERTY layout for MacOS
    _FN1,           //
    _FN2,           //
    _MEDIA,         //
    _LOWER,         //
    _RAISE,         //
    _ADJUST,        //
};

enum tap_dance {
    TD_WIN,
    TD_ESC,
    TD_RCTL,
    TD_LSFT_CAPS,
};

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


/* Tap Dance definitions */
#ifdef TAP_DANCE_ENABLE

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
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
        case KC_SWAP:
            keymap_config.raw = eeconfig_read_keymap();
            if (record->event.pressed) {
                keymap_config.swap_lalt_lgui = true;
                keymap_config.swap_rctl_rgui = true;
                // keymap_config.swap_ralt_rgui = true;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard(); // clear to prevent stuck keys
            }
            return false;
        case KC_NORM:
            keymap_config.raw = eeconfig_read_keymap();
            if (record->event.pressed) {
                keymap_config.swap_lalt_lgui = false;
                keymap_config.swap_rctl_rgui = false;
                // keymap_config.swap_ralt_rgui = false;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard(); // clear to prevent stuck keys
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
    // return process_record_keymap(keycode, record) && process_record_secrets(keycode, record);
}

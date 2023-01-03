#pragma once
#include QMK_KEYBOARD_H

#include "keyrecords/wrappers.h"
// #include "keyrecords/process_records.h"
// #include "version.h"
// #include "quantum.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY = 0,    // QWERTY layout for WIN or UNIX
    _COLEMAK,       // Colemak lazout
    _COLEMAK_DH,    // Colemak DHS layout
    _FN1,           //
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




enum userspace_custom_keycodes {
    KC_QWERTY = SAFE_RANGE, // change to QWERTY layer
    KC_COLEMAK,             // change to COLEMAK layer
    KC_COLEMAK_DH,          // change to COLEMAK DH layer
    KC_DVORAK,              // change to Dvorak layer
    KC_EMOM,                // shortcut for emoji picker in MACOS
    KC_EMOW,                // shortcut for emoji picker in WINDOWS
    KC_CAD,
    KC_SWAP,                // SWAP to MACOS mods
    KC_NORM,                // UNSWAP MACOS mods
    KC_R1,                  // wildcard to swap modifier in WIN/UNIX/MACOS
    KC_R2,                  // wildcard to swap modifier in WIN/UNIX/MACOS
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

/* Aliases for longer keycodes */
#define KC_CAD	LALT(LCTL(KC_DEL))
#define CA_QUOT LCA(KC_QUOT)
#define CA_SCLN LCA(KC_SCLN)
#define KC_CTLE LCTL_T(KC_ESC)
#define LT_SPCF LT(_FN1_60, KC_SPC)
#define LT_BPCF LT(_FN1_60, KC_BSPC)
#define CA_COPY LCTL(KC_C)
#define CA_PSTE LCTL(KC_V)
#define KC_EMOM LALT(LCTL(KC_SPACE))
#define KC_EMOW LGUI(KC_DOT)
#define LALT_F4 LM(_FN2, MOD_LALT)

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)

#define QWERTY KC_QWERTY
#define DVORAK KC_DVORAK
#define COLEMAK KC_COLEMAK
#define CLMKDH KC_COLEMAK_DH

/* OSM keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#ifdef TAP_DANCE_ENABLE
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

/**
 * @brief Keycode handler for keymaps
 *
 * This handles the keycodes at the keymap level, useful for keyboard specific customization
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

uint8_t mod_state;
/**
 * @brief Main user keycode handler
 *
 * This handles all of the keycodes for the user, including calling feature handlers.
 *
 * @param keycode Keycode from matrix
 * @param record keyrecord_t data structure
 * @return true Continue processing keycode and send to host
 * @return false Stop process keycode and do not send to host
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
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
        case KC_SWAP:
            keymap_config.raw = eeconfig_read_keymap();
            if (record->event.pressed) {
                keymap_config.swap_lalt_lgui = true;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard(); // clear to prevent stuck keys
            }
            return false;
        case KC_NORM:
            keymap_config.raw = eeconfig_read_keymap();
            if (record->event.pressed) {
                keymap_config.swap_lalt_lgui = false;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard(); // clear to prevent stuck keys
            }
            return false;
        case KC_R2:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(MOD_BIT(KC_RGUI));
                } else {
                    register_mods(MOD_BIT(KC_RALT));
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(MOD_BIT(KC_RGUI));
                } else {
                    unregister_mods(MOD_BIT(KC_RALT));
                }
            }
            return true;
        case KC_R1:
            if (record->event.pressed) {
                if (keymap_config.swap_lalt_lgui) {
                    register_mods(MOD_BIT(KC_RALT));
                } else {
                    register_mods(MOD_BIT(KC_RCTL));
                }
            } else {
                if (keymap_config.swap_lalt_lgui) {
                    unregister_mods(MOD_BIT(KC_RALT));
                } else {
                    unregister_mods(MOD_BIT(KC_RCTL));
                }
            }
            return true;
        case KC_4: // Implementation of Alt F4
            // Only detect in Windows-typical config
            if (!keymap_config.swap_lalt_lgui) {
                // Detect the activation of only Left Alt
                if ((mod_state & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
                    if (record->event.pressed) {
                        // No need to register KC_LALT because it's already active.
                        // The Alt modifier will apply on this KC_F4.
                        register_code(KC_F4);
                    } else {
                        unregister_code(KC_F4);
                    }
                    // Do not let QMK process the keycode further
                    return false;
                }
            }
            // Else, let QMK process the KC_4 keycode as usual
            return true;
        case KC_A ... KC_Z: // Hack for EurKEY on Windows, where alternate characters do not work with LALT
                // Detect the activation of only Left Alt
                if ((mod_state & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT)) {
                    static bool raltkey_registered;
                    if (record->event.pressed) {
                        // First, canceling MOD_LALT
                        del_mods(MOD_BIT(KC_LALT));
                        // Then sending actual combo
                        register_mods(MOD_BIT(KC_RALT));
                        register_code(keycode);
                        // Update the boolean variable to reflect the status of MOD_RALT
                        raltkey_registered = true;
                        // Reapplying modifier state so that the held LALT key still work even after having tapped the key.
                        set_mods(mod_state);
                        return false;
                    } else {
                        if (raltkey_registered) {
                            raltkey_registered = false;
                            unregister_mods(MOD_BIT(KC_RALT));
                            unregister_code(keycode);
                            return false;
                        }
                    }
                    // Do not let QMK process the keycode further
                    return true;
                }
            // Else, let QMK process the keycode as usual
            return true;
    }
    return true;
}



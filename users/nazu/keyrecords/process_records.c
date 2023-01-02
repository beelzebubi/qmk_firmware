#include "nazu.h"
// #include "version.h"

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) { return true; }

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

// __attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
// void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//     post_process_record_keymap(keycode, record);
// }

#include "nazu.h"
#include "version.h"

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
        case KC_SWAP:
            if (record->event.pressed) {
                // register_code(RCG_SWP);
                // register_code(RAG_SWP);
                register_code(LAG_SWP);
            } else {
                // unregister_code(RCG_SWP);
                // unregister_code(RAG_SWP);
                unregister_code(LAG_SWP);
            }
            return false;
        case KC_NORM:
            if (record->event.pressed) {
                // register_code(RCG_NRM);
                // register_code(RAG_NRM);
                register_code(LAG_NRM);
            } else {
                // unregister_code(RCG_NRM);
                // unregister_code(RAG_NRM);
                unregister_code(LAG_NRM);
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

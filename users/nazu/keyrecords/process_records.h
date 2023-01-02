#pragma once
#include "nazu.h"

enum userspace_custom_keycodes {
    KC_QWERTY = SAFE_RANGE, // change to QWERTY layer
    KC_COLEMAK,             // change to COLEMAK layer
    KC_COLEMAK_DH,          // change to COLEMAK DH layer
    KC_DVORAK,              // change to Dvorak layer
    KC_MAC,                 // change to MACOS layer
    KC_EMOM,                // shortcut for emoji picker in MACOS
    KC_EMOW,                // shortcut for emoji picker in WINDOWS
    LALT_F4,                // shortcut for LALT+F4
    KC_CAD,
    KC_SWAP,                // SWAP to MACOS mods
    KC_NORM,                // UNSWAP MACOS mods
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
#define MACOS KC_MAC
#define EN_MAC KC_SWAP
#define DS_MAC KC_NORM

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


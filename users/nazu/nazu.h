#pragma once

#include QMK_KEYBOARD_H

#include "keyrecords/wrappers.h"
#include "keyrecords/process_records.h"
#include "quantum.h"
#include "version.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY = 0,    // QWERTY layout for WIN or UNIX
    _MACOS,         // QWERTY layout for MacOS
    _COLEMAK_DH,    // Colemak DHS layout
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

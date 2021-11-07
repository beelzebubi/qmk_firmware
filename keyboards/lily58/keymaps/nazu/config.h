/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2020 Ben Roesner (keycapsss.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_ANIMATIONS
#   define RGBLIGHT_HUE_STEP 6 // number of steps to cycle through the hue by
#   define RGBLIGHT_SAT_STEP 6 // number of steps to increment the saturation by
#   define RGBLIGHT_VAL_STEP 6 // number of steps to increment the brightness by
#   define RGBLIGHT_SLEEP //  the RGB lighting will be switched off when the host goes to sleep
#   define RGBLIGHT_SPLIT // synchronization functionality for split keyboards
#   undef RGBLIGHT_ANIMATIONS
#   define RGBLIGHT_EFFECT_BREATHING
#   define RGBLIGHT_EFFECT_RAINBOW_MOOD
#endif

#ifdef OLED_ENABLE
#   define OLED_DISABLE_TIMEOUT
#endif

#ifdef RGB_MATRIX_ENABLE
#   define DRIVER_LED_TOTAL 70  // number of LEDs connected
#   define RGB_MATRIX_KEYPRESSES  // reacts to keypresses
// #   define RGB_MATRIX_KEYRELEASES // reacts to keyreleases (instead of keypresses)
// #   define RGB_DISABLE_AFTER_TIMEOUT 0 // number of ticks to wait until disabling effects
#   define RGB_DISABLE_WHEN_USB_SUSPENDED true  // turn off effects when suspended
// #   define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5 // limits the number of LEDs to process in an animation per task run (increases keyboard responsiveness)
// #   define RGB_MATRIX_LED_FLUSH_LIMIT 16 // limits in milliseconds how frequently an animation will update the LEDs. 16 (16ms) is equivalent to limiting to 60fps (increases keyboard responsiveness)
#   define RGB_MATRIX_MAXIMUM_BRIGHTNESS 150  // limits maximum brightness of LEDs to 200 out of 255. If not defined maximum brightness is set to 255
#   define RGB_MATRIX_HUE_STEP 8
#   define RGB_MATRIX_SAT_STEP 8
#   define RGB_MATRIX_VAL_STEP 5
#   define RGB_MATRIX_SPD_STEP 10
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
#define SPLIT_USB_DETECT
#define NO_USB_STARTUP_CHECK

// Tests for reducing firmware size
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#ifndef NO_DEBUG
#   define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#   define NO_PRINT
#endif // !NO_PRINT

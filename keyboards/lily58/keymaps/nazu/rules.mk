EXTRAKEY_ENABLE = yes

# OLED visualization
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
WPM_ENABLE = yes

# RBG
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB light
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = WS2812

ENCODER_ENABLE = no       # Enables the use of one or more encoders
# BACKLIGHT_ENABLE = yes     # Enable keyboard backlight functionality
LINK_TIME_OPTIMIZATION_ENABLE = yes 	   # significantly reduce the compiled size, but disable the legacy TMK Macros and Functions features
TAP_DANCE_ENABLE = yes	  # Enable Tap Dance

NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work

EXTRAFLAGS += -flto
MOUSEKEY_ENABLE = no

# # Build Options
# #   change to "no" to disable the options, or define them in the Makefile in
# #   the appropriate keymap folder that will get included automatically
# #
# # BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
# # EXTRAKEY_ENABLE = no        # Audio control and System control
# CONSOLE_ENABLE = no         # Console for debug
# COMMAND_ENABLE = no         # Commands for debug and configuration
# # BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
# AUDIO_ENABLE = no           # Audio output
# # RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
# SWAP_HANDS_ENABLE = no      # Enable one-hand typing

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

EXTRAKEY_ENABLE = yes

OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB light
LTO_ENABLE = yes 		   # significantly reduce the compiled size, but disable the legacy TMK Macros and Functions features

WPM_ENABLE = yes

EXTRAFLAGS += -flto
MOUSEKEY_ENABLE = no

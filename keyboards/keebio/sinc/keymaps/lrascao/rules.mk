# This enables Link Time Optimization, saving a significant amount of space.
LTO_ENABLE = yes

BOOTMAGIC_ENABLE = no

# OLED
# https://docs.qmk.fm/features/oled_driver
# (3210 bytes)
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c

# All RGB animations disabled except rainbow swirl to save up
# on firmware space
RGBLIGHT_ENABLE = no

BACKLIGHT_ENABLE  = no
COMMAND_ENABLE    = no  # Commands for debug and configuration
SWAP_HANDS_ENABLE = no  # Allow swapping hands of keyboard
UNICODE_ENABLE    = no  # Unicode
CONSOLE_ENABLE    = no  # Console for debug
MOUSEKEY_ENABLE   = no

# https://docs.qmk.fm/features/space_cadet
# (286 bytes)
SPACE_CADET_ENABLE = yes

# https://docs.qmk.fm/features/grave_esc
# (90 bytes)
GRAVE_ESC_ENABLE = yes

# https://docs.qmk.fm/#/feature_leader_key
# (236 bytes)
LEADER_ENABLE = yes

# Audio control and System control
# (384 bytes)
EXTRAKEY_ENABLE = yes

# The Combo feature is a chording type solution for adding custom actions.
# It lets you hit multiple keys at once and produce a different effect.
# For instance, hitting A and S within the combo term would hit ESC instead,
# or have it perform even more complex tasks.
# https://docs.qmk.fm/#/feature_combo
# (2346 bytes)
COMBO_ENABLE = no

# https://docs.qmk.fm/#/feature_tap_dance
# (894 bytes)
TAP_DANCE_ENABLE = yes

# Programmable button is a feature that can be used to send keys that have no predefined meaning.
# This means they can be processed on the host side by custom software without colliding without
# the operating system trying to interpret these keys.
# https://docs.qmk.fm/features/programmable_button
# (324 bytes)
PROGRAMMABLE_BUTTON_ENABLE = no

# Logo enabled
# (1198 bytes)
LOGO_ENABLE = no

# https://docs.qmk.fm/#/feature_auto_shift
# Tap a key and you get its character.
# Tap a key, but hold it slightly longer and you get its shifted state.
# (1978 bytes)
AUTO_SHIFT_ENABLE = no

# https://docs.qmk.fm/features/encoders
# (1086 bytes)
ENCODER_ENABLE = yes
# https://docs.qmk.fm/#/feature_encoders?id=encoder-map
# (216 bytes)
ENCODER_MAP_ENABLE = yes

# Music mode feature. This tranlates matrix positions into notes
MUSIC_ENABLE = no

ifeq ($(strip $(OLED_ENABLE)), yes)
SRC += oled.c
endif

ifeq ($(strip $(LOGO_ENABLE)), yes)
SRC += logo.c
OPT_DEFS += -DLOGO_ENABLE
endif

# Overrides ../../rules.mk
DEFAULT_FOLDER = keebio/sinc/rev2


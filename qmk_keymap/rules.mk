# See default rules.mk for Lily58 board at https://github.com/qmk/qmk_firmware/blob/master/keyboards/lily58/rules.mk for more options.

EXTRAKEY_ENABLE = yes     # Audio control and System control
OLED_DRIVER_ENABLE = yes  # OLED display

SRC +=  \
	./lib/rgb_state_reader.c \
	./lib/layer_state_reader.c \
	./lib/logo_reader.c \
	./lib/keylogger.c

# Loads /users/podnaut userspace.
USER_NAME := podnaut
KEYMAP_ENABLE = 34k  # Use "34k" keymap (from /users/podnaut/keymaps).
TAP_DANCE_ENABLE = yes
MOUSEKEY_ENABLE  = yes
KEY_OVERRIDE_ENABLE = no
SRC += users/podnaut/keymaps/features/custom_shift_keys.c

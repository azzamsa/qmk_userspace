#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_5,  KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_T,  KC_LSFT, KC_Q,     KC_W,    KC_E,    KC_R,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_G,  KC_LCTL, KC_A,     KC_S,    KC_D,    KC_F,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_B,  KC_TAB,  KC_Z,     KC_X,    KC_C,    KC_V,    XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        KC_PSCR,  KC_LGUI, KC_ENT,  KC_SPC,  OSL(1),     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [1] = LAYOUT(
        KC_0,     KC_GRV,   KC_6,    KC_7,     KC_8,     KC_9,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_P,     _______,  KC_Y,    KC_U,     KC_I,     KC_O,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SCLN,  _______,  KC_H,    KC_J,     KC_K,     KC_L,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SLSH,  _______,  KC_N,    KC_M,     KC_COMM,  KC_DOT,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            KC_F12,  _______,  XXXXXXX,  KC_DEL,  _______,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

};

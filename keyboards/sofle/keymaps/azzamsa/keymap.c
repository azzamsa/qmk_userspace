#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_5,  KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_T,  KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_G,  KC_LSFT, KC_A,     KC_S,    KC_D,    KC_F,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_B,  KC_LCTL, KC_Z,     KC_X,    KC_C,    KC_V,    XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        KC_PSCR,  KC_ENT, OSL(2),  KC_SPC,  OSL(1),     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [1] = LAYOUT(
        KC_0,     KC_GRV,   KC_6,    KC_7,     KC_8,     KC_9,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_P,     _______,  KC_Y,    KC_U,     KC_I,     KC_O,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SCLN,  _______,  KC_H,    KC_J,     KC_K,     KC_L,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_SLSH,  _______,  KC_N,    KC_M,     KC_COMM,  KC_DOT,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                            KC_F12,  _______,  XXXXXXX,  KC_DEL,  _______,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),


    [2] = LAYOUT(
        KC_F5,    _______, KC_F1,     KC_F2,   KC_F3,    KC_F4,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,  _______, _______,  _______,  _______,  _______,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,  _______, _______,  _______,  _______,  _______,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______,  _______, _______,  _______,  _______,  _______,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           _______,  _______,  _______,  _______,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

};

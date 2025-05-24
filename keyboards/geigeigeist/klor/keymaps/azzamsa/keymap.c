#include QMK_KEYBOARD_H

// Layer aliases
#define XXX KC_NO
#define ___ KC_TRANSPARENT

// Layer aliases
#define LA_EXT MO(_EXT)
#define LA_SYM MO(_SYM)

// Oneshot aliases
#define OS_GUI  OSM(MOD_LGUI)
#define OS_ALT  OSM(MOD_LALT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_SHFT OSM(MOD_LSFT)

// Other aliases
#define DEL_WORD LCTL(KC_BSPC)

enum layers {
    _BASE,
    _EXT,
    _FUNC,
    _SYM,
    _NUM,
};

/* enum keycodes { */
/*     // Custom oneshot mod implementation with no timers. */
/*     OS_SHFT = SAFE_RANGE, */
/*     OS_CTRL, */
/*     OS_ALT, */
/*     OS_GUI, */
/* }; */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
             KC_Q,  KC_W,  KC_F,  KC_P,   KC_B,                KC_J,    KC_L,   KC_U,    KC_Y,   KC_QUOT,
        XXX, KC_A,  KC_R,  KC_S,  KC_T,   KC_G,                KC_M,    KC_N,   KC_E,    KC_I,   KC_O,    XXX,
        XXX, KC_Z,  KC_X,  KC_C,  KC_D,   KC_V,   ___,    ___, KC_K,    KC_H,   KC_COMM, KC_DOT, KC_SLSH, XXX,
                           XXX,   LA_EXT, KC_SPC, XXX,    XXX, KC_LSFT, LA_SYM, XXX
    ),

    [_EXT] = LAYOUT(
             KC_ESC,  XXX,    QK_REP,  KC_ALGR, KC_INS,                 KC_PGUP,  KC_HOME, KC_UP,   KC_END,   KC_CAPS,
        XXX, OS_GUI,  OS_ALT, OS_CTRL, OS_SHFT, MS_BTN4,                KC_PGDN,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,  XXX,
        XXX, KC_UNDO, KC_CUT, KC_COPY, KC_LGUI, KC_PASTE, ___,     ___, DEL_WORD, KC_BSPC, KC_TAB,  KC_APP,   KC_PSCR, XXX,
                              XXX,     ___,     ___,     XXX,      XXX, KC_ENT,   ___,     XXX
    ),

    [_SYM] = LAYOUT(
             KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PLUS,               KC_EQL,  KC_GRV,  KC_SCLN, KC_COLN, KC_PLUS,
        XXX, KC_TILD, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS,               KC_CIRC, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  XXX,
        XXX, KC_ASTR, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS, ___,     ___, KC_AMPR, XXX,     KC_AMPR, KC_QUES, KC_BSLS, XXX,
                               XXX,     ___,     ___,     XXX,     XXX, ___,     ___,     XXX
    ),

    [_FUNC] = LAYOUT(
             KC_F12, KC_F7, KC_F8, KC_F9, XXX,                  KC_BRIU, KC_MNXT, KC_MPLY, KC_MPRV, KC_MSTP,
        XXX, KC_F11, KC_F4, KC_F5, KC_F6, XXX,                  KC_BRID, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  XXX,
        XXX, KC_F10, KC_F1, KC_F2, KC_F3, QK_BOOT, ___,    ___, KC_F10,  KC_VOLU, KC_F2,   KC_VOLD, KC_MUTE, XXX,
                            XXX,   ___,   ___,     XXX,    XXX, ___,    ___,   XXX
    ),

    [_NUM] = LAYOUT(
             KC_EQL,  KC_7, KC_8, KC_9, KC_MINS,              KC_F12,  KC_F7,   KC_F8,   KC_F9,  KC_VOLU,
        XXX, KC_ASTR, KC_4, KC_5, KC_6, KC_MINS,              KC_ALGR, OS_SHFT, OS_CTRL, OS_ALT, OS_GUI,  XXX,
        XXX, KC_0,    KC_1, KC_2, KC_3, KC_SLSH, ___,    ___, KC_F10,  KC_F1,   KC_F2,   KC_F3,  KC_MPLY, XXX,
                      XXX,  ___,  ___,  XXX,     XXX,    ___,    ___,   XXX
    ),


};


// Layers
layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _EXT, _SYM, _FUNC);
    return state;
}

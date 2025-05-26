#include QMK_KEYBOARD_H

// Layer aliases
#define XXX KC_NO
#define ___ KC_TRANSPARENT

// Layer aliases
#define LA_EXT  MO(_EXT)
#define LA_SYM  MO(_SYM)
#define LA_NUM  MO(_NUM)
#define LA_FUNC MO(_FUNC)

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
    _SYM,
    _NUM,
    _FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
             KC_Q,  KC_W,  KC_F,  KC_P,   KC_B,                KC_J,    KC_L,   KC_U,    KC_Y,   KC_QUOT,
        XXX, KC_A,  KC_R,  KC_S,  KC_T,   KC_G,                KC_M,    KC_N,   KC_E,    KC_I,   KC_O,    XXX,
        XXX, KC_Z,  KC_X,  KC_C,  KC_D,   KC_V,   ___,    ___, KC_K,    KC_H,   KC_COMM, KC_DOT, KC_SLSH, XXX,
                           XXX,   LA_EXT, KC_SPC, XXX,    XXX, KC_LSFT, LA_SYM, XXX
    ),

    [_EXT] = LAYOUT(
             KC_ESC, KC_ESC, KC_TAB,  KC_DEL,  XXX,                   KC_AGIN, KC_CUT,  KC_COPY, KC_PASTE, KC_UNDO,
        XXX, OS_GUI, OS_ALT, OS_CTRL, OS_SHFT, KC_LGUI,               KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT, XXX,
        XXX, XXX,    QK_REP, XXX,     KC_APP,  XXX,     ___,     ___, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  XXX,
                             XXX,     ___,     ___,     XXX,     XXX, KC_ENT,  KC_BSPC, XXX
    ),

    [_SYM] = LAYOUT(
             KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PLUS,               KC_EQL,  KC_GRV,  KC_COLN, KC_SCLN, KC_PLUS,
        XXX, KC_ASTR, KC_LCBR, KC_LPRN, KC_LBRC, KC_MINS,               KC_CIRC, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  XXX,
        XXX, KC_TILD, KC_RCBR, KC_RPRN, KC_RBRC, KC_UNDS, ___,     ___, XXX,     XXX,     KC_BSLS, KC_PIPE, KC_AMPR, XXX,
                               XXX,     LA_NUM,  LA_FUNC, XXX,     XXX, ___,     ___,     XXX
    ),

    [_NUM] = LAYOUT(
             KC_EQL,  KC_7, KC_8, KC_9, KC_PLUS,              XXX, XXX,     XXX,     XXX,    XXX,
        XXX, KC_0,    KC_4, KC_5, KC_6, KC_MINS,              XXX, OS_SHFT, OS_CTRL, OS_ALT, OS_GUI, XXX,
        XXX, KC_ASTR, KC_1, KC_2, KC_3, KC_SLSH, ___,    ___, XXX, XXX,     XXX,     XXX,    XXX,    XXX,
                            XXX,  ___,  ___,     XXX,    XXX, ___, ___,     XXX
    ),

    [_FUNC] = LAYOUT(
             KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,              KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP,
        XXX, KC_F11, KC_F4, KC_F5, KC_F6, XXX,                  KC_BRID, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  XXX,
        XXX, KC_F10, KC_F1, KC_F2, KC_F3, QK_BOOT, ___,    ___, XXX,     KC_VOLU, KC_VOLD, KC_VOLU, KC_MUTE, XXX,
                            XXX,   ___,   ___,     XXX,    XXX, ___,    ___,   XXX
    ),

};

// Combos
const uint16_t PROGMEM caps_combo[]   = { KC_G, KC_M, COMBO_END };

const uint16_t PROGMEM esc_combo[]    = { KC_F, KC_P, COMBO_END };
const uint16_t PROGMEM tab_combo[]    = { KC_W, KC_F, COMBO_END };
const uint16_t PROGMEM bspc_combo[]   = { KC_L, KC_U, COMBO_END };
const uint16_t PROGMEM ent_combo[]    = { KC_U, KC_Y, COMBO_END };

combo_t key_combos[] = {
    COMBO(caps_combo,  CW_TOGG),

    COMBO(esc_combo,   KC_ESC),
    COMBO(tab_combo,   KC_TAB),
    COMBO(bspc_combo,  KC_BSPC),
    COMBO(ent_combo,   KC_ENT),
};

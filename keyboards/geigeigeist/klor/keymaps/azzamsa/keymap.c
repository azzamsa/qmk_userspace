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
#define OS_RALT OSM(MOD_RALT)

// Other aliases
#define DEL_WORD LCTL(KC_BSPC)
#define SAVE     LCTL(KC_S)
#define SEL_ALL  LCTL(KC_A)
#define UNDO     LCTL(KC_Z)
#define COPY     LCTL(KC_C)
#define CUT      LCTL(KC_X)
#define PASTE    LCTL(KC_V)
#define FLIP     LALT(KC_TAB) // Switch Window

#define SH_SHFT  SFT_T(KC_SPC)

enum layers {
    _BASE,
    _EXT,
    _SYM,
    _NUM,
    _FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
             KC_Q,  KC_W,  KC_F,  KC_P,   KC_B,                 KC_J,    KC_L,   KC_U,    KC_Y,   KC_QUOT,
        XXX, KC_A,  KC_R,  KC_S,  KC_T,   KC_G,                 KC_M,    KC_N,   KC_E,    KC_I,   KC_O,    XXX,
        XXX, KC_Z,  KC_X,  KC_C,  KC_D,   KC_V,    ___,    ___, KC_K,    KC_H,   KC_COMM, KC_DOT, KC_SLSH, XXX,
                           XXX,   LA_EXT, SH_SHFT, XXX,    XXX, KC_LSFT, LA_SYM, XXX
    ),

    [_EXT] = LAYOUT(
             XXX,     KC_ESC, FLIP,    QK_REP,  SEL_ALL,               CW_TOGG,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        XXX, OS_GUI,  OS_ALT, OS_CTRL, OS_SHFT, SAVE,                  KC_DEL,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXX,
        XXX, UNDO,    CUT,    COPY,    PASTE,   KC_LGUI, ___,     ___, DEL_WORD, KC_BSPC, KC_TAB,  XXX,     KC_INS,  XXX,
                              XXX,     ___,     ___,     XXX,     XXX, KC_ENT,   LA_NUM,  XXX
    ),

    [_SYM] = LAYOUT(
             KC_TILD, KC_AT,   KC_HASH, KC_DLR,  KC_PLUS,               KC_PERC, KC_GRV,  KC_COLN, KC_SCLN, KC_EQL,
        XXX, KC_ASTR, KC_LCBR, KC_LPRN, KC_LBRC, KC_MINS,               KC_CIRC, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  XXX,
        XXX, KC_EXLM, KC_RCBR, KC_RPRN, KC_RBRC, KC_UNDS, ___,     ___, KC_AMPR, XXX,     KC_BSLS, KC_PIPE, XXX,     XXX,
                               XXX,     LA_NUM,  LA_FUNC, XXX,     XXX, ___,     ___,     XXX
    ),

    [_NUM] = LAYOUT(
             KC_EQL,  KC_7, KC_8, KC_9, KC_PLUS,              KC_CAPS, KC_PSCR, XXX,     XXX,    XXX,
        XXX, KC_0,    KC_4, KC_5, KC_6, KC_MINS,              XXX,     OS_SHFT, OS_CTRL, OS_ALT, OS_GUI, XXX,
        XXX, KC_ASTR, KC_1, KC_2, KC_3, KC_SLSH, ___,    ___, XXX,     XXX,     XXX,     XXX,    XXX,    XXX,
                            XXX,  ___,  ___,     XXX,    XXX, ___, ___,     XXX
    ),

    [_FUNC] = LAYOUT(
             KC_F12, KC_F7, KC_F8, KC_F9, XXX,                  KC_BRIU, KC_MNXT, KC_MPLY, KC_MPRV, KC_MSTP,
        XXX, KC_F11, KC_F4, KC_F5, KC_F6, XXX,                  KC_BRID, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,  XXX,
        XXX, KC_F10, KC_F1, KC_F2, KC_F3, QK_BOOT, ___,    ___, XXX,     KC_VOLU, XXX,     KC_VOLD, KC_MUTE, XXX,
                            XXX,   ___,   ___,     XXX,    XXX, ___,    ___,   XXX
    ),

};

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);
const key_override_t test_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_A);

const key_override_t *key_overrides[] = {
  &capsword_key_override,
  &test_key_override
};

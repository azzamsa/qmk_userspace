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

#define SH_SHFT  SFT_T(KC_SPC)

enum layers {
    _BASE,
    _EXT,
    _SYM,
    _NUM,
    _FUNC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q, KC_W, KC_F,   KC_P,    KC_B,      KC_J,    KC_L,    KC_U,    KC_Y,   KC_QUOT,
        KC_A, KC_R, KC_S,   KC_T,    KC_G,      KC_M,    KC_N,    KC_E,    KC_I,   KC_O,
        KC_Z, KC_X, KC_C,   KC_D,    KC_V,      KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH,
                    XXX,    LA_EXT,  SH_SHFT,   KC_LSFT, LA_SYM,  XXX
    ),

    [_EXT] = LAYOUT_split_3x5_3(
        XXX,     KC_ESC, QK_REP,  XXX,     KC_INS,     CW_TOGG,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        OS_GUI,  OS_ALT, OS_CTRL, OS_SHFT, OS_RALT,    KC_DEL,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        UNDO,    CUT,    COPY,    PASTE,   KC_LGUI,    DEL_WORD, KC_BSPC, KC_TAB,  SAVE,    SEL_ALL,
                         XXX,     ___,     ___,        KC_ENT,   LA_NUM,  XXX
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,    KC_EQL,  KC_GRV,  KC_COLN, KC_SCLN, KC_PLUS,
        OS_GUI,  OS_ALT, OS_CTRL, OS_SHFT, KC_CIRC,    KC_ASTR, KC_LCBR, KC_LPRN, KC_LBRC, KC_MINS,
        XXX,     XXX,    KC_BSLS, KC_PIPE, KC_AMPR,    KC_TILD, KC_RCBR, KC_RPRN, KC_RBRC, KC_UNDS,
                         XXX,     ___,     ___,        ___,     ___,     XXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        XXX,    XXX,    XXX,     XXX,     KC_CAPS,    XXX, KC_7, KC_8, KC_9, XXX,
        OS_GUI, OS_ALT, OS_CTRL, OS_SHFT, XXX,        XXX, KC_4, KC_5, KC_6, KC_0,
        XXX,    XXX,    XXX,     XXX,     XXX,        XXX, KC_1, KC_2, KC_3, XXX,
                        XXX,     ___,     ___,        ___, ___,  XXX
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
        XXX,     XXX,     KC_MPLY, KC_PSCR, KC_BRIU,     KC_F12, KC_F7, KC_F8, KC_F9, XXX,
        OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, KC_BRID,     KC_F11, KC_F4, KC_F5, KC_F6, XXX,
        KC_MUTE, KC_VOLD, KC_MPLY, KC_VOLU, QK_BOOT,     KC_F10, KC_F1, KC_F2, KC_F3, XXX,
                          XXX,     ___,     ___,         ___,    ___,   XXX
    ),
};

/* const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS); */
/* const key_override_t test_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_A); */

/* const key_override_t *key_overrides[] = { */
/*   &capsword_key_override, */
/*   &test_key_override */
/* }; */

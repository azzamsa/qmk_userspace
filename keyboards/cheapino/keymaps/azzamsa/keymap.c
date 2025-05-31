#include QMK_KEYBOARD_H

// Layer aliases
#define XXX KC_NO
#define ___ KC_TRANSPARENT

#define LT_ESC     LT(_MEDIA, KC_ESC)
#define LT_SPACE   LT(_NAV,   KC_SPACE)
#define LT_TAB     LT(_MOUSE, KC_TAB)

#define LT_ENT     LT(_SYM,  KC_ENT)
#define LT_BSPC    LT(_NUM,  KC_BSPC)
#define LT_DEL     LT(_FUNC, KC_DEL)

// Left-hand Mod-Tap aliases
#define MT_A   LGUI_T(KC_A)
#define MT_R   LALT_T(KC_R)
#define MT_S   LCTL_T(KC_S)
#define MT_T   LSFT_T(KC_T)

// Right-hand regular and Mod-Tap aliases
#define MT_N   LSFT_T(KC_N)
#define MT_E   LCTL_T(KC_E)
#define MT_I   LALT_T(KC_I)
#define MT_O   LGUI_T(KC_O)

// Other aliases
#define DL_WORD  LCTL(KC_BSPC)
#define UNDO     LCTL(KC_Z)
#define COPY     LCTL(KC_C)
#define CUT      LCTL(KC_X)
#define PASTE    LCTL(KC_V)

enum layer_names {
    _BASE,
    _NAV,
    _MEDIA,
    _MOUSE,
    _FUNC,
    _NUM,
    _SYM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
      KC_Q,  KC_W,  KC_F,    KC_P,     KC_B,            KC_J,    KC_L,     KC_U,    KC_Y,   KC_QUOT,
      MT_A,  MT_R,  MT_S,    MT_T,     KC_G,            KC_M,    MT_N,     MT_E,    MT_I,   MT_O,
      KC_Z,  KC_X,  KC_C,    KC_D,     KC_V,            KC_K,    KC_H,     KC_COMM, KC_DOT, KC_SLSH,
                    LT_ESC,  LT_SPACE, LT_TAB,          LT_ENT,  LT_BSPC,  LT_DEL
     ),

    [_MEDIA] = LAYOUT_split_3x5_3(
      QK_BOOT, XXX,     XXX,     XXX,     XXX,         XXX,     XXX,     XXX,     XXX,     XXX,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,         XXX,     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
      XXX,     XXX,     XXX,     XXX,     XXX,         XXX,     XXX,     XXX,     XXX,     XXX,
                        XXX,     XXX,     XXX,         KC_MSTP, KC_MPLY, KC_MUTE
    ),

    [_NAV] = LAYOUT_split_3x5_3(
      XXX,     XXX,     XXX,     XXX,      XXX,        KC_AGIN, PASTE,    COPY,    CUT,     UNDO,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  XXX,        CW_TOGG, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,
      XXX,     XXX,     XXX,     XXX,      XXX,        KC_INS, KC_HOME,  KC_PGDN, KC_PGUP, KC_END,
                        XXX,     XXX,      XXX,        KC_ENT,  KC_BSPC,  KC_DEL
     ),

    [_MOUSE] = LAYOUT_split_3x5_3(
      XXX,     XXX,     XXX,     XXX,     XXX,         XXX,     XXX,     XXX,     XXX,     XXX,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,         XXX,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
      XXX,     XXX,     XXX,     XXX,     XXX,         XXX,     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                        XXX,     XXX,     XXX,         KC_BTN3, KC_BTN1, KC_BTN2
    ),

    [_SYM] = LAYOUT_split_3x5_3(
      KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_AMPR,        XXX, XXX,     XXX,     XXX,     XXX,
      KC_GRV,   KC_COLN, KC_LCBR, KC_LBRC, KC_CIRC,        XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_TILDE, KC_SCLN, KC_RCBR, KC_RBRC, KC_PIPE,        XXX, XXX,     XXX,     XXX,     XXX,
                         KC_LPRN, KC_RPRN, KC_UNDS,        XXX, XXX,     XXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
      XXX,     KC_7, KC_8,    KC_9, KC_PLUS,              XXX, XXX,     XXX,     XXX,     XXX,
      KC_ASTR, KC_4, KC_5,    KC_6, KC_EQL,               XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      XXX,     KC_1, KC_2,    KC_3, KC_BSLS,              XXX, XXX,     XXX,     XXX,     XXX,
                     KC_PERC, KC_0, KC_MINS,              XXX, XXX,     XXX
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
      KC_F12, KC_F7, KC_F8,  KC_F9,  KC_PSCR,           XXX, XXX,     XXX,     XXX,     XXX,
      KC_F11, KC_F4, KC_F5,  KC_F6,  KC_SCRL,           XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_F10, KC_F1, KC_F2,  KC_F3,  KC_PAUS,           XXX, XXX,     XXX,     XXX,     XXX,
                     KC_APP, KC_SPC, KC_TAB,            XXX, XXX,     XXX
    ),
};

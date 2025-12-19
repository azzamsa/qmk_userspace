#include QMK_KEYBOARD_H

// Layer aliases
#define XXX KC_NO
#define ___ KC_TRANSPARENT

#define LT_ESC  LT(_MEDIA, KC_ESC)
#define LT_R    LT(_NAV,   KC_R)
#define LT_ENT  LT(_MOUSE, KC_ENT)

#define LT_BSPC  LT(_SYM,  KC_BSPC)
#define LT_SPACE LT(_NUM,  KC_SPACE)
#define LT_TAB   LT(_FUNC, KC_TAB)

// Left-hand Mod-Tap aliases
#define MT_S LGUI_T(KC_S)
#define MT_N LALT_T(KC_N)
#define MT_T LCTL_T(KC_T)
#define MT_H LSFT_T(KC_H)

// Right-hand regular and Mod-Tap aliases
#define MT_A LSFT_T(KC_A)
#define MT_E LCTL_T(KC_E)
#define MT_I LALT_T(KC_I)
#define MT_C LGUI_T(KC_C)

// Other aliases
#define DL_WORD LCTL(KC_BSPC)
#define REDO    KC_AGIN
#define UNDO    LCTL(KC_Z)
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define PASTE   LCTL(KC_V)
#define SF_G    LSFT(KC_G)

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
      KC_F, KC_P, KC_D,   KC_L, KC_X,            KC_SCLN, KC_U,   KC_O,    KC_Y,   KC_B,
      MT_S, MT_N, MT_T,   MT_H, KC_K,            KC_COMM, MT_A,   MT_E,    MT_I,   MT_C,
      KC_V, KC_W, KC_G,   KC_M, KC_J,            KC_MINS, KC_DOT, KC_QUOT, KC_EQL, KC_SLSH,
                  LT_ESC, LT_R, LT_ENT,          LT_BSPC, LT_SPACE, LT_TAB
     ),

    [_MEDIA] = LAYOUT_split_3x5_3(
      QK_BOOT, KC_SYRQ, XXX,     XXX,     XXX,         XXX,     XXX,     XXX,     XXX,     XXX,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,         XXX,     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
      XXX,     XXX,     XXX,     XXX,     XXX,         XXX,     XXX,     XXX,     XXX,     XXX,
                        XXX,     XXX,     XXX,         KC_MSTP, KC_MPLY, KC_MUTE
    ),

    [_NAV] = LAYOUT_split_3x5_3(
      UNDO,    CUT,     COPY,    PASTE,    REDO,       REDO,    PASTE,    COPY,    CUT,     UNDO,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  XXX,        CW_TOGG, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,
      XXX,     XXX,     XXX,     XXX,      XXX,        KC_INS,  KC_HOME,  KC_PGDN, KC_PGUP, KC_END,
                        XXX,     XXX,      XXX,        KC_ENT,  KC_BSPC,  KC_DEL
     ),

    [_MOUSE] = LAYOUT_split_3x5_3(
      XXX,     XXX,     XXX,     XXX,     XXX,         XXX,     MS_BTN4, XXX,     XXX,     MS_BTN5,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,         XXX,     MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT,
      XXX,     XXX,     XXX,     XXX,     XXX,         XXX,     MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
                        XXX,     XXX,     XXX,         MS_BTN3, MS_BTN1, MS_BTN2
    ),

    [_SYM] = LAYOUT_split_3x5_3(
      KC_EXLM,  KC_LCBR, KC_RCBR, KC_DLR,  KC_PIPE,        XXX, XXX,     XXX,     XXX,     XXX,
      KC_GRV,   KC_LBRC, KC_RBRC, KC_CIRC, KC_ASTR,        XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_TILDE, KC_AMPR, KC_COLN, KC_PERC, KC_HASH,        XXX, XXX,     XXX,     XXX,     XXX,
                         KC_LPRN, KC_RPRN, KC_SCLN,        XXX, XXX,     XXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
      KC_PERC, KC_7, KC_8,    KC_9, KC_PLUS,           XXX, XXX,     XXX,     XXX,     XXX,
      KC_ASTR, KC_4, KC_5,    KC_6, KC_EQL,            XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_BSLS, KC_1, KC_2,    KC_3, KC_MINS,           XXX, XXX,     XXX,     XXX,     XXX,
                     KC_COMM, KC_0, KC_DOT,            XXX, XXX,     XXX
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
      KC_F12, KC_F7, KC_F8,  KC_F9,  KC_PSCR,           XXX, XXX,     XXX,     XXX,     XXX,
      KC_F11, KC_F4, KC_F5,  KC_F6,  KC_SCRL,           XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_F10, KC_F1, KC_F2,  KC_F3,  KC_PAUS,           XXX, XXX,     XXX,     XXX,     XXX,
                     KC_APP, KC_SPC, KC_TAB,            XXX, XXX,     XXX
    ),
};

// Combos
enum combo_events {
    Z,
    Q,

    DEL,
    AT,
};

// left
const uint16_t PROGMEM z_combo[]   = {KC_W,   KC_G,    COMBO_END};
const uint16_t PROGMEM q_combo[]   = {KC_G,   KC_M,    COMBO_END};

// right
const uint16_t PROGMEM del_combo[] = {KC_DOT,  KC_QUOT,  COMBO_END};
const uint16_t PROGMEM at_combo[]  = {KC_QUOT, KC_EQL,   COMBO_END};

combo_t key_combos[] = {
    [Z]    = COMBO(z_combo,    KC_Z),
    [Q]    = COMBO(q_combo,    KC_Q),

    [DEL]  = COMBO(del_combo, KC_DEL),
    [AT]   = COMBO(at_combo,  KC_AT),
};

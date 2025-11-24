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
#define MT_A LGUI_T(KC_A)
#define MT_R LALT_T(KC_R)
#define MT_S LCTL_T(KC_S)
#define MT_T LSFT_T(KC_T)

// Right-hand regular and Mod-Tap aliases
#define MT_N LSFT_T(KC_N)
#define MT_E LCTL_T(KC_E)
#define MT_I LALT_T(KC_I)
#define MT_O LGUI_T(KC_O)

//
// Night
//

#define NIGHT DF(_NIGHT)

#define LT1_ESC  LT(_MEDIA, KC_ESC)
#define LT1_R    LT(_NAV, KC_R)
#define LT1_BSPC LT(_MOUSE, KC_BSPC)

#define LT1_ENT   LT(_SYM, KC_ENT)
#define LT1_SPACE LT(_NUM, KC_SPACE)
#define LT1_TAB   LT(_FUNC, KC_TAB)

// Left-hand Mod-Tap aliases
#define MT1_N LGUI_T(KC_N)
#define MT1_S LALT_T(KC_S)
#define MT1_H LCTL_T(KC_H)
#define MT1_T LSFT_T(KC_T)

// Right-hand regular and Mod-Tap aliases
#define MT1_C LSFT_T(KC_C)
#define MT1_A LCTL_T(KC_A)
#define MT1_E LALT_T(KC_E)
#define MT1_I LGUI_T(KC_I)

// Other aliases
#define DL_WORD LCTL(KC_BSPC)
#define REDO KC_AGIN
#define UNDO LCTL(KC_Z)
#define COPY LCTL(KC_C)
#define CUT LCTL(KC_X)
#define PASTE LCTL(KC_V)
#define SF_G LSFT_T(KC_G)

enum layer_names {
    _BASE,
    _NIGHT,
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

    [_NIGHT] = LAYOUT_split_3x5_3(
      KC_B,  KC_F,  KC_L,    KC_K,     KC_Q,            KC_P,    KC_G,      KC_O,    KC_U,    KC_DOT,
      MT1_N, MT1_S, MT1_H,   MT1_T,    KC_M,            KC_Y,    MT1_C,     MT1_A,   MT1_E,   MT1_I,
      KC_X,  KC_V,  KC_J,    KC_D,     KC_Z,            KC_QUOT, KC_W,      KC_SLSH, KC_SCLN, KC_COMM,
                    LT1_ESC, LT1_R,    LT1_BSPC,        LT1_ENT, LT1_SPACE, LT1_TAB
      
     ),

    [_MEDIA] = LAYOUT_split_3x5_3(
      QK_BOOT, KC_SYRQ, NIGHT,   XXX,     XXX,         XXX,     XXX,     XXX,     XXX,     XXX,
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
      KC_EXLM,  KC_LCBR, KC_RCBR, KC_HASH, KC_AMPR,        XXX, XXX,     XXX,     XXX,     XXX,
      KC_SCLN,  KC_CIRC, KC_UNDS, KC_DLR,  KC_ASTR,        XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_TILDE, KC_PIPE, KC_MINS, KC_PERC, KC_PLUS,        XXX, XXX,     XXX,     XXX,     XXX,
                         KC_LPRN, KC_RPRN, KC_AT,          XXX, XXX,     XXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
      KC_LBRC, KC_7, KC_8,   KC_9, KC_RBRC,              SF_G, XXX,     XXX,     XXX,     XXX,
      KC_COLN, KC_4, KC_5,   KC_6, KC_EQL,               KC_K, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_GRV,  KC_1, KC_2,   KC_3, KC_BSLS,              KC_J, XXX,     XXX,     XXX,     XXX,
                     KC_DOT, KC_0, KC_COMM,              XXX,  XXX,     XXX
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
      KC_F12, KC_F7, KC_F8,  KC_F9,  KC_PSCR,           XXX, XXX,     XXX,     XXX,     XXX,
      KC_F11, KC_F4, KC_F5,  KC_F6,  KC_SCRL,           XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_F10, KC_F1, KC_F2,  KC_F3,  KC_PAUS,           XXX, XXX,     XXX,     XXX,     XXX,
                     KC_APP, KC_SPC, KC_TAB,            XXX, XXX,     XXX
    ),
};

//
// Combos
enum combo_events {
    DEL,
};

const uint16_t PROGMEM del_combo[]    = {KC_W, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
    [DEL]    = COMBO(del_combo, KC_DEL),
};

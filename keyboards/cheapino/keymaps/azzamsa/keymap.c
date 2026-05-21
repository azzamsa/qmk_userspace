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

#define LT_V     LT(_BTN, KC_V)
#define LT_J     LT(_BTN, KC_J)

// Left-hand Mod-Tap aliases
#define MT_T LGUI_T(KC_T)
#define MT_S LALT_T(KC_S)
#define MT_N LCTL_T(KC_N)
#define MT_H LSFT_T(KC_H)

// Right-hand regular and Mod-Tap aliases
#define MT_C LSFT_T(KC_C)
#define MT_A LCTL_T(KC_A)
#define MT_I LALT_T(KC_I)
#define MT_E LGUI_T(KC_E)

// Other aliases
#define REDO    LCTL(LSFT(KC_Z))
#define UNDO    LCTL(KC_Z)
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define PASTE   LCTL(KC_V)

enum layer_names {
    _BASE,
    _NAV,
    _MEDIA,
    _MOUSE,
    _FUNC,
    _NUM,
    _SYM,
    _BTN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        XXX,  KC_L, KC_P,   KC_D, KC_F,    KC_QUOT, KC_W,     KC_O,    KC_U,   XXX,
        MT_T, MT_S, MT_N,   MT_H, KC_M,    KC_G,    MT_C,     MT_A,    MT_I,   MT_E,
        LT_V, KC_Z, KC_B,   KC_K, KC_Q,    KC_X,    KC_Y,     KC_COMM, KC_DOT, LT_J,
                    LT_ESC, LT_R, LT_ENT,  LT_BSPC, LT_SPACE, LT_TAB
    ),

    [_MEDIA] = LAYOUT_split_3x5_3(
        XXX,     XXX,     XXX,     XXX,     XXX,    XXX,     XXX,     KC_VOLU, XXX,     XXX,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,    XXX,     KC_MPRV, KC_VOLD, KC_MNXT, XXX,
        QK_BOOT, KC_SYRQ, XXX,     XXX,     XXX,    XXX,     XXX,     XXX,     XXX,     XXX,
                          XXX,     XXX,     XXX,    KC_MSTP, KC_MPLY, KC_MUTE
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        XXX,     XXX,     XXX,     XXX,      XXX,    KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXX,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  XXX,    KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_CAPS,
        XXX,     XXX,     XXX,     XXX,      XXX,    REDO,    PASTE,   COPY,    CUT,     UNDO,
                          XXX,     XXX,      XXX,    XXX,     XXX,     KC_DEL
    ),

    [_MOUSE] = LAYOUT_split_3x5_3(
        XXX,     XXX,     XXX,     XXX,     XXX,    MS_WHLU, MS_WHLL, MS_UP,   MS_WHLR, XXX,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,    MS_WHLD, MS_LEFT, MS_DOWN, MS_RGHT, XXX,
        XXX,     XXX,     XXX,     XXX,     XXX,    XXX,     MS_BTN4, XXX,     MS_BTN5, XXX,
                          XXX,     XXX,     XXX,    MS_BTN3, MS_BTN1, MS_BTN2
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        XXX,      KC_LCBR, KC_RCBR, KC_DLR,  KC_PIPE,    XXX, XXX,     XXX,     XXX,     XXX,
        KC_GRV,   KC_LBRC, KC_RBRC, KC_CIRC, KC_ASTR,    XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_TILDE, KC_EXLM, KC_BSLS, KC_AMPR, KC_HASH,    XXX, XXX,     XXX,     XXX,     XXX,
                           KC_LPRN, KC_RPRN, KC_SCLN,    XXX, XXX,     XXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        XXX,     KC_7, KC_8,    KC_9,    KC_PLUS,    XXX, XXX,     XXX,     XXX,     XXX,
        KC_0,    KC_4, KC_5,    KC_6,    KC_EQL,     XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_PERC, KC_1, KC_2,    KC_3,    KC_LT,      XXX, XXX,     XXX,     XXX,     XXX,
                       KC_UNDS, KC_MINS, KC_GT,      XXX, XXX,     XXX
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
        XXX,    KC_F7, KC_F8,   KC_F9,   KC_PSCR,    XXX, XXX,     XXX,     XXX,     XXX,
        KC_F11, KC_F4, KC_F5,   KC_F6,   KC_APP,     XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_F10, KC_F1, KC_F2,   KC_F3,   KC_INS,     XXX, XXX,     XXX,     XXX,     XXX,
                       KC_QUES, KC_SLSH, KC_COLN,    XXX, XXX,     XXX
    ),

    [_BTN] = LAYOUT_split_3x5_3(
        XXX,  XXX,   XXX,  XXX,   XXX,     XXX,  XXX,   XXX,  XXX, XXX,
        XXX,  KC_AT, XXX,  XXX,   XXX,     XXX,  XXX,   XXX,  XXX, XXX,
        REDO, CUT,   COPY, PASTE, UNDO,    UNDO, PASTE, COPY, CUT, REDO,
                     XXX,  XXX,   XXX,     XXX,  XXX,   XXX
    ),
};

// Combos
enum combo_events {
    // Both
    CW,
};

const uint16_t PROGMEM cw_combo[]   = {MT_H,    MT_C,    COMBO_END};

combo_t key_combos[] = {
    [CW]    = COMBO_ACTION(cw_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case CW: // Caps Word
        if (pressed) caps_word_on();
        break;
    }
}

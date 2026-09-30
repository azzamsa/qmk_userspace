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
#define MT_N LGUI_T(KC_N)
#define MT_S LALT_T(KC_S)
#define MT_H LCTL_T(KC_H)
#define MT_T LSFT_T(KC_T)

// Right-hand regular and Mod-Tap aliases
#define MT_C LSFT_T(KC_C)
#define MT_A LCTL_T(KC_A)
#define MT_E LALT_T(KC_E)
#define MT_I LGUI_T(KC_I)

// Other aliases
#define REDO    LCTL(LSFT(KC_Z))
#define UNDO    LCTL(KC_Z)
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
// KC_PASTE doesn't work reliably in some apps.
#define PASTE   LCTL(KC_V)
#define SELALL  LCTL(KC_A)

#define BASE  TG(_BASE)
#define GAME  TG(_GAME)
#define LT_T_GAME LT(_GAME_MIROR, KC_T)
#define LT_G_GAME LT(_GAME_NUM,   KC_G)
#define LT_B_GAME LT(_GAME_FUNC,  KC_B)

enum layer_names {
    _BASE,
    _NAV,
    _MEDIA,
    _MOUSE,
    _FUNC,
    _NUM,
    _SYM,
    // Game layers
    _GAME,
    _GAME_NUM,
    _GAME_FUNC,
    _GAME_MIROR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_X, KC_F, KC_L,   KC_K, KC_Q,        KC_P,    KC_G,     KC_O,    KC_U,    KC_DOT,
        MT_N, MT_S, MT_H,   MT_T, KC_M,        KC_Y,    MT_C,     MT_A,    MT_E,    MT_I,
        KC_B, KC_V, KC_J,   KC_D, KC_Z,        KC_QUOT, KC_W,     KC_SLSH, KC_SCLN, KC_COMMA,
                    LT_ESC, LT_R, LT_ENT,      LT_BSPC, LT_SPACE, LT_TAB
    ),
    // Media and mouse operation
    [_MEDIA] = LAYOUT_split_3x5_3(
        QK_BOOT, CUT,     COPY,    PASTE,   XXX,       XXX,     XXX,     XXX,     XXX,     XXX,
        MS_BTN4, MS_BTN1, MS_BTN3, MS_BTN2, XXX,       GAME,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        MS_BTN5, XXX,     XXX,     MS_BTN4, XXX,       XXX,     XXX,     XXX,     XXX,     XXX,
                          XXX,     XXX,     XXX,       KC_MSTP, KC_MPLY, KC_MUTE
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        UNDO,    CUT,     COPY,    PASTE,    REDO,       REDO,    PASTE,   COPY,    CUT,     UNDO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  XXX,        CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        XXX,     XXX,     XXX,     XXX,      XXX,        KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                          XXX,     XXX,      XXX,        XXX,     XXX,     KC_DEL
    ),

    [_MOUSE] = LAYOUT_split_3x5_3(
       UNDO,    CUT,     COPY,    PASTE,   REDO,    XXX,     MS_BTN4, XXX,     XXX,     MS_BTN5,
       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,     XXX,     MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT,
       XXX,     MS_ACL2, MS_ACL1, MS_ACL0, XXX,     XXX,     MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
                         XXX,     XXX,     XXX,     MS_BTN2, MS_BTN1, MS_BTN3
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        KC_HASH, KC_LPRN, KC_RPRN, KC_ASTR, KC_GRV,         XXX, KC_AT,   KC_BSLS, XXX,     XXX,
        KC_CIRC, KC_EXLM, KC_AMPR, KC_DLR,  KC_TILD,        XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_PIPE,        XXX, XXX,     XXX,     XXX,     XXX,
                          KC_UNDS, KC_EQL,  KC_PERC,        XXX, XXX,     XXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        KC_PLUS, KC_7, KC_8,    KC_9, KC_ASTR,          XXX, XXX,     XXX,     XXX,     XXX,
        KC_MINS, KC_4, KC_5,    KC_6, KC_EQL,           XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_UNDS, KC_1, KC_2,    KC_3, KC_BSLS,          XXX, XXX,     XXX,     XXX,     XXX,
                       KC_SLSH, KC_0, KC_PERC,          XXX, XXX,     XXX
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR,    XXX, XXX,     XXX,     XXX,     XXX,
        KC_F11, KC_F4, KC_F5, KC_F6, XXX,        XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_F10, KC_F1, KC_F2, KC_F3, XXX,        XXX, XXX,     XXX,     XXX,     XXX,
                       XXX,   XXX,   XXX,        XXX, XXX,     XXX
    ),

    [_GAME] = LAYOUT_split_3x5_3(
        LT_T_GAME, KC_Q, KC_W,    KC_E,   KC_R,           KC_Y,    KC_U,     KC_I,     KC_O,   KC_P,
        LT_G_GAME, KC_A, KC_S,    KC_D,   KC_F,           KC_H,    KC_J,     KC_K,     KC_L,   KC_SCLN,
        LT_B_GAME, KC_Z, KC_X,    KC_C,   KC_V,           KC_N,    KC_M,     KC_COMMA, KC_DOT, KC_SLASH,
                         KC_LCTL, KC_SPC, KC_LSFT,        KC_BSPC, KC_SPACE, KC_TAB
    ),

    [_GAME_NUM] = LAYOUT_split_3x5_3(
        KC_ESC, KC_7, KC_8, KC_9, KC_BSPC,           XXX, XXX,     XXX,     XXX,     XXX,
        XXX,    KC_4, KC_5, KC_6, KC_TAB,            XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        XXX,    KC_1, KC_2, KC_3, KC_PSCR,           XXX, XXX,     XXX,     XXX,     XXX,
                      KC_3, KC_1, KC_2,              XXX, XXX,     XXX
    ),

    [_GAME_FUNC] = LAYOUT_split_3x5_3(
        GAME, KC_F7,   KC_F8,  KC_F9,   KC_F12,        XXX, XXX,     XXX,     XXX,     XXX,
        XXX,  KC_F4,   KC_F5,  KC_F6,   KC_F11,        XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        XXX,  KC_LGUI, KC_ENT, KC_LALT, KC_F10,        XXX, XXX,     XXX,     XXX,     XXX,
                       KC_F3,  KC_F1,   KC_F2,         XXX, XXX,     XXX
    ),

    [_GAME_MIROR] = LAYOUT_split_3x5_3(
        XXX,  KC_U, KC_I, KC_O,    KC_P,       XXX, XXX, XXX, XXX, XXX,
        KC_H, KC_J, KC_K, KC_L,    KC_Y,       XXX, XXX, XXX, XXX, XXX,
        KC_N, KC_M, XXX,  XXX,     XXX,        XXX, XXX, XXX, XXX, XXX,
                    XXX,  KC_PSCR, XXX,        XXX, XXX, XXX
    ),
};

// shift functions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == CW_TOGG && record->event.pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
            tap_code(KC_CAPS);   // Shift + CW_TOGG = real Caps Lock
            return false;        // don't toggle Caps Word
        }
    }
    return true;
}

// Combos
enum combo_events {
    PSCR,

    SPC,
    DEL,
};

const uint16_t PROGMEM pscr_combo[]  = {KC_L,    KC_K,    COMBO_END};

const uint16_t PROGMEM del_combo[]   = {KC_V,    KC_J,    COMBO_END};
const uint16_t PROGMEM spc_combo[]   = {KC_J,    KC_D,    COMBO_END};

combo_t key_combos[] = {
    [PSCR]  = COMBO(pscr_combo, KC_PSCR),

    [DEL]  = COMBO(del_combo, KC_DEL),
    [SPC]  = COMBO(spc_combo, KC_SPC),
};

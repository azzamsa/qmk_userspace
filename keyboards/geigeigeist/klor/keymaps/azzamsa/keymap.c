#include QMK_KEYBOARD_H

// Layer aliases
#define XXX KC_NO
#define ___ KC_TRANSPARENT

#define LT_DEL  LT(_BTN, KC_DEL)
#define LT_ESC  LT(_MEDIA, KC_ESC)
#define LT_R    LT(_NAV,   KC_R)
#define LT_ENT  LT(_MOUSE, KC_ENT)

#define LT_BSPC  LT(_SYM,  KC_BSPC)
#define LT_SPACE LT(_NUM,  KC_SPACE)
#define LT_TAB   LT(_FUNC, KC_TAB)
#define LT_DEL   LT(_BTN, KC_DEL)

#define LT_J     LT(_BTN, KC_J)
#define LT_SCLN  LT(_BTN, KC_SCLN)

// Left-hand Mod-Tap aliases (same roles/order as klor: GUI, ALT, CTL, SFT)
#define MT_N LGUI_T(KC_N)
#define MT_S LALT_T(KC_S)
#define MT_H LCTL_T(KC_H)
#define MT_T LSFT_T(KC_T)

// Right-hand regular and Mod-Tap aliases (same roles/order as klor: plain, SFT, CTL, ALT, GUI)
#define MT_C LSFT_T(KC_C)
#define MT_A LCTL_T(KC_A)
#define MT_E LALT_T(KC_E)
#define MT_I LGUI_T(KC_I)

// Other aliases
// KC_PASTE doesn't work realibly on some apps.
#define REDO    LCTL(LSFT(KC_Z))
#define UNDO    LCTL(KC_Z)
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define PASTE   LCTL(KC_V)
#define SELALL  LCTL(KC_A)

// Game layer
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
    _BTN,
    // Game layers
    _GAME,
    _GAME_NUM,
    _GAME_FUNC,
    _GAME_MIROR,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
             KC_X, KC_F, KC_L, KC_K,   KC_Q,                         KC_P,     KC_G,   KC_O,    KC_U,    KC_DOT,
        XXX, MT_N, MT_S, MT_H, MT_T,   KC_M,                         KC_Y,     MT_C,   MT_A,    MT_E,    MT_I,     XXX,
        XXX, KC_B, KC_V, LT_J, KC_D,   KC_Z, XXX,           XXX,     KC_QUOT,  KC_W,   LT_SCLN, KC_SLSH, KC_COMMA, XXX,
                         XXX,  LT_ESC, LT_R, LT_ENT,        LT_BSPC, LT_SPACE, LT_TAB, XXX
    ),

    [_MEDIA] = LAYOUT(
             GAME,    XXX,     XXX,     XXX,     XXX,                      XXX,     XXX,     XXX,     XXX,     XXX,
        XXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,                      XXX,     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXX,
        XXX, QK_BOOT, KC_SYRQ, XXX,     XXX,     XXX, XXX,        XXX,     XXX,     XXX,     XXX,     XXX,     XXX,     XXX,
                               XXX,     XXX,     XXX, XXX,        KC_MSTP, KC_MPLY, KC_MUTE, XXX
    ),

    [_NAV] = LAYOUT(
             XXX,     XXX,     XXX,     XXX,     XXX,                  KC_PSCR, QK_REP,  XXX,     XXX,     XXX,
        XXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,                  CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXX,
        XXX, XXX,     XXX,     XXX,     XXX,     XXX, XXX,        XXX, KC_CAPS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXX,
                               XXX,     XXX,     XXX, XXX,        XXX, XXX,     XXX,     XXX
    ),

    [_MOUSE] = LAYOUT(
             XXX,     XXX,     XXX,     XXX,     XXX,                  XXX,     MS_BTN4, XXX,     XXX,     MS_BTN5,
        XXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,                  XXX,     MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXX,
        XXX, XXX,     XXX,     XXX,     XXX,     XXX, XXX,    XXX,     XXX,     MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR, XXX,
                               XXX,     XXX,     XXX, XXX,    MS_BTN3, MS_BTN1, MS_BTN2, XXX
    ),

    [_SYM] = LAYOUT(
             KC_HASH, KC_LPRN, KC_RPRN, KC_ASTR, KC_GRV,                      XXX, XXX,     XXX,     XXX,     XXX,
        XXX, KC_CIRC, KC_EXLM, KC_AMPR, KC_DLR,  KC_TILD,                     XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, KC_PIPE, XXX,           XXX, XXX, XXX,     XXX,     XXX,     XXX,     XXX,
                               XXX,     KC_UNDS, KC_EQL, KC_PERC,        XXX, XXX, XXX,     XXX
    ),

    [_NUM] = LAYOUT(
             KC_PLUS, KC_7, KC_8, KC_9,    KC_AT,                     XXX, XXX,     XXX,     XXX,     XXX,
        XXX, KC_UNDS, KC_4, KC_5, KC_6,    KC_ASTR,                   XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, KC_MINS, KC_1, KC_2, KC_3,    KC_BSLS, XXX,         XXX, XXX, XXX,     XXX,     XXX,     XXX,     XXX,
                            XXX,  KC_SLSH, KC_0,    KC_EQL,      XXX, XXX, XXX,     XXX
    ),

    [_FUNC] = LAYOUT(
             KC_F12, KC_F7, KC_F8, KC_F9, XXX,                  XXX, XXX,     XXX,     XXX,     XXX,
        XXX, KC_F11, KC_F4, KC_F5, KC_F6, XXX,                  XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, KC_F10, KC_F1, KC_F2, KC_F3, XXX, XXX,        XXX, XXX, XXX,     XXX,     XXX,     XXX,     XXX,
                            XXX,   XXX,   XXX, XXX,        XXX, XXX, XXX,     XXX
    ),

    [_BTN] = LAYOUT(
             XXX,     XXX,    XXX,     XXX,     XXX,                   XXX,  XXX,     XXX,    XXX,     XXX,
        XXX, REDO,    PASTE,  COPY,    CUT,     UNDO,                  REDO, PASTE,   COPY,   CUT,     UNDO,    XXX,
        XXX, SELWBAK, SELALL, SELLINE, SELWORD, XXX,  XXX,        XXX, XXX,  SELWBAK, SELALL, SELLINE, SELWORD, XXX,
                              XXX,     KC_DEL,  XXX,  XXX,        XXX, XXX,  KC_DEL,  XXX
    ),

    [_GAME] = LAYOUT(
             LT_T_GAME, KC_Q, KC_W, KC_E,    KC_R,                            KC_Y,     KC_U,   KC_I,     KC_O,   KC_P,
        XXX, LT_G_GAME, KC_A, KC_S, KC_D,    KC_F,                            KC_H,     KC_J,   KC_K,     KC_L,   KC_SCLN,  XXX,
        XXX, LT_B_GAME, KC_Z, KC_X, KC_C,    KC_V,   XXX,            XXX,     KC_N,     KC_M,   KC_COMMA, KC_DOT, KC_SLASH, XXX,
                              XXX,  KC_LCTL, KC_SPC, KC_LSFT,        KC_BSPC, KC_SPACE, KC_TAB, KC_DEL
    ),

    [_GAME_NUM] = LAYOUT(
             KC_ESC, KC_7, KC_8, KC_9, KC_BSPC,                   XXX, XXX,     XXX,     XXX,     XXX,
        XXX, XXX,    KC_4, KC_5, KC_6, KC_TAB,                    XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, XXX,    KC_1, KC_2, KC_3, KC_PSCR, XXX,         XXX, XXX, XXX,     XXX,     XXX,     XXX,     XXX,
                           XXX,  KC_3, KC_1,    KC_2,        XXX, XXX, XXX,     XXX
    ),

    [_GAME_FUNC] = LAYOUT(
             GAME, KC_F7,   KC_F8,  KC_F9,   KC_F12,                    XXX, XXX,     XXX,     XXX,     XXX,
        XXX, XXX,  KC_F4,   KC_F5,  KC_F6,   KC_F11,                    XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, XXX,  KC_LGUI, KC_ENT, KC_LALT, KC_F10, XXX,          XXX, XXX, XXX,     XXX,     XXX,     XXX,     XXX,
                            XXX,    KC_F3,   KC_F1,  KC_F2,        XXX, XXX, XXX,     XXX
    ),

    [_GAME_MIROR] = LAYOUT(
             XXX,  KC_U, KC_I, KC_O,    KC_P,                   XXX, XXX,     XXX,     XXX,     XXX,
        XXX, KC_H, KC_J, KC_K, KC_L,    KC_Y,                   XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, KC_N, KC_M, XXX,  XXX,     XXX, XXX,          XXX, XXX, XXX,     XXX,     XXX,     XXX,     XXX,
                         XXX,  XXX, KC_PSCR, XXX,          XXX, XXX, XXX,     XXX
    ),
};

// Combos
enum combo_events {
    CAPS
};

const uint16_t PROGMEM caps_combo[] = {KC_D,    KC_W,    COMBO_END};

combo_t key_combos[] = {
    [CAPS] = COMBO(caps_combo, CW_TOGG),
};

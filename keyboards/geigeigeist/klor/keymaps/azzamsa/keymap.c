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
#define LT_SLSH  LT(_BTN, KC_SLSH)

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
#define TIMES   LSFT(KC_X)

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
             KC_X, KC_F, KC_L,   KC_D,   KC_Q,                         KC_P,     KC_G,   KC_O,    KC_U,    KC_DOT,
        XXX, MT_N, MT_S, MT_H,   MT_T,   KC_M,                         KC_Y,     MT_C,   MT_A,    MT_E,    MT_I,    XXX,
        XXX, KC_B, KC_V, LT_J,   KC_K,   KC_Z, XXX,           XXX,     KC_QUOT,  KC_W,   LT_SLSH, KC_SCLN, KC_COMMA, XXX,
                         KC_DEL, LT_ESC, LT_R, LT_ENT,        LT_BSPC, LT_SPACE, LT_TAB, KC_DEL
    ),

    [_MEDIA] = LAYOUT(
             GAME,    XXX,     XXX,     XXX,     XXX,                      XXX,     XXX,     KC_VOLU, XXX,     XXX,
        XXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,                      XXX,     KC_MPRV, KC_VOLD, KC_MNXT, XXX, XXX,
        XXX, QK_BOOT, KC_SYRQ, XXX,     XXX,     XXX, XXX,        XXX,     XXX,     XXX,     XXX,     XXX,     XXX, XXX,
                               XXX,     XXX,     XXX, XXX,        KC_MSTP, KC_MPLY, KC_MUTE, XXX
    ),

    [_NAV] = LAYOUT(
             XXX,     XXX,     XXX,     XXX,     XXX,                  KC_CAPS, KC_HOME, KC_UP,   KC_END,  KC_PSCR,
        XXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,                  CW_TOGG, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP, XXX,
        XXX, XXX,     XXX,     XXX,     XXX,     XXX, XXX,        XXX, KC_INS,  SELWBAK, SELLINE, SELWORD, KC_PGDN, XXX,
                               XXX,     XXX,     XXX, XXX,        XXX, XXX,     XXX,     KC_DEL
    ),

    [_MOUSE] = LAYOUT(
             XXX, XXX,     OM_FAST, XXX,     XXX,                      XXX,     OM_BTN4, OM_U,    OM_BTN5, XXX,
        XXX, XXX, OM_HLDS, OM_SLOW, OM_RELS, XXX,                      XXX,     OM_L,    OM_D,    OM_R,    OM_W_U,  XXX,
        XXX, XXX, XXX,     XXX,     XXX,     XXX, XXX,        XXX,     XXX,     OM_W_L,  OM_DBLS, OM_W_R,  OM_W_D,  XXX,
                           XXX,     XXX,     XXX, XXX,        OM_SEL2, OM_BTN1, OM_BTN3, XXX
    ),

    [_SYM] = LAYOUT(
             KC_LBRC, KC_HASH, KC_EXLM, KC_ASTR, KC_RBRC,                      XXX, XXX,     XXX,     XXX,     XXX,
        XXX, KC_MINS, KC_CIRC, KC_AMPR, KC_DLR,  KC_EQL,                       XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, KC_UNDS, KC_LCBR, KC_TILD, KC_RCBR, KC_AT,   XXX,            XXX, XXX, XXX,     XXX,     XXX,     XXX,     XXX,
                               XXX,     KC_LPRN, KC_RPRN, KC_PERC,        XXX, XXX, XXX,     XXX
    ),

    [_NUM] = LAYOUT(
             KC_BSLS, KC_7, KC_8, KC_9,    KC_PLUS,                    XXX, XXX,     XXX,     XXX,     XXX,
        XXX, KC_GRV,  KC_4, KC_5, KC_6,    KC_EQL,                     XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, KC_PIPE, KC_1, KC_2, KC_3,    KC_MINS, XXX,          XXX, XXX, XXX,     XXX,     XXX,     XXX,     XXX,
                            XXX,  KC_SLSH, KC_0,    TIMES,        XXX, XXX, XXX,     XXX
    ),

    [_FUNC] = LAYOUT(
             KC_F12, KC_F7, KC_F8, KC_F9, XXX,                  XXX, XXX,     XXX,     XXX,     XXX,
        XXX, KC_F11, KC_F4, KC_F5, KC_F6, XXX,                  XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, KC_F10, KC_F1, KC_F2, KC_F3, XXX, XXX,        XXX, XXX, XXX,     XXX,     XXX,     XXX,     XXX,
                            XXX,   XXX,   XXX, XXX,        XXX, XXX, XXX,     XXX
    ),

    [_BTN] = LAYOUT(
             UNDO,    CUT,     COPY,    PASTE,   REDO,                  REDO, PASTE,   COPY,    CUT,     UNDO,
        XXX, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,                   XXX,  KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXX,
        XXX, UNDO,    CUT,     COPY,    PASTE,   REDO, XXX,        XXX, REDO, PASTE,   COPY,    CUT,     UNDO,    XXX,
                               XXX,     KC_DEL,  XXX,  XXX,        XXX, XXX,  KC_DEL,  XXX
    ),

    [_GAME] = LAYOUT(
             LT_T_GAME, KC_Q, KC_W, KC_E,    KC_R,                            KC_Y,    KC_U,     KC_I,     KC_O,   KC_P,
        XXX, LT_G_GAME, KC_A, KC_S, KC_D,    KC_F,                            KC_H,    KC_J,     KC_K,     KC_L,   KC_SCLN, XXX,
        XXX, LT_B_GAME, KC_Z, KC_X, KC_C,    KC_V,   XXX,            XXX,     KC_N,    KC_M,     KC_COMMA, KC_DOT, KC_SLASH, XXX,
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

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

#define LT_B     LT(_BTN, KC_B)
#define LT_COMMA LT(_BTN, KC_COMMA)

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
#define PASTE   LCTL(KC_V)
#define TIMES   LSFT(KC_X)

// Game layer
#define BASE  TG(_BASE)
#define GAME  TG(_GAME)
#define LT_G_GAME LT(_GAME_NUM,  KC_G)
#define LT_B_GAME LT(_GAME_FUNC, KC_B)

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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // comma, dot, and quote are most used symbols.
    [_BASE] = LAYOUT_split_3x5_3(
        KC_X, KC_F, KC_L,   KC_D, KC_Q,        KC_P,    KC_G,     KC_O,    KC_U,    KC_DOT,
        MT_N, MT_S, MT_H,   MT_T, KC_M,        KC_Y,    MT_C,     MT_A,    MT_E,    MT_I,
        LT_B, KC_V, KC_J,   KC_K, KC_Z,        KC_QUOT, KC_W,     KC_SLSH, KC_SCLN, LT_COMMA,
                    LT_ESC, LT_R, LT_ENT,      LT_BSPC, LT_SPACE, LT_TAB
    ),

    [_MEDIA] = LAYOUT_split_3x5_3(
        GAME,    XXX,     XXX,     XXX,     XXX,       XXX,     XXX,     XXX,     XXX,     XXX,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,       XXX,     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        QK_BOOT, KC_SYRQ, XXX,     XXX,     XXX,       XXX,     XXX,     XXX,     XXX,     XXX,
                          XXX,     XXX,     XXX,       KC_MSTP, KC_MPLY, KC_MUTE
    ),

    // Arrow keys are better on home row. This reduces finger travel significantly.
    // As I rely on them instead of hjkl.
    // Inverted-T also places `pgdn` and `pgup` on hard to reach or awkward positions.
    [_NAV] = LAYOUT_split_3x5_3(
        XXX,     XXX,     XXX,     XXX,      XXX,        REDO,    PASTE,   COPY,    CUT,     UNDO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  XXX,        CW_TOGG, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        XXX,     XXX,     XXX,     XXX,      XXX,        XXX,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                          XXX,     XXX,      XXX,        XXX,     XXX,     KC_DEL
    ),

    // `BTN4` / `BTN5` is miroring `UNDO` / `REDO`.
    [_MOUSE] = LAYOUT_split_3x5_3(
        XXX,     XXX,     XXX,     XXX,     XXX,        XXX,     MS_BTN5, XXX,     XXX,     MS_BTN4,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,        XXX,     MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT,
        XXX,     XXX,     XXX,     XXX,     XXX,        XXX,     MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
                          XXX,     XXX,     XXX,        MS_BTN3, MS_BTN1, MS_BTN2
    ),

    // Bigrams: `()`, `[]`, `{}`
    // Vim pairs `^ $`, `# *`
    [_SYM] = LAYOUT_split_3x5_3(
        KC_GRV,  KC_LCBR, KC_RCBR, KC_EXLM, KC_PIPE,        XXX, XXX,     XXX,     XXX,     XXX,
        KC_MINS, KC_LBRC, KC_RBRC, KC_AMPR, KC_TILD,        XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_CIRC, KC_HASH, KC_ASTR, KC_DLR,  KC_AT,          XXX, XXX,     XXX,     XXX,     XXX,
                          KC_LPRN, KC_PERC, KC_RPRN,        XXX, XXX,     XXX
    ),

    // mirrors `_`
    // Pairs: `+ -`, `/ *`
    [_NUM] = LAYOUT_split_3x5_3(
        KC_PLUS, KC_7, KC_8,    KC_9, KC_BSLS,        XXX, XXX,     XXX,     XXX,     XXX,
        KC_UNDS, KC_4, KC_5,    KC_6, KC_EQL,         XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_MINS, KC_1, KC_2,    KC_3, TIMES,          XXX, XXX,     XXX,     XXX,     XXX,
                       KC_SLSH, KC_0, KC_ASTR,        XXX, XXX,     XXX
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
        KC_F12, KC_F7, KC_F8, KC_F9, KC_CAPS,        XXX, XXX,     XXX,     XXX,     XXX,
        KC_F11, KC_F4, KC_F5, KC_F6, KC_PSCR,        XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        KC_F10, KC_F1, KC_F2, KC_F3, KC_INS,         XXX, XXX,     XXX,     XXX,     XXX,
                       XXX,   XXX,   XXX,            XXX, XXX,     XXX
    ),

    [_BTN] = LAYOUT_split_3x5_3(
        XXX,  XXX,   XXX,  XXX,     XXX,         XXX,  XXX,   XXX,     XXX,     XXX,
        XXX,  XXX,   XXX,  XXX,     XXX,         XXX,  XXX,   KC_MINS, KC_PLUS, XXX,
        UNDO, CUT,   COPY, PASTE,   REDO,        REDO, PASTE, COPY,    CUT,     UNDO,
                     XXX,  XXX,     XXX,         XXX,  XXX,   XXX
    ),

    [_GAME] = LAYOUT_split_3x5_3(
        KC_T,      KC_Q, KC_W,    KC_E,   KC_R,           XXX, XXX, XXX, XXX, XXX,
        LT_G_GAME, KC_A, KC_S,    KC_D,   KC_F,           XXX, XXX, XXX, XXX, XXX,
        LT_B_GAME, KC_Z, KC_X,    KC_C,   KC_V,           XXX, XXX, XXX, XXX, XXX,
                         KC_LCTL, KC_SPC, KC_LSFT,        XXX, XXX, XXX
    ),

    [_GAME_NUM] = LAYOUT_split_3x5_3(
        XXX, KC_7, KC_8,   KC_9, XXX,           XXX, XXX,     XXX,     XXX,     XXX,
        XXX, KC_4, KC_5,   KC_6, XXX,           XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
        XXX, KC_1, KC_2,   KC_3, XXX,           XXX, XXX,     XXX,     XXX,     XXX,
                   KC_ENT, KC_0, KC_TAB,        XXX, XXX,     XXX
     ),

     [_GAME_FUNC] = LAYOUT_split_3x5_3(
         GAME, KC_F7, KC_F8,   KC_F9,   KC_F12,        XXX, XXX,     XXX,     XXX,     XXX,
         XXX,  KC_F4, KC_F5,   KC_F6,   KC_F11,        XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
         XXX,  KC_F1, KC_F2,   KC_F3,   KC_F10,        XXX, XXX,     XXX,     XXX,     XXX,
                      KC_LGUI, KC_PSCR, KC_BSPC,       XXX, XXX,     XXX
      ),
};

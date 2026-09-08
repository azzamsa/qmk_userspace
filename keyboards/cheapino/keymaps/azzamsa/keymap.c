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

#define LT_J     LT(_BTN, KC_J)
#define LT_SLSH  LT(_BTN, KC_SLSH)

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
    // comma, dot, and quote are most used symbols.
    [_BASE] = LAYOUT_split_3x5_3(
        KC_X, KC_F, KC_L,   KC_D, KC_Q,        KC_P,    KC_G,     KC_O,    KC_U,    KC_DOT,
        MT_N, MT_S, MT_H,   MT_T, KC_M,        KC_Y,    MT_C,     MT_A,    MT_E,    MT_I,
        KC_B, KC_V, LT_J,   KC_K, KC_Z,        KC_QUOT, KC_W,     LT_SLSH, KC_SCLN, KC_COMMA,
                    LT_ESC, LT_R, LT_ENT,      LT_BSPC, LT_SPACE, LT_TAB
    ),

    [_MEDIA] = LAYOUT_split_3x5_3(
        GAME,    XXX,     XXX, XXX, XXX,       XXX,     XXX,     KC_VOLU, XXX,     XXX,
        XXX,     XXX,     XXX, XXX, XXX,       XXX,     KC_MPRV, KC_VOLD, KC_MNXT, XXX,
        QK_BOOT, KC_SYRQ, XXX, XXX, XXX,       XXX,     XXX,     XXX,     XXX,     XXX,
                          XXX, XXX, XXX,       KC_MSTP, KC_MPLY, KC_MUTE
    ),

    // Arrow keys are better on home row. This reduces finger travel significantly.
    // As I rely on them instead of hjkl.
    // Inverted-T also places `pgdn` and `pgup` on hard to reach or awkward positions.
    [_NAV] = LAYOUT_split_3x5_3(
        XXX,     XXX,     XXX,     XXX,      XXX,        REDO,    PASTE,   KC_UP,   CUT,      UNDO,
        KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  XXX,        CW_TOGG, KC_LEFT, KC_DOWN, KC_RGHT,  KC_PGUP,
        XXX,     XXX,     XXX,     XXX,      XXX,        KC_CAPS, KC_HOME, KC_INS,  KC_END,   KC_PGDN,
                          XXX,     XXX,      XXX,        XXX,     XXX,     KC_DEL
    ),

    // `BTN4` / `BTN5` is miroring `UNDO` / `REDO`.
    [_MOUSE] = LAYOUT_split_3x5_3(
        XXX, XXX, OM_FAST, XXX, XXX,        XXX,     OM_HLDS, OM_U,    OM_RELS, OM_W_U,
        XXX, XXX, OM_SLOW, XXX, XXX,        XXX,     OM_L,    OM_D,    OM_R,    OM_W_U,
        XXX, XXX, XXX,     XXX, XXX,        XXX,     OM_W_L,  OM_SEL1, OM_W_R,  OM_W_D,
                  XXX,     XXX, XXX,        OM_SEL2, OM_SEL1, OM_DBLS
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
        XXX,  XXX,   XXX,  XXX,     XXX,         XXX,  XXX,   XXX,  XXX, XXX,
        XXX,  XXX,   XXX,  XXX,     XXX,         XXX,  XXX,   XXX,  XXX, XXX,
        UNDO, CUT,   COPY, PASTE,   REDO,        REDO, PASTE, COPY, CUT, UNDO,
                     XXX,  XXX,     XXX,         XXX,  XXX,   XXX
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
                        KC_F3, KC_F1,   KC_F2,         XXX, XXX,     XXX
    ),

    [_GAME_MIROR] = LAYOUT_split_3x5_3(
        XXX,  KC_U, KC_I, KC_O,    KC_P,       XXX, XXX, XXX, XXX, XXX,
        KC_H, KC_J, KC_K, KC_L,    KC_Y,       XXX, XXX, XXX, XXX, XXX,
        KC_N, KC_M, XXX,  XXX,     XXX,        XXX, XXX, XXX, XXX, XXX,
                    XXX,  KC_PSCR, XXX,        XXX, XXX, XXX
    ),
};

// Combos
enum combo_events {
    X1,
    X2,
    DOT1,
    DOT2,
};

const uint16_t PROGMEM x1_combo[]   = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM x2_combo[]   = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM dot1_combo[] = {KC_W, KC_SLASH, COMBO_END};
const uint16_t PROGMEM dot2_combo[] = {KC_G, KC_O, COMBO_END};

combo_t key_combos[] = {
    [X1]   = COMBO(x1_combo,   KC_X),
    [X2]   = COMBO(x2_combo,   KC_X),
    [DOT1] = COMBO(dot1_combo, KC_DOT),
    [DOT2] = COMBO(dot2_combo, KC_DOT),
};

#include QMK_KEYBOARD_H

#include "features/oneshot.h"

// GUI
#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
// Alt
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))
// Momentarily
#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)

enum layers {
    _BASE,
    _SYM,
    _NAV,
    _NUM,
};

enum keycodes {
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    SW_WIN,  // Switch to next window         (cmd-tab)
    SW_LANG, // Switch to next input language (ctl-spc)
};

// aliases - mostly to keep the format/style consistent
#define XXX KC_NO
#define ___ KC_TRANSPARENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q, KC_W, KC_F, KC_P,   KC_B,      KC_J,   KC_L,    KC_U,    KC_Y,   KC_QUOT,
        KC_A, KC_R, KC_S, KC_T,   KC_G,      KC_M,   KC_N,    KC_E,    KC_I,   KC_O,
        KC_Z, KC_X, KC_C, KC_D,   KC_V,      KC_K,   KC_H,    KC_COMM, KC_DOT, KC_SLSH,
                    LA_NAV, KC_SPC, XXX,     XXX,    KC_LSFT, LA_SYM
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        KC_ESC,  KC_LBRC, KC_LCBR, KC_LPRN, KC_TILD,    KC_CIRC, KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,
        KC_SCLN, KC_ASTR, KC_EQL,  KC_UNDS, KC_PLUS,    KC_HASH, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,
        KC_PLUS, KC_PIPE, KC_AT,   KC_MINS, KC_PERC,    XXX,     KC_EXLM, KC_AMPR, KC_QUES, KC_BSLS,
                         ___,     ___,     XXX,         XXX,     ___,     ___
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        KC_TAB,  SW_WIN,  TAB_L,   KC_PSCR, KC_VOLU,    KC_DEL,  KC_COPY, KC_PSTE, XXX,     KC_CAPS,
        OS_GUI,  OS_ALT,  OS_CTRL, OS_SHFT, KC_VOLD,    KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        QK_BOOT, SPACE_R, BACK,    FWD,     KC_MPLY,    KC_ENT,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                          ___,     ___,     XXX,        XXX,     ___,     ___
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        KC_1,   KC_2,   KC_3,    KC_4,    KC_5,      KC_6,   KC_7,    KC_8,    KC_9,    KC_0,
        OS_GUI, OS_ALT, OS_CTRL, OS_SHFT, KC_F11,    KC_F12, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,
        KC_F1,  KC_F2,  KC_F3,   KC_F4,   KC_F5,     KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,
                          ___,   ___,     XXX,       XXX,    ___,     ___
    ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool sw_lang_active = false;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

// Combos
const uint16_t PROGMEM caps_combo[]   = { KC_SPC,  KC_LSFT,    COMBO_END };

const uint16_t PROGMEM gui_combo[]    = { KC_R,  KC_S,    COMBO_END };
const uint16_t PROGMEM ctrlg_combo[]  = { KC_F,  KC_P,    COMBO_END };
const uint16_t PROGMEM esc_combo[]    = { KC_S,  KC_T,    COMBO_END };
const uint16_t PROGMEM repeat_combo[] = { KC_C,  KC_D,    COMBO_END };

const uint16_t PROGMEM cln_combo[]    = { KC_L,  KC_U,    COMBO_END };
const uint16_t PROGMEM scln_combo[]   = { KC_U,  KC_Y,    COMBO_END };
const uint16_t PROGMEM bspc_combo[]   = { KC_N,  KC_E,    COMBO_END };
const uint16_t PROGMEM cbspc_combo[]  = { KC_M,  KC_N,    COMBO_END };
const uint16_t PROGMEM ent_combo[]    = { KC_H,  KC_COMM, COMBO_END };

const uint16_t PROGMEM select_all_combo[]  = { KC_COPY,  KC_PSTE, COMBO_END };

combo_t key_combos[] = {
    COMBO(caps_combo,   CW_TOGG),

    COMBO(gui_combo,    KC_LGUI),
    COMBO(ctrlg_combo,  LCTL(KC_G)),
    COMBO(esc_combo,    KC_ESC),
    COMBO(repeat_combo, QK_REP),

    COMBO(cln_combo,   LSFT(KC_SCLN)),
    COMBO(scln_combo,  KC_SCLN),
    COMBO(bspc_combo,  KC_BSPC),
    COMBO(cbspc_combo, LCTL(KC_BSPC)),
    COMBO(ent_combo,   KC_ENT),

    COMBO(select_all_combo, LCTL(KC_A)),
};

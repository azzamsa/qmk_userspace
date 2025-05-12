#include QMK_KEYBOARD_H

#include "features/oneshot.h"

// aliases - mostly to keep the format/style consistent
#define XXX KC_NO
#define ___ KC_TRANSPARENT

#define LA_SYM MO(_SYM)
#define LA_NAV MO(_NAV)

#define SW_WIN A(KC_TAB)

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
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
        KC_Q, KC_W, KC_F,   KC_P,   KC_B,      KC_J,   KC_L,    KC_U,    KC_Y,   KC_QUOT,
        KC_A, KC_R, KC_S,   KC_T,   KC_G,      KC_M,   KC_N,    KC_E,    KC_I,   KC_O,
        KC_Z, KC_X, KC_C,   KC_D,   KC_V,      KC_K,   KC_H,    KC_COMM, KC_DOT, KC_SLSH,
                    LA_NAV, KC_SPC, XXX,       XXX,    KC_LSFT, LA_SYM
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        XXX,    SW_WIN, XXX,     KC_PSCR, KC_PSTE,    MS_BTN5, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        OS_GUI, OS_ALT, OS_CTRL, OS_SHFT, KC_COPY,    MS_BTN4, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        KC_TAB, KC_ESC, KC_ENT,  KC_BSPC, KC_DEL,     KC_DEL,  KC_BSPC, KC_ENT,  KC_ESC,  KC_TAB,
                        ___,     ___,     XXX,        XXX,     ___,     ___
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        KC_TILD, KC_LBRC, KC_LCBR, KC_LPRN, KC_ASTR,    KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_GRV,
        KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,    KC_MINS, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,
        KC_SCLN, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,    KC_UNDS, KC_UNDS, KC_AMPR, KC_QUES, KC_BSLS,
                          ___,     ___,     XXX,        XXX,     ___,     ___
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        XXX,  KC_7, KC_8, KC_9, XXX,        KC_F12, KC_F7, KC_F8, KC_F9, KC_VOLU,
        KC_0, KC_4, KC_5, KC_6, XXX,        KC_F11, KC_F4, KC_F5, KC_F6, KC_VOLD,
        XXX,  KC_1, KC_2, KC_3, QK_BOOT,    KC_F10, KC_F1, KC_F2, KC_F3, KC_MPLY,
                       ___,   ___, XXX,     XXX,    ___,   ___
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

//
// Combos

// Corners (base)
const uint16_t PROGMEM q_combo[]        = { KC_W,    KC_F,    COMBO_END };

const uint16_t PROGMEM quote_combo[]    = { KC_U,     KC_Y,   COMBO_END };
const uint16_t PROGMEM dquote_combo[]   = { KC_E,     KC_I,   COMBO_END };

// Corners (nav)
const uint16_t PROGMEM end_combo[]      = { KC_PGDN, KC_PGUP, COMBO_END };

// Corners (sym)
const uint16_t PROGMEM grv_combo[]      = { KC_LBRC, KC_LCBR, COMBO_END };

// Needs dedicated key
const uint16_t PROGMEM esc_combo[]      = { KC_S,  KC_T,    COMBO_END };
const uint16_t PROGMEM tab_combo[]      = { KC_C,  KC_D,    COMBO_END };

const uint16_t PROGMEM bspc_combo[]     = { KC_N,  KC_E,    COMBO_END };
const uint16_t PROGMEM ent_combo[]      = { KC_H,  KC_COMM, COMBO_END };

// Convenience
const uint16_t PROGMEM caps_combo[]     = { KC_SPC, KC_LSFT, COMBO_END };
const uint16_t PROGMEM repeat_combo[]   = { KC_F,   KC_P,    COMBO_END };
const uint16_t PROGMEM cbspc_combo[]    = { KC_E,   KC_H,    COMBO_END };

combo_t key_combos[] = {
    // Corners
    COMBO(q_combo,       KC_Q),
    COMBO(quote_combo,   KC_QUOT),
    COMBO(dquote_combo,  KC_DQT),
    COMBO(end_combo,     KC_END),
    COMBO(grv_combo,     KC_GRV),

    // Needs dedicated key
    COMBO(esc_combo,     KC_ESC),
    COMBO(tab_combo,     KC_TAB),
    COMBO(ent_combo,     KC_ENT),
    COMBO(bspc_combo,    KC_BSPC),

    // Convenience
    COMBO(caps_combo,    CW_TOGG),
    COMBO(repeat_combo,  QK_REP),
    COMBO(cbspc_combo,   LCTL(KC_BSPC)),

};

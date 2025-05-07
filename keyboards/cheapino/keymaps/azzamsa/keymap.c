#include QMK_KEYBOARD_H

#include "features/oneshot.h"

#define HOME G(KC_LEFT)
#define END G(KC_RGHT)
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
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
    OS_CMD,

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
                    XXX,  KC_SPC, LA_NAV,    LA_SYM, KC_LSFT, XXX
    ),

    [_SYM] = LAYOUT_split_3x5_3(
        KC_EXLM, KC_AT,  KC_HASH, KC_DLR,  KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_COLN, KC_GRV, KC_LCBR, KC_RCBR, KC_PLUS,    KC_MINS, OS_SHFT, OS_CTRL, OS_ALT,  OS_SUP,
        KC_TILD, XXX,    XXX,     KC_SCLN, KC_PIPE,    KC_UNDS, KC_BSLS, KC_AMPR, KC_QUES, KC_SLASH,
                         XXX,     ___,     ___,        ___,     ___,     XXX
    ),

    [_NAV] = LAYOUT_split_3x5_3(
        QK_BOOT, SW_WIN,  TAB_L,  TAB_R,  KC_VOLU,    KC_TAB,  KC_ESC,  KC_ENT,  KC_BSPC, KC_DEL,
        OS_SHFT, OS_CTRL, OS_ALT, OS_SUP, KC_VOLD,    KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        SPACE_L, SPACE_R, BACK,   FWD,    KC_MPLY,    KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
                          XXX,    ___,    ___,        ___,     ___,     XXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
        KC_1,    KC_2,    KC_3,   KC_4,   KC_5,      KC_6,   KC_7,    KC_8,    KC_9,    KC_0,
        OS_SHFT, OS_CTRL, OS_ALT, OS_SUP, KC_F11,    KC_F12, OS_SHFT, OS_CTRL, OS_ALT,  OS_SUP,
        KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,     KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,
                          XXX,    ___,    ___,       ___,    ___,     XXX
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
    case OS_SUP:
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
oneshot_state os_cmd_state = os_up_unqueued;

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
        &os_cmd_state, KC_LGUI, OS_SUP,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

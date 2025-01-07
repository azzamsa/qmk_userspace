#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _NAV,
    _MOUSE,
    _MEDIA,
    _FUNC,
    _NUM,
    _SYM,
};

enum keycodes {
    // SMTD keycodes begin
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,

    // left home row
    CKC_A,
    CKC_R,
    CKC_S,
    CKC_T,

    CKC_ESC,
    CKC_SPC,
    CKC_TAB,

    // right home row
    CKC_N,
    CKC_E,
    CKC_I,
    CKC_O,

    CKC_ENT,
    CKC_BSPC,
    CKC_DEL,

    SMTD_KEYCODES_END,
    // SMTD keycodes end
};

// include after enum def, otherwise it won't work.
#include "features/sm_td.h"

// aliases - mostly to keep the format/style consistent
#define XXX KC_NO
#define ___ KC_TRANSPARENT


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x5_3(
      KC_Q,  KC_W,  KC_F,    KC_P,    KC_B,            KC_J,    KC_L,     KC_U,    KC_Y,   KC_QUOT,
      CKC_A, CKC_R, CKC_S,   CKC_T,   KC_G,            KC_M,    CKC_N,    CKC_E,   CKC_I,  CKC_O,
      KC_Z,  KC_X,  KC_C,    KC_D,    KC_V,            KC_K,    KC_H,     KC_COMM, KC_DOT, KC_SLSH,
                     CKC_ESC, CKC_SPC, CKC_TAB,        CKC_ENT, CKC_BSPC, CKC_DEL
    ),

    [_NAV] = LAYOUT_split_3x5_3(
      XXX,     XXX,     XXX,     XXX,      XXX,        KC_CAPS, KC_UNDO,  KC_CUT,  KC_COPY, KC_PSTE,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  XXX,        CW_TOGG, KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,
      XXX,     CKC_DEL, CKC_ENT, CKC_BSPC, XXX,        KC_INS,  KC_HOME,  KC_PGDN, KC_PGUP, KC_END,
                        XXX,     XXX,      XXX,        CKC_ENT, CKC_BSPC, CKC_DEL
    ),

    [_MOUSE] = LAYOUT_split_3x5_3(
      XXX,     XXX,     XXX,     XXX,     XXX,         XXX,     XXX,     XXX,     XXX,     XXX,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,         XXX,     KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
      XXX,     XXX,     XXX,     XXX,     XXX,         XXX,     KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                        XXX,     XXX,     XXX,         KC_BTN3, KC_BTN1, KC_BTN2
    ),

    [_MEDIA] = LAYOUT_split_3x5_3(
      QK_BOOT, XXX,     XXX,     XXX,     XXX,         XXX,     XXX,     XXX,     XXX,     XXX,
      KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXX,         XXX,     KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
      XXX,     XXX,     XXX,     XXX,     XXX,         XXX,     XXX,     XXX,     XXX,     XXX,
                        XXX,     XXX,     XXX,         KC_MSTP, KC_MPLY, KC_MUTE
    ),

    [_FUNC] = LAYOUT_split_3x5_3(
      KC_F12, KC_F7, KC_F8, KC_F9,  KC_PSCR,           XXX,    XXX,     XXX,     XXX,     XXX,
      KC_F11, KC_F4, KC_F5, KC_F6,  KC_SCRL,           XXX,    KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_F10, KC_F1, KC_F2, KC_F3,  KC_PAUS,           XXX,    XXX,     XXX,     XXX,     XXX,
                     XXX,   KC_APP, KC_SPC,            KC_TAB, XXX,     XXX
    ),

    [_NUM] = LAYOUT_split_3x5_3(
      KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC,              XXX, XXX,     XXX,     XXX,     XXX,
      KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,               XXX, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
      KC_GRV,  KC_1, KC_2, KC_3, KC_BSLS,              XXX, XXX,     XXX,     XXX,     XXX,
                   KC_DOT, KC_0, KC_MINS,              XXX, XXX,     XXX
    ),

    [_SYM] = LAYOUT_split_3x5_3(
      KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,        XXX, XXX,      XXX,     XXX,     XXX,
      KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,        XXX, KC_LSFT,  KC_LCTL, KC_LALT, KC_LGUI,
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,        XXX, XXX,      XXX,     XXX,     XXX,
                        KC_LPRN, KC_RPRN, KC_UNDS,        XXX, XXX, XXX
    ),

};

//
// SMTD
// https://github.com/stasmarkin/sm_td/
void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        // left side
        SMTD_MT(CKC_A, KC_A, KC_LGUI)
        SMTD_MT(CKC_R, KC_R, KC_LALT)
        SMTD_MT(CKC_S, KC_S, KC_LCTL)
        SMTD_MT(CKC_T, KC_T, KC_LSFT)

        SMTD_LT(CKC_ESC, KC_ESC, _MEDIA)
        SMTD_LT(CKC_SPC, KC_SPACE, _NAV)
        SMTD_LT(CKC_TAB, KC_TAB, _MOUSE)

        // righ side
        SMTD_MT(CKC_N, KC_N, KC_LSFT)
        SMTD_MT(CKC_E, KC_E, KC_LCTL)
        SMTD_MT(CKC_I, KC_I, KC_LALT)
        SMTD_MT(CKC_O, KC_O, KC_LGUI)

        SMTD_LT(CKC_ENT, KC_ENT, _SYM)
        SMTD_LT(CKC_BSPC, KC_BSPC, _NUM)
        SMTD_LT(CKC_DEL, KC_DEL, _FUNC)
    }
}

// Most of the keys were set to `300` and `20`, which I took from the sm_td author's keymaps.
// Because I can't type anything using the default settings.
uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    switch (keycode) {
        // left side
        case CKC_A:
            if (timeout == SMTD_TIMEOUT_RELEASE) return 5; // default: 50
            break;
        case CKC_R:
        case CKC_S:
        case CKC_T:

        case CKC_ESC:
        case CKC_SPC:
        case CKC_TAB:

        // right side
        case CKC_N:
        case CKC_E:
        case CKC_I:
        case CKC_O:
            if (timeout == SMTD_TIMEOUT_RELEASE) return 5;
            break;

        case CKC_ENT:
        case CKC_BSPC:
        case CKC_DEL:
   }

    return get_smtd_timeout_default(timeout);
}


//
// core
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    return true;
}


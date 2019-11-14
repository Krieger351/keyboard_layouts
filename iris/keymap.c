#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define L0 0
#define L1 1

#define KC_UTAB LSFT(KC_TAB)

#define SHFT_ENT LSFT_T(KC_ENT)
#define SHFT_SPC LSFT_T(KC_SPC)

#define KC_LOCK RGUI(RCTL(KC_Q))

#define KC_L1 MO(L1)

// Tap Dance Declarations
enum {
    TD_LBRC_RBRC = 0,
};
enum my_keycodes {
    KC_STLT = SAFE_RANGE,
};

#define KC_XBRC TD(TD_LBRC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L0] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤-
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_XBRC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_EQL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MINS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    RGB_TOG,          KC_MPLY, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LCTL, SHFT_ENT, KC_L1,                    KC_RGUI, SHFT_SPC, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [L1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_UTAB, _______, _______, KC_PGUP, _______, _______,                            _______, _______, KC_UP,   _______, _______, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_HOME, KC_PGDN, KC_END,  _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_M_P, _______, _______, _______, _______, _______, KC_STLT,          KC_LOCK, _______, _______, _______, _______, _______, RESET,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______,  _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

void keyboard_post_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
        rgblight_sethsv_noeeprom(HSV_CYAN);
    #endif
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_STLT:
            rgblight_sethsv_noeeprom(HSV_CYAN);
            return false;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(biton32(layer_state)){
            case L1:
                clockwise
                    ? rgblight_increase_hue_noeeprom()
                    : rgblight_decrease_hue_noeeprom();
                break;
            default:
                clockwise
                    ? tap_code(KC_WH_D)
                    : tap_code(KC_WH_U);
           break;
        }
    }
    else if (index == 1) {
        switch(biton32(layer_state)){
            case L1:
                clockwise
                    ? tap_code(KC_BRIU)
                    : tap_code(KC_BRID);
                break;
            default:
                clockwise
                    ? tap_code(KC_VOLU)
                    : tap_code(KC_VOLD);
           break;
        }
    }
}


// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for KC_LBRC, twice for KC_RBRC
    [TD_LBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC)
};

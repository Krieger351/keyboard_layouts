#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define L0 0
#define L1 1

#define KC_UTAB LSFT(KC_TAB)

#define KC_SENT LSFT_T(KC_ENT)
#define KC_SSPC LSFT_T(KC_SPC)

#define KC_LOCK RGUI(RCTL(KC_Q))
#define KC_CONS RGUI(LALT(KC_I))

#define KC_CMZ RGUI(KC_Z)
#define KC_CMX RGUI(KC_X)
#define KC_CMC RGUI(KC_C)
#define KC_CMV RGUI(KC_V)

#define KC_RGBT RGB_TOG
#define KC_____ _______
#define KC_RESET RESET

#define KC_L1 MO(L1)

enum my_keycodes {
    KC_STLT = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L0] = LAYOUT_kc(
  //┌────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┐
     GESC,1   ,2   ,3   ,4   ,5   ,               6   ,7   ,8   ,9   ,0   ,BSPC,
  //├────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┤
     TAB ,Q   ,W   ,E   ,R   ,T   ,               Y   ,U   ,I   ,O   ,P   ,LBRC,
  //├────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┤
     EQL ,A   ,S   ,D   ,F   ,G   ,               H   ,J   ,K   ,L   ,SCLN,QUOT,
  //├────┼────┼────┼────┼────┼────┼────┐    ┌────┼────┼────┼────┼────┼────┼────┤
     MINS,Z   ,X   ,C   ,V   ,B   ,RGBT,     MPLY,N   ,M   ,COMM,DOT ,SLSH,____,
  //└────┴────┴────┴─┬──┴─┬─┴───┬┴───┬┘     └┬───┴┬───┴┬───┴┬───┴────┴────┴────┘
                      LCTL,SENT,L1  ,         RGUI,SSPC,RALT
                  // └────┴────┴────┘        └────┴────┴───┘
  ),

  [L1] = LAYOUT_kc(
  //┌────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┐
     GRV ,F1  ,F2  ,F3  ,F4  ,F5  ,               F6  ,F7  ,F8  ,F9  ,F10 ,DEL ,
  //├────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┤
     UTAB,____,____,PGUP,____,____,               ____,____,UP  ,CONS,____,RBRC,
  //├────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┤
     ____,____,HOME,PGDN,END ,____,               ____,LEFT,DOWN,RGHT,____,BSLS,
  //├────┼────┼────┼────┼────┼────┼────┐    ┌────┼────┼────┼────┼────┼────┼────┤
     ____,CMZ ,CMX ,CMC ,CMV ,____,STLT,     LOCK,____,____,____,____,____,RESET,
  //└────┴────┴────┴─┬──┴─┬─┴───┬┴───┬┘     └┬───┴┬───┴┬───┴┬───┴────┴────┴────┘
                      ____,____,____,         ____,____,____
                  // └────┴────┴────┘        └────┴────┴───┘
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

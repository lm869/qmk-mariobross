#include QMK_KEYBOARD_H
#include <stdio.h>

enum {
    TD_PC,
    TD_COMI,
    TD_SLA,
    TD_CAPLOCK,
    TD_ALT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //|--ESC--+---Q---+---W---+---E---+---R---+---T---|                    |---Y---+---U---+---I---+---O---+---P---+---BackSp----|
     KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                         KC_Y,  KC_U,   KC_I,   KC_O,   KC_P,    KC_BSPC,
  //|---- TAB ----+---A---+---S---+---D---+---F---+---G---|                    |---H---+---J---+---K---+---L---+--- ; : ---+---  ' "  ---|
    LSFT_T(KC_TAB),  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                        KC_H,  KC_J,    KC_K,  KC_L,  TD(TD_PC), TD(TD_COMI),
  //-- SHF BLMSY --+---Z---+---X---+---C---+---V---+---B---|             |---N---+---M---+-- , --+-- . --+--- / ? ---+-- ENT SHF --|
     TD(TD_CAPLOCK), KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,                  KC_N,  KC_M,  KC_COMM, KC_DOT, TD(TD_SLA), RSFT_T(KC_ENT),
  //---------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+-------+--------+--------+--------|
                                         KC_LGUI, MO(1), KC_SPC,     KC_SPC, MO(2), TD(TD_ALT)
                                      //|--------------------------|  |--------------------------|
  ),

  [1] = LAYOUT_split_3x6_3(
  //|--ESC--+-- vol- --+-- vol+ --+-- up --+----R---+---T---|              |---7---+---8---+---9---+-------+--pageup--+---BackSp----|
     KC_ESC,  KC_VOLD,   KC_VOLU,   KC_UP, KC_R  , KC_T,                      KC_7,   KC_8,   KC_9,  XXXXXXX, KC_PGUP,  KC_BSPC,
  //|---SHF---+---------+----LEFT---+---DOWN---+---RIGHT---|              |---4---+---5---+---6---+--------+---ñ---+------------|
     KC_LSFT, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                   KC_4,   KC_5,   KC_6 ,  XXXXXXX, KC_SCLN, XXXXXXX,
  //|-------+-------+--prev--+---c---+---next--+--------|                |---1---+---2---+---3---+---0---+--pageDown--+----------|
     KC_LCTL,  KC_Z,  KC_MPRV, KC_C, KC_MNXT, XXXXXXX,                         KC_1,   KC_2,   KC_3, KC_0, KC_PGDN , XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         LCTL(KC_LALT), KC_TRNS, KC_SPC,    KC_SPC, MO(3), KC_RALT
                                      //|--------------------------|  |--------------------------|
  ),

  [2] = LAYOUT_split_3x6_3(
  //|--ESC--+--- ! ---+-- @ --+-- # --+-- $ --+-- % -----|                    |--- ^ ---+-- & --+--- * ---+-- ( ---+--- ) --+-- DEL --|
      KC_ESC, KC_EXLM, KC_AT,  KC_HASH, KC_DLR, KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
  //|-- F1 --+-- F2 --+-- F3 --+-- F4 --+-- F5 --+-- F6 --|                    |--- - ---+--- = --+--  [ --+-- ] --+-- | --+--------|
       KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_MINS , KC_EQL, KC_LBRC, KC_RBRC, KC_PIPE, KC_GRV,
  //|-- F7 --+-- F8 --+-- F9 --+---F10---+--F11---+--F12--|                    |--- _ ---+--- + ---+--- { ---+-- } --+-- \ --+--  --|
       KC_F7,  KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,                       KC_UNDS, KC_PLUS,  KC_LCBR,  KC_RCBR, KC_BSLS, KC_ENT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_LGUI, MO(3), KC_SPC,       KC_SPC, _______, KC_RALT
                                      //|--------------------------|  |--------------------------|
  ),

  [3] = LAYOUT_split_3x6_3(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG,                       XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                       XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   RESET,  \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX,                        XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LCTL, _______, KC_SPC,    KC_SPC, _______, KC_RALT 
                                      //|--------------------------|  |--------------------------|
  )
};


// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    [TD_COMI] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),
    [TD_SLA] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LCTRL, KC_CAPS),
    [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
    
};

#ifdef OLED_ENABLE
#include "screens.h"
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        set_keylog(keycode, record);
    } else {
        set_keylog(0, record);
    }
    return true;
}

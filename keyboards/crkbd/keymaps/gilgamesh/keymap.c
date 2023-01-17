/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 Gilgamesh @gilgamesh_one@mastodon.world

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_japanese.h"
#include "sendstring_japanese.h"


enum crkbd_layers {
    _DVORAK,
    _QWERTY,
    _COLEMAK_DH,
    _NUM,
    _NAV,
    _SYM,
    _EXT,
    _MSE,
    _FUN1,
    _FUN2,
};


#define NUM MO(_NUM)
#define NAV MO(_NAV)
#define SYM MO(_SYM)
#define EXT MO(_EXT)
#define MSE MO(_MSE)
#define FUN1 MO(_FUN1)
#define FUN2 MO(_FUN2)

enum custom_keycodes {
    GOOGL = SAFE_RANGE,
    GTRNS,
    DFINE,
};

// macros

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case GOOGL:
    if (record->event.pressed) {
      // when keycode GOOGL is pressed
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_C)SS_UP(X_LGUI));
      SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_DOWN(X_LALT)SS_TAP(X_SPC)SS_UP(X_LALT)SS_UP(X_LSFT)SS_UP(X_LCTL)SS_UP(X_LGUI));
      wait_ms(50);
      SEND_STRING(SS_TAP(X_G)SS_TAP(X_SPC));
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_V)SS_UP(X_LGUI)SS_TAP(X_ENT));
    } else {
      // when keycode GOOGL is released
    }
    break;
  case GTRNS:
    if (record->event.pressed) {
      // when keycode GTRNS is pressed
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_C)SS_UP(X_LGUI));
  SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_DOWN(X_LALT)SS_TAP(X_SPC)SS_UP(X_LALT)SS_UP(X_LSFT)SS_UP(X_LCTL)SS_UP(X_LGUI));
      wait_ms(50);
      SEND_STRING(SS_TAP(X_T)SS_TAP(X_SPC));
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_V)SS_UP(X_LGUI)SS_TAP(X_ENT));
    } else {
      // when keycode GTRNS is released
    }
    break;
  case DFINE:
    if (record->event.pressed) {
      // when keycode DFINE is pressed
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_C)SS_UP(X_LGUI));
SEND_STRING(SS_DOWN(X_LGUI)SS_DOWN(X_LCTL)SS_DOWN(X_LSFT)SS_DOWN(X_LALT)SS_TAP(X_SPC)SS_UP(X_LALT)SS_UP(X_LSFT)SS_UP(X_LCTL)SS_UP(X_LGUI));
      wait_ms(50);
      SEND_STRING(SS_TAP(X_D)SS_TAP(X_SPC));
      SEND_STRING(SS_DOWN(X_LGUI)SS_TAP(X_V)SS_UP(X_LGUI));
      wait_ms(70);
      SEND_STRING(SS_TAP(X_ENT));
    } else {
      // when keycode DFINE is released
    }
    break;
  }
  return true;
};


// combos

const uint16_t PROGMEM combo_esc[] = {KC_COMM, KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM combo_en[] = {KC_Q, KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_jp[] = {KC_M, KC_W, KC_V, COMBO_END};
const uint16_t PROGMEM combo_optbksp[] = {KC_H, KC_T, KC_N, COMBO_END};
const uint16_t PROGMEM combo_optdel[] = {KC_G, KC_C, KC_R, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(combo_esc, KC_ESC),
  COMBO(combo_en, KC_LNG2),
  COMBO(combo_jp, KC_LNG1),
  COMBO(combo_optbksp, LALT(KC_BSPC)),
  COMBO(combo_optdel, LALT(KC_DEL)),
     // keycodes with modifiers are possible too!
};


// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DVORAK] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      JP_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                         KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MINS,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TAB,   NUM,  KC_SPC, OSM(MOD_LSFT),    NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'

  ),

   [_QWERTY] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,  KC_COMM, KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
                             //`--------------------------'  `--------------------------'

  ),
  [_COLEMAK_DH] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,  KC_COMM, KC_DOT, KC_SLSH,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS
                             //`--------------------------'  `--------------------------'

  ),
  [_NUM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX,  KC_MEH, KC_HYPR, XXXXXXX, XXXXXXX,                      KC_PPLS,    KC_7,    KC_8,    KC_9, KC_PAST,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, XXXXXXX,                      JP_MINS,    KC_4,    KC_5,    KC_6, KC_SLSH,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX,    FUN2,    FUN1,     SYM, XXXXXXX,                      JP_COLN,    KC_1,    KC_2,    KC_3,    KC_0,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 XXXXXXX,     NUM, XXXXXXX,     KC_DEL,     SYM, KC_BSPC
                             //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      G(KC_Z), G(KC_X), G(KC_C), G(KC_V),LSG(KC_Z),                     XXXXXXX, XXXXXXX, KC_HYPR,  KC_MEH, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT,  KC_ESC,                      XXXXXXX, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,                      XXXXXXX,     EXT,     MSE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                CAPS_WORD,   EXT,   KC_SPC, OSM(MOD_LSFT),  NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'
  ),

  [_SYM] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX,  KC_MEH, KC_HYPR, XXXXXXX, XXXXXXX,                      JP_CIRC, KC_RBRC, KC_NUHS,   JP_AT,  JP_YEN,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, XXXXXXX,                        KC_RO, KC_ASTR, KC_LPRN, JP_DQUO, JP_QUES,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_SCLN, JP_LCBR, JP_RCBR, KC_LABK, KC_RABK,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TAB,     NUM,  KC_SPC, OSM(MOD_LSFT),  NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'
  ),

  [_EXT] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      KC_CAPS, KC_LNG1, KC_LNG2, JP_ZKHK, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_HYPR,  KC_MEH, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_KB_MUTE,KC_KB_VOLUME_UP,KC_KB_VOLUME_DOWN,KC_MPLY, XXXXXXX,   XXXXXXX, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX,   DFINE,   GTRNS,   GOOGL, XXXXXXX,                      XXXXXXX,     EXT,     MSE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TAB,     NUM,  KC_SPC,  OSM(MOD_LSFT), NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'
  ),
  [_MSE] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX, KC_BTN1, KC_BTN1, KC_BTN2,LSG(KC_5),                      KC_PWR, XXXXXXX, KC_HYPR,  KC_MEH, XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,LSG(KC_3),                     KC_SLEP, KC_RCTL, KC_RGUI, KC_RALT, KC_RSFT,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R,LSG(KC_4),                     KC_WAKE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TAB,     NUM,  KC_SPC,  OSM(MOD_LSFT), NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'
  ),

  [_FUN1] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX,  KC_MEH, KC_HYPR, XXXXXXX,DF(_COLEMAK_DH),               KC_PSCR,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL,DF(_DVORAK),                   KC_SCRL,   KC_F5,   KC_F6,   KC_F7,   KC_F8,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      OS_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,DF(_QWERTY),                   KC_PAUS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TAB,     NUM,  KC_SPC,  OSM(MOD_LSFT), NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'
  ),
  [_FUN2] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      QK_BOOT,  KC_MEH, KC_HYPR, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      KC_LSFT, KC_LALT, KC_LGUI, KC_LCTL, XXXXXXX,                       KC_INS,  KC_F17,  KC_F18,  KC_F19,  KC_F20,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       QK_RBT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_F13,  KC_F14,  KC_F15,  KC_F16,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_TAB,     NUM,  KC_SPC,  OSM(MOD_LSFT), NAV,  KC_ENT
                             //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define DISPLAY_LAYER_NAME(LAYER_NAME, LAYER_STRING) \
  if(get_highest_layer(layer_state|default_layer_state) == LAYER_NAME) { \
      oled_write_ln_P(PSTR(LAYER_STRING), false); \
      return;\
  }\


void oled_render_layer_state(void) {
  // if caps word is enabled, show
  if(is_caps_word_on()) {
      oled_write_ln_P(PSTR("CAPS WORD"), false);
      return;
  }
  DISPLAY_LAYER_NAME(_FUN2, "FUN 2");
  DISPLAY_LAYER_NAME(_FUN1, "FUN 1");
  DISPLAY_LAYER_NAME(_MSE, "MSE");
  DISPLAY_LAYER_NAME(_EXT, "EXT");
  DISPLAY_LAYER_NAME(_SYM, "SYM");
  DISPLAY_LAYER_NAME(_NAV, "NAV");
  DISPLAY_LAYER_NAME(_NUM, "NUM");
  DISPLAY_LAYER_NAME(_QWERTY, "QWERTY");
  DISPLAY_LAYER_NAME(_COLEMAK_DH, "COLEMAK DH");
  DISPLAY_LAYER_NAME(_DVORAK, "DVORAK");
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void oled_render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("N "), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("C "), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_ln_P(PSTR("S "), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void oled_render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Shift"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Option\n"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("Command"), (modifiers & MOD_MASK_GUI));
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("Control\n"), (modifiers & MOD_MASK_CTRL));
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_render_status_main(void) {
    /* Show Keyboard Layout  */
    oled_render_layer_state();
    oled_render_mod_status(get_mods());
    oled_render_keylock_status(host_keyboard_leds());
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_status_main();
    } else {
        oled_render_logo();
    }
    return false;
}


#endif // OLED_ENABLE

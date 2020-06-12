#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  VRSN = SAFE_RANGE,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  | Grv  |           |   =  |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   ]    |   Q  |   W  |   E  |   R  |   T  |  Ent |           | Bkp  |   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|      |           | spce |------+------+------+------+------+--------|
 * | \ /LCtl|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2| ' /RCtl|
 * |--------+------+------+------+------+------| Tab  |           | Del  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LAlt | Home | PgUp | PgDn | End  |                                       | Left |  Up  | Down | Rght | RAlt |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | LAlt |       | Menu | RGui |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | ~L2  |       | ~L2  |        |      |
 *                                 | Space|Backsp|------|       |------|  Enter | Space|
 *                                 |      |ace   | ~L1  |       | ~L1  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,          KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_GRV,
        KC_RBRC,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_ENT,
        LCTL_T(KC_BSLS), KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,         KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   KC_TAB,
        KC_LALT,         KC_HOME,      KC_PGUP,KC_PGDN,KC_END,
                                                    KC_LGUI,  KC_LALT,
                                                              TT(MDIA),
                                               KC_SPC,KC_BSPC,TT(SYMB),
        // right hand
             LGUI(KC_EQL),KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             KC_MINS,
             KC_BSPC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_LBRC,
                          KC_H,   KC_J,   KC_K,   KC_L,   LT(MDIA, KC_SCLN),RCTL_T(KC_QUOT),
             KC_DEL,      KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                                  KC_LEFT,KC_UP,  KC_DOWN,KC_RIGHT,         KC_RALT,
             KC_APP,      KC_RGUI,
             TT(MDIA),
             TT(SYMB),KC_ENT,KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           | NLck |      |      |   /  |   *  |   -  | PrntSc |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |           | Num  |      |   7  |   8  |   9  |   +  | Pause  |
 * |---------+------+------+------+------+------|      |           | Lock |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   ,  | Insert |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         | Cut  | Copy | Paste| Undo | Redo |      |           |      |      |   1  |   2  |   3  |   =  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * | EEP_RST |      |      |      |      |                                       |      |   0  |   .  | Enter|      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_FN0,  KC_FN1,  KC_FN2,  KC_FN3,  KC_FN4, KC_TRNS,
       EEP_RST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_NLCK, KC_TRNS, KC_TRNS,KC_PSLS, KC_PAST, KC_PMNS, KC_PSCR,
       KC_NLCK, KC_PSLS, KC_P7,  KC_P8,   KC_P9,   KC_PPLS, KC_PAUS,
                KC_PAST, KC_P4,  KC_P5,   KC_P6,   KC_PCMM, KC_INS,
       KC_TRNS, KC_PMNS, KC_P1,  KC_P2,   KC_P3,   KC_PEQL, KC_TRNS,
                         KC_TRNS,KC_P0,   KC_PDOT, KC_ENT,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Mute | Prev |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | Vol+ |      |      |
 *                                 |      |      |------|       |------| Next | Play |
 *                                 |      |      |      |       | Vol- |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_MUTE, KC_MPRV,
       KC_VOLU,
       KC_VOLD, KC_MNXT, KC_MPLY
),
};

// Fn action definition
const uint16_t PROGMEM fn_actions[] = {
  [0] = ACTION_MODS_KEY(MOD_LCTL, KC_C),                // FN0 - Ctrl X
  [1] = ACTION_MODS_KEY(MOD_LCTL, KC_H),                // FN1 - Ctrl C
  [2] = ACTION_MODS_KEY(MOD_LCTL, KC_U),                // FN2 - Ctrl V
  [3] = ACTION_MODS_KEY(MOD_LCTL, KC_LBRC),             // FN3 - Ctrl Z (undo)
  [4] = ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_LBRC),  // FN4 - Ctrl Maj Z (redo)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
};

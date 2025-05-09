#include QMK_KEYBOARD_H
#include "quantum.h"
#include "keymap_extras/keymap_us.h"
#include "send_string/send_string.h"
#include "send_string/send_string_keycodes.h"
#include "unicode/unicode.h"

// void set_unicode_map();

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

int unicode_mode = UC_MAC;  // Set initial mode (macOS)

enum unicode_names {
    AE_LOWER,
    AE_UPPER,
    OE_LOWER,
    OE_UPPER,
    AA_LOWER,
    AA_UPPER,
    AE_LOWER_WIN,
    AE_UPPER_WIN,
    OE_LOWER_WIN,
    OE_UPPER_WIN,
    AA_LOWER_WIN,
    AA_UPPER_WIN,
};


const uint32_t PROGMEM unicode_map[] = {
    [AE_LOWER] = 0x00E6,  // æ
    [AE_UPPER] = 0x00C6,
    [OE_LOWER] = 0x00F8,  // ø
    [OE_UPPER] = 0x00D8,
    [AA_LOWER] = 0x00E5,   // å
    [AA_UPPER] = 0x00C5,

    // windows unicode
    [AE_LOWER_WIN] = 0x00E6,  // æ
    [AE_UPPER_WIN] = 0x00C6,
    [OE_LOWER_WIN] = 0x00F8,  // ø
    [OE_UPPER_WIN] = 0x00D8,
    [AA_LOWER_WIN] = 0x00E5,   // å
    [AA_UPPER_WIN] = 0x00C5,

};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |Backsp|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  /   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |  =   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LOWER |CMD   | / Space /       \ Space\  |ENTER | UPPER| RAlt|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,   KC_SLSH ,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_MINS,  KC_EQL,
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_SPC, MO(_RAISE), KC_ENT, KC_RALT
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------| left | down |  up  | right|      |   ~  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |  `   |      |      |   |  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | CMD  |LOWER | / Space /       \ Space\  |UPPER | ENTER | RAlt|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______,  KC_DEL,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_LBRC, KC_RBRC, KC_F10,  KC_F11,  KC_F12,
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, KC_TILD,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLON, KC_EQL, KC_PIPE, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______

),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |   \   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   [  |   ]  |   :  |   0  |  å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      |   (  |   )  |   =  |  æ   |  ø   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|      |   {  |   }  |   |  |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LOWER |CMD   | / Space /       \ Space\  |ENTER | UPPER| RAlt|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, KC_BSLS, _______,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_GRV , KC_LBRC, KC_RBRC, KC_COLN, KC_TILD, XXXXXXX,
  _______,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LPRN, KC_RPRN,  KC_EQL, XXXXXXX, XXXXXXX,
  _______,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   XXXXXXX, XXXXXXX,  XXXXXXX, KC_LCBR, KC_RCBR, KC_PIPE, KC_PLUS, XXXXXXX,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD,                   XXXXXXX, KC_BRID ,KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX,                   KC_HOME, KC_VOLD, KC_VOLU,  KC_END, XXXXXXX, XXXXXXX,
  XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UC_PREV, UC_NEXT, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
      if (layer_state_is(2)) {
          uint8_t row = record->event.key.row;
          uint8_t col = record->event.key.col;

          // Check if the Shift key is held down
          bool shift_held = get_mods() & MOD_MASK_SHIFT;
          // æ key
          if (row == 7 && col == 1) {
              // if (unicode_mode == UC_MAC) {
              const char *ae = (shift_held) ? "Æ" : "æ";
              send_unicode_string(ae);
              // }
              // else {
              //     if (shift_held) {
              //         send_string("ae");
              //     } else {
              //         send_string("AE");
              //     }
              // }
              return false;
          }
          // ø key
          if (row == 7 && col == 0) {
              const char* oe = (shift_held) ? "Ø" : "ø";
              send_unicode_string(oe);
              return false;
          }
          // å key
          if (row == 6 && col == 0) {
              const char* aa = (shift_held) ? "Å" : "å";
              send_unicode_string(aa);
                return false;
          }
      }
      switch (keycode) {
            case UC_NEXT:
                unicode_mode = (unicode_mode == UC_WIN) ? UC_MAC : UC_WIN;
            break;
            case UC_PREV:
                unicode_mode = (unicode_mode == UC_MAC) ? UC_WIN : UC_MAC;
            break;
            // Handle other keycodes...
        }
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
      switch (unicode_mode) {
          case UC_MAC:
              oled_write_P(PSTR("Unicode: macOS\n"), false);
          break;
          case UC_WIN:
              oled_write_P(PSTR("Unicode: Windows\n"), false);
          break;
      }
#endif
    // set_timelog();
  }
  return true;
}

#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 */

[_QWERTY] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_UNDS,
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  KC_CAPS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC,                                                   KC_ENT, MO(_RAISE), KC_BSPC, KC_RALT
),
/* LOWER
 */

[_LOWER] = LAYOUT(
  _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK, KC_TILD,                   KC_PIPE, KC_RABK, KC_RPRN, KC_RCBR, KC_RBRC, _______,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DQUO,                   KC_DQUO, _______, _______, _______, _______, _______,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_QUOT,                   KC_QUOT, _______, _______, _______, _______, KC_GRV,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______,
  _______, _______, _______, _______,                                                       _______, _______, _______, _______
),
/* RAISE
 */

[_RAISE] = LAYOUT(
  _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_LABK, KC_TILD,                   KC_PIPE, KC_RABK, KC_RPRN, KC_RCBR, KC_RBRC, _______,
  _______, _______, _______, _______, _______, KC_DQUO,                   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH, KC_QUOT,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_GRV,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, _______,
  _______, _______, _______, _______,                                                       _______, _______, _______, _______
),
/* ADJUST
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  _______, _______, _______, _______,                                                       _______, _______, _______, _______
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
  led_t led_state = host_keyboard_led_state();

  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    // oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);

    // Caps Lock
    // oled_set_cursor(0, 25);
    oled_write_ln(led_state.caps_lock ? PSTR("Caps Lock On") : PSTR("Caps Lock Off"), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}

#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

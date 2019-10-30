#include QMK_KEYBOARD_H

#define _BASE_WIN 0 // Base layer (Windows specific)
#define _BASE_MAC 1 // Base layer (Mac specific)
#define _FN_WIN 2 // FN layer (Windows)
#define _FN_MAC 3 // Fn layer (MAc)
#define _INPUT 4 // Input mode layer
#define _LIGHTS 5 // Lighting layer

enum my_keycodes {
    SW_MAC = SAFE_RANGE,
    SW_WIN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

		[_BASE_WIN] = LAYOUT_65_ansi(
			KC_GESC,       KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,        KC_9,        KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
		    KC_TAB,        KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,        KC_O,        KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,
			KC_LCTL,       KC_A,      KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,        KC_L,        KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT,       KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,     KC_DOT,      KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
		    MO(_FN_WIN),   KC_LGUI,   KC_LALT,                   KC_SPC,                    KC_RALT,     MO(_FN_WIN), KC_RCTL,  KC_LEFT,           KC_DOWN,   KC_RIGHT),

        [_BASE_MAC] = LAYOUT_65_ansi(
			KC_GESC,       KC_1,      KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,        KC_9,        KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
		    KC_TAB,        KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,        KC_O,        KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,
			KC_LCTL,       KC_A,      KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,        KC_L,        KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT,       KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,     KC_DOT,      KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
		    MO(_FN_MAC),   KC_LALT,   KC_LGUI,                   KC_SPC,                    KC_RGUI,     MO(_FN_MAC), KC_RCTL,  KC_LEFT,           KC_DOWN,   KC_RIGHT),

		[_FN_WIN] = LAYOUT_65_ansi(
			KC_GRV,        KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,       KC_F9,       KC_F10,   KC_F11,   KC_F12,  KC_DEL,    _______,
		    _______,       _______,   _______, _______, _______, _______, _______, _______, OSL(_INPUT), _______,     _______,  _______,  _______, RESET,     _______,
			_______,       _______,   _______, _______, _______, _______, _______, _______, _______,     TG(_LIGHTS), _______,  _______,           EEP_RST,   _______,
		    _______,       _______,   _______, _______, _______, _______, _______, _______, _______,     _______,     _______,  _______,           KC_VOLU,   KC_MUTE,
		    _______,       _______,   _______,                   _______,                   _______,     _______,     _______,  KC_MPRV,           KC_VOLD,   KC_MNXT),

        [_FN_MAC] = LAYOUT_65_ansi(
			KC_GRV,        KC_F1,     KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,       KC_F9,       KC_F10,   KC_F11,   KC_F12,  KC_DEL,    _______,
		    _______,       _______,   _______, _______, _______, _______, _______, _______, OSL(_INPUT), _______,     _______,  _______,  _______, RESET,     _______,
			_______,       _______,   _______, _______, _______, _______, _______, _______, _______,     TG(_LIGHTS), _______,  _______,           EEP_RST,   _______,
		    _______,       _______,   _______, _______, _______, _______, _______, _______, _______,     _______,     _______,  _______,           KC_VOLU,   KC_MUTE,
		    _______,       _______,   _______,                   _______,                   _______,     _______,     _______,  KC_MPRV,           KC_VOLD,   KC_MNXT),

        [_INPUT] = LAYOUT_65_ansi(
			_______,       _______,   _______, _______, _______, _______, _______, _______, _______,     _______,     _______,  _______,  _______, _______,   _______,
		    _______,       _______,   SW_WIN,  _______, _______, _______, _______, _______, _______,     _______,     _______,  _______,  _______, _______,   _______,
			_______,       _______,   _______, _______, _______, _______, _______, _______, _______,     _______,     _______,  _______,           _______,   _______,
		    _______,       _______,   _______, _______, _______, _______, _______, SW_MAC,  _______,     _______,     _______,  _______,           _______,   _______,
		    _______,       _______,   _______,                   _______,                   _______,     _______,     _______,  _______,           _______,   _______),

        [_LIGHTS] = LAYOUT_65_ansi(
			TG(_LIGHTS),   RGB_M_P,   _______, _______, _______, _______, _______, _______, _______,     _______,     _______,  RGB_RMOD, RGB_MOD, _______,   RGB_SPI,
		    _______,       _______,   _______, _______, _______, _______, _______, _______, _______,     RGB_TOG,     _______,  _______,  _______, _______,   RGB_SAI,
			_______,       _______,   _______, _______, _______, _______, _______, _______, _______,     _______,     _______,  _______,           _______,   RGB_SAD,
		    _______,       _______,   _______, _______, _______, _______, _______, _______, _______,     _______,     _______,  _______,           RGB_VAI,   RGB_SPD,
		    _______,       _______,   _______,                   _______,                   _______,     _______,     _______,  RGB_HUD,           RGB_VAD,   RGB_HUI),

};

void matrix_init_user(void)
{
  //user initialization
}

void matrix_scan_user(void)
{
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case SW_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE_MAC);
            }
            break;
        case SW_WIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_BASE_WIN);
            }
            break;
    }
	return true;
}

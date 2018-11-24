/* Copyright 2018 Ollie Day
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "planckton.h"

#define _BASE  0
#define _LOWER 1
#define _RAISE 2
#define _FN    3

enum custom_keycodes {
	POUND = SAFE_RANGE,
	EURO,
	TERMINAL,
	WINDOW_LEFT,
	WINDOW_CENTRE,
	WINDOW_RIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT_planck_grid(
		KC_TAB,   KC_Q,    KC_W,    KC_C,    KC_P,       KC_COMM,              KC_DOT, KC_L,       KC_U,     KC_Y,        KC_Z,          KC_BSPACE,
		KC_BSPC,  KC_A,    KC_R,    KC_S,    KC_T,       KC_G,                 KC_K,   KC_N,       KC_E,     KC_I,        KC_O,          KC_ENT,
		KC_LSFT,  KC_X,    KC_V,    KC_F,    KC_D,       KC_B,                 KC_J,   KC_H,       KC_M,     KC_QUOT,     KC_QUES,       KC_CAPS,
		KC_LCTL,  MO(_FN), KC_LALT, KC_LGUI, MO(_LOWER), MT(MOD_LCTL, KC_ESC), KC_SPC, MO(_RAISE), TERMINAL, WINDOW_LEFT, WINDOW_CENTRE, WINDOW_RIGHT
	),
	[_LOWER] = LAYOUT_planck_grid(
		_______, KC_NO, KC_NO,   KC_UP,   KC_NO,    KC_NO,   KC_NO,       KC_7,  KC_8, KC_9,   KC_NO,   _______ ,
		_______, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,   KC_ASTERISK, KC_4,  KC_5, KC_6,   KC_PLUS, _______ ,
		_______, KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_SLASH,    KC_1,  KC_2, KC_3,   KC_MINS, KC_EQL,
		_______, KC_NO, _______, _______, _______,  _______, _______,     KC_NO, KC_0, KC_DOT, KC_COMM, KC_NO
	),
	[_RAISE] = LAYOUT_planck_grid(
		_______, KC_AT, KC_UNDS, KC_TILD, KC_CIRC, KC_PIPE, KC_AMPR, KC_DLR,  KC_SLSH, KC_PERC, KC_COLN, _______,
		_______, KC_LT, KC_LBRC, KC_LCBR, KC_LPRN, KC_EXLM, KC_EQL,  KC_RPRN, KC_RCBR, KC_RBRC, KC_GT,   _______,
		_______, POUND, KC_BSLS, KC_HASH, KC_DQT,  KC_MINS, KC_PLUS, KC_SCLN, KC_ASTR, KC_GRV,  EURO,    KC_NO,
		_______, KC_NO, _______, _______, KC_NO,   _______, _______, _______, KC_NO,   KC_NO,   KC_NO,   KC_NO
	),
	[_FN] = LAYOUT_planck_grid(
		_______, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, RESET, _______,
		_______, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, _______,
		_______, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		_______, _______, _______, _______, KC_NO, _______, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	)
};

const uint16_t custom_keys[] = {
		// _BASE, _LOWER, _RAISE
		KC_TAB,
		KC_ESC,
		KC_SPC,
		KC_ENT,
		// _BASE
		KC_COMM,
		KC_DOT,
		KC_QUES,
		KC_QUOT,
		// _LOWER
		KC_0,
		KC_1,
		KC_2,
		KC_3,
		KC_4,
		KC_5,
		KC_6,
		KC_7,
		KC_8,
		KC_9,
		KC_ASTERISK,
		KC_SLASH,
		KC_PLUS,
		KC_MINS,
		KC_DOT,
		KC_COMM,
		KC_EQL,
		// _RAISE
		KC_AT,
		KC_UNDS,
		KC_TILD,
		KC_CIRC,
		KC_PIPE,
		KC_AMPR,
		KC_DLR,
		KC_SLSH,
		KC_PERC,
		KC_COLN,
		KC_LT,
		KC_LBRC,
		KC_LCBR,
		KC_LPRN,
		KC_EXLM,
		KC_EQL,
		KC_RPRN,
		KC_RCBR,
		KC_RBRC,
		KC_GT,
		KC_BSLS,
		KC_HASH,
		KC_DQT,
		KC_MINS,
		KC_PLUS,
		KC_SCLN,
		KC_ASTR,
		KC_GRV,
};

static const int custom_keys_length = sizeof custom_keys / sizeof custom_keys[0];

static bool is_custom_keycode(const uint16_t keycode) {
	for (int i = 0; i < custom_keys_length; i++) {
		if (custom_keys[i] == keycode) {
			return true;
		}
	}
	return false;
}

bool process_record_user(const uint16_t keycode, keyrecord_t *const record) {
	if (record->event.pressed) {
		switch (keycode) {
			case POUND:
				register_code16(KC_RALT);
				register_code16(KC_KP_1);
				unregister_code16(KC_KP_1);
				register_code16(KC_KP_5);
				unregister_code16(KC_KP_5);
				register_code16(KC_KP_6);
				unregister_code16(KC_KP_6);
				unregister_code16(KC_RALT);
				return false;
			case EURO:
				register_code16(KC_RALT);
				register_code16(KC_KP_0);
				unregister_code16(KC_KP_0);
				register_code16(KC_KP_1);
				unregister_code16(KC_KP_1);
				register_code16(KC_KP_2);
				unregister_code16(KC_KP_2);
				register_code16(KC_KP_8);
				unregister_code16(KC_KP_8);
				unregister_code16(KC_RALT);
				return false;
			case TERMINAL:
				register_code16(KC_LCTL);
				register_code16(KC_GRV);
				unregister_code16(KC_GRV);
				unregister_code16(KC_LCTL);
				return false;
			case WINDOW_LEFT:
				register_code16(KC_LCTL);
				register_code16(KC_LALT);
				register_code16(KC_LEFT);
				unregister_code16(KC_LEFT);
				unregister_code16(KC_LALT);
				unregister_code16(KC_LCTL);
				return false;
			case WINDOW_CENTRE:
				register_code16(KC_LCTL);
				register_code16(KC_LALT);
				register_code16(KC_C);
				unregister_code16(KC_C);
				unregister_code16(KC_LALT);
				unregister_code16(KC_LCTL);
				return false;
			case WINDOW_RIGHT:
				register_code16(KC_LCTL);
				register_code16(KC_LALT);
				register_code16(KC_RIGHT);
				unregister_code16(KC_RIGHT);
				unregister_code16(KC_LALT);
				unregister_code16(KC_LCTL);
				return false;
		}
	}
	if (is_custom_keycode(keycode)) {
		// Register keystoke on key-up rather than key-down for consistency with Auto Shift feature
		if (!record->event.pressed) {
			register_code16(keycode);
			unregister_code16(keycode);
		}
		return false;
	}
	return true;
}

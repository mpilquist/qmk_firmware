// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "atreus62.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DEFAULT 0
#define _LOWER 1
#define _RAISE 2
#define _BL 3

#define _______ KC_TRNS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DEFAULT] = { /* qwerty */
		{ KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,      KC_5,    _______, KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_DEL  },
		{ KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,    _______, KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC },
		{ KC_GESC,  KC_A,    KC_S,    KC_D,    KC_F,      KC_G,    _______, KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT },
		{ KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,    KC_LBRC, KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_ENT  },
		{ TT(_BL),  KC_LCTL, KC_LALT, KC_LGUI, TT(_LOWER),KC_SPC,  KC_RBRC, KC_SPC,  TT(_RAISE),KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT }
},

[_LOWER] = {
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______, _______, _______ },
		{ KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______, KC_CIRC, KC_AMPR,   KC_ASTR,   KC_LPRN, KC_RPRN, KC_BSPC },
		{ KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_UNDS,   KC_PLUS,   KC_LCBR, KC_RCBR, KC_PIPE },
		{ _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_F12,  S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END,  _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_MNXT,   KC_VOLD, KC_VOLU, KC_MPLY }
},

[_RAISE] = {
		{ _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______ },
		{ KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC },
		{ KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS },
		{ _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______ },
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY }
},

[_BL] = {
		{ _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______, _______, RESET   },
		{ _______, _______, KC_UP,   _______, _______, _______, _______, _______, _______,   _______,   _______, _______, _______ },
		{ _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______, _______, _______, _______,   _______,   _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, KC_LPRN, _______, _______,   _______,   _______, _______, _______ },
		{ _______, _______, _______, _______, _______, _______, KC_RPRN, _______, _______,   _______,   _______, _______, _______ }
}

/*
[_TRNS] = {
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS },
		{ KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
},
*/
};



const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
	// MACRODOWN only works in this function
	switch (id) {
	case 0:
		if (record->event.pressed) {
			register_code(KC_RSFT);
		}
		else {
			unregister_code(KC_RSFT);
		}
		break;
	}
	return MACRO_NONE;
};

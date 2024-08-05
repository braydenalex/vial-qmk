/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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

enum socd_keycodes {
  SOCD_W = QK_KB_0,
  SOCD_A,
  SOCD_S,
  SOCD_D
};

bool w_down = false;
bool a_down = false;
bool s_down = false;
bool d_down = false;

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, KC_MPLY, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_MPRV, KC_MSTP, KC_MNXT
    ),

    [2] = LAYOUT( // Gaming layer
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    SOCD_W,  KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, SOCD_A,  SOCD_S,  SOCD_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_NO, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
	
    [3] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),
	

};
// clang-format on

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
	
	if (layer_state_is(2)) {
        // Set the color for W, A, S, D keys when layer 2 is active
        RGB_MATRIX_INDICATOR_SET_COLOR(14, 255, 0, 0); // W
        RGB_MATRIX_INDICATOR_SET_COLOR(9, 255, 0, 0); // A
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 255, 0, 0); // S
        RGB_MATRIX_INDICATOR_SET_COLOR(21, 255, 0, 0); // D
	}
	
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
				RGB_MATRIX_INDICATOR_SET_COLOR(3, 255, 0, 0); //CAPSLOCK KEY
				RGB_MATRIX_INDICATOR_SET_COLOR(67, 255, 0, 0);      //LEFT LED 01
				RGB_MATRIX_INDICATOR_SET_COLOR(68, 255, 0, 0);      //RIGHT LED 12
				RGB_MATRIX_INDICATOR_SET_COLOR(70, 255, 0, 0);    //LEFT LED 02
				RGB_MATRIX_INDICATOR_SET_COLOR(71, 255, 0, 0);    //RIGHT LED 13
				RGB_MATRIX_INDICATOR_SET_COLOR(73, 255, 0, 0);    //LEFT LED 03
				RGB_MATRIX_INDICATOR_SET_COLOR(74, 255, 0, 0);    //RIGHT LED 14
				RGB_MATRIX_INDICATOR_SET_COLOR(76, 255, 0, 0);      //LEFT LED 04
				RGB_MATRIX_INDICATOR_SET_COLOR(77, 255, 0, 0);      //RIGHT LED 15
				RGB_MATRIX_INDICATOR_SET_COLOR(80, 255, 0, 0);      //LEFT LED 05
				RGB_MATRIX_INDICATOR_SET_COLOR(81, 255, 0, 0);      //RIGHT LED 16
				RGB_MATRIX_INDICATOR_SET_COLOR(83, 255, 0, 0);     //LEFT LED 06
				RGB_MATRIX_INDICATOR_SET_COLOR(84, 255, 0, 0);     //RIGHT LED 17
				RGB_MATRIX_INDICATOR_SET_COLOR(87, 255, 0, 0);    //LEFT LED 07
				RGB_MATRIX_INDICATOR_SET_COLOR(88, 255, 0, 0);    //RIGHT LED 18
				RGB_MATRIX_INDICATOR_SET_COLOR(91, 255, 0, 0);  //LEFT LED 08
				RGB_MATRIX_INDICATOR_SET_COLOR(92, 255, 0, 0);  //Right LED 19
			}
		}
	}
	return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SOCD_W:
        if (record->event.pressed) {
            if (s_down) {
                unregister_code(KC_S);
            }
            register_code(KC_W);
            w_down = true;
        } else {
            unregister_code(KC_W);
            w_down = false;

            if (s_down) {
                register_code(KC_S);
            }

        }
        return false;
        break;
    case SOCD_A:
        if (record->event.pressed) {
            if (d_down) {
                unregister_code(KC_D);
            }
            register_code(KC_A);
            a_down = true;
        } else {
            unregister_code(KC_A);
            a_down = false;

            if (d_down) {
                register_code(KC_D);
            }

        }
        return false;
        break;
    case SOCD_S:
        if (record->event.pressed) {
            if (w_down) {
                unregister_code(KC_W);
            }
            register_code(KC_S);
            s_down = true;
        } else {
            unregister_code(KC_S);
            s_down = false;

            if (w_down) {
                register_code(KC_W);
            }

        }
        return false;
        break;
    case SOCD_D:
        if (record->event.pressed) {
            if (a_down) {
                unregister_code(KC_A);
            }
            register_code(KC_D);
            d_down = true;
        } else {
            unregister_code(KC_D);
            d_down = false;

            if (a_down) {
                register_code(KC_A);
            }
        }
        return false;
        break;
    }
    return true;
}

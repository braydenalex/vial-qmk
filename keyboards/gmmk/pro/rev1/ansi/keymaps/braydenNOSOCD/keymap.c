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
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           TG(3),
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT( // Mac layer
        KC_ESC,  KC_F1,   KC_F2,   KC_MCTL, KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_EJCT,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_F13,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                             KC_RCMD, MO(2), KC_RCTL,   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [2] = LAYOUT( // RGB layer
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_TOG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, RESET,            _______,
        _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, TG(1), _______, _______, _______,          _______, KC_MPLY, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_MPRV, KC_MSTP, KC_MNXT
    ),

    [3] = LAYOUT( // Gaming layer
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           TG(3),
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,  KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,  KC_S,  KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_NO, KC_LALT,                            KC_SPC,                             KC_RALT, MO(2),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

};
// clang-format on

// RGB led number layout, function of the key

//  67, led 01   0, ESC    6, F1      12, F2      18, F3   23, F4   28, F5      34, F6   39, F7   44, F8      50, F9   56, F10   61, F11    66, F12    69, Prt       Rotary(Mute)   68, led 12
//  70, led 02   1, ~      7, 1       13, 2       19, 3    24, 4    29, 5       35, 6    40, 7    45, 8       51, 9    57, 0     62, -_     78, (=+)   85, BackSpc   72, Home       71, led 13
//  73, led 03   2, Tab    8, Q       14, W       20. E    25, R    30, T       36, Y    41, U    46, I       52, O    58, P     63, [{     89, ]}     93, \|        75, PgUp       74, led 14
//  76, led 04   3, Caps   9, A       15, S       21, D    26, F    31, G       37, H    42, J    47, K       53, L    59, ;:    64, '"                96, Enter     86, PgDn       77, led 15
//  80, led 05   4, Sh_L   10, Z      16, X       22, C    27, V    32, B       38, N    43, M    48, ,<      54, .<   60, /?               90, Sh_R   94, Up        82, End        81, led 16
//  83, led 06   5, Ct_L   11,Win_L   17, Alt_L                     33, SPACE                     49, Alt_R   55, FN             65, Ct_R   95, Left   97, Down      79, Right      84, led 17
//  87, led 07                                                                                                                                                                      88, led 18
//  91, led 08                                                                                                                                                                      92, led 19

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

	if (layer_state_is(3)) {
        // Set the color for gaming keys when layer 2 is active
        RGB_MATRIX_INDICATOR_SET_COLOR(8, 213, 109, 255); // Q
        RGB_MATRIX_INDICATOR_SET_COLOR(14, 213, 109, 255); // W
        RGB_MATRIX_INDICATOR_SET_COLOR(20, 213, 109, 255); // E
        RGB_MATRIX_INDICATOR_SET_COLOR(25, 213, 109, 255); // R
        RGB_MATRIX_INDICATOR_SET_COLOR(9, 213, 109, 255); // A
        RGB_MATRIX_INDICATOR_SET_COLOR(15, 213, 109, 255); // S
        RGB_MATRIX_INDICATOR_SET_COLOR(21, 213, 109, 255); // D
        RGB_MATRIX_INDICATOR_SET_COLOR(26, 213, 109, 255); // F
        RGB_MATRIX_INDICATOR_SET_COLOR(10, 213, 109, 255); // Z
        RGB_MATRIX_INDICATOR_SET_COLOR(16, 213, 109, 255); // X
        RGB_MATRIX_INDICATOR_SET_COLOR(22, 213, 109, 255); // C
        RGB_MATRIX_INDICATOR_SET_COLOR(27, 213, 109, 255); // V
        RGB_MATRIX_INDICATOR_SET_COLOR(67, 213, 109, 255);      //LEFT LED 01
		RGB_MATRIX_INDICATOR_SET_COLOR(68, 213, 109, 255);      //RIGHT LED 12
		RGB_MATRIX_INDICATOR_SET_COLOR(70, 213, 109, 255);    //LEFT LED 02
		RGB_MATRIX_INDICATOR_SET_COLOR(71, 213, 109, 255);    //RIGHT LED 13
		RGB_MATRIX_INDICATOR_SET_COLOR(73, 213, 109, 255);    //LEFT LED 03
		RGB_MATRIX_INDICATOR_SET_COLOR(74, 213, 109, 255);    //RIGHT LED 14
		RGB_MATRIX_INDICATOR_SET_COLOR(76, 213, 109, 255);      //LEFT LED 04
		RGB_MATRIX_INDICATOR_SET_COLOR(77, 213, 109, 255);      //RIGHT LED 15
		RGB_MATRIX_INDICATOR_SET_COLOR(80, 213, 109, 255);      //LEFT LED 05
		RGB_MATRIX_INDICATOR_SET_COLOR(81, 213, 109, 255);      //RIGHT LED 16
		RGB_MATRIX_INDICATOR_SET_COLOR(83, 213, 109, 255);     //LEFT LED 06
		RGB_MATRIX_INDICATOR_SET_COLOR(84, 213, 109, 255);     //RIGHT LED 17
		RGB_MATRIX_INDICATOR_SET_COLOR(87, 213, 109, 255);    //LEFT LED 07
		RGB_MATRIX_INDICATOR_SET_COLOR(88, 213, 109, 255);    //RIGHT LED 18
		RGB_MATRIX_INDICATOR_SET_COLOR(91, 213, 109, 255);  //LEFT LED 08
		RGB_MATRIX_INDICATOR_SET_COLOR(92, 213, 109, 255);  //RIGHT LED 19
	}

    if (layer_state_is(1)) {
        // Set colors for mac layer
        RGB_MATRIX_INDICATOR_SET_COLOR(67, 255, 0, 0);      //Left LED 01
        RGB_MATRIX_INDICATOR_SET_COLOR(68, 255, 0, 0);      //Right LED 12
        RGB_MATRIX_INDICATOR_SET_COLOR(70, 255, 127, 0);    //Left LED 02
        RGB_MATRIX_INDICATOR_SET_COLOR(71, 255, 127, 0);    //Right LED 13
        RGB_MATRIX_INDICATOR_SET_COLOR(73, 255, 255, 0);    //Left LED 03
        RGB_MATRIX_INDICATOR_SET_COLOR(74, 255, 255, 0);    //Right LED 14
        RGB_MATRIX_INDICATOR_SET_COLOR(76, 0, 255, 0);      //Left LED 04
        RGB_MATRIX_INDICATOR_SET_COLOR(77, 0, 255, 0);      //Right LED 15
        RGB_MATRIX_INDICATOR_SET_COLOR(80, 0, 0, 255);      //Left LED 05
        RGB_MATRIX_INDICATOR_SET_COLOR(81, 0, 0, 255);      //Right LED 16
        RGB_MATRIX_INDICATOR_SET_COLOR(83, 46, 43, 95);     //Left LED 06
        RGB_MATRIX_INDICATOR_SET_COLOR(84, 46, 43, 95);     //Right LED 17
        RGB_MATRIX_INDICATOR_SET_COLOR(87, 139, 0, 255);    //Left LED 07
        RGB_MATRIX_INDICATOR_SET_COLOR(88, 139, 0, 255);    //Right LED 18
        RGB_MATRIX_INDICATOR_SET_COLOR(91, 255, 255, 255);  //Left LED 08
        RGB_MATRIX_INDICATOR_SET_COLOR(92, 255, 255, 255);  //Right LED 19
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
				RGB_MATRIX_INDICATOR_SET_COLOR(92, 255, 0, 0);  //RIGHT LED 19
			}
		}
	}
	return false;
}

/* Copyright 2021 Gigahawk
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


#pragma once

#define DRIVER_1_LED_TOTAL 66
#define DRIVER_2_LED_TOTAL 32
#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)

#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define FORCE_NKRO
//#define RGBLIGHT_HUE_STEP 5
//#define RGBLIGHT_SAT_STEP 17
//#define RGBLIGHT_VAL_STEP 17
#define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }

//enable RGB Matrix Effects for Vial
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

//Vial Keyboard UID
#define VIAL_KEYBOARD_UID {0x2D, 0x1F, 0x3C, 0x39, 0x0D, 0x7E, 0x18, 0x3F}
#define VIAL_UNLOCK_COMBO_ROWS { 1, 10 }
#define VIAL_UNLOCK_COMBO_COLS { 3, 4 }
#define VIAL_ENCODER_KEYCODE_DELAY 10

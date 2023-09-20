/* Copyright (C) 2023  Mark Joshwel
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LOWER | LGUI | LAlt | /Space  /       \Space \  |Enter | RAlt |LOWER |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,
                       MO(_LOWER), KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_ENT, KC_RALT, MO(_LOWER)
 ),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | F12  |  M1  | MUp  |  M2  |      |      |                    |      |  Up  |      |   7  |   8  |   9  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |CapsLk|MLeft |Mdown |MRight|      |      |-------.    ,-------| Left | Down |Right |   4  |   5  |   6  |
 * |------+------+------+------+------+------| Reset |    | Reset |------+------+------+------+------+------|
 * |LCTRL |MAccl0|MAccl1|MAccl3|      |      |-------|    |-------|      |      |      |   1  |   2  |   3  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      | APP  | LAlt | /       /       \      \  |      | RAlt |   0  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_LOWER] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_DEL,
  KC_F12,  KC_BTN1, KC_MS_U, KC_BTN2, _______, _______,                   _______,  KC_UP,   _______, KC_P7,   KC_P8,   KC_P9,
  KC_CAPS, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,                   KC_LEFT,  KC_DOWN, KC_RGHT, KC_P4,   KC_P5,   KC_P6,
  KC_LCTL, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, QK_BOOT, QK_BOOT, _______,  _______, _______, KC_P1,   KC_P2,   KC_P3,
                       _______, KC_APP, KC_LALT, _______, _______, _______, KC_RALT, KC_P0
 )
};

// encoder functionality modified from https://github.com/ergohaven/qmk_firmware/blob/master/keyboards/lily58/keymaps/eh/keymap.c
/* Copyright 2020 Naoki Katahira
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
#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}
#endif

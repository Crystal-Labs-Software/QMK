/* Copyright 2020 Aaron
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
	KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,
	KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,
	KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_BSPC,
	KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_UP,   KC_ENT,
	KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, MO(_FN), KC_MENU, KC_RCTL, KC_BSLS, KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_FN] = LAYOUT(
        KC_PWR,  KC_AUDIO_MUTE, KC_MEDIA_PLAY_PAUSE, KC_F3,  KC_F4,   KC_F5,          KC_F6,   KC_F7,     KC_F8,   KC_F9,   KC_F10,              KC_F11,            KC_BRIGHTNESS_UP,
	KC_GRV,  KC_1,          KC_2,                KC_3,   KC_4,    KC_5,           KC_6,    KC_7,      KC_8,    KC_9,    KC_0,                KC_MINS,           KC_BRIGHTNESS_DOWN,
	KC_TAB,  KC_Q,          KC_W,                KC_E,   KC_R,    KC_T,           KC_Y,    KC_U,      KC_I,    KC_O,    KC_PSCREEN,          KC_SCROLLOCK,      KC_PAUSE,
	KC_CAPS, KC_A,          KC_S,                KC_D,   KC_F,    KC_G,           KC_H,    KC_J,      KC_K,    KC_L,    KC_INSERT,           KC_HOME,           KC_PGUP,
	KC_LSFT, KC_Z,          KC_X,                KC_C,   KC_V,    KC_B,           KC_N,    KC_M,      KC_COMM, KC_RSFT, KC_END,              KC_AUDIO_VOL_UP,   KC_PGDOWN,
	KC_LCTL, KC_LGUI,       KC_LALT,             KC_SPC, KC_RALT, KC_TRANSPARENT, KC_MENU, KC_RCTL,   KC_BSLS, KC_DEL,  KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_MEDIA_NEXT_TRACK
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/* Copyright 2015-2017 Jack Humbert
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


//special keys 
#define ALTPRN	LALT_T(KC_LPRN)
#define SFTPRN	LSFT_T(KC_RPRN)
#define OS_SFT	OSM(MOD_LSFT)
#define OS_CTL	OSM(MOD_LCTL)
#define OS_ALT	OSM(MOD_LALT)
#define OS_GUI	OSM(MOD_LGUI)
#define OS_MEH	OSM(MOD_MEH)

//homerow qwerty

#define WIN_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define CTL_D LCTL_T(KC_D)
#define SFT_F LSFT_T(KC_F)
#define MEH_G MEH_T(KC_G)
#define MEH_H MEH_T(KC_H)
#define SFT_J RSFT_T(KC_J)
#define CTL_K RCTL_T(KC_K)
#define ALT_L RALT_T(KC_L)

//MOD HOME ROW COLEMAK
#define MOD_A LGUI_T(KC_A)
#define MOD_R LALT_T(KC_R)
#define MOD_S LCTL_T(KC_S)
#define MOD_T LSFT_T(KC_T)
#define MOD_G MEH_T(KC_G) 
#define MOD_M MEH_T(KC_M)
#define MOD_N RSFT_T(KC_N)
#define MOD_E RCTL_T(KC_E)
#define MOD_I RALT_T(KC_I)
#define MOD_O RGUI_T(KC_O)

//Layer Keys
#define SYMENT LT(_SYM,KC_ENT)
#define NUMSPC LT(_NUM,KC_SPC) 
#define FNBSPC LT(_FN,KC_BSPC)
#define FUNTAB LT(_FN,KC_TAB)
#define MOUBSP LT(_MOU,KC_BSPC)


//Copypaste
#define KC_CPY LCTL(KC_C)
#define KC_PST LCTL(KC_V)
#define KC_CUT LCTL(KC_X)
#define KC_UND LCTL(KC_Z)
#define KC_FND LCTL(KC_F)
 
enum planck_layers {
_QWERTY,
_COLEMAK,
_NUM,												
_FN,
_MOU,
_SYM, 
_BOARD,
_GAME,
_GAMEFXN
};

enum planck_keycodes {
QWERTY= SAFE_RANGE,
COLEMAK,
NUM,												
FN, 
SYM, 
MOU,
BOARD,
GAME,
GAMEFXN,
GAME_EXIT,
FLASK
};

enum tap_dance_actions {
  SLASHES = 0,
  RBRACK,
  LBRACK
};

enum combos {
  ZX_BKSP,
  DV_DEL
};

enum combo_events {
  YU_BSPWORD,
  LU_DELWORD,
  WF_BCKTAB,
  FP_FORTAB
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,     KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  WIN_A,   ALT_S,    CTL_D,   SFT_F,  MEH_G,   MEH_H,   SFT_J,   CTL_K,   ALT_L,   KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,     KC_C,    KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LALT, KC_LGUI,  KC_ESC,  FUNTAB, SYMENT,  NUMSPC,  MOUBSP,  KC_DEL,  KC_NO,   KC_RALT, KC_RCTL
),
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    KC_ESC,  MOD_A,   MOD_R,   MOD_S,   MOD_T,   MOD_G,   MOD_M,   MOD_N,   MOD_E,   MOD_I,   MOD_O,  KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LCTL, KC_LALT, KC_LGUI, KC_ESC,  FUNTAB,  SYMENT,  NUMSPC,  MOUBSP,  KC_DEL,  KC_NO,   KC_RALT, KC_RCTL
),

[_NUM] = LAYOUT_planck_grid( 
  KC_TAB,   KC_PGUP,         KC_HOME,        KC_UP,           KC_END,          KC_FND,          KC_EQL,          KC_7,             KC_8,             KC_9,         KC_PPLS,        KC_NO,
  KC_ESC,   LGUI_T(KC_PGDN), LALT_T(KC_LEFT),LCTL_T(KC_DOWN), LSFT_T(KC_RGHT), KC_MEH,          KC_PPLS,         RSFT_T(KC_4),     RCTL_T(KC_5),     RALT_T(KC_6), RGUI_T(KC_PMNS),KC_NO,
  KC_LSFT,  KC_UND,          KC_CUT,         KC_CPY,          KC_PST,          KC_CAPS,         KC_PAST,         KC_1,             KC_2,             KC_3,         TD(SLASHES),    KC_NO,
  KC_LCTL,  KC_LALT,         KC_LGUI,        KC_ESC,          FUNTAB,          SYMENT,          NUMSPC,          KC_0,             KC_NO,            KC_NO,       KC_NO,          KC_NO
),

[_MOU] = LAYOUT_planck_grid(
    KC_NO,   KC_WH_U, KC_WH_L,  KC_MS_U, KC_WH_R,  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_WH_D, KC_MS_L,  KC_MS_D, KC_MS_R,  KC_NO,   KC_NO,   KC_BTN1, KC_BTN2,  KC_BTN3, KC_NO,   KC_NO,
    KC_LSFT, KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,
    KC_LCTL, KC_LALT, KC_LGUI,  _______, _______,  _______, _______, _______, _______,  KC_NO,   KC_RALT, KC_RCTL
), 

[_FN] = LAYOUT_planck_grid(
  KC_NO,  KC_BRID, KC_BRIU,     KC_VOLD,     KC_VOLU,     KC_NO,     KC_PSCR,  KC_F7,    KC_F8,       KC_F9,       KC_F10,   KC_NO,
  KC_NO,  OS_GUI,  OS_ALT,      OS_CTL,      OS_SFT,      OS_MEH,    KC_SLCK,  KC_F4,    KC_F5,       KC_F6,       KC_F11,   KC_NO,
  KC_NO,  KC_MPRV, KC_MSTP,     KC_MPLY,     KC_MNXT,     KC_NO,     KC_SLCK,  KC_F1,    KC_F2,       KC_F3,       KC_F12,   KC_NO,
  KC_NO,  KC_NO,   KC_NO,       KC_NO,       _______,     _______,   _______,  _______,  _______,     _______,     KC_NO,    KC_NO
),

[_SYM] = LAYOUT_planck_grid(                       
  KC_NO,   KC_TILD,     KC_GRV,    KC_UNDS,   KC_MINS,   KC_NO,   KC_PLUS, KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_NO, 
  KC_NO,   KC_NO,       KC_LALT,   KC_LCTL,   KC_LSFT,   KC_NO,   KC_PIPE, KC_DLR,    KC_PERC,   KC_CIRC,   KC_UNDS,   KC_NO,
  KC_NO,   KC_NO,       KC_NO,     TD(LBRACK),TD(RBRACK),KC_NO,   KC_BSLS, KC_EXLM,   KC_AT,     KC_HASH,   KC_QUES,   KC_NO,
  KC_NO,   KC_NO,       KC_NO,     _______,   _______,   _______, _______, _______,   _______,   KC_NO,     KC_NO,     KC_NO 
),

[_BOARD] = LAYOUT_planck_grid(
  RESET,       KC_NO,          KC_NO,        KC_NO,    KC_NO,   KC_NO,   TERM_ON, TERM_OFF,    KC_NO,       KC_NO,      KC_NO,       COLEMAK,
  DEBUG,       KC_NO,          MU_MOD,       AU_ON,    AU_OFF,  AG_NORM, AG_SWAP, KC_NO,       KC_NO,       KC_NO,      KC_NO,       QWERTY,
  KC_PWR,      MUV_DE,         MUV_IN,       MU_ON,    MU_OFF,  MI_ON,   MI_OFF,  KC_NO,       KC_NO,       KC_NO,      KC_NO,       GAME,
  KC_SLEP,     KC_NO,          KC_NO,        _______,  _______, _______, _______, _______,     _______,     KC_NO,      KC_NO,       KC_NO
),
[_GAME] = LAYOUT_planck_grid(
    KC_1,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,               KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,               KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,               KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    KC_LALT, KC_5,    KC_4,    KC_3,    KC_2,    KC_SPC,  LT(_GAMEFXN,KC_ENT),KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_ESC
),
  
[_GAMEFXN] = LAYOUT_planck_grid( 
 
    KC_1,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    GAME_EXIT,
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LCTL, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 ,
    KC_LALT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_SPC,  _______, KC_TAB,  KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
};

#ifdef AUDIO_ENABLE
  float qwerty_song[][2]     = SONG(QWERTY_SOUND);
  float game_song[][2]  = SONG(MAJOR_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _FN, _MOU, _BOARD);
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
	case GAME:
	if (record->event.pressed) {
		#ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(game_song);
        #endif
		clear_keyboard();
		layer_on(_GAME);
		default_layer_set(_GAME);
	}
	  return false;
      break;
    case GAME_EXIT:
      if(record->event.pressed) {
		  #ifdef AUDIO_ENABLE
          stop_all_notes();
          PLAY_SONG(game_song);
        #endif
        layer_off(_NUM);
        layer_off(_FN);
        layer_off(_SYM);
		layer_off(_BOARD);
		layer_off(_GAME);
		layer_off(_GAMEFXN);
        layer_on(_QWERTY);
        default_layer_set(_QWERTY);
     }
      return false;
      break;
	 case FLASK:
      if (record->event.pressed)
      {
        SEND_STRING("12345");
      }
      return false;
      break;



      }
    return true;
};
void left_bracket (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
    register_code (KC_LSFT);
    register_code (KC_9);
  } else  if (state->count == 2) {
    register_code(KC_LBRACKET);
  } else  if (state->count == 3) {
    register_code (KC_LSFT);
    register_code (KC_LBRACKET);
  } else  if (state->count == 4) {
    register_code (KC_LSFT);
    register_code (KC_COMM);
	} else {
        reset_tap_dance (state);
    }
}
void left_bracket_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
    unregister_code (KC_LSFT);
    unregister_code (KC_9);
  } else  if (state->count == 2) {
    unregister_code(KC_LBRACKET);
  } else  if (state->count == 3) {
    unregister_code (KC_LSFT);
    unregister_code (KC_LBRACKET);
  } else  if (state->count == 4) {
    unregister_code (KC_LSFT);
    unregister_code (KC_COMM);
	} else {
        reset_tap_dance (state);
    }
}

void right_bracket (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
    register_code (KC_LSFT);
    register_code (KC_0);
  } else  if (state->count == 2) {
    register_code(KC_RBRACKET);
  } else  if (state->count == 3) {
    register_code (KC_LSFT);
    register_code (KC_RBRACKET);
  } else  if (state->count == 4) {
    register_code (KC_LSFT);
    register_code (KC_DOT);
	} else {
        reset_tap_dance (state);
    }
}
void right_bracket_reset (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
    unregister_code (KC_LSFT);
    unregister_code (KC_0);
  } else  if (state->count == 2) {
    unregister_code(KC_RBRACKET);
  } else  if (state->count == 3) {
    unregister_code (KC_LSFT);
    unregister_code (KC_RBRACKET);
  } else  if (state->count == 4) {
    unregister_code (KC_LSFT);
    unregister_code (KC_DOT);
	} else {
        reset_tap_dance (state);
    }
}


//Combo Definitions
const uint16_t PROGMEM bksp_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM bspword_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM del_combo[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM delword_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM fowardtab_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM backtab_combo[] = {KC_W, KC_F, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [ZX_BKSP] = COMBO(bksp_combo, KC_BSPC),
  [DV_DEL] = COMBO(del_combo, KC_DEL),
  [YU_BSPWORD] = COMBO_ACTION(bspword_combo),
  [LU_DELWORD] = COMBO_ACTION(delword_combo),
  [WF_BCKTAB] = COMBO_ACTION(backtab_combo),
  [FP_FORTAB] = COMBO_ACTION(fowardtab_combo)
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case YU_BSPWORD:
      if (pressed) {
        tap_code16(LCTL(KC_BSPC));
      }
      break;
    case LU_DELWORD:
      if (pressed) {
        tap_code16(LCTL(KC_DEL));
     }
      break;
    case WF_BCKTAB:
      if (pressed) {
        tap_code16(LCTL(LSFT(KC_TAB)));
     }
      break;
    case FP_FORTAB:
      if (pressed) {
        tap_code16(LCTL(KC_TAB));
     }
      break;
  }
}


//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [SLASHES]  = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BSLASH),
  [RBRACK]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, right_bracket, right_bracket_reset),
  [LBRACK]  = ACTION_TAP_DANCE_FN_ADVANCED (NULL, left_bracket, left_bracket_reset)
// Other declarations would go here, separated by commas, if you have them
};
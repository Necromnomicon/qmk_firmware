#pragma once
// default but used in macros
#define TAPPING_TERM 200

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
//#define TAPPING_FORCE_HOLD

// Auto Shift and Retro Shift (Auto Shift for Tap Hold).
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define RETRO_SHIFT 500

// Recommended for heavy chording.
#define QMK_KEYS_PER_SCAN 4


#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PREONIC_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND),\
								  SONG(MAJOR_SOUND)          }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4

// defines how many tap needed to toggle a layer
#define TAPPING_TOGGLE 3


//number of combos
#define COMBO_TERM 30
#define COMBO_COUNT 6
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_MAX_SPEED 10
#define MOUSEKEY_TIME_TO_MAX 50
#define MOUSEKEY_DELAY 50
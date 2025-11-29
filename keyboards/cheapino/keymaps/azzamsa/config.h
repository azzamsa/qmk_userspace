#pragma once

#define BOOTMAGIC_ROW 0
#define BOOTMAGIC_COLUMN 1

//
// Home-Row Modifiers

// TAPPING_TERM = max time (ms) between press and release to count as a *tap*.
// Higher value  → you can tap slower (more forgiving).
// Lower value   → you must tap faster (snappier, but easier to mis-trigger).
// Increase if taps become holds; decrease if holds feel delayed.

#undef TAPPING_TERM
#define TAPPING_TERM 200 // default

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

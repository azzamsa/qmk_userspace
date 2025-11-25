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
#define TAPPING_TERM 230

/* #define FLOW_TAP_TERM 150 */
/* #define CHORDAL_HOLD */
/* #define PERMISSIVE_HOLD */

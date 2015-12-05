#ifndef MACRO_INCLUDED
#define MACRO_INCLUDED

#include "input.h"

typedef struct MacroFrame_st MacroFrame;

/* Definitions for the Macro options */
//The size of each macro
#define MAC_1 2
#define MAC_2 4
#define MAC_3 10
#define MAC_4 1
#define MAC_5 1
#define MAC_6 1
#define MAC_7 1
#define MAC_8 1
#define MAC_9 1
#define MAC_10 1
#define MAC_11 1
#define MAC_12 1
#define MAC_13 1
#define MAC_14 1
#define MAC_15 1
#define MAC_16 1
#define MAC_17 1
#define MAC_18 1
#define MAC_19 1
#define MAC_20 1
#define MAC_21 1
#define MAC_22 1
#define MAC_23 1
#define MAC_24 1
#define MAC_25 1
#define MAC_26 1
#define MAC_27 1
#define MAC_28 1
//START OF EACH MACRO
#define MACRO1 0
#define MACRO2 MAC_1
#define MACRO3 MAC_1 + MAC_2
#define MACRO4 MAC_1 + MAC_2 + MAC_3
#define MACRO5 MAC_1 + MAC_2 + MAC_3 + MAC_4
#define MACRO6 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5
#define MACRO7 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6
#define MACRO8 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7
#define MACRO9 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8
#define MACRO10 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9
#define MACRO11 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10
#define MACRO12 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11
#define MACRO13 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12
#define MACRO14 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13
#define MACRO15 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14
#define MACRO16 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15
#define MACRO17 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16
#define MACRO18 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17
#define MACRO19 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18
#define MACRO20 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19
#define MACRO21 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20
#define MACRO22 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20 + MAC_21
#define MACRO23 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20 + MAC_21 + MAC_22
#define MACRO24 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20 + MAC_21 + MAC_22 + MAC_23
#define MACRO25 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20 + MAC_21 + MAC_22 + MAC_23 + MAC_24
#define MACRO26 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20 + MAC_21 + MAC_22 + MAC_23 + MAC_24 + MAC_25
#define MACRO27 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20 + MAC_21 + MAC_22 + MAC_23 + MAC_24 + MAC_25 + MAC_26
#define MACRO28 MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20 + MAC_21 + MAC_22 + MAC_23 + MAC_24 + MAC_25 + MAC_26 + MAC_27


struct MacroFrame_st
{
	// The current Input-Frame of the macro (e.g "The fifth frame, the sixth frame, etc.")
	unsigned int Frame;
	// The macro option (e.g. "MACRO4")
	unsigned int Macro;
};

// Gets the next frame of the macro and puts it in "output".
// Returns a bool value that is true if the returned output is
// the last last valid macro frame. Otherwise returns false.
int GetMacroInput(MacroFrame frame, Input* output);

#endif /* MACRO_INCLUDED */

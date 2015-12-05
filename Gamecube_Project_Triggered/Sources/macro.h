#ifndef MACRO_INCLUDED
#define MACRO_INCLUDED

#include "input.h"

typedef struct MacroFrame_st MacroFrame;

/* Definitions for the Macro options */
#define MACRO1 1
#define MACRO2 2
#define MACRO3 3
#define MACRO4 4
#define MACRO5 5
#define MACRO6 6
#define MACRO7 7
#define MACRO8 8
#define MACRO9 9
#define MACRO10 10
#define MACRO11 11
#define MACRO12 12
#define MACRO13 13
#define MACRO14 14
#define MACRO15 15
#define MACRO16 16
#define MACRO17 17
#define MACRO18 18
#define MACRO19 19
#define MACRO20 20
#define MACRO21 21
#define MACRO22 22
#define MACRO23 23
#define MACRO24 24
#define MACRO25 25
#define MACRO26 26
#define MACRO27 27
#define MACRO28 28

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

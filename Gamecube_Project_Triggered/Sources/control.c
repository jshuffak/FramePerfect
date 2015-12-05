#include "control.h"

Scheme* ActiveScheme = &Scheme1;

MacroFrame CurrentFrame = { 0, MACRO1 };

/* 
	Mode 0 = Echo mode
	Mode 1 = Macro mode
*/
unsigned char Mode = 0;

Input GetNextInput(Input input)
{
	return input;
}
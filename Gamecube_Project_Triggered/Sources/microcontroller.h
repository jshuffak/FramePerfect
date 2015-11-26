#ifndef MICRO_INCLUDED
#define MICRO_INCLUDED

/* Structure definitions go here */

#include <mc9s12c32.h>
#include <hidef.h>
#include "input.h"

/* Variable Declarations */

// Digital switch that enables/disables the controller and console communication 
extern int DigitalSwitch;
//Represents and counts each byte that comes from the controller output. Max should be at 64
extern byte byteCounter;
//Represents and counts 8 bits for every byte from the controller output. Set to zero for the next address 
extern byte bitcounter;
//Counting the falling edges of the signal
extern int EdgeCounter;
extern byte* FrameByte;


void initializations(void);
void outchar(char x);	// for debugging use only
char inchar(void);	// for bonus option (terminal input for setting clock)

#endif /* MICRO_INCLUDED */
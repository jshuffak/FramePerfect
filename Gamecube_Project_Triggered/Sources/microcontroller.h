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


//Functions
void initializations(void);
char inchar(void);        //Debugging
void outchar(char x);     //Debugging
void printout(char* x);   //Print a string to terminal for debugging
void shiftout(char);      //Shiftout a byte to our good friend the GAL
void delay(int);          //An arbitary delay function.  Should probably be used for debugging only
void getInput(char* readData); //Communicate with the controller and console

#endif /* MICRO_INCLUDED */
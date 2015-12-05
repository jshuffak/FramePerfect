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

//A flag to tell whether or not the packet has been communicated yet.  This should be cleared
//by control.h when it has read the flag
extern byte Transaction_Complete; 
                                  


//Functions
void initializations(void);
char inchar(void);        //Debugging
void outchar(char x);     //Debugging
void printout(char* x);   //Print a string to terminal for debugging
void shiftout(char);      //Shiftout a byte to our good friend the GAL
void delay(int);          //An arbitary delay function.  Should probably be used for debugging only


Input getInputFrame(void);  //Get the last input frame provided by the controller
void setOutputFrame(Input); //set which frame will be communicated to the console next

#endif /* MICRO_INCLUDED */
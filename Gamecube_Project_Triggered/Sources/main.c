/*
************************************************************************
 ECE 362 - Mini-Project C Source File - Fall 2015
***********************************************************************
	 	   			 		  			 		  		
 Team ID: 21

 Project Name: Frame Perfect

 Team Members:

   - Team/Doc Leader: Kyle Diekhoff      Signature: Kyle Diekhoff
   
   - Software Leader: Jordan Huffaker     Signature: Jordan Huffaker

   - Interface Leader: Eric Colter     Signature: Eric Colter

   - Peripheral Leader: Diego De La Fuente    Signature: Diego De La Fuente


 Academic Honesty Statement:  In signing above, we hereby certify that we 
 are the individuals who created this HC(S)12 source file and that we have
 not copied the work of any other student (past or present) while completing 
 it. We understand that if we fail to honor this agreement, we will receive 
 a grade of ZERO and be subject to possible disciplinary action.

***********************************************************************

 The objective of this Mini-Project is to intercept the communication
 between a GameCube and controller so that when a certain button combination
 is pressed, a frame perfect macro will be sent to the GameCube.


***********************************************************************

 List of project-specific success criteria (functionality that will be
 demonstrated):

 1. Ability to start macros with specific button combinations.

 2. Ability to switch the active macro button between X and Y.

 3. Ability to switch between schemes of macros with the D-Pad.

 4. Ability to run frame perfect macros read from flash memory.

 5. Ability to recover a connection when disconnected from the GameCube.

***********************************************************************

  Date code started: 11/21

  Update history (add an entry every time a significant change is made):

  Date: 11/25  Name: Jordan Huffaker   Update: Addition of microcontroller file.

  Date: 12/3  Name: Eric Colter   Update: Added GAL code and finished the working echo program.

  Date: 12/4  Name: Diego De La Fuente   Update: Added foundational microcontroller input and output drivers.
  
  Date: 12/5  Name: Jordan Huffaker   Update: Added main control logic and scheme functionality.
  
  Date: 12/5  Name: Kyle Diekhoff   Update: Added storage and recovery functionality.
  
  Date: 12/6  Name: Jordan Huffaker   Update: Added input masking and echoing functionality.
  
  Date: 12/7  Name: Diego De La Fuente   Update: Added some simple macros.
  
  Date: 12/7  Name: Kyle Diekhoff   Update: Now asserts macro frames 2 times instead of 3 times.
  
  Date: 12/8  Name: Jordan Huffaker   Update: Program now stores macros in flash memory.
  
  Date: 12/9  Name: Diego De La Fuente   Update: Added drill shine, fixed wave shine, and added moonwalk.
  
  Date: 12/10  Name: Jordan Huffaker   Update: Finalized schemes for Spark Challenge demonstration.


***********************************************************************
*/

#include "derivative.h"
#include "microcontroller.h"
#include "control.h"

#define CYCLESFOR40MICROWAIT 160

static void wait40MicroSeconds(void);

void main(void)
{
	initializations();

	for(;;)
	{
		// MicroController is working properly
		ClearWatchdogTimer();

		if (Transaction_Complete)
		{
			// Clear Transaction_Complete flag
			Transaction_Complete = 0;

			// Wait 40 Micro Seconds
			wait40MicroSeconds();

			// Get the next input from the control and send it out
			setOutputFrame(GetNextInput(getInputFrame()));
		}
	}
}

static void wait40MicroSeconds()
{
	int i;
	for (i = 0; i < CYCLESFOR40MICROWAIT; i++) {}
}
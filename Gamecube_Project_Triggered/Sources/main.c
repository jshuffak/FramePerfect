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
		Transaction_Complete = 1;
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
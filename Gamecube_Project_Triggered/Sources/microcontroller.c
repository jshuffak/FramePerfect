#include "microcontroller.h"

#define INITIALIZEWAIT 26666
#define ENSURESTARTWAIT 18

/* PIN Definitions */
#define DATALINE PTT_PTT4

static void waitForInitialization(void);

int DigitalSwitch = 0;
int EdgeCounter = 0;
int TimeCounter = 0; // Jordan i didn't add this into the .h file
//volatile Input* FrameInput = (Input*)malloc(sizeof(Input)); // if we are to load this in a, it needs to be a pointer to the beginning of a struct
Input FrameInputThing;
Input* FrameInput = &FrameInputThing;
byte* FrameByte = NULL; //(byte*)FrameInput;
byte byteCounter = 0;
int CurrentValue = 0;
byte bitCounter = 1;

void initializations()
{
	DisableInterrupts;
	//enable timer 
	//TSCR1 = 0x80; 
	// interrupt from wrap around disabled, counter reset by successful output compare 7, and pre scale set to 1
	//TSCR2 = 0x08; 
	// enable the output compare function
	//TIE  = 0x00; 
	//set the interrupt rate to be approximately 2ms.
	//TC7 = 50; 
	// Initiate IRQ interrupt, which has higher priority over the TIM interrupt
	INTCR_IRQE = 1;

	waitForInitialization();
	
	//Enable Interrupts
	EnableInterrupts;

}

// Waits 40 ms for the initialization routine to complete and another
// 40 micro seconds for the data line to remain high
static void waitForInitialization()
{
	unsigned int i;
	for(i = 0; i < INITIALIZEWAIT; i++) { }
	
	for(i = 0; i < ENSURESTARTWAIT; i++)
	{
		if (!DATALINE)
		{
			i = 0;
		}
	}
}

interrupt 6 void IRQ_ISR()
{

	EdgeCounter++;	//for every falling edge, add one to a counter. We want to wait to read controller data at the 25th edge
	if(EdgeCounter > 24& <= 88)
	{
		while(DATALINE) // precautionary
		{
		}
		while(TimeCounter <= 2)//according to me research, this be exactly 2ms of delay. lmao
		{
			TimeCounter++;
		}
		TimeCounter == 0;
		CurrentValue = DATALINE;
		if(CurrentValue == 1)
		{
			asm{
					ldaa FrameByte
					oraa bitCounter
					psha FrameByte
					
				}
		}
				if(bitCounter != 128) //note to Jordan, I don't know how to use labels to use branches in asm{} but if you can, be my guest. 2 microsec is actually 48 clock cycles
				{
					bitCounter = bitcounter<<1
				}
				else{
						bitCounter == 1;
						FrameByte++;
					}
				
		}
		if(EdgeCounter == 88)
			{
				EdgeCounter == 0;
				bitCounter == 1; //maybe useless code
			}
				
			
		while(!DATALINE)
		{
		}
	//	asm
	//{
				// 
		//		iny				//one cycles
			//	cpy #25			//three cycles
				//bgt controller			//one or three cycles
			//	rts
		
//	controller	movb #1, TIE_C7I // 4  clock cycles
	//			lsl bitCounter
		//		rts
//	}
	
	/* Equivalent C Code
		TIE = 0x80;
	*/
}
	
interrupt 15 void TIM_ISR(void)
{
	//asm
	//{
		//bset TFLG1, $80			// 4 clock cycles
		//ldaa FrameInput			//
		//oraa 0,bitCounter
		//psha FrameInput
		//cmpa 
		//movb #0, TIE_C7I			// 4 clock cycles
	}
	//TFLG1 = TFLG1 | 0x80; 
	//if(counterbit <8)
	//	orcc the corresponding bitcounter in the byte
	//else
	//	increment the memory by one and add one to counter so on the next byte
	
	 
	//TIE = 0x00;
}

char inchar()
{
	/* receives character from the terminal channel */
	while (!(SCISR1 & 0x20)); /* wait for input */
	return SCIDRL;
}

void outchar(char x)
{
	/* sends a character to the terminal channel */
	while (!(SCISR1 & 0x80)); /* wait for output buffer empty */
	SCIDRL = x;
}
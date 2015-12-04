#include "microcontroller.h"


#define INITIALIZEWAIT 26666
#define ENSURESTARTWAIT 18

/* PIN Definitions */
#define DATALINE PTT_PTT4

void waitForInitialization(void);





void initializations()
{
	DisableInterrupts;


/* Set the PLL speed (bus clock = 24 MHz) */
  CLKSEL = CLKSEL & 0x80; //; disengage PLL from system
  PLLCTL = PLLCTL | 0x40; //; turn on PLL
  SYNR = 0x02;            //; set PLL multiplier
  REFDV = 0;              //; set PLL divider
  while (!(CRGFLG & 0x08)){  }
  CLKSEL = CLKSEL | 0x80; //; engage PLL

/* Disable watchdog timer (COPCTL register) */
  COPCTL = 0x40   ; //COP off; RTI and COP stopped in BDM-mode

/* Initialize asynchronous serial port (SCI) for 9600 baud, interrupts off initially */
  SCIBDH =  0x00; //set baud rate to 9600
  SCIBDL =  0x9C; //24,000,000 / 16 / 156 = 9600 (approx)  
  SCICR1 =  0x00; //$9C = 156
  SCICR2 =  0x0C; //initialize SCI for program-driven operation
  DDRB   =  0x10; //set PB4 for output mode
  PORTB  =  0x10; //assert DTR pin on COM port

/* Initialize peripherals */
        
  DDRT = 0xFF;
  ATDDIEN = 0xC0;
  DDRAD = 0;
  DDRM = 0xFF;
  
/* Initialize SPI for 6Mbps*/
  SPICR1 = 0x50;
  SPICR2 = 0; 
  SPIBR = 0x10;       
            
/* Initialize interrupts */

  CRGINT = CRGINT | 0x80;
  TCTL2 = 0x40; //Toggle pin when timer goes off
  TCTL1 = 0x40;
  TSCR1 = 0x80; //Enable timer subsystem.
  TSCR2 = 0x08; //Dont prescale
    
  TIOS = 0x80;   //Set Ch 7 for output compare.
  TC7 = 11; //1ms interrupt rate
  TIE = 0;
  
  SPICR1 = 0x50;
  SPICR2 = 0x00;
  SPIBR = 0x10;        
              
              
  DDRT=0x60;
  //pin 4 will be used to read 
  PTT_PTT5 = 1; //Enable transmission gate
	
	//Enable IRQ
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


void getInput(char* readData){
  int i, currentChar;
  byte bitPos;
  
  for(currentChar=0;currentChar<8;currentChar++){
    readData[currentChar]=0;
  }
  
  for(currentChar=0;currentChar<25;currentChar++){ //blow through the console data
    while(PTT_PTT4);  //Wait for falling edge
    while(!PTT_PTT4); //Wait for rising edge
  }
  
  PTT_PTT5=0; //Cut transmission gate
  
  for(i=0;i<3;i++);
  PTT_PTT6=1; //Begin output from GAL
  for(i=0;i<5;i++);
  PTT_PTT6=0;
  
  currentChar=0;
  bitPos=1;
  while(currentChar<8){
    while(PTT_PTT4);   //Wait for falling edge
    for(i=0;i<5;i++);                 //Delay 1.25us
    
    if(PTT_PTT4)                      //Read data
      readData[currentChar] |= bitPos;
    bitPos = bitPos<<1;
    if(bitPos==0){
      currentChar++;
      bitPos=1;
    }
       
    while(!PTT_PTT4); //Ensure we are on the top edge
   }
   
   for(i=0;i<20;i++); //Hopefully we are done outputting now
   PTT_PTT5=1;        //Re-enable the trasmission gate
  
}


interrupt 6 void IRQ_ISR()
{

}
	
interrupt 15 void TIM_ISR(void)
{

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
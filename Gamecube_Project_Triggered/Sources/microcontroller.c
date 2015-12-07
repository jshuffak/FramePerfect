#define __MICROCONTROLLER
#include "microcontroller.h"

/* Constant definitions */
#define INITIALIZEWAIT 26666
#define ENSURESTARTWAIT 40

/* PIN Definitions */
#define DATALINE              PTT_PTT4
#define TRANSMISSION_GATE     PTT_PTT5
#define OUTPUT_BEGIN          PTT_PTT6

//Static function declarations

static void waitForInitialization(void);
static void getInput(char* readData);               //Communicate with the controller and console
static void shiftOutConrollerPacket(char* packet);  //Send the next packet out to the GAL

//global variables

Input InputBuffer;
Input OutputBuffer;
byte  Transaction_Complete = 0;
//byte panic = 0;






void initializations()

{
	DisableInterrupts;


	/* Set the PLL speed (bus clock = 24 MHz) */
	CLKSEL = CLKSEL & 0x80; //; disengage PLL from system
	PLLCTL = PLLCTL | 0x40; //; turn on PLL
	SYNR = 0x02;            //; set PLL multiplier
	REFDV = 0;              //; set PLL divider
	while (!(CRGFLG & 0x08)){}
	CLKSEL = CLKSEL | 0x80; //; engage PLL

	/* Disable watchdog timer (COPCTL register) */
	COPCTL = 0x40; //COP off; RTI and COP stopped in BDM-mode

	/* Initialize asynchronous serial port (SCI) for 9600 baud, interrupts off initially */
	SCIBDH = 0x00; //set baud rate to 9600
	SCIBDL = 0x9C; //24,000,000 / 16 / 156 = 9600 (approx)  
	SCICR1 = 0x00; //$9C = 156
	SCICR2 = 0x0C; //initialize SCI for program-driven operation
	DDRB = 0x10; //set PB4 for output mode
	PORTB = 0x10; //assert DTR pin on COM port

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
	DDRT = 0x62;
	//pin 4 will be used to read 
	PTT_PTT5 = 1; //Enable transmission gate

	//Enable IRQ
	INTCR_IRQE = 0;
	TRANSMISSION_GATE = 1;
	PTT_PTT1 = 1;
	waitForInitialization();
	PTT_PTT1 = 0;

	// Set the cop timer
	COPCTL = 0x41;

	//RTI Interrupt rate
	//RTICTL = 0x15; //The panic rate 600 us ish

	//Enable Interrupts
	EnableInterrupts;

}


// Waits 40 ms for the initialization routine to complete and another
// 40 micro seconds for the data line to remain high
static void waitForInitialization()
{
	unsigned int i, j;

	for (i = 0; i < INITIALIZEWAIT; i++) {
		for (j = 0; j< 10; j++){}
	}

	while (DATALINE){
	}

	for (i = 0; i < ENSURESTARTWAIT; i++)
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
	byte b;

	for (currentChar = 0; currentChar<25; currentChar++){ //blow through the console data
		while (PTT_PTT4);  //Wait for falling edge
		while (!PTT_PTT4); //Wait for rising edge
	}

	PTT_PTT5 = 0; //Cut transmission gate

	for (i = 0; i<3; i++);
	PTT_PTT6 = 1; //Begin output from GAL
	for (i = 0; i<5; i++);
	PTT_PTT6 = 0;

	currentChar = 0;
	bitPos = 1;
	while (currentChar<8){
		while (PTT_PTT4);   //Wait for falling edge
		for (i = 0; i<5; i++);                 //Delay 1.25us

		if (PTT_PTT4)                      //Read data
			readData[currentChar] |= bitPos;
		bitPos = bitPos << 1;
		if (bitPos == 0){
			currentChar++;
			bitPos = 1;
		}

		while (!PTT_PTT4); //Ensure we are on the top edge
	}

	for (i = 0; i<20; i++); //Hopefully we are done outputting now
	PTT_PTT5 = 1;        //Re-enable the trasmission gate

	for (i = 2; i <= 7; i++){
		b = readData[i];
		b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
		b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
		b = (b & 0xAA) >> 1 | (b & 0x55) << 1;  //Reverse the order of the bits
		readData[i] = b;
	}

}

static void shiftOutConrollerPacket(char* packet){
	int i;
	byte b;
	for (i = 0; i <= 1; i++) {
		b = packet[i];
		b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
		b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
		b = (b & 0xAA) >> 1 | (b & 0x55) << 1;  //Reverse the order of the bits
		shiftout(b);
	}
	for (i = 2; i <= 7; i++){
		shiftout(packet[i]);
	}
}

void ClearWatchdogTimer()
{
	ARMCOP = 0x55;
	ARMCOP = 0xAA;
}

interrupt 6 void IRQ_ISR()
{
	getInput((char*)(&InputBuffer));
	shiftOutConrollerPacket((char*)(&OutputBuffer));
	Transaction_Complete = 1;






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

void outchar(char x) {
	/* sends a character to the terminal channel */
	while (!(SCISR1 & 0x80));  /* wait for output buffer empty */
	SCIDRL = x;
}


void shiftout(char x) {

	while (!SPISR_SPTEF == 1) {
	}

	if (SPISR_SPTEF == 1) {

		SPIDR = x;

	}

}

Input getInputFrame(void) {
	int currentChar;
	Input storage = InputBuffer;

	for (currentChar = 0; currentChar<8; currentChar++){
		((char*)(&InputBuffer))[currentChar] = 0;
	}

	return storage;
}
void setOutputFrame(Input banana){


	//this be the echo dawg diggity
	OutputBuffer = banana;
	shiftOutConrollerPacket((char*)(&OutputBuffer));
}


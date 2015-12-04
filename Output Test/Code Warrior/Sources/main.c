/*
************************************************************************
 ECE 362 - Mini-Project C Source File - Fall 2015
***********************************************************************
                                                                                                                          
 Team ID: < ? >

 Project Name: < ? >

 Team Members:

   - Team/Doc Leader: < ? >      Signature: ______________________
   
   - Software Leader: < ? >      Signature: ______________________

   - Interface Leader: < ? >     Signature: ______________________

   - Peripheral Leader: < ? >    Signature: ______________________


 Academic Honesty Statement:  In signing above, we hereby certify that we 
 are the individuals who created this HC(S)12 source file and that we have
 not copied the work of any other student (past or present) while completing 
 it. We understand that if we fail to honor this agreement, we will receive 
 a grade of ZERO and be subject to possible disciplinary action.

***********************************************************************

 The objective of this Mini-Project is to .... < ? >


***********************************************************************

 List of project-specific success criteria (functionality that will be
 demonstrated):

 1.

 2.

 3.

 4.

 5.

***********************************************************************

  Date code started: < ? >

  Update history (add an entry every time a significant change is made):

  Date: < ? >  Name: < ? >   Update: < ? >

  Date: < ? >  Name: < ? >   Update: < ? >

  Date: < ? >  Name: < ? >   Update: < ? >


***********************************************************************
*/

#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <mc9s12c32.h>

/* All functions after main should be initialized here */
char inchar(void);
void outchar(char x);
void printout(char* x);
void shiftout(char);
void delay(int);

/* Important input output functions */
void shiftOutConrollerPacket(char* packet);
void getInput(char* packet);
void printPacket(char* packet);


/* Variable declarations */
char leftpb = 0;
char rghtpb = 0;
char prevpb = 0;
int  prevpbR = 0;
int  prevpbL = 0;
int  y = 0;
int twoMs = 100;
                                                                                                         

/* Special ASCII characters */
#define CR 0x0D                // ASCII return 
#define LF 0x0A                // ASCII new line 

/* LCD COMMUNICATION BIT MASKS (note - different than previous labs) */
#define RS 0x10                // RS pin mask (PTT[4])
#define RW 0x20                // R/W pin mask (PTT[5])
#define LCDCLK 0x40        // LCD EN/CLK pin mask (PTT[6])

/* LCD INSTRUCTION CHARACTERS */
#define LCDON 0x0F        // LCD initialization command
#define LCDCLR 0x01        // LCD clear display command
#define TWOLINE 0x38        // LCD 2-line enable command
#define CURMOV 0xFE        // LCD cursor move instruction
#define LINE1 0x80        // LCD line 1 cursor position
#define LINE2 0xC0        // LCD line 2 cursor position

                                    
/*                                    
***********************************************************************
 Initializations
***********************************************************************
*/

void  initializations(void) {

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
}

                                                                                      
/*                                                                                      
***********************************************************************
Main
***********************************************************************
*/
void main(void) {
char readData[8];
byte bitPos;
int currentChar;
int i;
int donk=1;
          DisableInterrupts
        initializations();                                                                              
        EnableInterrupts;
        
 PTT_PTT5 = 1; //Enable transmission gate 
 delay(48000);

 for(;;) {
  
/* < start of your main loop > */

 
 //while(PTT_PTT4==1); //Wait until start of new packet
 for(i=0;i<600;i++){ //Ensure the line is high for at least 400us (we are not in the middle of a packet when we start gathering data)
   if(PTT_PTT4==0)
      i=0;
 }
 
 
 //Read data
 getInput(readData);
 
 

//Print data to terminal if first bit is a one (it shouldn't be a one)
//if(readData[0]&0x01)
//  printPacket(readData);

//output data from GAL
shiftOutConrollerPacket(readData);


 
 
 
 
 
    

  

  
   } /* loop forever */
   
}   /* do not leave main */




/*
***********************************************************************                       
 RTI interrupt service routine: RTI_ISR
************************************************************************
*/

interrupt 7 void RTI_ISR(void)
{
          // clear RTI interrupt flag 
    CRGFLG = CRGFLG | 0x80;

}

/*
***********************************************************************                       
  TIM interrupt service routine                          
***********************************************************************
*/

interrupt 15 void TIM_ISR(void)
{
          // clear TIM CH 7 interrupt flag 
         TFLG1 = TFLG1 | 0x80; 
 

}

/*
***********************************************************************                       
  SCI interrupt service routine                                                   
***********************************************************************
*/

interrupt 20 void SCI_ISR(void)
{
 


}

/*
***********************************************************************
 Character I/O Library Routines for 9S12C32 
***********************************************************************
 Name:         inchar
 Description:  inputs ASCII character from SCI serial port and returns it
 Example:      char ch1 = inchar();
***********************************************************************
*/

char inchar(void) {
  /* receives character from the terminal channel */
        while (!(SCISR1 & 0x20)); /* wait for input */
    return SCIDRL;
}

/*
***********************************************************************
 Name:         outchar    (use only for DEBUGGING purposes)
 Description:  outputs ASCII character x to SCI serial port
 Example:      outchar('x');
***********************************************************************
*/

void outchar(char x) {
  /* sends a character to the terminal channel */
    while (!(SCISR1 & 0x80));  /* wait for output buffer empty */
    SCIDRL = x;
}

void shiftout(char x) {
  
  while(!SPISR_SPTEF == 1) {
  }
  
  if(SPISR_SPTEF == 1) {
  
    SPIDR = x;
  
  }
  
}

void delay(int x){
  int y;
  while(x!=0){
    x--;
    y=100;
    while(y!=0){
      y--;
    }
  }
  
}

void printout(char* x){
  while(*x !=0){
    outchar(*x);
    x++;
  }
}

void shiftOutConrollerPacket(char* packet){
  int i;
  byte b;
  for(i=0;i<8;i++) {
    b = packet[i];
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;  //Reverse the order of the bits
    shiftout(b);
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

void printPacket(char* readData){
  int currentChar;
  byte bitPos;
  for(currentChar=0;currentChar<8;currentChar++){
    for(bitPos=1; bitPos!=0; bitPos = bitPos<<1) {    
      outchar(((readData[currentChar] & bitPos)!=0) +'0');
    }
    outchar(' ');
  }
   outchar(LF);
   outchar(CR);
}
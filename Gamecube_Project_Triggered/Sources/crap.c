

void initializations(void)
{
	TSCR1 = 0x80; //enable timer 
	TSCR2 = 0x00 // intertupt from wrap around disabled, reset is inhibited, and prescale set to 1
	TIE  = 0x00; // enable the output compare function
	TC7 = 50;    //set the interupt rate to be approximately 2ms.
	asm
	{
		cli
		rts
	}
}

interrupt 6 void IRQ_ISR(void)
{

}

char inchar(void)
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
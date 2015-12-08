#include "control.h"

Scheme* ActiveScheme = &Scheme1;

MacroFrame CurrentFrame = { 0, MACRO1 };

// 0 for X and 1 for Y
unsigned char macroButton = 0;

/* 
	Mode 0 = Echo mode
	Mode 1 = Macro mode
*/
unsigned char Mode = 0;

static Input startMacro(int macro, Input* input)
{
	Input output = {0};

	// Set Macro Frame
	CurrentFrame.Frame = 0;
	CurrentFrame.Macro = macro;

	// Switch to macro mode
	Mode = 1;

	// Get first frame of Macro
	// If last frame enter echo mode
	if (GetMacroInput(CurrentFrame, &output, input))
		Mode = 0;

	// Increment the frame
	CurrentFrame.Frame++;

	return output;
}

static void reorganizeInput(Input* input, Input* output, unsigned char leftSlider, unsigned char rightSlider, unsigned char xJoy, unsigned char yJoy)
{
	output->Garbage = 0;
	output->Start = input->Start;
	if (macroButton)
	{
		output->Y = 0;
		output->X = input->X;
	}
	else
	{
		output->Y = input->Y;
		output->X = 0;
	}
	output->B = input->B;
	output->A = input->A;
	output->Garbage1 = 1;
	output->L = input->L;
	output->R = input->R;
	output->Z = input->Z;
	output->DUp = 0;
	output->DDown = 0;
	output->DRight = 0;
	output->DLeft = 0;
	output->JoyX = xJoy;
	output->JoyY = yJoy;
	output->CStickX = input->CStickX;
	output->CStickY = input->CStickY;
	output->LeftButt = leftSlider;
	output->RightButt = rightSlider;
}

Input GetNextInput(Input input)
{
	unsigned char leftSlider = input.LeftButt;
	unsigned char rightSlider = input.RightButt;
	unsigned char xJoy = input.JoyX;
	unsigned char yJoy = input.JoyY;
	unsigned char macrobutton;
	Input output = {0};

	// If in echo mode
	if (!Mode)
	{
		// Check which button is the macro button
		if (macroButton)
		{
			macrobutton = input.Y;
		}
		else
		{
			macrobutton = input.X;
		}
			
		// If the macro button is pressed
		if (macrobutton)
		{
			// Find the first valid macro and return the first frame of it.
			if (input.R)
				return startMacro(ActiveScheme->RightTrigger, &input);
			if (input.L)
				return startMacro(ActiveScheme->LeftTrigger, &input);
			if (input.JoyX > 225)
				return startMacro(ActiveScheme->RightArrow, &input);
			if (input.JoyY < 30)
				return startMacro(ActiveScheme->DownArrow, &input);
			if (input.JoyY > 225)
				return startMacro(ActiveScheme->UpArrow, &input);
			if (input.JoyX < 30)
				return startMacro(ActiveScheme->LeftArrow, &input);
			if (input.Z)
				return startMacro(ActiveScheme->ZButton, &input);

			leftSlider = 0;
			rightSlider = 0;
			xJoy = 128;
			yJoy = 128;
		}

		// If a D-Pad button is pressed, switch the scheme
		if (input.DUp)
			ActiveScheme = &Scheme1;
		else if (input.DDown)
			macroButton = !macroButton; // SCHEME 3 IS CURRENTLY NOT USED. MACRO BUTTON SWITCH IS!!
			// ActiveScheme = &Scheme3;
		else if (input.DRight)
			ActiveScheme = &Scheme2;
		else if (input.DLeft)
			ActiveScheme = &Scheme4;

		// Return current state of inputs from the controller masking the D-Pad and the MacroButton
		reorganizeInput(&input, &output, leftSlider, rightSlider, xJoy, yJoy);
		return output;
	}

	// If in macro mode
	else
	{
		// Get frame of Macro
		// If last frame enter echo mode
		if (GetMacroInput(CurrentFrame, &output, &input))
			Mode = 0;

		// Increment the frame
		CurrentFrame.Frame++;

		return output;
	}
}

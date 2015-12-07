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

static Input startMacro(int macro)
{
	Input output = {0};

	// Set Macro Frame
	CurrentFrame.Frame = 0;
	CurrentFrame.Macro = macro;

	// Switch to macro mode
	Mode = 1;

	// Get first frame of Macro
	// If last frame enter echo mode
	if (GetMacroInput(CurrentFrame, &output))
		Mode = 0;

	// Increment the frame
	CurrentFrame.Frame++;

	return output;
}

static void reorganizeInput(Input* input, Input* output, unsigned char leftSlider, unsigned char rightSlider)
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
	output->JoyX = input->JoyX;
	output->JoyY = input->JoyY;
	output->CStickX = input->CStickX;
	output->CStickY = input->CStickY;
	output->LeftButt = leftSlider;
	output->RightButt = rightSlider;
}

Input GetNextInput(Input input)
{
	unsigned char leftSlider = input.LeftButt;
	unsigned char rightSlider = input.RightButt;
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
				return startMacro(ActiveScheme->RightTrigger);
			if (input.L)
				return startMacro(ActiveScheme->LeftTrigger);
			if (input.JoyX > 170)
				return startMacro(ActiveScheme->RightArrow);
			if (input.JoyY < 80)
				return startMacro(ActiveScheme->DownArrow);
			if (input.JoyY > 170)
				return startMacro(ActiveScheme->UpArrow);
			if (input.JoyX < 80)
				return startMacro(ActiveScheme->LeftArrow);
			if (input.Z)
				return startMacro(ActiveScheme->ZButton);

			leftSlider = 0;
			rightSlider = 0;
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
		reorganizeInput(&input, &output, leftSlider, rightSlider);
		return output;
	}

	// If in macro mode
	else
	{
		// Get frame of Macro
		// If last frame enter echo mode
		if (GetMacroInput(CurrentFrame, &output))
			Mode = 0;

		// Increment the frame
		CurrentFrame.Frame++;

		return output;
	}
}
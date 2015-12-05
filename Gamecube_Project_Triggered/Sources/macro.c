#include "macro.h"
#define MACRO_SIZE 28
#define MAC_1 1

//Definitions
Input Macro_array[MACRO_SIZE];
Input Macro_1[MAC_1]
{ .Garbage = 0, .Start = 0, .Y = 1, .X = 0, .B = 0, .A = 0, .Garbage1 = 0, .L = 0, .R = 0, .Z = 0, .DUp = 0, .DDown = 0, .DRight = 0, .DLeft = 0, .JoyX = 0, .JoyY = 0, .CStickX = 0, .CStickY = 0, .LeftButt = 0, .RightButt = 0};


GetMacroInput(MacroFrame frame, Input* output)
{

  if(!(Macro_array[frame.Macro - 1][frame.Frame].Garbage == 3))
  {
    output->Garbage = Macro_array[frame.Macro - 1][frame.Frame].Garbage;
    output->Start = Macro_array[frame.Macro - 1][frame.Frame].Start;
    output->Y = Macro_array[frame.Macro - 1][frame.Frame].Y;
    output->X = Macro_array[frame.Macro - 1][frame.Frame].X;
    output->B = Macro_array[frame.Macro - 1][frame.Frame].B;
    output->A = Macro_array[frame.Macro - 1][frame.Frame].A;
    output->Garbage1 = Macro_array[frame.Macro - 1][frame.Frame].Garbage1;
    output->L = Macro_array[frame.Macro - 1][frame.Frame].L;
    output->R = Macro_array[frame.Macro - 1][frame.Frame].R;
    output->Z = Macro_array[frame.Macro - 1][frame.Frame].Z;
    output->DUp = Macro_array[frame.Macro - 1][frame.Frame].DUp;
    output->DDown = Macro_array[frame.Macro - 1][frame.Frame].DDown;
    output->DRight = Macro_array[frame.Macro - 1][frame.Frame].DRight;
    output->DLeft = Macro_array[frame.Macro - 1][frame.Frame].DLeft;
    output->JoyX = Macro_array[frame.Macro - 1][frame.Frame].JoyX;
    output->JoyY = Macro_array[frame.Macro - 1][frame.Frame].JoyY;
    output->CStickX = Macro_array[frame.Macro - 1][frame.Frame].CStickX;
    output->CStickY = Macro_array[frame.Macro - 1][frame.Frame].CStickY;
    output->LeftButt = Macro_array[frame.Macro - 1][frame.Frame].LeftButt;
    output->RightButt = Macro_array[frame.Macro - 1][frame.Frame].RightButt;
  }
  else
  {
    return 1;
  }
  return 0;
}



//Macro_1[0].B = 1;
//Macro_1[0].JoyY = -255;
//Macro_1[1].B = 1;
//Macro_1[1].JoyY = -255;
//Macro_1[2].B = 1;
//Macro_1[2].JoyY = -255;
//Macro_1[3].Y = 1;
//Macro_1[4].Y = 1;
//Macro_1[5].Y = 1;

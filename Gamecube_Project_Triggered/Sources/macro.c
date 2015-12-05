#include "macro.h"
#define MAC_1 1
#define MAC_2 1
#define MAC_3 1
#define MAC_4 1
#define MAC_5 1
#define MAC_6 1
#define MAC_7 1
#define MAC_8 1
#define MAC_9 1
#define MAC_10 1
#define MAC_11 1
#define MAC_12 1
#define MAC_13 1
#define MAC_14 1
#define MAC_15 1
#define MAC_16 1
#define MAC_17 1
#define MAC_18 1
#define MAC_19 1
#define MAC_20 1
#define MAC_21 1
#define MAC_22 1
#define MAC_23 1
#define MAC_24 1
#define MAC_25 1
#define MAC_26 1
#define MAC_27 1
#define MAC_28 1

//Definitions
Input Macro_array[MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20 + MAC_21 + MAC_22 + MAC_23 + MAC_24 + MAC_25 + MAC_26 + MAC_27 + MAC_28];

Macro_array[0] = { .Garbage = 0, .Start = 0, .Y = 1, .X = 0, .B = 0, .A = 0, .Garbage1 = 0, .L = 0, .R = 0, .Z = 0, .DUp = 0, .DDown = 0, .DRight = 0, .DLeft = 0, .JoyX = 0, .JoyY = 0, .CStickX = 0, .CStickY = 0, .LeftButt = 0, .RightButt = 0};


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





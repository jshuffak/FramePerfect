#include "macro.h"

//Definitions
Input Macro_array[MAC_1 + MAC_2 + MAC_3 + MAC_4 + MAC_5 + MAC_6 + MAC_7 + MAC_8 + MAC_9 + MAC_10 + MAC_11 + MAC_12 + MAC_13 + MAC_14 + MAC_15 + MAC_16 + MAC_17 + MAC_18 + MAC_19 + MAC_20 + MAC_21 + MAC_22 + MAC_23 + MAC_24 + MAC_25 + MAC_26 + MAC_27 + MAC_28]
  = { 
      {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,255,0,0,0,0},
      {3,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0}


        
  };




GetMacroInput(MacroFrame frame, Input* output)
{


  output->Garbage = 0;
  output->Start = Macro_array[(int)frame.Frame/3 + frame.Macro].Start;
  output->Y = Macro_array[(int)frame.Frame/3 + frame.Macro].Y;
  output->X = Macro_array[(int)frame.Frame/3 + frame.Macro].X;
  output->B = Macro_array[(int)frame.Frame/3 + frame.Macro].B;
  output->A = Macro_array[(int)frame.Frame/3 + frame.Macro].A;
  output->Garbage1 = 1;
  output->L = Macro_array[(int)frame.Frame/3 + frame.Macro].L;
  output->R = Macro_array[(int)frame.Frame/3 + frame.Macro].R;
  output->Z = Macro_array[(int)frame.Frame/3 + frame.Macro].Z;
  output->DUp = Macro_array[(int)frame.Frame/3 + frame.Macro].DUp;
  output->DDown = Macro_array[(int)frame.Frame/3 + frame.Macro].DDown;
  output->DRight = Macro_array[(int)frame.Frame/3 + frame.Macro].DRight;
  output->DLeft = Macro_array[(int)frame.Frame/3 + frame.Macro].DLeft;
  output->JoyX = Macro_array[(int)frame.Frame/3 + frame.Macro].JoyX;
  output->JoyY = Macro_array[(int)frame.Frame/3 + frame.Macro].JoyY;
  output->CStickX = Macro_array[(int)frame.Frame/3 + frame.Macro].CStickX;
  output->CStickY = Macro_array[(int)frame.Frame/3 + frame.Macro].CStickY;
  output->LeftButt = Macro_array[(int)frame.Frame/3 + frame.Macro].LeftButt;
  output->RightButt = Macro_array[(int)frame.Frame/3 + frame.Macro].RightButt;
  if(!(Macro_array[(int)frame.Frame/3].Garbage == 3))
  {
    
    return 1;
    
  }

  return 0;
}





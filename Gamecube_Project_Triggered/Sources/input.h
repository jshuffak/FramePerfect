#ifndef INPUT_INCLUDED
#define INPUT_INCLUDED

typedef struct Input_st Input;

struct Input_st
{
	// BYTE 1
	unsigned char Garbage   :3;
	unsigned char Start     :1;
	unsigned char Y         :1;
	unsigned char X         :1;
	unsigned char B         :1;
	unsigned char A         :1;
	// BYTE 2
	unsigned char Garbage1  :1;
	unsigned char L         :1;
	unsigned char R         :1;
	unsigned char Z         :1;
	unsigned char DUp       :1;
	unsigned char DDown     :1;
	unsigned char DRight    :1;
	unsigned char DLeft     :1;
	// BYTE 3
	unsigned char JoyX      :8;
	// BYTE 4
	unsigned char JoyY      :8;
	// BYTE 5
	unsigned char CStickX   :8;
	// BYTE 6
	unsigned char CStickY   :8;
	// BYTE 7
	unsigned char LeftButt  :8;
	// BYTE 8
	unsigned char RightButt :8;
};

//extern volatile Input* FrameInput;


#endif /* INPUT_INCLUDED */
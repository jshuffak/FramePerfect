#ifndef SCHEME_INCLUDED
#define SCHEME_INCLUDED

#include "macro.h"

typedef struct Scheme_st Scheme;

struct Scheme_st
{
	unsigned char RightTrigger;
	unsigned char LeftTrigger;
	unsigned char RightArrow;
	unsigned char UpArrow;
	unsigned char DownArrow;
	unsigned char LeftArrow;
	unsigned char ZButton;
};

extern Scheme Scheme1 = { MACRO1, MACRO2, MACRO3, MACRO4, MACRO5, MACRO6, MACRO7 };
extern Scheme Scheme2 = { MACRO8, MACRO9, MACRO10, MACRO11, MACRO12, MACRO13, MACRO14 };
extern Scheme Scheme3 = { MACRO15, MACRO16, MACRO17, MACRO18, MACRO19, MACRO20, MACRO21 };
extern Scheme Scheme4 = { MACRO22, MACRO23, MACRO24, MACRO25, MACRO26, MACRO27, MACRO28 };

#endif /* SCHEME_INCLUDED */
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

extern Scheme Scheme1;
extern Scheme Scheme2;
extern Scheme Scheme3;
extern Scheme Scheme4;

#endif /* SCHEME_INCLUDED */
#ifndef _gate__h_
#define _gate__h_

#include "../bit/bit.h"

char AND(char in1,char in2);
char OR(char in1,char in2);
char NOT(char in);
char NOR(char in1,char in2);
char NAND(char in1,char in2);
char XOR(char in1,char in2);
char XNOR(char in1,char in2);

void AND_TTF(char in);
void OR_TTF(char in);
void NOT_TTF(char in);
void NOR_TTF(char in);
void NAND_TTF(char in);
void XOR_TTF(char in);
void XNOR_TTF(char in);

#endif

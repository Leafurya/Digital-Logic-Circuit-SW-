#ifndef _adder__h_
#define _adder__h_

#include "../bit/bit.h"
#include "../gate/gate.h"

block HalfAdder(char in1,char in2);
block FullAdder(char in1,char in2,char in3);
block Adder(block in1,block in2,char opBit);
void HalfAdder_TTF(char in);
void FullAdder_TTF(char in);

#endif

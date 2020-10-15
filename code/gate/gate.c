#include "gate.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char AND(char in1,char in2){
	return in1&in2;
}
char OR(char in1,char in2){
	return in1|in2;
}
char NOT(char in){
	return !in;
}
char NOR(char in1,char in2){
	return NOT(OR(in1,in2));
}
char NAND(char in1,char in2){
	return NOT(AND(in1,in2));
}
char XOR(char in1,char in2){
	return OR(AND(NOT(in1),in2),AND(in1,NOT(in2)));
}
char XNOR(char in1,char in2){
	return OR(AND(NOT(in1),NOT(in2)),AND(in1,in2));
}

void AND_TTF(char in){
	printf("%d\n",AND(BitPOP((block *)&in),BitPOP((block *)&in)));
}
void OR_TTF(char in){
	printf("%d\n",OR(BitPOP((block *)&in),BitPOP((block *)&in)));
}
void NOT_TTF(char in){
	printf("%d\n",NOT(BitPOP((block *)&in)));
}
void NOR_TTF(char in){
	printf("%d\n",NOR(BitPOP((block *)&in),BitPOP((block *)&in)));
}
void NAND_TTF(char in){
	printf("%d\n",NAND(BitPOP((block *)&in),BitPOP((block *)&in)));
}
void XOR_TTF(char in){
	printf("%d\n",XOR(BitPOP((block *)&in),BitPOP((block *)&in)));
}
void XNOR_TTF(char in){
	printf("%d\n",XNOR(BitPOP((block *)&in),BitPOP((block *)&in)));
}

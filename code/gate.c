#include "gate.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _bit{
	unsigned int bit : 1;
}Bit;

char And(char in1,char in2){
	return in1&in2;
}
char Or(char in1,char in2){
	return in1|in2;
}
char Not(char in){
	return !in;
}
char Nor(char in1,char in2){
	return Not(Or(in1,in2));
}

void TruthTable(int inCount,void (*func)(char *ins)){
	int bits=0, tbits=0;
	int insCount=pow(2,inCount);
	char *ins=(char *)calloc(inCount,sizeof(char));
	Bit bit;
	int i,j;
	
	for(j=0;j<insCount;j++){
		for(i=0;i<inCount;i++){
			bit.bit=tbits;
			ins[i]=(char)bit.bit;
			tbits=tbits>>1;
		}
		bits++;
		tbits=bits;
		bit.bit=0;
		func(ins);
	}
	free(ins);
}

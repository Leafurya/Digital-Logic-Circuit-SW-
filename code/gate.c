#include "gate.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _bit{
	unsigned int bit : 1;
}Bit;

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

void TruthTable(int inCount,char (*gate)(char *ins)){
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
		for(i=inCount-1;i>=0;i--){
			printf("%d ",ins[i]);
		}
		bits++;
		tbits=bits;
		bit.bit=0;
		printf("%d\n",gate(ins));
	}
	free(ins);
}

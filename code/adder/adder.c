#include "../digitallogic.h"

#include <stdlib.h>
#include <stdio.h>

char HalfAdder(char in1,char in2){
	char output=0;
	
	BitPUSH(&output,XOR(in1,in2));
	BitPUSH(&output,AND(in1,in2));
	
	return output;
}
char FullAdder(char in1,char in2,char in3){
	char output=0;
	
	BitPUSH(&output,XOR(XOR(in1,in2),in3));
	BitPUSH(&output,OR(OR(AND(in1,in2),AND(in1,in3)),AND(in2,in3)));
	
	return output;
}
char ParallelAdder(char in1,char in2,int nBit){
	char result=0,tresult=0;
	char carry=0;
	int i;
	
	for(i=nBit;i>0;i--){
		tresult=FullAdder(BitPOP(&in1),BitPOP(&in2),carry);
		carry=BitPOP(&tresult);
		BitPUSH(&result,BitPOP(&tresult));
	}
	BitPUSH(&result,carry);
	result=BitReverse(result,nBit+1);
	
	return result;
}

void HalfAdder_TTF(char in){
	char result=HalfAdder(BitPOP(&in),BitPOP(&in));
	printf("%d %d\n",BitPOP(&result),BitPOP(&result));
}
void FullAdder_TTF(char in){
	char result=FullAdder(BitPOP(&in),BitPOP(&in),BitPOP(&in));
	printf("%d %d\n",BitPOP(&result),BitPOP(&result));
}

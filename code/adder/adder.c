#include "adder.h"
#include <stdlib.h>
#include <stdio.h>

block HalfAdder(char in1,char in2){
	block output=0;
	
	BitPUSH(&output,XOR(in1,in2));
	BitPUSH(&output,AND(in1,in2));
	
	return output;
}
block FullAdder(char in1,char in2,char in3){
	block output=0;
	
	BitPUSH(&output,XOR(XOR(in1,in2),in3));
	BitPUSH(&output,OR(OR(AND(in1,in2),AND(in1,in3)),AND(in2,in3)));
	
	return output;
}
block Adder(block in1,block in2,char opBit){
	block result=0,tresult=0;
	char carry=opBit;
	int i;
	
	for(i=BLOCK_SIZE;i>0;i--){
		tresult=FullAdder(BitPOP(&in1),XOR(BitPOP(&in2),opBit),carry);
		carry=BitPOP(&tresult);
		BitPUSH(&result,BitPOP(&tresult));
		
	}
	result=BitReverse(result,sizeof(block)*8);
	
	return result;
}

void HalfAdder_TTF(char in){
	block result=HalfAdder(BitPOP((block *)&in),BitPOP((block *)&in));
	printf("%d %d\n",BitPOP(&result),BitPOP(&result));
}
void FullAdder_TTF(char in){
	block result=(block)FullAdder(BitPOP((block *)&in),BitPOP((block *)&in),BitPOP((block *)&in));
	printf("%d %d\n",BitPOP(&result),BitPOP(&result));
}

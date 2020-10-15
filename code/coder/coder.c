#include "coder.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

block Decoder(block in,int nBit){
	block d=0;
	block tin=in,ttin=0;
	int i,j;
	char n=1;
	
	for(i=0;i<pow(2,nBit);i++){
		for(j=0,ttin=(block)i;j<nBit;j++){
			n=AND(XOR(BitPOP(&tin),BitPOP(&ttin)),n);
		}
		BitPUSH(&d,n);
		n=1;
		tin=in;
	}
	return d;
}
/*block _2x4Decoder(block in,int nBit){
	block tin=in;
	block d=0;
	
	char a=BitPOP(&in);
	char b=BitPOP(&in);
	
	BitPUSH(&d,AND(NOT(a),NOT(b)));
	BitPUSH(&d,AND(a,NOT(b)));
	BitPUSH(&d,AND(NOT(a),b));
	BitPUSH(&d,AND(a,b));
	
	return d;
}
block _3x8Decoder(block in,int nBit){
	block tin=in;
	block d=0;
	char a=BitPOP(&in);
	char b=BitPOP(&in);
	char c=BitPOP(&in);
	
	BitPUSH(&d,AND(NOT(a),AND(NOT(b),NOT(c))));
	BitPUSH(&d,AND(a,AND(NOT(b),NOT(c))));
	BitPUSH(&d,AND(NOT(a),AND(b,NOT(c))));
	BitPUSH(&d,AND(a,AND(b,NOT(c))));
	BitPUSH(&d,AND(NOT(a),AND(NOT(b),c)));
	BitPUSH(&d,AND(a,AND(NOT(b),c)));
	BitPUSH(&d,AND(NOT(a),AND(b,c)));
	BitPUSH(&d,AND(a,AND(b,c)));
	
	return d;
}*/
void _2x4Decoder_TTF(char in){
	block result=Decoder(in,2);
	printf("%d %d %d %d\n",BitPOP(&result),BitPOP(&result),BitPOP(&result),BitPOP(&result));
}
void _3x8Decoder_TTF(char in){
	int nIn=5;
	block result=BitReverse(Decoder(in,nIn),pow(2,nIn));
	int i;
	for(i=0;i<pow(2,nIn);i++){
		printf("%d ",BitPOP(&result));
	}
	printf("\n");
}

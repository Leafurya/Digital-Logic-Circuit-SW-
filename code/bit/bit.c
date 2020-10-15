#include "bit.h"
#include <math.h>
#include <stdio.h>
#include <string.h>

char BitPOP(block *byte){
	char bit=0;
	
	bit=*byte&1;
	*byte>>=1;
	
	return bit;
}
void BitPUSH(block *byte,char bit){
	*byte<<=1;
	*byte+=bit;
}
char BitTop(block byte){
	return byte&1;
}
block BitReverse(block byte,int size){
	block bit=0;
	
	for(;size>0;size--){
		BitPUSH(&bit,BitPOP(&byte));
	}
	
	return bit;
}

void TruthTable(char *inVal,char *outVal,void (*TruthTableFunc)(char in)){
	block in,tin;
	int nIn=strlen(inVal);
	int nIns=pow(2,nIn);
	int i;
	
	for(i=0;i<nIn;i++){
		printf("%c ",inVal[i]);
	}
	printf("| ");
	for(i=0;i<strlen(outVal);i++){
		printf("%c ",outVal[i]);
	}
	printf("\n");
	
	for(in=0;in<nIns;in++){
		tin=BitReverse(in,nIn);
		for(i=nIn;i>0;i--){
			printf("%d ",BitPOP(&tin));
		}
		printf("| ");
		TruthTableFunc(in);
	}
}

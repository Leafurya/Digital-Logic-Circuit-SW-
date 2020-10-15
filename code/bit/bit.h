#ifndef _bit__h_
#define _bit__h_

typedef int block;
#define BLOCK_SIZE	(sizeof(block)*8)

char BitPOP(block *byte);
void BitPUSH(block *byte,char bit);
block BitReverse(block byte,int size);
char BitTop(block byte);
void TruthTable(char *inVal,char *outVal,void (*TruthTableFunc)(char in));

#endif

#ifndef _bit__h_
#define _bit__h_

char BitPOP(char *byte);
void BitPUSH(char *byte,char bit);
char BitReverse(char byte,int size);
char BitTop(char byte);
void TruthTable(char *inVal,char *outVal,void (*TruthTableFunc)(char in));

#endif

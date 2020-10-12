#ifndef _gate__h_
#define _gate__h_

char AND(char in1,char in2);
char OR(char in1,char in2);
char NOT(char in);
char NOR(char in1,char in2);
char NAND(char in1,char in2);
char XOR(char in1,char in2);

void TruthTable(int inCount,char (*gate)(char *ins));

#endif

#ifndef _gate__h_
#define _gate__h_

char And(char in1,char in2);
char Or(char in1,char in2);
char Not(char in);
char Nor(char in1,char in2);


void TruthTable(int inCount,void (*func)(char *ins));

#endif

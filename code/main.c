#include <stdio.h>
#include <stdlib.h>

#include "gate.h"

char TruthTableFunc(char *in);

int main() {
	TruthTable(2,TruthTableFunc);
	return 0;
}

char TruthTableFunc(char *in){
	return XNOR(in[0],in[1]);
}

#include <stdio.h>
#include <stdlib.h>

#include "gate.h"

void func(char *ins){
	printf("%d %d %d\n",ins[1],ins[0],Nor(ins[0],ins[1]));
}

int main() {
	TruthTable(2,func);
	return 0;
}

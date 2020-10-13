#include <stdio.h>
#include <stdlib.h>

#include "digitallogic.h"

int main() {
	printf("AND\n");
	TruthTable("XY","F",AND_TTF);
	printf("\nOR\n");
	TruthTable("XY","F",OR_TTF);
	printf("\nNOT\n");
	TruthTable("X","F",NOT_TTF);
	printf("\nNOR\n");
	TruthTable("XY","F",NOR_TTF);
	printf("\nNAND\n");
	TruthTable("XY","F",NAND_TTF);
	printf("\nXOR\n");
	TruthTable("XY","F",XOR_TTF);
	printf("\nXNOR\n");
	TruthTable("XY","F",XNOR_TTF);
	printf("\nHalfAdder\n");
	TruthTable("XYZ","SC",HalfAdder_TTF);
	printf("\nFullAdder\n");
	TruthTable("XYZ","SC",FullAdder_TTF);
	printf("\nParallelAdder 0101(5) + 1101(13)\n");
	printf("%d\n",ParallelAdder(5,13,4));
	return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "digitallogic.h"

int main() {
	block sum;
	int i;
	
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
	TruthTable("XY","SC",HalfAdder_TTF);
	printf("\nFullAdder\n");
	TruthTable("XYZ","SC",FullAdder_TTF);
	
	printf("\nAdder 0000 0101(5) - 0000 1101(13) = 1111 1000(-8)\n");
	sum=Adder(5,13,1);
	printf("%d(",sum);
	sum=BitReverse(sum,BLOCK_SIZE);
	for(i=0;i<BLOCK_SIZE;i++){
		printf("%d",BitPOP(&sum));
	}
	printf(")\n");
	
	printf("\nAdder 0000 0101(5) + 0000 1101(13) = 0001 0010(18)\n");
	sum=Adder(5,13,0);
	printf("%d(",sum);
	sum=BitReverse(sum,BLOCK_SIZE);
	for(i=0;i<BLOCK_SIZE;i++){
		printf("%d",BitPOP(&sum));
	}
	printf(")\n");
	
	printf("\ndecoder\n");
	TruthTable("AB","3210",_2x4Decoder_TTF);
	
	printf("\ndecoder\n");
	TruthTable("ABCDE","fedcba9876543210",_3x8Decoder_TTF);
	return 0;
}

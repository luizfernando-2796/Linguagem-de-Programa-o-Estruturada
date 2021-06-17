//5. Desenvolva um programa que declare um vetor de inteiros e um ponteiro para inteiros. 
//Associe o ponteiro ao vetor. Agora, some mais um (+1) a cada posição do vetor usando o ponteiro (use *).

#include<stdio.h>

main(){
	int x, y;
	int *px;
	x=10;
	y=15;
	px = &x;
	printf("Valor de x: %i\n", *px);
	px = px-1;
	printf("Valor de y: %i\n", *px);
}

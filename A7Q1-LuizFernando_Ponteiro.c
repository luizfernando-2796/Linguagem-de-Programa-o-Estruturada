//1. Fa�a um programa em C que armazene em um vetor 3 valores, e imprima os valores
//utilizando nota��o de ponteiro.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

int main(){
	int v[3];
	int i;
	
	for(i=0; i<3; i++){
		printf("Digite os valores: \n");
		scanf("%d", v+i);
		printf("Valor impresso:\n");
		printf("%d\n", *(v+i));
		printf("Endereco: %x - Valor: %d\n", v+i, *(v+i));
	}
	return 0;
}


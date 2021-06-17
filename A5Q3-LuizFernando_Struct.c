//3. Escreva as instruções necessárias para definir um tipo de ESTRUTURA que contenha 2 elementos, uma “STRING” de 10 caracteres e um INTEIRO:

#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

typedef struct estrutura{
	char fruta[10];
	int qtde;
}dados;

int main(){
	dados registros[2];
	int i;
	
	printf("-----Informe os dados-----\n");
	for(i=0; i<2; i++){
	printf("\t\nNome da %i%c fruta: ", i+1, 167);
	fflush(stdin);
	fgets(registros[i].fruta, 10, stdin);
	printf("\t\nInforme a quantidade desejada: ");
	fflush(stdin);
	scanf("%i", &registros[i].qtde);
	}
	printf("\n-----Dados Registrados-----\n");
	for(i=0; i<2; i++){
		printf("\n%i%c fruta: %s", i+1, 167, registros[i].fruta );
		printf("Quantidade desejada: %i ", registros[i].qtde );
		printf(" \n");
	}
	return 0;
}




// 3- Desenvolva um programa em C que contenha um vetor contendo 5 elementos inteiros.
//Utilizando apenas nota��o de ponteiros, leia esse vetor do teclado e imprima o endere�o
//das posi��es contendo valores pares.

#include <stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int vetor[5], i;
	
	for(i=0;i<5; i++){
	printf("Digite o %d� valor:\n", i+1);
	scanf("%d", vetor+i);

	}
	puts("----Valores Digitados----");
	for(i=0;i<5; i++){
	printf(" %d \n", *(vetor+i));
	}	

	puts("----Valores Pares Encontrados----");
	for(i=0;i<5; i++){
		if(*(vetor+i)%2 == 0){
			printf("Valor: - %d -", *(vetor+i));
			printf(" Endere�o: %p\n", vetor+i);
		}
	}	
	return 0;
}

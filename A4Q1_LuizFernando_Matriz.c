//1-Escreva um programa em C que leia uma matriz 5 x 5 e um valor X. O programa deverá
//fazer uma busca desse valor na matriz e, ao final, escrever a localização (linha e coluna)
//ou uma mensagem de “não encontrado”.

#include <stdio.h>

int main (){
	int matriz[5][5];
	int L, C, valor, cont;
	
	puts("Digite os numeros que preencherao a matriz:");
	for(L=0; L<5; L++){
		for(C=0; C<5; C++){
			printf("Posicao da Linha %d - Coluna %d = ", L+1, C+1);
			scanf("%d", &matriz[L][C]);
		}
	}
	printf("Qual valor deseja buscar na matriz? Valor = ");
	scanf("%d", &valor);
	printf("\nValor = %d \n", valor);	
	for(L=0; L<5; L++){
		for(C=0; C<5; C++){
			if(valor==matriz[L][C]){
				printf("\nValor encontrado na Linha %d e Coluna %d .\n", L+1, C+1);
			}else cont++;
		}
	}
	if(cont == 25){
		printf("Valor nao encontrado!\n");
	}
	
	return 0;
	
}

//4- Desenvolva um programa em C que leia uma matriz 3 x 6 com valores reais.
//( a ) Imprima a soma de todos os elementos das colunas ímpares, ( b ) Imprima a média aritmética dos elementos da segunda e quarta colunas.
//( c ) Substitua os valores da sexta coluna pela soma dos valores das colunas 1 e 2,( d ) Imprima a matriz modificada.

#include <stdio.h>

int main(){
	
	float mA[3][6];
	int i, j;
	
	puts("Digite os numeros que preencherao a matriz:");
	for(i=0; i<3; i++){
		for(j=0; j<6; j++){
			printf("Posicao da Linha %d - Coluna %d = ", i+1, j+1);
			scanf("%d", &mA[i][j]);
		}
	}
	for(i=0; i<3; i++){
		for(j=0; j<6; j++){
		if(j==j%2==1){
			printf("")
		}
		}
	}

}

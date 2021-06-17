// 5- Desenvolva um programa em C que armazene 125 valores do tipo inteiro em uma 
//matriz de 3 (três) dimensões, essa matriz deverá ser desenvolvida em um formato parecido com um cubo. Exiba em tela o resultado obtido.

#include<stdio.h>
#include<stdlib.h>

int main(){
	int matriz[5][5][5];
	int i, j, l;
		
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			for(l=0;l<5;l++)
		matriz[i][j][l]=rand()%99;
		
	for(i=0;i<5;i++){
		printf("\n");
		for(j=0;j<5;j++){
			printf("\n");
			for(l=0;l<5;l++)
				printf("%4i", matriz[i][j][l]);
		}
	}
}

	


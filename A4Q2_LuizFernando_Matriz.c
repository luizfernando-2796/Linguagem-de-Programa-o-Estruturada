//2- Crie um programa em C para gerar uma matriz 4 x 4 com valores no intervalo [1 a 20].
//Depois transforme a matriz gerada em uma matriz triangular inferior, ou seja, atribuindo
//zero a todos os elementos acima da diagonal principal, por fim imprima a matriz original e
//a matriz transformada.

#include <stdio.h>

int main(){
	int matriz[4][4];
	int i, j;
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			matriz[i][j] = 1 + (rand()%20);
		}
	}
	printf("\t\t\tMatriz Original\n");
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			printf("\t%i\t",matriz[i][j]);
		}
		printf("\t\n");
	}
	printf("\n\t\t\tMatriz Triangular Inferior\n");
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
			if(i<j){
				matriz[i][j] = 0;
			}
			printf("\t%i\t",matriz[i][j]);
		}
		printf("\t\n");
	}
	
	return 0;	

}

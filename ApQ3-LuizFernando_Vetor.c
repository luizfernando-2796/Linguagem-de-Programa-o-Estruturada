// 3-Fa�a um algoritmo que calcule e escreva o somat�rio dos valores armazenados numa vari�vel composta unidimensional, 
//chamada dados, de at� 100 elementos num�ricos a serem lidos.

#include<stdio.h>

int main(){
	
	int dados[100];
	int i=0, soma=0;
	char continuar;
	
	do{
		printf("Digite o %i%c valor: ", i+1, 167);
		scanf("%i", &dados[i]);
		soma += dados[i];
		
		printf("Digite P para proximo valor: \n");
		continuar = getch();
		continuar = toupper(continuar);
		i++;
		
	}while(continuar=='P' && i<100);
	printf("Resultado da soma dos valores: %i", soma);
	
	return 0;
}

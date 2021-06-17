//  4 Crie uma fun��o que aceite como par�metro um vetor de inteiros com N valores, e 
//determina o maior elemento do vetor e o n�mero de vezes que este elemento ocorreu no 
//vetor. Por exemplo, para um vetor com os seguintes elementos: 3, 5, 12, 6, 7, 27, 9, 16, 
//27, a fun��o deve retorna para o programa que a chamou o valor 27 e o n�mero 2 
//(indicando que o n�mero 27 ocorreu 2 vezes). A fun��o deve ser do tipo void. 

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<string.h>

#define MAX 5

void incluirInteiros(int *vetor);
void procurarMaiorValor( int *vetor);

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int vetor[MAX], valorIgual;
	int qtde;

	incluirInteiros(vetor);
    procurarMaiorValor (vetor);
     
    return 0;
}

void incluirInteiros(int *vetor){
	int i;
	char continuar;
	
	for(i=0; i<MAX; i++){
	printf("Digite o %i� valor:", i+1);
	scanf("%i", &vetor[i]);
	fflush(stdin);
	}
}

void procurarMaiorValor ( int *vetor){
	int i, count = 0;
	int maiorValor=vetor[0];
	for(i=0; i<MAX; i++){
		if(vetor[i] >= maiorValor){
			maiorValor = vetor[i];
			count++;
		}
	}
	puts("----Valores Digitados----");
	printf("\nMaior valor: %i \n", maiorValor);
	printf("Quantidade: %d ", count);

}


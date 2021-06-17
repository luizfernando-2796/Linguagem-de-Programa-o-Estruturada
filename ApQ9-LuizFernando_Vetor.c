// 9 -Faça um algoritmo que leia a idade de até 100 pessoas e apresente a média entre todas, além de identificar a mais 
//velha e a posição em que ela se encontra no vetor. A idade mais velha pode aparecer em mais de uma posição.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#define MAX 100

int leValidaIdade(int i);
int calcularMediaIdades(int idade[], int qtde);
void leValidaPessoaMaisVelha ( int idade[], int i);

int main (){
	setlocale(LC_ALL, "Portuguese");
	int idade[MAX];
	int i, j, qtde=0;
	char continuar;
	int mediaIdades=0;
	
	for(i=0; i<MAX; i++){
		
		idade[i]= leValidaIdade(i);
		printf("A idade da %iª pessoa: %i \n", i+1, idade[i]);	
		printf("-----------");
		printf("\nPressione 'S' para informar mais idade.\n");
		continuar=getch();	
		continuar=toupper(continuar);
		if(continuar!='S'){
			break;
		}
	}
	qtde=i;	

	mediaIdades = calcularMediaIdades(idade,qtde);
	printf("A média das idades das pessoas é de %i anos.\n", mediaIdades);	

	leValidaPessoaMaisVelha (idade,i);

	return 0;
}

int leValidaIdade(int i){
	int idade;
	do{
		printf("Informe a %iª idade: ", i+1);
		scanf("%i", &idade);
		if(idade<0){
			puts("Idade inválida!\n");
		}
	}while(idade<0);
	return idade;
}

int calcularMediaIdades(int idade[], int qtde){
	int i;
	int mediaIdades = 0;
	for(i=0; i<=qtde; i++){
		mediaIdades+=idade[i];
	}
	mediaIdades/=i;
	return mediaIdades;
}

void leValidaPessoaMaisVelha ( int idade[], int qtde){
	int i, j, posicao[MAX], count = 0;
	int maiorIdade=idade[0];
	for(i=0; i<=qtde; i++){
		if(maiorIdade<idade[i]){
			maiorIdade=idade[i];
		}
	}
	printf("\nA pessoa mais velha tem a idade de %i anos. \n", maiorIdade);
	for(i = 0; i <= qtde; i++){
		if(maiorIdade == idade[i] ){
			posicao[count] = i;
			count++;		
		}
	}
	
	printf("Encontrado nas posições:");
	for(i = 0; i < count; i++){
		i == 0 ?  printf(" %i", posicao[i]) : printf(" - %i", posicao[i]);
	}
	
}
	


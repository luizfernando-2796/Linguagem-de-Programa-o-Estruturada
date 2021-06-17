//4. Crie uma estrutura, com o nome Dieta, para armazenar o nome de uma comida, o 
//peso de uma por��o e o n�mero de calorias. Escreva um programa semelhante a quest�o 3.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#define MAX 5

typedef struct Dieta{
	char nomeComida[30];
	int peso;
	int numCalorias;
}dieta;

void cadastroComidas(dieta *comida);
void listarComidas(dieta *comida);

int main(){
	setlocale(LC_ALL, "Portuguese");
	dieta comida[2][2];
	int i, opcao, opcao1;
	
	do{
		puts("Escolha uma op��o:");
		puts("\t1 - Cadastrar Dados");
		puts("\t2 - Exibir Dados");
		puts("\t3 - Sair");
		scanf("%i", &opcao);
		switch (opcao){
			case 1:
	
				do{
					printf("Deseja cadastrar um novo restaurante  10 - sim, 20 - n�o: ");
					scanf("%i", &opcao1);
					if(opcao1 == 10)
						i++;
						cadastroComidas(comida);					
				}while(opcao1 == 10);
				break;
			case 2:
				listarComidas(comida);
				break;
			case 3:
				exit(1);
				break;
			default:
				puts("Op��o inv�lida.");
		}
	}while(opcao==1 || i<MAX);
	return 0;
}

void cadastroComidas(dieta *comida){
	int i;
	puts("----Cadastro de Refei��es----");
	for(i=0; i<MAX; i++){
		printf("Informe o nome da %i� comida :", i+1);
		fflush(stdin);
		fgets(comida[i].nomeComida, 30, stdin);
		puts("Informe o peso de uma por��o em gramas: ");
		fflush(stdin);
		scanf("%i", &comida[i].peso);
		puts("Informe quantas calorias tem essa por��o: ");
		fflush(stdin);
		scanf("%i", &comida[i].numCalorias);
	}
}

void listarComidas(dieta *comida){
	int i;
	puts("-----Refei��es-----");
	for(i=0; i<MAX; i++){
		printf("\n%i� Comida: \n", i+1);
		printf("Nome da Comida: %s\n", comida[i].nomeComida);
		printf("Peso de %i gramas.\n", comida[i].peso);
		printf("Quantidade de calorias %i.", comida[i].numCalorias);
	}
}

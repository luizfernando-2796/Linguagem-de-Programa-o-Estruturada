//1. Desenvolva um programa em C utilizando registro que permita a entrada de nome, 
//endereço e telefone de 3 pessoas e os imprima ao final.

#include <stdio.h>

typedef struct agenda{
	char nome[20], endereco[100], telefone[10];
} agenda;

void preencherDados(agenda *pessoas);
void imprimirDados (agenda *pessoas);

int main(){
	
	agenda pessoas[3];
	preencherDados(pessoas);
	system("cls");
	imprimirDados (pessoas);
	return 0;
}

void preencherDados(agenda *pessoas){
	int i;
	printf("-------Preenchimento dos Dados-------\n");
	for(i=0; i<3; i++){
		printf("\nDigite o nome da %i%c pessoa: ", i+1, 167);
		fgets(pessoas[i].nome, 20, stdin); 
		fflush(stdin);
		printf("\nDigite o endereco da %i%c pessoa: ", i+1, 167);
		fgets(pessoas[i].endereco, 100, stdin);
		fflush(stdin);
		printf("\nDigite o telefone da %i%c pessoa: ", i+1, 167);
		scanf("%s", &pessoas[i].telefone);
		fflush(stdin);		
	}
}

void imprimirDados (agenda *pessoas){
	int i;
	printf("-----------Agenda----------\n");
	for(i=0; i<3; i++){
		printf("\n%i%c Pessoa: \n", i+1, 167);
		printf("\tNome: %s", pessoas[i].nome);
		printf("\tEndereco: %s", pessoas[i].endereco);
		printf("\tTelefone: %s", pessoas[i].telefone);
	}	
}

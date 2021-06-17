// 3 Crie uma estrutura para descrever restaurantes. Os membros devem armazenar o nome, o endereço, o preço médio e o tipo de comida. Crie uma matriz de estruturas e 
//escreva um programa que utilize uma função para solicitar os dados de um elemento da matriz e outra para listar todos os dados.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#define MAX 2

typedef struct endereco{
	char rua[30];
	char bairro[30];
	char cidade[30];
	char estado[2];
}end;

typedef struct comida{
	char nomeRest[30];
	end endereco;
	char tipoComida[20];
	float preco;
}rest;

void cadastroRestaurantes(rest restaurante[2][2]);
void listarRestaurantes(rest restaurante[2][2]);

int main(){
	rest restaurante[MAX][2];	
	int i=0, opcao, opcao1;
	setlocale (LC_ALL, "Portuguese");
	
	do{
		puts("Escolha uma opção:");
		puts("\t1 - Solicitar Dados");
		puts("\t2 - Listar Dados");
		puts("\t3 - Sair");
		scanf("%i", &opcao);
		switch (opcao){
			case 1:
				if(i<MAX){
				cadastroRestaurantes(restaurante);	
				i++;
				}else{
					puts("Não há como cadastrar mais restaurantes.");
				}
				break;
			case 2:
				if(i>0){
				listarRestaurantes(restaurante);
				}else{
					puts("Não há dados para exibir.");
				}
				break;
			case 3:
				exit(1);
				break;
			default:
				puts("Opção inválida.");
		}
	}while(1);
	return 0;
}
void cadastroRestaurantes(rest restaurante[MAX][2]){
	int i, j;
	puts("----Cadastro dos Restaurantes----");
	for(i=0; i<MAX; i++){
		for(j=0; j<2; j++){
			printf("Informe o nome do %iº restaurante :", i+1);
			fflush(stdin);
			fgets(restaurante[i][j].nomeRest, 30, stdin);
			puts("--Informe endereço--");
			puts("Rua: ");
			fflush(stdin);
			fgets(restaurante[i][j].endereco.rua, 30, stdin);
			puts("Bairro: ");
			fflush(stdin);
			fgets(restaurante[i][j].endereco.bairro, 30, stdin);
			puts("Cidade: ");
			fflush(stdin);
			fgets(restaurante[i][j].endereco.cidade, 30, stdin);
			puts("Estado: (Sigla)");
			fflush(stdin);
			fgets(restaurante[i][j].endereco.estado, 2, stdin);
			puts("Informe a especialidade da comida: ");
			fflush(stdin);
			fgets(restaurante[i][j].tipoComida, 20, stdin);
			puts("Informe a média de preço R$: ");
			fflush(stdin);
			scanf("%f", &restaurante[i][j].preco);
		}
	}
}
void listarRestaurantes(rest restaurante[MAX][2]){
	int i, j;
	puts("-----Restaurantes-----");
	for(i=0; i<MAX; i++){
		for(j=0; j<2; j++){
			printf("\n%iº Restaurante: \n", i+1);
			printf("Restaurante %s\n", restaurante[i][j].nomeRest);
			printf("Endereço: %s - Bairro: %s - Cidade: %s - Estado: %s\n", restaurante[i][j].endereco.rua, restaurante[i][j].endereco.bairro, restaurante[i][j].endereco.cidade, restaurante[i][j].endereco.estado);
			printf("Restaurante especializado em comida %s .\n", restaurante[i][j].tipoComida);
			printf("Preço Médio R$ %.2f \n", restaurante[i][j].preco);
		}
	}
}

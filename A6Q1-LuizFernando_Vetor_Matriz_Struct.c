//1- Considerando o conjunto de dados abaixo para criação da estrutura, crie um programa 
//em C que leia o preço, o nome e as baixas de todos os dias de todos os produtos, após 
//percorra a estrutura de dados e verifique qual foi o produto que teve mais baixa, ou seja, 
//que foi mais vendido. Ao final, mostre o nome e quantas unidades deste produto foram 
//vendidas. A estrutura deve conter: código, nome, preço, baixa como uma matriz 4X6, 
//onde o 4 representa as semanas e o 6 cada dia da semana (segunda a sábado)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

typedef struct dados{
	char nomeProd[30];
	double precoProduto;
	int cod, baixaEstoque;

}prod;

int main (){
	setlocale(LC_ALL, "Portuguese");
	prod vendaMensal[4][6], prodMaiorBaixa;
	int i, j;
	for(i=0; i<4; i++){
		for(j=0; j<6; j++){
			printf("Informe o código XXX do produto: \n");
			fflush(stdin);
			scanf("%d", &vendaMensal[i][j].cod);
			printf("Informe o nome do produto: \n");
			fflush(stdin);
			fgets(vendaMensal[i][j].nomeProd, 30, stdin);
			printf("Valor do produto: R$ \n");
			fflush(stdin);
			scanf("%d", &vendaMensal[i][j].precoProduto);
			printf("Informe a quantidade vendida: \n");
			fflush(stdin);
			scanf("%d", &vendaMensal[i][j].baixaEstoque);
		}
	}
	
	prodMaiorBaixa = vendaMensal[0][0];
	
	for(i=0; i<4; i++){
		for(j=0; j<6; j++){
			if (vendaMensal[i][j].baixaEstoque > prodMaiorBaixa.baixaEstoque){
				prodMaiorBaixa = vendaMensal[i][j];
			}	
		}
	}
	system("cls");
	printf("----Apresentação das Vendas----\n");
	printf("Nome do produto mais vendido: %s ", prodMaiorBaixa.nomeProd);
	printf("Quantidade vendida: %i unidades.\n", prodMaiorBaixa.baixaEstoque);
}

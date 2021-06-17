// Considerando o conjunto de dados abaixo para criação da estrutura, crie um programa em C
//que leia o preço, o nome e as baixas de todos os dias de todos os produtos e armazene em uma
//lista encadeada simples, após percorra a estrutura de dados e verifique qual foi o produto que
//teve mais baixa, ou seja, que foi mais vendido. Ao final, mostre o nome e quantas unidades deste
//produto foram vendidas. A estrutura deve conter: código, nome, preço, baixa como uma matriz
//4X6, onde o 4 representa as semanas e o 6 cada dia da semana (segunda a sábado)

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

typedef struct venda vendas;
struct venda{
	int codigo;
	char nome[20];
	double valor;
	int qtdVendasMensais[1][2];
	vendas *proximo;	
};
vendas* inicializar();
void menu();
vendas *inserir(vendas *vendasMes);
void produtoMaisVendido(vendas *vendasMes);

int main(){

	vendas *vendasMes; 
	int opcao, opcao2;

	vendasMes = inicializar();
	do{
        menu();
        scanf("%d", &opcao);
            switch(opcao){
                case 1: vendasMes = inserir(vendasMes); break;
                case 2: produtoMaisVendido(vendasMes); break;
                case 3: return 0;
                default: printf("Codigo invalido!");
            }
    printf("Deseja realizar uma nova operacao? Digite 1 - se sim.");   
    scanf("%d", &opcao2);
    }while (opcao2==1);
	
	return 0;
}

vendas* inicializar(){
	return NULL;
}

void menu(){
	printf("\nMENU\n1 - Inserir vendas da semana\n 2- Verificar produto com maior venda\n 3 - Sair\n");
}

vendas *inserir(vendas *vendasMes){
	int i, j;
	vendas* novo = (vendas*) malloc(sizeof(vendasMes));
	
	printf("Digite o codigo do produto: ");
	scanf("%d", &novo->codigo);
	fflush(stdin);
	
	printf("Nome do produto:");
	fgets(novo->nome, 20, stdin);
	fflush(stdin);
	
	printf("Valor do produto R$:");
	scanf("%f", &novo->valor);
	fflush(stdin);
	
	for(i=0; i<1; i++)	{
		for(j=0; j<2; j++){
			printf("Digite a quantidade de vendas da semana %d - dia %d:", i++, j++);
			scanf("%d", &novo->qtdVendasMensais[i][j]);
			fflush(stdin);
		}
	}
	
	novo->proximo = vendasMes; 
	
	return novo;
}

void produtoMaisVendido(vendas *vendasMes){
	int soma, i, j, maiorVendas=0, codigoMaiorVenda;
	vendas *aux;
	
	if(vendasMes == NULL){
	
		printf("Nao foram realizadas vendas!\n");
	}else{
		
		for(aux=vendasMes; aux!=NULL; aux=aux->proximo){
				soma = 0;
			for(i=0; i<1; i++)	{
				for(j=0; j<2; j++){
					soma = soma + aux->qtdVendasMensais[i][j];
				}
			}
			if(soma > maiorVendas){
				maiorVendas = soma;
				codigoMaiorVenda = aux->codigo;
			}
		}
	}
	printf("Produto mais vendido----\n");
	for(aux=vendasMes; aux!=NULL; aux=aux->proximo){
		if(codigoMaiorVenda == aux->codigo){
			printf("Codigo: %d\n", aux->codigo);
			printf("Produto: %s\n", aux->nome);
			printf("Quantidade de vendas: %d\n", maiorVendas);
		}
	}
}

// 4- Defina uma estrutura em C para armazenar dados de um veículo (Marca, modelo, cor, quantidade de portas, motorização), crie uma função para armazenar os dados de 10 
//veículos, outra para mostrar os dados armazenados, a função main() deve conter um pequeno menu para chamar as funções criadas.

#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#define MAX 3

typedef struct cadastro{
	char marca[20], modelo[20], cor[10];
	int qtdePortas;
	float motorizacao;
}cad;

void coleta_dados(cad *veiculos);
void imprime_dados(cad *veiculos);

int main(){
	cad veiculos[MAX];
	char opcao, opcao2, compara;
	int i, posicao;
	
	do{
		printf("Digite C para coletar e I para Imprimir\n");
		opcao = getchar();
		opcao = toupper(opcao);
		
		switch (opcao){
			case 'C': 
				coleta_dados(veiculos);
				imprime_dados(veiculos);
					break;
			return 0;		
			case 'I': 
				for(i=0;i<MAX; i++){
					if(veiculos[i].marca, "" == 0){
						printf("Registro encontrado.");
						imprime_dados(veiculos);
					}else{
						printf("Nao possui dados cadastrados.");
					}
				break;
				}
			return 0;		
		}
	}while(opcao!='C' && opcao!='I');
}


void coleta_dados(cad *veiculos){
	int i;
	printf("----Cadastramento do Veiculo----\n");
	for(i=0;i<MAX; i++){
		printf("Veiculo %i - Informe a marca: \n", i+1);
		fflush(stdin);
		fgets(veiculos[i]. marca, 20, stdin);
		printf("Veiculo %i - Informe o modelo: \n", i+1);
		fflush (stdin);
		fgets(veiculos[i].modelo, 20, stdin);
		printf("Veiculo %i - Informe a cor: \n", i+1);
		fflush(stdin);
		fgets(veiculos[i].cor, 10, stdin);
		printf("Veiculo %i - Informe a quantidade de portas: \n", i+1);
		fflush(stdin);
		scanf("%i", &veiculos[i].qtdePortas);
		printf("veiculo %i - Informe a motorizacao: \n", i+1);
		fflush(stdin);
		scanf("%f", &veiculos[i].motorizacao);
	}
}

void imprime_dados(cad *veiculos){
	int i; 
	
	printf("----Veiculos Cadastrados----");
	for(i=0; i<MAX;i++){
		printf("VEICULO %i MARCA: %s", i+1, veiculos[i].marca);
		printf("VEICULO %i MODELO: %s", i+1, veiculos[i].modelo);
		printf(" VEICULO %i COR: %s", i+1, veiculos[i].cor);
		printf("Veiculo %i - Quantidade de portas: %i ", i+1, veiculos[i].qtdePortas);
		printf("Veiculo %i - Motorizacao: %.1f", i+1, veiculos[i].motorizacao);
		
	}
}

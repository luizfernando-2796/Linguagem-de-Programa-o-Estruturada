//. Crie uma estrutura, com o nome Dieta, para armazenar em uma lista encadeada o nome de 
//uma comida, o peso de uma por��o e o n�mero de calorias. Escreva um programa semelhante a 
//quest�o 2.
// precisa corrigir o listar

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<locale.h>

typedef struct regime dieta;
struct regime{
	char nomeDieta[20];
	int pesoPorcao;
	int calorias;
	dieta *proximo;
};

dieta *inicializar();
void menu();
dieta *inserirDados(dieta *tipoDieta);
void listarDieta(dieta *tipoDieta);

int main(){
	setlocale (LC_ALL, "Portuguese");
	dieta *tipoDieta;
	int opcao, opcao2;
	
	tipoDieta = inicializar();
	
	do{ 
		menu();
		scanf("%d", &opcao);
		switch(opcao){
			case 1: tipoDieta = inserirDados(tipoDieta); break;
			case 2: listarDieta(tipoDieta); break;
			case 3: return 0;
			default: printf("C�digo Inv�lido.\n");
		}
	printf("Deseja realizar nova operacao? \n") ;
	printf("Digite 1 para sim: ");
	scanf("%d", &opcao2);
	
	}while(opcao2==1);
	
}

dieta *inicializar(){
	return NULL;
}

void menu(){
	printf("\n----MENU----\n1 - Cadastrar Dieta\n2 - Listar Dieta\n3 - Sair\n");
}

dieta *inserirDados(dieta *tipoDieta){
	dieta *novo = (dieta*) malloc(sizeof(tipoDieta));
	
	printf("Informe o nome da dieta: ");
	fflush(stdin);
	fgets(novo->nomeDieta, 20, stdin);
	fflush(stdin);
	
	printf("Informe o peso da por��o em gramas: ");
	fflush(stdin);
	scanf("%d", &novo->pesoPorcao);
	
	printf("Informe a quantidade de calorias: ");
	fflush(stdin);
	scanf("%d", &novo->calorias);
	
	novo->proximo = tipoDieta;
	
	return novo;
	
}

void listarDieta(dieta *tipoDieta){
	dieta *aux;
	if(tipoDieta != NULL){
		for(aux=tipoDieta; aux!=NULL; aux=aux->proximo){
			printf("Nome da dieta: %s", aux->nomeDieta);
			printf("Peso da por��o em gramas: %d", aux->pesoPorcao);
			printf("Quantidade de calorias: %d", aux->calorias);
		}
	}else{
		printf("----N�o h� dieta cadastrada.----");
	}
	
}

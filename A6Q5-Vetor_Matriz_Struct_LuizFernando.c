// 4 Para o controle dos veículos que circulam em uma determinada cidade, a Secretaria dos 
//Transportes criou o seguinte registro padrão:
//Proprietário: Combustível: Modelo: Cor: Nº chassi: Ano: Placa:
//Em que Combustível pode ser álcool, diesel ou gasolina;
// Placa possui os três primeiros valores alfabéticos e os quatro restantes valores numéricos.
//Sabendo que não temos uma definição do número máximo de veículos da cidade e que é preciso 
//armazenar todos os valores em uma lista encadeada simples, construa:
//a. Uma função que liste todos os proprietários cujos carros são do ano de 2010 ou posterior 
//e que sejam movidos a diesel.
//b. Uma função que liste todas as placas que comecem com a letra J e terminem com 0, 2, 4 
//ou 7 e seus respectivos proprietários.
//c. Uma função que liste o modelo e a cor dos veículos cujas placas possuem como segunda 
//letra uma vogal e cuja soma dos valores numéricos fornece um número par.
//d. Uma função que permita a troca de proprietário com o fornecimento do número do chassi 
//apenas para carros com placas que não possuam nenhum dígito igual a zero

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

ypedef struct veiculo end;
struct veiculo{
	char Proprietario[30];
	char Modelo[20];
	char Cor[30];
	float Combustivel;
	int chassi, Ano, Placa;
};

typedef struct tranpostes secretaria;
struct secretaria{
	char Proprietario[30];
	char Modelo[20];
	char Cor[30];
	float Combustivel;
	int chassi, Ano, Placa;
	transportes *secretaria;
};

secretaria *inicializar();
void menu();
secretaria *inserir(secretaria *cadsecretaria);
void listarsecretaria(secretaria *cadsecretaria);

int main(){
	secretaria *cadsecretaria;
	int opcao;
	cadsecretaria = inicializar();
	do{
        menu();
        scanf("%d", &opcao);
        fflush(stdin);
            switch(opcao){
                case 1:
               		cadsecretaria = inserir(cadsecretaria);
                break;
                
                case 2:
                    listar secretria(cadsecretaria);
                break;
                
                case 3:
                    return 0;
                break;
                
                default: printf("Codigo invalido!");
            }
    }while (opcao!=0);	
	
}

secretaria *inicializar(){
	return NULL;
}

void menu(){
	printf("1 - Inserir secretaria\n 2 - Listar cadastro dos secretarias\n 3 - Sair\n");
	
}
// falta terminar

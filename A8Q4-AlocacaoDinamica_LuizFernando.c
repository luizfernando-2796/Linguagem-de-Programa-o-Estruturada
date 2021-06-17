// 4 Para o controle dos ve�culos que circulam em uma determinada cidade, a Secretaria dos 
//Transportes criou o seguinte registro padr�o:
//Propriet�rio: Combust�vel: Modelo: Cor: N� chassi: Ano: Placa:
//Em que Combust�vel pode ser �lcool, diesel ou gasolina;
// Placa possui os tr�s primeiros valores alfab�ticos e os quatro restantes valores num�ricos.
//Sabendo que n�o temos uma defini��o do n�mero m�ximo de ve�culos da cidade e que � preciso 
//armazenar todos os valores em uma lista encadeada simples, construa:
//a. Uma fun��o que liste todos os propriet�rios cujos carros s�o do ano de 2010 ou posterior 
//e que sejam movidos a diesel.
//b. Uma fun��o que liste todas as placas que comecem com a letra J e terminem com 0, 2, 4 
//ou 7 e seus respectivos propriet�rios.
//c. Uma fun��o que liste o modelo e a cor dos ve�culos cujas placas possuem como segunda 
//letra uma vogal e cuja soma dos valores num�ricos fornece um n�mero par.
//d. Uma fun��o que permita a troca de propriet�rio com o fornecimento do n�mero do chassi 
//apenas para carros com placas que n�o possuam nenhum d�gito igual a zero

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

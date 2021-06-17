//6 – Faça uma agenda com os dados de N clientes, sendo o valor de N lido no programa. 
//Os dados de cada cliente devem estar numa estrutura denominada CLIENTE, que possua 
//os itens “nome, numero de identidade, telefone, estado civil e cidade de origem ”. Tais 
//dados devem ser gravados em disco.

#include <stdio.h>
#include <stdlib.h>

typedef struct dados{
	char nome[30], identidade[15], estadoCivil[10], cidade[20];
	int telefone;
}agenda;

agenda cadastrar();
void armazenar(agenda x);
void consultar();

int main(){
	agenda pessoas;
	int op, n, i;
	
	do{
		puts("Escolha uma opcao");
		puts("1 - Consultar");
		puts("2 - Cadastrar");
		puts("3 - Sair");
		scanf("%i", &op);
		switch (op){
			case 1:
				consultar();
				break;
			case 2:
				printf("Digite o numero de clientes:\n");
				scanf("%i", &n);				
				for(i=0; i<n; i++){
				armazenar(cadastrar());					
				}
				break;
			case 3:
				exit(1);
				break;
			default:
				puts("Opcao Invalida");		
		}
		system("pause");
		system("cls");
	}while(1);
	return 0;
}


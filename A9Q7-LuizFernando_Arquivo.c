//7 � Fa�a uma agenda com os dados de N clientes, sendo o valor de N lido no programa. 
//Os dados de cada cliente devem estar numa estrutura denominada CLIENTE, que possua 
//os itens �nome, numero de identidade, telefone, estado civil e cidade de origem �. Tais 
//dados devem ser gravados em disco.
// Complementando o exerc�cio, criar duas fun��es com os nomes criar_arquivo, 
//ler_arquivo, sendo cada uma destas op��es chamadas por um menu que cont�m os 
//seguintes itens: 
//(a) CONSULTAR
//(b) CADASTRAR CLIENTE
//(c) SAIR

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

agenda cadastrar(){
	agenda dado;
	puts("---------------------");
	puts("Informe o nome:");
	fflush(stdin);
	gets(dado.nome);
	puts("Informe a identidade:");
	fflush(stdin);
	gets(dado.identidade);
	puts("Digite o telefone: ");
	fflush(stdin);
	scanf("%i", &dado.telefone);
	puts("Estado Civil:");
	fflush(stdin);
	gets(dado.estadoCivil);
	puts("Informe a Cidade:");
	fflush(stdin);
	gets(dado.cidade);
	
	return dado;
}

void armazenar(agenda dado){
	FILE *fp;
	if((fp = fopen("agenda.bin", "ab"))!=NULL){ 
		fwrite(&dado, sizeof(dado), 1, fp);
		fclose(fp);
	}
}

void consultar(){
	FILE *fp;
	agenda dado;
	char nomeConsulta[25];
	if((fp = fopen("arquivo.bin", "rb"))!=NULL){
		while(fread(&dado, sizeof(dado), 1, fp)==1){
			if(strcmp(nomeConsulta, dado.nome)==0){
			printf("Nome: %s\n", dado.nome);
			printf("Identidade: %s\n", dado.identidade);
			printf("Telefone: %i\n", dado.telefone);
			printf("Estado Civil: %s\n", dado.estadoCivil);
			printf("Cidade: %s\n\n", dado.cidade);					
			}
		}
		fclose(fp);
	}else{
		puts("Arquivo nao encontrado.");
	}
}


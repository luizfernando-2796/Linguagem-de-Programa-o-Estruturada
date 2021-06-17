// � Fa�a um programa gerenciar uma agenda de contatos. Para cada contato armazene o
//nome, o telefone e o anivers�rio (dia e m�s). O programa deve permitir
//(a) inserir contato (b) remover contato (c) pesquisar um contato pelo nome
//(d) listar todos os contatos (e) listar os contatos cujo nome inicia com uma dada letra (f) imprimir os aniversariantes do m�s.
//Sempre que o programa for encerrado, os contatos devem ser armazenados em um
//arquivo bin�rio. Quando o programa iniciar, os contatos devem ser inicializados com os
//dados contidos neste arquivo bin�rio

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct data{
	int dia;
	int mes;
}data;
typedef struct dados{
	char nome[30];
	char telefone[15];
	data aniversario;
}agenda;

agenda inserirContato();
void armazenar(agenda x);
void listarContatos();
void removerContato();
void pesquisarNome();
void listarNomePorLetra();
void aniversariantesMes();

int main(){
	agenda contatos;
	char op;
	do{
		puts("Escolha uma opcao.");
		puts("a - Inserir contato.");
		puts("b - Remover Contato.");
		puts("c - Pesquisar um contato pelo nome.");
		puts("d - Listar todos os contatos.");
		puts("e - Listar os contatos cujo nome inicia com uma dada letra.");
		puts("f - Imprimir aniversariantes do mes.");
		puts("s - Sair.");
		op = getch();
		op = tolower(op);
		switch (op){
			case 'a':
				armazenar (inserirContato());
				break;
			case 'b':
				removerContato();
				break;
			case 'c':
				pesquisarNome();
				break;
			case 'd':
				listarContatos();
				break;
			case 'e':
				listarNomePorLetra();			
				break;
			case 'f':
				aniversariantesMes();			
				break;
			case 's':
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
agenda inserirContato(){
	agenda x;
	puts("Informe o nome do contato:");
	fflush(stdin);
	gets(x.nome);
	puts("Informe o telefone:");
	fflush(stdin);	
	gets(x.telefone);
	puts("Informe o aniversario: DD/MM");
	fflush(stdin);
	scanf("%i/%i", &x.aniversario.dia, &x.aniversario.mes);
	return x;
}

void armazenar(agenda x){
	FILE *fp;
	if((fp=fopen("agendaContatos.bin", "ab"))!=NULL){
		fwrite(&x, sizeof(x), 1, fp); 
		fclose(fp);
	}
}

void listarContatos(){
	FILE *fp;
	agenda x;
	if((fp=fopen("agendaContatos.bin", "rb"))!=NULL){
		while(fread(&x, sizeof(x), 1, fp)==1){
			printf("Nome %s\n", x.nome);
			printf("Telefone: %s\n", x.telefone);
			printf("Aniversario: %02i/%02i\n\n", x.aniversario.dia, x.aniversario.mes);
		}
		fclose(fp);
	}else{
		puts("Arquivo nao encontrado.");
	}
}

void removerContato(){
	FILE *fp, *fpRemove;
	agenda x;
	char nomeRemove[30];
	if((fp=fopen("agendaContatos.bin", "rb"))!=NULL){
		printf("Informe nome para exclusao:\n");
		fflush(stdin);
		gets(nomeRemove);
		fpRemove = fopen("arqRemove.bin", "wb");
		while(fread(&x, sizeof(x), 1, fp)==1){
			if(strcmp(nomeRemove,x.nome)==0){
				puts("Contato excluido.");
			}else{
				fwrite(&x, sizeof(x), 1, fpRemove);
			}
		}
		fclose(fp);
		fclose(fpRemove);
	}else{
		puts("Arquivo nao encontrado.");
	}
	
	if((fpRemove = fopen("arqRemove.bin", "rb"))!=NULL){
		fp=fopen("agendaContatos.bin", "wb");
		while(fread(&x, sizeof(x), 1, fpRemove)==1){
			fwrite(&x, sizeof(x), 1, fp);
		}
		fclose(fpRemove);
		fclose(fp);
	}
}

void pesquisarNome(){
	FILE *fp;
	agenda x;
	char nomePesquisa[30];
	if((fp=fopen("agendaContatos.bin", "rb"))!=NULL){
		printf("Informe nome que deseja pesquisar:\n");
		fflush(stdin);
		gets(nomePesquisa);
		printf("\n----Contato----\n");		
		while(fread(&x, sizeof(x), 1, fp)==1){
			if(strcmp(nomePesquisa,x.nome)==0){
				printf("Nome %s\n", x.nome);
				printf("Telefone: %s\n", x.telefone);
				printf("Aniversario: %02i/%02i\n\n", x.aniversario.dia, x.aniversario.mes);
			}
		}
		fclose(fp);
	}else{
		puts("Arquivo nao encontrado.");
	}	
}

void listarNomePorLetra(){
	FILE *fp;
	agenda x;
	char letra;
	if((fp=fopen("agendaContatos.bin", "rb"))!=NULL){
		printf("\nInforme a primeira letra do nome que deseja listar:\n");
		letra = getche();
		letra = toupper(letra);
		printf("\n----Contato----\n");
		while(fread(&x, sizeof(x), 1, fp)==1){
			if(letra == x.nome[0]){
				printf("Nome %s\n", x.nome);
				printf("Telefone: %s\n", x.telefone);
				printf("Aniversario: %02i/%02i\n\n", x.aniversario.dia, x.aniversario.mes);
			}
		}
		fclose(fp);
	}else{
		puts("Arquivo nao encontrado.");
	}	
}

void aniversariantesMes(){
	FILE *fp;
	agenda x;
	int mes;
	if((fp=fopen("agendaContatos.bin", "rb"))!=NULL){
		printf("\nDigite o mes que queira pesquisar os aniversariantes (MM): \n");
		scanf("%i", &mes);
		printf("\n----Aniversariantes do Mes----\n");
		while(fread(&x, sizeof(x), 1, fp)==1){
			if(mes == x.aniversario.mes){
				printf("Nome %s\n", x.nome);
				printf("Aniversario: %02i/%02i\n\n", x.aniversario.dia, x.aniversario.mes);
			}
		}
		fclose(fp);
	}else{
		puts("Arquivo nao encontrado.");
	}	
}

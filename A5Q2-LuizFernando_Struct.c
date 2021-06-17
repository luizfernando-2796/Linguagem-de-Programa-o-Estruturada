//2. Criar um registro chamado DadosAluno, que armazene o nome e idade de um aluno. 
//Na função main: criar uma variável que é uma estrutura DadosAluno; ler o nome e a idade 
//de um aluno e armazenar na variável criada; exibir na tela o nome do aluno e a idade do aluno. 

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAX 5

typedef struct alunos{
	char nome[30];
	int idade;
} alunos;

int main(){
	
	alunos dadosAlunos[MAX];
	int i = 0;
	char continuar;
	printf("-----Preenchimento dos Dados-----\n");		
	for(i=0; i<MAX; i++){
		printf("Digite o nome do %d%c aluno: \n", i+1, 167);
		fflush (stdin);
		fgets(dadosAlunos[i].nome, 30, stdin);
		fflush (stdin);
		printf("Digite a idade do %d%c aluno: \n", i+1, 167);
		fflush (stdin);
		scanf("%d", &dadosAlunos[i].idade);
		fflush (stdin);	
		printf("Digite 'N' para novo aluno: ");
		continuar = getchar();
		continuar = toupper(continuar);
			if( continuar != 'N' && i<MAX){
				break;
			}
	}
	printf("-------DADOS DOS ALUNOS-------");	
	for(i=0; i<MAX; i++){
		printf("\n%d%c aluno: %s ", i+1, 167, dadosAlunos[i]. nome);
		printf("Idade do %d%c aluno: %d\n", i+1, 167, dadosAlunos[i].idade);
	}
	return 0;	
}

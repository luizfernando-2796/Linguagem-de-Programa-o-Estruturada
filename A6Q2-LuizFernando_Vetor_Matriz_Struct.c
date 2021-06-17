// 2 - Desenvolva uma estrutura em C conforme o modelo abaixo e ap�s crie as fun��es 
//solicitadas:At� 500 alunos e Estrutura: N�mero da matr�cula, nome, s�rie, turma, sexo, m�dia, aprova, ano nascimento, naturalidade.
//(a) Cadastrar os dados. (b) Apresentar todos os dados.c) Exibir a porcentagem de alunos aprovados e reprovados por turma, totalizados por 
//s�rie.(d) Exibir a porcentagem de alunos do sexo masculino e do sexo feminino por turma, 
//totalizados por s�rie. (e) Apresentar a m�dia das idades de cada uma das s�ries.

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct cad{
	int matricula, serie, anoNasc;
	char nome[30], aprovado[10], natural[20];
	char turma[1], sexo[9];
	float media;

}cadastro;

int main(){
	setlocale(LC_ALL, "Portuguese");
	cadastro alunos[2], situacaoAlunos;
	int i, cont = 0;
	int 	totalAprovados = 0;
	char opcao;
	
	for(i=0; i<2; i++){
		puts("----Cadastro de Alunos----");
		printf("\nInforme o n�mero de matricula do aluno: \n");
		fflush(stdin);
		scanf("%i", &alunos[i].matricula);
		
		printf("Nome do aluno: \n");
		fflush(stdin);
		fgets(alunos[i].nome, 30, stdin);

		printf("Turma (Letra): ");
		fflush(stdin);
		alunos[i].turma = getche();
				
		printf("S�rie: \n");
		fflush(stdin);
		scanf("%i", &alunos[i].serie);
		
		printf("Sexo (F - feminino / M - masculino): \n");
		fflush(stdin);
		alunos[i].sexo= getche();
		
		printf("Informe a nota m�dia do aluno:	\n");
		fflush(stdin);
		scanf("%f", &alunos[i].media);
		
		printf("Situacao do aluno (Aprovado ou Reprovado): \n");
		fflush(stdin);
		fgets(alunos[i].aprovado, 10, stdin);
		
		printf("Ano de nascimento: \n");
		fflush(stdin);
		scanf("%i", &alunos[i].anoNasc);
		
		printf("Naturalidade: \n");
		fflush(stdin);
		fgets(alunos[i].natural, 20, stdin);
	}
	system("cls");

	printf("----Alunos cadastrados----\n");
	for(i=0; i<2; i++){
		puts("\n----Aluno----\n");
		printf("Matr�cula: %i\n", alunos[i].matricula);
		printf("Nome do aluno: %s \n", alunos[i].nome);
		printf("S�rie: %i \n",alunos[i].serie);
		printf("Turma: %s \n", alunos[i].turma);
		printf("Sexo: %s \n", alunos[i].sexo);
		printf("Nota M�dia: %f \n", alunos[i].media);
		printf("Situa��o do aluno: %s \n", alunos[i].aprovado);
		printf("Ano de nascimento: %i \n", alunos[i].anoNasc);
		printf("Natural de %s \n", alunos[i].natural);
	}
	situacaoAlunos = alunos[0];

	for(i=0; i<2; i++){
		if(alunos[i].aprovado == 'aprovado' && alunos[i].aprovado == 'APROVADO'){
		cont++;
		totalAprovados += cont;
		}	
	}
	return 0;
}

// 2-Altere o algoritmo anterior considerando que não se conhece quantos alunos esta turma tem (menos que 50). O número de aluno será informado pelo usuário.

#include <stdio.h>
#define MAX 49
int leValidaQtdeAlunos();
float leValidaNotas(int ind);
int main(){
	
	float notas[MAX];
	int i, qtdeAlunos;
	
	qtdeAlunos = leValidaQtdeAlunos();
	for(i=0; i<qtdeAlunos; i++){
		notas[i]= leValidaNotas(i);
	}

	return 0;
}
int leValidaQtdeAlunos(){
	int qtde;
	do{
		printf("\nDigite a quantidade de alunos em sua turma: \n");
		scanf("%i", &qtde);
		if(qtde<0 || qtde>MAX){
			printf("Quantidade de alunos inv%clida. (Menor que 50)\n", 160);
		}
	}while(qtde<0 || qtde>MAX);
	return qtde;
}

float leValidaNotas(int ind){
	float nota;
	do{
		printf("Digite a nota do %i%c aluno: ", ind+1, 167);
		scanf("%i", &nota);
		if (nota<0 || nota>10){
			printf("\nNota inv%clida. Notas de 0 a 10\n", 160);
		}
	}while(nota<0 || nota>10);
	return nota;
}

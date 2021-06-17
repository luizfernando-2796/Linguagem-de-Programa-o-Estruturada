//3- Fa�a um programa em C para ler uma matriz 5 x 10 que se refere a respostas de 10
//quest�es de m�ltipla escolha, referentes a 5 alunos. Leia tamb�m um vetor de 10
//posi��es contendo o gabarito de respostas que podem ser a, b, c ou d. Seu programa
//dever� comparar as respostas de cada aluno com o gabarito e armazenar em um outro
//vetor denominado resultado, contendo a pontua��o correspondente a cada aluno.

#include <stdio.h>

int main (){
	
	char questoes[5][10];
	char gabarito[10] = {'a','b','c','d','a','b','c','d','a','b'};
	int resultado[5] = {0,0,0,0,0};
	int i, j;
	
	for(i=0; i<5; i++){
		printf("Informe as respostas do %i%c aluno \n", i+1, 167);
		for(j=0; j<10; j++){
			printf("Questao %i = ", j+1);
			scanf("%c", &questoes[i][j]);
			fflush(stdin);
		}
	}
	system("cls");

	for(i=0; i<5; i++){
		for(j=0; j<10; j++){
			if(questoes[i][j]== gabarito[i]){
				resultado[i]= resultado[i]+1;
			}
		}
	}
	for(i=0; i<5; i++){
		printf("\tResultado do %i%c aluno: %i\n", i+1, 167, resultado[i]);

	}	
	
	return 0;
}


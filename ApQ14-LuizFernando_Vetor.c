//Lista1 questão 14 - Elabore um algoritmo que leia um conjunto de valores inteiros correspondentes a até 80 notas, variando 
//de 0 a 10, dos alunos de uma turma (vários alunos). Calcule a frequência de cada nota e apresente uma 
//tabela contendo os valores das notas e suas respectivas frequências.

#include<stdio.h>
#include<conio.h>
#define MAX 80

int leValidaMatricula(int notas[], int indice);
int calcularFrequencias(int frequencias[MAX][2],int notas[], int indice);
void frequenciaNotas(int matriz[MAX][2], int indice);

main(){
	int notas[MAX];
	int frequencias[MAX][2];
	int indice;
	char continuar;
	
	for(indice=0; indice<MAX; indice++){
	
		do{
			printf("Informe nota de 0 a 10. \n");
			printf("\nDigite a nota do %i%c aluno: ", indice+1, 167);
			scanf("%i", &notas[indice]);
		
			if(notas[indice] < 0 || notas[indice] > 10){
				printf("Nota %c invalida!\n");
			}
		}while(notas[indice] < 0 || notas[indice] > 10);
		 
		printf("-----------");
		printf("\nPressione 'S' para proximo aluno.\n");
		continuar=getch();	
		continuar=toupper(continuar);
		if(continuar!='S'){
			break;
		}
	}
	system("cls");
	int controleIndiceFrequencias =	calcularFrequencias(frequencias,notas,indice);
	
	for(indice = 0;indice<controleIndiceFrequencias; indice++){
		printf("Nota : %i   Frequencia : %i\n",frequencias[indice][0],frequencias[indice][1]);
	}
	
}

int calcularFrequencias(int frequencias[MAX][2],int notas[], int indice){
	int ind =0 , ind2 = 0;
	int controleIndiceFrequencias = 0;
	for(ind=0; ind<=indice; ind++){
		for(ind2=0; ind2<=controleIndiceFrequencias; ind2++){
			if(frequencias[ind2][0] == notas[ind]) {
				frequencias[ind2][1]++;
				break;
			}
			if(controleIndiceFrequencias == ind2){
				frequencias[controleIndiceFrequencias][0] = notas[ind];
				frequencias[controleIndiceFrequencias][1] = 1;
				controleIndiceFrequencias++;
				break;
			}
			
		}		
	
	}
	frequenciaNotas(frequencias,controleIndiceFrequencias);
	return controleIndiceFrequencias;
}

void frequenciaNotas(int matriz[MAX][2], int indice){
	int aux, ind1, ind2;
	
	for(ind1=0;ind1<indice;ind1++){
		for(ind2=ind1+1;ind2<indice;ind2++){
			if(matriz[ind1][1] <  matriz[ind2][1]){
				aux = matriz[ind1][0];
				matriz[ind1][0] = matriz[ind2][0];
				matriz[ind2][0] = aux;
				
				aux = matriz[ind1][1];
				matriz[ind1][1] = matriz[ind2][1];
				matriz[ind2][1] = aux;
				
			}
		}
	}
}

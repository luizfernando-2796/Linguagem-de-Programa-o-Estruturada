// 10 -Escrever um algoritmo que solicite e leia letra por letra o nome completo de uma pessoa. O caractere 
//sustenido “#” indica o fim do nome. Depois de lê-lo apresente todo o nome informado, sem o #.

#include<stdio.h>
#include<stdlib.h>
#define MAX 40

int main(){
	char nome[MAX];
	int i, contador = 0;
	
	puts("Digite o nome, ao final digite #:");
	do{
		nome[contador] = getche();
		
		if(nome[contador] == '#'){
			break;
		}
		contador++;
		if(nome[contador] == (MAX - 1)){
			puts("Limite maximo de caracteres excedido.");
			break;
		}
	}while(contador < MAX);
	printf("\n\n\nNome Completo:\n");
	for(i=0; i<contador; i++){
		printf("%c", nome[i]);
	}
	fflush(stdin);
	getch();
	
	return 0;
}

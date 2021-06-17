// 5 - Utilizando-se da função fprintf, criar um programa que grava em um arquivo em disco 
//uma estrutura de dados que contenha o nome da pessoa e o seu numero de identidade. 
//O programa deve possuir um menu com as opções “entrada de dados” e “sair do 
//programa”.

#include<stdio.h>
#include<conio.h>

int main (){
	FILE *CadArquivo = fopen ("testeamais.txt", "w");
	char ch;
	char nome[30];
	int identidade; 
	printf ("Digite o nome:");
	printf ("Digite a identidade:");
	while ((ch=getche()) != '\r')
		putc(ch, cadArquivo);
	fclose(cadArquivo);
}

// 3 Faça um programa que receba do usuário um arquivo texto e um caracter. Mostre na 
//tela quantas vezes aquele caractere ocorre dentro do arquivo.

#include<stdio.h>
#include<conio.h>
int main (){
	FILE *textoArquivo = fopen ("testeamais.txt", "w");
	char ch; 
	printf ("Digite varios caracteres:");
	while ((ch=getche()) != '\r')
		putc(ch, textoArquivo);/
	fclose(textoArquivo);
}

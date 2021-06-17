// – Escreva um programa que:
//(a) Crie/abra um arquivo texto de nome “arq.txt”
//(b) Permita que o usuário grave diversos caracteres nesse arquivo, até que o usuário entre com o caractere ‘0’
//(c) Feche o arquivo Agora, abra e leia o arquivo, caractere por caractere, e escreva na tela todos os caracteres armazenados.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	FILE *fp;
	char caracteres;
	char texto[100];
	int i=0;

	if((fp = fopen("arq.txt", "w"))!=NULL){
		printf("Digite varios caracteres. Para finalizar digite 0: \n");
		while((caracteres = getche())!= '0'){
			putc(caracteres, fp);
		}
		fclose(fp);
	}

	if((fp = fopen("arq.txt", "r"))!=NULL){
		while((caracteres = getc(fp))!= EOF){
			putc(caracteres, fp);
			texto[i] = caracteres;
			i++;
		}
		fclose(fp);
		texto[i]= '\0';
	}
	puts(texto);
}

//2 � Fa�a um programa que receba do usu�rio um arquivo texto e mostre na tela quantas letras s�o vogais e quantas s�o consoantes.

#include<stdio.h>
#include<string.h>

int main(){
	
	FILE *fp;
	char caracter, nomeArq[30];
	int contVogal=0, contConsoante=0;
	puts("Digite o nome do arquivo:");
	gets(nomeArq);
	
	if((fp=fopen(nomeArq, "r"))!=NULL){
		while((caracter = getc(fp))!=EOF){
			caracter = tolower(caracter);
			if(caracter =='a'|| caracter =='e' || caracter =='i' || caracter=='o' || caracter =='u'){
				contVogal++;
			}else{
				if(caracter>'a' && caracter<='z'){
					contConsoante++;
				}
			}
		}
		fclose(fp);
	}
	printf("Arquivo %s possui %i vogais.\n", nomeArq, contVogal);
	printf("Arquivo %s possui %i consoantes.\n", nomeArq, contConsoante);
}


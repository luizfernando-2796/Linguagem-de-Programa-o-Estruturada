// – Faça um programa que receba dois arquivos do usuário, e crie um terceiro arquivo 
//com o conteúdo dos dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo 
//do segundo).

#include<stdio.h>
#include<string.h>
int main(){
	FILE *fp1, *fp2;
	char texto[20], texto1[40];
	int i=1;
	
	fp2 = fopen("arquivoRecebe.txt", "w");
	
	do{
		printf("Digite o nome do %i%c arquivo: \n", i, 167);
		fflush(stdin);
		gets(texto);
		if((fp1 = fopen(texto, "r"))!= NULL){
			i++;
			while(fgets(texto1, 39, fp1)!= NULL){
				fputs(texto1, fp2);
			}
			fclose(fp1);
		}else{
			printf("%i%c arquivo nao pode ser aberto.\n", i, 167);
		}
	}while(i<=2);
	fclose(fp2);
}

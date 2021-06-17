//13. Fazer um algoritmo que:
//a) leia uma frase de até 80 caracteres, incluindo os brancos, b) conte quantos caracteres em branco existem na frase, 
//c) conte quantas vezes a letra ‘a’ ou ‘A’ aparece
//d) conte quantas vezes ocorre um mesmo par de letras na frase e quais são elas; //e) apresente o que foi calculado nos itens b, c e d

#include<stdio.h>
#define max 80

main(){
	char frase[max], aux;
	int ind, qtde, ind2, contBranco=0, contA=0, contPar;
	printf("Digite a frase:\n");
	ind=0;
	do{
		frase[ind]=getche();
		ind++;
	}while(ind<max && frase[ind-1]!='\r');
	if(ind<max){
		qtde=ind-1;
	}else{
		qtde=ind;
	}
	printf("\nfrase:\n");
	for(ind=0;ind<qtde;ind++)
		printf("%c", frase[ind]);
	for(ind=0;ind<qtde;ind++)
		if(frase[ind]==' ')
			contBranco++;
	printf("\nA quantidade de caracteres em branco sao: %i\n", contBranco);
	for(ind=0;ind<qtde;ind++)
		if(frase[ind]=='a' || frase[ind]=='A')
			contA++;
	printf("\nA quantidade de caracteres 'a' ou 'A' sao: %i\n", contA);
	for(ind=0;ind<qtde-2;ind++){
		contPar=1;
		for(ind2=ind+2;ind2<qtde-1;ind2++){
			if((frase[ind]==frase[ind2] && frase[ind+1]==frase[ind2+1])&&(frase[ind]!=' ' && frase[ind+1]!=' ')){
				contPar++;
			}
		}
		if(contPar>1){
			printf("\nO par %c%c aparece %i vezes\n",frase[ind], frase[ind+1], contPar);
		}
	}
}

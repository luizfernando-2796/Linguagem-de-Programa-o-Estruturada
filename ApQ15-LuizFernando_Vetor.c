//15 - Alterar o algoritmo de ordenação de caracteres para pesquisar um caractere específico.

#include <stdio.h>
#define max 30

int main(){
	char letras[max], pesq;
	int ind, qtde;
	printf("Digite as letras:\n");
	ind=0;
	do{
		letras[ind]=getche();
		ind++;
	}while(ind<max && letras[ind-1]!='\r');
	if(ind<max){
		qtde=ind-1;
	}else{
		qtde=ind;
	}
	printf("\nLetras:\n");
	for(ind=0;ind<qtde;ind++)
		printf("%c", letras[ind]);
		
    printf("\nInforme uma letra: \n");
    pesq=getch();
    
    for(ind=0;ind<qtde;ind++){
      if(pesq==letras[ind]){
      	printf("A letra %c esta presente na posicao %i \n",pesq,ind+1);
	  }	
	}

}

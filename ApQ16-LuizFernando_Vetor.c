//Lista 1 questão 16

#include <stdio.h>
#define Max

int main(){
	int vetorA[10], vetorB[10], vetorC[10];
	int ind, pesquisa;
	
	for(ind=0;ind<10;ind++){
		printf("Digite o %i%c valor para o vetor A:\n", ind+1, 248);
		scanf("%i", &vetorA[ind]);
	}
	
	for(ind=0;ind<10;ind++){
		printf("Digite o %i%c valor para o vetor B:\n", ind+1, 248);
		scanf("%i", &vetorB[ind]);
	}
	
	for(ind=0;ind<10;ind++){
		vetorC[ind] = vetorA[ind]+vetorB[ind];
	}
	
	printf("Digite um valor para pesquisa:\n");
	scanf("%i", &pesquisa);
	
	for(ind=0;ind<10;ind++){
		if(pesquisa==vetorC[ind]){
			printf("Valor encontrado na posicao %i\n", ind);
		}
	}
}

// 2-Crie um programa em C que receba três números do usuário depois crie uma função 
//que receba os 3 números como parâmetros: A, B e C. Ordene de tal forma que, ao final 
//da função, A contenha o menor número e C o maior. Imprima os três números. Obs: Utilize ponteiro para solucionar o problema.

#include<stdio.h>

void ordenar(int *pA, int *pB, int *pC);

int main(){
	int a, b, c;
	int *pA, *pB, *pC;
	
	pA = &a;
	pB = &b;
	pC = &c;
	ordenar(pA, pB, pC);
	printf("%d - %d - %d\n", *pA, *pB, *pC);
	printf("%d - %d - %d", a, b, c);
	
	return 0;
}

void ordenar(int *pA, int *pB, int *pC){
	int a, b, c;
	printf("Digite os valores: \n");
	scanf("%d", &a);
	scanf("%d", &b);	
	scanf("%d", &c);	
	fflush(stdin);
	if(a<=b && b<=c){
		*pA = a;
		*pB = b;
		*pC = c;
		}else{
			if(a<=c && c<=b){
				*pA = a;
				*pB = c;
				*pC = b;
			}else{
				if(b<=c && c<=a){
					*pA = b;
					*pB = c;
					*pC = a;
				}
			}
		}

}

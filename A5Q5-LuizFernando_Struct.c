// 5 - Considerando a estrutura abaixo para representar um vetor, implemente um programa 
//que calcule a soma de dois vetores, sabendo que: A + B = < (a1 + a2), (b1 + b2), (c1 + c2)> ,struct vetor{ int a; int b; int c; };

#include <stdio.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>

typedef struct vetor{
	int a;
	int b;
	int c;
}vet;

int main(){
	vet letras[3];

	int i;
	
	for(i=0; i<2; i++){
		printf("Digite o %i%c valor de 'a' : ", i+1, 167);
		scanf("%i", &letras[i].a);
		printf("Digite o valor de 'b' : ", i+1, 167);
		scanf("%i", &letras[i].b);	
		printf("Digite o valor de 'c' : ", i+1, 167);
		scanf("%i", &letras[i].c);	
			
	}
	
	letras[2].a = letras[0].a + letras[1].a;
	letras[2].b = letras[0].b + letras[1].b;
	letras[2].c = letras[0].c + letras[1].c;
	
	printf("A = %i + %i = %i \n", letras[0].a, letras[1].a, letras[2].a);
	printf("B = %i + %i = %i \n", letras[0].b, letras[1].b, letras[2].b);	
	printf("C = %i + %i = %i \n", letras[0].c, letras[1].c, letras[2].c);	
	printf("\n");
	if(letras[2].a + letras[2].b <= letras[0].a + letras[1].a)	{
		printf("A + B <= a1 + a2\n");
	}else{
		printf("A + B > a1 + a2\n");
	}
	if(letras[2].a + letras[2].b <= letras[0].b + letras[1].b)	{
		printf("A + B <= b1 + b2\n");
	}else{
		printf("A + B > b1 + b2\n");
	}
	if(letras[2].a + letras[2].b <= letras[0].c + letras[1].c)	{
		printf("A + B <= c1 + c2\n");
	}else{
		printf("A + B > c1 + c2\n");
	}		
}

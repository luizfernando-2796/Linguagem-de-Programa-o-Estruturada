// Lista 1 - questão 11
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

float lerValidarSalario();
int lerValidarCodigo(int cod[], int cont);
void apresentarMedia(float mediaSalario);
float calcularMedia(int contador, float mediaSalario, float salarios[]);
float encontrarMaiorSalario(int contador, float salarios[], int codigos[], int funcionarioMaiorSalario[], int *indiceMaior);
float encontrarMenorSalario(int contador, float salarios[], int codigos[], int funcionarioMenorSalario[], int *indiceMenor);
void apresentarMaiorMenor(int indiceMaior, int funcionarioMaiorSalario[], float maiorSalario, int indiceMenor, int funcionarioMenorSalario[], float menorSalario);

int main (void){

	float menorSalario, maiorSalario, mediaSalario;
	int contador = 0, indice = 0, indiceMaior = 0, indiceMenor = 0, igual = 0;
	float salarios[MAX] = {0};
	int codigos[MAX] = {0}, funcionarioMenorSalario[MAX] = {0}, funcionarioMaiorSalario[MAX] = {0};

	puts("(codigo 0 ou negativo para encerrar)\n");
	do{
		codigos[contador] = lerValidarCodigo(codigos, contador);
			if(codigos[contador] <= 0){
				break;
			}
		salarios[contador] = lerValidarSalario();		
		contador++;
	}while(contador < MAX);
	
	system("CLS");

	for(indice = 0; indice < contador; indice++){
		if(salarios[0] == salarios[indice]){
			igual++;
		}		
	}
	if(igual == contador){
		printf("\nSalarios iguais.");
	}
	maiorSalario = encontrarMaiorSalario(contador, salarios, codigos, funcionarioMaiorSalario, &indiceMaior);
	menorSalario = encontrarMenorSalario(contador, salarios, codigos, funcionarioMenorSalario, &indiceMenor);
	apresentarMaiorMenor(indiceMaior, funcionarioMaiorSalario, maiorSalario, indiceMenor, funcionarioMenorSalario, menorSalario);
	mediaSalario = calcularMedia(contador, mediaSalario, salarios);
	return 0;
}

int lerValidarCodigo(int cod[], int cont){
	int ind = 0;
	
	printf("Codigo Funcional: ");
	scanf("%i", &cod[cont]);
	
	if(cont <= 1){
		while(cod[cont] <= 0){
			printf("Codigo invalido:");
			scanf("%i", &cod[cont]);
		}
	}
	if(cont > 0){
		do{
			while(cod[cont] == cod[ind]){
				puts("Codigo ja cadastrado.");
				printf("Informe novo codigo:");
				scanf("%i", &cod[cont]);
			}
			ind++;
		}while(cont > 0 && ind < cont);
	}	
	return cod[cont];
}

float lerValidarSalario(){
	float salario;
	
	printf("Salario: R$ ");
	scanf("%f", &salario);
	
	while(salario <= 0){
		puts("Valor de salario invalido.");
		printf("Informe salario: R$ ");
		scanf("%f", &salario);
	}	
	return salario;
}

float encontrarMaiorSalario(int contador, float salarios[], int codigos[], int funcionarioMaiorSalario[], int *indiceMaior){
	int	indice, auxiliar = 0;
	
	float maiorSalario = salarios[0];
	for(indice = (contador - 1); indice >= 0; indice--){
		if(maiorSalario <= salarios[indice]){
			maiorSalario = salarios[indice];
		}
	}
	
	for(indice = 0; indice < contador; indice++){
		if(maiorSalario <= salarios[indice]){
			maiorSalario = salarios[indice];
			funcionarioMaiorSalario[auxiliar] = codigos[indice];		
			auxiliar++; 
		}
	}
	*indiceMaior = auxiliar;
	return maiorSalario;
}

float encontrarMenorSalario(int contador, float salarios[], int codigos[], int funcionarioMenorSalario[], int *indiceMenor){
	int	indice, auxiliar = 0;
	
	float menorSalario = salarios[0];
	for(indice = (contador - 1); indice >= 0; indice--){
		if(menorSalario >= salarios[indice]){
			menorSalario = salarios[indice];
		}
	}
	for(indice = 0; indice < contador; indice++){
		if(menorSalario >= salarios[indice]){
			menorSalario = salarios[indice];
			funcionarioMenorSalario[auxiliar] = codigos[indice];		
			auxiliar++;
		}
	}
	*indiceMenor = auxiliar;
	return menorSalario;
}	

float calcularMedia(int contador, float mediaSalario, float salarios[]){
	int indice;
	for(indice = 0; indice < contador; indice++){
		mediaSalario += salarios[indice];
	}
	mediaSalario /= contador;
	apresentarMedia(mediaSalario);
	return mediaSalario;
}

void apresentarMedia(float mediaSalario){
	printf("\n\nMedia Salarial: R$ %.2f.", mediaSalario);
}

void apresentarMaiorMenor(int indiceMaior, int funcionarioMaiorSalario[], float maiorSalario, int indiceMenor, int funcionarioMenorSalario[], float menorSalario){
	int indice;
	
	printf("\nMaior salario:");
	if(indiceMaior == 1){
		printf("\nCodigo: %i", funcionarioMaiorSalario[0]);
	}
	if(indiceMaior > 1){	
		printf("\nCodigos:");
		for(indice = 0; indice < indiceMaior; indice++){
			if(indice > 0 && indice < indiceMaior - 1){
				printf(",");
			}
			if(indice == indiceMaior - 1){
				printf(" e");
			}
			printf(" %i",funcionarioMaiorSalario[indice]);
		}
	}	
	printf("\nSalario: R$ %.2f", maiorSalario);

	printf("\n\nMenor Salario");
	if(indiceMenor == 1){
		printf("\nCodigo: %i",funcionarioMenorSalario[0]);
	}else{	
		printf("\nCodigos:");
		for(indice = 0; indice < indiceMenor; indice++){
			if(indice > 0 && indice < indiceMenor - 1){
				printf(",");
			}
			if(indice == indiceMenor - 1){
				printf(" e");
			}
			printf(" %i",funcionarioMenorSalario[indice]);
		}
	}	
	printf("\nSalario: R$ %.2f", menorSalario);
}


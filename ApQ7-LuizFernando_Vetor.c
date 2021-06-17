//7 -Desenvolva um algoritmo que cadastre os preços de até 100 diferentes CDs em uma loja. Após este cadastro, 
//o algoritmo deverá possibilitar a execução de uma de duas funções para aumento dos preços cadastrados, 
//sendo a primeira de 10% para todos os CDs, enquanto a segunda aumenta o percentual informado pelo 
//vendedor para todos os CDs. Será o vendedor que escolherá o tipo de aumento desejado. Após os cálculos 
//deverá ser apresentado o percentual de aumento e, para cada CD, o valor sem aumento e o valor com 
//aumento.

#include <stdio.h>

float aumenta10porCento(float precoCD);
float aumentaPorcentagem(float precoCD, float porcentagem);

int main(){
	
	float precoCD[100], precoCD2[100], porcentagem;
	int i, j, escolha;
	char continuar;
	
	for(i=0; i<100; i++){
		printf("Informe o valor do %i%c CD : R$ ", i+1, 167);
		scanf("%f", &precoCD[i]);
		
		printf("\nPressione 'S' para novo valor.\n");
		continuar=getch();	
		continuar=toupper(continuar);
			if(continuar!='S'){
				break;
			}	
	}
	puts("Escolha o aumento: \n");
	puts("1 - Aumento de 10% para todos os CDs. \n");
	puts("2 - Informar o percentual de aumento. \n");
	scanf("%i", &escolha);
	switch (escolha){
		case 1:
			for(j=0; j<=i; j++){
				precoCD2[j]= aumenta10porCento(precoCD[j]);
			}
			break;
		case 2:
			puts("Informe o percentual de aumento: \n");
			scanf("%f", &porcentagem);
			for(j=0; j<=i; j++){
				precoCD2[j]=aumentaPorcentagem(precoCD[j], porcentagem);
			}
			break;		
	}
	if(escolha==1){
		puts("Percentual de aumento 10%. \n");
	}else{
		printf("Percentual de aumento: %.2f por cento.\n", porcentagem);
	}
	for(j=0; j<=i; j++){
		printf("%i%c CD - valor sem aumento: R$ %.2f\n", j+1, 167, precoCD[j]);
		printf("%i%c CD - valor com aumento: R$ %.2f\n", j+1, 167, precoCD2[j]);
		puts("----------------------------------------");
	}
	
}
float aumenta10porCento(float precoCD){
	float result;
	result = precoCD*1.10;
	return result;
}

float aumentaPorcentagem(float precoCD, float porcentagem){
	float resultado1, resultado;
	resultado1 = (precoCD*porcentagem)/100;
	resultado = precoCD+resultado1;
	return resultado;
}

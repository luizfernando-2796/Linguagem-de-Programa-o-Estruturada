//8 -Fazer um algoritmo que leia até 30 caracteres e os ordene em ordem decrescente. 
//É considerado que A < B < C < ... (ordem alfabética).

#include <stdio.h>
#define MAX 30

main(){
	char caracteres[MAX];
	int indice, indice2, indice3, valor1, valor2;
	char auxiliar, continuar;
	
	for(indice=0; indice<MAX; indice++){
		
		printf("\nDigite %i%c letra: ", indice+1, 167);
		caracteres[indice]= getche();

		printf("\nDigite '1' para novo caracter.\n");
		continuar=getch();	
		continuar=toupper(continuar);
		if(continuar!='1'){
			break;
		}	
	}
	for(indice2=0; indice2<indice; indice2++){
		for(indice3=indice2+1; indice3<indice; indice3++){
			valor1=(int) caracteres[indice2];
			valor2=(int) caracteres[indice3];
			if(valor1<valor2){
			auxiliar=caracteres[indice3];
			caracteres[indice3]=caracteres[indice2];
			caracteres[indice2]=auxiliar;
			}
		}
	}
	for(indice2=0; indice2<indice; indice2++){
		if(indice2+1 == indice){
			printf("%c ", caracteres[indice2]);
		}else{
			printf("%c - ", caracteres[indice2]);
		}
	}
}


#include <stdio.h>
#include <locale.h>

int main(){
	
	setlocale(LC_ALL,"");
	int cod_estado, peso, cod_carga;
	float imposto, taxa_imp, preco, preco_quilo, total;
	printf("Digite o código do Estado => [1|2|3|4]: \n");
	scanf ("%d", &cod_estado);
	printf("Digite o peso da carga em toneladas: \n");
	scanf ("%d", &peso);
	printf("Digite o código da carga =>[10|11|12|...|40]: \n");
	scanf ("%d", &cod_carga);
	switch (cod_estado){
		case 1: 
			taxa_imp = 0.2;
			break;
		case 2:
			taxa_imp = 0.15;
			break;
		case 3:
			taxa_imp = 0.1;
			break;
		case 4:
			taxa_imp = 0.05;
			break;
		default:
			taxa_imp = 0;
			printf ("\n Código de estado inválido \n");
			break;
	}
	if (cod_carga >= 10 && cod_carga <= 20){
		preco_quilo = 180;
	}
	else if (cod_carga >= 21 && cod_carga <= 30){
		preco_quilo = 120;
	}
	else if (cod_carga >= 31 && cod_carga <= 40){
		preco_quilo = 230;
	}
	else{
		printf ("\n Código de carga inválido \n");
		preco_quilo = 0;
	}
	
	imposto = peso * 1000 * preco_quilo * taxa_imp;
	preco = peso * 1000 * preco_quilo;
	total = preco + imposto;
	
	printf ("\n Peso em Kg: %d \n Preco: %.2f \n Imposto: %.2f \n Total: %.2f \n", peso * 1000, preco, imposto, total);
	system("pause");
}

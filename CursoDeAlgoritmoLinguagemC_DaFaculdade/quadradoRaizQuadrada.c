#include <stdio.h>
#include <math.h>

int main(){
	int valor;
		printf("\n Digite um numero inteiro:");
		scanf ("%d", &valor);
		printf("\n A potencia de %d e %.2f \n", valor, pow(valor,2));
		printf("\n A potencia de %d e %.2f \n", valor, sqrt(valor));
		system("pause");
		return (0);
}
#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num, maior, menor, cont;
	
	printf("Digite o 1� n�mero: \n");
	scanf ("%d", &num);
	maior = num;
	menor = num;
	
	printf("Digite o 2� n�mero: \n");
	scanf ("%d", &num);
	if (num > maior)
		maior = num;
	if (num < menor)
		menor = num;
	
	printf("Digite o 3� n�mero: \n");
	scanf ("%d", &num);
	if (num > maior)
		maior = num;
	if (num < menor)
		menor = num;
		
	printf("Digite o 4� n�mero: \n");
	scanf ("%d", &num);
	if (num > maior)
		maior = num;
	if (num < menor)
		menor = num;
	
	printf("Digite o 5� n�mero: \n");
	scanf ("%d", &num);
	if (num > maior)
		maior = num;
	if (num < menor)
		menor = num;
		
	printf("O n�mero maior �: %d \n", maior);
	printf("O numero menor �: %d \n", menor);
	system("pause");
	return (0);
}

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num, maior, menor, cont;
	
	printf("Digite o 1° número: \n");
	scanf ("%d", &num);
	maior = num;
	menor = num;
	
	printf("Digite o 2° número: \n");
	scanf ("%d", &num);
	if (num > maior)
		maior = num;
	if (num < menor)
		menor = num;
	
	printf("Digite o 3° número: \n");
	scanf ("%d", &num);
	if (num > maior)
		maior = num;
	if (num < menor)
		menor = num;
		
	printf("Digite o 4° número: \n");
	scanf ("%d", &num);
	if (num > maior)
		maior = num;
	if (num < menor)
		menor = num;
	
	printf("Digite o 5° número: \n");
	scanf ("%d", &num);
	if (num > maior)
		maior = num;
	if (num < menor)
		menor = num;
		
	printf("O número maior é: %d \n", maior);
	printf("O numero menor é: %d \n", menor);
	system("pause");
	return (0);
}

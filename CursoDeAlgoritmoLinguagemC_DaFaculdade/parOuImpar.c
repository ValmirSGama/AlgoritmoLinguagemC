#include <stdio.h>
#include <math.h>

int main()
{
	int quadrado, num;
	float raiz;
	
	printf("\n Digite um numero inteiro: ");
	scanf ("%d", &num);
	if (num % 2 == 0)
	{
		raiz = sqrt(num);
		printf("\n O numero e par.");
		printf("\n A raiz quadrada e: %.3f", raiz);
	}
	else
	{
		quadrado = num * num;
		printf("\n O numero e impar.");
		printf("\n O numero ao quadrado e: %d \n", quadrado);
	}
	system("pause");
	return (0);
	
}

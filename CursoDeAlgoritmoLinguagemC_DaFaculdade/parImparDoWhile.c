#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int par, impar, num;
	par = 0;
	impar = 0;
	do{
		printf("Informe um número: \n");
		scanf("%d", &num);
		if (num % 2 == 0)
			par++;
		else
			impar++;
	}
	while (num != 0);
	printf("A quantidade de par é: %d\n", par);
	printf("A quantidade de impar é: %d\n", impar);
	printf("\n\n");
	system("pause");
	return (0);
}

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int par, impar, num;
	par = 0;
	impar = 0;
	printf("Informe um n�mero: \n");
	scanf("%d", &num);
	while(num != 0){
		if(num % 2 == 0)
			par++;
		else
			impar++;
			printf("Informe um n�mero: \n");
			scanf("%d", &num);
	}
	printf("A quantidade de par �: %d\n", par);
	printf("A quantidade de impar �: %d\n", impar);
	printf("\n\n");
	system("pause");
	return (0);
}

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num, i, qtdade;
	printf("Informe o número: \n");
	scanf ("%d", &num);
	qtdade = 0;
	for (i = 1; i <= num; i++){
		if (num % i == 0)
			qtdade ++;
	}
	if (qtdade == 2)
		printf("O número é primo. \n");
	else
		printf("Não é primo. \n");
	system("pause");
	return (0);
}

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num, i, qtdade;
	printf("Informe o n�mero: \n");
	scanf ("%d", &num);
	qtdade = 0;
	for (i = 1; i <= num; i++){
		if (num % i == 0)
			qtdade ++;
	}
	if (qtdade == 2)
		printf("O n�mero � primo. \n");
	else
		printf("N�o � primo. \n");
	system("pause");
	return (0);
}

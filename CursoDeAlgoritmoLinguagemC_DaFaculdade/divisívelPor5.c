#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num;
	printf("Informe o n�mero: \n");
	scanf ("%d", &num);
	if (num % 5 == 0)
		printf("O n�mero %d � divis�vel por 5 \n", num);
	else
		printf("O n�mero %d n�o � divis�vel por 5 \n", num);
	system("pause");
	return(0);
}

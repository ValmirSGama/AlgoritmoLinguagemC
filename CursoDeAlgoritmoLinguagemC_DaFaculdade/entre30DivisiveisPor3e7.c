#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int i;
	for (i = 1; i <= 30; i++){
		if (i % 3 == 0)
			printf("O n�mero %d � divis�vel por 3.\n", i);
		if (i % 7 == 0)
			printf("O n�mero %d � divis�vel por 7.\n", i);
	}
	system("pause");
	return (0);
}

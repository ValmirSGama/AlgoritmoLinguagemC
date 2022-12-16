#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num;
	printf("Informe o número: \n");
	scanf ("%d", &num);
	if (num % 5 == 0)
		printf("O número %d é divisível por 5 \n", num);
	else
		printf("O número %d não é divisível por 5 \n", num);
	system("pause");
	return(0);
}

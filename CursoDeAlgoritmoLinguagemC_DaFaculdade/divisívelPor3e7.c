#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num;
	
	printf("Informe um n�mero: \n");
	scanf ("%d", &num);
	
	if (num % 3 == 0)
		printf("O n�menro � divis�vel por 3. \n");
	if (num % 7 == 0)
		printf("O n�mero � divis�vel por 7. \n");
	
	system("pause");
	return(0);
}

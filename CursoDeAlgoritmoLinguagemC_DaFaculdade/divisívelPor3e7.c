#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num;
	
	printf("Informe um número: \n");
	scanf ("%d", &num);
	
	if (num % 3 == 0)
		printf("O númenro é divisível por 3. \n");
	if (num % 7 == 0)
		printf("O número é divisível por 7. \n");
	
	system("pause");
	return(0);
}

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int i, num;
	printf("Informe um n�mero: \n");
	scanf ("%d", &num);
	for (i = 3; i <= num; i = i + 3){
		printf("%d \n", i);
	}
	system("pause");
	return (0);
}

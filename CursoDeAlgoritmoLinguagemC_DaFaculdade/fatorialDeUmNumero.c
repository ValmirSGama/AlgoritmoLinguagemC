#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num, i, fat;
	printf("Informe um n�mero: \n");
	scanf ("%d", &num);
	fat = 1;
	for (i = 1; i <= num; i++)
		fat = fat * i;
		printf("O fatorial �: %d \n", fat);
		system("pause");
		return (0);
}

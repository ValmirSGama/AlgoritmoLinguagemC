#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int num, i, fat;
	printf("Informe um número: \n");
	scanf ("%d", &num);
	fat = 1;
	for (i = 1; i <= num; i++)
		fat = fat * i;
		printf("O fatorial é: %d \n", fat);
		system("pause");
		return (0);
}

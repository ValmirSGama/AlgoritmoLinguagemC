#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	char nome[30];
	int i;
	
	printf("Informe o nome: \n");
	scanf("%s", &nome);
	i = 0;
	while (i != 10){
		printf("\n %d - %s", i, nome);
		i++;
	}
	printf("\n\n");
	system("pause");
	return (0);
}

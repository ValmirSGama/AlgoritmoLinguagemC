#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	char nome[30];
	int i;
	
	printf("Informe um nome: \n");
	scanf("%s", &nome);
	i = 0;
	do{
		printf("\n %d - %s", i, nome);
		i++;
	}
	while(i != 10);
	printf("\n\n");
	system("pause");
	return(0);
}

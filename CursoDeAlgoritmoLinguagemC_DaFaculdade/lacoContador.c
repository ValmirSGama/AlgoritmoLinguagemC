#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	char nome[30];
	int i;
	
	printf("Informe o nome:\n");
	scanf("%s", &nome);
	for (i = 1; i <=10; i++){
		printf("\n %s", nome);
	}
	printf("\n \n");
	system("pause");
	return(0);
}

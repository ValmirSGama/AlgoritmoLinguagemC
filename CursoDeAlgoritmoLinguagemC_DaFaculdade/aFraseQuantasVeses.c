#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	char frase[30];
	int i, numero;
	printf("Digite a frase: \n");
	gets(frase);
	printf("Digite o n�mero de repeti��es: \n");
	scanf("%d", &numero);
	for (i = 1; i <= numero; i++){
		printf("%s\n", frase);
	}
	system("pause");
	return (0);
}

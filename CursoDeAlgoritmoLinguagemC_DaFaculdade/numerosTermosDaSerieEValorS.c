#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int numero, i;
	float resposta, divisor;
	resposta = 0;
	printf("Digite um númeoro: \n");
	scanf("%d", &numero);
	for (i = 1; i <= numero; i++){
		divisor = i;
		resposta = resposta + 1/divisor;
	}
	printf("Resposta: %f \n", resposta);
	system("pause");
	return (0);
}

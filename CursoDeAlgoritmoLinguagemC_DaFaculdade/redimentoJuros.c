#include <stdio.h>

int main()
{
	float deposito, taxa, rendimento, total;

	printf("\n Informe o valor do deposito: ");
	scanf ("%f", &deposito);
	printf("\n Informe a taxa de juros:");
	scanf ("%f", &taxa);
	rendimento = deposito * (taxa/100);
	total = deposito + rendimento;
	printf("\n O rendimento e: %.2f", rendimento);
	printf("\n O total e: %.2f \n", total);
	system("pause");
	return (0);
}

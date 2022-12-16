#include <stdio.h>
#include <locale.h>

int main()
{
	float altura, peso;
	char sexo;
	
	printf("Informe o sexo (M/F): \n");
	scanf ("%c", &sexo);
	printf("Informe a altura: \n");
	scanf ("%f", &altura);
	if ((sexo == 'F') || (sexo == 'f'))
	{
		peso = (61.1 * altura) - 44.7;
	}
	else
	{
		peso = (72.7 * altura) - 58;
	}
	printf("O sexo e: %c \n", sexo);
	printf("A altura e: %.2f \n", altura);
	printf("O peso ideal e: %.2f \n", peso);
	system("pause");
	return (0);
}

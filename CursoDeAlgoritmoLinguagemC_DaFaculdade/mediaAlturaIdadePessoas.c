#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int idade, nPessoas;
	float altura, somaA, somaI;
	char sexo;
	somaA = 0;
	somaI = 0;
	nPessoas = 0;
	printf("-------------------------------\n");
	printf("|Continua at� ser digitado (0)|\n");
	printf("-------------------------------\n");
	printf("Informe a idade: \n");
	scanf ("%d", &idade);
	while (idade != 0){
		printf("Informe a altura: \n");
		scanf ("%f", &altura);
		nPessoas++;
		somaI = somaI + idade;
		somaA = somaA + altura;
		printf("Informe a idade: \n");
		scanf ("%d", &idade);
	}
	printf("A m�dia de altura �: %.2f \n", somaA / nPessoas);
	printf("A m�dia de idade �: %.2f \n", somaI / nPessoas);
	system("pause");
	return (0);
}

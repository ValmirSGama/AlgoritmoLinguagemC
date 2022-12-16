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
	printf("|Continua até ser digitado (0)|\n");
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
	printf("A média de altura é: %.2f \n", somaA / nPessoas);
	printf("A média de idade é: %.2f \n", somaI / nPessoas);
	system("pause");
	return (0);
}

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int filhos, nPessoas;
	float salario, somas, somaF, mSalario;
	nPessoas = 0;
	somaF = 0;
	somas = 0;
	mSalario = 0;
	printf("---------------------------\n");
	printf("|Continua at� digitar (-1)|\n");
	printf("---------------------------\n");
	printf("Informe o sal�rio: \n");
	scanf ("%f", &salario);
	while (salario != -1){
		printf("Informe o n�mero de filhos: \n");
		scanf ("%d", &filhos);
		nPessoas++;
		if (salario > mSalario)
			mSalario = salario;
			somaF = somaF + filhos;
			somas = somas + salario;
			printf("Informe o sal�rio: \n");
			scanf ("%f", &salario);
	}
	printf("A m�dia de sal�rios �: %.2f \n", somas / nPessoas);
	printf("A m�dia de filhos �: %.2f \n", somaF / nPessoas);
	printf("O maior sal�rio �: %.2f \n", mSalario);
	system("pause");
	return (0);
}

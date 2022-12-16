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
	printf("|Continua até digitar (-1)|\n");
	printf("---------------------------\n");
	printf("Informe o salário: \n");
	scanf ("%f", &salario);
	while (salario != -1){
		printf("Informe o número de filhos: \n");
		scanf ("%d", &filhos);
		nPessoas++;
		if (salario > mSalario)
			mSalario = salario;
			somaF = somaF + filhos;
			somas = somas + salario;
			printf("Informe o salário: \n");
			scanf ("%f", &salario);
	}
	printf("A média de salários é: %.2f \n", somas / nPessoas);
	printf("A média de filhos é: %.2f \n", somaF / nPessoas);
	printf("O maior salário é: %.2f \n", mSalario);
	system("pause");
	return (0);
}

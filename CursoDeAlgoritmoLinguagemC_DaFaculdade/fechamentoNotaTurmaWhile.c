#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	float nota, soma, media;
	int cod, i, nNotas, nAprovados, nReprovados;
	nAprovados = 0;
	nReprovados = 0;
	printf("Informe o n�mero de notas da disciplina: \n");
	scanf("%d", &nNotas);
	printf("Informe o c�digo do aluno: \n");
	scanf("%d", &cod);
	while (cod != 0){
		soma = 0;
		for (i = 1; i <= nNotas; i++){
			printf("Informe a %d nota do aluno: \n", i);
			scanf("%f", &nota);
			soma = soma + nota;
		}
		media = soma / nNotas;
		if (media >= 6)
			nAprovados ++;
		else
			nReprovados ++;
			printf("Informe o c�digo do aluno:\n");
			scanf("%d", &cod);
	}
	printf("O n�mero de aprovados �: %d \n", nAprovados);
	printf("O n�mero de reprovados �: %d \n", nReprovados);
	printf("A m�dia da turma �: %f \n", media);
	printf("\n\n");
	system("pause");
	return (0);
}

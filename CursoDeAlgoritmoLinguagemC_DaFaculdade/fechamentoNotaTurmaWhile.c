#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	float nota, soma, media;
	int cod, i, nNotas, nAprovados, nReprovados;
	nAprovados = 0;
	nReprovados = 0;
	printf("Informe o número de notas da disciplina: \n");
	scanf("%d", &nNotas);
	printf("Informe o código do aluno: \n");
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
			printf("Informe o código do aluno:\n");
			scanf("%d", &cod);
	}
	printf("O número de aprovados é: %d \n", nAprovados);
	printf("O número de reprovados é: %d \n", nReprovados);
	printf("A média da turma é: %f \n", media);
	printf("\n\n");
	system("pause");
	return (0);
}

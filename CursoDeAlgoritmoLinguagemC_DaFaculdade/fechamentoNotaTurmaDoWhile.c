#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	float nota, soma, media;
	int cod, i, nNota, nAprovado, nReprovado;
	
	nAprovado = 0;
	nReprovado = 0;
	printf("Informe o n�mero de notas da disciplina:\n");
	scanf("%d", &nNota);
	do{
		printf("Informe o c�digo do aluno:\n");
		scanf("%d", &cod);
		soma = 0;
		if (cod != 0){
			for (i = 1; i <= nNota; i++){
				printf("Informe a %d nota do aluno:\n", i);
				scanf("%f", &nota);
				soma = soma + nota;
			}
			media = soma / nNota;
			if (media >= 6)
				nAprovado ++;
			else
				nReprovado ++;
		}
	}
	while (cod != 0);
	printf("O n�mero de aprovados �: %d \n", nAprovado);
	printf("O n�mero de reprovados �: %d \n", nReprovado);
	printf("A m�dia da turma �: %f \n", media);
	printf("\n\n");
	system("pause");
	return (0);
}

#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	float nota, soma, media;
	int cod, i, nNota, nAprovado, nReprovado;
	
	nAprovado = 0;
	nReprovado = 0;
	printf("Informe o número de notas da disciplina:\n");
	scanf("%d", &nNota);
	do{
		printf("Informe o código do aluno:\n");
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
	printf("O número de aprovados é: %d \n", nAprovado);
	printf("O número de reprovados é: %d \n", nReprovado);
	printf("A média da turma é: %f \n", media);
	printf("\n\n");
	system("pause");
	return (0);
}

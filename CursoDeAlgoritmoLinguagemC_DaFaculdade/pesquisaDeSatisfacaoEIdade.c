#include <stdio.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL,"");
	int idade, nPessoas, nPessoasI, nPessoasS, opiniao;
	float somaI, media;
	nPessoas = 0;
	nPessoasS = 0;
	nPessoasI = 0;
	somaI = 0;
	printf("-----------------------------\n");
	printf("|Encerra ao ser digitado (0)|\n");
	printf("-----------------------------\n");
	printf("1- Satisfatório| 2- Indiferente| 3- Insatisfatório.\n");
	printf("Informe a idade: \n");
	scanf ("%d", &idade);
	
	while (idade != 0){
		do{
			printf("Informe a opinião: \n");
			scanf ("%d", &opiniao);
		}while ((opiniao != 1) && (opiniao != 2) && (opiniao != 3));
		nPessoas ++;
		if (opiniao == 1){
			somaI = somaI + idade;
			nPessoasS ++;
		}
		else{
			if (opiniao == 3)
				nPessoasI ++;
		}
		printf("Informe a idade: \n");
		scanf ("%d", &idade);
	}
	media = (somaI / nPessoasS);
	printf("O número de pessoas insatisfeitas é: %d \n", nPessoasI);
	printf("O número de pessoas satisfeita é: %d \n", nPessoasS);
	printf("A média de idade das pessoas satisfeitas é: %.2f \n", media);
	system("pause");
	return (0);
}

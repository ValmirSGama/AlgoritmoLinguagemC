#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*O programa permite que o usuário escolha o tamanho dos vetores vetor1 e vetor2, aloca dinamicamente 
memória para esses vetores, preenche-os com valores calculados usando a função pow() e, em seguida, 
imprime os valores dos vetores.*/

int tamanho;
int *vetor1, *vetor2;

int main(){
	int i;
	printf ("Escolha o tamanho do vetor: ");
	scanf("%d", &tamanho);  // Leitura do tamanho do vetor a partir da entrada padrão.

	vetor1 = (int *) malloc(sizeof (int)*tamanho);  // Alocação dinâmica de memória para vetor1.
	vetor2 = (int *) malloc(sizeof (int)*(tamanho*2));  // Alocação dinâmica de memória para vetor2.

	printf ("\nvetor1: \n");
	for (i = 0; i < tamanho; i++) {
		vetor1[i] = pow(2,i);  // Preenchimento de vetor1 com valores calculados usando a função pow().
		printf ("Posicao %d: %d\n", i, vetor1[i]);  // Impressão das posições e valores de vetor1.
	}

	printf ("\nvetor2: \n");
	for (i = 0; i < tamanho*2; i++) {
		vetor2[i] = pow(3,i);  // Preenchimento de vetor2 com valores calculados usando a função pow().
		printf ("Posicao %d: %d\n", i, vetor2[i]);  // Impressão das posições e valores de vetor2.
	}

	system("pause");  // Comando para pausar a execução do programa (sistema dependente).
	return(0);        // Retorno do valor 0 para indicar que o programa terminou com sucesso.
}

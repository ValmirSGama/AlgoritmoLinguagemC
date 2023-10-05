#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*O programa solicita ao usuário o tamanho do vetor, aloca dinamicamente memória para o vetor, preenche-o 
com valores calculados usando a função pow()*/

int main() {
	int tam;          // Declaração de uma variável para armazenar o tamanho do vetor.
	int *vetor;       // Declaração de um ponteiro para inteiro chamado vetor.
	printf ("Escolha o tamanho do vetor: ");
	scanf("%d", &tam);  // Leitura do tamanho do vetor a partir da entrada padrão.

	vetor = (int *) malloc(sizeof (int)*tam);  // Alocação dinâmica de memória para o vetor.

	for (int i = 0; i < tam; i++){
		vetor[i] = pow(2, i);  // Preenchimento do vetor com valores calculados usando a função pow().
		printf ("posição %d: %d\n", i, vetor[i]);  // Impressão das posições e valores do vetor.
	}

	system("pause");  // Comando para pausar a execução do programa (sistema dependente).
	return(0);        // Retorno do valor 0 para indicar que o programa terminou com sucesso.
}

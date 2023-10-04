#include <stdio.h>
#include <stdlib.h>

/*O programa aloca dinamicamente memória para um inteiro, atribui o valor 42 a essa memória e, em seguida, 
imprime o endereço e o valor armazenado na memória alocada. */
 
int main() {
	int *ptr;  // Declaração de um ponteiro para inteiro chamado ptr.
	ptr = (int *) malloc(sizeof (int));  // Alocação dinâmica de memória para um inteiro e atribuição do endereço ao ptr.
	
	*ptr = 42;  // Atribuição do valor 42 ao local apontado por ptr.
	printf ("Endereco: %p\nvalor: %d \n\n", ptr, *ptr);  // Impressão do endereço e valor apontado por ptr.

	system("pause");  // Comando para pausar a execução do programa (sistema dependente).
	return(0);        // Retorno do valor 0 para indicar que o programa terminou com sucesso.
}

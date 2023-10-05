#include<stdio.h>
#include<stdlib.h>

/* Definição de Ponteiro Alocação Dinâmica, Declara no Escopo Global
Apenas o Endereço do Ponteiro*/

main(){
	int *ptr;  // Declaração de um ponteiro para inteiro chamado ptr.
	printf ("Endereco: %p\n\n", ptr);  // Impressão do valor do ponteiro ptr (não inicializado).

	ptr = (int *) malloc(sizeof (int));  // Alocação de memória para um inteiro e atribuição do endereço ao ptr.
	printf ("Endereco: %p\nvalor: %d\n\n", ptr, *ptr);  // Impressão do endereço e valor apontado por ptr (deve ser não inicializado).

	*ptr = 10;  // Atribuição do valor 10 ao local apontado por ptr.
	printf ("Endereco: %p\nvalor: %d\n\n", ptr, *ptr);  // Impressão do endereço e valor apontado por ptr.

	int x;  // Declaração de uma variável inteira chamada x.
	x = 20;  // Atribuição do valor 20 a x.
	ptr = &x;  // Atribuição do endereço de x a ptr.
	printf ("Endereco: %p\nvalor: %d\n\n", ptr, *ptr);  // Impressão do endereço e valor apontado por ptr (deve ser o endereço de x e 20).

	ptr = (int *) malloc(sizeof (int));  // Alocação de memória para um inteiro e atribuição do endereço ao ptr (substitui a alocação anterior sem liberar a memória).
	printf ("Endereco: %p\nvalor: %d\n\n", ptr, *ptr);  // Impressão do endereço e valor apontado por ptr (deve ser não inicializado).

	system("Pause");  // Comando para pausar a execução do programa (sistema dependente).
	return(0);  // Retorno do valor 0 para indicar que o programa terminou com sucesso.
}

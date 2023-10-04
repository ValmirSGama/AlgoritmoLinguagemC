#include <stdio.h>
#include <stdlib.h>

int xi;          // Declaração de uma variável inteira chamada xi.
int *ptr_xi;     // Declaração de um ponteiro para inteiro chamado ptr_xi.

void imprimir(){
    ptr_xi = &xi;  // Atribuição do endereço de xi a ptr_xi.
    xi = *ptr_xi;  // Atribuição do valor apontado por ptr_xi a xi.

    printf("Valor de xi = %d \n", xi);           // Impressão do valor de xi.
    printf("Valor de &xi = %p \n", &xi);         // Impressão do endereço de xi.
    printf("Valor de ptr_xi = %p \n", ptr_xi);   // Impressão do valor do ponteiro ptr_xi.
    printf("Valor de *ptr_xi = %d \n\n", *ptr_xi); // Impressão do valor apontado por ptr_xi.
}

int main(){
    xi = 10;        // Atribuição de 10 a xi.
    ptr_xi = &xi;   // Atribuição do endereço de xi a ptr_xi.
    imprimir();      // Chamada da função imprimir().

    xi = 20;        // Atribuição de 20 a xi.
    imprimir();      // Chamada da função imprimir().

    *ptr_xi = 30;   // Atribuição de 30 ao valor apontado por ptr_xi (que é o mesmo que xi).
    imprimir();      // Chamada da função imprimir().

    system("pause"); // Comando para pausar a execução do programa (sistema dependente).
    return(0);       // Retorno do valor 0 para indicar que o programa terminou com sucesso.
}
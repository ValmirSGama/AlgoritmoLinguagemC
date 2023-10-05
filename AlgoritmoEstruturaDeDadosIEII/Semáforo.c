#include <stdio.h>
#include <stdlib.h>

/*O programa declara uma estrutura chamada "semaforo" e cria três instâncias dessa estrutura, cada uma com 
um par de valores (cor e id). Em seguida, ele usa um ponteiro para percorrer essas instâncias e imprimir 
os valores de cada uma.*/

// Definição de uma estrutura chamada "semaforo" que tem um campo de texto (cor) e um campo inteiro (id).
struct semaforo {
	char cor[10];
	int id;
};

// Criação de três instâncias (s1, s2 e s3) da estrutura "semaforo" e inicialização com valores.
struct semaforo s1 = {"Vermelho", 1};
struct semaforo s2 = {"Amarelo", 2};
struct semaforo s3 = {"Verde", 3};

struct semaforo *ptr_s; // Declaração de um ponteiro para a estrutura "semaforo".

int main(){
	ptr_s = &s1;  // Atribuição do endereço de s1 ao ponteiro ptr_s.
	printf("%d - %s\n", (*ptr_s).id, (*ptr_s).cor);  // Impressão dos valores de id e cor de s1 usando o ponteiro ptr_s.
	ptr_s = ptr_s + 1;  // Avanço do ponteiro ptr_s para apontar para s2 (pois as instâncias são contíguas na memória).
	printf("%d - %s\n", (*ptr_s).id, (*ptr_s).cor);  // Impressão dos valores de id e cor de s2 usando o ponteiro ptr_s.
	ptr_s = ptr_s + 1;  // Avanço do ponteiro ptr_s para apontar para s3.
	printf("%d - %s\n", (*ptr_s).id, (*ptr_s).cor);  // Impressão dos valores de id e cor de s3 usando o ponteiro ptr_s.
	
	system("pause");  // Comando para pausar a execução do programa (sistema dependente).
	return(0);        // Retorno do valor 0 para indicar que o programa terminou com sucesso.
}

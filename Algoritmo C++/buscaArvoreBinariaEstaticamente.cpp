#include <iostream>

/*Esse código demonstra uma busca em uma árvore binária com vetor estático e o valor de busca pre-definido 
e imprime a posição onde o valor foi encontrado ou uma mensagem "Valor não encontrado" se o valor não 
estiver na árvore.*/

static int buscaArvoreBinaria(int vec[], int arg, int tam) {
	 // Inicializa variáveis para o nó atual (no), o índice de achou e a variável fim
    int no = 0;
    int achou = -1;
    int fim = 0;
	// Enquanto achou for -1 e fim for menor ou igual a tam, continue o loop
    while ((achou == -1) && (fim <= tam)) {
    	// Verifica se o valor arg é igual ao valor no nó atual do vetor
        if (arg == vec[no]) {
            achou = no;	// Se for igual, o valor foi encontrado e o índice é armazenado em achou
        }
        // Se o valor arg for menor que o valor no nó atual, vá para o nó da esquerda
        if (arg < vec[no]) {
            no = (2 * no) + 1;
        } else {	// Caso contrário, vá para o nó da direita
            no = (2 * no) + 2;
        }
        fim++;	// Incrementa a variável fim para controlar o número de iterações
    }

    return achou;	// Retorna o índice onde o valor foi encontrado (ou -1 se não encontrado)
}

int main() {
    // Define o tamanho do vetor e inicializa um vetor ordenado.
    int tamanho = 10;
    int vetor[] = {1, 4, 6, 8, 10, 12, 15, 18, 20, 25};
    
    // Define o valor que estamos procurando na árvore binária.
    int valorProcurado = 15;

    // Chama a função buscaArvoreBinaria para procurar o valor no vetor.
    int resultado = buscaArvoreBinaria(vetor, valorProcurado, tamanho - 1);

    // Verifica se o resultado da busca é diferente de -1 (valor encontrado).
    if (resultado != -1) {
        // Imprime a mensagem indicando que o valor foi encontrado e sua posição.
        std::cout << "Valor encontrado na posição: " << resultado << std::endl;
    } else {
        // Caso contrário, imprime a mensagem de que o valor não foi encontrado.
        std::cout << "Valor não encontrado." << std::endl;
    }

    return 0; // Retorna 0 para indicar que o programa foi concluído com sucesso.
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*Este código implementa o algoritmo de ordenação QuickSort e permite ao usuário gerar uma lista aleatória, 
criar uma lista manualmente e ordená-la usando o QuickSort. A eficiência do QuickSort depende da escolha 
do pivô e da distribuição dos elementos na lista. Em média, o QuickSort possui uma complexidade de tempo 
média de O(n log n), onde "n" é o número de elementos na lista. No entanto, em casos raros, o QuickSort 
pode degradar para O(n^2) se a escolha do pivô for sempre o elemento mínimo ou máximo da lista.*/

#define tamanho 10

// Protótipos das funções
void menu_mostrar(void);
void lista_mostrar(int[]);
void lista_gerar(int[]);
void lista_ler(int[]);
void lista_limpar(int[], int[]);
void lista_mostrar_ordenado(int[], int);
int quickSort(int[], int, int, int);
int particiona(int[], int, int);
void troca(int*, int*);

// Aplica o modo quickSort
int quickSort(int vec[], int left, int right, int qtd) {
    int r;
    if (right > left) {
        r = particiona(vec, left, right);
        qtd = quickSort(vec, left, r - 1, qtd); // Chama recursivamente o quickSort para a metade esquerda.
        qtd = quickSort(vec, r + 1, right, qtd); // Chama recursivamente o quickSort para a metade direita.
    }
    return (qtd + 1); // Incrementa o contador de iterações.
}

// Divide o vetor em pedaços menores
int particiona(int vec[], int left, int right) {
    int i, j;
    i = left;
    for (j = left + 1; j <= right; ++j) {
        if (vec[j] < vec[left]) {
            ++i;
            troca(&vec[i], &vec[j]); // Troca os elementos se o elemento atual for menor que o pivô.
        }
    }
    troca(&vec[left], &vec[i]); // Coloca o pivô na posição correta.
    return i; // Retorna a posição do pivô.
}

// Função de troca de elementos
void troca(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Mostra o conteúdo da lista
void lista_mostrar(int vec[]) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vec[i]);
    }
    printf("]\n\n");
}

// Mostra o menu
void menu_mostrar(void) {
    printf("1 - Gerar lista aleatoriamente\n");
    printf("2 - Criar lista manualmente\n");
    printf("3 - QuickSort ordena lista\n");
    printf("0 - Sair...\n\n");
}

// Mostra o conteúdo da lista ordenada
void lista_mostrar_ordenado(int vec[], int qtd) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vec[i]);
    }
    printf("] Tempo = %d iterações\n\n", qtd);
}

// Gera uma lista aleatória
void lista_gerar(int vec[]) {
    for (int i = 0; i < tamanho; i++) {
        vec[i] = rand() % 50; // Preenche o vetor com números aleatórios entre 0 e 49.
    }
}

// Permite que o usuário entre com os valores da lista
void lista_ler(int vec[]) {
    for (int i = 0; i < tamanho; i++) {
        system("cls"); // Limpa a tela do console (específico para sistemas Windows).
        lista_mostrar(vec); // Chama a função para mostrar a lista atual.
        printf("\nDigite o valor para a posicao %d: ", i); // Solicita que o usuário insira um valor.
        scanf("%d", &vec[i]); // Lê o valor inserido pelo usuário.
    }
}

// Prepara a lista para ordenação
void lista_limpar(int lista[], int ordenado[]) {
    for (int i = 0; i < tamanho; i++) {
        ordenado[i] = lista[i]; // Copia a lista original para a lista ordenada.
    }
}

// Função Principal
int main(void) {
    setlocale(LC_ALL,""); // Configura a localização para lidar com caracteres acentuados.
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios.

    int lista[tamanho]; // Declaração de um vetor chamado 'lista'.
    int ordenado[tamanho]; // Declaração de outro vetor chamado 'ordenado'.
    int opt = -1; // Declaração de uma variável para a opção do menu.
    int qtd = 0; // Declaração de uma variável para contar o número de iterações.

    do { // Início de um loop do-while para exibir o menu e processar opções.
        system("cls"); // Limpa a tela do console (específico para sistemas Windows).
        lista_mostrar(lista); // Chama a função para exibir a lista não ordenada.
        lista_mostrar_ordenado(ordenado, qtd); // Chama a função para exibir a lista ordenada.
        menu_mostrar(); // Chama a função para exibir o menu de opções.
        scanf("%d", &opt); // Lê a opção escolhida pelo usuário.

        switch (opt) { // Início de uma estrutura de seleção switch para processar a opção.
            case 1: // Caso a opção seja 1:
                lista_gerar(lista); // Chama a função para gerar uma lista aleatória.
                break;
            case 2: // Caso a opção seja 2:
                lista_ler(lista); // Chama a função para permitir que o usuário insira valores na lista.
                break;
            case 3: // Caso a opção seja 3:
                lista_limpar(lista, ordenado); // Chama a função para preparar a lista para ordenação.
                qtd = quickSort(ordenado, 0, tamanho - 1, qtd); // Chama a função de ordenação e armazena o número de iterações.
                break;
        }
    } while (opt != 0); // O loop continua até que o usuário escolha a opção 0 (sair).

    system("pause"); // Pausa a execução para que o usuário possa ver os resultados antes de encerrar o programa.
    return 0; // Retorna 0 para indicar que o programa foi encerrado com sucesso.
}
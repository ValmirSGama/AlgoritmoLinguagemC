// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*Este código é uma implementação do algoritmo Bubble Sort, ele contabiliza
as iterações e exibe esse valor no momento em que mostra a lista ordenada.*/

// Constantes
#define tamanho 10

// Variáveis
int lista[tamanho];
int ordenado[tamanho];
int opt = -1;
int qtd;

// Prototipação
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);
void troca(int* a, int* b);
int bubbleSort(int vec[]);

// Função de troca de valores
void troca(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

// Função de ordenação usando o Bubblesort
int bubbleSort(int vec[]) {
    int qtd, i, j;
    qtd = 0;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = i + 1; j < tamanho; j++) {
            if (vec[i] > vec[j]) {
                troca(&vec[i], &vec[j]);
            }
            qtd++;
        }
    }
    return qtd;
}

// Mostra o conteúdo da lista
void lista_mostrar(void) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("]\n\n");
}

// Mostra o menu
void menu_mostrar(void) {
    printf("1 - Gerar lista aleatoriamente\n");
    printf("2 - Criar lista manualmente\n");
    printf("0 - Sair...\n\n");
}

// Gera uma lista aleatória
void lista_gerar(void) {
    for (int i = 0; i < tamanho; i++) {
        lista[i] = rand() % 50;
    }
}

// Permite que o usuário entre com os valores da lista
void lista_ler(void) {
    for (int i = 0; i < tamanho; i++) {
        system("cls");
        lista_mostrar();
        printf("\nDigite o valor para a posicao %d: ", i);
        scanf("%d", &lista[i]);
    }
}

// Prepara a lista para ordenação
void lista_limpar(void) {
    for (int i = 0; i < tamanho; i++) {
        ordenado[i] = lista[i];
    }
}

// Mostra o conteúdo da lista ordenada
void lista_mostrar_ordenado(void) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", ordenado[i]);
    }
    printf("] Tempo = %d iterações\n\n", qtd);
}

// Função Principal
int main(void) {
	setlocale(LC_ALL,"");
    srand(time(NULL));
    do {
        system("cls");
        lista_mostrar();
        lista_mostrar_ordenado();
        menu_mostrar();
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                lista_gerar();
                lista_limpar();  // Adiciona a chamada para limpar a lista antes da ordenação
                qtd = bubbleSort(ordenado);  // Chama a função bubbleSort para ordenar a lista
                break;
            case 2:
                lista_ler();
                lista_limpar();  // Adiciona a chamada para limpar a lista antes da ordenação
                qtd = bubbleSort(ordenado);  // Chama a função bubbleSort para ordenar a lista
                break;
        }
    } while (opt != 0);
    system("pause");
    return 0;
}
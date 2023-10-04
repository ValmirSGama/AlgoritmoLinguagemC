// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*Este código implementa o algoritmo de ordenação Insertion Sort e contabiliza a quantidade de iterações 
realizadas durante a ordenação. Ele é eficiente para conjuntos de dados pequenos ou parcialmente ordenados. 
Ele têm complexidade de tempo de O(n^2) no pior caso.*/

// Constantes
#define tamanho 10

// Variáveis
int lista[tamanho];
int ordenado[tamanho];
int opt = -1;
int qtd;  // Variável para armazenar a quantidade de iterações

// Prototipação
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);
void troca(int *a, int *b);
int insertionSort(int vec[], int tam);  // Protótipo da função de Insertion Sort

// Função para trocar dois elementos de posição
void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Aplicando o Insertion Sort
int insertionSort(int vec[], int tam)
{ 
    int i, j, qtd = 0;  // Inicializa a variável qtd
    for(i = 1; i < tam; i++){
        j = i;
        while((vec[j] < vec[j - 1]) && (j != 0)){
            troca(&vec[j], &vec[j-1]); 
            j--; 
            qtd++;  // Incrementa qtd a cada comparação e troca
        } 
    }
    return qtd;  // Retorna a quantidade de iterações
}

// Mostra o menu
void menu_mostrar(void){
    printf("1 - Gerar lista aleatoriamente\n");
    printf("2 - Criar lista manualmente\n");
    printf("3 - InsertionSort ordena lista\n");  // Adiciona a opção para ordenar usando o Insertion Sort
    printf("0 - Sair...\n\n");
}

// Mostra o conteúdo da lista
void lista_mostrar(void){
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("]\n\n");
}

// Gera uma lista aleatória
void lista_gerar(void){
    for (int i = 0; i < tamanho; i++){
        lista[i] = rand() % 50;
    }
}

// Permite que o usuário entre com os valores da lista
void lista_ler(void){
    for (int i = 0; i < tamanho; i++){
        system("cls");
        lista_mostrar();
        printf("\nDigite o valor para a posição %d: ", i);
        scanf("%d", &lista[i]);
    }
}

// Prepara a lista para ordenação
void lista_limpar(void){
    for (int i = 0; i < tamanho; i++) {
        ordenado[i] = lista[i];
    }
}

// Mostra o conteúdo da lista ordenada
void lista_mostrar_ordenado(void){
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", ordenado[i]);
    }
    printf("] Tempo = %d iterações\n\n", qtd);  // Exibe a quantidade de iterações
}

// Função Principal
int main(void){
    setlocale(LC_ALL,"");
    srand(time(NULL));
    do {
        system("cls");
        lista_mostrar();
        lista_mostrar_ordenado();
        menu_mostrar();
        scanf("%d", &opt);
        
        switch (opt){
            case 1:
                lista_gerar();
                break;
            case 2:
                lista_ler();
                break;
            case 3:
                lista_limpar();  // Adiciona a chamada para limpar a lista antes da ordenação
                qtd = insertionSort(ordenado, tamanho);  // Chama a função insertionSort para ordenar a lista
                break;
        }
    } while (opt != 0);
    
    system("pause");
    return 0;
}

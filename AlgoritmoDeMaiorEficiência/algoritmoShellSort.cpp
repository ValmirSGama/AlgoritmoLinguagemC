// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*Este código implementa o algoritmo de ordenação Shell Sort e contabiliza a quantidade de iterações 
realizadas durante a ordenação. O Shell Sort é um algoritmo de ordenação eficiente para conjuntos de 
dados de tamanho moderado e é uma melhoria em relação ao Bubble Sort e ao Insertion Sort. Ele tem 
uma complexidade de tempo média de O(n^1.5)*/

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
int shellSort(int vec[], int tam);  // Protótipo da função Shell Sort

// Função para trocar dois elementos de posição
void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Aplicando o Shell Sort
int shellSort(int vec[], int tam) {
    int i , j , valor, qtd = 0;  // Inicializa a variável qtd
    int gap = 1;
    do {
        gap = 3*gap+1;
    } while(gap < tam);
    do {
        gap /= 3;
        for(i = gap; i < tam; i++) {
            valor = vec[i];
            j = i - gap;
            while (j >= 0 && valor < vec[j]) {
                vec[j + gap] = vec[j];
                j -= gap;
                qtd++;  // Incrementa qtd a cada comparação e troca
            }
            vec[j + gap] = valor;
        }
    } while ( gap > 1);
    return (qtd);  // Retorna a quantidade de iterações
}

// Mostra o menu
void menu_mostrar(void){
    printf("1 - Gerar lista aleatoriamente\n");
    printf("2 - Criar lista manualmente\n");
    printf("3 - ShellSort ordena lista\n");  // Adiciona a opção para ordenar usando o Shell Sort
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
                qtd = shellSort(ordenado, tamanho);  // Chama a função shellSort para ordenar a lista
                break;
        }
    } while (opt != 0);
    
    system("pause");
    return 0;
}

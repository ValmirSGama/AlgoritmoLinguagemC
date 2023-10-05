#include <stdio.h>
#include <stdbool.h>

/*Esse algoritmo é chamado de "Busca em Largura (Breadth-First Search, BFS)" em um grafo. Ele realiza uma 
busca em largura em um grafo não direcionado, começando a partir de um nó de origem e procurando um nó 
de destino.*/

#define MAXV 100

struct str_no {
    int id;
    struct str_no* proximo;
};

// Função para realizar a busca em largura em um grafo
void buscaEmLargura(struct str_no g[], int inicio, int alvo) {
    int fila[MAXV]; // fila
    bool visitado[MAXV]; // nós visitados
    int indice = 0; // controle da fila
    bool achou = false; // flag (não visitados)
    int corrente = inicio;
    struct str_no* ptr;
    int i;
    
    printf("=-=-=-= Busca em Largura =-=-=-= \n");
    
    // Inicializando visitados
    for (i = 0; i < MAXV; i++)
        visitado[i] = false;
    
    // Inicializando fila e visitando o primeiro nó
    printf("VISITANDO: %d. \n", corrente);
    visitado[corrente] = true;
    fila[indice] = corrente;
    indice++;
    
    while (true) {
        // Percorrendo os nós adjacentes ao vértice corrente
        for (ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo) {
            corrente = ptr->id;
            if (!visitado[corrente]) {
                printf("VISITANDO: %d. \n", corrente);
                if (corrente == alvo) {
                    printf("Alvo encontrado!\n\n\n");
                    return;
                }
                visitado[corrente] = true;
                fila[indice] = corrente;
                indice++;
            }
        }
        
        // Verificando se a fila não está vazia
        if (indice != 0) {
            // Atualizando o vértice corrente
            corrente = fila[0];
            // Desenfileirando o primeiro vértice
            for (i = 1; i < indice; i++)
                fila[i - 1] = fila[i];
            indice--;
        } else {
            // Não há mais vértices para visitar
            printf("Encerrando busca.\n");
            break;
        }
    }
    return;
}

int main() {
    struct str_no grafo[MAXV];
    for (int i = 0; i < MAXV; i++) {
        grafo[i].id = i;
        grafo[i].proximo = NULL;
    }
    
    // Adicionando as arestas no grafo (exemplo de grafo não direcionado)
    grafo[0].proximo = &(struct str_no){1, &(struct str_no){2, NULL}};
    grafo[1].proximo = &(struct str_no){0, &(struct str_no){3, &(struct str_no){4, NULL}}};
    grafo[2].proximo = &(struct str_no){0, &(struct str_no){4, NULL}};
    grafo[3].proximo = &(struct str_no){1, &(struct str_no){4, NULL}};
    grafo[4].proximo = &(struct str_no){1, &(struct str_no){2, &(struct str_no){3, NULL}}};
    
    // Executando a busca em largura
    buscaEmLargura(grafo, 0, 4);
    
    return 0;
}

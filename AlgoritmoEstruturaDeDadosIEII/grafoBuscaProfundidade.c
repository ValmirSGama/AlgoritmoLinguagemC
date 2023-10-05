#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*algoritmo é chamado de "Busca em Profundidade (Depth-First Search, DFS)" em um grafo. Ele realiza 
uma busca em profundidade em um grafo não direcionado, começando a partir de um nó de origem e 
procurando um nó de destino.*/

#define MAXV 100

struct str_no {
    int id;
    struct str_no *proximo;
};

// Função para realizar a busca em profundidade em um grafo
void buscaEmProfundidade(struct str_no g[], int inicio, int alvo) {
    int pilha[MAXV]; // Pilha para armazenar os nós visitados
    bool visitado[MAXV]; // Array para marcar os nós visitados
    int indice = 0; // Índice do topo da pilha
    bool achou = false; // Flag de controle para nós não visitados
    int corrente = inicio; // Nó corrente para iniciar a busca
    struct str_no *ptr;
    int i;
    
    printf("=-=-=-= Busca em Profundidade =-=-=-=\n");
    
    // Marcando todos os nós como 'não visitados'
    for(i = 0; i < MAXV; i++) {
        visitado[i] = false;
    }
    
    // Loop principal da busca em profundidade
    while(true) {
        // Se o nó corrente ainda não foi visitado, marque como visitado e empilhe
        if(!visitado[corrente]) {
            printf("VISITANDO: %d. \n", corrente);
            
            if(corrente == alvo) {
                printf("Alvo encontrado!\n\n\n");
                return;
            }
            
            visitado[corrente] = true;
            pilha[indice] = corrente;
            indice++;
        }
        
        // Buscando por nós adjacentes não visitados
        achou = false;
        
        // Percorre a lista de nós adjacentes ao nó corrente
        for(ptr = g[corrente].proximo; ptr != NULL; ptr = ptr->proximo) {
            if(!visitado[ptr->id]) {
                achou = true;
                break;
            }
        }
        
        if(achou) {
            // Atualiza o nó corrente para o próximo não visitado
            corrente = ptr->id;
        } else {
            // Não há vértices adjacentes não visitados, tenta desempilhar o vértice do topo
            indice--;
            
            if(indice == -1) {
                // Não há mais vértices não visitados, encerra a busca
                printf("Encerrando a busca. \n");
                break;
            }
            
            corrente = pilha[indice-1];
        }
    }
    return;
}

// Função auxiliar para criar o grafo
void criarGrafo(struct str_no g[], int numVertices) {
    int i;
    for (i = 0; i < numVertices; i++) {
        g[i].id = i;
        g[i].proximo = NULL;
    }
}

// Função auxiliar para adicionar uma aresta ao grafo
void adicionarAresta(struct str_no g[], int origem, int destino) {
    struct str_no *novoNo = (struct str_no *)malloc(sizeof(struct str_no));
    novoNo->id = destino;
    novoNo->proximo = g[origem].proximo;
    g[origem].proximo = novoNo;
}

int main() {
    int numVertices = 5;
    struct str_no grafo[MAXV];
    
    criarGrafo(grafo, numVertices);

    // Adicionando arestas ao grafo
    adicionarAresta(grafo, 0, 1);
    adicionarAresta(grafo, 0, 2);
    adicionarAresta(grafo, 1, 3);
    adicionarAresta(grafo, 2, 4);
    
    // Executando a busca em profundidade
    buscaEmProfundidade(grafo, 0, 4);

    return 0;
}

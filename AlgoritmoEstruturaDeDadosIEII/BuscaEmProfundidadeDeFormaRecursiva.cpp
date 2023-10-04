//exemplo de implementação da busca em profundidade de forma recursiva:
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Estrutura de um vértice
typedef struct {
	int visitado;
	int adjacentes[MAX_VERTICES];
	int numAdjacentes;
} Vertice;

// Função para realizar a busca em profundidade recursiva
void buscaProfundidadeRecursiva(Vertice *grafo, int vertice) {
	grafo[vertice].visitado = 1;
	printf("%d ", vertice);

	for (int i = 0; i < grafo[vertice].numAdjacentes; i++) {
		int verticeAdjacente = grafo[vertice].adjacentes[i];
		if (!grafo[verticeAdjacente].visitado) {
			buscaProfundidadeRecursiva(grafo, verticeAdjacente);
		}
	}
}

// Função principal
int main() {
	int numVertices = 6;

	Vertice grafo[numVertices];

	// Inicialização do grafo com vértices não visitados
	for (int i = 0; i < numVertices; i++) {
		grafo[i].visitado = 0;
		grafo[i].numAdjacentes = 0;
	}

	// Definição das arestas do grafo
	grafo[0].adjacentes[0] = 1;
	grafo[0].adjacentes[1] = 2;
	grafo[0].numAdjacentes = 2;

	grafo[1].adjacentes[0] = 3;
	grafo[1].adjacentes[1] = 4;
	grafo[1].numAdjacentes = 2;

	grafo[2].adjacentes[0] = 5;
	grafo[2].numAdjacentes = 1;

	printf("Busca em Profundidade Recursiva: ");
	buscaProfundidadeRecursiva(grafo, 0);

	return 0;
}

/*Neste exemplo, a função buscaProfundidadeRecursiva é responsável por
 realizar a busca em profundidade de forma recursiva.

Ela marca o vértice como visitado, imprime seu valor e, em seguida, chama a função
recursivamente para cada vértice adjacente não visitado.

Ambos os exemplos implementam a busca em profundidade em um grafo
representado por uma estrutura de vértices com listas de adjacência.

A busca em profundidade percorre o grafo a partir de um vértice inicial,
explorando o máximo possível em cada ramificação antes de retroceder.*/
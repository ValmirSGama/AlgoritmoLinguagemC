//Busca em Profundidade Iterativa
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Estrutura de um vértice
typedef struct {
	int visitado;
	int adjacentes[MAX_VERTICES];
	int numAdjacentes;
} Vertice;

// Pilha para a busca em profundidade iterativa
typedef struct {
	int itens[MAX_VERTICES];
	int topo;
} Pilha;

// Função para inicializar a pilha
void inicializarPilha(Pilha *pilha) {
	pilha->topo = -1;
}

// Função para verificar se a pilha está vazia
int pilhaVazia(Pilha *pilha) {
	return pilha->topo == -1;
}

// Função para empilhar um item
void empilhar(Pilha *pilha, int item) {
	pilha->itens[++pilha->topo] = item;
}

// Função para desempilhar um item
int desempilhar(Pilha *pilha) {
	return pilha->itens[pilha->topo--];
}

// Função para realizar a busca em profundidade iterativa
void buscaProfundidadeIterativa(Vertice *grafo, int numVertices, int verticeInicial) {
	Pilha pilha;
	inicializarPilha(&pilha);

	grafo[verticeInicial].visitado = 1;
	empilhar(&pilha, verticeInicial);

	while (!pilhaVazia(&pilha)) {
		int verticeAtual = desempilhar(&pilha);
		printf("%d ", verticeAtual);

		int i;
		for (i = 0; i < grafo[verticeAtual].numAdjacentes; i++) {
			int verticeAdjacente = grafo[verticeAtual].adjacentes[i];
			if (!grafo[verticeAdjacente].visitado) {
				grafo[verticeAdjacente].visitado = 1;
				empilhar(&pilha, verticeAdjacente);
			}
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

	printf("Busca em Profundidade Iterativa: ");
	buscaProfundidadeIterativa(grafo, numVertices, 0);

	return 0;
}

/*O algoritmo começa definindo uma estrutura de dados chamada "Pilha",
que será utilizada para armazenar os vértices a serem visitados. Em
seguida, temos a função buscaProfundidadeIterativa, que recebe como
parâmetros o grafo, o número de vértices e o vértice inicial.

Dentro da função buscaProfundidadeIterativa, inicializamos a pilha
vazia e marcamos o vértice inicial como visitado. Em seguida,
empilhamos o vértice inicial na pilha.

A partir daí, entramos em um loop enquanto a pilha não estiver vazia.
Em cada iteração do loop, desempilhamos um vértice da pilha e o
visitamos. Nesse caso, a visita consiste em apenas imprimir o valor do
vértice.

Após visitar o vértice, percorremos todos os vértices adjacentes a ele.
Se algum vértice adjacente ainda não tiver sido visitado, marcamos
como visitado e o empilhamos na pilha. Dessa forma, garantimos que ele
será visitado posteriormente.

O loop continua até que a pilha esteja vazia, o que significa que todos
os vértices alcançáveis a partir do vértice inicial foram visitados.

Neste exemplo, o grafo é representado por uma estrutura de vértices com
listas de adjacência. Cada vértice contém um array chamado "adjacentes",
que armazena os índices dos vértices adjacentes a ele.

Por fim, no programa principal, criamos um grafo de exemplo com 6
vértices e definimos as arestas entre eles. Chamamos a função
buscaProfundidadeIterativa, passando o grafo, o número de vértices e o
vértice inicial como argumentos.

O algoritmo, então, executa a busca em profundidade iterativa a partir
do vértice inicial e imprime a sequência de vértices visitados.*/
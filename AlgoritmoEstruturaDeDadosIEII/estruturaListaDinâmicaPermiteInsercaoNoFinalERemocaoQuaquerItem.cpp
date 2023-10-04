#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Este algoritmo é um exemplo de implementação de uma lista encadeada, onde os nós são 
inseridos no final da lista e podem ser removidos com base em seu valor.*/

// Definindo a estrutura da lista
typedef struct no {
	int dado;
	struct no *proximo;
} no;

// Definindo variáveis
typedef no *ptr_no;
ptr_no lista;
int op;

// Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void lista_inserir(ptr_no lista);
void lista_remover(ptr_no lista);
void lista_mostrar(ptr_no lista);

// Função principal
int main() {
	// Inicialização da máquina de números randômicos
	srand(time(NULL));
	op = 1;

	// Criando o primeiro nó da lista
	lista = (ptr_no)malloc(sizeof(no));
	lista->dado = 0;
	lista->proximo = NULL;

	// Laço principal
	while (op != 0) {
		system("cls"); // Limpa a tela (sistema dependente).
		menu_mostrar(); // Mostra o conteúdo da lista e o menu de opções.
		scanf("%d", &op); // Leitura da escolha do usuário.
		menu_selecionar(op); // Chama a função correspondente com base na escolha do usuário.
	}
	system("pause");
	return (0);
}

// Mostrar o menu de opções
void menu_mostrar() {
	lista_mostrar(lista); // Mostra o conteúdo da lista.
	printf("\n\nEscolha uma das opções:\n");
	printf("1 - Inserir no final da lista\n");
	printf("2 - Remover um item da lista\n");
	printf("0 - Sair\n\n");
}

// Executa a opção escolhida no menu
void menu_selecionar(int op) {
	switch (op) {
		case 1:
			lista_inserir(lista); // Chama a função para inserir no final da lista.
			break;
		case 2:
			lista_remover(lista); // Chama a função para remover um item da lista.
			break;
	}
}

// Inserir um elemento no final da lista
void lista_inserir(ptr_no lista) {
	while (lista->proximo != NULL) {
		lista = lista->proximo;
	}
	lista->proximo = (ptr_no)malloc(sizeof(no));
	lista = lista->proximo;
	lista->dado = rand() % 100; // Insere um valor aleatório no novo nó.
	lista->proximo = NULL;
}

// Remove um elemento da lista por valor
void lista_remover(ptr_no lista) {
	int dado;
	ptr_no atual;
	atual = (ptr_no)malloc(sizeof(no));
	printf("\n\nEscolha um dos itens:\n");
	scanf("%d", &dado);
	while ((lista->dado != dado)) {
		if (lista->proximo == NULL) {
			break;
		}
		atual = lista;
		lista = lista->proximo;
	}
	if (lista->dado == dado) {
		atual->proximo = lista->proximo;
	}
}

// Mostra o conteúdo da lista
void lista_mostrar(ptr_no lista) {
	system("cls"); // Limpa a tela (sistema dependente).
	while (1) {
		printf("%d, ", lista->dado);
		if (lista->proximo == NULL) {
			break;
		}
		lista = lista->proximo;
	}
}

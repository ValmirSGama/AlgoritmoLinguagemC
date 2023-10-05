// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*Este algoritmo é um exemplo de implementação de uma fila, que permite ao usuário interagir com 
a fila por meio de operações de inclusão e exclusão, além de visualizar o estado atual da fila.*/

// Constantes
#define tamanho 5

// Estrutura da Fila
struct tfila {
	int dados[tamanho];
	int ini;
	int fim;
};

// Variáveis globais
struct tfila fila;
int op;

// Prototipação
void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();

// Função principal
int main(){
	setlocale(LC_ALL, "portuguese");
	op = 1;
	fila.ini = 0;
	fila.fim = 0;
	while (op != 0) {
		system("cls");  // Limpa a tela (sistema dependente).
		fila_mostrar();  // Mostra o conteúdo da fila.
		menu_mostrar();  // Mostra o menu de opções.
		scanf("%d", &op);  // Leitura da escolha do usuário.
		switch (op) {
			case 1:
				fila_entrar();  // Chama a função para incluir na fila.
				break;
			case 2: 
				fila_sair();  // Chama a função para excluir da fila.
				break;
		}
	}
	return(0);
}

// Adicionar um elemento no final da fila
void fila_entrar() {
	if (fila.fim == tamanho) {
		printf("\nA fila está cheia, volte outro dia!\n\n");
		system("pause");  // Pausa a execução do programa (sistema dependente).
	}
	else {
		printf("\nDigite o valor a ser inserido: ");
		scanf("%d", &fila.dados[fila.fim]);
		fila.fim++;
	}
}

// Retirar o primeiro elemento da fila
void fila_sair() {
	if (fila.ini == fila.fim) {
		printf("\nFila vazia, mas logo aparece alguém!\n\n");
		system("pause");  // Pausa a execução do programa (sistema dependente).
	}
	else {
		int i;
		for (i = 0; i < tamanho; i++) {
			fila.dados[i] = fila.dados[i+1];
		}
		fila.dados[fila.fim] = 0;
		fila.fim--;
	}
}

// Mostrar o conteúdo da fila
void fila_mostrar() {
	int i;
	printf("[ ");
	for (i = 0; i < tamanho; i++) {
		printf("%d ", fila.dados[i]);
	}
	printf("]\n\n");
}

// Mostrar o menu de opções
void menu_mostrar() {
	printf("\nEscolha uma opção:\n");
	printf("1 - Incluir na fila\n");
	printf("2 - Excluir da fila\n");
	printf("0 - Sair\n\n");
}

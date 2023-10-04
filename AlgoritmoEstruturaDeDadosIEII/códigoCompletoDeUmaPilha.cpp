#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/*O programa implementa uma pilha simples usando uma estrutura e fornece um menu de opções para empilhar, 
desempilhar e sair do programa.*/

// Constantes
#define tamanho 5

// Estrutura de Pilha
struct tpilha {
	int dados[tamanho];
	int ini;
	int fim;
};

// Variáveis globais
struct tpilha pilha;
int op;

// Prototipação
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();

// Função principal
int main(){
	setlocale(LC_ALL, "Portuguese");
	op = 1;
	pilha.ini = 0;
	pilha.fim = 0;
	while (op != 0) {
		system("cls");  // Limpa a tela (sistema dependente).
		pilha_mostrar();  // Mostra o conteúdo da pilha.
		menu_mostrar();  // Mostra o menu de opções.
		scanf ("%d", &op);  // Leitura da escolha do usuário.
		switch (op) {
			case 1:
				pilha_entrar();  // Chama a função para empilhar.
				break;
			case 2:
				pilha_sair();  // Chama a função para desempilhar.
				break;
		}
	}
	return(0);
}

// Adicionar um elemento no final da pilha
void pilha_entrar() {
	if (pilha.fim == tamanho) {
		printf("\nA pilha está cheia, impossível empilhar!\n\n");
		system("pause");  // Pausa a execução do programa (sistema dependente).
	}
	else {
		printf("\nDigite o valor a ser empilhado: ");
		scanf("%d", &pilha.dados[pilha.fim]);
		pilha.fim++;
	}
}

// Retirar o último elemento da pilha
void pilha_sair() {
	if (pilha.ini == pilha.fim) {
		printf("\nA pilha está vazia, impossível desempilhar!\n\n");
		system("pause");  // Pausa a execução do programa (sistema dependente).
	}
	else {
		pilha.dados[pilha.fim-1] = 0;
		pilha.fim--;
	}
}

// Mostrar o conteúdo da pilha
void pilha_mostrar() {
	int i;
	printf("[  ");
	for (i = 0; i < tamanho; i++) {
		printf("%d  ", pilha.dados[i]);
	}
	printf("]\n\n");
}

// Mostrar o menu de opções
void menu_mostrar() {
	printf("\nEscolha uma opção:\n");
	printf("1 - Empilhar\n");
	printf("2 - Desempilhar\n");
	printf("0 - Sair\n\n");
}

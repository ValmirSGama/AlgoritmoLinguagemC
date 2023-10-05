#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*Esse algoritmo é chamado de "Gerenciamento de Fila", e ele permite que os usuários entrem na fila, 
saiam da fila e visualizem o conteúdo atual da fila.*/ 

//Constantes
#define tamanho 5

//Estrutura do Cliente
struct tcliente {
    char nome[50];
    char hora[6];
};

//Estrutura da Fila
struct tfila {
    struct tcliente dados[tamanho];
    int ini;
    int fim; 
};

//Variáveis globais
struct tfila fila;

//Adicionar um elemento no final da Fila
void fila_entrar() {
    if (fila.fim == tamanho) {
        printf("\nA fila está cheia, volte outro dia!\n\n");
        system("pause");
    } else {
        printf("\nDigite o nome do cliente que chegou: ");
        scanf("%s", fila.dados[fila.fim].nome);
        printf("\nDigite a hora da chegada do cliente: ");
        scanf("%s", fila.dados[fila.fim].hora);
        fila.fim++;
    }
}

//Retirar o primeiro elemento da Fila
void fila_sair() {
    if (fila.ini == fila.fim) {
        printf("\nFila vazia, mas logo aparece alguém!\n\n");
        system("pause");
    } else {
        int i;
        for (i = 0; i < tamanho; i++) {
            strcpy(fila.dados[i].nome, fila.dados[i + 1].nome);
            strcpy(fila.dados[i].hora, fila.dados[i + 1].hora);
        }
        strcpy(fila.dados[fila.fim].nome, "");
        strcpy(fila.dados[fila.fim].hora, "");
        fila.fim--;
    }
}

//Mostrar o conteúdo da Fila
void fila_mostrar() {
    int i;
    printf("[\n");
    for (i = 0; i < tamanho; i++) {
        printf("Cliente %s ", fila.dados[i].nome);
        printf("chegou às %s horas\n", fila.dados[i].hora);
    }
    printf("]\n\n");
}

//Função principal com duas estruturas de repetição 
int main() {
	setlocale(LC_ALL,"");
    fila.ini = 0;
    fila.fim = 0;
    int opcao;

    do {
        printf("=== Gerenciamento de Fila ===\n");
        printf("1. Entrar na fila\n");
        printf("2. Sair da fila\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                fila_entrar();
                break;
            case 2:
                fila_sair();
                break;
            case 3:
                fila_mostrar();
                break;
            case 0:
                printf("Encerrando o programa. Até logo!\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}


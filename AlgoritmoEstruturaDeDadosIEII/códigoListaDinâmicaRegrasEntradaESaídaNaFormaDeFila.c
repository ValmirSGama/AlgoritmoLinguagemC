#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* O código implementa uma fila, onde a inserção ocorre no final e a remoção no início da fila,
também conhecida como "First-In First-Out" (FIFO).*/

// Definindo a estrutura da fila
typedef struct no {
    int dado;
    struct no* proximo;
} no;

// Definindo variáveis
typedef no* ptr_no;
ptr_no fila;
int op;

// Prototipação
void menu_mostrar();
void menu_selecionar(int op);
void fila_inserir(ptr_no* fila, int valor);  // Prototipação da função para inserir na fila
int fila_remover(ptr_no* fila);             // Prototipação da função para remover da fila
void fila_mostrar(ptr_no fila);			   //Prototipação da função para mostrar

// Função Principal
int main() {
    // Inicializando máquina de números randômicos
    srand(time(NULL));
    op = 1;
    
    // Criando o primeiro nó da fila
    fila = (ptr_no)malloc(sizeof(no));
    fila->dado = 0;
    fila->proximo = NULL;
    
    // Laço principal
    while (op != 0) {
        system("cls");
        menu_mostrar();
        scanf("%d", &op);
        menu_selecionar(op);
    }
    system("Pause");
    return 0;
}

// Mostra o menu de opções
void menu_mostrar() {
    fila_mostrar(fila);
    printf("\n\nEscolha uma das opcoes:\n");
    printf("1 - Inserir no final da fila\n");
    printf("2 - Remover no inicio da fila\n");
    printf("0 - Sair\n\n");
}

// Implementação da função para selecionar a opção do menu
void menu_selecionar(int op) {
    int valor;
    switch (op) {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            fila_inserir(&fila, valor);
            break;
        case 2:
            valor = fila_remover(&fila);
            if (valor != -1) {
                printf("Elemento removido: %d\n", valor);
            } else {
                printf("Fila vazia. Não é possível remover.\n");
            }
            break;
        case 0:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }
}


// Implementação da função para inserir na fila
void fila_inserir(ptr_no* fila, int valor) {
    ptr_no novo_no = (ptr_no)malloc(sizeof(no));
    novo_no->dado = valor;
    novo_no->proximo = NULL;
    
    if (*fila == NULL) {
        *fila = novo_no;
    } else {
        ptr_no temp = *fila;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo_no;
    }
}

// Implementação da função para remover da fila
int fila_remover(ptr_no* fila) {
    if (*fila == NULL) {
        return -1; // Fila vazia
    }
    
    int valor = (*fila)->dado;
    ptr_no temp = *fila;
    *fila = (*fila)->proximo;
    free(temp);
    
    return valor;
}

// Implementação da função para mostrar a fila
void fila_mostrar(ptr_no fila) {
    printf("Fila: ");
    
    ptr_no temp = fila;
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->proximo;
    }
    
    printf("\n");
}

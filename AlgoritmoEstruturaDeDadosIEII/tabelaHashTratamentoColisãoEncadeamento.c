#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Este é um exemplo simples de como implementar uma tabela hash para armazenar e recuperar 
valores associados a chaves*/

#define TABLE_SIZE 100

// Estrutura para cada nó da tabela hash
typedef struct Node {
    char key[50];
    int value;
    struct Node* next;
} Node;

// Função de hash simples
unsigned int hash(const char* key) {
    unsigned int hash_value = 0;
    int i = 0;

    while (key[i] != '\0') {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % TABLE_SIZE;
        i++;
    }

    return hash_value;
}

// Função para inserir um elemento na tabela hash
void insert(Node* table[], const char* key, int value) {
    unsigned int index = hash(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Função para pesquisar um elemento na tabela hash
int search(Node* table[], const char* key) {
    unsigned int index = hash(key);

    if (table[index] == NULL) {
        return -1;  // Valor não encontrado
    } else {
        Node* current = table[index];
        while (current != NULL) {
            if (strcmp(current->key, key) == 0) {
                return current->value;  // Valor encontrado
            }
            current = current->next;
        }
        return -1;  // Valor não encontrado
    }
}

int main() {
    Node* table[TABLE_SIZE];
    memset(table, 0, sizeof(Node*) * TABLE_SIZE);  // Inicializa a tabela com NULL

    // Exemplo de uso
    insert(table, "chave1", 10);
    insert(table, "chave2", 20);
    insert(table, "chave3", 30);

    int value = search(table, "chave2");
    if (value != -1) {
        printf("Valor encontrado: %d\n", value);
    } else {
        printf("Valor não encontrado.\n");
    }

    return 0;
}
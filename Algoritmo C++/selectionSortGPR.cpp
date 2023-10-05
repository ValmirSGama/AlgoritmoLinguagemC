#include <iostream>

/*O programa demonstra a ordenação de um vetor usando o algoritmo Selection Sort e exibe o vetor antes 
e depois da ordenação*/

// Função para ordenar o vetor usando o algoritmo Selection Sort
void selectionSort(int vec[], int tam) {
    int i, j, min, tmp;
    for (i = 0; i < (tam - 1); i++) {
        min = i;
        for (j = (i + 1); j < tam; j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }
        if (i != min) {
            // Troca os elementos vec[i] e vec[min]
            tmp = vec[i];
            vec[i] = vec[min];
            vec[min] = tmp;
        }
    }
}

int main() {
    int vec[] = {5, 2, 9, 1, 3};
    int tam = sizeof(vec) / sizeof(vec[0]);

    std::cout << "Array antes da ordenação: ";
    for (int i = 0; i < tam; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    // Chama a função de ordenação Selection Sort
    selectionSort(vec, tam);

    std::cout << "Array após a ordenação: ";
    for (int i = 0; i < tam; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

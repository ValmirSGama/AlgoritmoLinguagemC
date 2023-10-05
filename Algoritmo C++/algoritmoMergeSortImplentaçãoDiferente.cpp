#include <iostream>
#include <locale.h>

/*Este código implementa o algoritmo Merge Sort. Ele inclui a função 
`mergeSort()` para realizar a ordenação do array e a função `merge()` para 
mesclar os subarrays ordenados.*/

// Função auxiliar para mesclar dois subarrays ordenados
void merge(int vec[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Criar arrays temporários
    int L[n1], R[n2];

    // Copiar dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++)
        L[i] = vec[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = vec[meio + 1 + j];

    // Mesclar os arrays temporários de volta em vec[]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = inicio; // Índice inicial do subarray mesclado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver algum
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver algum
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

// Função principal para realizar o Merge Sort
void mergeSort(int vec[], int inicio, int fim) {
    if (inicio < fim) {
        // Encontrar o ponto médio do array
        int meio = inicio + (fim - inicio) / 2;

        // Chamada recursiva para a primeira metade do array
        mergeSort(vec, inicio, meio);

        // Chamada recursiva para a segunda metade do array
        mergeSort(vec, meio + 1, fim);

        // Mesclar as duas metades ordenadas
        merge(vec, inicio, meio, fim);
    }
}

int main() {
	setlocale(LC_ALL,"");
    int tamanho;
    //std::cout << "Digite o tamanho do array: ";
    //std::cin >> tamanho;
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];
    //std::cout << "Digite os elementos do array:\n";
    printf("Digite os elementos do array:\n");
    for (int i = 0; i < tamanho; i++)
        //std::cin >> vetor[i];
        scanf("%d", &vetor[i]);

    // Chamada da função mergeSort para ordenar o array
    mergeSort(vetor, 0, tamanho - 1);

    //std::cout << "Array ordenado:\n";
    printf("Array ordenado: ");
    for (int i = 0; i < tamanho; i++)
        //std::cout << vetor[i] << " ";
        printf("%d ", vetor[i]);

    return 0;
}

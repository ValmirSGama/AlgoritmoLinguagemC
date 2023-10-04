#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/*Este código implementa o algoritmo de ordenação Merge Sort e contabiliza a quantidade de iterações 
realizadas durante a ordenação. O Merge Sort é um algoritmo de ordenação eficiente e estável, que 
possui uma complexidade de tempo de O(n log n), tornando-o um dos mais rápido*/ 

#define tamanho 10

// Protótipos das funções
void menu_mostrar(void);  // Protótipo da função que exibe o menu de opções
void lista_mostrar(int[]); // Protótipo da função que mostra o conteúdo da lista
void lista_gerar(int[]); // Protótipo da função que gera uma lista aleatória
void lista_ler(int[]); // Protótipo da função que permite ao usuário inserir valores manualmente na lista
void lista_limpar(int[], int[]);  // Protótipo da função que copia os valores da lista original para a lista a ser ordenada
void lista_mostrar_ordenado(int[], int); // Protótipo da função que mostra o conteúdo da lista ordenada e exibe o número de iterações
int mergeSort(int[], int, int); // Protótipo da função que implementa o algoritmo Merge Sort para ordenar a lista
void junta(int[], int); // Protótipo da função que junta os pedaços da lista em um novo vetor ordenado

// Aplica o modo mergeSort
int mergeSort(int vec[], int tam, int qtd) {
    int meio;
    if (tam > 1) {
        meio = tam / 2;
        qtd = mergeSort(vec, meio, qtd);
        qtd = mergeSort(vec + meio, tam - meio, qtd);
        junta(vec, tam);
    }
    return (qtd + 1);
}

// Junta os pedaços num novo vetor ordenado
// Recebe um vetor 'vec', o tamanho do vetor 'tam' e a contagem de iterações 'qtd'
void junta(int vec[], int tam) {
    int i, j, k;
    int meio;
    int* tmp;
    tmp = (int*) malloc(tam * sizeof(int)); // Aloca memória temporária 'tmp' para armazenar a combinação
    if (tmp == NULL) { // Verifica se a alocação de memória foi bem-sucedida
        exit(1); // Encerra o programa com código de erro 1 em caso de falha na alocação
    }
    // Calcula o ponto médio do vetor
    meio = tam / 2;
    i = 0;
    j = meio;
    k = 0;
    // Combina as duas metades ordenadas
    while (i < meio && j < tam) {
        if (vec[i] < vec[j]) {
            tmp[k] = vec[i];
            ++i;
        } else {
            tmp[k] = vec[j];
            ++j;
        }
        ++k;
    }
    // Verifica se uma das metades ainda possui elementos não combinados
    if (i == meio) {
        while (j < tam) {
            tmp[k] = vec[j];
            ++j;
            ++k;
        }
    } else {
        while (i < meio) {
            tmp[k] = vec[i];
            ++i;
            ++k;
        }
    }
    // Copia os elementos combinados de volta para o vetor original
    for (i = 0; i < tam; ++i) {
        vec[i] = tmp[i];
    }
    free(tmp); // Libera a memória temporária alocada
}

// Mostra o menu
void menu_mostrar(void) {
    printf("1 - Gerar lista aleatoriamente\n"); // Adiciona a opção para gerar lista aleatoriamente
    printf("2 - Criar lista manualmente\n"); // Adiciona a opção para criar lista manualmente
    printf("3 - MergeSort ordena lista\n"); // Adiciona a opção para ordenar usando o Merge Sort
    printf("0 - Sair...\n\n");
}

// Mostra o conteúdo da lista
// Recebe um vetor 'vec' como entrada e imprime seus elementos na tela
void lista_mostrar(int vec[]) {
    printf("[ ");	// Imprime o início da representação do vetor
    for (int i = 0; i < tamanho; i++) {	// Loop para iterar através dos elementos do vetor
        printf("%d ", vec[i]);	// Imprime o elemento atual do vetor, seguido de um espaço
    }
    printf("]\n\n");	// Imprime o fim da representação do vetor e uma quebra de linha
}

// Gera uma lista aleatória
// Recebe um vetor 'vec' como entrada e preenche cada elemento com um valor aleatório entre 0 e 49
void lista_gerar(int vec[]) {
    for (int i = 0; i < tamanho; i++) {	// Loop para percorrer todos os elementos do vetor
        vec[i] = rand() % 50;	// Atribui um valor aleatório entre 0 e 49 ao elemento atual do vetor
    }
}

// Permite que o usuário entre com os valores da lista
// Recebe um vetor 'vec' como entrada e permite que o usuário insira valores para cada elemento do vetor
void lista_ler(int vec[]) {
    for (int i = 0; i < tamanho; i++) {	// Loop para percorrer todos os elementos do vetor
        system("cls");	// Limpa a tela do console para uma apresentação mais limpa
        lista_mostrar(vec);	// Chama a função para mostrar o conteúdo atual do vetor
        printf("\nDigite o valor para a posicao %d: ", i);	// Solicita ao usuário que insira um valor para a posição atual
        scanf("%d", &vec[i]);	// Lê o valor inserido pelo usuário e o armazena no elemento atual do vetor
    }
}

// Prepara a lista para ordenação
// Recebe dois vetores como entrada, 'vec1' e 'vec2', e copia os elementos de 'vec1' para 'vec2'
void lista_limpar(int vec1[], int vec2[]) {	
    for (int i = 0; i < tamanho; i++) {	// Loop para percorrer todos os elementos dos vetores
        vec2[i] = vec1[i]; // Copia o elemento atual de 'vec1' para 'vec2'
   

 }
}

// Mostra o conteúdo da lista ordenada
// Recebe um vetor 'vec' e um valor 'qtd' que representa o número de iterações
void lista_mostrar_ordenado(int vec[], int qtd) {
    printf("[ ");	 // Imprime o início da representação do vetor
    for (int i = 0; i < tamanho; i++) {	 // Loop para percorrer todos os elementos do vetor
        printf("%d ", vec[i]);	// Imprime o elemento atual do vetor
    }
    printf("] Tempo = %d iterações\n\n", qtd);	// Imprime o número de iterações realizadas
}

// Função Principal
int main(void) {
    setlocale(LC_ALL,"");	// Configura a localização para lidar com caracteres acentuados
    srand(time(NULL));	// Inicializa a semente do gerador de números aleatórios

    int lista[tamanho];	// Declaração de um vetor chamado 'lista'
    int ordenado[tamanho];	// Declaração de outro vetor chamado 'ordenado'
    int opt = -1;	// Declaração de uma variável para a opção do menu
    int qtd = 0;	// Declaração de uma variável para contar o número de iterações

    do {	// Início de um loop do-while para exibir o menu e processar opções
        system("cls");	// Limpa a tela
        lista_mostrar(lista);	// Chama a função para exibir a lista não ordenada
        lista_mostrar_ordenado(ordenado, qtd);	// Chama a função para exibir a lista ordenada
        menu_mostrar();	// Chama a função para exibir o menu de opções
        scanf("%d", &opt);	// Lê a opção escolhida pelo usuário
        
        switch (opt) {	// Início de uma estrutura de seleção switch para processar a opção
            case 1:	// Caso a opção seja 1:
                lista_gerar(lista);	// Chama a função para gerar uma lista aleatória
                break;
            case 2:	// Caso a opção seja 2:
                lista_ler(lista);	// Chama a função para permitir que o usuário insira valores na lista
                break;
            case 3: // Caso a opção seja 3:
                lista_limpar(lista, ordenado);	// Chama a função para preparar a lista para ordenação
                qtd = mergeSort(ordenado, tamanho, qtd);	// Chama a função de ordenação e armazena o número de iterações
                break;
        }
    } while (opt != 0);	// O loop continua até que o usuário escolha a opção 0 (sair)
    
    system("pause");	// Pausa a execução para que o usuário possa ver os resultados antes de encerrar o programa
    return 0;	// Retorna 0 para indicar que o programa foi encerrado com sucesso
}
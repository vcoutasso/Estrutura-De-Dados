/*
 * Escreva um programa para resolver o problema das n-rainhas, onde em um tabuleiro de tamanho n x n nenhuma rainha possa atacar as outras, ou seja, duas rainhas não podem compartilhar fila, coluna ou diagonal.
 */

 // TODO: Verificar se tem alguma bobeira no codigo que esteja prejudicando o tempo de execução.
 // Para valores de n maiores de 100 em meus testes, o tempo de execução pode demorar muito.
 // Pode ser algum erro no código ou limitação de hardware. Mais provável que algum bug.

 // TODO: Estudar a necessidade da variavel MAX, visto que é um valor completamente arbitrário.
 // Quando o valor for muito baixo, provavelmente haverá repetições desnecessárias de configurações do tabuleiro.
 // Estudar possíveis alternativas.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Limite de tentativas por coluna antes de voltar para o passo anterior
#define MAX 2

void printArray(int **arr, int n) {
    int row = n;
    int col = n;

    for (row = 0; row < n; ++row) {
        for (col = 0; col < n; ++col)
            printf("%d ", arr[row][col]);
        printf("\n");
    }
    printf("\n");
}

int isTileFree(int **arr, int n, int row, int col) {
    int i, j;

    // Verifica se ja existe uma rainha em row
    for (i = 0; i < col; ++i) {
        // Se houver, posição invalida. Retorna 0
        if (arr[row][i] == 1)
            return 0;
    }

    // Verifica se ja existe uma rainha na mesma diagonal
    i = row;
    j = col;

    // Verifica primeiro acima
    do {
        if (arr[i][j] == 1)
            return 0;
        --i;
        --j;
    } while(i > -1 && j > -1);

    // Em seguida, verifica abaixo
    i = row;
    j = col;

    do {
        if (arr[i][j] == 1)
            return 0;
        ++i;
        --j;
    } while(i < n && j > -1);

    return 1;
}

// Função recursiva para encontrar a solução. arr representa o tabuleiro, n o tamanho (nxn) e col a coluna na qual o algoritmo tentará encontrar a solução
int findSolution(int **arr, int n, int col) {
    int tries = 0;
    int row;
    int count = 0;

    // Imprime estado atual do tabuleiro para acompanhar a solução
    //printArray(arr, n);

    // Se for a primeira posição, escolhe aleatoriamente uma row
    if (col == 0) {
        int rd = rand() % n;
        arr[rd][col] = 1;
        while (findSolution(arr, n, col + 1) == 0) {
            arr[rd][col] = -1;
            while (arr[rd][col] == -1)
                rd = rand() % n;
            arr[rd][col] = 1;
        }
        for (row = 0; row < n; ++row) {
            if (arr[row][col] == -1)
                arr[row][col] = 0;
        }
    }
        // Caso contrario, escolhe rows aleatorias até que encontre uma válida
        // Escolhe um valor aleatoriamente e verifica se é valido. Se não for, marca a posição como -1 para não continuar tentando as mesmas posições
    else {
        while (1) {

            // Se tiver tentado muitas vezes, volta um passo
            count++;
            if (count > MAX)
                return 0;

            printf("Tentativa %d da coluna %d\n", count, col);

            // TODO: Não chamar isTileFree() se a condição do if for verdadeira
            do {
                row = rand() % n;
                if (arr[row][col] != -1) {
                    arr[row][col] = -1;
                    ++tries;
                }
            } while (!isTileFree(arr, n, row, col) && tries < n);

        // Se tiver tentado todas as posições sem sucesso, retorna 0 para alterar a posição anterior. Caso contrário, continua resolvendo a partir da posição encontrada
        if (tries < n)
            arr[row][col] = 1;

            // Reseta a coluna e retorna 0
        else {
            for (row = 0; row < n; ++row)
                arr[row][col] = 0;
            return 0;
        }

        if (col < n - 1) {
             if (findSolution(arr, n, col + 1) == 1) {
                 for (row = 0; row < n; ++row) {
                     if (arr[row][col] == -1)
                         arr[row][col] = 0;
                 }
                 return 1;
             }
             // Reseta a coluna e procura outra posicao
             else {
                 for (row = 0; row < n; ++row)
                     arr[row][col] = 0;
                 tries = 0;
             }
        }
            // Se for a ultima coluna, retorna 1
        else {
            for (row = 0; row < n; ++row) {
                if (arr[row][col] == -1)
                    arr[row][col] = 0;
            }
            return 1;
        }
        }
    }
}

void nQueens(int n) {
    int **board = malloc(sizeof(int*) * n);
    int row, col;

    for (row = 0; row < n; ++row)
        board[row] = malloc(sizeof(int) * n);

    for (row = 0; row < n; ++row) {
        for (col = 0; col < n; ++col)
            board[row][col] = 0;
    }

    findSolution(board, n, 0);
    printf("\nSolucao encontrada: \n\n");

    printArray(board, n);

}

int main() {
    int n;

    srand(time(NULL));

    printf("Informe o valor de N para um tabuleiro NxN: ");
    scanf("%d", &n);

    if (n > 3)
        nQueens(n);
    else
        printf("No solution for n = %d\n", n);

    return 0;
}

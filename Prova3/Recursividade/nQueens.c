/*
 * Escreva um programa para resolver o problema das n-rainhas, onde em um tabuleiro de tamanho n x n nenhuma rainha possa atacar as outras, ou seja, duas rainhas não podem compartilhar fila, coluna ou diagonal.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void findSolution(int **arr, int n, int col) {
	// Se for a primeira posição, escolhe aleatoriamente uma row
	if (col == 0)
		arr[rand() % n][col] = 1;
	// Caso contrario, escolhe rows aleatorias até que encontre uma válida
	else {
		int row;
		do {
			row = rand() % n;
		} while(!isTileFree(arr, n, row, col));
		arr[row][col] = 1;
	}
	// Imprime estado atual do tabuleiro para acompanhar a solução
	printArray(arr, n);

	if (col < n - 1)
		findSolution(arr, n, col+1);
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
	printf("Um possivel arranjo de rainhas eh: \n\n\n");

	printArray(board, n);

}

int main() {
	int n;

	srand(time(NULL));

	printf("Informe o valor de N para um tabuleiro NxN: ");
	scanf("%d", &n);
	printf("\n");

	nQueens(n);

	return 0;
}

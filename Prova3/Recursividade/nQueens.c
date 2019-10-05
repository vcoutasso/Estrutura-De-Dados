/*
 * Escreva um programa para resolver o problema das n-rainhas, onde em um tabuleiro de tamanho n x n nenhuma rainha possa atacar as outras, ou seja, duas rainhas não podem compartilhar fila, coluna ou diagonal.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verbose = 0;

void printArray(int **arr, int n) {
	int row;
	int col;

	for (row = 0; row < n; ++row) {
		for (col = 0; col < n; ++col)
			printf("%d ", arr[row][col]);
		printf("\n");
	}
	printf("\n");
}

// Verifica se a posição indicada por row e col é uma posição válida (não está sendo atacada por outras rainhas)
int isPositionValid(int **arr, int n, int row, int col) {
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
	// Variavel para verificar quantas das possiveis rows foram tentativas sem sucesso de escolher a prox posição. Usado para retornar para a coluna anterior se falhar em todos os casos
	int tries = 0;
	int row = 0;
	int i = 0;

	while (1) {

		// Imprime estado atual do tabuleiro para acompanhar a solução. OBS: Tem impacto significativo na performance.
		if (verbose) {
			printf("Tentativa %d da coluna %d\n", tries, col);
			printArray(arr, n);
		}

		// Escolhe uma row aleatoriamente.
		// TODO: Restringir o numero de opções para apenas row validas (que ainda não foram selecionadas). Atualmente todo numero no intervalo de 0 a n é valido, podendo haver (potencialmente muitas) repetições desnecessárias.
		// OBS: Restringindo as possibilidades de valores para row, o numero de tentativas necessarias tambem diminui, aumentando ainda mais a performance. Porem, deve ser ajustada a condição do do while
		do {
			row = rand() % n;
			// Se nao tiver tentado com esse valor antes
			if (arr[row][col] != -1) {
				arr[row][col] = -1;
				++tries;
				if (isPositionValid(arr, n, row, col) == 1) {
					// Marca a posição valida encontrada
					arr[row][col] = 1;
					break; // Se achou uma posição válida
				}
			}
			else {
				// Se tiver tentado todas as posições sem sucesso, retorna 0 para alterar a posição anterior. Caso contrário, continua resolvendo a partir da posição encontrada
				if (tries == n) {
					for (i = 0; i < n; ++i)
						arr[i][col] = 0;

					return 0;
				}
			}
		} while (1);

		// Se nao for a ultima coluna
		if (col < n - 1) {
			// Se tiver sucesso em achar a proxima posicao, limpa as posicoes que ja foram tentadas nessa coluna e retorna 1 sinalizando outro sucesso
			if (findSolution(arr, n, col + 1) == 1) {
				for (i = 0; i < n; ++i) {
					if (arr[i][col] == -1)
						arr[i][col] = 0;
				}
				return 1;
			}
			// Marca a posição atual como invalida e procura outra posicao na proxima iteracao
			else {
				arr[row][col] = -1;
			}
		}
		// Se for a ultima coluna, retorna 1
		else {
			for (i = 0; i < n; ++i) {
				if (arr[i][col] == -1)
					arr[i][col] = 0;
			}
			return 1;
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

	for(row = 0; row < n; ++row)
		free(board[row]);

	free(board);

}

int main(int argc, char** argv) {
	int n;

	srand(time(NULL));

	if (argc == 1) {
		printf("Informe o valor de N para um tabuleiro NxN: ");
		scanf("%d", &n);
	}
	else
		n = strtol(argv[1], NULL, 10);

	if (n > 3)
		nQueens(n);
	else
		printf("Valor invalido!\n");

	return 0;
}

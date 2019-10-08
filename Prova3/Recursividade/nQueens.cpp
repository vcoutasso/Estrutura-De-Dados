/*
 * nQueens solver to find the first solution for a NxN board
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

typedef struct Queen Queen;

struct Queen {
	short row;
	short col;
};

// true if position is attacked and false otherwise
std::vector<bool> attackedPositions;
// holds the positions of all placed queens
std::vector<Queen> queens;

void updateAttackedPositions(short n) {
	std::vector<Queen>::iterator it;
	std::vector<bool>::iterator aux_it;

	// horizontal and vertical
	for (it = queens.begin(); it != queens.end(); ++it) {

		for (int i = 0; i < n; ++i) {
			attackedPositions[i * n + it->row] = true;
		}

		for (int i = 0; i < n; ++i) {
			attackedPositions[it->col * n + i] = true;
		}

		// TODO: implement diagonal
	}
}

int findSolution(short n, short col) {
	//short tentativas = 0;
	short row = 0;

	while (true) {
		do {
			// if isn't attacked;
			if (!attackedPositions[row])
				break;
			++row;

			// No valid position within this column with current queens placement. Return 1 step and keep trying
			if (row >= n)
				return 0;

		} while (true);

		queens.push_back(Queen{row, col});
		updateAttackedPositions(n);

		if (col < n - 1) {
			if (findSolution(n, col + 1))
				return 1;
			else {
				queens.pop_back();
				updateAttackedPositions(n);
			}
		}
		else
			return 1;
	}
}

void printBoard(short n) {
	char ch;
	for (int col = 0; col < n; ++col) {
		for (int rol = 0; rol < n; ++rol) {
			ch = attackedPositions[col * n + rol] ? '-' : 'Q';
			std::cout << ch << " ";
		}
		std::cout << std::endl;
	}
}

void nQueens(short n) {
	for (int i = 0; i < n * n; i++)
		attackedPositions.push_back(false);

	attackedPositions.push_back(true);

	findSolution(n, 0);

	printBoard(n);
}

int main(int argc, char **argv) {
	srand(time(nullptr));

	short n;

	if (argc < 2) {
		std::cout << "Informe o valor de N para um tabuleiro NxN: ";
		std::cin >> n;
	}
	else
		n = (short) strtol(argv[1], nullptr, 10);

	nQueens(n);

	return 0;
}

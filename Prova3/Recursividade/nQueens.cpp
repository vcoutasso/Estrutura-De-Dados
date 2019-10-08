/*
 * nQueens solver to find the first solution for a NxN board
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

typedef struct Queen Queen;

clock_t begin_time;
clock_t total_time = 0;

struct Queen {
	int row;
	int col;
};

// true if position is attacked and false otherwise
std::vector<bool> attackedPositions;
// holds the positions of all placed queens
std::vector<Queen> queens;

void updateAttackedPositions(int n) {
	clock_t time = std::clock();
	std::vector<Queen>::iterator it;

	int queenPosition;
	int i;

	// reset board
	for (i = 0; i < n * n; ++i)
		attackedPositions[i] = false;

	for (it = queens.begin(); it != queens.end(); ++it) {

		queenPosition = it->col * n + it->row;

		int col = it->col;
		int row = it->row;

		// same row
		for (i = 0; i < n; ++i)
			attackedPositions[n * i + row] = true;

		// same column
		for (i = 0; i < n; ++i)
			attackedPositions[col * n + i] = true;

		// diagonal
		for (i = 1; i < n; ++i) {
			if (queenPosition - i * (n + 1) > 0)
				attackedPositions[queenPosition - i * (n + 1)] = true;
			if (queenPosition + i * (n + 1) < n * n)
				attackedPositions[queenPosition + i * (n + 1)] = true;
		}

		while (col > 0 && row < n - 1) {
			++row;
			--col;
		}

		while (row >= 0 && col < n) {
			attackedPositions[col * n + row] = true;
			--row;
			++col;
		}

		attackedPositions[queenPosition] = false;
		total_time += time - std::clock();
	}
}

int findSolution(int n, int col) {
	//int tentativas = 0;
	std::vector<int> possiveisValores;

	for (int i = 0; i < n; ++i)
		possiveisValores.push_back(i);

	int row = 0;

	while (true) {
		do {
			// No valid position within this column with current queens placement. Return 1 step and keep trying
			if (possiveisValores.size() == 0)
				return 0;

			row = possiveisValores[rand() % possiveisValores.size()];

			// if isn't attacked;
			if (!attackedPositions[col * n + row])
				break;

			//possiveisValores.erase(std::remove(possiveisValores.begin(), possiveisValores.end(), row), possiveisValores.end());

			auto it = std::find(possiveisValores.begin(), possiveisValores.end(), row);
			if (it != possiveisValores.end())
				possiveisValores.erase(it);

		} while (true);

		queens.push_back(Queen{row, col});
		updateAttackedPositions(n);

		if (col < n - 1) {
			if (findSolution(n, col + 1))
				return 1;
			else {
				queens.pop_back();
				updateAttackedPositions(n);

			auto it = std::find(possiveisValores.begin(), possiveisValores.end(), row);
			if (it != possiveisValores.end())
				possiveisValores.erase(it);
			}
		}
		else
			return 1;
	}
}

void printBoard(int n) {
	char ch;
	for (int col = 0; col < n; ++col) {
		for (int row = 0; row < n; ++row) {
			ch = attackedPositions[col + n * row] ? '-' : 'Q';
			std::cout << ch << " ";
		}
		std::cout << std::endl;
	}
}

void nQueens(int n) {
	begin_time = std::clock();

	for (int i = 0; i < n * n; i++)
		attackedPositions.push_back(false);

	findSolution(n, 0);

	printBoard(n);
}

int main(int argc, char **argv) {
	srand(time(nullptr));

	int n;

	if (argc < 2) {
		std::cout << "Informe o valor de N para um tabuleiro NxN: ";
		std::cin >> n;
	}
	else
		n = (int) strtol(argv[1], nullptr, 10);

	if (n < 4)
		std::cout << "N deve ser maior que 4!" << std::endl;
	else
		nQueens(n);

	std::cout << "\nTotal time: " << float( std::clock() - begin_time) / CLOCKS_PER_SEC << "s" << std::endl;

	return 0;
}

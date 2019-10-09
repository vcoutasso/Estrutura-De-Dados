/*
 * nQueens solver to find the first solution for a NxN board
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

typedef struct Queen Queen;

clock_t begin_time;

struct Queen {
	int row;
	int col;
};

// holds the positions of all placed queens
std::vector<Queen> queens;

bool isSafe(int row, int col) {

	for (auto it = queens.begin(); it != queens.end(); ++it) {
		int queen_row = it->row;
		int queen_col = it->col;

		if (queen_row == row || queen_row - queen_col == row - col || queen_row + queen_col == row + col)
			return false;
	}

	return true;
}


int findSolution(int n, int col) {
	std::vector<int> possiblePositions;

	for (int i = 0; i < n; ++i) {
		possiblePositions.push_back(i);
	}

	int row = 0;
	int index;

	while (true) {
		do {
			// No valid position within this column with current queens placement. Return 1 step and keep trying
			if (possiblePositions.empty())
				return 0;

			index = rand() % possiblePositions.size();
			row = possiblePositions[index];

			// removes the positions because its value has already been stored
			std::swap(*(possiblePositions.begin() + index), possiblePositions.back());
			possiblePositions.pop_back();

			// if isn't attacked;
			if (isSafe(row, col))
				break;


		} while (true);

		queens.push_back(Queen{row, col});

		if (col < n - 1) {
			if (findSolution(n, col + 1))
				return 1;
			else
				queens.pop_back();
		}
		else
			return 1;
	}
}

void printBoard(int n) {
	char ch;
	for (int col = 0; col < n; ++col) {
		for (int row = 0; row < n; ++row) {
			ch = (queens.begin() + col)->row == row ? 'Q' : '-';
			std::cout << ch << " ";
		}
		std::cout << std::endl;
	}
}

void nQueens(int n) {
	// find solution for the first column. since its a recursive function, there's no need to call it for the remaining columns
	findSolution(n, 0);

	// print final board
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
	else {
		begin_time = std::clock();
		nQueens(n);
		std::cout << "\nSolution found in " << float(std::clock() - begin_time) / CLOCKS_PER_SEC << "s" << std::endl;
	}


	return 0;
}

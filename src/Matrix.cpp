#include "Matrix.h"

Matrix MX_new(unsigned int rows, unsigned int columns) {
	Matrix result(rows, std::vector<bool>(columns));
	return result;
}

void MX_setCell(Matrix& matrix, bool value, unsigned int x, unsigned int y) {
	matrix[x][y] = value;
}

void MX_invertRow(Matrix& matrix, unsigned int row, unsigned int c_size) {
	for (int i = 0; i < c_size; i++) {
		matrix[row][i] = matrix[row][i] ? false : true;
	}
}

void MX_invertColumn(Matrix& matrix, unsigned int column, unsigned int r_size) {
	for (int i = 0; i < r_size; i++) {
		matrix[i][column] = matrix[i][column] ? false : true;
	}
}

void MX_print(Matrix matrix, unsigned int r_size, unsigned int c_size) {
	for (int r = 0; r < r_size; r++) {
		for (int c = 0; c < c_size; c++) {
			std::cout << matrix[r][c] << '\t';
		}

		std::cout << std::endl;
	}
}

bool MX_check(Matrix matrix, bool goal, unsigned int r_size, unsigned int c_size) {
	for (int r = 0; r < r_size; r++) {
		for (int c = 0; c < c_size; c++) {
			if (matrix[r][c] != goal) {
				return false;
			}
		}
	}

	return true;
}

void MX_randomChange(Matrix& matrix, unsigned int r_size, unsigned int c_size) {
	int r = 0, c = 0;
	int coin = rand() % (1 - 0 + 1) + 0;

	if (coin) {
		r = rand() % ((r_size - 1) - 0 + 1) + 0;
		MX_invertRow(matrix, r, c_size);
		return;
	}

	c = rand() % ((c_size - 1) - 0 + 1) + 0;
	MX_invertColumn(matrix, c, r_size);
}

void MX_solve(Matrix matrix, unsigned int r_size, unsigned int c_size) {
	/*
	* here we could already do checks, but we won't because of "scientific purposes".
	*/

	MX_print(matrix, r_size, c_size);
	std::cout << std::endl << "____________________" << std::endl;

	while (!MX_check(matrix, false, r_size, c_size)) {
		MX_randomChange(matrix, r_size, c_size);
		MX_print(matrix, r_size, c_size);
		//Sleep(100);
		std::cout << std::endl << "____________________" << std::endl;
	}

	std::cout << "Problem solvable." << std::endl;
}

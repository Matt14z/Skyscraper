#include "Matrix.h"

Matrix MX_new(int rows, int columns) {
    if(rows <= 0  || columns <= 0)
    {
        std::cerr << "Invalid size. It must be positive!";
        exit(1);
    }

	Matrix result(rows, std::vector<bool>(columns));
	return result;
}

void MX_setCell(Matrix& matrix, bool value, int x, int y) {
    if(x < 0  || y < 0)
    {
        std::cerr << "Invalid coordinate. It must be positive!";
        exit(1);
    }

	matrix[x][y] = value;
}

void MX_invertRow(Matrix& matrix, int row, int c_size) {
    if(c_size <= 0 || row < 0)
    {
        std::cerr << "Invalid value. It must be positive!";
        exit(1);
    }

	for (int i = 0; i < c_size; i++) {
		matrix[row][i] = matrix[row][i] ? false : true;
	}
}

void MX_invertColumn(Matrix& matrix, int column, int r_size) {
    if(r_size <= 0 || column < 0)
    {
        std::cerr << "Invalid value. It must be positive!";
        exit(1);
    }

	for (int i = 0; i < r_size; i++) {
		matrix[i][column] = matrix[i][column] ? false : true;
	}
}

void MX_print(Matrix matrix, int r_size, int c_size) {
    if(r_size <= 0 || c_size <= 0)
    {
        std::cerr << "Invalid value. It must be positive!";
        exit(1);
    }

	for (int r = 0; r < r_size; r++) {
		for (int c = 0; c < c_size; c++) {
			std::cout << matrix[r][c] << '\t';
		}

		std::cout << std::endl;
	}
}

bool MX_check(Matrix matrix, bool goal, int r_size, int c_size) {
    if(r_size <= 0 || c_size <= 0)
    {
        std::cerr << "Invalid value. It must be positive!";
        exit(1);
    }

	for (int r = 0; r < r_size; r++) {
		for (int c = 0; c < c_size; c++) {
			if (matrix[r][c] != goal) {
				return false;
			}
		}
	}

	return true;
}

void MX_randomChange(Matrix& matrix, int r_size, int c_size) {
    if(r_size <= 0 || c_size <= 0)
    {
        std::cerr << "Invalid value. It must be positive!";
        exit(1);
    }

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

void MX_solve(Matrix matrix, int r_size, int c_size) {
    if(r_size <= 0 || c_size <= 0)
    {
        std::cerr << "Invalid value. It must be positive!";
        exit(1);
    }

	/*
	* here we could already do checks, but we won't because of "scientific purposes".
	*/

	MX_print(matrix, r_size, c_size);
	std::cout << std::endl << "____________________" << std::endl;

	while (!MX_check(matrix, false, r_size, c_size)) {
		MX_randomChange(matrix, r_size, c_size);
		MX_print(matrix, r_size, c_size);

#ifdef _WIN32
        Sleep(100);
#else
        usleep(100);
#endif
		std::cout << std::endl << "____________________" << std::endl;
	}

	std::cout << "Problem solvable." << std::endl;
}

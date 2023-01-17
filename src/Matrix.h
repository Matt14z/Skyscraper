#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

typedef std::vector<std::vector<bool>> Matrix;

Matrix MX_new(int rows, int columns);
void MX_setCell(Matrix& matrix, bool value, int x, int y);
void MX_invertRow(Matrix& matrix, int row, int c_size);
void MX_invertColumn(Matrix& matrix, int column, int r_size);
void MX_print(Matrix matrix, int r_size, int c_size);
bool MX_check(Matrix matrix, bool goal, int r_size, int c_size);
void MX_randomChange(Matrix& matrix, int r_size, int c_size);
void MX_solve(Matrix matrix, int r_size, int c_size);

#endif
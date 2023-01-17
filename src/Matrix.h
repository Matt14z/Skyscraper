#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

#include <Windows.h>

typedef std::vector<std::vector<bool>> Matrix;

Matrix MX_new(unsigned int rows, unsigned int columns);
void MX_setCell(Matrix& matrix, bool value, unsigned int x, unsigned int y);
void MX_invertRow(Matrix& matrix, unsigned int row, unsigned int c_size);
void MX_invertColumn(Matrix& matrix, unsigned int column, unsigned int r_size);
void MX_print(Matrix matrix, unsigned int r_size, unsigned int c_size);
bool MX_check(Matrix matrix, bool goal, unsigned int r_size, unsigned int c_size);
void MX_randomChange(Matrix& matrix, unsigned int r_size, unsigned int c_size);
void MX_solve(Matrix matrix, unsigned int r_size, unsigned int c_size);

#endif
#include "Matrix.h"

/*
* Example of possible cases:
* 
* -Chessboard pattern:
	Matrix test = MX_new(3, 3);
	MX_setCell(test, true, 0, 0);
	MX_setCell(test, true, 0, 2);
	MX_setCell(test, true, 1, 1);
	MX_setCell(test, true, 2, 0);
	MX_setCell(test, true, 2, 2);

  -Alternated full on/off columns/rows:
	Matrix test = MX_new(3, 3);
	MX_setCell(test, true, 0, 1);
	MX_setCell(test, true, 1, 1);
	MX_setCell(test, true, 2, 1);

  -1 dimension matrices:
	Matrix test = MX_new(1, 5);
*/

int main()
{
	srand(time(NULL));
	Matrix test = MX_new(3, 3);
	MX_setCell(test, true, 0, 1);
	MX_setCell(test, true, 1, 1);
	MX_setCell(test, true, 2, 1);

	MX_solve(test, 3, 3);

	return 0;
}

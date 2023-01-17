# Skyscraper
Code made to solve a the following problem:
One day the workers in a skyscraper forget to turn off all the lights and some are left on.
Noticing it, you try to the lights off, but the system is broken.
Turning off the lights of an office turn the lights in the same column/row at their invert.
Can you turn off all the lights? Can you describe a specific method?

SOLUTION: In some cases it is impossible to turn all lights off.
Some of the cases where the problem is solvable are:

-Chessboard pattern:
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

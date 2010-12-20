#include "Board.h"

Board::Board() {
}

Board::Board(btnSquare * ins) {
	orientation = 0;
	btns = ins;
	int oSetup[8][9] = {
		{ // north (standard)
			0, 1, 2,
			3, 4, 5,
			6, 7, 8},
		{ // north flip
			2, 1, 0,
			5, 4, 3,
			8, 7, 6},
		{ // east
			2, 5, 8,
			1, 4, 7,
			0, 3, 6
		},
		{ // east flip
			8, 5, 2,
			7, 4, 1,
			6, 3, 0
		},
		{ // west
			6, 3, 0,
			7, 4, 1,
			8, 5, 2
		},
		{ // west flip
			0, 3, 6,
			1, 4, 7,
			2, 5, 8
		},
		{ // south
			8, 7, 6,
			5, 4, 3,
			2, 1, 0
		},
		{ // south flip
			6, 7, 8,
			3, 4, 5,
			0, 1, 2 
		}};
	memcpy(orients, oSetup, sizeof(orients));
/*
	For educational purpose: The following code does exactly what the above
	memcpy call does. The memcpy code is much more efficient, however.

	for(int r = 0; r < 8; ++r) {
		for(int c = 0; c < 9; ++c) {
			orients[r][c] = oSetup[r][c];
		}
	}
*/
}

btnSquare * Board::get(int index) {
	return &btns[orients[orientation][index]];
}

bool Board::rotate() {
	++orientation;
	if(orientation == 8) {
		orientation = 0;
		return false;
	}
	return true;
}

void Board::reset() {
	for(int i = 0; i < 9; ++i) btns[i].unset();
}
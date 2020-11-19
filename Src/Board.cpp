#include "Board.h"

/**
 * The board, and all possible transformations in a game-legal sense.
 *
 * The transforms, when known, enable us to easily walk over the entire
 * space of a given move, through all possible configurations on the
 * game board.
 */
static const int order[][9] = {
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
	}
};

/**
 * We expect this to be exactly 8.
 */
static const int NUM_SECTORS = std::size(order);

Board::Board() {}

Board::Board(btnSquare * ins) {
	orientation = 0;
	btns = ins;
}

btnSquare * Board::get(int index) {
	return &btns[order[orientation][index]];
}

bool Board::rotate() {
	if(++orientation == NUM_SECTORS) {
		reorient();
		return false;
	}
	return true;
}

/**
 * MUST be called for
 * any rotators who
 * are not returning
 * to unity.
 */
void Board::reorient() {
	orientation = 0;
}

void Board::reset() {
	for(int i = NUM_SECTORS; i >= 0; --i) btns[i].unset();
}
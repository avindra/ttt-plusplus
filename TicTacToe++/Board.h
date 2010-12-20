#include "btnSquare.h"

class Board
{
public:
	// Data
	int orientation;
	btnSquare * btns;

	int orients[8][9];

	// Constructors
	Board();
	Board(btnSquare * in);

	// Methods
	bool rotate();
	void reset();
};
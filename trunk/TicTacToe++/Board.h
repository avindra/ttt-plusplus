#include "btnSquare.h"

class Board
{
public:
	int orientation;
	btnSquare * btns;

	Board();
	Board(btnSquare * in);
};
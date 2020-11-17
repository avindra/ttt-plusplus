#include "Game.h"

const int winPaths[8][3] = {
	{0, 1, 2},
	{3, 4, 5},
	{6, 7, 8},

	// vertical
	{0, 3, 6},
	{1, 4, 7},
	{2, 5, 8},

	// diagonal
	{0, 4, 8},
	{2, 4, 6}
};

int Game::checkWinner(Board* board) {
	int winRar = 0;
	for(int j = 7; j >= 0; --j) {
		int xCount = 0, oCount = 0;
		for(int i = 2; i >=0; --i) {
			btnSquare * temp = board->get(winPaths[j][i]);
			if(temp->isX())
			{
				if(++xCount == 3)
				{
					winRar = 1;
					break;
				} else if(oCount != 0) break;
			} else if(temp->isO())
			{
				if(++oCount==3)
				{
					winRar = 2;
					break;
				} else if(xCount != 0) break;
			}
		}
		if(winRar != 0) break;
	}

	return winRar;
}
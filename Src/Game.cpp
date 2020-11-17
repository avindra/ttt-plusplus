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

/**
 * Check if there is a winner.
 * 
 * Outcomes:
 *  0: No winner
 *  1: X is the winner
 *  2: O is the winner
 */
int Game::checkWinner(Board* board) {
	for(int j = 7; j >= 0; --j) {
		int xCount = 0, oCount = 0;
		for(int i = 2; i >=0; --i) {
			btnSquare * temp = board->get(winPaths[j][i]);
			if(temp->isX()) {
				if(++xCount == 3) {
					return 1;
				}
			} else if(temp->isO()) {
				if(++oCount==3) {
					return 2;
				}
			}
		}
	}

	return 0;
}
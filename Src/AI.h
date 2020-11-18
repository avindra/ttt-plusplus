#include "Board.h"

#include <QtWidgets/QLabel>

/**
 * Todo: decouple QT 100% from this code.
 */
class AI {
public:

	// todo: remove taunt
	static btnSquare* computerMove(Board* a, QLabel* taunt, bool imp, bool hard, bool norm);

private:

	static btnSquare * checkMoves(Board* a, int numChecks, int check[][3], bool checkX);

	/**
	 * Given a list of indices,
	 * randomly select one from that list.
	 */
	static btnSquare * pickMove(int length, int list[], Board* b);
};
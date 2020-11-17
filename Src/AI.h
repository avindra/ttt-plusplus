#include "Board.h"

#include <QtWidgets/QLabel>

/**
 * Todo: decouple QT 100% from this code.
 */
class AI {
public:
	// todo: remove taunt
	static btnSquare * checkMoves(QLabel* taunt, Board* a, int check[][3], bool checkX, int i);

	// todo: remove taunt
	static btnSquare* computerMove(Board* a, QLabel* taunt, bool imp, bool hard, bool norm);
};
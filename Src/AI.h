#include "Board.h"

enum Strategy {
	Win,
	Defend,
	Fork,
	BlockFork,
	Center,
	OpposingCorner,
	EmptyCorner,
	EmptySide,
	Random,
};

class AI {
public:

	/**
	 * Returns the outcome of a move,
	 * and the reason it was picked.
	 */
	static std::pair<btnSquare*, Strategy> computerMove(Board* a, bool imp, bool hard, bool norm);

private:

	static btnSquare * checkMoves(Board* a, int numChecks, int check[][3], bool checkX);

	/**
	 * Given a list of indices,
	 * randomly select one from that list.
	 */
	static btnSquare * pickMove(int length, int list[], Board* b);
};

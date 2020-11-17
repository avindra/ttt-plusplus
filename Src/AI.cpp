#include "AI.h"

/**
 * TODO: doc
 */
btnSquare* AI::checkMoves(QLabel* taunt, Board* board, int checks[][3], bool isX, int len)
{
	do
	{
		btnSquare * _temp;
		for (int i = len; i >= 0; --i)
		{
			_temp = (board->get(checks[i][0])->autoCheck(isX)
				 && board->get(checks[i][1])->autoCheck(isX)
				 && board->get(checks[i][2])->isEnabled())

				 ? board->get(checks[i][2])
				 : 0;
			if (_temp)
			{
				taunt->setText("Move calculated! " + QString::number(checks[i][0]) + " | " + QString::number(checks[i][1]) + " | " + QString::number(checks[i][2]));
				board->reorient();
				return _temp;
			}
		}
	} while (board->rotate());
	return 0;
}


/**
 * Logic for the computer's decision making
 * at all difficulty levels.
 * 
 * @see https://en.wikipedia.org/wiki/Tic-tac-toe#Strategy
 */
btnSquare* AI::computerMove(Board* board, QLabel* taunt, bool isImpossible, bool isHard, bool isNormal) {
	int criticalChecks[4][3] = {
		{0, 1, 2},
		/*
			O O ?
			_ _ _
			_ _ _
		*/
		{0, 2, 1},
		/*
			O ? O
			_ _ _
			_ _ _
		*/
		{0, 4, 8},
		/*
			O _ _
			_ O _
			_ _ ?
		*/
		// I excluded 804 / 084, because later on, the 
		// center would be picked anyway. Similar coding
		// strategy is used further down as well.
		{3, 4, 5}
		/*
			_ _ _
			O O ?
			_ _ _
		*/
	};
	btnSquare * temp;

	//win
	if (isHard || isImpossible || (isNormal && (qrand() % 2) >= 1))
	{
		if (temp = checkMoves(taunt, board, criticalChecks, false, 3)) {
			taunt->setText("I see an opportunity! You lose! Fear my awesome power!");
			return temp;
		}
	}
	//defend
	if (isHard || isImpossible || isNormal)
	{
		if (temp = checkMoves(taunt, board, criticalChecks, true, 3)) {
			taunt->setText("I block your dumb ass!");
			return temp;
		}
	}

	if(isImpossible)
	{
		//<-------------------------------------------------------------------------->
		//								   FORKING
		//<-------------------------------------------------------------------------->
		int forks[16][3] = {
 			//<--a-->
			{0, 2, 4},
			{0, 4, 2},
			{2, 4, 0},
			//<--b-->
			{4, 6, 7},
			{4, 7, 6},
			{7, 6, 4},
			//<--c-->
			{0, 1, 3},
			{0, 3, 1},
			{3, 1, 0},
			//<--d-->
			{0, 8, 6},
			{0, 6, 2},
			{0, 2, 6},
			{6, 2, 0},
			//<--e-->
			{1, 6, 7},
			{1, 7, 6},
			{6, 7, 1}
		};
		if (temp = checkMoves(taunt, board, forks, false, 15)) {
			taunt->setText("Muahahaha! Checkmate, bitch!");
			return temp;
		}
		//<-------------------------------------------------------------------------->
		//							BLOCK FORKING
		//<-------------------------------------------------------------------------->
		int bForks[15][3] = {
			//<--e-->
			{1, 6, 7},
			{1, 7, 6},
			{6, 7, 1},
			//<--f-->
			{0, 2, 5},
			{0, 5, 2},
			{5, 2, 0},
 			//<--a-->
			{0, 2, 4},
			{0, 4, 2},
			{2, 4, 0},
			//<--b-->
			{4, 6, 7},
			{4, 7, 6},
			{7, 6, 4},
			//<--c-->
			{0, 1, 3},
			{0, 3, 1},
			{3, 1, 0}
		};
		if (temp = checkMoves(taunt, board, bForks, true, 14)) {
			taunt->setText("I see what you did there... Blocked your fork, loser!");
			return temp;
		}
		//<--d-->
		bool defend = false;
		btnSquare * badbut;
		do
		{
			int tests[3][3] = {
				{0, 6, 2},
 				{0, 2, 6},
				{6, 2, 0}
			};
			for(int i = 2; i >= 0; --i) {
				int innerTest[3];
				memcpy(innerTest, tests[i], sizeof(innerTest));
				if (board->get(innerTest[0])->isX() && board->get(innerTest[1])->isX() && (board->get(innerTest[2])->isEnabled() || board->get(8)->isEnabled()))
				{
					defend = true;
					badbut = board->get(innerTest[2]);
				}
			}
			if (defend)
			{
				btnSquare * theMove = board->get(0);
				while (!theMove->isEnabled() || theMove == badbut || theMove == board->get(8))
				{
					theMove = board->get((qrand() % 7) + 1);
				}
				board->reorient();
				return theMove;
			}
		} while (board->rotate());
		//center
		if (board->get(4)->isEnabled())
			return board->get(4);
		//opposite corner
		int opposites[2][2] = {
			{0, 8},
			{3, 7}
		};
		for(int i = 1; i >= 0; --i) {
			int inner[2];
			memcpy(inner, opposites[i], sizeof(inner));

			temp = board->get(inner[1]);
			if (board->get(inner[0])->isX() && temp->isEnabled()) return temp;

			temp = board->get(inner[0]);
			if (board->get(inner[1])->isX() && temp->isEnabled()) return temp;
		}

		// TODO: If corners, and similarly sides, are all taken up, then
		// the code will result in an infinite loop.
		// 
		// This has never happened, which means the code below isn't even
		// being reached.

		//empty corner
		int corners[4] = {
			0,  2,

			6,  8
		};
		temp = board->get(corners[qrand() % 3]);
		while (!temp->isEnabled())
		{
			temp = board->get(corners[qrand() % 3]);
		}
		if (temp->isEnabled()) return temp;
		//empty side
		int sides[4] = {
			 1, 
		   3,  5,
		     7  
		};
		temp = board->get(sides[qrand() % 3]);
		while (!temp->isEnabled())
		{
			temp = board->get(sides[qrand() % 3]);
		}
		return temp;
	}

	// randomly play a remaining square
	// Theoretically, the code will never reach here.
	temp = board->get(qrand() % 8);
	while (!temp->isEnabled())
	{
		temp = board->get(qrand() % 8);
	}
	return temp;
}
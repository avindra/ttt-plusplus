#include "AI.h"

/**
 * Logic for the computer's decision making
 * at all difficulty levels.
 * 
 * @see https://en.wikipedia.org/wiki/Tic-tac-toe#Strategy
 */
btnSquare* AI::computerMove(bool isImpossible, bool isHard, bool isNormal) {
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
		if (temp = checkMoves(criticalChecks, false, 3)) {
			taunt->setText("I see an opportunity! You lose! Fear my awesome power!");
			return temp;
		}
	}
	//defend
	if (isHard || isImpossible || isNormal)
	{
		if (temp = checkMoves(criticalChecks, true, 3)) {
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
		if (temp = checkMoves(forks, false, 15)) {
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
		if (temp = checkMoves(bForks, true, 14)) {
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
				if (gameBoard->get(innerTest[0])->isX() && gameBoard->get(innerTest[1])->isX() && (gameBoard->get(innerTest[2])->isEnabled() || gameBoard->get(8)->isEnabled()))
				{
					defend = true;
					badbut = gameBoard->get(innerTest[2]);
				}
			}
			if (defend)
			{
				btnSquare * theMove = gameBoard->get(0);
				while (!theMove->isEnabled() || theMove == badbut || theMove == gameBoard->get(8))
				{
					theMove = gameBoard->get((qrand() % 7) + 1);
				}
				gameBoard->reorient();
				return theMove;
			}
		} while (gameBoard->rotate());
		//center
		if (gameBoard->get(4)->isEnabled())
			return gameBoard->get(4);
		//opposite corner
		int opposites[2][2] = {
			{0, 8},
			{3, 7}
		};
		for(int i = 1; i >= 0; --i) {
			int inner[2];
			memcpy(inner, opposites[i], sizeof(inner));

			temp = gameBoard->get(inner[1]);
			if (gameBoard->get(inner[0])->isX() && temp->isEnabled()) return temp;

			temp = gameBoard->get(inner[0]);
			if (gameBoard->get(inner[1])->isX() && temp->isEnabled()) return temp;
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
		temp = gameBoard->get(corners[qrand() % 3]);
		while (!temp->isEnabled())
		{
			temp = gameBoard->get(corners[qrand() % 3]);
		}
		if (temp->isEnabled()) return temp;
		//empty side
		int sides[4] = {
			 1, 
		   3,  5,
		     7  
		};
		temp = gameBoard->get(sides[qrand() % 3]);
		while (!temp->isEnabled())
		{
			temp = gameBoard->get(sides[qrand() % 3]);
		}
		return temp;
	}

	// randomly play a remaining square
	// Theoretically, the code will never reach here.
	temp = gameBoard->get(qrand() % 8);
	while (!temp->isEnabled())
	{
		temp = gameBoard->get(qrand() % 8);
	}
	return temp;
}
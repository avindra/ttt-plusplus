#include "AI.h"

/**
 * Checks MUST contain at least one
 * path to check.
 */
btnSquare* AI::checkMoves(QLabel* taunt, Board* board, int checks[][3], bool isX)
{
	int len = sizeof(checks) / sizeof(checks[0]);
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

	board->reorient();
	return 0;
}

/**
 * From a list of possible plays,
 * randomly select an available
 * one.
 */
btnSquare* AI::pickMove(int _list[], Board* board) {
	std::vector<int> vc_list(_list, _list + sizeof _list / sizeof _list [0]);
	std::vector<int> vc_out;

	// C++ .filter https://stackoverflow.com/a/21204788/270302
	std::copy_if (
		vc_list.begin(), vc_list.end(),
		std::back_inserter(vc_out),
		[&board](int i){
			btnSquare* btn = board->get(i);
			return btn->isEnabled();
		}
	);

	int* list = vc_out.data();

	int length = sizeof(list) / list[0];
	// no possible moves left.
	if (length == 0) {
		return nullptr;
	} else if (length == 1) {
		return board->get(list[0]);
	}

	// randomly pick available one from the list
	int operand = length - 1;
	int idx = rand() % operand;
	return board->get(list[idx]);
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

	// generic reference to a button which can
	// possibly be selected as the computer's move
	btnSquare * play;

	//win
	if (isHard || isImpossible || (isNormal && (rand() % 2) >= 1))
	{
		if ((play = checkMoves(taunt, board, criticalChecks, false))) {
			taunt->setText("Well played! Better luck next time :)");
			return play;
		}
	}
	//defend
	if (isHard || isImpossible || isNormal)
	{
		if ((play = checkMoves(taunt, board, criticalChecks, true))) {
			taunt->setText("Not so fast!!");
			return play;
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
		if ((play = checkMoves(taunt, board, forks, false))) {
			taunt->setText("Now there are two ;)");
			return play;
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
		if ((play = checkMoves(taunt, board, bForks, true))) {
			taunt->setText("There can only be one");
			return play;
		}

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
					theMove = board->get((rand() % 7) + 1);
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

			play = board->get(inner[1]);
			if (board->get(inner[0])->isX() && play->isEnabled()) return play;

			play = board->get(inner[0]);
			if (board->get(inner[1])->isX() && play->isEnabled()) return play;
		}

		//empty corner
		int corners[4] = {
			0,  2,

			6,  8
		};
		play = pickMove(corners, board);

		if (play && play->isEnabled()) return play;

		//empty side
		int sides[4] = {
			 1, 
		   3,  5,
		     7  
		};
		play = pickMove(sides, board);
		if (play && play->isEnabled()) return play;
	}


	// randomly play any remaining square.
	// Theoretically, the code should never get here.
	int entireBoard[9] = {0,1,2,3,4,5,6,7,8};
	return pickMove(entireBoard, board);
}
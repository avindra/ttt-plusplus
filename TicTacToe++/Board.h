#include "btnSquare.h"

class Board
{
public:
	/*
	 *	Data
	 */

	// The current orientation (0-7) of the game board.
	int orientation;

	// The array of buttons on the board.
	btnSquare * btns;

	// The following is a matrix of all the possible board orientations.
	//	The purpose is that we can check a single possibility, and automatically
	//	rotate through the other possibilities instead of typing out 
	//	each and every possibility, which would take forever and would lead to 
	//	unnecessarily complex code.
	int orients[8][9];

	/*
	 * Constructors
	 */
	
	// The default constructor, which should never be used.
	// Only here because C++ requires it.
	Board();
	// The constructor, accepting the array of buttons.
	Board(btnSquare * in);

	/*
	 * Methods
	 */

	// Gets the square with respect to the current orientation.
	// Looks incredibly simple and useless, but compared with older
	// revisions, this helps save tons of code and heavily increases
	// the performance of this app.
	btnSquare * get(int index);

	// Changes the board to the next orientation.
	// 
	// Returns "false" when the board has been iterated through
	// all of it's orientations.
	// 
	// It's important to use a do while() with this, and not a for / while,
	// since this function will change to the next orientation
	// before returning whether the end was reached or not.
	bool rotate();

	void reorient();

	// Reset the board to the standard position.
	void reset();
};
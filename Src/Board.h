#pragma once

#include "btnSquare.h"

class Board
{
public:
	// DATA

	// The current orientation (0-7) of the game board.
	int orientation;

	// The array of buttons on the board.
	btnSquare * btns;
	// CONSTRUCTORS
	
	// The default constructor, which should never be used.
	// Only here because C++ requires it.
	Board();
	// The constructor, accepting the array of buttons.
	Board(btnSquare * in);

	/*
	 * Methods
	 */

	/**
	 * Get square with respect to the current orientation.
	 */
	btnSquare * get(int index);

	/**
	 * Cycle board to the next orientation.
	 *
	 * Returns "false" when the board has returned to unity.
	 *
	 * do while() loops pair well with this (avoid for / while),
	 * because invoking this function changes the orientation.
	 */
	bool rotate();

	void reorient();

	// Reset the board to the standard position.
	void reset();
};
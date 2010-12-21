#ifndef WINMAIN_H
#define WINMAIN_H

#include <QtGui/QMainWindow>
#include "ui_winmain.h"
#include "Board.h"
// Don't include "btnSquare.h", it's included in Board.h


class winMain : public QMainWindow
{
	Q_OBJECT
	public:
		// Game keeping essentials
		Board * gameBoard;
		bool xHasTurn;

		bool computer;

		/*
		 * Controls we need to find.
		 */
		QRadioButton *radEasy, *radNormal, * radHard, * radImp;
		QLabel * whoseTurn;

		// Construct / destruct
		winMain(QWidget *parent = 0, Qt::WFlags flags = 0);
		~winMain();

		// Returns whether or not there's a winner.
		bool winner();


		void pressButton(btnSquare * which);

		/// <summary>
		/// This function heavily improves program flow by 
		/// checking the moves from a single function, instead
		/// of just repeating a lot of code.
		/// </summary>
		/// <param name="checks">The array of checks.</param>
		/// <param name="isX">Tell the function whether to verify against X (true) or O (false).</param>
		/// <returns></returns>
		btnSquare * checkMoves(int check[4][3], bool checkX);
		btnSquare * computerMove();

	public slots:
		// Event handlers
		void newGame();
		void aboutGame();
		void btnPressed();

	private:
		Ui::winMainClass ui;
};

#endif // WINMAIN_H

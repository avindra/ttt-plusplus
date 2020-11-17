#ifndef WINMAIN_H
#define WINMAIN_H

#include <QtWidgets/QMainWindow>
#include "ui_winmain.h"
#include "Board.h"

class winMain : public QMainWindow
{
	Q_OBJECT
	public:
		// Game keeping essentials
		Board * gameBoard;
		bool xHasTurn;

		/*
		 * Controls we need to find.
		 */
		QRadioButton *radEasy, *radNormal, * radHard, * radImp, * radComputer;
		QLabel * whoseTurn, * taunt;

		// Construct / destruct
		winMain(QWidget *parent = 0, Qt::WindowFlags flags = 0);
		~winMain();

		// Returns whether or not there's a winner.
		bool winner(bool isComp);

		void pressButton(btnSquare * which);

		virtual void keyPressEvent(QKeyEvent * e);

	public slots:
		// Event handlers
		void newGame();
		void aboutGame();
		void aboutQt();
		void btnPressed();

	private:
		Ui::winMainClass ui;
};

#endif // WINMAIN_H

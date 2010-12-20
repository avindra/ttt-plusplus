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

		QLabel * whoseTurn;

		// Construct / destruct
		winMain(QWidget *parent = 0, Qt::WFlags flags = 0);
		~winMain();

	public slots:
		// Event handlers
		void newGame();
		void aboutGame();
		void btnPressed();

	private:
		Ui::winMainClass ui;
};

#endif // WINMAIN_H

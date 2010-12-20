#ifndef WINMAIN_H
#define WINMAIN_H

#include <QtGui/QMainWindow>
#include "ui_winmain.h"
#include "btnSquare.h"

class winMain : public QMainWindow
{
	Q_OBJECT
	public:

		bool xHasTurn;

		// Construct / destruct
		winMain(QWidget *parent = 0, Qt::WFlags flags = 0);
		~winMain();
	public slots:
		void newGame();
		void aboutGame();
		void btnPressed();

	private:
		Ui::winMainClass ui;
};

#endif // WINMAIN_H

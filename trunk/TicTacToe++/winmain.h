#ifndef WINMAIN_H
#define WINMAIN_H

#include <QtGui/QMainWindow>
#include "ui_winmain.h"

class winMain : public QMainWindow
{
	Q_OBJECT
	public:
		// Construct / destruct
		winMain(QWidget *parent = 0, Qt::WFlags flags = 0);
		~winMain();
	public slots:
		void aboutGame();
		void btnPressed();

	private:
		Ui::winMainClass ui;
};

#endif // WINMAIN_H
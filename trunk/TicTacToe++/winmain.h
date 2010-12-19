#ifndef WINMAIN_H
#define WINMAIN_H

#include <QtGui/QMainWindow>
#include "ui_winmain.h"

class winMain : public QMainWindow
{
	Q_OBJECT

public:
	winMain(QWidget *parent = 0, Qt::WFlags flags = 0);
	~winMain();

private:
	Ui::winMainClass ui;
};

#endif // WINMAIN_H

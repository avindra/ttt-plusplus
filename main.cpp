#include "winmain.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	winMain w;
	w.show();
	return a.exec();
}

#include "winmain.h"

winMain::winMain(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QGridLayout * grid = findChild<QGridLayout *>("grdGame");
	for(int r = 0; r < 3; ++r) {
		for(int c = 0; c < 3; ++c) {
			QPushButton  * btn = new QPushButton();
			btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
			grid->addWidget(btn, r, c);
		}
	}
}

winMain::~winMain()
{

}

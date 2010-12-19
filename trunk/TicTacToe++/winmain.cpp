#include "winmain.h"
#include <QMessageBox>

winMain::winMain(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	// Find the main "grdGame" as "grid"
	QGridLayout * grid = findChild<QGridLayout *>("grdGame");

	// Connect the exit button in the main menu to the quit function.
	QAction * mnuExit = findChild<QAction*>("mnuExit");
	connect(mnuExit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));


	// Connect the about button in the help menu to the function
	QAction * about = findChild<QAction*>("mnuAbout");
	connect(about, SIGNAL(triggered(bool)), qApp, SLOT(aboutGame()));


	// Connect the exit button in the main form to the quit function.
	QPushButton * exit = findChild<QPushButton*>("btnExit");
	connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));

	// Set up the board
	for(int r = 0; r < 3; ++r) {
		for(int c = 0; c < 3; ++c) {
			QPushButton  * btn = new QPushButton();

			// Set button to fill it's allotted space
			btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

			// Connect the button to the event
		//	connect(btn, SIGNAL(clicked()), qApp, SLOT(winMain::btnClicked()));

			// Add it to the board
			grid->addWidget(btn, r, c);
		}
	}
}

void winMain::aboutGame() {
	QMessageBox::about(this, "About this game", "<h1>Tic-Tac-Toe++</h1>");
}

winMain::~winMain()
{

}

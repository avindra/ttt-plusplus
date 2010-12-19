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
	connect(about, SIGNAL(triggered(bool)), this, SLOT(aboutGame()));


	// Connect the exit button in the main form to the quit function.
	QPushButton * exit = findChild<QPushButton*>("btnExit");
	connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));

	// Set up the board
	for(int r = 0; r < 3; ++r) {
		for(int c = 0; c < 3; ++c) {
			btnSquare  * btn = new btnSquare();

			// Connect the button to the event
			connect(btn, SIGNAL(clicked()), this, SLOT(btnPressed()));

			// Add it to the board
			grid->addWidget(btn, r, c);
		}
	}
}

void winMain::btnPressed() {
	QMessageBox::about(this, "Demo", "Button clicked!");
}

void winMain::aboutGame() {
	QMessageBox::about(this, "About this game", "<h1>Tic-Tac-Toe++</h1><p>This game was made mostly by Avindra Vishal Goolcharan. It is not licensed for commercial purposes, and is expressly restricted from such activity under <a href=\"http://creativecommons.org/licenses/by-nc-nd/3.0/\">Creative Commons (Attribution-Noncommercial-No Derivative Works) 3.0 Unported</a>.</p><p>For a history of this application and more, see the <a href=\"http://code.google.com/p/ttt-plusplus/\">project's homepage</a> on Google Code.</p>");
}

winMain::~winMain()
{

}
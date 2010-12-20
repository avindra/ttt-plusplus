#include "winmain.h"
#include <QMessageBox>

winMain::winMain(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	xHasTurn = true;
	ui.setupUi(this);

	// Find the whose Turn label
	whoseTurn = findChild<QLabel *>("lblTurn");

	// Find the main "grdGame" as "grid"
	QGridLayout * grid = findChild<QGridLayout *>("grdGame");

	// Connect the exit button in the main menu to the quit function.
	QAction * mnuExit = findChild<QAction*>("mnuExit");
	connect(mnuExit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));


	// Connect the about button in the help menu to the function
	QAction * about = findChild<QAction*>("mnuAbout");
	connect(about, SIGNAL(triggered(bool)), this, SLOT(aboutGame()));

	// Connect the new button in the file menu to the function
	QAction * mnunew = findChild<QAction*>("mnuNewGame");
	connect(mnunew, SIGNAL(triggered(bool)), this, SLOT(newGame()));

	// Connect the exit button in the main form to the quit function.
	QPushButton * exit = findChild<QPushButton*>("btnExit");
	connect(exit, SIGNAL(clicked()), qApp, SLOT(quit()));

	// Connect the new game button to the new game function.
	QPushButton * ng = findChild<QPushButton*>("btnNew");
	connect(ng, SIGNAL(clicked()), this, SLOT(newGame()));

	// Set up the board
	btnSquare* chainIn = new btnSquare[9];
	int i = -1;
	for(int r = 0; r < 3; ++r) {
		for(int c = 0; c < 3; ++c) {
			btnSquare * btn = &chainIn[++i];

			// Connect the button to the event
			connect(btn, SIGNAL(clicked()), this, SLOT(btnPressed()));

			// Add it to the board
			grid->addWidget(btn, r, c);
		}
	}
	gameBoard = new Board(chainIn);
#ifdef DEBUG
	// We're just checking to verify if the
	// board's orientations were properly set up here.
	QString out = "Orient:\t";
	for(int r = 0; r < 8; ++r) {
		for(int c = 0; c < 8; ++c) {
			out += QString::number(gameBoard->orients[r][c]) + " ";
		}
		if(r != 7) out += "\nOrient:\t";
	}
	QMessageBox::about(this, "Board Debug: Orientation setup", out);
#endif
}

void winMain::newGame() {
	gameBoard->reset();
	whoseTurn->setText("X");
	xHasTurn = true;
}

void winMain::btnPressed() {
	btnSquare* btnPressed = (btnSquare * ) sender();
	if(xHasTurn) {
		btnPressed->setX();
		whoseTurn->setText("O");
	} else {
		btnPressed->setO();
		whoseTurn->setText("X");
	}
	xHasTurn = !xHasTurn;
}

void winMain::aboutGame() {
	QMessageBox::about(this, "About this game", "<h1>Tic-Tac-Toe++</h1><p>This game was made mostly by Avindra Vishal Goolcharan. It is not licensed for commercial purposes, and is expressly restricted from such activity under <a href=\"http://creativecommons.org/licenses/by-nc-nd/3.0/\">Creative Commons (Attribution-Noncommercial-No Derivative Works) 3.0 Unported</a>.</p><p>For a history of this application and more, see the <a href=\"http://code.google.com/p/ttt-plusplus/\">project's homepage</a> on Google Code.</p>");
}

winMain::~winMain()
{

}
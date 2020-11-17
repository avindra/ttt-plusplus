#include "winmain.h"
#include <QMessageBox>
#include <QKeyEvent>

#include "AI.h"
#include "Game.h"

winMain::winMain(QWidget *parent, Qt::WindowFlags flags)
	: QMainWindow(parent, flags)
{
	xHasTurn = true;
	ui.setupUi(this);

	// get Rads
	radEasy = findChild<QRadioButton*>("radEasy");
	radNormal = findChild<QRadioButton*>("radNormal");
	radHard = findChild<QRadioButton*>("radHard");
	radImp = findChild<QRadioButton*>("radImp");
	radComputer = findChild<QRadioButton*>("radComputer");

	// Find labels
	whoseTurn = findChild<QLabel *>("lblTurn");
	taunt = findChild<QLabel *>("lblTaunt");

	// Find the main "grdGame" as "grid"
	QGridLayout * grid = findChild<QGridLayout *>("grdGame");

	// Connect the exit button in the main menu to the quit function.
	QAction * mnuExit = findChild<QAction*>("mnuExit");
	connect(mnuExit, SIGNAL(triggered(bool)), qApp, SLOT(quit()));


	// Connect the about button in the help menu to the function
	QAction * about = findChild<QAction*>("mnuAbout");
	connect(about, SIGNAL(triggered(bool)), this, SLOT(aboutGame()));

	QAction * abqt = findChild<QAction*>("mnuAboutQt");
	connect(abqt, SIGNAL(triggered(bool)), this, SLOT(aboutQt()));

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
	for(int r = 2; r >= 0; --r) {
		for(int c = 2; c >= 0; --c) {
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
		for(int c = 0; c < 9; ++c) {
			out += QString::number(gameBoard->orients[r][c]) + " ";
		}
		if(r != 7) out += "\nOrient:\t";
	}
	QMessageBox::information(this, "Board Debug: Orientation setup", out);
#endif
}

void winMain::newGame() {
	gameBoard->reset();
	whoseTurn->setText("X");
	taunt->setText("");
	xHasTurn = true;
}

bool winMain::winner(bool isComp) {
	int winRar = Game::checkWinner(gameBoard);
	if(winRar != 0)
	{
		if(QMessageBox::question(this, "We have a winner!", (isComp ? "The computer (" : "") + QString(winRar==1 ? "X" : "O") + (isComp ? ")" : "") + " wins!!\n\nPlay again?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes)
			newGame();
		else
			qApp->quit();
		return true;
	}
	bool draw = true;
	for(int i = 8; i >= 0; --i) {
		if(gameBoard->get(i)->isEnabled()) {
			draw = false;
			break;
		}
	}
	if(draw) {
		QMessageBox::information(this, "It's a draw!", "Nobody wins.");
		newGame();
		return true;	
	}
	return false;
}

void winMain::pressButton(btnSquare * which) {
	if(xHasTurn) {
		which->setX();
		whoseTurn->setText("O");
	} else {
		which->setO();
		whoseTurn->setText("X");
	}
	xHasTurn = !xHasTurn;
}

void winMain::btnPressed() {
	pressButton((btnSquare * ) sender());
	if (winner(false)) return;
	if (radComputer->isChecked()) {
		btnSquare* computerChoice = AI::computerMove(gameBoard, taunt, radImp->isChecked(), radHard->isChecked(), radNormal->isChecked());
		pressButton(computerChoice);
		if(winner(true)) return;
	}
}

void winMain::keyPressEvent(QKeyEvent * e) {
	int which = -1;
	switch(e->key()) {
		case Qt::Key_1 :
			which = 2; break;
		case Qt::Key_2 :
			which = 1; break;
		case Qt::Key_3 :
			which = 0; break;

		case Qt::Key_4 :
			which = 5; break;
		case Qt::Key_5 :
			which = 4; break;
		case Qt::Key_6 :
			which = 3; break;

		case Qt::Key_7 :
			which = 8; break;
		case Qt::Key_8 :
			which = 7; break;
		case Qt::Key_9 :
			which = 6; break;
	}
	if(which!=-1) gameBoard->get(which)->click();
}

void winMain::aboutGame() {
	QMessageBox::about(this, "About this game", "<h1>Tic-Tac-Toe++</h1><p>Made by Avindra Vishal Goolcharan. It is not licensed for commercial purposes, and is expressly restricted from such activity under <a href=\"http://creativecommons.org/licenses/by-nc-nd/3.0/\">Creative Commons <small>(Attribution-Noncommercial-No Derivative Works)</small> 3.0 Unported</a>.</p><p>For a history of this application and more, see the <a href=\"https://github.com/avindra/ttt-plusplus/\">project's homepage</a> on GitHub.</p>");
}

void winMain::aboutQt() {
	QMessageBox::aboutQt(this);
}

winMain::~winMain() {}

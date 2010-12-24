#include "winmain.h"
#include <QMessageBox>

winMain::winMain(QWidget *parent, Qt::WFlags flags)
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
	xHasTurn = true;
}

bool winMain::winner(bool isComp) {
	int winPaths[8][3] = {
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},

		// vertical
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},

		// diagonal
		{0, 4, 8},
		{2, 4, 6}
	};
	int winRar = 0;
	for(int j = 7; j >= 0; --j) {
		int xCount = 0, oCount = 0;
		for(int i = 2; i >=0; --i) {
			btnSquare * temp = gameBoard->get(winPaths[j][i]);
			if(temp->isX())
			{
				if(++xCount == 3)
				{
					winRar = 1;
					break;
				} else if(oCount != 0) break;
			} else if(temp->isO())
			{
				if(++oCount==3)
				{
					winRar = 2;
					break;
				} else if(xCount != 0) break;
			}
		}
		if(winRar != 0) break;
	}
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


btnSquare* winMain::checkMoves(int checks[][3], bool isX)
{
	do
	{
		btnSquare * temp;
		for (int i = sizeof(checks) - 1; i >= 0; --i)
		{
			temp = (gameBoard->get(checks[i][0])->autoCheck(isX)
				 && gameBoard->get(checks[i][1])->autoCheck(isX)
				 && gameBoard->get(checks[i][2])->isEnabled())

				 ? gameBoard->get(checks[i][2])
				 : 0;
			if (temp)
			{
				gameBoard->reorient();
				return temp;
			}
		}
	} while (gameBoard->rotate());
	return 0;
}

btnSquare* winMain::computerMove() {
	int criticalChecks[4][3] = {
		{0, 1, 2},
		/*
			O O ?
			_ _ _
			_ _ _
		*/
		{0, 2, 1},
		/*
			O ? O
			_ _ _
			_ _ _
		*/
		{0, 4, 8},
		/*
			O _ _
			_ O _
			_ _ ?
		*/
		// I excluded 804 / 084, because later on, the 
		// center would be picked anyway. Similar coding
		// strategy is used further down as well.
		{3, 4, 5}
		/*
			_ _ _
			O O ?
			_ _ _
		*/
	};
	btnSquare * temp;

	//win
	if (radHard->isChecked() || radImp->isChecked() || (radNormal->isChecked() && (qrand() % 2) >= 1))
	{
		if (temp = checkMoves(criticalChecks, false)) return temp;
	}
	//defend
	if (radHard->isChecked() || radImp->isChecked() || radNormal->isChecked())
	{
		if (temp = checkMoves(criticalChecks, true)) return temp;
	}

	if(radImp->isChecked())
	{
		//<-------------------------------------------------------------------------->
		//								   FORKING
		//<-------------------------------------------------------------------------->
		int forks[16][3] = {
 			//<--a-->
			{0, 2, 4},
			{0, 4, 2},
			{2, 4, 0},
			//<--b-->
			{4, 6, 7},
			{4, 7, 6},
			{7, 6, 4},
			//<--c-->
			{0, 1, 3},
			{0, 3, 1},
			{3, 1, 0},
			//<--d-->
			{0, 8, 6},
			{0, 6, 2},
			{0, 2, 6},
			{6, 2, 0},
			//<--e-->
			{1, 6, 7},
			{1, 7, 6},
			{6, 7, 1}
		};
		if (temp = checkMoves(forks, false)) return temp;
		//<-------------------------------------------------------------------------->
		//							BLOCK FORKING
		//<-------------------------------------------------------------------------->
		int bForks[15][3] = {
			//<--f-->
			{0, 2, 5},
			{0, 5, 2},
			{5, 2, 0},
 			//<--a-->
			{0, 2, 4},
			{0, 4, 2},
			{2, 4, 0},
			//<--b-->
			{4, 6, 7},
			{4, 7, 6},
			{7, 6, 4},
			//<--c-->
			{0, 1, 3},
			{0, 3, 1},
			{3, 1, 0},
			//<--e-->
			{1, 6, 7},
			{1, 7, 6},
			{6, 7, 1}
		};
		if (temp = checkMoves(bForks, true)) return temp;
		//<--d-->
		bool defend = false;
		btnSquare * badbut;
		do
		{
			int tests[3][3] = {
				{0, 6, 2},
 				{0, 2, 6},
				{6, 2, 0}
			};
			for(int i = 2; i >= 0; --i) {
				int innerTest[3];
				memcpy(innerTest, tests[i], sizeof(innerTest));
				if (gameBoard->get(innerTest[0])->isX() && gameBoard->get(innerTest[1])->isX() && (gameBoard->get(innerTest[2])->isEnabled() || gameBoard->get(8)->isEnabled()))
				{
					defend = true;
					badbut = gameBoard->get(innerTest[2]);
				}
			}
			if (defend)
			{
				btnSquare * theMove = gameBoard->get(0);
				while (!theMove->isEnabled() || theMove == badbut || theMove == gameBoard->get(8))
				{
					theMove = gameBoard->get((qrand() % 7) + 1);
				}
				return theMove;
			}
		} while (gameBoard->rotate());
		//center
		if (gameBoard->get(4)->isEnabled())
			return gameBoard->get(4);
		//opposite corner
		int opposites[2][2] = {
			{0, 8},
			{3, 7}
		};
		for(int i = 1; i >= 0; --i) {
			int inner[2];
			memcpy(inner, opposites[i], sizeof(inner));

			temp = gameBoard->get(inner[1]);
			if (gameBoard->get(inner[0])->isX() && temp->isEnabled()) return temp;

			temp = gameBoard->get(inner[0]);
			if (gameBoard->get(inner[1])->isX() && temp->isEnabled()) return temp;
		}

		// TODO: If corners, and similarly sides, are all taken up, then
		// the code will result in an infinite loop.
		// 
		// This has never happened, which means the code below isn't even
		// being reached.

		//empty corner
		int corners[4] = {
			0,  2,

			6,  8
		};
		temp = gameBoard->get(corners[qrand() % 3]);
		while (!temp->isEnabled())
		{
			temp = gameBoard->get(corners[qrand() % 3]);
		}
		if (temp->isEnabled()) return temp;
		//empty side
		int sides[4] = {
			 1, 
		   3,  5,
		     7  
		};
		temp = gameBoard->get(sides[qrand() % 3]);
		while (!temp->isEnabled())
		{
			temp = gameBoard->get(sides[qrand() % 3]);
		}
		return temp;
	}

	// randomly play a remaining square
	// Theoretically, the code will never reach here.
	temp = gameBoard->get(qrand() % 8);
	while (!temp->isEnabled())
	{
		temp = gameBoard->get(qrand() % 8);
	}
	return temp;
}

void winMain::btnPressed() {
	pressButton((btnSquare * ) sender());
	if (winner(false)) return;
	if (radComputer->isChecked()) {
		pressButton(computerMove());
		if(winner(true)) return;
	}
}

void winMain::aboutGame() {
	QMessageBox::about(this, "About this game", "<h1>Tic-Tac-Toe++</h1><p>This game was made mostly by Avindra Vishal Goolcharan. It is not licensed for commercial purposes, and is expressly restricted from such activity under <a href=\"http://creativecommons.org/licenses/by-nc-nd/3.0/\">Creative Commons <small>(Attribution-Noncommercial-No Derivative Works)</small> 3.0 Unported</a>.</p><p>For a history of this application and more, see the <a href=\"http://code.google.com/p/ttt-plusplus/\">project's homepage</a> on Google Code.</p>");
}

void winMain::aboutQt() {
	QMessageBox::aboutQt(this);
}

winMain::~winMain()
{
}
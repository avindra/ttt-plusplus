#include "btnSquare.h"

// Construct
btnSquare::btnSquare() : QPushButton() {
	// Set button to fill it's allotted space
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->setStyleSheet(style = "font-size:42px;");
}

// Destruct
btnSquare::~btnSquare() {

}

/**
 * Called at the end of
 * the game to prevent
 * further play.
 */
void btnSquare::disable() {
	this->setEnabled(false);
	this->setStyleSheet(style + "background-color:gray;color:white;");
}

void btnSquare::setX() {
	if(!this->isEnabled()) return;
	state = 1;
	this->setText("X");
	this->setEnabled(false);
	this->setStyleSheet(style + "background-color:red;color:white;");
}

void btnSquare::setO() {
	if(!this->isEnabled()) return;
	state = 2;
	this->setText("O");
	this->setEnabled(false);
	this->setStyleSheet(style + "background-color:orange;");
}

void btnSquare::unset() {
	this->setText("");
	this->setEnabled(true);
	this->setStyleSheet(style);
	state = 0;
}

bool btnSquare::isX() {
	return state == 1;
}

bool btnSquare::isO() {
	return state == 2;
}

bool btnSquare::autoCheck(bool checkX) {
	return checkX ? isX() : isO();
}
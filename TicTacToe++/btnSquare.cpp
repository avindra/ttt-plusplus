#include "btnSquare.h"

// Construct
btnSquare::btnSquare() : QPushButton() {
	// Set button to fill it's allotted space
	this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->setStyleSheet("font-size:42px");
}

// Destruct
btnSquare::~btnSquare() {

}

void btnSquare::setX() {
	if(!this->isEnabled()) return;
	state = 1;
	this->setText("X");
	this->setEnabled(false);
}

void btnSquare::setO() {
	if(!this->isEnabled()) return;
	state = 2;
	this->setText("O");
	this->setEnabled(false);
}

void btnSquare::unset() {
	this->setText("");
	this->setEnabled(true);
	state = 0;
}

bool btnSquare::isX() {
	return state == 1;
}

bool btnSquare::isO() {
	return state == 2;
}
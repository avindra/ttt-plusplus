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
	blnIsX = true;
	this->setText("X");
	this->setEnabled(false);
}

void btnSquare::setO() {
	if(!this->isEnabled()) return;
	blnIsX = false;
	this->setText("O");
	this->setEnabled(false);
}

void btnSquare::unset() {
	this->setText("");
	this->setEnabled(true);
}

bool btnSquare::isX() {
	return blnIsX;
}

bool btnSquare::isO() {
	return !blnIsX;
}
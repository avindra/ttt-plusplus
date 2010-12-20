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
	if(this->isFlat()) return;
	blnIsX = true;
	this->setText("X");
	this->setFlat(true);
}

void btnSquare::setO() {
	if(this->isFlat()) return;
	blnIsX = false;
	this->setText("O");
	this->setFlat(true);
}

void btnSquare::unset() {
	this->setText("");
	this->setFlat(false);
}

bool btnSquare::isX() {
	return blnIsX;
}

bool btnSquare::isO() {
	return !blnIsX;
}
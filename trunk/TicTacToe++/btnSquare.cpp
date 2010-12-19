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
	blnIsX = true;
	this->setText("X");
	this->setFlat(true);
}

void btnSquare::setO() {
	blnIsX = false;
	this->setText("O");
	this->setFlat(true);
}

void btnSquare::unset() {
	this->setText("");
}

bool btnSquare::isX() {
	return blnIsX;
}

bool btnSquare::isO() {
	return !blnIsX;
}
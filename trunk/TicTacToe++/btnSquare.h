#include <QPushButton>

class btnSquare : public QPushButton
{
	Q_OBJECT
	public:
		// Construct / destruct
		btnSquare();
		~btnSquare();

		/*
			Setters
		*/

		// Mark this square with an X
		void setX();
		// Mark this square with an O
		void setO();
		// Reset this square.
		void unset();

		/*
			Checks
		*/

		// Returns whether or not the square has an X.
		bool isX();
		// Returns whether or not the square has an O.
		bool isO();

		// Whether or not this square has an X.
		bool blnIsX;
};
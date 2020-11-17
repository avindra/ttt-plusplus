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
		bool autoCheck(bool isX);

		// State of the square. 0 is blank, 1 is X, 2 is O
		int state;

		QString style;
};
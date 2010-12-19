#include <QPushButton>

class btnSquare : public QPushButton
{
	Q_OBJECT
	public:
		// Construct / destruct
		btnSquare();
		~btnSquare();

		void setX();
		void setO();
		void unset();

		bool isX();
		bool isO();

	private:
		bool blnIsX;
};
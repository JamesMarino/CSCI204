/*
 * Changes are commented below
 */

#include <iostream>

// Semicolon
using namespace std;

// Spelling / Definition errors
// Syntax (semicolon)
class Rectangle
{
	// Protected args
	protected:
		int length;
		int width;
	public:
		// Added int as second argument
		// getData should not be constant, private
		// properties are being modified
		void setData(int, int);
		void showRectangle();
		void displayArea();
};

// Setting data not getting
void Rectangle::setData(int len, int wid)
{
	this->length = wid;
	this->width = len;
}

void Rectangle::showRectangle()
{
	cout << "Dementions are Length: " << this->length
		<< " by Width: " << this->width << endl;
}

// Out of line definitions
void Rectangle::displayArea()
{
	// Times not plus
	int area = this->length * this->width;
	cout << "Area is " << area << endl;
}

class Block : public Rectangle
{
private:
	int height;
public:
	// Correct definition, setting not getting
	void setData(int, int, int);
	void showBlock();
	void computeVolume();
};

// Out of line implementation
void Block::setData(int width, int length, int height)
{
	// Set the data
	Rectangle::setData(length, width);
	this->height = height;
}

void Block::showBlock()
{
	cout << "Height " << height << endl;
	Rectangle::showRectangle();
}

// It's computing Volume
void Block::computeVolume()
{
	int volume = this->length * this->width * this->height;
	cout << "Volume is " << volume << endl;
}

int main ()
{
	// Adjust definitions and instances
	Rectangle rectangle;
	rectangle.setData(4, 5);
	
	cout << "Rectangle... " << endl;
	rectangle.showRectangle();
	rectangle.displayArea();
	
	cout << "Block... " << endl;
	Block cube;
	// Set data
	cube.setData(4, 5, 6);
	cube.showBlock();
	
	// Show new values
	cube.computeVolume();
	
	// Return 0
	return 0;
}

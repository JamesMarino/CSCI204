#include <iostream>
using namespace std;

// No virtual include file
// Namespace std

/*
 * Class A
 */

class A {
	public:
		// Constructors
		A (int a = 0);
		
		// Needs return type
		virtual void print() const;
		virtual void doubleNum();
	private:
		int x;
};

// A Implementation
A::A(int x) {
	// Assigned to constant value
	this->x = x;
}

void A::print() const {
	cout << "A x: " << x << endl;
}

void A::doubleNum() {
	x = x + 2;
}

/*
 * Class B
 */

class B : public A {
	public:
		B (int x = 0, int y = 0);
		
		// All functions the same should be virtual
		// Just in case
		virtual void print() const;
		virtual void doubleNum();
	private:
		int y;
};

// B Implementation
B::B(int y, int x) : A(x) {
	// Changed to B's private member
	this->y = y;
}

void B::print() const {
	// Changed to y
	cout << "B y: " << y << endl;
}

void B::doubleNum() {
	y = y + 2;
}

int main() {
	A *ptrA;
	B *ptrB;
	
	// Assign
	ptrA = new A(4);
	ptrA->print();
	ptrA->doubleNum();
	ptrA->print();
	delete ptrA;
	
	ptrB = new B(5);
	ptrB->print();
	delete ptrB;
	
	return 0;
}


/*
 * Changes Are Commented below
 */

// Removed string (unnessasary)
#include <iostream>

// Added namespace declaration std::
using namespace std;

class Student
{
	
	// Placed into appropriate private and public functions
	private:
		int stuID;
		// Changed to integer
		int year;
		double gpa;
		
	public:
		Student (const int, const int, const double);
		void showYear ();
		Student& operator++ ();
};

// Added constants to all inputs, not to be altered
Student::Student(const int i, const int y, const double g)
{
	// All refrenced to the class intance members
	this->stuID= i;
	this->year = y;
	this->gpa = g;
}

void Student::showYear ()
{
	// Output class instance of property
	cout << this->year;
}

// Fixed ++ operator declaration (assumed used in main function)
Student& Student::operator++ ()
{
	// Add one
	this->year++;
	
	return *this;
}

int main()
{
	
	// Cleaned up with appropriate values
	Student a(111, 2, 3.50),
			b(222, 1, 3.00),
			c(333, 3, 2.75);
	
	// Cleaned up main function
	cout << "Student a is year ";
	a.showYear();
	cout << endl;
	
	cout << "Student b is year ";
	b.showYear();
	cout << endl;
	
	cout << "Student c is year ";
	c.showYear();
	cout << endl;
	
	// Fixed up ++ after b
	++a;
	++b;
	++c;
	
	cout << "Student a is now year ";
	a.showYear();
	cout << endl;
	
	cout << "Student b is now year ";
	b.showYear();
	cout << endl;
	
	cout << "Student c is now year ";
	c.showYear();
	cout << endl;
	
	return 0;
}


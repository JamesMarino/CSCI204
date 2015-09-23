#include <iostream>
#include <string>
using namespace std;

// Template typename corrected
template <typename T>
T subtract(T x, T y)
{
	// Instantiate variable
	T difference = (x - y);
	
	// Return
	return difference;
}

// Cleaned up class
// private: missing semicolon
// Changed age to integer
// Added semicolon
class Person
{
	
// Added friend function for stream out
friend ostream& operator<<(ostream&, const Person&);
	
private:
	string lastName;
	string firstName;
	int age;
public:
	void setValues(string, string, int);
	Person operator-(Person);
};

// Fixed variable Names
// Reversed stream direction
ostream& operator<<(ostream& output, const Person &person)
{
	// Updated to years in output
	output << person.firstName << " "
		<< person.lastName << " "
		<< person.age << " years old"
		<< endl;
	
	return output;
}

// Reversed last name property and paramter assignment
void Person::setValues(string last, string first, int ageIn)
{
	lastName = last;
	firstName = first;
	age = ageIn;
}

// Operator shouold be minus
Person Person::operator-(Person p)
{
	Person temp;
	
	// Weird but OK
	// output to temp
	temp.lastName = "Difference";
	temp.firstName = "Age";
	
	temp.age = age - p.age;
	
	// Make the age positive no matter what
	temp.age = -(temp.age);
	
	return temp;
}

int main()
{
	// Ints
	int a = 7, b = 26, c = 0;
	c = subtract(a, b);
	
	// Doubles
	double d = 39.25, e = 2.01, f = 0;
	f = subtract(d, e);
	
	// Persons
	Person g, h, i;
	
	g.setValues("the Builder", "Alice", 50);
	h.setValues("the Engine", "Edward", 90);
	
	// Take away peoples age
	i = subtract(g, h);
	
	cout << c << endl
		<< f << endl
		<< i << endl;

	return 0;
}

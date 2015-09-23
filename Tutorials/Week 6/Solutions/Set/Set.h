#include <iostream>

using namespace std;

class Set
{
private:
	int* elements;
	int elementSize;
public:
	Set();
	Set(int);
	Set(const Set& source);
	~Set();
	
	// Binary Operators
	Set operator+(Set&);
	Set operator-(Set&);
	Set operator&(Set&);
	
	// Stream overload
	friend istream& operator>>(istream&, const Set&);
	friend ostream& operator<<(ostream&, const Set&);
};

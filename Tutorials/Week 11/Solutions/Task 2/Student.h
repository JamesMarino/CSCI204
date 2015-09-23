#ifndef __Student__
#define __Student__

#include <iostream>
#include <sstream>
#include <locale>
#include <vector>
#include <deque>

class Student
{
private:
	std::string FirstName;
	std::string LastName;
	int StudentID;
	float GPA;
	
public:
	friend bool operator>(const Student&, const Student&);
	friend bool operator<(const Student&, const Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
};

#endif

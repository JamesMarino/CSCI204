#ifndef __Student__
#define __Student__

#include <iostream>
#include <sstream>
#include <locale>
#include <vector>

class Student
{
private:
	std::string FirstName;
	std::string LastName;
	int StudentID;
	float GPA;
	
public:
	friend std::ostream& operator<<(std::ostream&, const Student&);
	friend std::istream& operator>>(std::istream&, Student&);
};

#endif

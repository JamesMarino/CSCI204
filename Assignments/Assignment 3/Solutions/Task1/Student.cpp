/*------------------------------------------------------
 * Student's Name: James Marino
 * Student's email address: jm617@uow.edu.au
 * Laboratory group: CL/03 Friday 15:30
 * Purpose of this assignment:
 * Student Class (with various overloading) for storage
 * in a linked list
 -------------------------------------------------------*/

#include "Student.h"

Student::Student()
{
	number = 0;
	name = "";
	email = "";
}

std::istream& operator>>(std::istream &stream, Student &student)
{
	std::cout << "Input number: ";
	stream >> student.number;
	
	std::cout << "Input name: ";
	
	// Input special for first and last names
	// (Space in between)
	std::string temp;
	stream >> temp;
	student.name = temp;
	stream >> temp;
	student.name += " ";
	student.name += temp;
	
	std::cout << "Input email: ";
	stream >> student.email;
	
	return stream;
}

std::ostream& operator<<(std::ostream &stream, const Student &student)
{
	stream << student.number << ", "
	<< student.name << ", "
	<< student.email;
	
	return stream;
}

const Student& Student::operator=(const Student &input)
{
	// Check for self assignment
	if (this != &input) {
		number = input.number;
		name = input.name;
		email = input.email;
	}
	
	return (*this);
}

bool Student::operator>(const Student &lhs) const
{
	if (this->email > lhs.email) {
		return true;
	} else {
		return false;
	}
}

bool Student::operator<(const Student &lhs) const
{
	if (this->email < lhs.email) {
		return true;
	} else {
		return false;
	}
}
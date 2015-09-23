/*------------------------------------------------------
 * Student's Name: James Marino
 * Student's email address: jm617@uow.edu.au
 * Laboratory group: CL/03 Friday 15:30
 * Purpose of this assignment:
 * Header: Student Class (with various overloading)
 * for storage in a linked list
 -------------------------------------------------------*/

#ifndef __Student__
#define __Student__

#include <string>
#include <iostream>

class Student
{
private:
	int number;
	std::string name;
	std::string email;
	
public:
	// Constructors
	Student();
	
	/*
	 * Overloading
	 */
	// Streams
	friend std::istream& operator>>(std::istream&, Student&);
	friend std::ostream& operator<<(std::ostream&, const Student&);
	
	// Assingment
	const Student& operator=(const Student&);
	
	// Relational
	bool operator>(const Student&) const;
	bool operator<(const Student&) const;
};

#endif

#include <iomanip>
#include "Employee.h"

Employee::Employee() {
	init();
}

Employee::Employee(int theID, char* fn, char* ln, double r) {
	this->employeeID = theID;
	strcpy(fname, fn);
	strcpy(lname, ln);
	payRate = r;
}

Employee::Employee(const Employee &e) {
	employeeID = e.employeeID;
	strcpy(fname, e.fname);
	strcpy(lname, e.lname);
	payRate = e.payRate;
}

void Employee::init() {
	employeeID = 0;
	fname[0] = '\0';
	lname[0] = '\0';
	payRate = 0.0;
}

int Employee::getID() {
	return employeeID;
}

void Employee::setRate(double rate) {
    payRate = rate;
}

std::ostream& operator<<(std::ostream& out, const Employee &e) {
	out << "Employee ID: " << e.employeeID << std::endl;
	out << "First name: " << e.fname << std::endl;
	out << "Last name: " << e.lname << std::endl;
	out << "Pay rate/hour: $"; 
	out.width(8);
	out.precision(2);
	out << std::fixed << std::setfill('0') << e.payRate << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Employee &e) {

	return in;
}



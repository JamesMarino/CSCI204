#include<iostream>
#include<cstring>
#ifndef _EMPLOYEE_
#define _EMPLOYEE_
class Employee {
	friend std::ostream& operator<<(std::ostream&, const Employee &);
	friend std::istream& operator>>(std::istream&, Employee &);
	private:
		int id;
		char fname[50];
		char lname[50];
		double payRate;

	public:
		Employee();
		Employee(int, char*, char*, double);
		Employee(const Employee &);
		void init();
		int getID();
		void setRate(double);
};

#endif


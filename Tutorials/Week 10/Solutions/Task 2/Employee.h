#ifndef __Employee__
#define __Employee__

#include <iostream>
#include <string>
#include <fstream>

struct EmployeeData
{
	int IDNumber;
	char firstName[60];
	char lastName[60];
	double hourlyPayRate;
};

template <typename structure>
class File
{
private:
	File();
	
	// Data Members
	std::fstream FileStream;
	char *FileName;
	
	// Positioning
	long long readPosition;
	long long writePosition;
	bool IsEOF;
	
	struct Error {
		static const std::string open;
		static const std::string close;
	};
	
public:
	~File();
	File(const char*);
	bool read(structure&, long long, bool);
	bool write(structure&);
	bool update(structure&);
	
	// Access
	bool getEOFStatus();
	long long getPositionOfFile(bool);
	void setPositionOfFile(long long, bool);
	void resetEOFFlag();
	
};

class Employee
{
	
private:
	// Do not use default contructor
	Employee();
	
	// Data members
	EmployeeData data;
	File<EmployeeData> *file;
	
	// Overloading
	friend std::ostream& operator<<(std::ostream&, const Employee&);
	friend std::istream& operator>>(std::istream&, Employee&);
	
public:
	~Employee();
	Employee(const char*);
	
	// Access Members
	bool addEmployee();
	bool searchEmployee(int);
	bool updatePay(int, double);
	
};

#endif

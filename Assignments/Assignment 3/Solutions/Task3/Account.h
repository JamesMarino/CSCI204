/*------------------------------------------------------
 * Student's Name: James Marino
 * Student's email address: jm617@uow.edu.au
 * Laboratory group: CL/03 Friday 15:30
 * Purpose of this assignment:
 * Construct a doubley linked list, including iterator
 * Knowledge and use of the internals and workings of
 * containers
 -------------------------------------------------------*/

#ifndef __Account__
#define __Account__

#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "Date.h"

class Account
{
private:
	/*
	 * Sizes
	 */
	static const int NAME_SIZE = 60;
	static const int ADDRESS_SIZE = 120;
	
	/*
	 * Class Data
	 */
	long AccountNumber;
	char FullName[NAME_SIZE];
	char Sex;
	MYLIB::Date DOB;
	char Address[ADDRESS_SIZE];
	double Balance;
	
	/*
	 * Misc Constants
	 */
	static const char COMMA;
	static const char NEW_LINE;
	static const char CARRIAGE_RETURN;
	static const char EMPTY_CHAR;
	static const char NULL_BYTE;
	static const std::string EMPTY_STRING;
	
public:
	/*
	 * Initialisation
	 */
	Account();
	Account(const Account&);
	
	/*
	 * Overloading
	 */
	const Account& operator=(const Account&);
	
	bool operator<=(const Account&) const;
	bool operator>=(const Account&) const;
	bool operator<(const Account&) const;
	bool operator>(const Account&) const;
	
	friend std::istream& operator>>(std::istream&, Account&);
	friend std::ostream& operator<<(std::ostream&, const Account&);
	
	/*
	 * Manipulators
	 */
	class currency
	{
	private:
		int width;
		int precision;
		
	public:
		currency();
		currency(int, int);
		
		// Overloaders
		friend std::ostream& operator<<(std::ostream&, const currency&);
	};
	
	/*
	 * Others
	 */
	void reset();
	bool empty();
	void initString(char[], int);
	const char* getFullName();
};

#endif

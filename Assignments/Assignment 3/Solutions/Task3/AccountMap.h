/*------------------------------------------------------
 * Student's Name: James Marino
 * Student's email address: jm617@uow.edu.au
 * Laboratory group: CL/03 Friday 15:30
 * Purpose of this assignment:
 * Construct a doubley linked list, including iterator
 * Knowledge and use of the internals and workings of
 * containers
 -------------------------------------------------------*/

#ifndef __AccountMap__
#define __AccountMap__

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "Account.h"
#include "Date.h"

class AccountMap
{
public:
	AccountMap();
	~AccountMap();
	
	// Comparison in multimap
	class CompareCharArrays
	{
	public:
		bool operator()(const char*, const char*) const;
	};
	
	/*
	 * Utilities
	 */
	void loadData(const char*);
	void displayData();
	
private:
	std::multimap<char*, Account, CompareCharArrays> accounts;
	std::multimap<char*, Account, CompareCharArrays>::iterator it;
	
	/*
	 * Data Details
	 */
	long recordAmount;
	char **FullName;
	
	/*
	 * Utilities
	 */
	void setRecordAmount(const char *fileName);
	
	/*
	 * Constants
	 */
	static const int NAME_SIZE = 60;
	
};

#endif

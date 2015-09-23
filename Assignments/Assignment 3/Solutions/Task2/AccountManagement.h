/*------------------------------------------------------
 * Student's Name: James Marino
 * Student's email address: jm617@uow.edu.au
 * Laboratory group: CL/03 Friday 15:30
 * Purpose of this assignment:
 * Construct a doubley linked list, including iterator
 * Knowledge and use of the internals and workings of
 * containers
 -------------------------------------------------------*/

#ifndef __AccountManagement__
#define __AccountManagement__

#include <fstream>
#include "Account.h"
#include "OrderedList.h"

class AccountManagement
{
private:
	MYLIB::OrderedList<Account> list;
	
public:
	void loadData(const char*);
	void saveData(const char*);
	
	void displayData();
};

#endif

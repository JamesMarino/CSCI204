/*------------------------------------------------------
 * Student's Name: James Marino
 * Student's email address: jm617@uow.edu.au
 * Laboratory group: CL/03 Friday 15:30
 * Purpose of this assignment:
 * Construct a doubley linked list, including iterator
 * Knowledge and use of the internals and workings of
 * containers
 -------------------------------------------------------*/

#include "AccountManagement.h"
using namespace std;

void AccountManagement::loadData(const char *fileName)
{
	// Open the file
	ifstream inputFile;
	inputFile.open(fileName);
	
	// Check of file is good
	if (inputFile.good()) {
		
		// Setup Container
		Account temp;
		
		// Untill the end of the file
		while (!inputFile.eof()) {
			
			inputFile >> temp;
			
			if (!temp.empty()) {
				list.insert(temp);
			}
		}
		
		inputFile.close();
	} else {
		cerr << "File IO Error." << endl;
		inputFile.close();
	}
	
}

void AccountManagement::displayData()
{
	MYLIB::OrderedList<Account>::iterator iterate = list.begin();
	
	while (iterate != list.end()) {
		iterate++;
		cout << *iterate;
	}
}

void AccountManagement::saveData(const char *outputFileName)
{
	ofstream outputFile;
	outputFile.open(outputFileName, ios::binary | ios::trunc);
	
	// Check file is O.K.
	if (outputFile.good()) {
		
		MYLIB::OrderedList<Account>::iterator iterate = list.begin();
		
		while (iterate != list.end()) {
			iterate++;
			outputFile.write((char*)&*iterate, sizeof(Account));
		}
		
		outputFile.close();
	} else {
		cerr << "File IO Error." << endl;
		outputFile.close();
	}
}

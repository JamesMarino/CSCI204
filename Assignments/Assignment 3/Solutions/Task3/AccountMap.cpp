/*------------------------------------------------------
 * Student's Name: James Marino
 * Student's email address: jm617@uow.edu.au
 * Laboratory group: CL/03 Friday 15:30
 * Purpose of this assignment:
 * Construct a doubley linked list, including iterator
 * Knowledge and use of the internals and workings of
 * containers
 -------------------------------------------------------*/

#include "AccountMap.h"
using namespace std;

AccountMap::AccountMap()
{
	recordAmount = 0;
	FullName = NULL;
}

AccountMap::~AccountMap()
{
	if (FullName != NULL) {
		
		// Delete each sub Value
		for (int i = 0; i < recordAmount; i++) {
			delete [] FullName[i];
		}
		
		// Delete the main Array
		delete [] FullName;
		
	}
}

bool AccountMap::CompareCharArrays::operator()(const char *lhs, const char *rhs) const
{
	return string(lhs) < string(rhs);	
}

void AccountMap::setRecordAmount(const char *fileName)
{
	ifstream inputFile;
	inputFile.open(fileName, ios::binary);
	
	// Check Status
	if (inputFile.good()) {
		
		// Temp
		Account temp;
		
		// Find the amount of records
		while (!inputFile.eof()) {
			inputFile.read((char*)&temp, sizeof(Account));
			recordAmount++;
		}
		
		// Seek to begining
		inputFile.clear();
		inputFile.seekg(0, ios::beg);
		
		// Close off File
		inputFile.close();
		
	} else {
		inputFile.close();
		cerr << "Error Reading File." << endl;
	}
}

void AccountMap::loadData(const char *fileName)
{
	setRecordAmount(fileName);
	
	ifstream inputFile;
	inputFile.open(fileName, ios::binary);
	
	// Check Status
	if (inputFile.good()) {
		
		// Temp
		Account temp;
		
		// Seek to begining
		inputFile.clear();
		inputFile.seekg(0, ios::beg);
		
		// Initialise Array
		FullName = new char*[recordAmount];
		
		// Initialise each Value
		for (int i = 0; i < recordAmount; i++) {
			FullName[i] = new char[NAME_SIZE];
		}
		
		// Set up counter
		int counter = 0;
		
		// Cycle through until end of file
		while (!inputFile.eof()) {
			
			// Read in
			inputFile.read((char*)&temp, sizeof(Account));
			
			// Copy in
			strcpy(FullName[counter], temp.getFullName());
			
			// Store in multimap
			accounts.insert(pair<char* const, Account>(FullName[counter], temp));
			
			counter++;
			
		}
		
		inputFile.close();
		
	} else {
		cerr << "File IO Error.";
		inputFile.close();
	}
}

void AccountMap::displayData()
{
	it = accounts.begin();
	
	while (it != accounts.end()) {
		cout << it->second;
		it++;
	}
}

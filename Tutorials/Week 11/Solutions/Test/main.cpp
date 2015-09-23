#include "Employee.h"
using namespace std;

int main (int argc, char *argv[])
{
	if (argc <= 1) {
		cerr << "Enter A Filename." << endl;
		return -1;
	} else if (argc > 2) {
		cerr << "Enter appropriate amount of arguments." << endl;
		return -1;
	}
	
	// Set up file stream
	fstream inputFile;
	
	// Open file
	inputFile.open(argv[1], ios::out | ios::binary);
	
	// Test if opened successfully
	if(inputFile.good()) {
		
		// Seek to beg
		inputFile.seekp(0, ios::beg);
		
		/*
		 * Store In Data
		 */
		Employee employee1;
		
		employee1.employeeID = 10;
		strcpy(employee1.fname, "James");
		strcpy(employee1.lname, "Test");
		employee1.payRate = 3894.38;
		
		inputFile.write((char*)&employee1, sizeof(Employee));
		
		// Close the file
		inputFile.close();
		
		return 0;
		
	} else {
		cerr << "File does not exist, "
		<< "or was not opened properly."
		<< endl;
		
		return -1;
	}
	
}

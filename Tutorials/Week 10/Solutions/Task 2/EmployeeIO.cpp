#include "Employee.h"
#include "Employee.cpp"
using namespace std;

bool clearFileContents(const char*);

int main()
{
	int selection = -1, temporaryID = 0;
	double temporaryWage = 0.00;
	const char *FILE_NAME = "edata.bin";
	
	Employee employee(FILE_NAME);
	
	// Clear File
	// Set to true to clear file
	bool clear = false;
	if (clear) {
		clearFileContents(FILE_NAME);
		return 0;
	}
	
		
	// Store user options
	cout << "1. Add a new employee." << endl
	<< "2. Search an employee." << endl
	<< "3. Update an employee hourly pay rate." << endl
	<< "0. Exit." << endl << endl;
	
	// Take Input
	do {
		cout << "> ";
		cin >> selection;
		
		switch (selection) {
			case 0:
				// Do nothing but break
				break;
			case 1:
				
				// Run Functions
				cin >> employee;
				
				if (employee.addEmployee()) {
					cout << endl << "A record has been added." << endl << endl;
				} else {
					cerr << endl << "Record already Exists." << endl << endl;
				}
				
				break;
				
			case 2:
				cout << "Employee ID: ";
				cin >> temporaryID;
				
				if (employee.searchEmployee(temporaryID)) {
					cout << endl << employee << endl;
				} else {
					cerr << endl << "Employee not found." << endl;
				}
				
				break;
				
			case 3:
				
				cout << "Employee ID: ";
				cin >> temporaryID;
				
				if (employee.searchEmployee(temporaryID)) {
					cout << endl << employee << endl;
					
					cout << "New pay rate/hour: ";
					cin >> temporaryWage;
					
					if (employee.updatePay(temporaryID, temporaryWage)) {
						cout << "A record has been updated." << endl;
					} else {
						cout << "A record has NOT been updated." << endl;
					}
					
				} else {
					cerr << endl << "Employee not found." << endl;
				}
				
				break;
				
			default:
				cout << '\a' << "Invalid Option" << endl;
				break;
		}
		
	} while (selection != 0);
	
	return 0;
	
}

/*
int main ()
{
	// Local Vars
	const char FILE_NAME[] = "edata.bin";
	Employee employee(FILE_NAME);
	
	// clearFileContents(FILE_NAME);
	
	// Read out
	employee.searchEmployee(23);
	cout << employee;
	
	//employee.addEmployee();
	
	// Update
	employee.updatePay(23, 20.00);
	
	// Read out
	employee.searchEmployee(23);
	cout << employee;

	return 0;

}
*/

bool clearFileContents(const char *FILE_NAME)
{
	ofstream file(FILE_NAME, ios::out | ofstream::trunc);
	
	if (file.good()) {
		
		file.close();
		return true;
	} else {
		
		file.close();
		return false;
	}
}

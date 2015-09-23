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
	
	// All amount of arguments are fine
	
	// Set up file stream
	fstream inputFile;
	
	// Open file
	inputFile.open(argv[1], ios::in | ios::binary);
	
	// Test if opened successfully
	if(inputFile.good()) {
		
		// Initialise Employee Objects
		Employee employee[2];
		
		for (int i = 0; i < 2; i++) {
			inputFile.read((char*)&employee[i], sizeof(Employee));
		}
		
		// Print out the stored values
		for (int i = 0; i < 2; i++) {
			cout << employee[i] << endl;
		}
		
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

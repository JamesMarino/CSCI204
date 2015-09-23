#include <iostream>
using namespace std;

int main() {
	
	// Define size of array
	const int ARRAY_SIZE = 3;
	
	// Initialise
	// Static (assign 3 to cater for null byte ending)
	int staticArray[ARRAY_SIZE];
	
	// Tell User
	cout << "Enter 3 Values for an array (Static): ";
	
	// Store
	for (int i = 0; i <= ARRAY_SIZE - 1; i++) {
		cin >> staticArray[i];
	}
	
	// Print out
	for (int i = 0; i <= 2; i++) {
		cout << "Array Value "
				<< i << ": "
				<< staticArray[i] << endl;
	}
	
    return 0;
}

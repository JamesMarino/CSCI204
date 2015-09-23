#include <iostream>
using namespace std;

int main() {
	
	// Define size of array
	const int ARRAY_SIZE = 3;
	
	// Place onto the heap
	int * dynamicArray;
	
	// Initialise
	// (assign 3 to cater for null byte ending)
	dynamicArray = new int[ARRAY_SIZE];
	
	// Tell User
	cout << "Enter 3 Values for an array (Dynamic): ";
	
	// Store
	for (int i = 0; i <= ARRAY_SIZE - 1; i++) {
		cin >> dynamicArray[i];
	}
	
	// Print out
	for (int i = 0; i <= 2; i++) {
		cout << "Array Value "
		<< i << ": "
		<< dynamicArray[i] << endl;
	}
	
	// Remove dynamic instance
	delete [] dynamicArray;
	
	return 0;
}

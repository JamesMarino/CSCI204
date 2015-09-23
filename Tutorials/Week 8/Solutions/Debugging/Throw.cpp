#include <iostream>
#include <exception>
using namespace std;

/* General Fixing
 * - Spacing and indentation
 * - variable and function names
 */

void one();

int main() {
	try {
		// Function not found, changed to one
		one();
		cout << "Two";
		
	} catch (exception e) {
		// Stream Out wrong way
		cout << "Three";
	}
	
	// Fix syntax with streams
   	cout << "Four" << endl;
   	cout << "Five" << endl;
	
   	return 0;
}

void one () {
	try {
		cout << "Six";
		// Changed throw exception
		throw exception();
		
		// Throwing a second time?
		//throw exception();
		
	} catch (exception f) {
		cout << "Seven";
		
		// Rethrow not sure
		//rethrow;
		//cout << "Eight";
		
		// Throw the excpetion again
		// to go up the heirachy
		throw exception();
	}
	
	// Fix syntax with streams
	// Code not expected in output and never executed
	//cout << "Nine";
	//throw exception();
	//cout << "Ten";
}


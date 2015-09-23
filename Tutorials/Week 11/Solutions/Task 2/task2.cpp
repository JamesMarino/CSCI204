#include "Student.h"
using namespace std;

int main ()
{
	cout << "~~~~~ Important ~~~~~~" << endl;
	cout << "Run Using input by hand, file in ";
	cout << "Not working due to ':' delimiter" << endl;
	
	// Initialise Vector
	vector<Student> vectorStudent;
	
	// Initialisation
	Student temp;
	int recordAmount;
	
	// Get number of records
	cout << "How many student records: ";
	cin >> recordAmount;
	
	// Read in the records
	// Store into vector
	for (int i = 0; i < recordAmount; i++) {
		cin >> temp;
		
		vectorStudent.push_back(temp);
	}
	
	// Update status
	cout << endl << "There are " << recordAmount
		<< " records in the vector." << endl << endl;
	
	// Instansiate the double ended queue
	deque<Student> dequeStudent;
	
	for (int i = 0; i < recordAmount; i++) {
		dequeStudent.push_back(vectorStudent[i]);
	}
	
	cout << "Copy Students from vector to deque:" << endl;
	for (int i = 0; i < recordAmount; i++) {
		cout << dequeStudent[i] << endl;
	}
	
	// Sorting
	sort(dequeStudent.begin(), dequeStudent.end());
	
	// Print out sorted
	cout << endl << "Sorted records in deque:" << endl;
	for (int i = 0; i < recordAmount; i++) {
		cout << dequeStudent[i] << endl;
	}
	
	return 0;
}

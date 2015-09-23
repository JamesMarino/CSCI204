/* 	------------------------------------------------------------
 * 	Student's Name: James Marino
 * 	Student's email address: jm617@uowmail.edu.au
 * 	Laboratory group: CL/03 Friday 15:30
 * 	Purpose of this assignment:
 *		Read in data from a file into memory and perform
 *		various computations on the data (average, total etc).
 *	------------------------------------------------------------ */

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

// Class Definition
class Student
{
	private:
		// Properties
		char * name;
		int * marks;
		int num;
	
	public:
		Student();
		~Student();
	
		// Processing
		int getTotalRecords(ifstream&);
		void readRecord(ifstream&, int);
		void computeNumberOfSubjects();
		int computeTotalMarks();
		double computeAverageMark();
	
		// Access to Properties
		char * getName();
		int * getMarks();
		int getNum();
	
};

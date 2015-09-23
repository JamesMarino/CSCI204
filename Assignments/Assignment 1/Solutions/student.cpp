/* 	------------------------------------------------------------
 * 	Student's Name: James Marino
 * 	Student's email address: jm617@uowmail.edu.au
 * 	Laboratory group: CL/03 Friday 15:30
 * 	Purpose of this assignment:
 *		Read in data from a file into memory and perform
 *		various computations on the data (average, total etc).
 *	------------------------------------------------------------ */

#include "student.h"
using namespace std;

Student::Student()
{
	// Initialise to the heap
	this->name = 0;
	this->marks = new int[3];
	this->num = 0;
	
}

Student::~Student()
{
	// Memory Management
	delete [] this->name;
	delete [] this->marks;
}

int Student::getTotalRecords(ifstream& inputFile)
{
	// Initialise Local Variables
	int totalRecords;
	
	// Read from file
	inputFile >> totalRecords;
	return totalRecords;
}

void Student::readRecord(ifstream & inputFile, int lineNumber)
{
	// Initialise Local Variables
	char eat = '\0';
	int asciiEat = 0, actualPassedCharacters = 0, offsetPassedCharacters = 0;
	long long currentPosition = 0;
	
	// Go back to the start of the file
	inputFile.seekg(0, ios::beg);
	
	// Eat lines to get to the beggining of the lineNumber of the file
	for (int i = 1; i <= lineNumber; i++) {
		eat = inputFile.get();
		
		while (eat != '\n')
			eat = inputFile.get();
	}
	
	// Eat one character before, ties in with counter
	// 48 is start of ascii numbers (0) and 57 is end (9)
	while ((asciiEat < 48) || (asciiEat > 57)) {
		asciiEat = inputFile.get();
		actualPassedCharacters += 1;
	};
	
	// Offset
	offsetPassedCharacters = actualPassedCharacters - 1;
	
	// Dynamically allocate the right amount of memory for name
	this->name = new char[offsetPassedCharacters];
	
	// Go back to the start of the name
	inputFile.seekg(-actualPassedCharacters, ios::cur);
	
	// Set the current position before getting the line
	currentPosition = inputFile.tellg();
	
	// Get the whole name and store it
	inputFile.getline(this->name, offsetPassedCharacters);
	
	// Clear the stream before seeking again
	inputFile.clear();
	
	// Position back to where your up to
	currentPosition += offsetPassedCharacters;
	
	// Navigate to the end of the name
	inputFile.seekg(currentPosition, ios::beg);
	
	// Store the marks
	for (int i = 0; i <= 3; i++) {
		inputFile >> this->marks[i];
	}
	
}

void Student::computeNumberOfSubjects()
{
	// Loop through
	for (int i = 0; i <= 3; i++) {
		if (this->marks[i] != 0) {
			this->num += 1;
		}
	}
}

int Student::computeTotalMarks()
{
	// Initialise Local Vars
	int totalMarks = 0;
	
	// Loop through
	for (int i = 0; i <= 3; i++) {
		totalMarks += this->marks[i];
	}
	
	return totalMarks;
}

double Student::computeAverageMark()
{
	// Initialise Local Vars
	int totalMarks = 0, averageMark = 0;
	
	// Get total marks
	totalMarks = this->computeTotalMarks();
	averageMark = totalMarks / this->num;
	
	return averageMark;
}

// Public Access to class Properties
char * Student::getName()
{
	return this->name;
}

int * Student::getMarks()
{
	return this->marks;
}

int Student::getNum()
{
	return this->num;
}

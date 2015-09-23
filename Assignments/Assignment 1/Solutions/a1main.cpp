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
#include "student.h"
using namespace std;

int main(int argc, char* argv[])
{
	
	// Initialise Local Vars
	ifstream InputFile;
	int recordAmount = 0, instanceCount = 1;
	char * fileName;
	
	if (argc != 2) {
		cout << "Please specify a File." << endl;
		return -1;
	}
	
	// Fix up command line input args
	fileName = new char[strlen(argv[1])];
	strcpy(fileName, argv[1]);
	
	// Open the file
	InputFile.open(fileName);
	
	// Check if file opened is corrupted
	if (InputFile.good()) {
		cout << "Please Enter a Valid File." << endl;
		InputFile.close();
		
	} else {
	
		// Do the setup
		Student setup;
		recordAmount = setup.getTotalRecords(InputFile);
		
		// Initialise Mark tables and Total Lists
		int ** MarkTable = new int * [recordAmount];
		for (int i = 0; i < recordAmount; ++i) {
			MarkTable[i] = new int[4];
		}
		
		// Total Marks
		int MarkTotals[4], AverageTotals[4];
		// Initialise these
		for (int i = 0; i < 4; i++) {
			MarkTotals[i] = 0;
			AverageTotals[i] = 0;
		}
		
		// Close the file
		InputFile.close();
		
		// Initilise student objects
		Student * students;
		students = new Student[recordAmount];
		
		// Print Header
		cout << setw(18) << "Name"
			<< setw(10) << "Mark 1"
			<< setw(10) << "Mark 2"
			<< setw(10) << "Mark 3"
			<< setw(10) << "Mark 4"
			<< setw(10) << "Total"
			<< setw(10) << "Average"
			<< endl << setfill('=') << setw(78) << '=' << endl;
		
		// Store everything into memory
		// Loop through each instance
		for (int i = 0; i < recordAmount; i++) {
			// Open the file
			InputFile.open(fileName);
			
			// Initialise the instances
			students[i].readRecord(InputFile, instanceCount);
			students[i].computeNumberOfSubjects();
			
			// Print out
			cout << setfill(' ') << setw(18) << students[i].getName();
			
			for (int j = 0; j <= 3; j++) {
				cout << setw(10);
				
				// Fill In Mark table
				MarkTable[i][j] = students[i].getMarks()[j];
				
				if (MarkTable[i][j] == 0) {
					cout << ' ';
				} else {
					cout << MarkTable[i][j];
				};
			}
			
			cout << setw(10) << students[i].computeTotalMarks()
				<< setw(10) << students[i].computeAverageMark()
				<< endl;
			
			InputFile.close();
			instanceCount++;
		}
		
		// Work out totals
		for (int i = 0; i < recordAmount; i++) {
			for (int j = 0; j < 4; j++) {
				MarkTotals[j] += MarkTable[i][j];
			}
		}
		
		cout << setfill('=') << setw(78) << '=' << endl
			<< setfill(' ') << setw(18) << "Total";
		
		// Print totals
		for (int j = 0; j < 4; j++) {
			cout << setw(10) << MarkTotals[j];
		}
		
		cout << endl << setfill(' ') << setw(18) << "Average";
		
		// Work out and print average totals
		for (int j = 0; j < 4; j++) {
			AverageTotals[j] = MarkTotals[j] / recordAmount;
			cout << setw(10) << AverageTotals[j];
		}
		
		cout << endl << setfill('=') << setw(78) << '=' << endl;
		
		// Delete dynamics
		delete [] students;
		delete [] MarkTable;
		// Delete recursively
		for (int i = 0; i < recordAmount; ++i) {
			delete [] MarkTable[i];
		}
		
	}
	
	// Delete dynamics
	delete [] fileName;
	
	return 0;
}

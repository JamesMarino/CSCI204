#include "Employee.h"
using namespace std;

/*
 * Generic File Implementation
 */
template <typename structure>
File<structure>::File() {}

// Constructor
template <typename structure>
File<structure>::File(const char *fileName)
{
	// Assign new memory for filename
	FileName = new char[strlen(fileName)];
	
	// Store the FileName
	strcpy(FileName, fileName);
	readPosition = 0;
	writePosition = 0;
	IsEOF = false;
}

// Destructor
template <typename structure>
File<structure>::~File()
{
	// Delete the FileName
	delete [] FileName;
	
	if (FileStream.is_open()) {
		FileStream.close();
	}
}

// Errors
template <typename structure>
const string File<structure>::Error::open = "Could Not Open File";
template <typename structure>
const string File<structure>::Error::close = "Could Not Close File";

/**
 * @return {bool} Success or failure status
 * @param {structure} instance being read from the stream
 * @param {int} position of marking to seek to
 * @param {bool} starting point, begining or end
 */
template <typename structure>
bool File<structure>::read(structure &instance, long long position, bool begining)
{
	FileStream.open(FileName, ios::in | ios::binary);
	
	if (FileStream.good()) {
		
		// Perform operations
		if (begining) {
			FileStream.seekg(position, ios::beg);
		} else {
			FileStream.seekg(position, ios::end);
		}
		
		// Read in the structure
		if (!FileStream.eof()) {
			FileStream.read((char *)&instance, sizeof(structure));
			
			// Update Statuses
			readPosition = FileStream.tellg();
			
			if (!FileStream.eof()) {
				IsEOF = false;
			} else {
				IsEOF = true;
			}
			
			// Close off Filestream
			FileStream.close();
			
			return true;
		} else {
			// Update EOF
			IsEOF = true;
			
			// Close off Filestream
			FileStream.close();
			
			return false;
		}
		
	} else {
		
		// Close off Filestream
		FileStream.close();
		
		cerr << Error::open << endl;
		
		return false;
	}
}

/**
 * @purpose Writes to the end of the file a structure
 * @return {bool} Status of the request
 * @parameter {structure} Structure being written to disk
 */
template <typename structure>
bool File<structure>::write(structure &instance)
{
	FileStream.open(FileName, ios::out | ios::binary | ios::app);
	
	if (FileStream.good()) {
		
		FileStream.seekp(0, ios::end);
		
		FileStream.write((char *)&instance, sizeof(structure));
		
		// Update Write position
		writePosition = FileStream.tellp();
		
		return true;
		
	} else {
		// Close off Filestream
		FileStream.close();
		
		cerr << Error::open << endl;
		return false;
	}
	
}

template <typename structure>
bool File<structure>::update(structure& newInstance)
{
	
	FileStream.open(FileName, ios::out | ios::in | ios::binary);
	
	if (FileStream.good()) {
		
		// Position write marker in the last read location
		// Use read.() and read until file is found
		FileStream.seekp(readPosition - sizeof(structure), ios::beg);
		
		FileStream.write((char *)&newInstance, sizeof(structure));
		
		// Update write position
		writePosition = FileStream.tellp();
		
		// Close off Filestream
		FileStream.close();
		
		return true;
		
	} else {
		// Close off Filestream
		FileStream.close();
		
		cerr << Error::open << endl;
		return false;
	}
}

// Accessors
template <typename structure>
bool File<structure>::getEOFStatus()
{
	return IsEOF;
}

template <typename structure>
long long File<structure>::getPositionOfFile(bool read)
{
	if (read) {
		return readPosition;
	} else {
		return writePosition;
	}
}

template <typename structure>
void File<structure>::setPositionOfFile(long long position, bool read)
{
	if (read) {
		readPosition = position;
	} else {
		readPosition = position;
	}
}

template <typename structure>
void File<structure>::resetEOFFlag()
{
	IsEOF = false;
}

/*
 * Employee Class Implementation
 */

Employee::Employee() {};

Employee::Employee(const char *fileName)
{
	// Intstantiate to Heap
	file = new File<EmployeeData>(fileName);
	
	data.IDNumber = -1;
	strcpy(data.firstName, "");
	strcpy(data.lastName, "");
	data.hourlyPayRate = 0;
}

Employee::~Employee()
{
	delete file;
}

bool Employee::addEmployee()
{
	bool success = false, duplicate = false;
	EmployeeData Temp = {0, 0, 0, 0};
	
	// Search from begining
	file->setPositionOfFile(0, true);
	file->resetEOFFlag();
	
	while (!file->getEOFStatus()) {
		
		long long lastKnownPosition = file->getPositionOfFile(true);
		cout << "last pos:  " << lastKnownPosition << endl;
		success = file->read(Temp, lastKnownPosition, true);
		
		if (!success) {
			cerr << "{File IO Error}" << endl;
			return false;
		}
		cout << "Id in file: " << Temp.IDNumber << " | " << "Input ID: " << data.IDNumber << endl;
		if (Temp.IDNumber == data.IDNumber) {
			duplicate = true;
			break;
		}
	}
	
	if (!duplicate) {
		success = file->write(data);
		
		if (!success) {
			cerr << "{File IO Error}" << endl;
			return false;
		}
		
		return true;
	} else {
		return false;
	}
	
}

bool Employee::searchEmployee(int UserID)
{
	
	bool success = false, found = false;
	
	// Search from begining
	file->setPositionOfFile(0, true);
	file->resetEOFFlag();
	
	while (!file->getEOFStatus()) {
		
		long long lastKnownPosition = file->getPositionOfFile(true);
		success = file->read(data, lastKnownPosition, true);
		
		if (data.IDNumber == UserID) {
			found = true;
			break;
		}
	}
	

	return found;
	
}

/**
 * The current instance of data in employee has the new employee information
 * UserID selects from the file where the data record is, and will replace
 * with current instance (new data)
 * @param {int} UserID
 */
bool Employee::updatePay(int UserID, double wage)
{
	// Local Vars
	bool success = false, duplicate = false;
	EmployeeData tempOld;
	
	// Search from begining
	file->setPositionOfFile(0, true);
	file->resetEOFFlag();
	
	// Search for employee and Store into old User
	while (!file->getEOFStatus()) {
		
		long long lastKnownPosition = file->getPositionOfFile(true);
		success = file->read(tempOld, lastKnownPosition, true);
		
		if (!success) {
			cerr << "{File IO Error}" << endl;
			return false;
		}
		
		if (tempOld.IDNumber == UserID) {
			duplicate = true;
			break;
		}
	}
	
	if (duplicate) {
		// Update data instance
		data.IDNumber = UserID;
		data.hourlyPayRate = wage;
		
		// Write to the last read position
		success = file->update(data);
		
		if (!success) {
			cerr << "{File IO Error}" << endl;
			return false;
		}
		
		return true;
		
	} else {
		return false;
	}
	
}

ostream& operator<<(ostream &output, const Employee &employee)
{
	
	output << "Employee ID: " << employee.data.IDNumber << endl
	<< "First Name: " << employee.data.firstName << endl
	<< "Last Name: " << employee.data.lastName << endl
	<< "Pay Rate/Hour: " << employee.data.hourlyPayRate << endl;
	
	return output;
}

istream& operator>>(istream &input, Employee &employee)
{
	// Enter everything but Employee ID
	// This needs a check
	cout << "Employee ID: ";
	input >> employee.data.IDNumber;
	cout << "First Name: ";
	input >> employee.data.firstName;
	cout << "Last Name: ";
	input >> employee.data.lastName;
	cout << "Pay Rate/Hour: ";
	input >> employee.data.hourlyPayRate;
	
	return input;
}

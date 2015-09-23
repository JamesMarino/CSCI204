/*------------------------------------------------------
 * Student's Name: James Marino
 * Student's email address: jm617@uow.edu.au
 * Laboratory group: CL/03 Friday 15:30
 * Purpose of this assignment:
 * Construct a doubley linked list, including iterator
 * Knowledge and use of the internals and workings of
 * containers
 -------------------------------------------------------*/

#include "Account.h"
using namespace std;

const char Account::COMMA = ',';
const char Account::NEW_LINE = '\n';
const char Account::CARRIAGE_RETURN = '\r';
const char Account::EMPTY_CHAR = ' ';
const char Account::NULL_BYTE = '\0';
const string Account::EMPTY_STRING = "";

Account::Account()
{
	AccountNumber = 0;
	initString(FullName, NAME_SIZE);
	Sex = NULL_BYTE;
	DOB.setDate();
	initString(Address, ADDRESS_SIZE);
	Balance = 0.00;
}

Account::Account(const Account &existing)
{
	AccountNumber = existing.AccountNumber;
	strcpy(FullName, existing.FullName);
	Sex = existing.Sex;
	DOB = existing.DOB;
	strcpy(Address, existing.Address);
	Balance = existing.Balance;
}

const Account& Account::operator=(const Account &existing)
{
	AccountNumber = existing.AccountNumber;
	strcpy(FullName, existing.FullName);
	Sex = existing.Sex;
	DOB = existing.DOB;
	strcpy(Address, existing.Address);
	Balance = existing.Balance;
	
	return (*this);
}

void Account::initString(char clearString[], int length)
{
	for (int i = 0; i < length; i++) {
		clearString[i] = NULL_BYTE;
	}
}

void Account::reset()
{
	AccountNumber = 0;
	initString(FullName, NAME_SIZE);
	Sex = EMPTY_CHAR;
	DOB.setDate();
	initString(Address, ADDRESS_SIZE);
	Balance = 0.00;
}

bool Account::empty()
{
	if ((AccountNumber == 0) &&
		(FullName[0] == EMPTY_CHAR) &&
		(Sex == EMPTY_CHAR) &&
		(Address[0] == EMPTY_CHAR) &&
		(Balance == 0.00)) {
		return true;
	} else {
		return false;
	}
}

const char* Account::getFullName()
{
	return FullName;
}

bool Account::operator<=(const Account &rhs) const
{
	if (this->AccountNumber <= rhs.AccountNumber) {
		return true;
	} else {
		return false;
	}
}

bool Account::operator>=(const Account &rhs) const
{
	if (this->AccountNumber >= rhs.AccountNumber) {
		return true;
	} else {
		return false;
	}
}

bool Account::operator<(const Account &rhs) const
{
	if (this->AccountNumber < rhs.AccountNumber) {
		return true;
	} else {
		return false;
	}
}

bool Account::operator>(const Account &rhs) const
{
	if (this->AccountNumber > rhs.AccountNumber) {
		return true;
	} else {
		return false;
	}
}

istream& operator>>(istream &stream, Account &input)
{
	// Initialise temporary String to read into
	string wholeLine = Account::EMPTY_STRING;
	string temp[6];
	
	size_t currentPosition = 0;
	int counter = 0;
	
	// Read in the whole line
	getline(stream, wholeLine, Account::NEW_LINE);
	
	// Test for carriage return
	if (wholeLine[0] != Account::CARRIAGE_RETURN) {
		
		// Test for
		if (wholeLine != Account::EMPTY_STRING) {
			
			// Delimit
			while ((currentPosition = wholeLine.find(Account::COMMA)) != std::string::npos) {
				
				temp[counter] = wholeLine.substr(0, currentPosition);
				wholeLine.erase(0, currentPosition + 1);
				
				counter += 1;
			}
			
			// For string to {other} conversion
			// CC is C++98
			char *tempChar;
			
			// Slot in remaining
			temp[5] = wholeLine;
			// Erase the cariage return (+1 for actual length)
			size_t length5 = temp[5].length() + 1;
			temp[5].erase(length5 - 2, length5);
			
			// Account Number
			// input.AccountNumber = stol(temp[0]);
			// Must use 'strtol' C++11 not supported
			input.AccountNumber = strtol(temp[0].c_str(), &tempChar, 0);
			
			// FullName
			strcpy(input.FullName, temp[1].c_str());
			
			// Sex
			// Get first character of string
			input.Sex = temp[2][0];
			
			// DOB
			input.DOB.setDate(temp[3]);
			
			// Address
			strcpy(input.Address, temp[4].c_str());
			
			// Balance
			// input.Balance = stod(temp[5]);
			// Must use 'strtod' C++11 not supported
			input.Balance = strtod(temp[5].c_str(), &tempChar);
			
		} else {
			input.reset();
		}
	} else {
		input.reset();
	}
	
	return stream;
}

ostream& operator<<(ostream &stream, const Account &output)
{
	string DOBString = output.DOB.toString();
	
	stream
	<< setfill('0') << right << setw(10) << output.AccountNumber << ' '
	<< setfill(' ') << left << setw(20) << output.FullName << ' '
	<< setfill(' ') << left << setw(3) << output.Sex << ' '
	<< DOBString << ' '
	<< setfill(' ') << left << setw(41) << output.Address << ' '
	<< Account::currency(10, 2) << output.Balance << endl;
	
	return stream;
}

Account::currency::currency()
{
	width = 0;
	precision = 0;
}

Account::currency::currency(int wid, int prec)
{
	width = wid;
	precision = prec;
}

ostream& operator<<(ostream &stream, const Account::currency &output)
{
	stream << "$";
	stream << setfill('0');
	stream << right;
	stream << fixed;
	stream << setw(output.width);
	stream << setprecision(output.precision);
	stream << showpoint;
	
	return stream;
}

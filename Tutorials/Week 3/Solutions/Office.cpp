// Office.cpp
// Static field holds rent due date for an office - rents are due on the 1st

#include <iostream>
#include <string>

using namespace std;

class Office
{
	private:
		int officeNum;
		string tenant;
		int rent;
		static int rentDueDate;
	public:
		void setOfficeData(int, string, int);
		static void showRentDueDate();
		void showOffice();
};

int Office::rentDueDate = 1;

void Office::setOfficeData (int num, string occupant, int rent)
{
	this->officeNum = num;
	this->tenant = occupant;
	this->rent = rent;
}

void Office::showOffice ()
{
	cout << "Office " << this->officeNum << " is occupied by " << this->tenant << "." << endl;
	cout << "The rent, $" << this->rent << " is due on day " << rentDueDate << " of the month." << endl;
	cout << "ALL rents are due on the day " << rentDueDate << " of the month." << endl;
}

void Office::showRentDueDate ()
{
	cout << "All rents are due on day " << rentDueDate << " of the month." << endl;
}

int main()
{
	Office myOffice;
	myOffice.setOfficeData(234, "Dr. Smith", 450);
	Office::showRentDueDate();
	myOffice.showOffice();
}

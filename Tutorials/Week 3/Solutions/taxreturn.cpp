// taxreturn.cpp

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class TaxReturn
{
private:
	int TaxID;
	string LastName;
	string FirstName;
	int AnnualIncome;
	int Dependants;
	int TaxOwed;
	static double TaxRates[4][3];
public:
	void displayTaxTable();
	void setAll(int, string, string, int, int);
	void calculateTax();
	void display();
};

double TaxReturn::TaxRates[4][3] = {
	{0.10, 0.08, 0.07},
	{0.12, 0.11, 0.09},
	{0.18, 0.15, 0.13},
	{0.25, 0.22, 0.19}
	
};

void TaxReturn::displayTaxTable()
{
	// Inform the user
	cout << "Current Tax Table Below:" << endl;
	cout << setfill('-') << setw(25) << '-' << endl;
	cout << setfill(' ');
	
	// Iterate
	for (int i = 0; i < 4; i++) {
		cout << setw(0);
		for (int j = 0; j < 3; j++) {
			cout << TaxRates[i][j];
			cout << setw(10);
		}
		
		// Print new line each row
		cout << endl;
	}
}

void TaxReturn::setAll(int taxID, string firstName, string lastName, int annualIncome, int dependants)
{
	this->TaxID = taxID;
	this->FirstName = firstName;
	this->LastName = lastName;
	this->AnnualIncome = annualIncome;
	this->Dependants = dependants;
}

void TaxReturn::calculateTax()
{
	const int TAX_BRACKET_MAX_1 = 10000;
	const int TAX_BRACKET_MAX_2 = 30000;
	const int TAX_BRACKET_MAX_3 = 60000;
	
	int row = 0;
	int column = 0;
	
	// Get the row for income range
	if (this->AnnualIncome < TAX_BRACKET_MAX_1) {
		row = 0;
	} else if ((this->AnnualIncome > TAX_BRACKET_MAX_1) && (this->AnnualIncome < TAX_BRACKET_MAX_2)) {
		row = 1;
	} else if ((this->AnnualIncome > TAX_BRACKET_MAX_2) && (this->AnnualIncome < TAX_BRACKET_MAX_3)) {
		row = 2;
	} else {
		row = 3;
	}
	
	// Get the column, switch on dependencies
	switch (this->Dependants) {
		case 0:
			column = 0;
			break;
			
		case 1:
			column = 1;
			break;
			
		default:
			column = 2;
			break;
	}
	
	// Calculate Tax
	this->TaxOwed = this->AnnualIncome * this->TaxRates[row][column];
	
}

void TaxReturn::display()
{
	cout << "Name: " << this->FirstName << " " << this->LastName << endl
			<< "Tax ID: " << this->TaxID << endl
			<< "Annual Income: " << this->AnnualIncome << endl
			<< "Dependants: " << this->Dependants << endl
			<< "Tax Owing: " << this->TaxOwed << endl;
}

int main()
{
	TaxReturn taxReturns[3];
	int TaxID;
	string LastName;
	string FirstName;
	int AnnualIncome;
	int Dependants;
	
	for (int i = 0; i < 3; i++) {
		cout << "What's Your Tax ID? ";
		cin >> TaxID;
		cout << "What's Your Name (First and Last)? ";
		cin >> FirstName >> LastName;
		cout << "What's You Annual Income? ";
		cin >> AnnualIncome;
		cout << "Any Dependants? How Many? ";
		cin >> Dependants;
		cout << endl;
		
		taxReturns[i].setAll(TaxID, FirstName, LastName, AnnualIncome, Dependants);
		taxReturns[i].calculateTax();
		taxReturns[i].display();
		cout << endl;
	}
	
    return 0;
}

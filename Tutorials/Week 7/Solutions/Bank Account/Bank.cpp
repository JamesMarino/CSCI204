#include "Bank.h"

//*********************************
// Class: Savings | Implementation
//*********************************

Saving::Saving()
{
	CardNumber = 0;
}

void Saving::setValues(long long CardNumber)
{
	this->CardNumber = CardNumber;
}

long double Saving::calculateInterest(long double Balance)
{
	return Balance * ((0.3/100) / 360) * 30;;
}

//*********************************
// Class: Credit | Implementation
//*********************************

Credit::Credit()
{
	CardNumber = 0;
	Limitation = 0;
	RepaymentDue = "";
}

void Credit::setValues(long long CardNumber, long Limitation, string RepaymentDue)
{
	this->CardNumber = CardNumber;
	this->Limitation = Limitation;
	this->RepaymentDue = RepaymentDue;
}

long double Credit::calculateInterest(long double Balance)
{
	return Balance * ((12.5/100) / 360) * 10;
}

//*********************************
// Class: Account | Implementation
//*********************************

Account::Account()
{
	BSB = 0;
	AccountNumber = 0;
	Address = "";
	PhoneNumber = 0;
	Balance = 0;
	Interest = 0;
	AccountType = "";
	FullName = "";
	
}

void Account::setValues(long BSB, long AccountNumber, string FullName, string Address, long PhoneNumber, long double Balance, long long CardNumber, long Limitation, string RepaymentDue)
{
	// Store Values regardless of account type
	this->BSB = BSB;
	this->AccountNumber = AccountNumber;
	this->Address = Address;
	this->PhoneNumber = PhoneNumber;
	this->Balance = Balance;
	this->FullName = FullName;
	
	// Check either credit or savings account
	if (Limitation == 0 && RepaymentDue == "") {
		// It is a savings account
		this->savings.setValues(CardNumber);
		this->AccountType = "Savings";
	} else {
		// It is a credit account
		this->credit.setValues(CardNumber, Limitation, RepaymentDue);
		this->AccountType = "Credit";
	}
	
}

long long Account::getCardNumber()
{
	if (this->AccountType == "Savings") {
		return savings.CardNumber;
	} else {
		return credit.CardNumber;
	}
}

void Account::calculateInterest()
{
	if (this->AccountType == "Savings") {
		Interest = savings.calculateInterest(Balance);
	} else {
		Interest = credit.calculateInterest(Balance);
	}
	
	Balance += Interest;
	
}

void Account::displayAccountDetails()
{
	cout << "BSB#: " << BSB << ", "
		<< "Account#: " << AccountNumber << ", "
		<< FullName << ", "
		<< AccountType << ", "
		<< "Card#: " << getCardNumber() << ", "
		<< "Balance: $" << Balance << " CR, "
		<< "Interest: $" << Interest
		<< endl;
	
}

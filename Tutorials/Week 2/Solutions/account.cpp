#include <iostream>
using namespace std;

class Account
{
	private:
		long AccountNumber;
		char * AccountType;
		float Balance;
	
	public:
		// Constructor / Destructor
		Account();
		~Account();
	
		// Contructor helper
		void setAccount(long, char[], float);
		
		// Methods
		bool withdraw (float AmountToRemove);
		
		// Acess to properties
		char * getAccType ();
		float getBalance ();
		long getNumber ();
};

// Class Account Implementation
Account::Account()
{
	this->AccountType = new char[8];
	strcpy(this->AccountType, "Spending");
	this->Balance = 12;
	this->AccountNumber = 923456784;
}

Account::~Account()
{
	delete this->AccountType;
}

// Contructor helper
void Account::setAccount(long AccountNumber, char AccountType[], float Balance)
{
	this->AccountNumber = AccountNumber;
	this->AccountType = AccountType;
	this->Balance = Balance;
}

// Methods
bool Account::withdraw (float AmountToRemove)
{
	// Initialise
	float difference = 0.0;
	
	difference  = this->Balance - AmountToRemove;
	
	if (difference < 0) {
		return false;
	} else {
		this->Balance -= AmountToRemove;
	}
	
	return true;
}

// Acess to properties
char * Account::getAccType ()
{
	return this->AccountType;
}

float Account::getBalance ()
{
	return this->Balance;
}

long Account::getNumber ()
{
	return this->AccountNumber;
}

int main() {
	
	// Instantiate
	float transferAmount = 0.0;
	
	Account * account;
	account = new Account;
	
	// Take user input
	cout << "How much would you like to withdraw from your " << account->getAccType() << " ($" << account->getBalance() << ")" << "? $";
	cin >> transferAmount;
	cout << endl;
	
	// Check
	if (account->withdraw(transferAmount)) {
		cout << "Transfer of $" << transferAmount << " was successful." << endl << "You have $" << account->getBalance() << " remaining.";
	} else {
		cout << "You do not have enough funds available to tranfer $" << transferAmount << endl << "You have only $" << account->getBalance() << " in your account.";
	};
	
	cout << endl << endl;
	cout << "Account Details:" << endl
			<< "Account Type: " << account->getAccType() << endl
			<< "Balance: " << account->getBalance() << endl
			<< "Account Number: " << account->getNumber() << endl;
	
	// Delete
	delete account;
	
    return 0;
}

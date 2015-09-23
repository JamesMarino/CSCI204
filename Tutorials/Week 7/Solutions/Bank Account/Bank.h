#include <iostream>
#include <string>

using namespace std;

class Saving;
class Credit;
class Account;

class Saving {
	// Make savings accessable to account
	friend class Account;
	
	private:
		long long CardNumber;
	public:
		Saving();
		long double calculateInterest(long double);
		void setValues(long long);
	
};

class Credit {
	// Make Credit accessible to account
	friend class Account;
	
	private:
		long long CardNumber;
		long Limitation;
		string RepaymentDue;
	public:
		Credit();
		long double calculateInterest(long double);
		void setValues(long long, long, string);
	
};

class Account {
	private:
		string Address;
		string FullName;
		string AccountType;
	
		long BSB;
		long AccountNumber;
		long PhoneNumber;
		long double Balance;
		long double Interest;
	
		// Account Types Within
		Saving savings;
		Credit credit;
	public:
		Account();
		void setValues(long, long, string, string, long, long double, long long, long = 0, string = "");
		long long getCardNumber();
		void calculateInterest();
		void displayAccountDetails();
};

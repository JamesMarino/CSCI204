#include <iostream>
#include <string>

using namespace std;

// Forward Declaration
class City;
class Customer;

class City
{
	private:
		string CityName;
		string State;
		int PostCode;
	public:
		City ();
		void set (string, string, int);
		void display ();
};

class Customer
{
	private:
		City city;
		int IDNumber;
	public:
		Customer (int, string, string, int);
		void display ();
};

// Class Customer Details

Customer::Customer (int IDNumber, string CityName, string State, int PostCode)
{
	this->city.set(CityName, State, PostCode);
	this->IDNumber = IDNumber;
}

void Customer::display()
{
	cout << "Customer :: ID Number: " << this->IDNumber << endl;
	
	// Call City display()
	this->city.display();
	
	// QUESTION 5.
	/* 
	 * Attempt to access Post Code field in City
	 * this->city.PostCode;
	 *
	 * You Can't
	 * 'PostCode' is a private member of 'City'
	 */
	
}

// Class City Details

City::City ()
{
	this->CityName = "";
	this->State = "";
	this->PostCode = 0;
}

void City::set (string CityName, string State, int PostCode)
{
	this->CityName = CityName;
	this->State = State;
	this->PostCode = PostCode;
}

void City::display()
{
	cout << "City :: Post Code: " << this->PostCode << endl;
	cout << "City :: Name: " << this->CityName << endl;
	cout << "City :: State: " << this->State << endl;
}

int main ()
{
	
	Customer aCust(1572, "Wollongong", "NSW", 2500);
	aCust.display();
	
	return 0;
}

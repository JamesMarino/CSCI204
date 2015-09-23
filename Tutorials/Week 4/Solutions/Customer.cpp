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
		City (string, string, int);
		void printDetails (Customer&);
};

class Customer
{
	private:
		int IDNumber;
		int PostCode;
		
	public:
		Customer (int = 0, int = 0);
		friend void City::printDetails(Customer&);
};

// Class Customer Details

Customer::Customer (int IDNumber, int PostCode)
{
	this->IDNumber = IDNumber;
	this->PostCode = PostCode;
}

// Class City Details

City::City (string CityName, string State, int PostCode)
{
	this->CityName = CityName;
	this->State = State;
	this->PostCode = PostCode;
}

void City::printDetails(Customer& customer)
{
	cout << "Customer :: ID Number: " <<  customer.IDNumber << endl;
	cout << "Customer :: Post Code: " << customer.PostCode << endl;
	cout << "City :: Name: " << this->CityName << endl;
	cout << "City :: State: " << this->State << endl;
}

int main ()
{
	
	Customer customer(6960, 2500);
	City city("Wollongong", "NSW", 2500);
	
	city.printDetails(customer);
	
	
	return 0;
}

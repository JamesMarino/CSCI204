#include "Bank.h"
using namespace std;

int main() {
	
	Account Alice;
	Account Bob;
	
	Alice.setValues(123456, 12345678, "Alice", "1 Northfields Avenue Wollongong", 1234567, 1000.00, 1234567890123456);
	Bob.setValues(123123, 12341234, "Bob", "20 Moore Street, North Wollongong", 12341234, 1000.00, 987654321123456, 2000, "20 April 2014");
	
	Alice.calculateInterest();
	Bob.calculateInterest();
	
	Alice.displayAccountDetails();
	Bob.displayAccountDetails();
	
    return 0;
}

/*
 * Changes Are Commented below
 */

// IOStream is added as a header
#include <string>
#include <iostream>

using namespace std;

// Class name is incorrect
class BirthdayCake
{
	private:
		// Datatype changed appropriately, int to char
		int orderNumber;
		string cakeFlavour;
		string icingType;
		int numCandles;
	public:
		// Function definition updated, included int data type at start
		BirthdayCake (int, string = "chocolate", string = "butter cream", int = 1);
		void displayBirthdayCake ();
};

BirthdayCake::BirthdayCake (int orderNumber, string cakeFlavour, string icing, int candles)
{
	// Uses this to refrence instance of class
	// Removes stand alone refrences to properties and "that"
	this->orderNumber = orderNumber;
	this->cakeFlavour = cakeFlavour;
	this->icingType = icing;
	this->numCandles = candles;
}

// Global function declared, updated to class function
void BirthdayCake::displayBirthdayCake ()
{
	// Cleaned up output
	cout << "Order #" << this->orderNumber << " " << this->cakeFlavour << " cake with "
			<< this->icingType << " icing and " << this->numCandles;
	
	// Changed logical error, when single candle (numCandles == 1)
	if (this->numCandles == 1)
		cout << " candle";
	else
		cout << " candles";
	
	cout << endl;
}

int main()
{
	
	// Cleaned and updated for appropriate output
	
	cout << "Cakes are white with butter cream icing and "
		<< "1 candle unless otherwise indicated" << endl;
	
	BirthdayCake a (111, "chocolate", "whipped cream", 8);
	BirthdayCake b (222, "yellow", "chocolate");
	BirthdayCake c (333, "banana");
	BirthdayCake d (444);
	
	a.displayBirthdayCake();
	b.displayBirthdayCake();
	c.displayBirthdayCake();
	d.displayBirthdayCake();
}


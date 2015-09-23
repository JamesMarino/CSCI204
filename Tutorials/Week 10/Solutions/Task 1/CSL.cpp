#include <iostream>

// Added namespace
using namespace std;

/*
 * Comma Seperated List - Class
 */
template<typename T>
class CSL
{
private:
	int size;
	T *list;
public:
	CSL(T*, int);
	~CSL();
	void showList();
};

// Fixed the CSL constructor
template<typename T>
CSL<T>::CSL(T *instance, int length)
{
	// Initialise Variables
	size = length;
	
	// Copy In the pointer
	list = new T[length];
	
	for (int i = 0; i < size; i++) {
		list[i] = instance[i];
	}
}

// Added Destructor
template<typename T>
CSL<T>::~CSL()
{
	delete [] list;
}

template<typename T>
void CSL<T>::showList()
{
	cout << "Comma separated list: " << endl;
	
	for (int x = 0; x < size; x++) {
		cout << list[x];
		
		// Removed size +1, placed -1 instead
		if (x != (size - 1)) {
			cout << ", ";
		}
	}
	
	cout << endl << endl;
}

/*
 * Class Video
 */
class Video
{
friend ostream& operator<<(ostream&, const Video&);
	
private:
	string title;
	double price;
public:
	void setVideo(string, double);
};

// Cleaned up
// Variable names
void Video::setVideo(string videoTitle, double videoPrice)
{
	title = videoTitle;
	price = videoPrice;
}

// Cleaned Up
// Return an Ostream
ostream& operator<<(ostream& output, const Video &aVideo)
{
	output << aVideo.title << " sells for $" << aVideo.price;
	return output;
}

/*
 * Class Customer
 */
class Customer
{
friend ostream& operator<<(ostream&, const Customer&);
	
private:
	string name;
	double balanceDue;
public:
	void setCustomer(string, double);
};

// Cleaned up
// Variable names
void Customer::setCustomer(string customerName, double price)
{
	name = customerName;
	balanceDue = price;
}

// Cleaned up
// Variable names
ostream& operator<<(ostream& output, const Customer &aCustomer)
{
	output << aCustomer.name << " owes $" << aCustomer.balanceDue;
	return output;
}

int main()
{
	// Set Locals
	int CSL_Size;
	int someInts[] = {12, 34, 55, 77, 99};
	double someDoubles[] = {11.11, 23.44, 44.55, 123.66};
	
	// Instances
	Video someVideos[2];
	Customer someCustomers[6];
	
	// Set Values
	someVideos[0].setVideo("Bob the Builder", 12.50);
	someVideos[1].setVideo("Thomas the Tank Engine", 15.00);
	
	someCustomers[0].setCustomer("Zaps", 23.55);
	someCustomers[1].setCustomer("Martin", 155.77);
	someCustomers[2].setCustomer("Fine", 333.88);
	someCustomers[3].setCustomer("Torrence", 123.99);
	someCustomers[4].setCustomer("Richard", 20.06);
	// Most time spent debuging on such stupid mistake:
	// change 4 to 5
	someCustomers[5].setCustomer("Curtin", 56999.19);
	
	// Store the sizes
	CSL_Size = sizeof(someInts)/sizeof(someInts[0]);
	CSL<int> CSL_Integers(someInts, CSL_Size);
	
	// Fixed double in type
	CSL_Size = sizeof(someDoubles)/sizeof(someDoubles[0]);
	CSL<double> CSL_Doubles(someDoubles, CSL_Size);
	
	CSL_Size = sizeof(someVideos)/sizeof(someVideos[0]);
	CSL<Video> CSL_Videos(someVideos, CSL_Size);
	
	CSL_Size = sizeof(someCustomers)/sizeof(someCustomers[0]);
	CSL<Customer> CSL_Customers(someCustomers, CSL_Size);
	
	// Added parentheses
	CSL_Integers.showList();
	CSL_Doubles.showList();
	CSL_Videos.showList();
	CSL_Customers.showList();
	
	return 0;
}

#include "Bag.h"
#include "Bag.cpp"
using namespace std;

int main()
{
	
	/********************
	 Integers
	 *******************/
	{
		int elementSize = 0, element = 0;
		
		/* Bag 1 */
		// How big?
		cout << "Number of integers for an integer Bag 1: ";
		cin >> elementSize;
		
		// Intstantiate
		MYLIB::Bag<int> Bag1(elementSize);
		
		// Input
		cin >> Bag1;
		// Display
		cout << "The First Integer bag contains: ";
		cout << Bag1;
		cout << endl;
		
		/* Bag 2 */
		elementSize = 0;
		
		cout << "Number of integers for an integer Bag 2: ";
		cin >> elementSize;
		
		MYLIB::Bag<int> Bag2(elementSize);
		
		cin >> Bag2;
		cout << "The Second Integer bag contains: ";
		cout << Bag2;
		cout << endl;
		
		/* Combine */
		MYLIB::Bag<int> Bag3;
		cout << "Combine two integer bags: ";
		
		// Add
		Bag3 = Bag1 + Bag2;
		
		// Display Output
		cout << Bag3;
		cout << endl;
		
		/* Removal */
		for (int i = 0; i < 2; i++) {
			cout << "Input the element that needs to be removed: ";
			cin >> element;
			
			// Remove
			Bag3.remove(element);
			
			cout << "After the element " << element << " has been removed, the bag contains: "
			<< Bag3
			<< endl;
		}
	}
	
	/********************
	 Doubles
	 *******************/
	
	{
		double elementSize = 0, element = 0;
		
		/* Bag 1 */
		// How big?
		cout << "Number of doubles for an double Bag 1: ";
		cin >> elementSize;
		
		// Intstantiate
		MYLIB::Bag<double> Bag1(elementSize);
		
		// Input
		cin >> Bag1;
		// Display
		cout << "The First Double bag contains: ";
		cout << Bag1;
		cout << endl;
		
		/* Bag 2 */
		elementSize = 0;
		
		cout << "Number of Double for an integer Bag 2: ";
		cin >> elementSize;
		
		MYLIB::Bag<double> Bag2(elementSize);
		
		cin >> Bag2;
		cout << "The Second Double bag contains: ";
		cout << Bag2;
		cout << endl;
		
		/* Combine */
		MYLIB::Bag<double> Bag3;
		cout << "Combine two Double bags: ";
		
		// Add
		Bag3 = Bag1 + Bag2;
		
		// Output
		cout << Bag3;
		cout << endl;
		
		/* Removal */
		for (int i = 0; i < 2; i++) {
			cout << "Input the element that needs to be removed: ";
			cin >> element;
			
			// Remove
			Bag3.remove(element);
			
			cout << "After the element " << element << " has been removed, the bag contains: "
			<< Bag3
			<< endl;
		}
	}
	
	return 0;
}

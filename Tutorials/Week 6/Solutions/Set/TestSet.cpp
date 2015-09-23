#include "Set.h"

using namespace std;

int main()
{
	
	int setLengths[] = {0, 0};
	
	// Build the sets
	for (int i = 0; i < 2; i++) {
		cout << "Input the number of elements for Set " << i + 1 << ": ";
		cin >> setLengths[i];
	}
	
	// Create Sets
	Set setUnion, setMinus, setIntersection;
	Set set1(setLengths[0]), set2(setLengths[1]);
	
	cout << "Input Elements for Set 1: ";
	cin >> set1;
	
	cout << "Input Elements for Set 2: ";
	cin >> set2;
	
	// Dislpay sets
	cout << "Set 1 = ";
	cout << set1;
	
	cout << "Set 2 = ";
	cout << set2;
	
	// Add Sets Togethor (Union)
	setUnion = set1 + set2;
	cout << "UNION: Set1 + Set2 = ";
	cout << setUnion;
	
	// Minus sets (Minus)
	setMinus = set1 - set2;
	cout << "MINUS: Set1 - Set2 = ";
	cout << setMinus;
	
	// &amp sets (Intersection)
	setIntersection = set1 & set2;
	cout << "INTERSECTION: Set1 & Set2 = ";
	cout << setIntersection;
	
    return 0;
}

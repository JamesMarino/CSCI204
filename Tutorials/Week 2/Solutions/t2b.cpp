#include <iostream>
#include <math.h>
using namespace std;

// Function definitions
void inputNumberOfChairsForTable (int &);
void inputSurfaceAreaForTable (int &);
void inputColourOfCushionsOnChairSeats (char[]);
void inputWoodUsedToBuildTable (char &);
void calculatePrice (float &, int, int, char);
void displayPriceOfPurchase (float);
void displayDetailsOfPurchase (int, int, char[], char);

int main() {
	
	// Initialise varibales
	int NumberOfChairs = 0, SurfaceArea = 0;
	char ColourOfCushions[64], WoodUsed;
	float price = 0.0;
	
	// Functions
	inputNumberOfChairsForTable(NumberOfChairs);
	inputColourOfCushionsOnChairSeats(ColourOfCushions);
	inputSurfaceAreaForTable(SurfaceArea);
	inputWoodUsedToBuildTable(WoodUsed);
	
	// New line
	cout << '\n';
	
	// Calculate Price
	calculatePrice(price, NumberOfChairs, SurfaceArea, WoodUsed);
	
	// Output to user
	displayDetailsOfPurchase(NumberOfChairs, SurfaceArea, ColourOfCushions, WoodUsed);
	displayPriceOfPurchase(price);
	
	return 0;
}

void inputNumberOfChairsForTable (int &numberOfChairs)
{
	numberOfChairs = 0;
	
	cout << "Input the Number of Chairs for the Table: ";
	cin >> numberOfChairs;
	
}

void inputSurfaceAreaForTable (int &surfaceArea)
{
	surfaceArea = 0;
	
	cout << "Input the Surface Area for the Table: ";
	cin >> surfaceArea;
	
}

void inputColourOfCushionsOnChairSeats (char colour[])
{
	// Does this have to be dynamically allocated
	cout << "Input the Colour of Cushions for Table: ";
	cin >> colour;
}

void inputWoodUsedToBuildTable (char &wood)
{
	// Initialise
	wood = '\0';
	
	// Take user input
	cout << "Enter the wood used to build the table." << endl;
	cout << "m for Mahogany, o for Oak, or p for Pine: ";
	cin >> wood;
	
	while (!(wood == 'm' ||
			 wood == 'o' ||
			 wood == 'p')) {
		cout << "Please Enter a Valid Input 'm', 'o' or 'p': ";
		cin >> wood;
	}
	
}

void calculatePrice (float &finalPrice, int numberOfChairs, int surfaceArea, char typeOfWood)
{
	// Initialise
	int x = 0, S = 0, N = 0;
	finalPrice = 0.0;
	
	// Find x
	switch (typeOfWood) {
		case 'm':
			x = 200;
			break;
			
		case 'o':
			x = 150;
			break;
			
		case 'p':
			x = 95;
			break;
	}
	
	// Assign S and N
	S = surfaceArea;
	N = numberOfChairs;
	
	// Formula:
	// x(S + 1⁄2 N)
	// Where
		// x = $200, $150, $95 respectively for m, o and p
		// S = surface area
		// N = chairs
	finalPrice = x * (S + (0.5 * N));
	
}

void displayDetailsOfPurchase (int chairAmount, int surfaceArea, char cushionColour[], char typeOfWood)
{
	float squareRootSurfaceArea = sqrt(surfaceArea);
	
	// Find long form wood type
	switch (typeOfWood) {
		case 'm':
			cout << "You have chosen a Mahogony table with:" << endl;
			break;
			
		case 'o':
			cout << "You have chosen a Oak table with:" << endl;
			break;
			
		case 'p':
			cout << "You have chosen a Pine table with:" << endl;
			break;
	}
	
	cout << "Dimensions " << squareRootSurfaceArea << " by "
	<< squareRootSurfaceArea
	<< " and " << chairAmount << " chairs with "
	<< cushionColour << " cushions." << endl;
	
	cout << endl;
	
}

void displayPriceOfPurchase (float price)
{
	cout << "Price of Purchase is: $" << price << endl;
	cout << endl;
}

/* 	------------------------------------------------------------
 * 	Student's Name: James Marino
 * 	Student's email address: jm617@uowmail.edu.au
 * 	Laboratory group: CL/03 Friday 15:30
 * 	Purpose of this assignment:
 *		Correct logical and syntactical errors. Changes are
 *		commented below.
 *	------------------------------------------------------------ */

/*	Global Changes:
 *	- Fixed indenting of structures
 *	- Various spacing / aesthetical design of code
 */

#include <iostream>
#include <string>

using namespace std;

//***************************************************
// 1st Class - "Painting"
//***************************************************

/*	Change:
 *	- char artist changed to datatype string
 *	- added getTitle() method
 *	- added default contructor
 */
class Painting
{
	protected:
		string title;
		string artist;
		int value;
	public:
		Painting();
		Painting(string, string = "");
		void showPainting();
		void setData();
	
		string getTitle();
		string getArtist();
};

Painting::Painting()
{
	// Initialise Values
	this->title = "";
	this->artist = "";
	this->value = 0;
}

/*	Change:
 *	- Fixed ambiguity in parameter names
 *	- Added data type for "painter"
 *	- Added this-> pointer to reduce ambiguity of assignment
 */
Painting::Painting(string name, string painter)
{
	this->title = name;
	this->artist = painter;
	this->value = 400;
}

/*	Change:
 *	- Scope resolution operator as ":" not "::"
 *	- Changed name acting as class property to "artist" class propety
 *	- Updated value
 *	- Input for artist repeated twice
 */
void Painting::setData()
{
	cout << "Enter the painting's title: ";
	cin >> this->title;
	cout << "Enter artist name: ";
	cin >> this->artist;
	cout << endl;
	
	// updated value to 400
	this->value = 400;
}

/*	Change:
 *	- Method name not correct, changed to showPainting()
 *	- changed constant value string to class property instance
 *	- Added " by " contstant string
 *	- Added endl and $ sign to output
 */
void Painting::showPainting()
{
	cout << this->title << " by " << this->artist << " value $" << this->value << endl;
}

/*	Changes:
 *	- Return type to string
 *	- Returns artist property
 */
string Painting::getArtist()
{
	return this->artist;
}

string Painting::getTitle()
{
	return this->title;
}

//***************************************************
// 2nd Class - "FamousPainting" extends "Painting"
//***************************************************

/*	Change:
 *	- Extended the class FamousPainting from Painting
 *	- Semicolon at end of class missing
 *	- Added method "isPaintingFamous(Painting painting)"
 */
class FamousPainting : public Painting
{
	public:
		FamousPainting(string, string);
		bool isPaintingFamous();
};

/*	Change:
 *	- Corrected value of painting 25 to 25000
 */
FamousPainting::FamousPainting(string name, string painter) : Painting(name, painter)
{
	this->value = 25000;
}

/*	Change:
 *	- See bellow for more changes
 *	- Pass painting by reference, do not invoke copy contructor
 */
bool isPaintingFamous(Painting &painting)
{
	// Setup Local Vars
	// Deafult, assume not famous
	bool isFamous = false;
	const int NUM = 4;
	string artists[NUM] = {
		"Degas",
		"Monet",
		"Picasso",
		"Rembrandt"
	};
	
	// Changed to int, no need for char
	// Fixed arraym cause segmentation fault in CC not in clang/g++
	for (int x = 0; x < NUM; x++)
		// Use passed in data, update how array displays variable
		if (painting.getArtist() == artists[x])
			// If match, fame is true
			isFamous = true;
	
	return isFamous;
}

/*	Change:
 *	- Global for loop variable instantiations
 *	- See below for others
 */
int main()
{
	// Changed number of records, only 4
	const int NUM = 4;
	
	// Declare new paintings
	Painting pictures[NUM];

    for(int i = 0; i < NUM; ++i)
    {
		// Declare new instance
		Painting temp;
		
		// Set the data
		temp.setData();
		
		// Check if it is famous (to increase cost)
		if(isPaintingFamous(temp))
		{
			// Create a Famous painting
			FamousPainting tempFamous(temp.getTitle(), temp.getArtist());
			
			// Copy to the temporary class, default contructor should be fine
			temp = tempFamous;
		}
		
		// Added array index
       pictures[i] = temp;
	}
	
	// Cleaned up for loop
	for (int i = 0; i < NUM; i++)
		// Added index
		pictures[i].showPainting();
	
	// Return for main function
	return 0;
}

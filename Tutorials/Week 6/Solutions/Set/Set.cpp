#include "Set.h"

using namespace std;

Set::Set()
{	
	this->elements = NULL;
	this->elementSize = 0;
}

Set::Set(int arraySize)
{
	this->elementSize = arraySize;
	this->elements = new int[arraySize];
}

Set::~Set()
{
	if (this->elements == NULL)
		delete [] this->elements;
	
	this->elements = NULL;
}

Set::Set(const Set& source)
{
	// Copy to this
	this->elementSize = source.elementSize;
	this->elements = new int[source.elementSize];
	
	// Copy contents of pointer
	for (int i = 0; i < source.elementSize; i++) {
		this->elements[i] = source.elements[i];
	}
}

istream& operator>>(istream& streamInput, const Set& inputSet)
{
	
	for (int i = 0; i < inputSet.elementSize; i++) {
		streamInput >> inputSet.elements[i];
	}
	
	return streamInput;
}

ostream& operator<<(ostream& streamOutput, const Set& inputSet)
{
	streamOutput << "{";
	
	for (int i = 0; i < inputSet.elementSize; i++) {
		streamOutput << inputSet.elements[i];
		
		if (i != (inputSet.elementSize - 1)) {
			streamOutput << ", ";
		}
	}
	
	streamOutput << "}" << endl;
	
	return streamOutput;
}

Set Set::operator&(Set& inputSet)
{
	
	// Make a watch list for duplicates of maximum sized array
	int arraySize = 0;
	
	if (this->elementSize > inputSet.elementSize) {
		arraySize = this->elementSize;
	} else {
		arraySize = inputSet.elementSize;
	}
	
	// Duplicates list
	int duplicatesList[arraySize];
	
	// Check for duplicates
	int duplicatesCounter = 0;
	
	// Looping through current set
	for (int i = 0; i < this->elementSize; i++) {
		// Loop through the input set
		for (int j = 0; j < inputSet.elementSize; j++) {
			// Compare
			if (this->elements[i] == inputSet.elements[j]) {
				
				// Set up flag
				bool addToList = true;
				
				// Check if it has already been counted and added
				for (int k = 0; k <= duplicatesCounter; k++) {
					if(this->elements[i] == duplicatesList[k])
						addToList = false;
				}
				
				if (addToList) {
					// Add to the duplicate list
					duplicatesList[duplicatesCounter] = this->elements[i];
					
					// Increase when duplicate found
					duplicatesCounter++;
				}
			}
		}
	}
	
	Set outputSet(duplicatesCounter);
	
	for (int i = 0; i < duplicatesCounter; i++) {
		outputSet.elements[i] = duplicatesList[i];
	}
	
	return outputSet;
	
}

Set Set::operator+(Set& inputSet)
{
	
	// Make a watch list for duplicates of maximum sized array
	int arraySize = 0;
	
	if (this->elementSize > inputSet.elementSize) {
		arraySize = this->elementSize;
	} else {
		arraySize = inputSet.elementSize;
	}
	
	// Duplicates list
	int duplicatesList[arraySize];
	
	// Check for duplicates
	int duplicatesCounter = 0;
	int outputSetSize = this->elementSize + inputSet.elementSize;
	
	// Looping through current set
	for (int i = 0; i < this->elementSize; i++) {
		// Loop through the input set
		for (int j = 0; j < inputSet.elementSize; j++) {
			// Compare
			if (this->elements[i] == inputSet.elements[j]) {
				
				// Set up flag
				bool addToList = true;
				
				// Check if it has already been counted and added
				for (int k = 0; k <= duplicatesCounter; k++) {
					if(this->elements[i] == duplicatesList[k])
						addToList = false;
				}
				
				if (addToList) {
					// Add to the duplicate list
					duplicatesList[duplicatesCounter] = this->elements[i];
					
					// Decrease the output array size
					outputSetSize -= 1;
					
					// Add to the counter
					duplicatesCounter++;
				}
			}
		}
	}
	
	// Check Incase Negative (more than 1 similar value found
	if (outputSetSize <= 0) {
		outputSetSize = 1;
	}
	
	// Make a size for the output set
	Set outputSet(outputSetSize);
	
	{
		
		// Scoped 'i'
		int i = 0;
		bool duplicate = false;
		
		// Store all of the 1st set into the new array
		for (; i < this->elementSize; i++) {
			outputSet.elements[i] = this->elements[i];
		}
		
		// Check the array for duplicates before storing second set
		for (int j = 0; j < inputSet.elementSize; j++) {
			
			// Check against the duplicates list
			for (int k = 0; k < duplicatesCounter; k++) {
				if (inputSet.elements[j] == duplicatesList[k]) {
					duplicate = true;
				}
			}
			
			// Store the value if no duplicate
			if (!duplicate)
				outputSet.elements[i] = inputSet.elements[j];
			
			// Increase counter
			i++;
			
			// Reset flag
			duplicate = false;
			
		}
		
	}
	
	return outputSet;
}

Set Set::operator-(Set& inputSet)
{
	
	// Find amount of duplicates
	// find the actual duplicates
	
	// Instatiate class
	
	// check if duplicate, if duplicate do not store
	// Make a watch list for duplicates of maximum sized array
	int arraySize = 0;
	
	if (this->elementSize > inputSet.elementSize) {
		arraySize = this->elementSize;
	} else {
		arraySize = inputSet.elementSize;
	}
	
	// Duplicates list
	int duplicatesList[arraySize];
	
	// Check for duplicates
	int duplicatesCounter = 0;
	int outputSetSize = this->elementSize;
	
	// Looping through current set
	for (int i = 0; i < this->elementSize; i++) {
		// Loop through the input set
		for (int j = 0; j < inputSet.elementSize; j++) {
			// Compare
			if (this->elements[i] == inputSet.elements[j]) {
				
				// Set up flag
				bool addToList = true;
				
				// Check if it has already been counted and added
				for (int k = 0; k <= duplicatesCounter; k++) {
					if(this->elements[i] == duplicatesList[k])
						addToList = false;
				}
				
				if (addToList) {
					// Add to the duplicate list
					duplicatesList[duplicatesCounter] = this->elements[i];
					
					// Decrease the output array size
					outputSetSize -= 1;
					
					// Add to the counter
					duplicatesCounter++;
				}
			}
		}
	}
	
	// Check Incase Negative (more than 1 similar value found
	if (outputSetSize <= 0) {
		outputSetSize = 1;
	}
	
	// Make a size for the output set
	Set outputSet(outputSetSize);
	
	{
		
		// Scoped 'i'
		int c = 0;
		bool duplicate = false;
		
		for (; c < outputSet.elementSize;) {
			
			// Store all of the 1st set into the new array
			for (int i = 0; i < this->elementSize; i++) {
				
				// Check against the duplicates list
				for (int k = 0; k < duplicatesCounter; k++) {
					if (this->elements[i] == duplicatesList[k]) {
						duplicate = true;
					}
				}
				
				// Store the value if no duplicate
				if ((!duplicate) && this->elements[i] != 0) {
					// Do the element
					outputSet.elements[c] = this->elements[i];
					c++;
				}
				
				// Reset flag
				duplicate = false;
				
			}
		}
		
	}
	
	return outputSet;
}

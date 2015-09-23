#include "Bag.h"
using namespace std;

template <class Type>
MYLIB::Bag<Type>::Bag()
{
	elementsSize = 0;
	elements = NULL;
	
	computeType();
}

template <class Type>
MYLIB::Bag<Type>::Bag(int size)
{
	elementsSize = size;
	elements = new Type[size];
	
	for (int i = 0; i <= size; i++) {
		elements[i] = '\0';
	}
	
	computeType();
}

template <class Type>
MYLIB::Bag<Type>::~Bag()
{
	delete [] elements;
	
}

template <class Type>
void MYLIB::Bag<Type>::computeType()
{
	// Get the type
	int DT = *typeid(Type).name();
	
	switch (DT) {
		case 105:
			fullType = "Integer";
			break;
			
		case 100:
			fullType = "Double";
			break;
			
		case 102:
			fullType = "Float";
			break;
			
		default:
			fullType = "Type";
			break;
	}
}

template <class Type>
void MYLIB::Bag<Type>::add(Type value)
{
	for (int i = 0; i < elementsSize; i++) {
		if (elements[i] == '\0') {
			elements[i] = value;
			break;
		}
	}
}

template <class Type>
void MYLIB::Bag<Type>::remove(Type value)
{
	for (int i = 0; i < elementsSize; i++) {
		if (elements[i] == value) {
			elements[i] = '\0';
			break;
		}
	}
}

/*
 * Overloading
 */
template <class Type>
istream& MYLIB::operator>>(istream& stream,  MYLIB::Bag<Type>& input)
{
	// Check object is initialised
	if (input.elements == NULL) {
		string error = "Elements not intialised";
		throw error;
	} else {
		
		for (int i = 0; i < input.elementsSize; i++) {
			cout << "Input a " << input.fullType << ": ";
			stream >> input.elements[i];
		}
		
		return stream;
	}
}

template <class Type>
ostream& MYLIB::operator<<(ostream& stream, const MYLIB::Bag<Type>& output)
{
	if (output.elements == NULL) {
		string error = "Elements not intialised";
		throw error;
	} else {
		
		for (int i = 0; i < output.elementsSize; i++) {
			
			if (output.elements[i] != '\0') {
				stream << output.elements[i];
				
				if (output.elementsSize != (i + 1)) {
					stream << ", ";
				} else {
					stream << endl;
				}
			}
		}
		
		return stream;
	}

}

template <class Type>
void MYLIB::Bag<Type>::postBag(int size)
{
	elementsSize = size;
	elements = new Type[size];
	
	for (int i = 0; i <= size; i++) {
		elements[i] = '\0';
	}
	
}

template <class Type>
const MYLIB::Bag<Type>& MYLIB::Bag<Type>::operator=(const MYLIB::Bag<Type>& input)
{
	// Check for self assignment
	if (this != &input) {
		this->postBag(input.elementsSize);
		
		for (int i = 0; i < input.elementsSize; i++) {
			this->elements[i] = input.elements[i];
		}
		
	}
	
	return (*this);
	
}

template <class Type>
MYLIB::Bag<Type> MYLIB::Bag<Type>::operator+(const MYLIB::Bag<Type>& input) const
{
	if (this->elements == NULL) {
		string error = "First Object Added - Elements not intialised";
		throw error;
	} else if (input.elements == NULL) {
		string error = "Second Object Added - Elements not intialised";
		throw error;
	} else {
		int newElementSize = this->elementsSize + input.elementsSize;
		
		MYLIB::Bag<Type> result(newElementSize);
		
		{
			int globalCount = 0;
			
			for (int i = 0; i < this->elementsSize; i++) {
				result.elements[globalCount] = this->elements[i];
				globalCount++;
			}
			
			for (int i = 0; i < input.elementsSize; i++) {
				result.elements[globalCount] = input.elements[i];
				globalCount++;
			}
		}
		
		return result;
	}
}

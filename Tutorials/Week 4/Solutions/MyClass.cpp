#include <iostream>

using namespace std;

class MyClass
{
private:
	int * intArray;
	int arraySize;
	
public:
	MyClass();
	MyClass(int[], int);
	~MyClass();
	void display ();
};

MyClass::MyClass()
{
	this->arraySize = NULL;
	this->intArray = NULL;
}

MyClass::MyClass(int intData[], int arrSize)
{
	// Take of 1 (0 based Array)
	arrSize -= 1;
	
	this->arraySize = arrSize;
	this->intArray = new int[arrSize];
	
	// Populate the new Array
	for (int i = 0; i <= arrSize; i++) {
		this->intArray[i] = intData[i];
	}
}

MyClass::~MyClass()
{
	delete [] this->intArray;
}

void MyClass::display()
{
	// Populate the new Array
	for (int i = 0; i <= this->arraySize; i++) {
		cout << "Array Element " << i
		<< " = " << this->intArray[i] << endl;
	}
}

int main ()
{
	// Array
	int array[] = {2, 4, 6, 8};
	int arraySize = 4;
	
	MyClass myClass(array, arraySize);
	myClass.display();
	
	return 0;
}

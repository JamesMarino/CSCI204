#include <iostream>
using namespace std;

/*
 * Class Definition
 */
class Singleton
{
private:
	Singleton();
	static Singleton* instance;
	static int instantiationAttempts;
	
public:
	static Singleton* create();
	static void destroy();
	
	// Get
	int getInstantiationAttempts() const;
	Singleton* getInstanceAddress() const;
};

/*
 * Class Implementation
 */

// Constructor
Singleton::Singleton()
{
	// Empty contructor
}

// Define Instance to NULL
Singleton* Singleton::instance = NULL;

// Attempts
int Singleton::instantiationAttempts = 0;

// Custom Contructor
Singleton* Singleton::create()
{
	
	// Increase the attempts
	instance->instantiationAttempts++;
	
	if (instance == NULL) {
		instance = new Singleton;
	} else {
		cout << "There is already one of these!" << endl;
	}
	
	return instance;
}

// Custom Destructor
void Singleton::destroy()
{
	if (instance != NULL) {
		delete instance;
		instance = NULL;
	}
}

// Access Members
int Singleton::getInstantiationAttempts() const
{
	return instance->instantiationAttempts;
}

Singleton* Singleton::getInstanceAddress() const
{
	return instance;
}

int main()
{
	// Create instance
	Singleton *singleInstance;
	
	int userInput = 3;
	
	// Show Status
	cout << "Instantiation Attempts: " << singleInstance->getInstantiationAttempts() << endl;
	cout << "Current Address: " << singleInstance->getInstanceAddress() << endl;
	
	while (userInput != 0) {
		cout << "Enter 2 to create a Singleton." << endl;
		cout << "Enter 1 to destroy a Singleton." << endl;
		cout << "Enter 0 to stop." << endl;
		cin >> userInput;
		
		switch (userInput) {
			case 2:
				singleInstance = Singleton::create();
				break;
				
			case 1:
				Singleton::destroy();
				break;
				
			case 0:
				break;
				
			default:
				cout << "Enter a Valid Option." << endl;
				break;
		}
		
		// Show Status
		cout << "Attempts: " << singleInstance->getInstantiationAttempts() << endl;
		cout << "Current Address: " << singleInstance->getInstanceAddress() << endl;
	}
	
	return 0;
}
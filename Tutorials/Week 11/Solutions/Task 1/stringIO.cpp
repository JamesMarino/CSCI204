#include "Student.h"
using namespace std;

template<typename T>
string toString (T value)
{
	// Set up string stream output
	ostringstream outStream;
	
	// Place the Type into the string stream
	outStream << value;
	
	// Return the string
	return outStream.str();
	
}

template <typename T>
T toValue(string str)
{
	T output;
	
	// Store in the stream into the input stream
	istringstream inStream(str);
	
	inStream >> output;
	
	return output;
	
}

int main ()
{
	/*
	 * Integer
	 */
	int anInt;
	string anIntString;
	
	cout << "Input an Integer: ";
	cin >> anInt;
	
	anIntString = toString(anInt);
	cout << "Integer to String: " << anIntString << endl;
	anInt = toValue<int>(anIntString);
	cout << "String to Integer: " << anInt << endl;
	
	cout << endl;
	
	/*
	 * Double
	 */
	double aDouble;
	string aDoubleString;
	
	cout << "Input a Double: ";
	cin >> aDouble;
	
	aDoubleString = toString(aDouble);
	cout << "Double to String: " << aDoubleString << endl;
	aDouble = toValue<double>(aDoubleString);
	cout << "String to Double: " << aDouble << endl;
	
	cout << endl;
	
	/*
	 * Student
	 */
	Student aStudent;
	string aStudentString;
	
	cout << "Input a Student Record: ";
	cin >> aStudent;
	
	aStudentString = toString(aStudent);
	cout << "Student to String: " << aStudentString << endl;
	aStudent = toValue<Student>(aStudentString);
	cout << "String to Student: " << aStudent << endl;
	
	return 0;
}

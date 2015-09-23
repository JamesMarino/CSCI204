#include "Student.h"
using namespace std;

/*
 * Custom Steam Delimiters
 * Source:
 * http://stackoverflow.com/questions/1894886/parsing-a-comma-delimited-stdstring
 */
struct csv_reader: ctype<char>
{
	csv_reader(): ctype<char>(get_table()) {}
	
	static ctype_base::mask const* get_table()
	{
		static vector<ctype_base::mask> rc(table_size, ctype_base::mask());
		
		rc[':'] = ctype_base::space;
		rc['\n'] = ctype_base::space;
		rc[' '] = ctype_base::space;
		return &rc[0];
	}
};

/*
 * Overloading
 */
ostream& operator<<(ostream& output, const Student& student)
{
	output << student.FirstName;
	
	// Check if conversion from Student to String has been done
	if (student.LastName != "") {
		output << ":" << student.LastName << ":";
		output << student.StudentID << ":";
		output << student.GPA;
	}
	
	return output;
}

istream& operator>>(istream& input, Student& student)
{
	// Set Locale
	cin.imbue(std::locale(std::locale(), new csv_reader()));
	
	// Do the input
	input >> student.FirstName;
	input >> student.LastName;
	input >> student.StudentID;
	input >> student.GPA;
	
	return input;
}

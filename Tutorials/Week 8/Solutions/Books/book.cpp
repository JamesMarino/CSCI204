#include <iostream>
#include<iomanip>
using namespace std;

class BookException;

/*
 * Class: Book Definition
 */

class Book
{
	
private:
	static const int stringSize;
	int IDNumber;
	char *Title;
	char *Authors;
	int Pages;
	double Price;
	
public:
	Book();
	~Book();
	
	// Get Data
	friend istream& operator>>(istream&, Book&);
	friend ostream& operator<<(ostream&, const Book&);
	
};

istream& operator>>(istream&, Book&);
ostream& operator<<(ostream&, const Book&);

// Book Implentation
const int Book::stringSize = 90;

Book::Book()
{
	IDNumber = 0;
	Title = new char[stringSize];
	Authors = new char[stringSize];
	Pages = 0;
	Price = 0;
}

Book::~Book()
{
	delete [] Title;
	delete [] Authors;
}

/*
 * Class: Book Exception
 */

class BookException : public runtime_error
{
private:
	Book* book;
	string errorMessage;
	
public:
	BookException(Book&, string);
	void what();
	
	// Get Data
	Book& getBook();
};

// Implentation
BookException::BookException(Book& errorBook, string errorMsg) : runtime_error(errorMsg)
{
	book = &errorBook;
	errorMessage = errorMsg;
}

void BookException::what()
{
	cout << errorMessage << endl << endl;
}

Book& BookException::getBook()
{
	return *book;
}

ostream& operator<<(ostream &streamOutput, const Book &book)
{
	
	streamOutput << endl;
	streamOutput << "ID Number: " << book.IDNumber << endl
	<< "Title: " << book.Title << endl
	<< "Authors: " << book.Authors << endl
	<< "Number of Pages: " << book.Pages << endl
	<< "Price: $" << fixed << setprecision(2) << book.Price << endl;
	
	return streamOutput;
}

istream& operator>>(istream& streamInput, Book &book)
{
	
	cout << "ID Number: ";
	streamInput >> book.IDNumber;
	streamInput.ignore();
	
	cout << "Title: ";
	streamInput.ignore();
	streamInput.getline(book.Title, Book::stringSize);
	streamInput.ignore();
	
	cout << "Authors: ";
	streamInput.ignore();
	streamInput.getline(book.Authors, Book::stringSize);
	streamInput.ignore();
	
	cout << "Number of Pages: ";
	streamInput >> book.Pages;
	
	if ((book.Pages%4) != 0) {
		BookException error(book, "Incorrect Number of Pages");
		throw error;
	}
	
	cout << "Price: ";
	streamInput >> book.Price;
	
	if ((book.Price < 5) || (book.Price > 250)) {
		BookException error(book, "Incorrect Price");
		throw error;
	}
	
	return streamInput;
}

int main() {
	
	const int maxBooks = 2;
	
	Book book[maxBooks];
	int bookCounter = 0;

	while (bookCounter < maxBooks) {
		try {
			cin >> book[bookCounter];
			
			// Increase the Counter
			bookCounter++;
			
			// New line, it worked
			cout << endl;
			
		} catch (BookException error) {
			
			// Print The Book Error Number
			cout << "Number " << bookCounter + 1 << " Book Error";
			
			// Print the incorrect book
			cout << error.getBook();
			
			// Say the type of error
			error.what();
		}
	}
	
	// Print The books
	cout << "-------- The Two Books Are: --------" << endl;
	for (int i = 0; i < maxBooks; i++) {
		cout << book[i];
	}
	
    return 0;
}

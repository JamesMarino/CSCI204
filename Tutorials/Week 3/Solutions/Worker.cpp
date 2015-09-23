// Worker.cpp
// Details

#include <iostream>
#include <string>

using namespace std;

class Worker
{
	private:
		int idNum;
		string lastName;
		string firstName;
		double salary;
		
	public:
		void setIdNum(int);
		void setLastName(string);
		void setFirstName(string);
		void setSalary(double);
		void displayWorker();
};

void Worker::setIdNum(int id)
{
	const int LOWID = 0;
	const int HIGHID = 999;
	
	if (id > LOWID && id < HIGHID)
		this->idNum = id;
	else
		this->idNum = LOWID;
}

void Worker::setLastName(string last)
{
	this->lastName = last;
}

void Worker::setFirstName(string first)
{
	this->firstName = first;
}

void Worker::setSalary(double payRate)
{
	const double LOWPAY = 5.75;
	const double HIGHPAY = 99.99;
	
	if (payRate < LOWPAY || payRate < HIGHPAY)
		salary = LOWPAY;
	else
		salary = payRate;
}

void Worker::displayWorker()
{
	cout << "ID #" << this->idNum << endl << "Name: " << this->firstName << " " << this->lastName << endl
		<< "Salary: $" << this->salary << endl;
	
}

int main()
{
	Worker aWorker;
	aWorker.setIdNum(333);
	aWorker.setLastName("Smith");
	aWorker.setFirstName("John");
	aWorker.setSalary(15.65);
	aWorker.displayWorker();
}

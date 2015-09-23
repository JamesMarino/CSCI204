#include <iostream>
#include "OrderedList.h"
#include "Student.h"

int main() {
	int num;
	std::cout << "How many integers? ";
	std::cin >> num;
	std::cout << num << std::endl;

	MYLIB::OrderedList<int> listi;
	for(int i=0; i<num; i++) {
		std::cout << "Input an integer: ";
		int v;
		std::cin >> v;
		std::cout << v << std::endl;
		listi.insert(v);
	}

	std::cout << "Output integers: " << std::endl;
	MYLIB::OrderedList<int>::iterator it = listi.begin();
	while(it != listi.end()) {
		std::cout << *it << ' ';
		it++;
	}
	std::cout << std::endl;


	std::cout << "How many doubles? ";
	std::cin >> num;
	std::cout << num << std::endl;

	MYLIB::OrderedList<double> listd;
	for(int i=0; i<num; i++) {
		std::cout << "Input a double: ";
		double v;
		std::cin >> v;
		std::cout << v << std::endl;
		listd.insert(v);
	}

	std::cout << "Output doubles: " << std::endl;
	MYLIB::OrderedList<double>::iterator itd = listd.begin();
	while(itd != listd.end()) {
		std::cout << *itd << ' ';
		++itd;
	}
	std::cout << std::endl;

	std::cout << "How many student records? ";
	std::cin >> num;
	std::cout << num << std::endl;

	MYLIB::OrderedList<Student> lists;
	for(int i=0; i<num; i++) {
		Student st;
		std::cin >> st;
		std::cout << st << std::endl;
		lists.insert(st);
	}

	std::cout << "Output students: " << std::endl;
	MYLIB::OrderedList<Student>::iterator its = lists.begin();
		while(its != lists.end()) {
		std::cout << *(its++) << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

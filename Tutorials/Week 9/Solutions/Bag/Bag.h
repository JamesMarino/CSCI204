#ifndef __Bag__
#define __Bag__

#include <iostream>

namespace MYLIB {
	
	template <class Type>
	class Bag;
	
	template <class Type>
	std::istream& operator>>(std::istream& stream,  Bag<Type>& input);
	template <class Type>
	std::ostream& operator<<(std::ostream& stream, const Bag<Type>& output);
	
	template <class Type>
	class Bag
	{
	private:
		Type *elements;
		int elementsSize;
		std::string fullType;
		
		// Post Constructor
		void postBag(int);
		
	public:
		// Constructor
		Bag();
		Bag(int);
		~Bag();
		
		// Setup
		void computeType();
		
		// Access
		void add(Type);
		void remove(Type);
		
		// Overloaders
		const Bag& operator=(const Bag&);
		Bag operator+(const Bag&) const;
		
		friend std::istream& operator>> <Type>(std::istream&,  Bag<Type>&);
		friend std::ostream& operator<< <Type>(std::ostream&, const Bag<Type>&);
	};
	
}

#endif

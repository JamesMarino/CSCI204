/*------------------------------------------------------
 * Student's Name: James Marino
 * Student's email address: jm617@uow.edu.au
 * Laboratory group: CL/03 Friday 15:30
 * Purpose of this assignment:
 * Construct a doubley linked list, including iterator
 * Knowledge and use of the internals and workings of
 * containers
 -------------------------------------------------------*/

#ifndef __OrderedList__
#define __OrderedList__

namespace MYLIB {
	
	template<typename Type>
	class ListNode;
	
	class iterator;
	
	template<typename Type>
	class OrderedList
	{
	private:
		ListNode<Type> *head;
		ListNode<Type> *tail;
		
		int size;
		
		// Helpers
		Type getNext(int);
		
	public:
		~OrderedList();
		OrderedList();
		
		// Modifiers
		void insert(const Type&);
		
		// Iterators
		class iterator;
		
		iterator begin();
		iterator end();
		
		class iterator
		{
		private:
			ListNode<Type> *node;
			
		public:
			// Constructor
			iterator();
			
			// Modifiers
			void setNode(ListNode<Type>*);
			
			// Overloading
			iterator& operator++();
			iterator& operator++(int);
			
			bool operator==(const iterator&) const;
			bool operator!=(const iterator&) const;
			
			Type& operator*();
		};
		
	};
	
	template<typename Type>
	class ListNode
	{
	private:
		ListNode<Type> *previous;
		ListNode<Type> *next;
		
		// Holds an object
		Type object;
		
	public:
		ListNode();
		ListNode(Type);
		
		// Manipulation
		void storeObject(Type);
		Type& getObject();
		
		// Setting Nodes
		void pointPrevious(ListNode<Type>*);
		void pointNext(ListNode<Type>*);
		
		// Getting Nodes
		ListNode<Type>* getPrevious();
		ListNode<Type>* getNext();
	};
	
};

#endif

template<typename Type>
MYLIB::OrderedList<Type>::iterator::iterator()
{
	node = NULL;
}

template<typename Type>
typename MYLIB::OrderedList<Type>::iterator MYLIB::OrderedList<Type>::begin()
{
	// Initialise temporary Iterator
	iterator temp;
	
	// Assign to first element
	temp.setNode(head);
	
	// Return Temp
	return temp;
}

template<typename Type>
typename MYLIB::OrderedList<Type>::iterator MYLIB::OrderedList<Type>::end()
{
	// Initialise temporary Iterator
	iterator temp;
	
	temp.setNode(tail->getPrevious());
	
	// Return Temp
	return temp;
}

template<typename Type>
void MYLIB::OrderedList<Type>::iterator::setNode(ListNode<Type> *inputNode)
{
	node = inputNode;
}

template<typename Type>
Type& MYLIB::OrderedList<Type>::iterator::operator*()
{
	return node->getObject();
}

template<typename Type>
typename MYLIB::OrderedList<Type>::iterator& MYLIB::OrderedList<Type>::iterator::operator++()
{
	node = node->getNext();
	
	return (*this);
}

template<typename Type>
typename MYLIB::OrderedList<Type>::iterator& MYLIB::OrderedList<Type>::iterator::operator++(int)
{
	node = node->getNext();
	
	return (*this);
}

template<typename Type>
bool MYLIB::OrderedList<Type>::iterator::operator!=(const typename MYLIB::OrderedList<Type>::iterator &rhs) const
{
	if (this->node != rhs.node) {
		return true;
	} else {
		return false;
	}
}

template<typename Type>
bool MYLIB::OrderedList<Type>::iterator::operator==(const typename MYLIB::OrderedList<Type>::iterator &rhs) const
{
	if (this->node == rhs.node) {
		return true;
	} else {
		return false;
	}
}

/*
 * ListNode Definition
 */
template<typename Type>
MYLIB::ListNode<Type>::ListNode()
{
	// Initialise
	previous = NULL;
	next = NULL;
}

template<typename Type>
MYLIB::ListNode<Type>::ListNode(Type obj)
{
	// Initialise
	previous = NULL;
	next = NULL;
	object = obj;
}

template<typename Type>
void MYLIB::ListNode<Type>::pointPrevious(ListNode<Type> *p)
{
	previous = p;
}

template<typename Type>
void MYLIB::ListNode<Type>::pointNext(ListNode<Type> *n)
{
	next = n;
}

template<typename Type>
MYLIB::ListNode<Type>* MYLIB::ListNode<Type>::getNext()
{
	return next;
}

template<typename Type>
MYLIB::ListNode<Type>* MYLIB::ListNode<Type>::getPrevious()
{
	return previous;
}

template<typename Type>
void MYLIB::ListNode<Type>::storeObject(Type obj)
{
	object = obj;
}

template<typename Type>
Type& MYLIB::ListNode<Type>::getObject()
{
	return object;
}

/*
 * OrderedList Definition
 */
template<typename Type>
MYLIB::OrderedList<Type>::OrderedList()
{
	head = new ListNode<Type>();
	tail = new ListNode<Type>();
	
	// Set size to 0; Nothing stored yet
	size = 0;
	
	// Organise the previous --> head to point at the tail
	head->pointPrevious(tail);
	
	// Organise the tail -- to point to the head
	tail->pointNext(head);
	
}

template<typename Type>
MYLIB::OrderedList<Type>::~OrderedList()
{
	ListNode<Type> *temp;
	
	// Delete down the list
	while (head != NULL) {
		temp = head;
		head = head->getNext();
		
		delete temp;
	}
	
	// Delete head and tail
	delete head;
	delete tail;
	
}

template<typename Type>
Type MYLIB::OrderedList<Type>::getNext(int position)
{
	Type temp = -1;
	MYLIB::ListNode<Type> *current = head;
	
	for (int i = 0; i < position; i++) {
		current = current->getNext();
		
		if (current == NULL) {
			return -1;
		}
		
		temp = current->getObject();
	}
	
	return temp;
}

template<typename Type>
void MYLIB::OrderedList<Type>::insert(const Type &object)
{
	ListNode<Type> *previous;
	ListNode<Type> *current;
	ListNode<Type> *next;
	ListNode<Type> *newNode;
	
	// Set the current to the head
	previous = head->getPrevious();
	current = head;
	next = head->getNext();
	
	// Create a new node regardless
	newNode = new ListNode<Type>(object);
	
	// Update Size, new object created
	size += 1;
	
	/*
	 * Check the next node for NULL
	 * (Empty List) or (Populated List)
	 */
	if (next == NULL) {
		
		/*
		 * HEAD
		 */
		
		// Assign [current -> next] to [newNode]
		current->pointNext(newNode);
		
		// Get the new node we are working with
		previous = current;
		current = current->getNext();
		
		// Assign [previous] to the [current]
		current->pointPrevious(previous);
		
		/*
		 * TAIL
		 */
		// Assign the tail's previous element to the new node
		tail->pointPrevious(current);
		
	} else {
		
		/*
		 * HEAD
		 */
		
		// This will position at the immediate element
		// GREATER THAN the object being inserted
		while (current->getObject() < object)
		{
			// Not the right place to insert
			// Move along
			
			// Get the new node we are working with
			previous = current;
			current = current->getNext();
			
			// Get the new current object
			if (current != NULL) {
				next = current->getNext();
				//currentObject = current->getObject();
			} else {
				// We are at the right position
				// Exit out
				break;
			}
		}
		
		// Assign previous point -> Next to newNode
		previous->pointNext(newNode);
		
		// Get temp address to store the previously
		// removed into
		ListNode<Type> *tempCurrent = previous->getNext();
		
		// Assign current to next
		tempCurrent->pointNext(current);
		
		// Fix Previous
		// Previous of Current
		tempCurrent->pointPrevious(previous);
		// Previous of Next
		if (current != NULL) {
			current->pointPrevious(tempCurrent);
		}
		
		/*
		 * TAIL
		 */
		// Check if the current next is NULL (last element)
		if (tempCurrent->getNext() == NULL) {
			// Assign the tail's previous element to the new node
			tail->pointPrevious(tempCurrent);
		}
		
	}
	
}

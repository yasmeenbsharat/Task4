#include <iostream>
#include <vector>
#include "Queue.h"
int main() {
	
	{   // Test Stack

		Stack < int > s; //create an empty stack .
		s.push(8); //Insert 8 into the stack.
		s.push(9); //Inserts a new element (9) at the top of the stack, above its current top element.
		s.push(10); //Insert 10  at the top of the stack.
		s.push(11); //Insert 11 at the top of the stack.
		// Stack becomes 8, 9, 10, 11 
		std::cout << "The elements of the stack : ";
		s.printStack();

		s.pop(); // removing the top  element (11) (last itam )
		s.pop(); // removing the next top (10)

		// Stack becomes 8, 9
		std::cout << "The elements of the stack : ";
		s.printStack();

		// check if the stack is empty
		if (s.empty()) {
			std::cout << "The stack is empty\n";
		}
		else {
			std::cout << "The stack is not empty\n";
		}

		//test the getVector() method
		std::vector < int > v = s.getVector();
		std::cout << "The elements of the vector : ";

		for (size_t i = 0; i < v.size(); i++)
			std::cout << v[i] << ", ";
		std::cout << std::endl;

		//std::cout << s;

	}
	
	std::cout << " -------------------------------------------------------------------------------------------------" << std::endl;

	{ // Test Queue

		Queue < int > q; //create an empty queue .
		q.push(1); // Insert (1) into the queue.
		q.push(2); //Inserts a new element (2) at the back of the queue.
		q.push(3); //Inserts a new element (3) at the back of the queue.
		q.push(4); //Inserts a new element (4) at the back of the queue.
		// Queue becomes 1,2, 3, 4 
		std::cout << "The elements of the queue: ";
		q.printQueue();
		q.pop(); // removing the front element (1)
		q.pop(); // removing the next front element (2)
		// Queue becomes  3, 4 
		std::cout << "The elements of the queue: ";
		q.printQueue();
		q.push(5);
		// Queue becomes  3, 4 ,5
		std::cout << "The elements of the queue: ";
		q.printQueue();
	}

}
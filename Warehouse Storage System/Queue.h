
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <iomanip>
#include "WHLocation.h"

using namespace std;

//Queue class.
class Queue
{
	//nested node class to store data.
	class Node
	{
  	public:
    	WHLocation* data;
      Node*    next;
  };

	public:
		//constructor to init default values of queue.
		Queue();

		//destructor used to delete nodes from list but not data.
		~Queue();

		//function used to check if queue is empty.
		bool isEmpty() const;

		//check and store first element in queue.
		void peekFirst(WHLocation** loc) const;

		//remove first element from queue.
		void popFirst(WHLocation** loc);

		//add element to end of the queue.
		void addLast(WHLocation* loc);

		//print the elements from queue.
		void print() const;

	private:
		//member variables to track front & end.
		Node* head;
		Node* tail;

};
#endif

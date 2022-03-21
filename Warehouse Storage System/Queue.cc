
#include "Queue.h"

//constructor used to initialize head and tail to null.
Queue::Queue()
{
	head = NULL;
	tail = NULL;
}

//destructor used to deallocate nodes but keep node ata.
Queue::~Queue()
{
	//track current and next node.
	Node* currNode = head;
  Node* nextNode = NULL;


		//while current node isnt null keep iterating.
    while(currNode!=NULL)
		{
			//next node equal to current node pointer.
        nextNode = currNode->next;

				//delete current node.
        delete currNode;

				//keep iterating.
        currNode = nextNode;
    }
}

//check if queue is empty.
bool Queue::isEmpty() const
{
	Node* currNode = head;

	//if head is null return true.
	if(currNode == NULL)
	{
		return true;
	}

	//return false if head is not empty.
	return false;
}

//check the first elment in the queue and store it.
void Queue::peekFirst(WHLocation** loc) const
{
	Node* currNode = head;

	//if head is null return null.
	if(currNode == NULL)
	{
		*loc = NULL;
	}

	//store data in loc.
	else
	{
		*loc = currNode->data;
	}

}

//remove the first node from queue.
void Queue::popFirst(WHLocation** loc)
{
	Node* currNode = head;

	//if head is null return null.
	if(currNode == NULL)
	{
		loc = NULL;
	}

	//delete the first node from the queue.
	else
	{
		//store the first node data.
		*loc = currNode->data;

		//change head pointer.
		head = currNode->next;

		//make current node point to null
		currNode->next = NULL;

		//delete node.
		delete currNode;
	}

}

//add node to end of queue
void Queue::addLast(WHLocation* loc)
{
	//store current and new node.
	Node* currNode = head;
	Node* newNode = new Node();
	//new node data equals loc.
	newNode->data = loc;

	//check if queue is empty.
	if(isEmpty())
	{
		//make head new node.
		head = newNode;
	}

	//while the current node isnt null
	while(currNode != NULL)
	{
		//if this is the current last nodee in the queue add the new node here.
		if(currNode->next == NULL)
		{
			currNode->next = newNode;
			newNode->next = NULL;
			break;
		}

		currNode = currNode->next;
	}


}

//print out all data in the queue.
void Queue::print() const
{
	Node* currNode = head;

	cout<<endl<<"Printing List: "<<endl<<endl;
	while(currNode != NULL)
	{
		currNode->data->print();
		currNode = currNode->next;
	}

}

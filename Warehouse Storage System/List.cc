
#include "List.h"

//default constructor to init the head member variable to null.
List::List():head(NULL)
{
}

//destructor used to delete nodes and node data from the list.
List::~List()
{
    //Nodes to keep track of head and current node and next node.
    Node* currNode = head;
    Node* nextNode = NULL;

    //while the current node is not null, delete the node and it's data from the list. (deallocate memory.)
    while(currNode!=NULL)
		{
        //set next node equal to current nodes next element.
        nextNode = currNode->next;

        //deallocate the memory for the node and it's data.
        delete currNode->data;
        delete currNode;

        //move to next node in list.
        currNode = nextNode;
    }

}

//method used to add new node to list with the product as the data.
void List::add(Product* prod)
{
    //create new node.
    Node* newNode = new Node();

    //new node's data is equal to passed in product.
    newNode->data = prod;

    //new node points to null.
    newNode->next = NULL;

    //current node stores head.
    Node* currNode = head;

    //track previous node in list.
    Node* prevNode = NULL;

    //while the current node in the list is not null, find where new node should be placed aphabetically in the list.
    while(currNode!=NULL)
		{
      //if the new node data is less than the current node data than break out the loop.
        if(newNode->data->getName() < currNode->data->getName())
				{
            break;
        }
        //store previous node.
        prevNode = currNode;

        //store current node.
        currNode = currNode->next;
    }

    //insert currNode if no nodes
    if (prevNode == NULL)
		{
      //head equal new nodee.
        head = newNode;
    }
    //otherwise place the new node to where the previous node points to.
		else
		{
        prevNode->next = newNode;
    }

    //node points to current node so now ex: prevNode --> newNode --> currNode
    newNode->next = currNode;

}

//search for node with specific data and remove it.
void List::remove(const string& name, Product** prod)
{

    //store current node and previous node.
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    //wwhile the current node is not null iterate through the list.
    while(currNode!=NULL)
		{
        //if the node we're looking for is found break out the loop
        if(currNode->data->getName() == name)
				{
           break;
        }

        //iterate list.
        prevNode = currNode;
        currNode = currNode->next;
    }

    //if the current node is null return null.
    if(currNode == NULL)
		{
        *prod = NULL;
        return;
    }
    //currNode is not NULL make its next element the head since we're removing it.
    if (prevNode == NULL)
		{
        head = currNode->next;
    }

    //otherwise make the previous node point to the current nodes pointer.
		else
		{
        prevNode->next = currNode->next;
    }
    //store removed nodee data.
    *prod = currNode->data;

    //delete node.
    delete currNode;
}

//check if the list is empty.
bool List::isEmpty() const
{
	Node* currNode = head;

  //if head is empty return true.
	if(currNode == NULL)
	{
		return true;
	}

  //return false if head is not empty.

	return false;
}

//not used
void List::removeUpTo(const string& name)
{
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    while (currNode!=NULL)
		{
        if (name < currNode->data->getName())
				{
           break;
        }
        prevNode = currNode;
        currNode = currNode->next;
        delete prevNode->data;
        delete prevNode;
    }

    head = currNode;
}

//print the data in the list.
void List::print() const
{

    //test code.
    Node* currNode = head;
    cout<<"Print list..."<<endl;

    if (currNode == NULL){
        cout <<"List empty"<<endl;
    }

    //iterate through list and print each node.
    while(currNode != NULL){
        currNode->data->print();
        currNode = currNode->next;
    }
}

//will fill find a product in the list and return it.
void List::findProduct(const string& name, Product** prod) const
{

    //store current and previous node.
    Node * currNode;
    Node * prevNode;

    currNode = head;
    prevNode = NULL;

    //while current node isnt null keep iterating.
    while(currNode!=NULL)
		{
        //if data is found break out of loop
        if (currNode->data->getName() == name)
				{
           break;
        }

        //keep iterating through list.
        prevNode = currNode;
        currNode = currNode->next;
    }

    //if nothing found return null.
    if(currNode == NULL)
		{
        *prod = NULL;
        return;
    }

    //store data in the product output paramter.
    *prod = currNode->data;
}

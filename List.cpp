/*
Antony Tejakusuma
CIS 22C
Lab 1
*/

#include "List.h"
#include <iostream>
using namespace std;

List::List(): start(NULL), end(NULL), cursor(NULL), length(0) {}

List::~List()
{
    cursor = start;
    NodePtr temp;
    while(cursor != NULL)
    {
        temp = cursor->next;

        delete cursor;

        cursor = temp;

    }
}

void List::print()
{
    NodePtr temp = start; //create a temporary iterator
    while (temp != NULL) {
    	cout << cursor->data << " ";
        temp = cursor->next;
    }
    cout << endl; //What does this do?
}

void List::add_start(int data){
    if (length==0) {
        start = new Node(data);
        end = start;
    } else {
        NodePtr N = new Node(data);//create the new node by calling the node constructor
        N->next = start;//set the new node's next field to point to the start
        start = N;//make the start be the new node
    }
    length++;

}

void List::add_end(int data){
	if (length==0) {
        start = new Node(data);
        end = start;
    } else {
    	NodePtr N = new Node(data);
    	end->next = N;
    	end = N;
    }
    length++;
}

bool List::is_empty(){
    return (length==0);
}

int List::get_length(){
	return length;
}

int List::get_start(){      
    return start->data;
}

int List::get_end(){
	return end->data;
}



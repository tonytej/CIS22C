/*
Antony Tejakusuma
CIS 22C
Lab 1
*/

#include "List.h"
#include <assert.h>
#include <iostream>
using namespace std;

template <class listitem>
List<listitem>::List(): start(NULL), end(NULL), cursor(NULL), length(0) {}

template <class listitem>
List<listitem>::~List()
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

template <class listitem>
void List<listitem>::print(){
    NodePtr temp = start; //create a temporary 
    while (temp != NULL) {
    	cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; //What does this do?
}

template <class listitem>
void List<listitem>::add_start(listitem data){
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

template <class listitem>
void List<listitem>::add_end(listitem data){
	if (length==0) {
        start = new Node(data);
        end = start;
    } else {
    	NodePtr N = new Node(data);
    	end->next = N;
    	end = end->next;
    }
    length++;
}

template <class listitem>
bool List<listitem>::is_empty(){
    return (length==0);
}

template <class listitem>
int List<listitem>::get_length(){
	return length;
}

template <class listitem>
listitem List<listitem>::get_start(){     
    assert(start != NULL); 
    return start->data;
}

template <class listitem>
listitem List<listitem>::get_end(){
    assert(end != NULL);
	return end->data;
}
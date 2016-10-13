/*
Antony Tejakusuma
CIS22C
Stack.cpp
*/

#include <iostream>
#include "Stack.h"
#include <assert.h>
using namespace std;

Stack::Stack(): top(NULL), length(0) {}

Stack::Stack(const Stack &stack):length(stack.length){
    if(stack.top == NULL){
        top = NULL;
    } else {
        top = new Node;
        top->data = stack.top->data;
        NodePtr temp;
        temp = stack.top;
        NodePtr qtemp = top;
        while (temp->next != NULL){
            qtemp->next = new Node;
            qtemp = qtemp->next;
            temp = temp->next;
            qtemp->data = temp->data;
        }
    }
}

Stack::~Stack(){
    NodePtr temp = top;
    NodePtr temp2 = top;
    while(temp != NULL){
        temp = temp->next;
        delete temp2;
        temp2 = temp;
    }
}

void Stack::pop(){
    assert(length != 0);
    if (length==1){
        delete top;
        top = NULL;
        length = 0;
    } else {
        NodePtr temp = top;
        top = top->next; //make the start pointer point to the second node in the List
        delete temp; //delete the original start
        length--;
    }
}

void Stack::push(string data){
    if (length==0){
        top = new Node(data);
    } else {
        NodePtr N = new Node(data);
        N->next = top;
        top = N;
    }
    length++;
}

string Stack::get_top(){
    return top->data;
}

int Stack::get_length(){
    return length;
}

void Stack::print(){
    NodePtr temp;
    temp = top;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool Stack::operator==(const Stack &stack){
    if (length != stack.length)
        return false;
    NodePtr temp1 = top;
    NodePtr temp2 = stack.top;
    while (temp1 != NULL){
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}





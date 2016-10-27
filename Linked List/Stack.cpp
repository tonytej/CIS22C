/*
Antony Tejakusuma
CIS22C
Stack.cpp
*/

#include "Stack.h"
#include <iostream>
#include <assert.h>

using namespace std;

Stack::Stack(){}

Stack::Stack(const Stack &S):stack(S.stack){}

Stack::~Stack(){}

void Stack::pop(){
    stack.remove_start();
}

void Stack::push(int data){
    stack.add_start(data);
}

/*bool Stack::operator==(const Stack &S){

}*/

int Stack::get_top(){
    stack.get_start();
}

int Stack::get_size(){
    stack.get_length();
}

void Stack::print(){
    stack.print();
}


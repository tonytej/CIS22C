/*
Antony Tejakusuma
CIS 22C
Lab 1
*/
#include "List.cpp"
#include <iostream>
using namespace std;

int main()
{
    //creating a new list object L
    List L;

    L.add_start(5);
    cout << "The start of the List should be 5: " << L.get_start() << endl;
    cout << "The end of the List should be 5: " << L.get_end() << endl;

    cout << "List should contain: 5" << endl;
    L.print();

    L.add_end(10);

    cout << "The start of the List should be 5: " << L.get_start() << endl;
    cout << "The end of the List should be 10: " << L.get_end() << endl;

    cout << "List should contain: 5 10" << endl;
    L.print();
   
    //YOU MUST ADD MORE TESTS HERE TO RECEIVE CREDIT FOR THIS LAB!!!
}
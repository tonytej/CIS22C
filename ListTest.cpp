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

    if(L.is_empty())   
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl;

    L.add_start(5);
    cout << "The start of the List should be 5: " << L.get_start() << endl;
    cout << "The end of the List should be 5: " << L.get_end() << endl;

    cout << "List should contain: 5" << endl;
    cout << "Length of the list should be 1: " << L.get_length() << endl;
    L.print();

    L.add_end(10);

    cout << "The start of the List should be 5: " << L.get_start() << endl;
    cout << "The end of the List should be 10: " << L.get_end() << endl;

    cout << "List should contain: 5 10" << endl;
    cout << "Length of the list should be 2: " << L.get_length() << endl;
    L.print();

    L.add_start(11);
    cout << "The start of the List should be 11: " << L.get_start() << endl;
    cout << "The end of the List should be 10: " << L.get_end() << endl;

    cout << "List should contain: 11 5 10" << endl;
    cout << "Length of the list should be 3: " << L.get_length() << endl;
    L.print();

    L.add_end(3);

    cout << "The start of the List should be 11: " << L.get_start() << endl;
    cout << "The end of the List should be 3: " << L.get_end() << endl;

    cout << "List should contain: 11 5 10 3" << endl;
    cout << "Length of the list should be 4: " << L.get_length() << endl;
    L.print();

    if(L.is_empty())   
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl;
}

/*
Results:
List is empty
The start of the List should be 5: 5
The end of the List should be 5: 5
List should contain: 5
Length of the list should be 1: 1
5
The start of the List should be 5: 5
The end of the List should be 10: 10
List should contain: 5 10
Length of the list should be 2: 2
5 10
The start of the List should be 11: 11
The end of the List should be 10: 10
List should contain: 11 5 10
Length of the list should be 3: 3
11 5 10
The start of the List should be 11: 11
The end of the List should be 3: 3
List should contain: 11 5 10 3
Length of the list should be 4: 4
11 5 10 3
List is not empty
*/
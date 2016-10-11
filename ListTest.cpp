/*
Antony Tejakusuma
CIS 22C
Lab 1
*/

#include "List.h"
#include <iostream>
using namespace std;

int main()
{
    /*
    //creating a new list object L
    List<int> L;

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
        cout << "List is not empty" << endl << endl;

    List<double> L1;

    if(L1.is_empty())   
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl;

    L1.add_start(2.2);
    cout << "The start of the List should be 5: " << L1.get_start() << endl;
    cout << "The end of the List should be 5: " << L1.get_end() << endl;

    cout << "List should contain: 5" << endl;
    cout << "Length of the list should be 1: " << L1.get_length() << endl;
    L1.print();

    L1.add_end(3.14);

    cout << "The start of the List should be 5: " << L1.get_start() << endl;
    cout << "The end of the List should be 10: " << L1.get_end() << endl;

    cout << "List should contain: 5 10" << endl;
    cout << "Length of the list should be 2: " << L1.get_length() << endl;
    L1.print();

    L1.add_start(5.55);
    cout << "The start of the List should be 11: " << L1.get_start() << endl;
    cout << "The end of the List should be 10: " << L1.get_end() << endl;

    cout << "List should contain: 11 5 10" << endl;
    cout << "Length of the list should be 3: " << L1.get_length() << endl;
    L1.print();

    L1.add_end(8.98);

    cout << "The start of the List should be 11: " << L1.get_start() << endl;
    cout << "The end of the List should be 3: " << L1.get_end() << endl;

    cout << "List should contain: 11 5 10 3" << endl;
    cout << "Length of the list should be 4: " << L1.get_length() << endl;
    L1.print();

    if(L1.is_empty())   
        cout << "List is empty" << endl;
    else
        cout << "List is not empty" << endl;*/

    List<int> L;
    L.add_start(5);
    L.add_start(7);
    L.add_end(9);
    L.add_end(11);
    L.print();
    L.remove_start();
    L.remove_end();
    L.print();

    List<string> L1;
    L1.add_start("Albert");
    L1.add_start("Darren");
    L1.add_end("Kevin");
    L1.add_end("Tandar");
    L1.print();
    L1.remove_start();
    L1.remove_end();
    L1.print();

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
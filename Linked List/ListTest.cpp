/*
Antony Tejakusuma
CIS 22C
ListTest.cpp
*/

#include "List.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "TESTING BASIC FUNCTIONS" << endl;
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
    cout << "The start of the List should be 2.2: " << L1.get_start() << endl;
    cout << "The end of the List should be 2.2: " << L1.get_end() << endl;

    cout << "List should contain: 2.2" << endl;
    cout << "Length of the list should be 1: " << L1.get_length() << endl;
    L1.print();

    L1.add_end(3.14);

    cout << "The start of the List should be 2.2: " << L1.get_start() << endl;
    cout << "The end of the List should be 3.14: " << L1.get_end() << endl;

    cout << "List should contain: 2.2 3.14" << endl;
    cout << "Length of the list should be 2: " << L1.get_length() << endl;
    L1.print();

    L1.add_start(5.55);
    cout << "The start of the List should be 5.55: " << L1.get_start() << endl;
    cout << "The end of the List should be 3.14: " << L1.get_end() << endl;

    cout << "List should contain: 5.55 2.2 3.14" << endl;
    cout << "Length of the list should be 3: " << L1.get_length() << endl;
    L1.print();

    L1.add_end(8.98);

    cout << "The start of the List should be 5.55: " << L1.get_start() << endl;
    cout << "The end of the List should be 8.98: " << L1.get_end() << endl;

    cout << "List should contain: 5.55 2.2 3.14 8.98" << endl;
    cout << "Length of the list should be 4: " << L1.get_length() << endl;
    L1.print();

    if(L1.is_empty())   
        cout << "List is empty" << endl << endl;
    else
        cout << "List is not empty" << endl << endl;


    cout << "TESTING DOUBLY LINKED LIST AND CURSOR OPERATIONS" << endl;
    List<int> L2;
    L2.add_start(5);
    L2.add_start(7);
    L2.add_end(9);
    L2.add_end(11);
    cout << "Should print 7 5 9 11: ";
    L2.print();
    cout << "Should print 4: " << L2.get_length() << endl;
    L2.remove_start();
    L2.remove_end();
    cout << "Should print 5 9: ";
    L2.print();
    cout << "Should print 2: " << L2.get_length() << endl;
    L2.begin_cursor();
    L2.move_cursor();
    cout << "Should print 9: " << L2.get_cursor() << endl;

    List<string> L3;
    L3.add_start("Albert");
    L3.add_start("Darren");
    L3.add_end("Kevin");
    L3.add_end("Edric");
    cout << "Should print Darren Albert Kevin Edric: ";
    L3.print();
    cout << "Should print 4: " << L3.get_length() << endl;
    L3.remove_start();
    L3.remove_end();
    cout << "Should print Albert Kevin: ";
    L3.print();
    cout << "Should print 2: " << L3.get_length() << endl;
    L3.begin_cursor();
    L3.add_cursor("Tony");
    cout << "Should print Albert Tony Kevin: ";
    L3.print();
    cout << "Should print 3: " << L3.get_length() << endl;
    L3.move_cursor();
    L3.remove_cursor();
    cout << "Should print Albert Kevin: ";
    L3.print();
    cout << "Should print 2: " << L3.get_length() << endl;
    L3.begin_cursor();
    L3.move_cursor();
    L3.remove_cursor();
    cout << "Should print Albert: ";
    L3.print();
    cout << "Should print 1: " << L3.get_length() << endl;
    L3.remove_start();
    cout << "Should print nothing: ";
    L3.print();
    if (L3.off_end()){
        cout << "Cursor off the end of the list" << endl;
    } else {
        cout << "Cursor is not off the end of the list" << endl;
    }
    
    cout << endl;
    cout << "TESTING REVERSE PRINTING" << endl;
    List <int> L4;
    L4.add_start(30);
    L4.add_start(25);
    L4.add_start(20);
    L4.add_start(15);
    L4.add_start(10);
    L4.add_start(5);
    cout << "Normal print: ";
    L4.print();
    cout << "Reverse print: ";
    L4.print_reverse();
    List<string> L5;
    L5.add_start("Tony");
    L5.add_start("Kevin");
    L5.add_start("Edric");
    L5.add_start("Andre");
    cout << "Normal print: ";
    L5.print();
    cout << "Reverse print: ";
    L5.print_reverse();
    cout << endl;
    
    cout << "TESTING INDEX OPERATIONS" << endl;
    L4.begin_cursor();
    cout << "Begin cursor." << endl;
    cout << "Should print 1: " << L4.get_index() << endl;
    L4.scroll_to_index(3);
    cout << "Scrolled to index 3." << endl;
    cout << "Should print 3: " << L4.get_index() << endl;
    L4.scroll_to_index(1);
    cout << "Scrolled to index 1." << endl;
    cout << "Should print 1: " << L4.get_index() << endl;
    L4.scroll_to_index(5);
    cout << "Scrolled to index 5." << endl;
    cout << "Should print 5: " << L4.get_index() << endl << endl;

    cout << "TESTING SEARCH OPERATIONS" << endl;
    cout << "Linear Searching for 20. Should print 4: " << L4.linear_search(20) << endl;
    cout << "Linear Searching for 5. Should print 1: " << L4.linear_search(5) << endl;
    cout << "Linear Searching for 30. Should print 6: " << L4.linear_search(30) << endl;

    cout << "Binary Searching for 20. Should print 4: " << L4.binary_search(1, L4.get_length(), 20) << endl;
    cout << "Binary Searching for 5. Should print 1: " << L4.binary_search(1, L4.get_length(), 5) << endl;
    cout << "Binary Searching for 30. Should print 6: " << L4.binary_search(1, L4.get_length(), 30) << endl;
}

/*
Results:
TESTING BASIC FUNCTIONS
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

List is empty
The start of the List should be 2.2: 2.2
The end of the List should be 2.2: 2.2
List should contain: 2.2
Length of the list should be 1: 1
2.2 
The start of the List should be 2.2: 2.2
The end of the List should be 3.14: 3.14
List should contain: 2.2 3.14
Length of the list should be 2: 2
2.2 3.14 
The start of the List should be 5.55: 5.55
The end of the List should be 3.14: 3.14
List should contain: 5.55 2.2 3.14
Length of the list should be 3: 3
5.55 2.2 3.14 
The start of the List should be 5.55: 5.55
The end of the List should be 8.98: 8.98
List should contain: 5.55 2.2 3.14 8.98
Length of the list should be 4: 4
5.55 2.2 3.14 8.98 
List is not empty

TESTING DOUBLY LINKED LIST AND CURSOR OPERATIONS
Should print 7 5 9 11: 7 5 9 11 
Should print 4: 4
Should print 5 9: 5 9 
Should print 2: 2
Should print 9: 9
Should print Darren Albert Kevin Edric: Darren Albert Kevin Edric 
Should print 4: 4
Should print Albert Kevin: Albert Kevin 
Should print 2: 2
Should print Albert Tony Kevin: Albert Tony Kevin 
Should print 3: 3
Should print Albert Kevin: Albert Kevin 
Should print 2: 2
Should print Albert: Albert 
Should print 1: 1
Should print nothing: 
Cursor off the end of the list

TESTING REVERSE PRINTING
Normal print: 5 10 15 20 25 30
Reverse print: 30 25 20 15 10 5
Normal print: Andre Edric Kevin Tony
Reverse print: Tony Kevin Edric Andre

TESTING INDEX OPERATIONS
Begin cursor.
Should print 1: 1
Scrolled to index 3.
Should print 3: 3
Scrolled to index 1.
Should print 1: 1
Scrolled to index 5.
Should print 5: 5

TESTING SEARCH OPERATIONS
Linear Searching for 20. Should print 4: 4
Linear Searching for 5. Should print 1: 1
Linear Searching for 30. Should print 6: 6
Binary Searching for 20. Should print 4: 4
Binary Searching for 5. Should print 1: 1
Binary Searching for 30. Should print 6: 6
*/

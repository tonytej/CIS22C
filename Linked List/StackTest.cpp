/*
Antony Tejakusuma
CIS22C
StackTest.cpp
*/

#include "Stack.cpp"
#include <iostream>

using namespace std;

int main() {
    cout << "TESTING BASIC FUNCTIONS (PUSH, POP, ACCESSORS)" << endl;
    Stack S;
    S.push(5);
    S.push(10);
    S.push(15);
    cout << "Should print 15 10 5: ";
    S.print();
    cout << "Top should be 15: " << S.get_top() << endl;
    cout << "Size should be 3: " << S.get_size() << endl;
    S.pop();
    S.pop();
    cout << "Popped twice." << endl;
    cout << "Should print 5: ";
    S.print();
    cout << "Top should be 5: " << S.get_top() << endl;
    cout << "Size should be 1: " << S.get_size() << endl << endl;
    
    cout << "TESTING COPY CONSTRUCTOR AND OPERATOR==" << endl; 
    Stack S1;
    S1.push(1);
    S1.push(2);
    S1.push(3);
    S1.push(4);
    S1.push(5);
    Stack S2(S1);
    cout << "S1 contains 5 4 3 2 1: ";
    S1.print();
    cout << "S2 contains 5 4 3 2 1: ";
    S2.print();
    cout << "Comparing S1 and S2: ";
    if(S1==S2){
        cout << "S1 is equal to S2" << endl;
    } else {
        cout << "S1 is not equal to S2" << endl;
    }
    cout << "Comparing S and S1: ";
    if(S==S1){
        cout << "S is equal to S1" << endl;
    } else {
        cout << "S is not equal to S1" << endl;
    }
}
/*
TESTING BASIC FUNCTIONS (PUSH, POP, ACCESSORS)
Should print 15 10 5: 15 10 5 
Top should be 15: 15
Size should be 3: 3
Popped twice.
Should print 5: 5 
Top should be 5: 5
Size should be 1: 1

TESTING COPY CONSTRUCTOR AND OPERATOR==
S1 contains 5 4 3 2 1: 5 4 3 2 1 
S2 contains 5 4 3 2 1: 5 4 3 2 1 
Comparing S1 and S2: S1 is equal to S2
Comparing S and S1: S is not equal to S1
*/

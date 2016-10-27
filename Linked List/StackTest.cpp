/*
Antony Tejakusuma
CIS22C
StackTest.cpp
*/

#include "Stack.cpp"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    S.push(5);
    S.push(10);
    S.push(15);
    cout << "Should print 15 10 5: ";
    S.print();
    cout << "Should print 15: " << S.get_top() << endl;
    cout << "Should print 3: " << S.get_size() << endl;
    S.pop();
    S.pop();
    cout << "Should print 5: ";
    S.print();
    cout << "Should print 5: " << S.get_top() << endl;
    cout << "Should print 1: " << S.get_size() << endl;
}

/*
Antony Tejakusuma
CIS 22C
StackTest.cpp
*/

#include "Stack.cpp"
#include <iostream>
using namespace std;

int main(){
    Stack S;
    S.push("Y");
    S.push("N");
    S.push("O");
    S.push("T");
    cout << "Should print T O N Y: ";
    S.print();
    cout << "Length should be 4: " << S.get_length() << endl;
    cout << "Top should be T: " << S.get_top() << endl;
    S.pop();
    S.pop();
    cout << "Should print N Y: ";
    S.print();
    cout << "Length should be 2: " << S.get_length() << endl;
    S.push("T");
    S.push("O");
    Stack S1(S);
    cout << "Should print Same stack: ";
    if(S==S1){
        cout << "Same stack." << endl;
    } else {
        cout << "Different stack." << endl;
    }
}

/*
Results:
Should print T O N Y: T O N Y
Length should be 4: 4
Top should be T: T
Should print N Y: N Y
Length should be 2: 2
Should print Same stack: Same stack.
*/
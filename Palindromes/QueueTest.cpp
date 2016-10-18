/*
Antony Tejakusuma
CIS 22C
QueueTest.cpp
*/

#include "Queue.cpp"
#include <iostream>
using namespace std;

int main() {
    Queue q;
    cout << "Should print Queue is empty: ";
    if(q.is_empty()){
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
    q.enqueue("T");
    q.enqueue("O");
    q.enqueue("N");
    q.enqueue("Y");
    cout << "Should print T O N Y: ";
    q.print();
    cout << "Should print 4: " << q.get_length() << endl;
    cout << "Should print T: " << q.get_front() << endl;
    q.dequeue();
    cout << "Should print O N Y: ";
    q.print();
    cout << "Should print 3: " << q.get_length() << endl;
    cout << "Should print O: " << q.get_front() << endl;
    cout << "Should print Queue is not empty: ";
    if(q.is_empty()){
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }
    Queue q1(q);
    cout << "Should print same queue: ";
    if(q==q1){
        cout << "Same queue" << endl;
    } else {
        cout << "Different queue" << endl;
    }
}

/*
Results:
Should print Queue is empty: Queue is empty
Should print T O N Y: T O N Y
Should print 4: 4
Should print T: T
Should print O N Y: O N Y
Should print 3: 3
Should print O: O
Should print Queue is not empty: Queue is not empty
Should print same queue: Same queue
*/
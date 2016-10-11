/*
Antony Tejakusuma
CIS 22C
ListTest.cpp
*/

#include "Queue.cpp"
#include <iostream>
using namespace std;

int main()
{
    Queue q;
    q.enqueue("T");
    q.enqueue("O");
    q.enqueue("N");
    q.enqueue("Y");
    q.print();
    cout << q.get_length() << endl;
    cout << q.get_front() << endl;
    q.dequeue();
    q.print();
    cout << q.get_length() << endl;
    cout << q.get_front() << endl;

    Queue q1;
    q1.enqueue("T");
    q1.enqueue("O");
    q1.enqueue("N");
    q1.enqueue("Y");

    if(q==q1){
        cout << "Same queue" << endl;
    } else {
        cout << "Different queue" << endl;
    }
}

/*
Results:
=
*/
#include <iostream>
#include "Queue.h"
#include <assert.h>
using namespace std;

Queue::Queue(){}

Queue::Queue(const Queue &queue):length(queue.length)
{
    {
        if(queue.front == NULL)
        {
            end = front = NULL;
        }
       else
        {
            front = new Node;
            front->data = queue.front->data;
            NodePtr temp;
            temp = queue.front;
            NodePtr qtemp = front; //create temporary iterator

            while(temp->next != NULL)
            {

                qtemp->next = new Node;
                qtemp = qtemp->next;
                temp = temp->next;
                qtemp->data = temp->data;

            }

            end = qtemp;
        }
    }
}

Queue::~Queue()
{
    NodePtr temp = front;
    NodePtr temp2 = front;
    while (temp != NULL)
    {
        temp = temp->next;
        delete temp2;
        temp2 = temp;
    }
}

void Queue::dequeue(){
    assert(length != 0);
    if (length==1){
        delete front;
        front = end = NULL;
        length = 0;
    } else {
        NodePtr temp = front;
        front = front->next; //make the start pointer point to the second node in the List
        delete temp; //delete the original start
        length--;
    }
}

void Queue::enqueue(string data){
    if (length==0) {
        front = new Node(data);
        end = front;
    } else {
        NodePtr N = new Node(data);
        end->next = N;
        end = N;
    }
    length++;
}

bool Queue::operator==(const Queue &queue){
    if(length != queue.length)
        return false;
    NodePtr temp1 = front;
    NodePtr temp2 = queue.front;
    while(temp1 != NULL){
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

string Queue::get_front() {
    return front->data;
}

int Queue::get_length(){
    return length;
}

void Queue::print()
{
    NodePtr temp;
    temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
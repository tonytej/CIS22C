/*
Antony Tejakusuma
CIS 22C
List.h
*/

#include <cstddef> //for NULL
#include <assert.h>
#include <iostream>
using namespace std;

template <class listitem>
class List
{
    private:
             struct Node
             {
                listitem data;
                Node* next;
                Node* previous;
   
                Node(listitem data): next(NULL), previous(NULL), data(data){}
             };
   
             typedef struct Node* NodePtr;
   
             NodePtr start;
             NodePtr end;
             NodePtr cursor;
   
             int length;

             void reverse(NodePtr node);
             //Helper function for the public printReverse() function
             //Recursively prints the data ina a List in reverse
    public:
   
        /**Constructors and Destructors*/
   
        List();
        //Default constructor; initializes and empty list
        //Postcondition: data is empty and next is initialized to NULL
   
        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: dynamic memory allocated freed, no memory leaks
   
        List(const List &list);
        //Copy construcor. Initializes list to have the same elements as another list
        //Postcondition: newly created list is the same as another list
   
        /**Accessors*/
   
   
        listitem get_start();
        //Returns the first element in the list
        //Precondition: the list exists or has been initialized, start pointer contains data
   
   
        listitem get_end();
        //Returns the last element in the list
        //Precondition: the list exists or has been initialized, end pointer contains data
   
   
        listitem get_cursor();
        //Returns the element pointed to by the iterator
        //Precondition: the list exists or has been initialized, cursor pointer contains data
   
   
        bool is_empty();
        //Determines whether a list is empty.
   
   
   
        bool off_end();
        //Determines if the iterator is off the end of the list (i.e. whether cursor is NULL)
   
   
        int get_length();
        //Returns the length of the list
   
   
        /**Manipulation Procedures*/
   
        void begin_cursor();
        //Moves the iterator to point to the first element in the list
        //If the list is empty, the iterator remains NULL
        //Postcondition: cursor points to the first element in the list
   
   
        void add_cursor(listitem data);
        //Inserts a new element into the list in the position after the iterator
        //Precondition: cursor is pointing to a node in the list
        //Postcondition: a new node is positioned after the position where the iterator is pointing
   
        void remove_end();
        //Removes the value of the last element in the list
        //Precondition: the list exists or has been initialized, end pointer contains data
        //Postcondition: the last element in the list will hold no data
   
        void remove_start();
        //Removes the value of the first element in the list
        //Precondition: the list exists or has been initialized, start pointer contains data
        //Postcondition: the first element in the list will hold no data
   
        void add_end(listitem data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: new element will be added at the end of the list
   
        void add_start(listitem data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: new element will be added at the start of the list
   
   
        void remove_cursor();
        //Removes the element pointed at by the iterator
        //Precondition: the list exists or has been initialized, the cursor is pointing at an element in the list
        //Postcondition: the element which was pointed by the cursor is no more
   
        void move_cursor();
        //Moves the iterator forward by one element in the list
        //Precondition: the list exists or has been initialized, the cursor is pointing at an element in the list
        //Postcondition: the iterator is now ahead by one element in the list than it was before
   
   
        /**Additional List Operations*/
              
        void print();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty
    
        void print_reverse();
        //Wrapper function that calls the reverse helper function to print a list in reverse
        //prints nothing if the list is empty

        bool operator==(const List& list);
};

template <class listitem>
List<listitem>::List(): start(NULL), end(NULL), cursor(NULL), length(0) {}

template <class listitem>
List<listitem>::List(const List &list): length(list.length){
    if(list.start == NULL){ //If the original list is empty, make an empty list for this list{
        start = end = cursor = NULL;
    } else {
        start = new Node(list.start->data); //using second Node constructor
        NodePtr temp = list.start; //set a temporary node pointer to point at the start of the original list
        cursor = start; //set iterator to point to start of the new list
        while(temp->next != NULL){
            temp = temp->next; //advance up to the next node in the original list
            cursor->next = new Node(temp->data); //using node constructor to create a new node with copy of data
            cursor = cursor->next; //advance to this new node
        }
        end = cursor; //Why do I need this line of code?
        cursor = NULL;
    }
}

template <class listitem>
List<listitem>::~List(){
    cursor = start;
    NodePtr temp;
    while(cursor != NULL){
        temp = cursor->next;
        delete cursor;
        cursor = temp;
    }
}

template <class listitem>
void List<listitem>::remove_start(){
    assert(length != 0);
    if (length==1){
        delete start;
        start = end = cursor = NULL;
        length = 0;
    } else {
        if (cursor == start)
            cursor = NULL;
        start = start->next; //make the start pointer point to the second node in the List
        delete start->previous; //delete the original start
        start->previous = NULL;
        length--;
    }
}

template <class listitem>
void List<listitem>::remove_end(){
    assert(length != 0);
    if (length==1){
        delete start;
        start = end = cursor = NULL;
        length = 0;
    } else {
        if (cursor == end)
            cursor = NULL;
        end = end->previous; //make the start pointer point to the second node in the List
        delete end->next; //delete the original start
        end->next = NULL;
        length--;
    }
}

template <class listitem>
void List<listitem>::add_start(listitem data){
    if (length==0) {
        start = new Node(data);
        end = start;
    } else {
        NodePtr N = new Node(data);//create the new node by calling the node constructor
        N->next = start;//set the new node's next field to point to the start
        start->previous = N;
        start = N;//make the start be the new node
    }
    length++;
}

template <class listitem>
void List<listitem>::add_end(listitem data){
    if (length==0) {
        start = new Node(data);
        end = start;
    } else {
        NodePtr N = new Node(data);
        N->previous = end;
        end->next = N;
        end = end->next;
    }
    length++;
}

template<class listitem>
void List<listitem>::begin_cursor(){
    assert(length!=0);
    cursor = start;
}

template<class listitem>
void List<listitem>::remove_cursor(){
    assert(!off_end());
    if(cursor==start){
        remove_start();
    } else {
        cursor->previous->next = cursor->next;
        if(cursor!=end)
            cursor->next->previous = cursor->previous;
        delete cursor;
        cursor = NULL;
        length--;
    }
}

template<class listitem>
void List<listitem>::add_cursor(listitem data){
    assert(!off_end());
    if(cursor==end){
        add_end(data);
    } else {
        NodePtr N = new Node(data);
        N->next = cursor->next;
        N->previous = cursor;  
        N->next->previous = N;
        cursor->next = N;
        length++;
    }
}

template<class listitem>
void List<listitem>::move_cursor(){
    assert(!off_end());
    cursor = cursor->next;
}

template <class listitem>
listitem List<listitem>::get_start(){     
    assert(start != NULL); 
    return start->data;
}

template <class listitem>
listitem List<listitem>::get_end(){
    assert(end != NULL);
    return end->data;
}

template <class listitem>
bool List<listitem>::is_empty(){
    return (length==0);
}

template <class listitem>
int List<listitem>::get_length(){
    return length;
}

template <class listitem>
listitem List<listitem>::get_cursor(){
    assert(!off_end());  
    return cursor->data;
}

template<class listitem>
bool List<listitem>::off_end(){
    return (cursor==NULL);
}

template <class listitem>
void List<listitem>::print(){
    NodePtr temp = start; //create a temporary 
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; //What does this do?
}

template <class listitem>
bool List<listitem>::operator==(const List& list){
    if(length != list.length)
        return false;
    NodePtr temp1 = start;
    NodePtr temp2 = list.start;
    while(temp1 != NULL){
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

template <class listitem>
void List<listitem>::reverse(NodePtr node){
    if (node == NULL)
        return;
    reverse(node->previous);
    cout << node->data << " ";
}

template<class listitem>
void List<listitem>::print_reverse(){
    reverse(end);
}



















/*
Antony Tejakusuma
CIS 22C
Lab 1
*/

#include <cstddef> //for NULL

class List
{
    private:
             struct Node
             {
                int data;
                Node* next;
   
                Node(int data): next(NULL), data(data){}
             };
   
             typedef struct Node* NodePtr;
   
             NodePtr start;
             NodePtr end;
             NodePtr cursor;
   
             int length;
    public:
   
        /**Constructors and Destructors*/
   
        List();
        //Default constructor; initializes and empty list
        //Postcondition:
   
        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition:
   
        List(const List &list);
        //Copy construcor. Initializes list to have the same elements as another list
        //Postcondition:
   
        /**Accessors*/
   
   
        int get_start();
        //Returns the first element in the list
        //Precondition:
   
   
        int get_end();
        //Returns the last element in the list
        //Precondition:
   
   
        int get_cursor();
        //Returns the element pointed to by the iterator
        //Precondition:
   
   
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
        //Postcondition:
   
   
        void insert_cursor(int data);
        //Inserts a new element into the list in the position after the iterator
        //Precondition:
        //Postcondition:
   
        void remove_end();
        //Removes the value of the last element in the list
        //Precondition:
        //Postcondition:
   
        void remove_start();
        //Removes the value of the first element in the list
        //Precondition:
        //Postcondition:
   
        void add_end(int data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition:
   
        void add_start(int data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition:
   
   
        void remove_cursor();
        //Removes the element pointed at by the iterator
        //Precondition:
        //Postcondition:
   
        void move_cursor();
        //Moves the iterator forward by one element in the list
        //Precondition:
        //Postcondition:
   
   
        /**Additional List Operations*/
              
        void print();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty
};
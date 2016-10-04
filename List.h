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
        //Postcondition: data is empty and next is initialized to NULL
   
        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: dynamic memory allocated freed, no memory leaks
   
        List(const List &list);
        //Copy construcor. Initializes list to have the same elements as another list
        //Postcondition: newly created list is the same as another list
   
        /**Accessors*/
   
   
        int get_start();
        //Returns the first element in the list
        //Precondition: the list exists or has been initialized, start pointer contains data
   
   
        int get_end();
        //Returns the last element in the list
        //Precondition: the list exists or has been initialized, end pointer contains data
   
   
        int get_cursor();
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
   
   
        void insert_cursor(int data);
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
   
        void add_end(int data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: new element will be added at the end of the list
   
        void add_start(int data);
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
};
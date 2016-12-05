#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_


#include <cstddef>
#include <string>
#include <assert.h>
#include <iostream>


using namespace std;


template <class bstitem>
class BinarySearchTree
{
    private:
        struct Node
        {
                bstitem data;
                Node* left;
                Node* right;
                Node(bstitem newdata): data(newdata), left(NULL), right(NULL) {}
        };


        typedef struct Node* NodePtr;
        NodePtr root;


        /**Private helper functions*/
        bstitem minimumHelper(NodePtr root);


        bstitem maximumHelper(NodePtr root);


        NodePtr removeHelper(NodePtr root, bstitem value);


        bool findHelper(NodePtr root, bstitem value);
        
        int getSizeHelper(NodePtr root);


        int getHeightHelper(NodePtr root);


        void insertHelper(NodePtr root, bstitem value);
        //private helper function for insert
        //recursively inserts a value into the BST


        void inOrderPrintHelper(NodePtr root, ostream& s);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest
        void preOrderPrintHelper(NodePtr root, ostream& s);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder


        void postOrderPrintHelper(NodePtr root, ostream& s);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder


        /**Public functions*/


    public:
        BinarySearchTree();
        //Instantiates a new Binary Search Tree
        //post: a new Binary Search Tree object


        bstitem minimum();
        //finds the minimum value in the Binary Search Tree and returns it
        //pre: !isEmpty()


        bstitem maximum();
        //finds the maximum value in the Binary Search Tree and returns it
        //pre: !isEmpty()


        bool isEmpty();
        //determines whether the Binary Search Tree is empty


        int getSize();
        //returns the size of the tree


        bstitem getRoot();
        //returns the value stored at the root of the Binary Search Tree
        //pre: the Binary Search Tree is not empty


        int getHeight();
        //recursively finds the height of the tree and returns it
        //Pre: !isEmpty()


        bool find(bstitem value);
        //returns whether the value is in the tree
        //Pre: !isEmpty()


        void insert(bstitem value);
        //inserts a new value into the Binary Search Tree
        //post: a new value inserted into the Binary Search Tree


        void remove(bstitem value);
        //removes the specified value from the tree
        //Pre: !isEmpty()
        //Pre: The value is contained in the Binary Search tree


        void inOrderPrint(ostream& s);
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing


        void preOrderPrint(ostream& s);
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing
        void postOrderPrint(ostream& s);
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing
};
#endif /* BINARYSEARCHTREE_H_ */
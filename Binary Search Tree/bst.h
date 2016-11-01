#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <cstddef>
#include <string>

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

        void insertHelper(NodePtr root, bstitem value);
        //private helper function for insert
        //recursively inserts a value into the BST

        void inOrderPrintHelper(NodePtr root);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest

        void preOrderPrintHelper(NodePtr root);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder

        void postOrderPrintHelper(NodePtr root);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder

        /**Public functions*/

    public:
        BinarySearchTree();
        //Instantiates a new Binary Search Tree
        //post: a new Binary Search Tree object

        bool isEmpty();
        //determines whether the Binary Search Tree is empty

        void insert(bstitem value);
        //inserts a new value into the Binary Search Tree
        //post: a new value inserted into the Binary Search Tree

        bstitem getRoot();
        //returns the value stored at the root of the Binary Search Tree
        //pre: the Binary Search Tree is not empty

        void inOrderPrint();
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void preOrderPrint();
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void postOrderPrint();
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

};

#endif /* BINARYSEARCHTREE_H_ */
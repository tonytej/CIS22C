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

template<class bstitem>
BinarySearchTree<bstitem>::BinarySearchTree() : root(NULL) {}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::minimumHelper(NodePtr root){
    while(root != NULL){
        root = root->left;
    }
    return (root->left);
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::minimum(){
    assert(!isEmpty());
    return minimumHelper(root);
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::maximumHelper(NodePtr root){
    while(root != NULL){
        root = root->right;
    }
    return (root->left);
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::maximum(){
    assert(!isEmpty());
    return maximumHelper(root);
}

template<class bstitem>
bool BinarySearchTree<bstitem>::isEmpty(){
    return (root == NULL);
}

template<class bstitem>
int BinarySearchTree<bstitem>::getSize(){
    if (root == NULL){
        return 0;
    } else {
        return (getSize(root->left) + 1 + getSize(root->right));
    }
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::getRoot(){
    assert(!isEmpty());
    return root->data;
}

template<class bstitem>
int BinarySearchTree<bstitem>::getHeight(){
    assert(!isEmpty());
    NodePtr temp = root;
    if(temp == NULL){
        return 0;
    } else {
        return (max(getHeight(temp->left), getHeight(temp->right)) + 1);
    }
}

template<class bstitem>
bool BinarySearchTree<bstitem>::findHelper(NodePtr root, bstitem value){
    if(root->data == value){
        return true;
    } else if (value < root->data){
        if (root->left == NULL){
            return false;
        } else {
            return findHelper(root->left, value);
        }
    } else {
        if (root->right == NULL){
            return false;
        } else {
            return findHelper(root->right, value);
        }
    }
    return false;
}

template<class bstitem>
bool BinarySearchTree<bstitem>::find(bstitem value){
    assert(!isEmpty());
    if (value == root->data)
        return true;
    else
        return findHelper(root,value);
}

template <class bstitem>
void BinarySearchTree<bstitem>::insertHelper(NodePtr root, bstitem value){
    if(value == root->data){
        return;
    } else if(value < root->data){
        if(root->left == NULL){
            NodePtr N = new Node(value);
            root->left = N;
        } else {
            insertHelper(root->left, value);
        }
    } else {
        if(root->right == NULL){
            NodePtr N = new Node(value);
            root->right = N;
        } else {
            insertHelper(root->right, value);
        }
    }
}

template<class bstitem>
void BinarySearchTree<bstitem>::insert(bstitem value){
    if(root==NULL){
        root = new Node(value);
    } else {
        insertHelper(root, value);
    }
}

template<class bstitem>
typename BinarySearchTree<bstitem>::NodePtr BinarySearchTree<bstitem>::removeHelper(NodePtr root, bstitem value){
    if(root == NULL){
        return root;
    } else if (value < root->data){
        root->left = removeHelper(root->left, value);
    } else if (value > root->data){
        root->right = removeHelper(root->right, value);
    } else {
        if(root->left == NULL and root->right == NULL){
            delete root;
        } else if (root->right == NULL){
            root->left = root;
            delete root;
        } else if (root->left ==NULL){
            root->right = root;
            delete root;
        } else {
            root->data = minimumHelper(root->right);
            root->right = removeHelper(root-right, root->data); 
        }
    }
    return root;
}

template<class bstitem>
void BinarySearchTree<bstitem>::remove(bstitem value){
    assert(!isEmpty());
    assert(find(value));
    root = remove(root, value);
}

template<class bstitem>
void BinarySearchTree<bstitem>::inOrderPrintHelper(NodePtr root){
    if(root == NULL){
        return;
    } else {
        inOrderPrint(root->left);
        cout << root->data << " ";
        inOrderPrint(root->right);
    }
}

template<class bstitem>
void BinarySearchTree<bstitem>::inOrderPrint(){
   inOrderPrintHelper(root);
}

template<class bstitem>
void BinarySearchTree<bstitem>::preOrderPrintHelper(NodePtr root){
    if(root == NULL){
        return;
    } else {
        cout << root->data << " ";
        preOrderPrint(root->left);
        preOrderPrint(root->right);
    }
}

template<class bstitem>
void BinarySearchTree<bstitem>::preOrderPrint(){
    preOrderPrintHelper(root);
}

template<class bstitem>
void BinarySearchTree<bstitem>::postOrderPrintHelper(NodePtr root){
    if(root == NULL){
        return;
    } else {
        postOrderPrintHelper(root->left);
        postOrderPrintHelper(root->right);
        cout << root->data << " ";
    }
}

template<class bstitem>
void BinarySearchTree<bstitem>::postOrderPrint(){
    postOrderPrintHelper(root);
}


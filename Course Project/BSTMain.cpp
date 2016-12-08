/*
 *
 * Timothy Lee
 * CIS 22C
 * BSTMain.h
 *
 */


#ifndef BSTMain_H_
#define BSTMain_H_


#include <cstddef>
#include <string>
#include <assert.h>
#include <iostream>
#include <fstream>


using namespace std;


template <class bstitem>
class BSTMain
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


        //file output usage
        void inOrderPrintHelper(NodePtr root, ofstream& file);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest


        void preOrderPrintHelper(NodePtr root, ofstream& file);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder


        void postOrderPrintHelper(NodePtr root, ofstream& file);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder


        //regular cout usage
        void inOrderPrintHelper(NodePtr root);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest


        void preOrderPrintHelper(NodePtr root);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder


        void postOrderPrintHelper(NodePtr root);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder






        bool printHelper_by_title(NodePtr root, string value);
        bool printHelper_by_artist(NodePtr root, string value);
        bool printHelper_by_genre(NodePtr root, string value);

        bstitem findHelper_by_title(NodePtr root, string value);
        bstitem findHelper_by_artist(NodePtr root, string value);
        bstitem findHelper_by_genre(NodePtr root, string value);

        bstitem minimumHelper(NodePtr root);


        bstitem maximumHelper(NodePtr root);


        NodePtr removeHelper(NodePtr root, bstitem value);


        int getHeightHelper(NodePtr root);


        int getSizeHelper(NodePtr root);


        void copyHelperFunction(NodePtr root, NodePtr origin);

        bool findHelper(NodePtr root, bstitem value);

        void deconstructorHelper(NodePtr root);
        /**Public functions*/




    public:


        BSTMain();
        //Instantiates a new Binary Search Tree
        //post: a new Binary Search Tree object


        ~BSTMain();
        //destructor


        BSTMain(const BSTMain &BSTMain);


        bool isEmpty();
        //determines whether the Binary Search Tree is empty


        void insert(bstitem value);
        //inserts a new value into the Binary Search Tree
        //post: a new value inserted into the Binary Search Tree


        bstitem getRoot();
        //returns the value stored at the root of the Binary Search Tree
        //pre: the Binary Search Tree is not empty
/*
        //file output usage
        void inOrderPrint(ofstream& file);
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing


        void preOrderPrint(ofstream& file);
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing


        void postOrderPrint(ofstream& file);
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing
*/
        //regular cout usage
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


        bool print_by_title(string value);
        bool print_by_artist(string value);
        bool print_by_genre(string value);

        bstitem find_by_title(string value);
        bstitem find_by_artist(string value);
        bstitem find_by_genre(string value);


        bstitem minimum();


        bstitem maximum();


        void remove(bstitem value);


        int getHeight();


        int getSize();

        bool find(bstitem value);
};


//default construction


template <class bstitem>
BSTMain<bstitem>::BSTMain():root(NULL) {}


//deconstruction
template <class bstitem>
void BSTMain<bstitem>::deconstructorHelper(NodePtr root)
{
    if(root != NULL)
    {
        deconstructorHelper(root->left);
        deconstructorHelper(root->right);
        delete root;
    }
}
template <class bstitem>
BSTMain<bstitem>::~BSTMain()
{
    deconstructorHelper(root);
}


//copy construction


template <class bstitem>
BSTMain<bstitem>::BSTMain(const BSTMain &BST):root(BST.root)
{
    if(BST.root == NULL)
    {
        root = NULL;
    }
    else
    {
        copyHelperFunction(root, BST.root);
    }
}


template <class bstitem>
void BSTMain<bstitem>::copyHelperFunction(NodePtr root, NodePtr origin)
{
    if(origin != NULL)
    {
        root = new Node(origin->data);
        copyHelperFunction(root->left, origin->left);
        copyHelperFunction(root->right, origin->right);
    }
    else
    {
        root = NULL;
    }
}




//access functions


template <class bstitem>
bstitem BSTMain<bstitem>::minimum()
{
    assert(!isEmpty());
    return minimumHelper(root);
}


template <class bstitem>
bstitem BSTMain<bstitem>::minimumHelper(NodePtr root)
{
    if(root->left == NULL)
        return root->data;
    else
        minimumHelper(root->left);
}


template <class bstitem>
bstitem BSTMain<bstitem>::maximum()
{
    assert(!isEmpty());
    return maximumHelper(root);
}


template <class bstitem>
bstitem BSTMain<bstitem>::maximumHelper(NodePtr root)
{
    if(root->right == NULL)
        return root->data;
    else
        minimumHelper(root->right);
}


template <class bstitem>
bool BSTMain<bstitem>::isEmpty()
{
    if(root == NULL)
        return true;
    else
        return false;
}


template <class bstitem>
int BSTMain<bstitem>::getSize() //let you know how many elements in the list
{
    return getSizeHelper(root);
}


template <class bstitem>
int BSTMain<bstitem>::getSizeHelper(NodePtr root) 
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return getSizeHelper(root->left)+ 1 + getSizeHelper(root->right);
    }
}


template <class bstitem>
bstitem BSTMain<bstitem>::getRoot()
{
    assert(!isEmpty());
    return root->data;
}


///check
template <class bstitem>
int BSTMain<bstitem>::getHeight()
{
    assert(!isEmpty());
    return getHeightHelper(root);
}


template <class bstitem>
int BSTMain<bstitem>::getHeightHelper(NodePtr root)
{


    if(root == NULL)
        return 0;
    else
    {
        int leftHeight= getHeightHelper(root->left);
        int rightHeight = getHeightHelper(root->right);


    if(leftHeight >rightHeight)
        return leftHeight +1;
    else
        return rightHeight +1;
    }
}

template<class bstitem>
bool BSTMain<bstitem>::findHelper(NodePtr root, bstitem value){
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
bool BSTMain<bstitem>::find(bstitem value){
    assert(!isEmpty());
    if (value == root->data)
        return true;
    else
        return findHelper(root,value);
}
///check


//manipulation functions


template <class bstitem>
void BSTMain<bstitem>::insert(bstitem value)
{
    if (root == NULL)
    {
        root = new Node(value); //if the tree is empty insert the value at the root
    }
    else
    {
        insertHelper(root, value); //otherwise call the helper function, passing it the root
    }
}


template <class bstitem>
void BSTMain<bstitem>::insertHelper(NodePtr root, bstitem value)
{
    if(root->data.get_title() == value.get_title())
    {
        cout << "no same value allowed"<<endl;
    }


    if(value.get_title() < root->data.get_title())
    {
        if(root->left == NULL)
        {
            root->left = new Node(value);
        }
        else
        {
            insertHelper(root->left, value);
        }
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = new Node(value);
        }
        else
        {
            insertHelper(root->right, value);
        }
    }
}


template <class bstitem>
void BSTMain<bstitem>::remove(bstitem value)
{
    assert(!isEmpty());
    root = removeHelper(root, value);
}


template <class bstitem>
typename BSTMain<bstitem>::NodePtr BSTMain<bstitem>::removeHelper(NodePtr root, bstitem value)
{
    if(root == NULL)
    {
        return root;
    }
    else if(value.get_title() < root->data.get_title())
    {
        root->left = removeHelper(root->left, value);
    }
    else if(value.get_title() > root->data.get_title())
    {
        root->right = removeHelper(root->right, value);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
        }
        else if(root->left != NULL && root->right == NULL)
        {
            NodePtr temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->left == NULL && root->right != NULL)
        {
            NodePtr temp = root;
            root = root->right;
            delete temp;
        }
        else
        {
            bstitem min = minimum();
            root->data = min;
            root->right = removeHelper(root->right, min);
        }
    }
    return root;
}

//regular cout usage
template <class bstitem>
void BSTMain<bstitem>::inOrderPrint()
{
    if(root != NULL)
    {
        inOrderPrintHelper(root);
    }
}


template <class bstitem>
void BSTMain<bstitem>::inOrderPrintHelper(NodePtr root)
{
    if(root != NULL)
    {
        inOrderPrintHelper(root->left);
        root->data.print_song();
        cout << endl;
        inOrderPrintHelper(root->right);
    }
}


template <class bstitem>
void BSTMain<bstitem>::preOrderPrint()
{
    if(root != NULL)
    {
        preOrderPrintHelper(root);
    }
}


template <class bstitem>
void BSTMain<bstitem>::preOrderPrintHelper(NodePtr root)
{
    if(root != NULL)
    {
        root->data.print_song();
        cout << endl;
        preOrderPrintHelper(root->left);
        preOrderPrintHelper(root->right);
    }
}


template <class bstitem>
void BSTMain<bstitem>::postOrderPrint()
{
    if(root != NULL)
    {
        postOrderPrintHelper(root);
    }
}


template <class bstitem>
void BSTMain<bstitem>::postOrderPrintHelper(NodePtr root)
{
    if(root != NULL)
    {
        postOrderPrintHelper(root->left);
        postOrderPrintHelper(root->right);
        root->data.print_song();
        cout << endl;
    }
}


template <class bstitem>
bool BSTMain<bstitem>::print_by_title(string value)
{
    assert(!isEmpty());
    if (value == root->data.get_title())
    {
        cout << "Song found!" << endl;
        root->data.print_song();
        return true;
    }
    else
        return printHelper_by_title(root, value);
}


template <class bstitem>
bool BSTMain<bstitem>::printHelper_by_title(NodePtr root, string value)
{
    if(root->data.get_title() == value)
    {
        cout << "Song found!" << endl;
        root->data.print_song();
        return true;
    }
    else if(value < root->data.get_title())
    {
        if(root->left == NULL)
        {
            cout << " Song not found"<< endl;
            return false;
        }
        else
            printHelper_by_title(root->left, value);
    }
    else if(value > root->data.get_title())
    {
        if(root->right == NULL)
        {
                cout << " Song not found"<< endl;
                return false;
        }
        else
            printHelper_by_title(root->right, value);
    }
    else
    {
        cout << " Song not found"<< endl;
        return false;
    }
}
/////////////////////////////////////////////////////
template <class bstitem>
bool BSTMain<bstitem>::print_by_artist(string value)
{
    find_by_artist(value).print_song();
    return true;
}


template <class bstitem>
bool BSTMain<bstitem>::printHelper_by_artist(NodePtr root, string value)
{
    if(root->data.get_artist() == value)
    {
        cout << "Song found!" << endl;
        root->data.print_song();
        return true;
    }
    else if(value < root->data.get_artist())
    {
        if(root->left == NULL)
        {
            cout << " Song not found"<< endl;
            return false;
        }
        else
            printHelper_by_artist(root->left, value);
    }
    else if(value > root->data.get_title())
    {
        if(root->right == NULL)
        {
                cout << " Song not found"<< endl;
                return false;
        }
        else
            printHelper_by_artist(root->right, value);
    }
    else
    {
        cout << " Song not found"<< endl;
        return false;
    }
}
/////////////////////////////////////////////////////


template <class bstitem>
bool BSTMain<bstitem>::print_by_genre(string value)
{
    assert(!isEmpty());
    if (value == root->data.get_genre())
    {
        cout << "Song found!" << endl;
        root->data.print_song();
        return true;
    }
    else
        return printHelper_by_genre(root, value);
}


template <class bstitem>
bool BSTMain<bstitem>::printHelper_by_genre(NodePtr root, string value)
{
    if(root->data.get_genre() == value)
    {
        cout << "Song found!" << endl;
        root->data.print_song();
        return true;
    }
    else if(value < root->data.get_genre())
    {
        if(root->left == NULL)
        {
            cout << " Song not found"<< endl;
            return false;
        }
        else
            printHelper_by_genre(root->left, value);
    }
    else if(value > root->data.get_title())
    {
        if(root->right == NULL)
        {
                cout << " Song not found"<< endl;
                return false;
        }
        else
            printHelper_by_genre(root->right, value);
    }
    else
    {
        cout << " Song not found"<< endl;
        return false;
    }
}

template <class bstitem>
bstitem BSTMain<bstitem>::find_by_title(string value)
{
    assert(!isEmpty());
    if (value == root->data.get_title())
    {
        return root->data;
    }
    else
        return findHelper_by_title(root, value);
}


template <class bstitem>
bstitem BSTMain<bstitem>::findHelper_by_title(NodePtr root, string value)
{
    if(root->data.get_title() == value)
    {
        return root->data;
    }
    else if(value < root->data.get_title())
    {
        if(root->left == NULL)
        {
            cout << " Song not found"<< endl;
            return;
        }
        else
            findHelper_by_title(root->left, value);
    }
    else if(value > root->data.get_title())
    {
        if(root->right == NULL)
        {
                cout << " Song not found"<< endl;
                return;
        }
        else
            findHelper_by_title(root->right, value);
    }
    else
    {
        cout << " Song not found"<< endl;
        return;
    }
}

template <class bstitem>
bstitem BSTMain<bstitem>::find_by_artist(string value)
{
    assert(!isEmpty());
    if (value == root->data.get_artist())
    {
        return root->data;
    }
    else
        return findHelper_by_artist(root, value);
}


template <class bstitem>
bstitem BSTMain<bstitem>::findHelper_by_artist(NodePtr root, string value)
{
    if(root->data.get_artist() == value)
    {
        return root->data;
    }
    else if(value < root->data.get_artist())
    {
        if(root->left == NULL)
        {
            cout << " Song not found"<< endl;
            return;
        }
        else
            findHelper_by_artist(root->left, value);
    }
    else if(value > root->data.get_artist())
    {
        if(root->right == NULL)
        {
                cout << " Song not found"<< endl;
                return;
        }
        else
            findHelper_by_artist(root->right, value);
    }
    else
    {
        cout << " Song not found"<< endl;
        return;
    }
}

template <class bstitem>
bstitem BSTMain<bstitem>::find_by_genre(string value)
{
    assert(!isEmpty());
    if (value == root->data.get_genre())
    {
        return root->data;
    }
    else
        return findHelper_by_genre(root, value);
}


template <class bstitem>
bstitem BSTMain<bstitem>::findHelper_by_genre(NodePtr root, string value)
{
    if(root->data.get_genre() == value)
    {
        return root->data;
    }
    else if(value < root->data.get_genre())
    {
        if(root->left == NULL)
        {
            cout << " Song not found"<< endl;
            return;
        }
        else
            findHelper_by_genre(root->left, value);
    }
    else if(value > root->data.get_genre())
    {
        if(root->right == NULL)
        {
                cout << " Song not found"<< endl;
                return;
        }
        else
            findHelper_by_genre(root->right, value);
    }
    else
    {
        cout << " Song not found"<< endl;
        return;
    }
}

#endif /* BSTMain_H_ */


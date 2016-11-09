/*
Antony Tejakusuma
CIS22C
BinarySearchTreeTest.cpp
*/

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(){
    BinarySearchTree<int> tree;
    tree.insert(12);
    tree.insert(6);
    tree.insert(9);
    tree.insert(45);
    tree.insert(3);
    tree.insert(7);
    tree.insert(10);
    tree.insert(2);
    tree.insert(4);
    tree.insert(13); 
    cout << "Inserted some integers to the tree." << endl;    
    cout << "Inorder Printing. Should print 2 3 4 6 7 9 10 12 13 45: ";
    tree.inOrderPrint(cout);
    cout << endl << "Preorder Printing. Should print 12 6 3 2 4 9 7 10 45 13: ";
    tree.preOrderPrint(cout);
    cout << endl << "Postorder Printing. Should print 2 4 3 7 10 9 6 13 45 12: ";
    tree.postOrderPrint(cout);
    cout << endl;
    
    cout << "Minimum value. Should print 2: " << tree.minimum() << endl;
    cout << "Maximum value. Should print 45: " << tree.maximum() << endl;
    
    if(tree.isEmpty()){
        cout << "Tree is empty" << endl;
    } else {
        cout << "Tree is not empty" << endl;
    }

    cout << "Size. Should print 10: " << tree.getSize() << endl;
    cout << "Root. Should print 12: " << tree.getRoot() << endl;
    cout << "Height. Should print 3: " << tree.getHeight() << endl;
    
    cout << "Finding 15. ";
    if(tree.find(15)){
        cout << "Found 15" << endl;
    } else {
        cout << "Did not find 15" << endl;
    }

    cout << "Finding 10. ";
    if(tree.find(10)){
        cout << "Found 10" << endl;
    } else {
        cout << "Did not find 10" << endl;
    }

    cout << "Removing 13. " << endl;
    tree.remove(13);
    cout << "Inorder Printing. Should print 2 3 4 6 7 9 10 12 45: ";
    tree.inOrderPrint(cout);
    cout << endl << "Preorder Printing. Should print 12 6 3 2 4 9 7 10 45: ";
    tree.preOrderPrint(cout);
    cout << endl << "Postorder Printing. Should print 2 4 3 7 10 9 6 45 12: ";
    tree.postOrderPrint(cout);
    cout << endl;

    cout << "Minimum value. Should print 2: " << tree.minimum() << endl;
    cout << "Maximum value. Should print 45: " << tree.maximum() << endl;
    
    if(tree.isEmpty()){
        cout << "Tree is empty" << endl;
    } else {
        cout << "Tree is not empty" << endl;
    }

    cout << "Size. Should print 9: " << tree.getSize() << endl;
    cout << "Root. Should print 12: " << tree.getRoot() << endl;
    cout << "Height. Should print 3: " << tree.getHeight() << endl;
    
    cout << "Finding 13. ";
    if(tree.find(13)){
        cout << "Found 15" << endl;
    } else {
        cout << "Did not find 13" << endl;
    }
}

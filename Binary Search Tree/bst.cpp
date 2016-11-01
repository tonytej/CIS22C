/*
Antony Tejakusuma
CIS22C
bst.cpp
*/

#include <iostream>

using namespace std;

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

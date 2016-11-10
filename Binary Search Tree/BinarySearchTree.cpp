/*
Antony Tejakusuma
CIS22C
BinarySearchTree.cpp
*/

#include <iostream>
#include "BinarySearchTree.h"
#include <fstream>
#include <sstream>

using namespace std;

int main(){
    ifstream fin("infile.txt");
    if(fin.fail()){
        cout << "Input file failed to open.\n";
        exit(-1);
    }
    
    ofstream fout("outfile.txt");

    string line;
    int count = 1;
    BinarySearchTree<int>* tree = new BinarySearchTree<int>();
    while(getline(fin, line)){
        if(count == 1){
            istringstream iss(line);
            string word;
            int num;
            while(iss >> word){
                num = stoi(word);
                tree->insert(num);
                cout << "inserted" << endl;
            }
            tree->preOrderPrint(fout);
            fout << endl;
            tree->inOrderPrint(fout);
            fout << endl;
            count++;
            
        } else if (count == 2){

            int num = stoi(line);
            if(tree->find(num)){
                fout << num << " was found in the Binary Search Tree" << endl;
                tree->remove(num);
            } else {
                fout << num << " was not found in the Binary Search Tree" << endl;
            }
            count++;
        } else {
            int num = stoi(line);
            tree->insert(num);
            tree->postOrderPrint(fout);
            fout << endl;
            fout << "The root of the tree is " << tree->getRoot() << endl;
            fout << "The maximum value is " << tree->maximum() << endl;
            fout << "The minimum value is " << tree->minimum() << endl;
            fout << "The size of the Binary Search Tree is " << tree->getSize() << endl;
            fout << "The height of the Binary Search Tree is " << tree->getHeight() << endl << endl;
            count = 1;
            line = "";
            delete tree;
            BinarySearchTree<int>* tree = new BinarySearchTree<int>();
        }
    }
}

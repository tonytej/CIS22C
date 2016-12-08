#include "BinarySearchTree.h"
#include "Song.cpp"
#include <iostream>

using namespace std;

int main(){
	BinarySearchTree<Song> bst;
	Song a("a", "a", "a", "a");
	Song b("b", "b", "b", "b");
	Song c("c", "c", "c", "c");
	Song d("d", "d", "d", "d");
	Song e("e", "e", "e", "e");
	bst.insert(a);
	bst.insert(b);
	bst.insert(c);
	bst.insert(d);

	bst.inOrderPrint(cout);
	if(!bst.find(e)){
		cout << "did not found e" << endl;
		bst.insert(e);
	} else {
		cout << "found e" << endl;
	}

	bst.inOrderPrint(cout);
}
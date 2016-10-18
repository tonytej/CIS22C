/*
Antony Tejakusuma
CIS 22C
StackTest.cpp
*/

#include "Stack.cpp"
#include "Queue.cpp"
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("palindrome.txt");
    if (fin.fail()) {
        cout << "Input file failed to open.\n";
        exit(-1);
    }

    string line;
    
    while(getline(fin, line)){
        str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
str.erase(str.find_last_not_of(' ')+1);
        cout << line << endl;
    }
}

/*
Results:

*/
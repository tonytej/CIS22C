/*
Antony Tejakusuma
CIS 22C
Palindrome.cpp
*/

#include <algorithm>
#include "Stack.cpp"
#include "Queue.cpp"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
    ifstream fin("palindrome.txt");
    if (fin.fail()) {
        cout << "Input file failed to open.\n";
        exit(-1);
    }

    string line; // variable to store each line of the input
    Queue Q; // Queue to hold the modified version of the phrases that can easily be processed.
    Queue Q1; // Queue to store the original phrases with the symbols and spaces.
    Stack S; // Stack to reverse the phrase

    while(getline(fin, line)){
    	Q1.enqueue(line); // enqueue the original phrases
    	// The following for loop remove some characters
    	// of the phrases in order to simplify the 
        // process of checking Palindromes. The only 
        // thing that is needed is the alphabets of
        // the phrases.
        char chars[] = " .?!,'";
    	for (unsigned int i = 0; i < strlen(chars); ++i){
      		line.erase (remove(line.begin(), line.end(), chars[i]), line.end()); // removal of unwanted characters
   		}
        for(int i = 0; line[i]; i++){
  			line[i] = tolower(line[i]); // another modification. convert every alphabets to lowercase for ease of comparing.
		}	
        Q.enqueue(line); // enqueue modified phrases
    }

	while(Q.get_length() != 0){ // only checking Q because length of Q and Q1 is the same
    	string str = Q.get_front();
    	string ori = Q1.get_front();
	   	for(int i = 0; i < str.size(); i++){ // iterate through the modified phrase
	   		string letter(1, str[i]); // convert individual char to string
	   		S.push(letter); // push to stack
	   	}

	   	string rev; // variable to hold the reversed string
	   	while(S.get_length() != 0){ 
	   		rev += S.get_top(); //combine each reversed letter together
	   		S.pop();
	   	}

	   	if (str == rev){ // checking for palindromes
	   		ori += " (Palindrome)";
	   	} else {
	   		ori += " (Not a Palindrome)";
	   	}

	   	cout << ori << endl; // print original phrases with its palindrome status
	   	Q.dequeue(); // Processed phrase dequeued.
	   	Q1.dequeue(); // On to the next one.
    }  
}

/*
Results:
A man, a plan, a canal, Panama. (Palindrome)
Do geese see God? (Palindrome)
Never odd. Even. (Not a Palindrome)
Never odd or even. (Palindrome)
Eye (Palindrome)
Ear (Not a Palindrome)
Able was I ere I saw Elba! (Palindrome)
Was it Eliot's toilet I saw? (Palindrome)
Race cars (Not a palindrome)
*/

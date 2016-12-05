#include <iostream>

using namespace std;




const int SIZE = 10;

int main (){

	

	void assignID(string array[SIZE], string word);

	
	
	string assignment[SIZE];
	for (int i = 0; i < SIZE; i++){
		assignment[i] = " ";
	}

	string sample[6] = { "love", "mind", "time", "existence", "soccer", "passion"};
	for (int i = 0; i < 6; i++){
		assignID(assignment, sample[i]);
	}

	for (int i = 0; i < SIZE; i++){
		cout << i << ": " << assignment[i] << endl;
	}

	cout << assignment[] << endl;

}

void assignID(string array[SIZE], string word){
    	for(int i = 0; i < SIZE; i++){
     		if (array[i] == " "){
            	array[i] = word;
            	break;
        	}
    	}
	}


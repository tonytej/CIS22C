#include "Hash_Table.cpp"
#include <sstring>
#include <iostream>

using namespace std;

int main(){
	string lyrics[3] = {"I love you so much", "I love you", "I hate you"};
	search(string lyrics[], Hash_Table h, string value);
	Hash_Table h;

}

void mapping(string lyrics[], Hash_Table h, string value){
	for (int i = 0; i < lyrics.length(); i++){
		stringstream s(i);
		string word;
		for (int j = 0; s >> word; j++){
			if(word == value){
				h.insert(word);
				break;
			}
		}
	}
}
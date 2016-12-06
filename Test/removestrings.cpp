#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	void removeSubstrs(string& s, string& p);
	string useless[20] = { "an", "the" , "of", "to", "and", "but", "nor", "or", "some", "any",
							"very", "in", "on", "at", "before", "after", "into", "over", "through", "along"};
	string sample = "Waiting at the door to find you’re up to no good
You don’t have to like it
Knocks again, won’t leave though you wish it would
You don’t have to like it
It’s a reminder, a subliminal thing
You don’t have to like it
You’ve been acquainted before so don’t pretend to forget
This isn’t any different


How can we forget the almighty?
Go
Sh


It shows up to say I’m right and you’re wrong
You don’t have to like it
Knocks again and says you’ve known all along
You don’t have like it
It’s a reminder, a visceral thing
You don’t have to like it
Just when you think you’re alone, there’s no escaping it
You can never get away with it


How can we forget the almighty?
How can we forget the almighty?
Go
Sh


You don’t have to like it
You don’t have to like it
You don’t have to like it
You don’t have to like it
How can we forget the almighty?
How can we forget the almighty?
Go";


		vector<string> vec;
		istringstream iss(sample);
		while (iss) {
       		string word;
        	iss >> word;
        	transform(word.begin(), word.end(), word.begin(), ::tolower);
        	vec.push_back(word);
    	}
    	

    	for(int i = 0; i < vec.size(); i++){
    		for(int j = 0; j < 20; j++){
    			if(vec[i] == useless[j]){
    				vec.erase(remove_if(vec.begin(), vec.end(), [&]( const string& str )
    				{
        			return std::find(begin(useless), end(useless), str ) != end(useless);
    				}), vec.end()); 
    			}
    		}
    		cout << vec[i] << " ";
		}
		cout << endl;
	
	//ofstream fout("input.txt");

}
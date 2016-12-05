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

	ifstream fin("input.txt");
	if(fin.fail()){
		cout << "Input failed to open" << endl;
		exit(-1);
	}

	string line;
	getline(fin, line);
	getline(fin, line);
	getline(fin, line);
	getline(fin, line);

	ofstream fout("output.txt");

	int count = 1;
	while(getline(fin, line)){
		vector<string> vec;
		istringstream iss(line);
		while (iss) {
       		string word;
        	iss >> word;
        	transform(word.begin(), word.end(), word.begin(), ::tolower);
        	vec.push_back(word);
    	}
    	

    	for(int i = 0; i < vec.size(); i++){
    		for(int j = 0; j < 20; j++){

    			if(vec[i] == useless[j]){
    				cout << vec[i] << endl;
    				vec.erase(remove(vec.begin(), vec.end(), vec[i]), vec.end());
    			}
    		}
    		fout << vec[i] << " ";
		}
		fout << endl;
	}
	

	//ofstream fout("input.txt");

}
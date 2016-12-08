#include "Hash_Table.cpp"
#include "Hash_Table_Search.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Search {
	private:
		Hash_Table ht;
		Hash_Table_Search hts;
		string useless[21] = { "there", "a", "the" , "of", "to", "and", "but", "nor", "or", "some", "any",
							"very", "in", "on", "at", "before", "after", "into", "over", "through", "along"};
		string files[16] = { "almightygosh.txt", "areweready.txt", "byebye.txt", "electrify.txt", "explotar.txt", "highandlow.txt", "painting.txt",
							 "paperroute.txt", "porcelain.txt", "raging.txt", "sameoldblues.txt", "sendthemoff.txt", "shelter.txt", "surprise.txt", "tearingmeup.txt"};
	public:
		void buildAssignmentTable(){
			int count = 0;
			for (int i = 0; i < 15; i++){
				Song s;
				ifstream fin(files[i]);
				if(fin.fail()){
					cout << "Input failed to open" << endl;
					exit(-1);
				}
				
				string line;
				getline(fin, line);
				getline(fin, line);
				getline(fin, line);
				getline(fin, line);
				getline(fin, line);

				while(getline(fin, line)){
					vector<string> vec;
					istringstream iss(line);
					while (iss) {
			       		string word;
			        	iss >> word;
			        	transform(word.begin(), word.end(), word.begin(), ::tolower);
			        	vec.push_back(word);
			    	}
			    	for(int k = 0; k < vec.size(); k++){
			    		for(int j = 0; j < 21; j++){
			    			if(vec[k] == useless[j]){
			    				vec.erase(remove_if(vec.begin(), vec.end(), [&]( const string& str )
			    				{
			        			return std::find(begin(useless), end(useless), str ) != end(useless);
			    				}), vec.end());
			    			}
			    		}
			    		wordID w(vec[k], -1);
			    		if (hts.find(w) == -1){
			    			w.setID(count);
			    			hts.insert(w);
			    			count++;
			    		}
					}
				}		
			}
		}

		void buildInvertedIndex(){
			int count = 0;
			for (int i = 0; i < 15; i++){
				Song s;
				ifstream fin(files[i]);
				if(fin.fail()){
					cout << "Input failed to open" << endl;
					exit(-1);
				}
				
				string line;
				getline(fin, line);
				s.set_artist(line);
				getline(fin, line);
				s.set_title(line);
				getline(fin, line);
				s.set_genre(line);
				getline(fin, line);
				getline(fin, line);

				string lyric;

				while(getline(fin, line)){
					lyric += "\n" + line;
					s.set_lyrics(lyric);
					vector<string> vec;
					istringstream iss(line);
					while (iss) {
			       		string word;
			        	iss >> word;
			        	transform(word.begin(), word.end(), word.begin(), ::tolower);
			        	vec.push_back(word);
			    	}
			    	for(int k = 0; k < vec.size(); k++){
			    		for(int j = 0; j < 21; j++){
			    			if(vec[k] == useless[j]){
			    				vec.erase(remove_if(vec.begin(), vec.end(), [&]( const string& str )
			    				{
			        			return std::find(begin(useless), end(useless), str ) != end(useless);
			    				}), vec.end());
			    			}
			    		}
			    		wordID w(vec[k], -1);
			    		if (hts.find(w) == -1){
			    			w.setID(count);
			    			hts.insert(w);
			    			ht.insert(w, s);
			    			count++;
			    		}
					}
				}		
			}
		}

		void print_ht(){
			ht.print();
		}

		void print_hts(){
			hts.print();
		}
};

int main(){
	Search s;
	s.search();
	s.print_ht();
	//s.print_hts();
}


/*1. Read in a word from a file
2. Determine whether it has already been assigned an id
2a. Search the wordid hash table to see if the word is there.
2aa. If the word is found in the WordID hash table, return it's id
2ab. If the word is not found in the WordID hash table, assign it an id = counter++; and insert it into the wordID hash table
3. Insert the Haiku that contains that word into the hash table at index = id*/
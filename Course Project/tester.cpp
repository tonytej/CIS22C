#include "BST.cpp"
#include "Search.cpp"
#include <iostream>

using namespace std;

void addSong(BST<Song> bst, Search se){
	string title;
	string artist;
	string genre;
	string lyrics;
	cout << "Title: ";
	cin >> title;

	cout << "Artist: ";
	cin >> artist;
	
	cout << "Genre: ";
	cin >> genre;
	
	cout << "Lyrics: ";
	cin >> lyrics;
	
	Song s(title, artist, genre, lyrics);
	bst.insert(s);
	se.insert(s);
}

void removeSong(BST<Song> bst, Search se){
	string song;
	cout << "Song to be removed: ";
	cin >> song;
	cout << "bst passed" << endl;
	bst.remove(song);
	
	se.remove(song);
}

/*void statistics(BST bst, Search se){

}*/

void populateBST(BST<Song> bst){
	vector<string> files = { "almightygosh.txt", "areweready.txt", "byebye.txt", "electrify.txt", "explotar.txt", "highandlow.txt", "painting.txt",
                        "paperroute.txt", "porcelain.txt", "raging.txt", "sameoldblues.txt", "sendthemoff.txt", "shelter.txt", "surprise.txt", "tearingmeup.txt"};
	for (int i = 0; i < files.size(); i++){
        Song s;
        ifstream fin(files[i]);
        if(fin.fail()){
        	cout << "Input failed to open" << endl;
         	exit(-1);
        }
               
        string line;
        getline(fin, line); //first line
        s.set_artist(line);
        getline(fin, line); //second line
        s.set_title(line);
        getline(fin, line); //third line
        s.set_genre(line);
        getline(fin, line);
        getline(fin, line);

        string lyric;

        while(getline(fin, line)){ //get rest of the line
            lyric += "\n" + line;
            s.set_lyrics(lyric);
        }
        bst.insert(s);      //insert s to the BST
	}
}
int main(){
	BST<Song> bst;
	Search se;
	se.buildAssignmentTable();
	se.buildInvertedIndex();
	vector<string> files = { "almightygosh.txt", "areweready.txt", "byebye.txt", "electrify.txt", "explotar.txt", "highandlow.txt", "painting.txt",
                        "paperroute.txt", "porcelain.txt", "raging.txt", "sameoldblues.txt", "sendthemoff.txt", "shelter.txt", "surprise.txt", "tearingmeup.txt"};
	for (int i = 0; i < files.size(); i++){
        Song s;
        ifstream fin(files[i]);
        if(fin.fail()){
        	cout << "Input failed to open" << endl;
         	exit(-1);
        }
               
        string line;
        getline(fin, line); //first line
        s.set_artist(line);
        getline(fin, line); //second line
        s.set_title(line);
        getline(fin, line); //third line
        s.set_genre(line);
        getline(fin, line);
        getline(fin, line);

        string lyric;

        while(getline(fin, line)){ //get rest of the line
            lyric += "\n" + line;
            s.set_lyrics(lyric);
        }
        bst.insert(s);      //insert s to the BST
	}

	cout << bst.getSize() << endl; //15

	addSong(bst, se);
	cout << bst.getSize() << endl;//16
	//removeSong(bst, se);
	cout << bst.getSize() << endl;//15
}	
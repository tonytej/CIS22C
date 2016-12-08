#include <iostream>
#include "Search.cpp"



using namespace std;


int main() {
    Search se;
    void addSong(Song s);
    void removeSong(Song s);

    string repeat = "n";
    do {
        int input;
        cout << "1. Display Catalog" << endl;
        cout << "2. Remove Song" << endl;
        cout << "3. Add Song" << endl;
        cout << "4. Search for Song" << endl;
        cout << "5. Download Song" << endl;
        cout << "6. Statistics" << endl;
        cout << "Type number according to your selection" << endl;
        cin >> input;
    } while(repeat == "y")

    if (input == 1)
    {
        int in;
        cout << "Song Catalog" << endl;
        cout << "1. Unsorted Song List" << endl;
        cout << "2. Song List sorted by Title" << endl;
        cout << "3. Return" << endl;
        cin << in;
        if (in == 1) {
            preOrderPrint();    //call post or pre order print on the BST
        }

        If (in == 2){
            inOrderPrint();      //call inOrderPrint on the BST
        }

        If (in == 3) {


        }
            }


    else if (input == 2)
    {
        cout << "Please type in the song name that you wish to remove:" << endl;
        cin >> value;
        remove(bstitem value);
        //cout << song.get_title() << “has been successfully removed!” << endl;
        
    }


    else if (input == 3)
    {
        string data;
        cout << “Please type in the file name: “ << endl;
        cin >> data;
    }


    else if (input == 4)
    {
        int in;
        cout << "Search Submenu" << endl;
        cout << "1. Search by Artist" << endl;
        cout << "2. Search by Song Title" << endl;
        cout << "3. Search by Genre" << endl;
        cout << "4. Search by Lyrics" << endl;
        cin >> in;
        if (in == 1)
        {
        cout << "Search a song by it's artist" << endl;
        cout << "Type in the artist name you wish to search for: " << endl;


        }
 

        if (in == 2)
        {
        cout << "Search a song by the song name" << endl;
        cout << "Type in the song name you wish to search for: " << endl;
        }
        
        if (in == 3)
        {
            cout << "Search a song by the genre" << endl;
            cout << "Type in the genre you wish to search for: " << endl;
        }
        
        if (in == 4)
        {
            cout << "Type in a word you wish to search for: " << endl;
            string word;
            cin >> word;
            cout << "Here are the songs that contain the word " << word << ": " << endl;
            se.searchKeyword(word);

        }


    }


    else if (input == 5)
    {
              //code for the user to download song
    }
    
    else if(input == 6)
    {
int input2;
    cout << "1. Number of Genres in the Soundtrack" << endl;
    cout << "2. Number of Songs in each genre" << endl;
    cout << "3. Number of Songs in list" << endl;
If (input2 == 1) {


}
If (input2 == 2) {


}


If (input2 == 3) {
getSize();
}
    
}





#include "Hash_Table.h"
#include <iostream>
#include <assert.h>



using namespace std;

Hash_Table::Hash_Table(){}

Hash_Table::~Hash_Table(){}

int Hash_Table::hash(wordID b){
    return b.getID();
}

/*int Hash_Table::count_bucket(int index){
    return Table[index].getSize();
}*/

bool Hash_Table::find(Song b){
    for(int i = 0; i < SIZE; i++){
        return Table[i].find(b);
    }
}

void Hash_Table::insert(wordID b, Song s){
    int index = hash(b);
    Table[index].insert(s);
}

/*void Hash_Table::remove(Song b){
    int TableIndex = hash(b.get_title()+b.get_artist()); 
    if(Table[TableIndex].get_length() != 0){
        int ListIndex = Table[TableIndex].linear_search(b);
        if(ListIndex != -1){
            Table[TableIndex].scroll_to_index(ListIndex);
            Table[TableIndex].remove_cursor();
        } else {
            cout << "Song is not in the table." << endl;
        }
    } else {
        cout << "Song is not in the table." << endl;
    }    
}

void Hash_Table::print_bucket(int index){
    assert(index >= 0 and index < SIZE);
    cout << "Printing bucket: " << index << endl << endl;
    Table[index].begin_cursor();
    while(!Table[index].off_end()){
        Song temp = Table[index].get_cursor();
        cout << temp.get_title() << endl;
        cout << "by " << temp.get_artist() << endl;
        cout << "Genre: " << temp.get_genre() << endl;
        cout << "Lyrics: " << temp.get_lyrics() << endl << endl;
        Table[index].move_cursor();
    }
}

void Hash_Table::print_table(){
    for(int i = 0; i < SIZE; i++){
        if(!Table[i].is_empty()){
            Song temp = Table[i].get_start();
            cout << "<---------------------->" << endl;
            cout << "Bucket: " << i << endl;
            cout << temp.get_title() << endl;
            cout << "by " << temp.get_artist() << endl;
            cout << "Genre: " << temp.get_genre() << endl;
            cout << "Lyrics: " << temp.get_lyrics() << endl;
            cout << "Number of Songs at this bucket: " << Table[i].get_length() << endl;
            cout << "<---------------------->" << endl << endl;
        }
    }
}*/
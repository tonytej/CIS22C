/*
Antony Tejakusuma
CIS22C
Hash_Table.cpp
*/

#include "Hash_Table.h"
#include <iostream>
#include <assert.h>

using namespace std;

Hash_Table::Hash_Table(){
    for (int i = 0; i < SIZE; i++){
        Table[i] = " ";
    }
}

Hash_Table::~Hash_Table(){}

int Hash_Table::hash(string key){
    

int Hash_Table::count_bucket(int index){
    assert(index >= 0 and index < SIZE);
    if(index >= 0 and index < SIZE){
        return Table[index].get_length();
    } else {
        return -1;
    }
}

int Hash_Table::find(Song b){
    for(int i = 0; i < SIZE; i++){
        if(!Table[i].is_empty()){
            Table[i].begin_cursor();
            while(!Table[i].off_end()){  
                if(Table[i].get_cursor() == b)
                    return i;
                Table[i].move_cursor();
            }
        }
    }
    return -1;
}

void Hash_Table::insert(Song b){
    int index = hash(b.get_title()+b.get_artist());
    Table[index].add_end(b);
}

void Hash_Table::remove(Song b){
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
        cout << "Lyrics: $" << temp.get_lyrics() << endl << endl;
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
            cout << "Genre: " << temp.get_Genre() << endl;
            cout << "Lyrics: $" << temp.get_lyrics() << endl;
            cout << "Number of Songs at this bucket: " << Table[i].get_length() << endl;
            cout << "<---------------------->" << endl << endl;
        }
    }
}

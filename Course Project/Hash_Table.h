#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_


#include <string>
#include "List.h"
#include "Song.h"
using namespace std;


class Hash_Table {
public:
    /**Constructors*/


    Hash_Table();
    //constructor


    ~Hash_Table();
    //destructor


    /**Access Functions*/


    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: title + author


    int count_bucket(int index);
    //counts the number of Books at this index
    //returns the count
    //pre: 0<= index < SIZE


    int search_by_title(Song t);
    //Searches for t in the table
    //returns the index at which t is located
    //returns -1 if t is not in the table


    bool search_by_artist(Song a);
    //Searches for a in the table
    //returns the index at which a is located
    //returns -1 if a is not in the table


    bool search_by_genre(Song g);
    //Searches for g in the table
    //returns the index at which g is located
    //returns -1 if g is not in the table

    void assignID(string word){
        for(int i = 0; i < SIZE; i++){
            if (assignment[i] == -1){
                assignment[i] = word;
                break;
            }
        }
    }

    /**Manipulation Procedures*/


    void display();
    //Prints in the format:
    //<------------------------>
    //<title>
    //by <artist>
    //Genre: <genre>
    //Lyrics: <lyrics>
    //<----------------------->
private:
    static const int SIZE = 10;
    List<Song> Table[SIZE];
    string assignment[SIZE];
};


#endif /* HASH_TABLE_H_ */
/*
Antony Tejakusuma
CIS22C
Hash_Table.cpp
*/

#include "Hash_Table.h"
#include <iostream>
#include <assert.h>

using namespace std;

Hash_Table::Hash_Table(){}

Hash_Table::~Hash_Table(){}

int Hash_Table::hash(string key){
    int index, sum = 0;
    for(int i = 0; i < key.length(); i++)
        sum += (int) key[i];
    index = sum % SIZE;
    return index;
}

int Hash_Table::count_bucket(int index){
    assert(index >= 0 and index < SIZE);
    if(index >= 0 and index < SIZE){
        return Table[index].get_length();
    } else {
        return -1;
    }
}

int Hash_Table::find(Book b){
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

void Hash_Table::insert(Book b){
    int index = hash(b.get_title()+b.get_author());
    Table[index].add_end(b);
}

void Hash_Table::remove(Book b){
    int TableIndex = hash(b.get_title()+b.get_author()); 
    if(Table[TableIndex].get_length() != 0){
        int ListIndex = Table[TableIndex].linear_search(b);
        if(ListIndex != -1){
            Table[TableIndex].scroll_to_index(ListIndex);
            Table[TableIndex].remove_cursor();
        } else {
            cout << "Book is not in the table." << endl;
        }
    } else {
        cout << "Book is not in the table." << endl;
    }    
}

void Hash_Table::print_bucket(int index){
    assert(index >= 0 and index < SIZE);
    cout << "Printing bucket: " << index << endl << endl;
    Table[index].begin_cursor();
    while(!Table[index].off_end()){
        Book temp = Table[index].get_cursor();
        cout << temp.get_title() << endl;
        cout << "by " << temp.get_author() << endl;
        cout << "ISBN#: " << temp.get_isbn() << endl;
        cout << "Price: $" << temp.get_price() << endl << endl;
        Table[index].move_cursor();
    }
}

void Hash_Table::print_table(){
    for(int i = 0; i < SIZE; i++){
        if(!Table[i].is_empty()){
            Book temp = Table[i].get_start();
            cout << "<---------------------->" << endl;
            cout << "Bucket: " << i << endl;
            cout << temp.get_title() << endl;
            cout << "by " << temp.get_author() << endl;
            cout << "ISBN#: " << temp.get_isbn() << endl;
            cout << "Price: $" << temp.get_price() << endl;
            cout << "Number of books at this bucket: " << Table[i].get_length() << endl;
            cout << "<---------------------->" << endl << endl;
        }
    }
}

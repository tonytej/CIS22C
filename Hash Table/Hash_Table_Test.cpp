/*
Antony Tejakusuma
CIS22C
Hash_Table_Test.cpp
*/
#include "Hash_Table.cpp"
#include "Book.cpp"
#include <iostream>

using namespace std;

int main(){
	Hash_Table ht;
    Book pp("Pride and Prejudice", "Jane Austen", 1234567, 4.95);
    Book c("Contact", "Carl Sagan", 99993339, 9.95);
    Book hg("The Hunger Games", "Suzanne Collins", 12388888, 13.55);
    Book hp("Harry Potter", "J.K. Rowlings", 55555678, 12.99);
    Book mhc("The Man in the High Castle", "Philip K Dick", 95959595, 15.95);
    Book bh("Bleak House", "Charles Dickens", 473890238, 8.00);
    ht.insert(pp);
    ht.insert(c);
    ht.insert(hg);
    ht.insert(mhc);
    ht.insert(bh);
    ht.insert(hp);    
    cout << "Inserted 6 books." << endl;
    cout << "Counting bucket 9. Should print 2: " << ht.count_bucket(9) << endl;
    cout << "Counting bucket 2. Should print 1: " << ht.count_bucket(0) << endl;
    cout << "Counting bucket 1. Should print 0: " << ht.count_bucket(1) << endl << endl;
    cout << "Finding Harry Potter. Should print 4: " << ht.find(hp) << endl;
    cout << "Finding Pride and Prejudice. Should print 2: " << ht.find(pp) << endl;
    cout << "Finding Contact. Should print 4: " << ht.find(c) << endl << endl;
    ht.print_bucket(4);
    cout << "Removing Contact." << endl;
    ht.remove(c);
    cout << "Finding Contact. Should print -1: " << ht.find(c) << endl << endl;
    ht.print_bucket(4);
    ht.print_table();
}

/*
Inserted 6 books.
Counting bucket 9. Should print 2: 2
Counting bucket 2. Should print 1: 1
Counting bucket 1. Should print 0: 0

Finding Harry Potter. Should print 4: 4
Finding Pride and Prejudice. Should print 2: 2
Finding Contact. Should print 4: 4

Printing bucket: 4

Contact
by Carl Sagan
ISBN#: 99993339
Price: $9.95

Harry Potter
by J.K. Rowlings
ISBN#: 55555678
Price: $12.99

Removing Contact.
Finding Contact. Should print -1: -1

Printing bucket: 4

Harry Potter
by J.K. Rowlings
ISBN#: 55555678
Price: $12.99

<---------------------->
Bucket: 0
Bleak House
by Charles Dickens
ISBN#: 473890238
Price: $8
Number of books at this bucket: 1
<---------------------->

<---------------------->
Bucket: 2
Pride and Prejudice
by Jane Austen
ISBN#: 1234567
Price: $4.95
Number of books at this bucket: 1
<---------------------->

<---------------------->
Bucket: 4
Harry Potter
by J.K. Rowlings
ISBN#: 55555678
Price: $12.99
Number of books at this bucket: 1
<---------------------->

<---------------------->
Bucket: 9
The Hunger Games
by Suzanne Collins
ISBN#: 12388888
Price: $13.55
Number of books at this bucket: 2
<---------------------->

*/

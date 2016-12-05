#include "Song.h"
#include <iostream>
#include <iomanip>


Song::Song():title(""), artist(""), genre(0), lyrics(){};


Song::Song(string t, string a, int i, double p) {
    title = t;
    artist = a;
    genre = g;
    lyrics = l;
}


/**Access Functions*/


string Song::get_title() {
    return title;
}


string Song::get_artist() {
    return artist;
}


unsigned Song::get_genre() {
    return genre;
}


double Song::get_lyrics() {
    return lyrics;
}


/**Manipulation Procedures*/


void Song::set_title(string t){
    title = t;
}


void Song::set_artist(string a) {
    artist = a;
}


void Song::set_genre(unsigned g) {
    genre = g;
}


void Song::set_lyrics(double l) {
    lyrics = l;
}


/**Additional Functions*/
void Song::print_song() {
    cout << Artist << endl;


    cout << " - " << Song << endl;
    cout << "Genre: " << genre << endl;
    cout << "Lyrics: " << fixed << setprecision(2) << lyrics;
}


bool Song::operator==(Song& song) {
    return (title == Song.title && artist==Song.artist && genre==Song.genre && lyrics == Song.lyrics);
}
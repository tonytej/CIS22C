#include "Song.h"
#include <iostream>
#include <iomanip>


Song::Song():title(""), artist(""), genre(0), lyrics(){};


Song::Song(string t, string a, string g, string l) {
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


string Song::get_genre() {
    return genre;
}


string Song::get_lyrics() {
    return lyrics;
}

/**Manipulation Procedures*/


void Song::set_title(string t){
    title = t;
}


void Song::set_artist(string a) {
    artist = a;
}


void Song::set_genre(string g) {
    genre = g;
}


void Song::set_lyrics(string l) {
    lyrics = l;
}


/**Additional Functions*/
void Song::print_song() {
    cout << "Title: " << title << endl;
    cout << "By: " << artist << endl;
    cout << "Genre: " << genre << endl;
    cout << "Lyrics: " << fixed << setprecision(2) << lyrics << endl;
}


bool Song::operator==(Song& song) {
    return (title == song.title && artist == song.artist && genre==song.genre && lyrics == song.lyrics);
}
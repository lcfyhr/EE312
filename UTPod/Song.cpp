//
// Created by vbhon on 3/27/2020.
//

#include "Song.h"
#include <iostream>
#include <string>

Song::Song() {
    title = "";
    artist = "";
    size = 0;
}

Song::Song(string _title, string _artist, int _size) {
    title = _title;
    artist = _artist;
    size = _size;
}

string Song::getTitle() const {
    return title;
}

void Song::setTitle(string _title) {
    title = _title;
}

string Song::getArtist() const {
    return artist;
}

void Song::setArtist(string _artist) {
    artist = _artist;
}

int Song::getSize() const {
    return size;
}

void Song::setSize(int _size) {
    size = _size;
}

bool Song::operator>(Song const &rhs) {
    if (artist > rhs.artist) {
        return true;
    } else if (artist == rhs.artist) {
        if (title > rhs.title) {
            return true;
        } else if (title == rhs.title) {
            if(size > rhs.size) {
                return true;
            }
        }
    }
    return false;
}

bool Song::operator<(Song const &rhs) {
    if (artist < rhs.artist) {
        return true;
    } else if (artist == rhs.artist) {
        if (title < rhs.title) {
            return true;
        } else if (title == rhs.title) {
            if (size < rhs.size) {
                return true;
            }
        }
    }
    return false;
}

bool Song::operator==(Song const &rhs) {
    return( title == rhs.title &&
            artist == rhs.artist &&
            size == rhs.size);
}

Song::~Song() {

}
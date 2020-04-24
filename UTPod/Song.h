//
// Created by vbhon on 3/27/2020.
//

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <iostream>
#include <string>
using namespace std;

class Song{
    private:
    	string title;
    	string artist;
    	int size;

    public:
    	Song ();
    	Song (string _title, string _artist, int _size);

    	string getTitle() const;
    	void setTitle(string _title);

    	string getArtist() const;
    	void setArtist(string _artist);

    	int getSize() const;
    	void setSize(int _size);

    	bool operator >(Song const &rhs);
    	bool operator <(Song const &rhs);
    	bool operator ==(Song const &rhs);

    	~Song();
};

#endif //UTPOD_SONG_H
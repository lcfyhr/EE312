//
// Created by vbhon on 3/27/2020.
//

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>


#include "UTPod.h"
#include "Song.h"

using namespace std;

UtPod::UtPod() {
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
    songs = NULL;
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int _memSize) {
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
    songs = NULL;
    if (_memSize > 0 && _memSize <= 512) {
        memSize = _memSize;
    } else {
        memSize = MAX_MEMORY;
    }
}

int UtPod::addSong(Song const &s) {
    if (s.getSize() > getRemainingMemory() || s.getSize() <= 0 || s.getTitle().empty() || s.getArtist().empty()) {
        return NO_MEMORY;
    } else {
        SongNode* tempSongNode = new SongNode();
        tempSongNode -> s = s;
        tempSongNode -> next = songs;
        songs = tempSongNode;
        return SUCCESS;
    }
}

int UtPod::removeSong(Song const &s) {
    SongNode* tempSongNode = songs;
    SongNode* lastSongNode = NULL;
    while (tempSongNode != NULL) {
        if (tempSongNode -> s == s) {
            if (lastSongNode == NULL) {
                songs = tempSongNode -> next;
            } else {
                lastSongNode -> next = tempSongNode -> next;            // bridges deletion
            }
            delete tempSongNode;
            return SUCCESS;
        } else {
            lastSongNode = tempSongNode;
            tempSongNode = tempSongNode -> next;
        }
    }
    return NOT_FOUND;
}

int UtPod::getTotalSongs() {
    int totalsongs = 0;
    SongNode* tempSongNode = songs;
    while (tempSongNode != NULL) {
        tempSongNode = tempSongNode -> next;
        totalsongs++;
    }
    return totalsongs;
}

void UtPod::showSongList() {
    SongNode* tempSongNode = songs;
    while (tempSongNode != NULL) {
        cout << "Title: " << tempSongNode -> s.getTitle() << ", Artist: " << tempSongNode -> s.getArtist() << ", Size: " << tempSongNode -> s.getSize() << " MB" << endl;
        tempSongNode = tempSongNode -> next;
    }
}

void UtPod::sortSongList() {
    if (getTotalSongs() < 2) {
        return;
    }
    SongNode* tempSongNode1 = songs;
    SongNode* tempSongNode2 = NULL;
    while (tempSongNode1 != NULL) {
        tempSongNode2 = tempSongNode1 -> next;
        while (tempSongNode2 != NULL) {
            if (tempSongNode1 -> s > tempSongNode2 -> s) {
                Song tempSong = tempSongNode2 -> s;
                tempSongNode2 -> s = tempSongNode1 -> s;
                tempSongNode1 -> s = tempSong;
            }
            tempSongNode2 = tempSongNode2 -> next;
        }
        tempSongNode1 = tempSongNode1 -> next;
    }
}

void UtPod::shuffle() {
    int totalSongs = getTotalSongs();
    for (int i = 0; i < totalSongs; i++) {
        int r1 = (rand() % totalSongs);
        int r2 = (rand() % totalSongs);
        SongNode* tempSongNode1 = songs;
        SongNode* tempSongNode2 = songs;
        for (int j = 0; j < r1; j++) {
            tempSongNode1 = tempSongNode1 -> next;
        }
        for (int k = 0; k < r2; k++) {
            tempSongNode2 = tempSongNode2 -> next;
        }
        Song tempSong = tempSongNode2 -> s;
        tempSongNode2 -> s = tempSongNode1 -> s;
        tempSongNode1 -> s = tempSong;
    }
}

int UtPod::getTotalMemory() {
    return memSize;
}

int UtPod::getRemainingMemory() {
    int memUsed = 0;
    SongNode* tempSongNode = songs;
    while (tempSongNode != NULL) {
        memUsed += tempSongNode -> s.getSize();
        tempSongNode = tempSongNode -> next;
    }
    return (getTotalMemory() - memUsed);
}

void UtPod::clearMemory() {
    SongNode* tempSongNode = songs;
    while(tempSongNode != NULL){
        songs = songs -> next;
        delete tempSongNode;
        tempSongNode = songs;
    }
}

UtPod::~UtPod() {
    this->clearMemory();
}


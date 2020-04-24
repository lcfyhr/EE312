#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UTPod.h"

using namespace std;

int main(int argc, char *argv[])
{
	cout << "---------------------Testing UtPod Memory Size-----------------------------\n" << endl;
	UtPod TexasPod256(256);
	UtPod TexasPodMax(512);
	UtPod TexasPodZero(0);
    UtPod TexasPodNegative(-120);
    UtPod TexasPodOversize(513);
    UtPod TexasPodNoSize;

    cout << "~TexasPod256 (input = 256)~\nExpected size: 256 MB\nActual Size: " << TexasPod256.getTotalMemory() << " MB\n" << endl;
    cout << "~TexasPodMax (input = 512)~\nExpected size: 512 MB\nActual Size: " << TexasPodMax.getTotalMemory() << " MB\n" << endl;
    cout << "~TexasPodZero (input = 0)~\nExpected size: 512 MB\nActual Size: " << TexasPodZero.getTotalMemory() << " MB\n" << endl;
    cout << "~TexasPodNegative (input < 0)~\nExpected size: 512 MB\nActual Size: " << TexasPodNegative.getTotalMemory() << " MB\n" << endl;
    cout << "~TexasPodOversize (input > 512)~\nExpected size: 512 MB\nActual Size: " << TexasPodOversize.getTotalMemory() << " MB\n" << endl;
    cout << "~TexasPodNoSize (no size input)~\nExpected size: 512 MB\nActual Size: " << TexasPodNoSize.getTotalMemory() << " MB\n" << endl;

    TexasPod256.clearMemory();
    TexasPodMax.clearMemory();
    TexasPodZero.clearMemory();
    TexasPodNegative.clearMemory();
    TexasPodOversize.clearMemory();
    TexasPodNoSize.clearMemory();

    cout << "-------------Testing UtPod Song Architecture-------------------\n" << endl;

    UtPod t;

    cout << "~~Testing specific songs with bad inputs...\n~~Then correcting them with given set methods...\n" << endl;

    Song empty;
    Song negsize("Negative Size Song", "Artist", -5);
    Song toobig("Too Big Song", "Artist", 513);
    Song notitle("","Artist", 15);
    Song noartist("Title", "", 15);

    int result = t.addSong(empty);
    if (result == 0) {
        cout << "Added Empty Song" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add Empty Song" << endl;
    }
    cout << "Setting instance variables of Empty song to The Ants Go Marching by Ananda Sen (50 MB)" << endl;
    empty.setTitle("The Ants Go Marching");
    empty.setArtist("Ananda Sen");
    empty.setSize(50);
    result = t.addSong(empty);
    if (result == 0) {
        cout << "Added " << empty.getTitle() << " by " << empty.getArtist() << " [" << empty.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add Empty song" << endl;
    }
    cout << endl;
    result = t.addSong(negsize);
    if (result == 0) {
        cout << "Added " << negsize. getTitle() << " by " << negsize.getArtist() << " [" << negsize.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << negsize.getTitle() << endl;
    }
    cout << "Adjusting size of " << negsize.getTitle() << " to 25 MB" << endl;
    negsize.setSize(25);
    result = t.addSong(negsize);
    if (result == 0) {
        cout << "Added " << negsize. getTitle() << " by " << negsize.getArtist() << " [" << negsize.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << negsize.getTitle() << endl;
    }
    cout << endl;
    result = t.addSong(toobig);
    if (result == 0) {
        cout << "Added " << toobig. getTitle() << " by " << toobig.getArtist() << " [" << toobig.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << toobig.getTitle() << " because size is: " << toobig.getSize() << " MB" << endl;
        cout << "Remaining memory is only: " << t.getRemainingMemory() << endl;
    }
    cout << "Adjusting size of " << toobig.getTitle() << " to 15 MB" << endl;
    toobig.setSize(15);
    result = t.addSong(toobig);
    if (result == 0) {
        cout << "Added " << toobig. getTitle() << " by " << toobig.getArtist() << " [" << toobig.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << toobig.getTitle() << endl;
    }
    cout << endl;
    result = t.addSong(notitle);
    if (result == 0) {
        cout << "Added " << notitle. getTitle() << " by " << notitle.getArtist() << " [" << notitle.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add song with no title" << endl;
    }
    cout << "Adjusting title to Default Title" << endl;
    notitle.setTitle("Default Title");
    result = t.addSong(notitle);
    if (result == 0) {
        cout << "Added " << notitle. getTitle() << " by " << notitle.getArtist() << " [" << notitle.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << notitle.getTitle() << endl;
    }
    cout << endl;
    result = t.addSong(noartist);
    if (result == 0) {
        cout << "Added " << noartist. getTitle() << " by " << noartist.getArtist() << " [" << noartist.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add song with no artist" << endl;
    }
    cout << "Adjusting artist to Default Artist" << endl;
    noartist.setArtist("Default Artist");
    result = t.addSong(noartist);
    if (result == 0) {
        cout << "Added " << noartist. getTitle() << " by " << noartist.getArtist() << " [" << noartist.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << noartist.getTitle() << endl;
    }
    cout << endl;

    cout << "***********Clearing UtPod Memory***********\n" << endl;

    t.clearMemory();
    cout << "Current song list:" << endl;
    t.showSongList();
    cout << endl;

    cout << "~~Testing specific songs with correct inputs...\n" << endl;

    Song s1("Bury a Friend", "Billie Eilish", 24);
    Song s2("Baby", "Justin Bieber", 40);
    Song s3("SICKO MODE", "Travis Scott", 35);
    Song s4("sicko mode", "travis scott", 32);
    Song s5("sicko mode", "travis scott", 32);
    result = t.addSong(s1);
    if (result == 0) {
        cout << "Added " << s1. getTitle() << " by " << s1.getArtist() << " [" << s1.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << s1.getTitle() << endl;
    }
    cout << endl;
    result = t.addSong(s2);
    if (result == 0) {
        cout << "Added " << s2. getTitle() << " by " << s2.getArtist() << " [" << s2.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << s2.getTitle() << endl;
    }
    cout << endl;
    result = t.addSong(s3);
    if (result == 0) {
        cout << "Added " << s3. getTitle() << " by " << s3.getArtist() << " [" << s3.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << s3.getTitle() << endl;
    }
    cout << endl;
    result = t.addSong(s4);
    if (result == 0) {
        cout << "Added " << s4. getTitle() << " by " << s4.getArtist() << " [" << s4.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << s4.getTitle() << endl;
    }
    cout << endl;
    result = t.addSong(s5);
    if (result == 0) {
        cout << "Added " << s5. getTitle() << " by " << s5.getArtist() << " [" << s5.getSize() << " MB]" << endl;
        cout << endl;
        t.showSongList();
    } else {
        cout << "Failed to add " << s5.getTitle() << endl;
    }
    cout << endl;
    cout << "Deleting both duplicates of sicko mode by travis scott from UtPod" << endl;
    t.removeSong(s5);
    t.removeSong(s5);
    cout << endl;
    t.showSongList();
    cout << "\n***********Clearing UtPod Memory***********\n" << endl;
    t.clearMemory();
    cout << "Current song list:" << endl;
    t.showSongList();
    cout << endl;
    cout << "--------------Testing UtPod Memory & Song Sorting and Shuffling----------------\n" << endl;

    cout << "Checking remaining memory..." << endl;
    cout << "Expected Memory: 512 MB\n" << "Actual Memory: " << t.getRemainingMemory() << " MB\n" << endl;

    cout << "Adding a bunch of songs to the UtPod...\n" << endl;

    Song song1("Bury a Friend", "Billie Eilish", 24);
    Song song2("Baby", "Justin Bieber", 40);
    Song song3("SICKO MODE", "Travis Scott", 35);
    Song song4("Don't Stop Believing","Journey",65);
    Song song5("Starshopping","Lil Peep",60);
    Song song6("Black & White","JUICEWRLD",76);
    t.addSong(song1);
    t.addSong(song2);
    t.addSong(song3);
    t.addSong(song4);
    t.addSong(song5);
    t.addSong(song6);
    t.showSongList();

    cout << "\nChecking remaining memory..." << endl;
    cout << "Expected Memory: 212 MB\n" << "Actual Memory: " << t.getRemainingMemory() << " MB\n" << endl;

    cout << "Sorting songs in ascending order...\n" << endl;

    t.sortSongList();
    t.showSongList();

    cout << "\nShuffling songs randomly...\n" << endl;

    t.shuffle();
    t.showSongList();

    cout << "\nSorting songs in ascending order...\n" << endl;

    t.sortSongList();
    t.showSongList();

    cout << "\nShuffling songs randomly...\n" << endl;

    t.shuffle();
    t.showSongList();

    cout << "\nSorting songs in ascending order...\n" << endl;

    t.sortSongList();
    t.showSongList();

    cout << "\nShuffling songs randomly...\n" << endl;

    t.shuffle();
    t.showSongList();

    cout << "\n***********Clearing UtPod Memory***********\n" << endl;
    t.clearMemory();
    cout << "Current song list:" << endl;
    t.showSongList();
    cout << endl;

    cout << "-----------Testing Direct Song Comparators-------------\n" << endl;

    cout << "Adding default song to the UtPod..." << endl;
    Song sim1("Title", "Artist", 5);
    t.addSong(sim1);
    t.showSongList();

    cout << "\nTesting equal songs in the UtPod..." << endl;
    Song sim2("Title", "Artist", 5);
    t.addSong(sim2);
    t.showSongList();
    if (sim1 == sim2) {
        cout << "Songs are equal!" << endl;
    } else {
        cout << "Songs are not equal!" << endl;
    }
    t.removeSong(sim2);

    cout << "\nTesting title comparison in the UtPod..." << endl;
    Song sim3("title", "Artist", 5);
    t.addSong(sim3);
    t.showSongList();
    if (sim1 > sim3) {
        cout << sim1.getTitle() << " > " << sim3.getTitle() << endl;
    } else if (sim1 < sim3) {
        cout << sim1.getTitle() << " < " << sim3.getTitle() << endl;
    }
    t.removeSong(sim3);

    cout << "\nTesting artist comparison in the UtPod..." << endl;
    Song sim4("Title", "artist", 5);
    t.addSong(sim4);
    t.showSongList();
    if (sim1 > sim4) {
        cout << sim1.getArtist() << " > " << sim4.getArtist() << endl;
    } else if (sim1 < sim4) {
        cout << sim1.getArtist() << " < " << sim4.getArtist() << endl;
    }
    t.removeSong(sim4);

    cout << "\nTesting size comparison in the UtPod..." << endl;
    Song sim5("Title", "Artist", 6);
    t.addSong(sim5);
    t.showSongList();
    if (sim1 > sim5) {
        cout << sim1.getSize() << " > " << sim5.getSize() << endl;
    } else if (sim1 < sim5) {
        cout << sim1.getSize() << " < " << sim5.getSize() << endl;
    }

    t.addSong(sim2);
    t.addSong(sim3);
    t.addSong(sim4);
    t.sortSongList();

    cout << "\nShowing correct sorting order of all previous songs..." << endl;

    t.showSongList();

    cout << "\n***********Clearing UtPod Memory***********\n" << endl;
    t.clearMemory();
    cout << "Current song list:" << endl;
    t.showSongList();
    cout << endl;

    cout << "*-*-*-*-*-*-*-*-*-*-*-*-End of Testing-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

}

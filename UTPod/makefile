final: UTPodDriver.o UTPod.o Song.o
	g++ -o test UTPodDriver.o UTPod.o Song.o
UTPodDriver.o: UTPodDriver.cpp UTPod.h Song.h
	g++ -c UTPodDriver.cpp
UTPod.o: UTPod.cpp UTPod.h Song.h
	g++ -c UTPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp
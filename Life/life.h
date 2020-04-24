// life.h
// -- EE 312 Project 2

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, Lars Fyhr, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Lars Fyhr
 * email address: fyhr_lars@yahoo.com
 * UTEID: lcf597
 * Section 5 digit ID: 16119
 *
 *///
// Created by priebe on 9/5/2018.
//

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H

#endif //UNTITLED1_LIFE_H

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);    // given .txt file in correct format, generates character array to represent world of cells

void showWorld(char *grid[], int numRows, int numCols);     // displays world of cells that is represented by the character array (* are live cells // . are empty spaces)

void iterateGeneration(char *grid[], int numRows, int numCols);     // iterates the world of cells to next generation given Conway's rules for life

char changeLifeStatus(char oldstatus);      // given a cell's current life status, returns the changed life status)

int checkSurroundingLife(int row, int col, char *grid[], int numRows, int numCols);       // returns the amount of surrounding living cells for a given cell in the world (checks for faults)

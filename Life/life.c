// life.c
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
// Created by Lars Fyhr on 02/04/2020.
//

#include "life.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {
    FILE *fp;
    fp = fopen(fname, "r");                 // open the file as fp if it is there
    if (fp != NULL) {
        char worldline[BUFSIZ];
        *numCols = 0;
        *numRows = 0;
        while (fgets(worldline, sizeof(worldline), fp) != NULL) {
            if (*numRows >= 80) {
                printf("\nMax acceptable row size was passed!\n");          // exit if rows pass the max allowed
                exit(1);
            }
            grid[*numRows] = (char *) malloc(strlen(worldline));        // dynamically allocate a row of chars
            strcpy(grid[*numRows], worldline);          // copy string to grid array (also keep tab of rows/cols)
            *numCols = strlen(worldline) - 1;
            (*numRows)++;
        }
    } else {
        printf("\nCould not open file!\n");               // catch error if file is unable to open
        exit(1);
    }
    fclose(fp);                                         // close file as proper procedure

    //printf("\nRows = %d \n", *numRows);
    //printf("Columns = %d \n", *numCols);                // debug to find if reading right rows and columns
}

void showWorld(char *grid[], int numRows, int numCols) {
    printf("\n");
    for (int i = 0; i < numRows; i++) {
         for (int j = 0; j < numCols; j++) {
             if (grid[i][j] == '0') {
                 printf(".");
             } else if (grid[i][j] == '1') {            // print out the world of characters with the correct format
                 printf("*");
             } else {
                 printf("\n\nProgram stopped because world contained bad inputs!\n"); // exit program if bad inputs
                 exit(1);
             }
         }
         printf("\n");
    }
    printf("\n");
}

void iterateGeneration(char *grid[], int numRows, int numCols) {
    char newgrid[numRows][numCols];
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            if (grid[i][j] == '0') {
                if (checkSurroundingLife(i, j, grid, numRows, numCols) == 3) {
                    newgrid[i][j] = changeLifeStatus('0');    // if empty space surrounded by 3 live cells, create live cell
                } else {                                            // change or keep cell status based on given rules
                    newgrid[i][j] = '0';
                }
            }
            if (grid[i][j] == '1') {
                if (checkSurroundingLife(i, j, grid, numRows, numCols) < 2 || checkSurroundingLife(i, j, grid, numRows, numCols) > 3) {
                    newgrid[i][j] = changeLifeStatus('1');        // if live cell not surrounded be 2 or 3 live cells, kill it
                } else {                                                // change or keep cell status based on given rules
                    newgrid[i][j] = '1';
                }
            }
        }
    }
    for (int i = 0; i < numRows ; i++) {
        for (int j = 0; j < numCols; j++) {
            grid[i][j] = newgrid[i][j];                         // replace old world with newly generated world
        }
    }
}

int checkSurroundingLife(int row, int col, char *grid[], int numRows, int numCols) {
    int surroundingLife = 0;
    if (row > 0) {
        if (col > 0) {
            if (grid[row - 1][col - 1] == '1') {
                surroundingLife++;
            }
        }
        if (grid[row - 1][col] == '1') {                  // diagonal above + left, above, diagonal above + right
            surroundingLife++;
        }
        if (col < numCols - 1) {
            if (grid[row - 1][col + 1] == '1') {
                surroundingLife++;
            }
        }
    }
    if ((grid[row][col - 1] == '1') && (col > 0)) {                 // left and right
        surroundingLife++;
    }                                                               // check the surrounding cells, keeping in mind not
    if ((grid[row][col + 1] == '1') && (col < numCols - 1)) {       // to check left or right if on the edges, as this
        surroundingLife++;                                          // carries it over to the next or previous lines
    }
    if (row < numRows - 1) {
        if (col > 0) {
            if (grid[row + 1][col - 1] == '1') {
                surroundingLife++;
            }
        }
        if (grid[row + 1][col] == '1') {                   // diagonal down + left, down, diagonal down + right
            surroundingLife++;
        }
        if (col < numCols - 1) {
            if (grid[row + 1][col + 1] == '1') {
                surroundingLife++;
            }
        }
    }
    return (surroundingLife);
}

char changeLifeStatus(char oldstatus) {
    if (oldstatus == '1') {
        return('0');
    } else {                                               // change the life status of a cell given its status
        return('1');
    }
}
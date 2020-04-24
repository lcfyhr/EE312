//
// Created by Lars Fyhr on 2/24/20.
// Edited on 03/04/20
//
// Name: Lars Fyhr
// Email: fyhr_lars@yahoo.com
// UTEID: lcf597

#include "stack312_ll.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 25
#define MAX_COLS 27             // makes room for the '\n' and '\0' so that it can still be 25 x 25

void showPictureNoLoops(char pic[MAX_ROWS][MAX_COLS], int rows, int cols, int currentRow, int currentCol);
                                // displays the picture of the entered text file
void checkSurroundings(Stack312 *s, StackEntry focusedPixel, char colorbefore, char pic[MAX_ROWS][MAX_COLS], int rows, int cols);
                                // checks surrounding pixels of a focused pixel to see if they can be flood filled
void PixelPop(Stack312 *s, StackEntry inPixel, char picture[MAX_ROWS][MAX_COLS], int fileRows, int fileCols, char inColor);
                                // recursive stack function that continues the flood fill process based off the surrounding pixels that were
                                // pushed to the stack and needed to be checked again and then changed

int main(int argc, char *argv[]){
    Stack312 s;
    char *fname = argv[1];
    int fileRows = 0;
    int fileCols = 0;
    int inRow = MAX_ROWS;
    int inCol = MAX_COLS;
    char picture[MAX_ROWS][MAX_COLS];
    char inColor = picture[MAX_ROWS][MAX_COLS];
    makeStack(&s);

    FILE *fp;
    fp = fopen(fname, "r");                 // open the file as fp if it is there
    if (fp != NULL) {
        while(fileRows < MAX_ROWS && fgets(picture[fileRows], MAX_COLS, fp) != NULL){
            fileRows++;
        }
        fileCols = strlen(picture[0]) - 1;
        //printf("\nSuccesful!\n");
    } else {
        printf("\nCould not open file!\n");               // catch error if file is unable to open
        exit(1);
    }
    fclose(fp);                                         // close file as proper procedure
    //printf("\n%d rows, %d columns \n", fileRows, fileCols);
    while (true) {
        showPictureNoLoops(picture, fileRows, fileCols, 0, 0);
        while (!(inRow >= -1 && inRow < fileRows)) {
            printf("Enter a row: ");
            scanf("%d", &inRow);
            while (getchar() != '\n') {}
            if (inRow == -1) {                          // prompt user to select a valid row, -1 exits program
                printf("\nExited program...\n");
                exit(1);
            }
        }
        while (!(inCol >= -1 && inCol < fileCols)) {
            printf("Enter a column: ");
            scanf("%d", &inCol);
            while (getchar() != '\n') {}
            if (inCol == -1) {                          // prompt user to select a valid column, -1 exits program
                printf("\nExited program...\n");
                exit(1);
            }
        }
        while (((int)inColor < 33 || (int)inColor > 126) || (inColor == picture[MAX_ROWS][MAX_COLS])) {
            printf("Enter a color: ");
            scanf("%c", &inColor);                      // prompt user to enter a valid color
            while (getchar() != '\n') {}
        }

        StackEntry inPixel;
        inPixel.row = inRow;
        inPixel.col = inCol;                            // create a stackentry of the users selected pixel
        inPixel.color = picture[inRow][inCol];
        push(inPixel, &s);

        if (!isEmpty(s)) {
            PixelPop(&s,inPixel, picture, fileRows, fileCols, inColor);
        }

        inRow = MAX_ROWS;
        inCol = MAX_COLS;
        inColor = picture[MAX_ROWS][MAX_COLS];          // reset selection and free memory
        free(s.top);
    }
}

void PixelPop(Stack312 *s, StackEntry inPixel, char picture[MAX_ROWS][MAX_COLS], int fileRows, int fileCols, char inColor) {
    if (!isEmpty(*s)) {
        StackEntry outPixel = pop(s);
        checkSurroundings(s, outPixel, inPixel.color, picture, fileRows, fileCols);
        picture[outPixel.row][outPixel.col] = inColor;                              // recursive stack function to continue flood filling
        PixelPop(s,inPixel, picture, fileRows, fileCols, inColor);
    }
}

void showPictureNoLoops(char picture[MAX_ROWS][MAX_COLS], int rows, int cols, int currentRow, int currentCol) {
    if (currentRow == 0 && currentCol == 0) {
        printf("\n");
    }
    if (currentRow < rows) {
        if (currentCol < cols) {
            printf("%c", picture[currentRow][currentCol]);
            currentCol++;
        } else {
            currentRow++;                               // display the picture given by the text file
            currentCol = 0;
            printf("\n");
        }
        showPictureNoLoops(picture, rows, cols, currentRow, currentCol);
    } else {
        printf("\n");
    }
}

void checkSurroundings(Stack312 *s, StackEntry focusedPixel, char colorbefore, char pic[MAX_ROWS][MAX_COLS], int rows, int cols) {
    if (focusedPixel.row > 0) {//check above
        if (pic[focusedPixel.row - 1][focusedPixel.col] == colorbefore) {
            StackEntry newfocusedPixel;
            newfocusedPixel.row = focusedPixel.row - 1;
            newfocusedPixel.col = focusedPixel.col;                     // push new stack entry if it should be flood filled
            newfocusedPixel.color = colorbefore;
            push(newfocusedPixel, s);
        }
        if (focusedPixel.col > 0) {//check above and left
            if (pic[focusedPixel.row - 1][focusedPixel.col - 1] == colorbefore) {
                StackEntry newfocusedPixel;
                newfocusedPixel.row = focusedPixel.row - 1;
                newfocusedPixel.col = focusedPixel.col - 1;             // push new stack entry if it should be flood filled
                newfocusedPixel.color = colorbefore;
                push(newfocusedPixel, s);
            }
        }
        if (focusedPixel.col < cols) {//check above and right
            if (pic[focusedPixel.row - 1][focusedPixel.col + 1] == colorbefore) {
                StackEntry newfocusedPixel;
                newfocusedPixel.row = focusedPixel.row - 1;
                newfocusedPixel.col = focusedPixel.col + 1;             // push new stack entry if it should be flood filled
                newfocusedPixel.color = colorbefore;
                push(newfocusedPixel, s);
            }
        }
    }
    if (focusedPixel.col > 0) {//check left
        if (pic[focusedPixel.row][focusedPixel.col - 1] == colorbefore) {
            StackEntry newfocusedPixel;
            newfocusedPixel.row = focusedPixel.row;
            newfocusedPixel.col = focusedPixel.col - 1;                 // push new stack entry if it should be flood filled
            newfocusedPixel.color = colorbefore;
            push(newfocusedPixel, s);
        }
    }
    if (focusedPixel.col < cols) {//check right
        if (pic[focusedPixel.row][focusedPixel.col + 1] == colorbefore) {
            StackEntry newfocusedPixel;
            newfocusedPixel.row = focusedPixel.row;
            newfocusedPixel.col = focusedPixel.col + 1;                 // push new stack entry if it should be flood filled
            newfocusedPixel.color = colorbefore;
            push(newfocusedPixel, s);
        }
    }
    if (focusedPixel.row < rows) {//check below
        if (pic[focusedPixel.row + 1][focusedPixel.col] == colorbefore) {
            StackEntry newfocusedPixel;
            newfocusedPixel.row = focusedPixel.row + 1;
            newfocusedPixel.col = focusedPixel.col;                     // push new stack entry if it should be flood filled
            newfocusedPixel.color = colorbefore;
            push(newfocusedPixel, s);
        }
        if (focusedPixel.col > 0) {//check below and left
            if (pic[focusedPixel.row + 1][focusedPixel.col - 1] == colorbefore) {
                StackEntry newfocusedPixel;
                newfocusedPixel.row = focusedPixel.row + 1;
                newfocusedPixel.col = focusedPixel.col - 1;             // push new stack entry if it should be flood filled
                newfocusedPixel.color = colorbefore;
                push(newfocusedPixel, s);
            }
        }
        if (focusedPixel.col < cols) {//check below and right
            if (pic[focusedPixel.row + 1][focusedPixel.col + 1] == colorbefore) {
                StackEntry newfocusedPixel;
                newfocusedPixel.row = focusedPixel.row + 1;
                newfocusedPixel.col = focusedPixel.col + 1;             // push new stack entry if it should be flood filled
                newfocusedPixel.color = colorbefore;
                push(newfocusedPixel, s);
            }
        }
    }
}

//
// Created by Lars Fyhr on 2/24/20.
//
// Name: Lars Fyhr
// Email: fyhr_lars@yahoo.com
// UTEID: lcf597

#include "stack312_arr.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CHAR 82                                         // makes room for the '\n' & '\0' termination

char checkBrackets(char lastOpening, char lastClosing);

int main (int argc, char *argv[]) {
    Stack312 s1;
    char *fname = argv[1];
    char firsterror = '0';
    char eq[MAX_CHAR];

    makeStack(&s1);

    FILE *fp;
    fp = fopen(fname, "r");                 // open the file as fp if it is there
    if (fp != NULL) {
        while (fgets(eq, sizeof(eq), fp) != NULL) {
            printf("\n");
            if ((strlen(eq) == MAX_CHAR - 1) && (eq[strlen(eq) - 1] != '\n')) {
                printf("Equation length too long!\n\n");  // checks to see if any line does not constrain to 80 chars (other than '\n' and null termination)
                exit(1);
            }
            //if (strlen(eq) <= 1) {
            //    printf("No equations entered!");      // considered checking for blank expressions, but technically valid
            //    exit(1);
            //}
            firsterror = '0';
            for (int c = 0; c < strlen(eq); c++) {
                if (eq[c] != '\n') {
                    printf("%c", eq[c]);          // print out the equation line w/o '\n'
                }
            }
            printf(" === ");
            for (int c = 0; c < strlen(eq); c++) {
                if (firsterror == '0') {                // while no error found, read character of equation
                    if (eq[c] != '\n') {
                        if (eq[c] == '[' || eq[c] == '(' || eq[c] == '<') {
                            push(eq[c], &s1);                   // push any open brackets
                        } else if (eq[c] == ']' || eq[c] == ')' || eq[c] == '>') {
                            char open = 'X';                    // when a closing bracket found
                            if (!isEmpty(s1)) {
                                open = pop(&s1);                // check to see if theres an opening bracket
                            }
                            char close = eq[c];
                            firsterror = checkBrackets(open, close);  // check to see if they're matching braces
                        }
                    }
                }
            }
            if (firsterror == '0') {
                while (!isEmpty(s1)) {
                    char tempchar = pop(&s1);
                    if (tempchar == '(') {              // if unmatched opening brackets, return the first unmatched one
                        firsterror = ')';
                    }
                    if (tempchar == '[') {
                        firsterror = ']';
                    }
                    if (tempchar == '<') {
                        firsterror = '>';
                    }
                }
            }
            if (firsterror == '0') {
                printf("Valid Expression!");
            } else {                                       // if an error was found, print it, if not AKA '0', "Valid Expression!"
                printf("missing: %c ", firsterror);
            }
            printf("\n");
        }
        //printf("\nSuccesful!\n");
    } else {
        printf("\nCould not open file!\n");               // catch error if file is unable to open
        exit(1);
    }
    fclose(fp);                                             // close file as proper procedure
    printf("\n");
}

char checkBrackets(char lastOpening, char lastClosing) {
    if (lastClosing == ')') {
        if (lastOpening == '(') {
            return '0';
        } else {
            return '(';
        }
    } else if (lastClosing == ']') {                       // check two given brackets, to see if they match, if no open bracket
        if (lastOpening == '[') {                          // available to be checked this is also an error, so return a '0'
            return '0';                                    // if all succeed in matching, or the missing bracket if fails
        } else {
            return '[';
        }
    } else if (lastClosing == '>') {
        if (lastOpening == '<') {
            return '0';
        } else {
            return '<';
        }
    } else {
        return 0;
    }
}

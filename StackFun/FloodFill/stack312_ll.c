//
// Created by Lars Fyhr on 2/24/20.
//
// Name: Lars Fyhr
// Email: fyhr_lars@yahoo.com
// UTEID: lcf597

#include "stack312_ll.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void makeStack(Stack312 *s) {
    s -> top = NULL;                    // top of the stack is NULL, empty
}

bool isFull(Stack312 s) {
    return false;                       // stack will never be full (linked list)
}

bool isEmpty(Stack312 s) {
    if (s.top == NULL) {
        return true;
    } else {                            // if top of the stack reaches NULL, empty
        return false;
    }
}

void push(StackEntry e, Stack312 *s) {
    StackNode *temp = (StackNode *) malloc(sizeof(StackNode));
    temp -> pixel = e;                                              // add stack entry as top and link it to next entry
    temp -> next = s -> top;
    s -> top = temp;
}

StackEntry pop(Stack312 *s) {
    StackEntry p = s -> top -> pixel;
    StackNode *ptr = s -> top;                      // remove stack entry and move top down to next entry
    s -> top = s -> top -> next;
    free(ptr);
    return p;
}
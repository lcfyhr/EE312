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

void makeStack(Stack312 *s) {
    s -> top = 0;                           // set the stack starting at 0 (will put first item at 1)
}

bool isFull(Stack312 s) {
    if (s.top == MAX_ELEMENTS) {
        return true;
    } else {                                // if it reaches the max elements, stack is full
        return false;
    }
}

bool isEmpty(Stack312 s) {
    if (s.top == 0) {
        return true;
    } else {                                // if it hits down at 0, stack is empty
        return false;
    }
}

void push(StackEntry e,Stack312 *s) {
    s -> top++;                           // increments the stack's top up and places the new element there
    s -> elements[s -> top] = e;
}

StackEntry pop(Stack312 *s) {
    s -> top--;
    return s -> elements[s -> top+1];       // increments stack's top down but returns the one it moved from
}


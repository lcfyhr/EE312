//stack_arr.h
//Add documentation including Pre and Post conditions for functions

#include <stdio.h>
#include <stdbool.h>

#define MAX_ELEMENTS 100

typedef char StackEntry;

typedef struct Stack312 {
    int top;
    StackEntry elements[MAX_ELEMENTS];
} Stack312;

void makeStack(Stack312 *s);
// creates a new stack of items with structure Stack312
// precondition: given a reference pointer to where to create the stack (*s)
// postcondition: stack is created in memory

bool isFull(Stack312 s);
// returns a boolean depending on whether or not stack is full or not
// precondition: stack is initialized and given a reference to the stack (s)
// postcondition: returns bool of whether or not the stack is full or not

bool isEmpty(Stack312 s);
// returns a boolean depending on whether or not stack is empty or not
// precondition: stack is initialized and given a reference to the stack (s)
// postcondition: returns bool of whether or not the stack is full or not

void push(StackEntry e,Stack312 *s);
// adds a new item to the top of the stack
// precondition: stack is initialized, given a reference to the stack (*s), and not full
// postcondition: entry 'e' is now at the top of the stack

StackEntry pop(Stack312 *s);
// removes top item from the stack and returns it
// precondition: stack is initialized, given a reference to the stack (*s), and not empty
// postcondition: top item removed from stack and returns item which is a copy of the removed stack entry 'e'
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

// CodeCamp.c -- EE 312 Project 1

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
 */

/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
    int hamm = 0;
    for (int ind = 0; ind < len; ind++) {
        if (aList[ind] != bList[ind]) {
            hamm++;
        }
    }
    return hamm;
}

/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2. 
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {
    num1 = abs(num1);
    num2 = abs(num2);
    while (num1 >= 10) {
        num1 = num1%10;
    }
    while (num2 >= 10) {
        num2 = num2%10;
    }
    if (num1 == num2) {
        return true;
    } else {
        return false;
    }
}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {
    int sum = 0;
    for (int i = 0; i < 1000; i++) {
        if (i%3 == 0 || i%5 == 0) {
            sum += i;
        }
    }
    return sum;
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0q otherwise.
*/

int reverseInt(int num) {
    int newnum = 0;
    int sign = 0;
    if (num >= 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    num = abs(num);
    while (num > 0) {
        newnum = newnum*10 + num%10;
        num = num/10;
    }
    return newnum*sign;
}

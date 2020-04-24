#include<stdio.h>
#include<stdbool.h>


// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Lars Fyhr
 * email address: fyhr_lars@yahoo.com
 * UTEID: lcf597
 * Section 5 digit ID: 16119
 *  
 */

//function prototypes. These will be completed in CodeCamp.c
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int num1, int num2);
int reverseInt(int num); 
//****************************

int main() {
  
  // test 1, hammingDistance
  int h1[] = {10, 20, 30, 40, 50, 40, 30, 20, 10};
  int h2[] = {0, 20, 100, 40, 50, 40, 30, -100, 10};
  int expected = 3;
  int actual = hammingDistance(h1, h2, 9);
  printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 1, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 1, hamming distance\n\n");

  // test 2, hamming distance
  int h3[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
  int h4[] = {-60, -60, -60, -60, -60, -60, -60, -60, -60, 100};
  expected = 9;
  actual = hammingDistance(h3, h4, 10);
  printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 2, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 2, hamming distance\n\n");

  // test 3, hamming distance
  int h5[50000] = {69};
  int h6[50000] = {70};
  expected = 1;
  actual = hammingDistance(h5, h6, 50000);
  printf("Test 3 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 3, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 3, hamming distance\n\n");

  // test 4, last digit
  int n1 = 42069;
  int n2 = 6969;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 4, last digit\n\n");
  else 
     printf("**** FAILED **** test 4, last digit\n\n");

  // test 5, last digit
  n1 = -1;
  n2 = 666;
  expected = false;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
    printf("passed test 5, last digit\n\n");
  else 
     printf("**** FAILED **** test 5, last digit\n\n");

  // test 6, last digit
  n1 = 0;
  n2 = 10000;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 6 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)   
    printf("passed test 6, last digit\n\n");
  else 
     printf("**** FAILED **** test 6, last digit\n\n");

  // test 7, sum of multiples of 3 or 5
  expected = 233168;
  actual = sum3or5Multiples();
  printf("Test 7 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 7, sum of multiples of 3 or 5\n\n");
  else 
     printf("**** FAILED **** test 7, sum of multiples of 3 or 5\n\n");

  // test 8, reverse int
  n1 = -500;
  expected = -5;
  actual = reverseInt(n1);
  printf("Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 8, reverse int\n\n");
  else 
     printf("**** FAILED **** test 8, reverse int\n\n");

  // test 9, reverse int
  n1 = 766677;
  expected = 776667;
  actual = reverseInt(n1); 
  printf("Test 9 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 9, reverse int\n\n");
  else 
     printf("**** FAILED **** test 9, reverse int\n\n");

  // test 10, reverse int
  n1 = 1200;
  expected = 21;
  actual = reverseInt(n1); 
  printf("Test 10 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 10, reverse int\n");
  else 
     printf("**** FAILED **** test 10, reverse int\n");

}

/* mathStuff_lcf597.c

Roger Priebe and Lars Fyhr
cs1428 10/15/2007 (updated 3/24/09)
EE312  10/3/2018

Edited by lcf597 on 03/04/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*************************  Function Prototypes  ********************************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false

bool isPrime (int number);
int isDivisible (int number, int divisor);

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n);

//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);

//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);
void primeFactors(int number, int divisor);

//********************************  MAIN  *****************************************

int main () {


    int testNum;

    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);

    if (isPrime(testNum))
        printf("%d is prime\n",testNum);
    else
        printf("%d is not prime.\n", testNum);

    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);

    printPrimes(testNum);

    printf("\n");

    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);

    printf("The %d Fibonacci number is : %d", testNum, findFibo(testNum));

    printf("\n");

    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);

    findFactors(testNum);

    return 0;
}

//********************************  Functions  *****************************************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false

bool isPrime (int number) {
    if (number == 1) {                   // 1 is counted as not prime here
        return false;
    }
    const int START_DIVISOR = 2; //HINT: You may want a helper function
    if (isDivisible(number, START_DIVISOR) == number) {
        return true;                    // check if the number is divisible by anything other than itself and 1
    } else {
        return false;
    }
}

//function isDivisible
//input parameter - two positive integers (one divisor, one divedend)
//returns the first divisor that leaves a remainder of 0 for the divedend

int isDivisible (int number, int divisor) {
    if (number%divisor == 0) {
        return divisor;
    } else {
        return isDivisible(number, divisor + 1);    // if the number is not divisible, try next number;
    }
}

//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n) {
    if (n <= 1) {                           // stops working at 262053
        printf("Not a valid entry!");
        return;
    }
    if (n == 2) {
        printf("%d ", n);                   // 2 is prime, but stops recursive from checking non-valid possibilities
        return;
    }
    printPrimes(n-1);
    if (isPrime(n)){                        // backwards recursive loop so starts at 1 and finishes towards input number
        printf("%d ", n);
    }
}

//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n) {
    if (n == 0 || n == 1) {
        return n;
    }                                      // if n = 1, return first Fibo number, else recursive nth fibonnaci equation
    return findFibo(n-2) + findFibo(n-1);
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number) {
    const int START_DIVISOR = 2; //HINT: You may want a helper function
    if (isPrime(number)) {
        printf("%d=prime", number);                 // if entered number is prime, return number
        return;
    }
    printf("%d=", number);
    primeFactors(number, START_DIVISOR);
}

void primeFactors(int number, int divisor) {
    if (isPrime(number)) {
        printf("%d\n", number);                       // if last quotient is prime, you are done finding factors
        return;
    }
    if (isPrime(divisor)) {
        if (number % divisor == 0) {
            printf("%d*", divisor);
            primeFactors(number/divisor, divisor);        // try dividing number by first prime number, keep incrementing
        } else {                                                  // until you find a prime number to divide by
            primeFactors(number, divisor + 1);
        }
    } else {
        primeFactors(number, divisor + 1);
    }
}
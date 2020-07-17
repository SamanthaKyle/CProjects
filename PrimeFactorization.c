#include <stdio.h>
/* This program will return the prime factors of a given input.

This exercise serves as an introduction to recursion, though it can be done iteratively.

Ex.
75 -> 3 5 5
56 -> 2 2 2 7
*/

void factor(int num){
  int i = 2;
  /* A base case is the case wherein you have no need to recurse anymore. Once your input is 1, it cannot be factored further. */
  if (num == 1) return;

  /* This loop ensures that ONLY prime factors are considered, because all non-primes have smaller prime factors, thus those will be reached before any non-prime factor since the iteration goes in increasing order. */

  while (num%i != 0){
    i++;
  }

  printf("%d ", i);

  /* This recursive call to the factor function allows us to check the other remaining portion of the number's factors. Think of prime factorisation like a tree, and draw out what this would look like. */
  factor(num/i);
}

int main(void) {
  int num;
  printf("This program will return the prime factors of a given number.\n Enter a number here: ");
  scanf("%d", &num); // provide the top portion of the main function to the students so they don't have to worry about
  factor(num);
  return 0;
}
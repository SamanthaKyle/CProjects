#include <stdio.h>
/* This statement imports a library that allows us to use special variable types, macros, and functions. Without this, you could not print anything! */

int main(void) {
  
  int n;

  printf("This program will print the first n prime numbers. \nEnter your desired integer n such that n >= 1: ");
  scanf("%d", &n); //provide this line if students aren't 
  int primes[n];

  /* 2 is a special case, so I have it automatically added to the list. Surely there is a smarter way :).*/

  primes[0] = 2;
  int idx = 1;

  for (int i = 2; idx != n; i++){
    for (int j = 2; j < i; j++){
      if (i%j == 0){
        break;
      }
      if (j == i - 1){
        primes[idx] = i;
        idx++;
      }
    }
  }

  /* The following is purely to print the primes list, the formatting is arbitrary. */

  for (int k = 0; k < n - 1; k++){
    printf("%d, ", primes[k]);
  }
  printf("%d\n", primes[n - 1]);

  return 0;
}
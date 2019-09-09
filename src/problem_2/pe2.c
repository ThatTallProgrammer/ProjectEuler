/*
 * Program: pe2
 * ------------
 * Calculates the sum of all even 
 * Fibonacci numbers up to a limit
 * 
 * Joseph Cauthen
 * August 30th, 2019
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){

  int sum = 0;
  int lim = 4E8;
  int i;

  // create buffer to hold recent
  // Fibonacci calculations
  int *fib = (int *)malloc(3 * sizeof(int));

  // set starting values to 1
  for(i = 0; i < 3; i++) *(fib + i) = 1;

  // caculate Fibonacci numbers until the 
  // limit is reached
  for(i = 2; *(fib + (i - 1) % 3) < lim; i++){

    *(fib + i % 3) = *(fib + (i - 1) % 3) + 
                     *(fib + (i - 2) % 3);

    if(*(fib + i % 3) % 2 == 0) sum = sum + *(fib + i % 3);

    printf("fib %6d: %d\n", i, *(fib + i % 3));

  }

  printf("Answer = %d\n", sum);

  free(fib);

return 0;
}

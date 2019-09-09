/*
 * Program: pe1
 * ------------
 * calculates the sum of the 
 * multiples of 3 or 5 up to 
 * 1000
 * 
 * Joseph Cauthen
 * August 30, 2019
 *
 */ 

#include <stdio.h>

int main(){

  // holds the final sum
  int sum = 0;
  int lim = 1E3;

  // add all multiples of 3 where 
  // 3k < 1000
  int a = 3;
	while(a < lim){

    sum = sum + a;
    a = a + 3;

  }

  // add all multiples of 5 where 
  // 5b < 1000 
  int b = 5;
  while(b < lim){

    sum = sum + b;
    b = b + 5;

  }

  // subtract all multiples of 15
  // where 15c < 1000
  int c = 15;
  while(c < lim){

    sum = sum - c;
    c = c + 15;

  }

  printf("Answer = %d\n", sum);
	
return 0;
}

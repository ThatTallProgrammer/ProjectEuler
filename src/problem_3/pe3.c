/*
 * Program: pe3
 * ------------
 * calculate the largest prime factor
 * of 600851475143 and print the 
 * result to the console
 * 
 * Joseph Cauthen
 * September 2nd, 2019
 * 
 */ 

#include <stdio.h>

/*
 * Function: abs_d
 * ---------------
 * calculate the absolute value
 * of a double precision FP number
 * 
 * x: a real number
 * 
 * return: the absolute value of x
 *
 */ 
double abs_d(double x){
  if(x < 0) return -x;

return x; 
} 


/* 
 * Function: sqrt
 * --------------
 * calculate the square root of 
 * a number
 * 
 * n: a real numer
 * 
 * return: the approximate square root
 *    of n
 *
 */
double sqrt(double n){

  double eps = 0.001;
  double x = 1;

	while(abs_d(n - x * x) > eps){

    x = x - (n - x * x) / (-2 * x);

  } 

return x; 
}

int main(){

  // the long int must hold 7E14
  if(sizeof(long int) < 8) return 1;

	// the number being factorized
  long int n = 600851475143;

	// find factors of n until < the 
  // greatest factor
  // continue dividing n until n 
  // itself is prime
  long int f;
	long int lim = (long int)sqrt(n);
  for(f = 3; f < lim; f++){

    if(n % f == 0){
      n = n / f;
	    f--;
      lim = (long int)sqrt(n);
    }

  }

  // print the result to the console
	printf("Answer = %ld\n", n);

return 0;
}


/* 
 * Program: pe6
 * ------------
 * calculate the difference between 
 * the square of the sum and the sum of 
 * the squares from 1 to 100 inclusive
 * 
 * Joseph Cauthen
 * September 4th, 2019
 */

#include <stdio.h>

/*
 * Function: sum_naturals
 * ----------------------
 * sum all of the numbers from 
 * 1 to n inclusive
 * 
 * n: upper limit of the summation
 * 
 * return: the sum of 1 + 2 .... + n
 * 
 */
int sum_naturals(int n){

  return n * (n + 1) / 2;

}

/*
 * Function: sum_squares
 * ---------------------
 * sum the squares of all numbers 
 * from 1 to n inclusive
 * 
 * n: the upper limit of the summation
 * 
 * return: 1^2 + 2^2 ... + n^2
 * 
 */ 
int sum_squares(int n){

  return n * (n + 1) * (2 * n + 1) / 6;

}

int main(){

  int a = sum_naturals(100);
  int b = sum_squares(100);

  int ans = a * a - b;

  printf("Answer = %d\n", ans);

return 0;
}

/*
 * Program: pe9
 * ------------
 * calculate the Pythagorean triple such that 
 * a + b + c = 1000
 */ 

#include <stdio.h> 
#include <stdlib.h>

#define PYTHAG_SUM 1000 
#define MAX PYTHAG_SUM / 2 + 1

/* 
 * Function: is_pythag
 * -------------------
 * determine if two numbers, a and b, derive
 * a third number, c, which satisfies the two 
 * equations 
 * 
 * a^2 + b^2 = c^2
 * a + b + c = PYTHAG_SUM 
 *
 * a: the smaller integer
 * b: the larger integer
 *
 * return: 1 if such a number c exists and 0 otherwise
 * 
 */
int is_pythag(int a, int b){

  return !( a * (a + 1) + b * (b + 1) + 
		(PYTHAG_SUM - a - b) * (1 - PYTHAG_SUM + a + b) - PYTHAG_SUM);

}

int main(){

  int a;
  int b;
  int c; 
  int found;

  /* 
   * try all combinations of a and b 
   * if a pair (a, b) satisfies the test 
   * specified in is_pythag(a, b) then 
   * break from the loop
   */
  found = 0;
  for(a = 1; a < MAX; ++a){
    
    // b is always greater than a to avoid
    // checking identical pairs 
    for(b = a; b < MAX; ++b){
      
      // if the test is satisfied then the pair 
      // has been found
      if(is_pythag(a, b)) found = 1;

      if(found) break;

    }

    if(found) break;
  }

  // because a + b + c = PYTHAG_SUM
  // c = PYTHAG_SUM - a - b
  c = PYTHAG_SUM - (a + b);
  
  // no pair of (a, b) satisfied the test in is_pythag
  if(!found) {
  
    printf("No Pythagorean triple coulb be found for a + b + c = %d\n", PYTHAG_SUM);
  
  }else{

    // print the answer to the console
    printf("%d^2 + %d^2 = %d^2\n", a, b, c);
    printf("%d + %d + %d = %d\n", a, b, c, PYTHAG_SUM);
    printf("Answer = %d\n", a * b * c);    

  }

return 0;
}

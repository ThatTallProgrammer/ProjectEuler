/* 
 * Program: pe4 
 * ------------
 * calculate the maximum product of
 * two 3 digit integers which is a 
 * palindrome in base 10 and print it 
 * to the console
 * 
 * Joseph Cauthen
 * September 2nd, 2019
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>

/*
 * Function: is_pal 
 * ----------------
 * determine if a number is
 * a palindrome in base 10
 * 
 * n: an integer value
 * 
 * return: 1 if integer is palindrome
 *     and 0 otherwise
 *
 */ 
int is_pal(int n){

	int size = 0;
	int* digits = (int*)malloc(128 * sizeof(int));
  int ispal = 1;

	// load digits of n into array
  while(n != 0){
    *(digits + size) = n % 10;
    n = n / 10;
    size++;
	}

	int i;
	for(i = 0; i < (size - i - 1); i++) {
    if( *(digits + i) != *(digits + size - i - 1) ) {
      ispal = 0;
      break;
    }
  }

  free(digits);
return ispal;
}

int main(){
  
  // loop through all possible 
  // combinations of multipliers
  // saving the maximum product
  int i;
  int j;
  int max = 0;
  for(i = 999; i > 0; i--){
    for(j = 999; j > 0; j--){
      if(is_pal(i * j)) {
        int prod = i * j;
        if(prod > max) max = prod;
      }
    }
  }

// print the maximum product to the 
// console
printf("Answer = %d\n", max);

return 0;
}

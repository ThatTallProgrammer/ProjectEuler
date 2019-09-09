/* 
 * Program: pe5
 * ------------
 * calculate the smallest number divisible by
 * all integers from in [1, 20]
 * 
 */ 

#include <stdio.h>
int main(){

  // list the primes and coprimes found in [1, 20]
  int primes[8] = {2, 3, 5, 7, 11, 13, 17, 19};
	int compos[11] = {4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20};
	
  // divide out the prime numbers from the coprime numbers
  int i;
  int j;
  for(i = 0; i < 8; i++){
    for(j = 0; j < 11; j++){
      if(compos[j] % primes[i] == 0) 
        compos[j] = compos[j] / primes[i];
    }
  }

  // the smallest coprime is now the prime number 2
  // divide out the smallest coprimes from the remaining coprimes 
  for(i = 0; i < 11; i++){

    // if a divisor is 1 it always divides
    if(compos[i] == 1) continue;

    for(j = i + 1; j < 11; j++){

      if(compos[j] % compos[i] == 0) 
        compos[j] = compos[j] / compos[i];

    }

  }

  /* 
   * the concatenation of both sets represents the 
   * prime factorization of the number we are looking for
   * 
   * multiply everything together to get the answer 
   */ 
  int prod = 1;
  for(i = 0; i < 8; i++) prod = prod * primes[i];
  for(i = 0; i < 11; i++) prod = prod * compos[i];
  
  printf("Answer = %d\n", prod);

return 0;
}

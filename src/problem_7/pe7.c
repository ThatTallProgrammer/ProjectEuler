/*
 * Program: pe7
 * ------------
 * calculates the 10001st prime number
 * 
 */ 

#include <stdio.h>
#include <stdlib.h>

float abs_f(float);
int is_prime(int, int*, int);
int sqrt_rounded_up(double);

/*
 * Function: abs_f
 * ---------------
 * calculate the absolute value of a 
 * real value
 * 
 * x: a real valued number
 * 
 * return: the absolute value of x
 * 
 */
float abs_f(float x){

  if(x < 0) return -x;

return x;
}

/*
 * Function: is_prime
 * ------------------
 * determine if a positive integer is prime
 *
 * n: the number undergoing a primality test
 * known_primes: pointer to a list of known primes
 * kp_size: the size of the list of known primes
 * 
 * return: 1 if n is prime and 0 if not
 * 
 */
int is_prime(int n, int* known_primes, int kp_size){

  // numbers less than 2 cannot be prime
	if(n < 2) return 0;

  // stop checking if the current divisor is greater than this
	int lim = sqrt_rounded_up(n);
	
  // search for proper divisors from known prime numbers until
  // the divisors are greater than the square root of n
	int i;
	for(i = 0; i < kp_size && *(known_primes + i) < lim; i++){    
	
    // if any prime number divides n then n is not prime
    if(n % *(known_primes + i) == 0) return 0;

  }

// no prime number divides n
// n must be prime
return 1;
}

/*
 * Function: sqrt_rounded_up
 * -------------------------
 * calculate the square root of a real
 * valued number and return the next integer 
 * that is greater then this square root
 * 
 * n: a positive real number
 *
 * return: the next integer greater than the 
 *    square root of n
 *
 */
int sqrt_rounded_up(double n){

	// pick an arbitrary value for x
  // selecting n ensures x will be 
  //    slightly greater than the actual
  //    square root
  double x = n;

  // let x = sqrt(n)
  // use the Newton Raphson method of 
  // locating function zeroes to solve 
  // n - x * x = 0
  double eps = 1E-2; 
  while(abs_f(n - x * x) > eps) 
    x = x - (n - x * x) / (-2 * x);
 
return (int)x + 1; 
}

int main(){

	// create buffer to hold prime numbers

  int max_prime = 10001;
	int* prime_buf = calloc(max_prime, sizeof(int));

	// set first prime number to 2
  *prime_buf = 2;
  *(prime_buf + 1) = 3;
  int cur_prime = 2;

	// calculate prime numbers until the desired prime is reached
  int i;
  while(cur_prime < max_prime){

    int last_prime = *(prime_buf + cur_prime - 1);
		for(i = 2;; i = i + 2){

      if(is_prime(last_prime + i, prime_buf, cur_prime)){

        *(prime_buf + cur_prime) = last_prime + i;
        break;

      }
    
    }

    cur_prime++;

  }

	printf("Answer = %d\n", *(prime_buf + max_prime - 1));

  // free allocated memory
  free(prime_buf);

return 0;
}

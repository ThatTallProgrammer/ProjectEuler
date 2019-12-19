#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// node for single tailed linked list
struct Node{
  int value;
  struct Node* next;
};

// find the absolute value of a floating point number
double flabs(double x){
  return (x > 0) ? x : -x;
}

// Newton-Raphson implementation for square root
double sroot(double x){
  
  double r = 1.0;
  double eps = 1E-4;

  while (flabs(r * r - x) > eps){
    r = r - (r * r - x) / (2 * r);
  }

return r;
}

// naive implementation for a primality test
bool isprime(int x, struct Node* primes){
  int max = (int)(sroot(x)) + 1;

  struct Node* node = primes;
  while (node != NULL && node->value <= max){
    if(x % node->value == 0) return false;
    node = node->next;
  }

  return true;
}

// sums a singly linked list
long sum(struct Node* list){
  long sum = 0;
  
  for(list; list != NULL; list = list->next) sum = sum + list->value;

  return sum;
}

struct Node* append(struct Node* node, int prime){
  node->next = malloc(sizeof(struct Node));
  node->next->value = prime;
  node->next->next = NULL;
  
  return node->next;
}

int main(){

  int max = 2000000;

  struct Node* primes = malloc(sizeof(struct Node));
  primes->value = 2;
  primes->next = NULL;

  struct Node* tail = append(primes, 3);
  for(int current = 5; current <= max; current = current + 2){
    if( isprime(current, primes) ){
      tail = append(tail, current);
    }
  }

  printf("sum = %ld\n", sum(primes));

return 0;
}

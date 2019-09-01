#include <stdio.h>

int main(){

  // the long int must hold 7E14
  if(sizeof(long int) < 8) return 1;

  long int n = 600851475143;

  long int f = 3;
  int i;
  for(i = 0; f <= n && f + i < 775147; i++){
    if(n % (f + i) == 0){
      n = n / f;
      f = f + i;
      i = 0;
      printf("%ld\n", f);
    }
  }

	printf("Answer = %ld\n", n);

return 0;
}

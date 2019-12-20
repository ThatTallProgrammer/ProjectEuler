#include <stdio.h>
#include <stdlib.h>



int main(){

  int num = 0;
  int i, j = 0;
  int product = 0;
  int max_product = 0;

  int matrix[20 * 20];

  // load the numbers into the matrix
  FILE* file = fopen("files/pe11.txt", "r");
  for(i = 0; i < 20 * 20; i++){
    fscanf(file, "%d", &num);
    matrix[i] = num;
  }
  
  // check the horizontal numbers
  for(i = 0; i < 20; i++){
    for(j = 0; j < 17; j++){
      int row = i * 20;
      product = matrix[row + j] * matrix[row + j + 1] * matrix[row + j + 2] * matrix[row + j + 3];
      if(product > max_product) max_product = product;
    }  
  }

  // check the vertical numbers
  for(i = 0; i < 17; i++){
    for(j = 0; j < 20; j++){
      int row = i * 20;
      product = matrix[row + j] * matrix[row + j + 20] * matrix[row + j + 40] * matrix[row + j + 60];
      if(product > max_product) max_product = product;
    }  
  }

  // check the right diagonal numbers
  for(i = 0; i < 17; i++){
    for(j = 0; j < 17; j++){
      int row = i * 20;
      product = matrix[row + j] * matrix[row + j + 21] * matrix[row + j + 42] * matrix[row + j + 63];
      if(product > max_product) max_product = product;
    }  
  }

  // check the left diagonal numbers
  for(i = 0; i < 17; i++){
    for(j = 3; j < 20; j++){
      int row = i * 20;
      product = matrix[row + j] * matrix[row + j + 19] * matrix[row + j + 38] * matrix[row + j + 57];
      if(product > max_product) max_product = product;
    }  
  }

  printf("Max Product: %d\n", max_product);

return 0;
}

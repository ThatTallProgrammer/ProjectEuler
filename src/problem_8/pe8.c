/*
 * Program: pe8
 * ------------
 * calculate the maximum product of 13 contiguous
 * digits in the 1000 digit number saved in pe8.txt
 * 
 */

#include <stdio.h>
#include <stdlib.h>

#define DATAPATH "../data/pe8.txt"

int main(){

	FILE* fptr; 
	char ch;
	int* digits;
	long int product;
  long int max;
  int i;
 	int j;

  // set the parameters of the problem
  int product_size = 13; 
  int number_size = 1000;
	
	// open file
	fptr = fopen(DATAPATH, "r");
	if(fptr == NULL){
  
    printf("Unable to open %s", DATAPATH);
		exit(1);

  }

	// allocated buffer to hold digits
  digits = malloc(1024 * sizeof(int));

  // read digits into the buffer 
	ch = fgetc(fptr);
  i = 0;
	while(ch != EOF){

    // covert each character into an integer
		*(digits + i) = ch - '0';
    i++;
		ch = fgetc(fptr);

  }
  
  // max holds the answer to the problem
  max = 0;

  // for every combination of 13 contiguous digits
  // calculate the product
  // save the maximum out of this set
  for(i = 0; i < number_size - product_size; i++){
    
		product = *(digits + i);
    for(j = i + 1; j < i + product_size; j++){

      if(product == 0) continue;
      
      product = product * *(digits + j);

    }  
    
    if(product > max) max = product;

  } 
  
  // print the answer to the screen
  printf("Answer = %ld\n", max);

  // deallocate memory
  free(digits);

return 0;
}

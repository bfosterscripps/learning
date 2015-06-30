/*
20150630

> Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop.


I don't understand - but I will assume this means I should replace tabs with spaces.

> Assume a fixed set of tab stops, say every n columns.
> Should n be a variable or a symbolic parameter?
I assume this means a tab is worth a certain number of spaces...


*/

#include <stdio.h>

#define SPACEPERTAB 4

int main() {
  int inputChar;

  inputChar = 0;

  while ((inputChar = getchar()) != EOF ) {
    if(inputChar == '\t'){
      for(int i = 0; i < SPACEPERTAB; ++i){
        //printf("On tab space %d, SPACEPERTAB is %d", i, SPACEPERTAB);
        printf(" ");
      }
    } else {
      printf("%c", inputChar);
    }
  }
}

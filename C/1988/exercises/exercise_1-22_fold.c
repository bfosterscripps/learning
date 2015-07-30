/*

Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the n-th column of input.

Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.

*/

#include <stdio.h>

#define MAXCHAR 80

int main(){
  int currCharCount, currChar;

  currCharCount = currChar = 0;
  while( (currChar = getchar()) != EOF ){
    if(currChar == '\n'){
      //printf("\nnewline!, reset currCharCount ( which = %d )\n", currCharCount);
      currCharCount = 0;
      printf("\n");

    } else if((currChar == ' ' || currChar == '\t') && currCharCount >= MAXCHAR){
        //printf("\n <<over %d chars, reset currCharCount ( which = %d )>>\n", MAXCHAR, currCharCount);
        currCharCount = 0;
        printf("\n");
    } else {
      currCharCount++;
      printf("%c", currChar);
    }
  }

}

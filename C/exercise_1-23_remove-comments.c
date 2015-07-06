/*

Write a program to remove all comments from a C program.

Don't forget to handle quotes strings and character constants properly.

C comments do not nest.

*/

#include <stdio.h>

#define MAXCHAR 80

int main(){
  int isBlockComment, isLineComment, currChar;

  isBlockComment = isLineComment = currChar = 0;
  while( (currChar = getchar()) != EOF ){
    if(isBlockComment == 1){
      if(currChar == '*' && ((currChar = getchar()) != EOF && currChar == '/')){
        isBlockComment = 0;
      }
    } else if(isLineComment == 1){
      if(currChar == '\n'){
        isLineComment = 0;
        printf("\n");
      }
    } else if((isBlockComment == 0 || isLineComment == 0) && currChar == '/'){
      if((currChar = getchar()) != EOF && currChar == '/'){
        isLineComment = 1;
      }else if (currChar == '*'){
        isBlockComment = 1;
      } else {
        printf("/%c",currChar);
      }
    } else {
      printf("%c", currChar);
    }

  } // while loop
// this is just a test...
}

/*
20150701

> Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing.

> Use the same tab stops as for detab.

> When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
If tabs are already being used and a tab or single blank suffices to reach a stop,
  then a tab would be preferred - otherwise, keeping all spaces seems cleaner.


*/

#include <stdio.h>

#define SPACEPERTAB 4

int main() {
  int inputChar, spaceCombo, tabCombo;


  inputChar = spaceCombo = tabCombo = 0;

  while ((inputChar = getchar()) != EOF ) {
    if(inputChar == ' '){
      spaceCombo++;
    }else if (inputChar == '\t'){
      tabCombo++;
    }else{
      if(spaceCombo >= SPACEPERTAB){
        tabCombo += (spaceCombo / SPACEPERTAB);
        spaceCombo = (spaceCombo % SPACEPERTAB);
      }
      if(tabCombo > 0){
        for(int i = 0; i < tabCombo; i++){
          printf("\t");
        }
        tabCombo = 0;
      }
      if(spaceCombo > 0){
        for (int i = 0; i < spaceCombo; i++){
          printf(" ");
        }
        spaceCombo = 0;
      }
      printf("%c", inputChar);
    }
  }
}

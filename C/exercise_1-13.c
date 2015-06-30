/*
20150624

Purpose:
Write a program to print a histogram of the lengths of words in its input.
It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#include <stdio.h>


int main(){
  int inputChar, lengthCount, arrayLength, maxFrequency;
  arrayLength = 45;
  int wordLengths[arrayLength];

  inputChar = lengthCount = maxFrequency = 0;

  for (int i = 0; i < arrayLength; ++i) {
    wordLengths[i] = 0;
  }

  while ((inputChar = getchar()) != EOF ) {
    if (inputChar == ' ' || inputChar == '\n' || inputChar == '\t'){
      printf("New word. Length was: %d. Word lengths before: %d\n", lengthCount, wordLengths[lengthCount]);
      ++wordLengths[lengthCount];
      lengthCount = 0;
      printf("Length is now: %d.\n", lengthCount);
    } else {
      ++lengthCount;
    }
  }

  for (int i = 0; i < arrayLength; ++i) {
    if (wordLengths[i] > 0){
      printf("%d words with %d length\n", wordLengths[i], i);
    }
    if (wordLengths[i] > maxFrequency) { //if new high score!
      maxFrequency++;
    }
  }

  // iterate through frequencies of lengths
  for (int f = 0; f < maxFrequency; f++) {
    //printf("f: %d\n", f);
    // iterate through the lengths themselves
    for (int l = 0; l < arrayLength; ++l) {
      //printf("l: %d\n", l);
      if (wordLengths[l] > 0 && wordLengths[l] >= (maxFrequency - f)){
        if ((l / 10) > 0){
          printf(" _  ");
        } else {
            printf(" _ ");
        }
      } else if(wordLengths[l] > 0) {
        if ((l / 10) > 0){
          printf("    ");
        } else {
            printf("   ");
        }
      }
    }
    printf("\n");
  }

  printf("\n");

  for (int i = 0; i < arrayLength; ++i) {
    if (wordLengths[i] > 0){
      printf(" %d ", i);
    }
  }
  printf("\n");

  return 0;
}

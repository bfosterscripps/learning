/*

Date: 20150715
Author: Brandon Foster
Purpose: Write an alternative version of squeeze(s1, s2) that deletes each char
  in s1 that matches any character in the string s2.

// This is the original squeeze:

void squeeze(char s[], int c){
  int i, j;

  for(i = j = 0; s[i] != '\0'; i++)
    if(s[i] != c)
      s[j++] = s[i];
  s[j] = '\0';
}

*/

#include <stdio.h>

void squeeze(char s1[], char s2[]){
  int i, j, isMatch;

  for(i = j = 0; s1[i] != '\0'; i++){
    isMatch = 0;
    for (int k = 0; s2[k] != '\0'; k++){
      if(s1[i] == s2[k])
        isMatch = 1;
    }
    if(isMatch == 0){
      s1[j++] = s1[i];
    }
  }
  s1[j] = '\0';
}


int main(){
  char first[] = "fishy cakes";
  char verboten[] = "skh";

  squeeze(first, verboten);

  printf("First: %s\n", first);
  return 0;
}

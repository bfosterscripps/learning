/*

Date: 20150720
Author: Brandon Foster

Exercise 3-1.

Our binary search makes two tests inside the loop, when one would suffice
(at the price of more tests outside.)

Write a version with only one test inside the loop and measure the difference in run-time.

The original binary search:
// binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch(int x, int v[], int n) {
   int low, high, mid;
   low = 0;
   high = n - 1;
   while (low <= high) {
     mid = (low+high)/2;

     if (x < v[mid])
      high = mid + 1;
     else if (x  > v[mid])
      low = mid + 1;
     else    //found match
      return mid;
   }
   return -1;   //no match
}

*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1]
// only one test inside the loop
int newBinSearch(int x, int v[], int n) {
   int low, high, mid;
   low = 0;
   high = n - 1;
   mid = (low + high) >> 1;
   while (low <= high) {
     if (x < v[mid]){
      high = mid - 1;
    }else{
      low = mid + 1;
    }
    mid = (low + high) >> 1;
    //printf("Mid: %d, high: %d, low: %d\n", mid, high, low);
   }
   if(v[mid] == x){
     return mid;
   } else {
     return -1;
   }
}


void sort(int numbers[], int count) {
  int j;
  int temp;

  do{
    j = 0;
    for(int i = 0;i < count - 1; i++){
      if (numbers[i] > numbers[i + 1]){
        j = 1;
        temp = numbers[i];
        numbers[i] = numbers[i+1];
        numbers[i + 1] = temp;
      }
    }
  } while (j == 1);
}

// binsearch:  find x in v[0] <= v[1] <= ... <= v[n-1]
int originalBinSearch(int x, int v[], int n) {
   int low, high, mid;
   low = 0;
   high = n - 1;
   while (low <= high) {
     mid = (low + high) / 2;
     //printf("Mid: %d, high: %d, low: %d\n", mid, high, low);
     if (x < v[mid]){
       high = mid - 1;
     } else if (x  > v[mid]){
       low = mid + 1;
     } else    //found match
      return mid;
   }
   return -1;   //no match
}


int main(){
  //looking for "find" in a random set of "values" with "max" number of elements
  int find, max, indexFound;
  max = 1000;
  srand(time(NULL));
  find = rand() % max;
  int values[max];

  printf("Randomly find %d\n", find);

  //srand(time(NULL));
  // initialize the values array with random numbers
  for(int i = 0; i < max; i++){
    values[i] = rand() % (max + 1);
    if( values[i] == find ){
      values[i] += rand() % (max - find);
    }
  }

  // randomly stick the number you need to find in the array
  //srand(time(NULL));
  int randIndex = rand() % (max + 1);
  values[randIndex] = find;

  sort(values, max);

  for(int i = 0; i < max; i++){
    printf("i: %d, v[i]: %d\n", i, values[i]);
  }

  clock_t start, stop;

  // Time the old function

  start = clock();

  indexFound = originalBinSearch(find, values, max);

  stop = clock();

  printf("Original took %Lf cycles with %d cycles per second.\n", (long double)(stop - start), CLOCKS_PER_SEC);

  printf("Found %d at %d.\n", values[indexFound], indexFound);

  // Time the New function

  start = clock();

  indexFound = newBinSearch(find, values, max);

  stop = clock();

  printf("New took %Lf cycles with %d cycles per second.\n", (long double)(stop - start), CLOCKS_PER_SEC);

  printf("Found %d at %d.\n", values[indexFound], indexFound);

  return 0;
}

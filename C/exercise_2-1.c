/*

  20150707
  Exercise 2-1 from The C Programming Language (2nd edition)

  Write a program to determine the ranges of char, short, int,
    and long variables, both signed and unsigned, by printing appropriate values
   from standard headers and by direct computation.

Harder if you compute them:
  determine the ranges of the various floating-point types.

*/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
  char baseChar;
  unsigned char uCharPrev, uCharNext;

  baseChar = 0;

  // by printing values from standard headers:


  printf("Maxes and Mins from standard headers:\n");


  // ranges of char
  printf("\nchar\n");

  printf("Max of char: %d\n", CHAR_MAX);
  // notice whether this is 0 or the same as SCHAR_MIN
  printf("Min of char: %d\n", CHAR_MIN);

  // specficially signed
  printf("Max of signed char: %d\n", SCHAR_MAX);
  printf("Min of signed char: %d\n", SCHAR_MIN);
  //unsigned
  printf("Max of unsigned char: %u\n", UCHAR_MAX);
  // min would be 0

  // ranges of short
  printf("\nshort\n");

  printf("Max of short: %d\n", SHRT_MAX);
  printf("Min of short: %d\n", SHRT_MIN);
  printf("Max of unsigned short: %u\n", USHRT_MAX);
  // unsigned min would be 0

  // ranges of int
  printf("\nint\n");

  printf("Max of int: %d\n", INT_MAX);
  printf("Min of int: %d\n", INT_MIN);
  // at this point %d returned -1, %u has to be used to represent unsigned int
  printf("Max of unsigned int: %u\n", UINT_MAX);
  // unsigned min would be 0

  // ranges of long
  printf("\nlong\n");

  // %d craps out, need to use long d, %ld
  printf("Max of long: %ld\n", LONG_MAX);
  printf("Min of long: %ld\n", LONG_MIN);
  // %u can't be used here, need to use long u, %lu
  printf("Max of unsigned long: %lu\n", ULONG_MAX);
  // unsigned min would be 0

  // now... how to go about computing them...

  //computer ranges of char

  printf("\ncomputed char\n");

  // compute min by ... adding!
  while((baseChar + 1) >= 0){
    ++baseChar;
  }

  printf("Computed min char value: %d\n", baseChar);

  // reset the char
  baseChar = 0;

  // compute max by ... subtracting!
  while((baseChar - 1) < 0){
    --baseChar;
  }

  printf("Computed max char value: %d\n", baseChar);


  //compute unsigned char max...
  uCharNext = 1;
  while(uCharNext != 0){
    uCharPrev = uCharNext;
    ++uCharNext;
    //printf(" %d", uCharNext);
  }

  printf("Computed max unsigned char: %u\n", uCharPrev);


  printf("\ncomputed short\n");

  short baseShort;

  baseShort = 0;

  // computed short ranges

  //compute max
  while((baseShort - 1) < 0){
    baseShort--;
    //printf(" %d", baseShort);
  }

  printf("Computed max of signed short: %d\n", baseShort);

  //compute min
  baseShort = 0;
  while((baseShort + 1) > 0){
    baseShort++;
    //printf(" %d", baseShort);
  }

  printf("Computed min of signed short: %d\n", baseShort);


  unsigned short uShortNext, uShortPrev;
  uShortNext = uShortPrev = 1;

  while(uShortNext != 0){
    uShortPrev = uShortNext;
    uShortNext++;
    //printf(" %d", uShortNext);
  }

  printf("Computed max of unsigned short: %u\n", uShortPrev);


/*

  printf("\ncomputed int\n");

  int baseInt;

  baseInt = -1;

  // computed short ranges

  //compute max
  while(baseInt < 0){
    baseInt--;
    //printf(" %d", baseInt);
  }

  printf("Computed max of signed int: %d\n", baseInt);

  //compute min
  baseInt = 1;

  while(baseInt > 0){
    baseInt++;
    //printf(" %d", baseInt);
  }

  printf("Computed min of signed int: %d\n", baseInt);


  unsigned int uIntNext, uIntPrev;
  uIntNext = uIntPrev = 1;

  while(uIntNext != 0){
    uIntPrev = uIntNext;
    uIntNext++;
    //printf(" %d", uIntNext);
  }

  printf("Computed max of unsigned int: %u\n", uIntPrev);

***/



  printf("\ncomputed long\n");

  long baseLongPrev, baseLongNext, addition;

  baseLongPrev = baseLongNext = -1;

  // computed short ranges

  //compute max
  addition = 100000000000000000;


  while(baseLongNext < 0){
    baseLongNext = baseLongNext - addition;
    //printf("Iterate: %ld\n", baseLongNext);
    if(baseLongNext > 0){
      if(addition != 1){
        baseLongNext = baseLongPrev;
        if(addition >= 10){
          addition = addition / 10;
          //printf("Addition: %ld\n", addition);
        }
      }
    }else{
      baseLongPrev = baseLongNext;
    }
  }

  printf("Computed max of signed long: %ld\n", baseLongNext);
  printf("Computed min of signed long: %ld\n", baseLongPrev);

  unsigned long uLongPrev, uLongNext;

  uLongPrev = uLongNext = 1;

  // computed short ranges

  //compute max
  addition = 100000000000000000;


  while(uLongNext != 0){
    uLongNext = uLongNext + addition;
    //printf("Iterate: %lu\n", uLongNext);
    if(uLongNext == 0 || uLongNext < uLongPrev){
      if(addition != 1){
        uLongNext = uLongPrev;
        if(addition >= 10){
          addition = addition / 10;
          //printf("Addition: %ld\n", addition);
        }
      }
    }else{
      uLongPrev = uLongNext;
    }
  }

  printf("Computed max of unsigned long: %lu\n", uLongPrev);
  //printf("Computed max of unsigned long: %lu\n", uLongNext);


}

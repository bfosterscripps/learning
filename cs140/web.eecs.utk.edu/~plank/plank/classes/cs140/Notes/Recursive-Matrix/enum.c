#include <stdio.h>
#include <stdlib.h>

void recursive_enumerate(int zeros, int ones, int twos, char *string, int loc)
{
  if (zeros > 0) {
    string[loc] = '0';
    recursive_enumerate(zeros - 1, ones, twos, string, loc+1);
  }
  if (ones > 0) {
    string[loc] = '1';
    recursive_enumerate(zeros, ones - 1, twos, string, loc+1);
  }
  if (twos > 0) {
    string[loc] = '2';
    recursive_enumerate(zeros, ones, twos - 1, string, loc+1);
  }
  if (zeros + ones + twos == 0) {
    string[loc] = '\0';
    printf("%s\n", string);
  }
}

main(int argc, char **argv)
{
  int ones;
  int twos;
  int zeros;
  char *s;

  if (argc != 4) {
    fprintf(stderr, "usage: enum zeros ones two\n");
    exit(1);
  }
  zeros = atoi(argv[1]);
  ones = atoi(argv[2]);
  twos = atoi(argv[3]);

  s = (char *) malloc(sizeof(char)*(zeros+ones+twos+1));
  recursive_enumerate(zeros, ones, twos, s, 0);
}

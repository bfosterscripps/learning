#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

main(int argc, char **argv)
{
  int n;
  double f;
  double count;
  int i, j;
  long t0;

  if (argc != 2) { 
    fprintf(stderr, "Usage: linear2 n\n");
    exit(1);
  }

  n = atoi(argv[1]);

  t0 = time(0);
  count = 0;
  f = 23.4;
  for (i = 0; i < n; i++) {
    count++;
    f = f * f + 1;
    j = (int) f / 1000;
    f = f - j*1000;
  }
  for (i = 0; i < n; i++) {
    count++;
    f = f * f + 1;
    j = (int) f / 1000;
    f = f - j*1000;
  }
  printf("N: %d   Count: %.0lf   Time: %ld\n", n, count, time(0)-t0);
}

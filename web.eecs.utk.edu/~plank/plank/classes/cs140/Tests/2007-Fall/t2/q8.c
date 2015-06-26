#include <stdio.h>
#include <stdlib.h>

void enum_strings(char *s, int a, int b, int start)
{
  if (a == 0 && b == 0) {
    s[start] == '\0';
    printf("%s\n", s);
    return;
  }
  if (a > 0) {
    s[start] = 'A';
    enum_strings(s, a-1, b, start+1);
  }
  if (b > 0) {
    s[start] = 'B';
    enum_strings(s, a, b-1, start+1);
  }
}

main(int argc, char **argv)
{
  char *s;
  int a, b;

  if (argc != 3 || sscanf(argv[1], "%d", &a) == 0 || 
                   sscanf(argv[1], "%d", &b) == 0 || 
                   a < 0 || b < 0) {
    fprintf(stderr, "usage: q8 a b\n");
    exit(1);
  }

  s = (char *) malloc(sizeof(char) * (a + b + 1));
  enum_strings(s, a, b, 0);
}

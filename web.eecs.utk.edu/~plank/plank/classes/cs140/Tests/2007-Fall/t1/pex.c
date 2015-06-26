#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(int argc, char **argv)
{
  char *s, *u, *v;

  s = argv[1];
  v = strchr(s, 'G');
  u = strdup(s);
  
  if (v == NULL) exit(0);

  *v = 'g';
  v += 5;
  *v = 'i';

  printf("0x%x 0x%x\n", s, u);

  printf("argc: %d\n", argc);
  printf("argv[1]: 0x%x %s\n", argv[1], argv[1]);
  printf("s: 0x%x %s\n", s, s);
  printf("u: 0x%x %s\n", u, u);
  printf("v: 0x%x %s\n", v, v);
  printf("strstr: 0x%x %s\n", strstr(u, "ge"), strstr(u, "ge"));
}

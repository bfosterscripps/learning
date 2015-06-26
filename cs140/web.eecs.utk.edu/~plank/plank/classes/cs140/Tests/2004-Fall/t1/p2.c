#include <stdio.h>
#include "fields.h"

main()
{
  IS is;
  int i, j, k;
  char *s;

  is = new_inputstruct(NULL);

  i = 0;
  j = 0;
  while (get_line(is) >= 0) {
    s = is->fields[i%is->NF];
    k = j%strlen(s);
    printf("%c\n", s[k]);
    i++;
    j++;
  }
}

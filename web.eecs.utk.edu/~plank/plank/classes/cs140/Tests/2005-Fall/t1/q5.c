#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "dllist.h"



main()
{
  int i;
  IS is;
  char *x, *y;

  i = 0;
  is = new_inputstruct(NULL);

  while (get_line(is) >= 0) {
    x = strchr(is->text1, 'o');
    if (x == NULL) x = is->text1;
    y = strchr(is->text1, 's');
    if (y == NULL) y = is->text1;
    printf("%d\n", y - x);
  }
}

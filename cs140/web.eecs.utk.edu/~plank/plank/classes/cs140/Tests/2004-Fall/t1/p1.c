#include <stdio.h>
#include "fields.h"

main()
{
  IS is;
  int i;

  is = new_inputstruct(NULL);

  while (get_line(is) >= 0) {
    if (is->NF >= 3) {
      if (sscanf(is->fields[2], "%d", &i) == 1) {
        printf("%d\n", i);
      }
    }
  }
}

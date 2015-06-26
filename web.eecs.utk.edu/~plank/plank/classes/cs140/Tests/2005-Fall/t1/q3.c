#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "dllist.h"

main()
{
  IS is;
  Dllist d, tmp;
  int i;

  d = new_dllist();
  i = 0;
  is = new_inputstruct(NULL);

  while (get_line(is) >= 0) {
    if (i % 2 == 0) {
      dll_append(d, new_jval_s(strdup(is->fields[0])));
    } else {
      dll_prepend(d, new_jval_s(strdup(is->fields[is->NF-1])));
    }
    i++;
  }
  dll_traverse(tmp, d) {
    printf("%s\n", tmp->val.s);
  }
}

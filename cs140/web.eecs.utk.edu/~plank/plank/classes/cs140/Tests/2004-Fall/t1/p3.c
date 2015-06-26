#include <string.h>
#include <stdio.h>
#include "fields.h"
#include "dllist.h"

main()
{
  IS is;
  int i;
  Dllist d, tmp;
   
  d = new_dllist();

  is = new_inputstruct(NULL);

  while (get_line(is) >= 1) {
    if (is->line % 2 == 0) {
      dll_append(d, new_jval_s(strdup(is->fields[0])));
    } else {
      dll_prepend(d, new_jval_s(strdup(is->fields[0])));
    }
  }
  dll_traverse(tmp, d) {
    printf("%s\n", tmp->val.s);
  }
}

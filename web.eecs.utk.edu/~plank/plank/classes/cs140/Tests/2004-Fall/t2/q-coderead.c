#include "fields.h"
#include "jrb.h"

main()
{
  IS is;
  JRB t, tmp;
  int i;
  int j;
  int x;

  j = 0;
  t = make_jrb();
  is = new_inputstruct(NULL);

  while (get_line(is) >= 0) {
    for (i = 0; i < is->NF; i++) {
      jrb_insert_str(t, strdup(is->fields[i]), new_jval_i(j));
      j++;
    }
  }

  jrb_traverse(tmp, t) {
    x = strlen(tmp->key.s);
    printf("%c", tmp->key.s[tmp->val.i%x]);
  }
  printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"
#include "stack.h"
#include "queue.h"
#include "dllist.h"

main()
{
  IS is;
  Queue q;
  Stack s;
  Dllist l;
  int i;
  Jval j;

  is = new_inputstruct(NULL);

  while (get_line(is) > 0) {
    q = new_queue();
    s = new_stack();
    l = new_dllist();
    for (i = 0; i < strlen(is->fields[0]); i++) {
      queue_enqueue(q, new_jval_c(is->fields[0][i]));
      stack_push(s, new_jval_c(is->fields[0][i]));
      dll_append(l, new_jval_c(is->fields[0][i]));
      dll_prepend(l, new_jval_c(is->fields[0][i]));
    }
    while (!queue_empty(q)) {
      j = queue_dequeue(q); printf("%c", j.c);
      j = stack_pop(s); printf("%c", j.c);
      printf("%c", l->flink->val.c); dll_delete_node(l->flink);
      printf("%c", l->flink->val.c); dll_delete_node(l->flink);
      printf(" ");
    }
    printf("\n");
    free_queue(q);
    free_stack(s);
    free_dllist(l);
  }
}

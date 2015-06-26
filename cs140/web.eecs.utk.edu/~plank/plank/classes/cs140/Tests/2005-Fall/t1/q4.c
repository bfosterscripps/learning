#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "stack.h"

main()
{
  Queue q;
  Stack s;
  Jval v;
  IS is;
  int i;

  q = new_queue();
  s = new_stack();
  i = 0;
  is = new_inputstruct(NULL);

  while (get_line(is) >= 0) {
    if (i % 2 == 0) {
      queue_enqueue(q, new_jval_s(strdup(is->fields[0])));
    } else {
      stack_push(s, new_jval_s(strdup(is->fields[0])));
    }
    i++;
  }
  while (!queue_empty(q)) { 
    v = queue_dequeue(q);
    printf("%s\n", v.s);
  }
  while (!stack_empty(s)) { 
    v = stack_pop(s);
    printf("%s\n", v.s);
  }
}



#include <stdio.h>
#include "fields.h"

main()
{
  IS is;
  double n, x;
  double total;
  int nfield, i;

  is = new_inputstruct(NULL);

  while (get_line(is) >= 0) {
    if (is->text1[0] != '#') {
      for (nfield = 0; sscanf(is->fields[nfield], "%lf", &n) == 0; nfield++) ;
      total = 0;
      for (i = nfield+1; i < is->NF; i++) {
        sscanf(is->fields[i], "%lf", &x);
        total += x;
      }
      printf("%10.4lf", total/n);
      for (i = 0; i < nfield; i++) printf(" %s", is->fields[i]);
      printf("\n");
    }
  }
}

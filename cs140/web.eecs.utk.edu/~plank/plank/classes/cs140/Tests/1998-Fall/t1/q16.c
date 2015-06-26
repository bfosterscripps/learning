#include <stdio.h>
#include <string.h>
#include "fields.h"

main(int argc, char **argv)
{
    /* Make variable declarations */

    FILE *f;       /* For reading in the file */
    int n;         /* Number of lines */
    char **array;  /* Array for holding n lines */
    IS is;         /* Inputstruct for reading input */
    int i;         /* Induction variable for the for loops */

    /* Make sure you have the right number of command line arguments */

    if (argc != 3) {
      fprintf(stderr, "usage: revn n filename\n");
      exit(1);
    }

    /* Make sure n is a legal value */

    n = atoi(argv[1]);  /* You could also do a sscanf here */
    if (n <= 0) {
      fprintf(stderr, "Bad value of n\n");
      exit(1);
    }

   /* Open the file, allocate your array to hold the lines */

    f = fopen(argv[2], "w");
    if (f == NULL) { perror(argv[2]); exit(1); }
    array = (char **) malloc(sizeof(char *) * n);
   
   /* Read in the first n lines (or the entire file if it has < n lines */
   /* There are other ways to do this, but this is pretty clean */

    is = new_inputstruct(NULL);
    for (i = 0; i < n; i++) {
      if (get_line(is) < 0) {
        n = i;
      } else {
        array[i] = strdup(is->text1);
      }
    }

   /* Print out the first n lines to the file in reverse order */

   for (i = n-1; i >= 0; i--) {
     fprintf(f, "%s", array[i]);
   }

}

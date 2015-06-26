#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fields.h"

fill_matrix(int **matrix, int rows, int *elements,
             int srow, int scol)
{
  if (rows == 1) {
    matrix[srow][scol] = *elements;
  } else {
    fill_matrix(matrix, rows/2, elements, srow, scol);
    fill_matrix(matrix, rows/2, elements, srow+rows/2, scol+rows/2);
    fill_matrix(matrix, rows/2, elements+(rows/2), srow, scol+rows/2);
    fill_matrix(matrix, rows/2, elements+(rows/2), srow+rows/2, scol);
  }
}

main()
{
  IS is;
  int *elements;
  int n, i, j, **matrix;

  is = new_inputstruct(NULL);
  get_line(is);
  n = is->NF;
  elements = (int *) malloc(sizeof(int)* n);
  for (i = 0; i < n; i++) {
    elements[i] = atoi(is->fields[i]);
  }
  matrix = (int **) malloc(sizeof(int *)* n);
  for (i = 0; i < n; i++) {
    matrix[i] = (int *) malloc(sizeof(int)* n);
  }
  fill_matrix(matrix, n, elements, 0, 0);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}


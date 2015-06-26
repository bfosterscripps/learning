#include "q8.h"

int PackingParts::pack(vector <int> partSizes, vector <int> boxSizes)
{
  int p, b, max;

  max = 0;
  b = 0;
  for (p = 0; p < partSizes.size(); p++) {
    while (b < boxSizes.size() && boxSizes[b] < partSizes[p]) b++;
    if (b == boxSizes.size()) return max;
    b++;
    max++;
  }
  return max;
}

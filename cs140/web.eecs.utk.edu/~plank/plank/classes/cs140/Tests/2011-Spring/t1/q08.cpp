#include <iostream>
#include <vector>
using namespace std;

main()
{
  vector <int> v;
  int i;

  v.resize(5, 5);
  v.push_back(1);
  v.resize(10, 10);
  v.resize(8);
  v.resize(10, 11);
  for (i = 0; i < v.size(); i++) printf("%d ", v[i]); printf("\n");
}

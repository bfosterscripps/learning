#include <iostream>
using namespace std;

main()
{
  string i, j, k;

  i = "Fred";  j = "Luther"; 

  cin >> i;
  cin >> j;
  k = j;
  k[0]++;
  printf("%s %s %s\n", i.c_str(), 
       j.c_str(), k.c_str());
} 

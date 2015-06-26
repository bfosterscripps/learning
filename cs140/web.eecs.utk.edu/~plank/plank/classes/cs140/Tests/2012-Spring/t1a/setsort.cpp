#include <set>
#include <iostream>
using namespace std;

main()
{
  multiset <string> l;
  multiset <string>::iterator lit;
  string s;

  while (getline(cin, s)) l.insert(s);
  
  for (lit = l.begin(); lit != l.end(); lit++) cout << *lit << endl;
}

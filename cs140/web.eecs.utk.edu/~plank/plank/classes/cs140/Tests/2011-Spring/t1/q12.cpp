#include <vector>
#include <iostream>
using namespace std;

string a(string &s)
{
  s[0] += 2;
  s.push_back(s[0]);
  return s;
}

main(int argc, char **argv)
{
  vector <string> v;
  int i;

  v.push_back("A");
  for (i = 0; i < 4; i++) v.push_back(a(v[i]));
  for (i = 0; i < v.size(); i++) cout << v[i] << endl;
}

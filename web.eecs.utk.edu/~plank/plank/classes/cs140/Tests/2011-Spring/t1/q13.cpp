#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

vector <int> i_like_tea(string &s)
{
  istringstream ss;
  vector <int> rv;
  int i;
  string str;

  ss.str(s);
  i = 0;
  while (ss >> str) {
    if (str.find('t') != string::npos || str.find('T') != string::npos) rv.push_back(i);
    i++;
  }
  return rv;
}

main()
{
  string s;
  vector <int> rv;
  int i;

  while (getline(cin, s)) {
    rv = i_like_tea(s);
    for (i = 0; i < rv.size(); i++) printf("%d ", rv[i]);
    printf("\n");
  }
}

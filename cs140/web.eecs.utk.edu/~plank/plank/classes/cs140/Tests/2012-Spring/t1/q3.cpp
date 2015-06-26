#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector <int> stoivec(string &s)
{
  vector <int> v;
  istringstream ss;
  int i;
  string dummy;

  ss.clear();
  ss.str(s);
  while (1) {
    if (ss >> i) {
      v.push_back(i);
    } else {
      ss.clear();
      if (!(ss >> dummy)) return v;
    }
  }
}

main()
{
  string s;
  vector <int> rv;
  int i;

  while (getline(cin, s)) {
    rv = stoivec(s);
    if (rv.size() > 0) {
      cout << rv[i];
      for (i = 1; i < rv.size(); i++) cout << " " << rv[i];
    }
    cout << endl;
  }
}

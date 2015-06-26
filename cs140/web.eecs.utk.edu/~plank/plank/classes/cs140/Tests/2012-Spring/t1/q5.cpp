#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector <int> IVec;

void avg(vector <IVec> &v)
{
  double n;
  double t;
  int i, j;

  for (i = 0; i < v.size(); i++) {
    if (v[i].size() == 0) {
      printf("Bad\n");
    } else {
      t = 0;
      n = v[i].size();
      for (j = 0; j < v[i].size(); j++) t += v[i][j];
      printf("%.3lf\n", t/n);
    }
  }
}


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
  vector <IVec> v;
  int i;

  while (getline(cin, s)) {
    v.push_back(stoivec(s));
  }
  avg(v);
}

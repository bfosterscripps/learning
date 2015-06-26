#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string svectos(vector <string> &v)
{
  string s;
  int i;

  for (i = 0; i < v.size(); i++) {
    if (i != 0) s += " ";
    s += v[i];
  }

  for (i = 0; i < s.size(); i++) {
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] += ('a' - 'A');
  }
  return s;
}

main()
{
  string s, word;
  istringstream ss;
  vector <string> line;
  int i;

  while (getline(cin, s)) {
    ss.clear();
    ss.str(s);
    line.clear();
    while (ss >> word) line.push_back(word);
    cout << svectos(line) << endl;
  }
}

#include <iostream>
using namespace std;

string s_to_p(string s)
{
  int i, j;

  i = 0;
  j = s.size()-1;
  while (i < j) {
    if (s[i] < s[j]) {
      s[j] = s[i];
    } else {
      s[i] = s[j];
    }
    i++;
    j--;
  }
  return s;
}

main()
{
  string s;

  while (cin >> s) cout << s_to_p(s) << endl;
}

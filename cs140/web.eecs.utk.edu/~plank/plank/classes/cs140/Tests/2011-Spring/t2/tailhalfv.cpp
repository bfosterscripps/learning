#include <vector>
#include <iostream>
using namespace std;

main()
{
  vector <string> lh;
  string s;
  int i;

  i = 0;
  while (getline(cin, s)) {
    lh.push_back(s);
    i++;
    if (i%2 == 0) lh.erase(lh.begin());
  }

  for (i = 0; i < lh.size(); i++) {
    cout << lh[i] << endl;
  }
}

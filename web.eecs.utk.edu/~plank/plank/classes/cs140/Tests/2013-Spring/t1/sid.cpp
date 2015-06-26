#include <iostream>
#include <sstream>
#include <string>
using namespace std;

main()
{
  string s;
  istringstream ss;
  int i;
  double d;

  while (cin >> s) {
    ss.clear();
    ss.str(s);
    if (ss >> d) {
      if (s.find('.') != string::npos) {
        printf("%-10s %7.3lf\n", s.c_str(), d);
      } else {
        i = d;
        printf("%-10s %7d\n", s.c_str(), i);
      }
    } else cout << s << endl;
  }
}

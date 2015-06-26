#include <iostream>
using namespace std;

int main()
{
  int i, n1;
  string s;

  for (i = 0; i < 10; i++) {
    if (!(cin >> n1)) {
      cin.clear();
      if (!(cin >> s)) return 0;
      cout << "Number " << i << " entered incorrectly\n";
    } else {
      cout << "Number " << i << " equals " << n1 << endl;
    }
  }

  return 0;
}

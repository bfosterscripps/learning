#include <iostream>
#include <string>
using namespace std;

int main()
{
  int i, j;
  string s;

  if (cin >> i) {
    cout << "I is " << i << endl;
  } else {
    cout << "Bad cin call reading i -- calling cin.clear()\n";
    cin.clear();
    cin >> s;
  }

  if (cin >> j) {
    cout << "J is " << j << endl;
  } else {
    cout << "Bad cin call reading j -- calling cin.clear()\n";
    cin.clear();
    cin >> s;
  }

  return 0;
}

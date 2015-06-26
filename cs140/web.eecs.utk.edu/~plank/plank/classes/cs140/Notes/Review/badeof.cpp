#include <iostream>
using namespace std;

int main()
{
  string s;
  int i;

  i = 0;
  while (!cin.eof()) {
    i++;
    cin >> s;
    cout << "String " << i << " is " << s << endl;
  }
  return 0;
}

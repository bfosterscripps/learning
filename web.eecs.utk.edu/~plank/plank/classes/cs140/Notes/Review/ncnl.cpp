#include <iostream>
using namespace std;

int main()
{
  int nc, nl;
  char c;

  nc = 0;
  nl = 0;

  while (cin >> c) {
    nc++;
    if (c == 'L') nl++;
  }

  cout << "# of characters: " << nc << endl;
  cout << "# of L's: " << nl << endl;
  return 0;
}

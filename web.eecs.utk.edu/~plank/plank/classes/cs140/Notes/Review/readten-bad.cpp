#include <iostream>
using namespace std;

int main()
{
  int i, n1;

  for (i = 0; i < 10; i++) {
    if (!cin >> n1) {
      cout << "Done\n";
      return 0;
    }
    cout << "Number " << i << " equals " << n1 << endl;
  }

  return 0;
}

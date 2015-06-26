#include <iostream>
using namespace std;

main(int argc, char **argv)
{
  char *cs;
  string s1, s2;

  cs = argv[1];
  s1 = argv[1];
  s2 = s1;

  cs[0] = 'X';
  s1[1] = 'Y';
  s2.push_back('Z');

  cout << argv[1] << endl;
  cout << cs << endl;
  cout << s1 << endl;
  cout << s2 << endl;

}

#include <iostream>
#include <vector>
using namespace std;

class RoomNumber {
  public: 
    int numberOfSets(int n);
};

int RoomNumber::numberOfSets(int n)
{
  vector <int> count;
  int i;
  int digit;
  int max;

  count.resize(9, 0);

  while (n > 0) {
    digit = n % 10;
    n /= 10;
    if (digit == 9) digit = 6;
    count[digit]++;
  }

  count[6] = (count[6]+1)/2;
  max = 0;
  for (i = 0; i < 9; i++) if (count[i] > max) max = count[i];
  return max;
}


int main(int argc, char **argv)
{
  int i;
  class RoomNumber TheClass;
  int retval;
  int roomNumber;

  if (argc != 2) { fprintf(stderr, "usage: q7 number\n"); exit(1); }

  roomNumber = atoi(argv[1]);
  retval = TheClass.numberOfSets(roomNumber);
  cout << retval << endl;

  exit(0);
}

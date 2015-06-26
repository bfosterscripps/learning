#include "q8.h"

int main(int argc, char **argv)
{
  int i;
  class PackingParts TheClass;
  int retval;
  vector <int> partSizes;
  vector <int> boxSizes;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  partSizes = ;
  boxSizes = ;
*/


 if (atoi(argv[1]) == 0) {
    partSizes.push_back(2);
    partSizes.push_back(2);
    partSizes.push_back(2);
    boxSizes.push_back(1);
    boxSizes.push_back(2);
    boxSizes.push_back(2);
    boxSizes.push_back(3);
  }

 if (atoi(argv[1]) == 1) {
    partSizes.push_back(1);
    partSizes.push_back(5);
    boxSizes.push_back(2);
    boxSizes.push_back(5);
  }

 if (atoi(argv[1]) == 2) {
    partSizes.push_back(10);
    partSizes.push_back(10);
    partSizes.push_back(10);
    partSizes.push_back(10);
    boxSizes.push_back(9);
    boxSizes.push_back(9);
    boxSizes.push_back(9);
    boxSizes.push_back(10);
    boxSizes.push_back(10);
    boxSizes.push_back(10);
  }

 if (atoi(argv[1]) == 3) {
    partSizes.push_back(1);
    partSizes.push_back(1);
    partSizes.push_back(1);
    partSizes.push_back(1);
    boxSizes.push_back(1);
    boxSizes.push_back(2);
    boxSizes.push_back(2);
    boxSizes.push_back(3);
    boxSizes.push_back(6);
    boxSizes.push_back(7);
  }

 if (atoi(argv[1]) == 4) {
    partSizes.push_back(1);
    partSizes.push_back(1);
    partSizes.push_back(1);
    partSizes.push_back(1);
    boxSizes.push_back(2);
    boxSizes.push_back(3);
    boxSizes.push_back(6);
  }

 if (atoi(argv[1]) == 5) {
    partSizes.push_back(10);
    partSizes.push_back(32);
    partSizes.push_back(46);
    partSizes.push_back(55);
    partSizes.push_back(55);
    partSizes.push_back(84);
    partSizes.push_back(100);
    boxSizes.push_back(15);
    boxSizes.push_back(31);
    boxSizes.push_back(34);
    boxSizes.push_back(46);
    boxSizes.push_back(59);
    boxSizes.push_back(68);
    boxSizes.push_back(83);
    boxSizes.push_back(99);
  }

  retval = TheClass.pack(partSizes, boxSizes);
  cout << retval << endl;

  exit(0);
}

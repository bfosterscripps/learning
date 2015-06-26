#include "ColorfulRabbits.cpp"

int main(int argc, char **argv)
{
  int i;
  class ColorfulRabbits TheClass;
  int retval;
  vector <int> replies;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  replies = ;
*/


 if (atoi(argv[1]) == 0) {
    replies.push_back( 1);
    replies.push_back( 1);
    replies.push_back( 2);
    replies.push_back( 2 );
  }

 if (atoi(argv[1]) == 1) {
    replies.push_back( 0 );
  }

 if (atoi(argv[1]) == 2) {
    replies.push_back( 2);
    replies.push_back( 2);
    replies.push_back( 44);
    replies.push_back( 2);
    replies.push_back( 2);
    replies.push_back( 2);
    replies.push_back( 444);
    replies.push_back( 2);
    replies.push_back( 2 );
  }

  retval = TheClass.getMinimum(replies);
  cout << retval << endl;

  exit(0);
}

#include "RouteIntersection.cpp"

int main(int argc, char **argv)
{
  int i;
  class RouteIntersection TheClass;
  string retval;
  int N;
  vector <int> coords;
  string moves;

  if (argc != 2) { fprintf(stderr, "usage: a.out num\n"); exit(1); }

/*
  N = ;
  coords = ;
  moves = ;
*/


 if (atoi(argv[1]) == 0) {
    N = 1;
    coords.push_back(1);
    moves = "+";
  }

 if (atoi(argv[1]) == 1) {
    N = 2;
    coords.push_back(1);
    coords.push_back(2);
    coords.push_back(1);
    coords.push_back(2);
    moves = "++--";
  }

 if (atoi(argv[1]) == 2) {
    N = 3;
    coords.push_back(1);
    coords.push_back(2);
    coords.push_back(3);
    coords.push_back(1);
    coords.push_back(2);
    moves = "+++--";
  }

 if (atoi(argv[1]) == 3) {
    N = 344447;
    coords.push_back(132);
    coords.push_back(51717);
    coords.push_back(628);
    coords.push_back(344447);
    coords.push_back(628);
    coords.push_back(51717);
    coords.push_back(344447);
    coords.push_back(2);
    moves = "+-++-+--";
  }

 if (atoi(argv[1]) == 4) {
    N = 1;
    coords.push_back(1);
    coords.push_back(1);
    moves = "+-";
  }

 if (atoi(argv[1]) == 5) {
    N = 990630;
    coords.push_back(833196);
    coords.push_back(524568);
    coords.push_back(361663);
    coords.push_back(108056);
    coords.push_back(28026);
    coords.push_back(824639);
    coords.push_back(269315);
    coords.push_back(440977);
    coords.push_back(440977);
    coords.push_back(765458);
    coords.push_back(988451);
    coords.push_back(242440);
    coords.push_back(948414);
    coords.push_back(130873);
    coords.push_back(773990);
    coords.push_back(765458);
    coords.push_back(130873);
    coords.push_back(28026);
    coords.push_back(853121);
    coords.push_back(553636);
    coords.push_back(581069);
    coords.push_back(82254);
    coords.push_back(735536);
    coords.push_back(833196);
    coords.push_back(898562);
    coords.push_back(898562);
    coords.push_back(940783);
    coords.push_back(988451);
    coords.push_back(540613);
    coords.push_back(317306);
    coords.push_back(623194);
    coords.push_back(940783);
    coords.push_back(571384);
    coords.push_back(988451);
    coords.push_back(108056);
    coords.push_back(514374);
    coords.push_back(97664);
    moves = "--+---+-+++-+-+---++-++-+---+-+--+-++";
  }

  retval = TheClass.isValid(N, coords, moves);
  cout << retval << endl;

  exit(0);
}

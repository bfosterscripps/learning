#include <cstdlib>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int timing_seconds(string s)
{
  int colon;
  istringstream ss;
  int min, sec;

  colon = s.find(':');
  if (colon == string::npos) return -1;
  s[colon] = ' ';
  ss.str(s);
  if (!(ss >> min >> sec)) return -1;
  return sec + min*60;
}

main()
{
  vector <string> songs;
  vector <string> timings;
  string line;
  int i;

  while(getline(cin, line)) {
    i = line.find("  ");
    if (i == string::npos) { cerr << "Bad line -- " << line << endl; exit(1); }
    songs.push_back(line.substr(0, i));
    while (line[i] == ' ') i++;
    timings.push_back(line.substr(i));
  }
  for (i = 0; i < songs.size(); i++) {
    printf("Song: %-40s -- Timing %5s -- %5d\n", songs[i].c_str(), timings[i].c_str(), 
           timing_seconds(timings[i]));
  }
}
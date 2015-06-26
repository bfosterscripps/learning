string RabbitVoting::getWinner(vector <string> names, vector <string> votes)
{
  map <string, int> v;
  map <string, int>::iterator vit;
  int i;
  string winner;

  for(i = 0; i < votes.size(); i++) {
    if (votes[i] != names[i]) v[votes[i]]++;
  }

  i = 0;
  IT(vit, v) if (vit->second > i) i = vit->second;

  IT(vit, v) if (vit->second == i) {
    if (winner != "") return "";
    winner = vit->first;
  }
  return winner;
}


#include<bits/stdc++.h>

#include "Match.h"

using namespace std;

int main() {

  int overCount, playerCount;
  cout << "No. of players for each team: ";
  cin >> playerCount;
  cout << "\nNo. of overs: ";
  cin >> overCount;
  Match match(overCount, playerCount);
  for (int inning = 0; inning < 2; inning++) {

    cout << "\nBatting Order for team " << inning + 1 << " :\n";
    string playerName;

    for (int i = 0; i < playerCount; i++) {
      cin >> playerName;
      match.initialiseBatsman(inning + 1, playerName, i);

    }

    int strike = 0, nonstrike = 1;

    bool isAllOut = false;

    string ball;

    int totaldeliveries = 6 * overCount, j = 0;

    while (j < totaldeliveries) {

      if (j % 6 == 0 && j < totaldeliveries) {
        cout << "Over " << j / 6 + 1 << endl;
      }

      cin >> ball;

      match.updateScoreboard(strike, ball, nonstrike, j, isAllOut, inning + 1);

      if (isAllOut) {
        match.printScoreboard(inning + 1, j, strike, nonstrike);
        break;
      }

      if (match.getTotalRuns(2) > match.getTotalRuns(1)) {
        match.printScoreboard(inning + 1, j, strike, nonstrike);
        break;
      }

      if (j % 6 == 0) {
        match.printScoreboard(inning + 1, j, strike, nonstrike);
        swap(strike, nonstrike);
      }
    }

  }

  match.matchResult();

  return 0;
}
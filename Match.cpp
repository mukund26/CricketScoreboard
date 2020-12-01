#include "Match.h"

Match::Match(): noOfOvers(0), noOfPlayers(0) {
  firstInningBatsmen.resize(0);
  secondInningBatsmen.resize(0);
}

Match::Match(int noOfOvers, int noOfPlayers): noOfOvers(noOfOvers), noOfPlayers(noOfPlayers) {
  firstInningBatsmen.resize(noOfPlayers);
  secondInningBatsmen.resize(noOfPlayers);
}

void Match::initialiseBatsman(int inning, string playerName, int batsmanOrder) {
  Batsmen batter(playerName, inning);

  if (inning == 1) {
    firstInningBatsmen[batsmanOrder] = batter;

  } else {
    secondInningBatsmen[batsmanOrder] = batter;
  }
}

void Match::setExtras(string ball, int inning) {
  if (inning == 1)
    firstInningExtras[ball]++;
  else
    secondInningExtras[ball]++;
}

int Match::getTotalExtras(int inning) {
  int totalextras = 0;
  if (inning == 1) {
    for (auto x: firstInningExtras) {
      totalextras += x.second;
    }
  } else {
    for (auto x: secondInningExtras) {
      totalextras += x.second;
    }
  }
  return totalextras;
}

int Match::getWides(int inning) {
  if (inning == 1)
    return firstInningExtras["Wd"];
  return secondInningExtras["Wd"];
}

int Match::getNoBalls(int inning) {
  if (inning == 1)
    return firstInningExtras["Nb"];
  return secondInningExtras["Nb"];
}

bool Match::updateWicket(int & strikeBatsman, int & nonStrikeBatsman, int & deliveries, int inning) {
  deliveries++;
  if (inning == 1)
    firstInningBatsmen[strikeBatsman].setIsOut();
  else
    secondInningBatsmen[strikeBatsman].setIsOut();
  if (max(strikeBatsman, nonStrikeBatsman) == noOfPlayers - 1) {
    return true;
  }
  strikeBatsman = max(strikeBatsman, nonStrikeBatsman) + 1;
  return false;
}

void Match::updateScoreboard(int & strikeBatsman, string ball, int & nonStrikeBatsman, int & deliveries, bool & isAllOut, int inning) {
  if (ball == "Wd" || ball == "Nb") {
    setExtras(ball, inning);
    return;
  }
  if (ball == "W") {
    if (inning == 1)
      isAllOut = updateWicket(strikeBatsman, nonStrikeBatsman, deliveries, inning);
    else
      isAllOut = updateWicket(strikeBatsman, nonStrikeBatsman, deliveries, inning);
    return;
  }
  int run = ball[0] - '0';
  if (inning == 1) {
    firstInningBatsmen[strikeBatsman].setTotalRuns(run);
  } else
    secondInningBatsmen[strikeBatsman].setTotalRuns(run);
  if (run & 1) {
    swap(nonStrikeBatsman, strikeBatsman);
  }
  deliveries++;
}

int Match::getTotalRuns(int inning) {
  int score = 0;
  if (inning == 1) {
    for (int i = 0; i < noOfPlayers; i++) {
      score += firstInningBatsmen[i].getTotalRuns();
    }
  } else {
    for (int i = 0; i < noOfPlayers; i++) {
      score += secondInningBatsmen[i].getTotalRuns();
    }
  }
  score += getTotalExtras(inning);
  return score;
}

void Match::printScoreboard(int inning, int deliveries, int strikeBatsman, int nonStrikeBatsman) {
  cout << "Scorecard for Team " << inning << " : \n";
  cout << "Player Name\t\tRuns\tFours\tSixes\tBalls\tStrikeRate\n";
  std::vector < Batsmen > batsmen;
  if (inning == 1) {
    batsmen = firstInningBatsmen;
  } else {
    batsmen = secondInningBatsmen;
  }
  for (int i = 0; i < noOfPlayers; i++) {
    cout << batsmen[i].getPlayerName();
    if ((i == strikeBatsman || i == nonStrikeBatsman) && !batsmen[i].getIsOut()) {
      cout << "*";
    }
    cout << "\t\t\t";
    cout << batsmen[i].getTotalRuns() << "\t";
    cout << batsmen[i].getFours() << "\t";
    cout << batsmen[i].getSixes() << "\t";
    cout << batsmen[i].getBallsFaced() << "\t";
    cout << batsmen[i].getStrikeRate();
    cout << endl;
  }

  cout << "Total " << getTotalRuns(inning) << " / " << getTotalWickets(inning) << endl;
  int totalOvers = deliveries / 6;
  cout << "Overs : " << totalOvers;
  if (deliveries % 6 != 0) {
    cout << "." << deliveries % 6;
  }
  cout << endl;
}

int Match::getTotalWickets(int inning) {
  int wicketCount = noOfPlayers;
  if (inning == 1) {
    for (int i = 0; i < noOfPlayers; i++) {
      if (!firstInningBatsmen[i].getIsOut()) {
        wicketCount--;
      }
    }
  } else {
    for (int i = 0; i < noOfPlayers; i++) {
      if (!secondInningBatsmen[i].getIsOut()) {
        wicketCount--;
      }
    }
  }

  return wicketCount;
}

void Match::matchResult() {
  if (getTotalRuns(1) > getTotalRuns(2)) {
    cout << "Team 1 won by " << getTotalRuns(1) - getTotalRuns(2) << " runs " << endl;
  } else if (getTotalRuns(1) < getTotalRuns(2)) {
    cout << "Team 2 won by " << noOfPlayers - getTotalWickets(2) << " wickets " << endl;
  } else {
    cout << "Match Tie" << endl;
  }
}

Match::~Match() {}
#ifndef MATCH_H
#define MATCH_H

#include "Batsmen.h"

#include<map>

#include<vector>

#include<string>

#include<math.h>

#include<iostream>

class Match: public Batsmen {

  int noOfPlayers, noOfOvers;
  std::map < string, int > firstInningExtras, secondInningExtras;
  std::vector < Batsmen > firstInningBatsmen, secondInningBatsmen;

  public:

    Match();

  Match(int noOfOvers, int noOfPlayers);

  void initialiseBatsman(int inning, string playerName, int batsmanOrder);

  void setExtras(string ball, int inning);

  int getTotalExtras(int inning);

  int getWides(int inning);

  int getNoBalls(int inning);

  bool updateWicket(int & strikeBatsman, int & nonStrikeBatsman, int & deliveries, int inning);

  void updateScoreboard(int & strikeBatsman, string ball, int & nonStrikeBatsman, int & deliveries, bool & isAllOut, int inning);

  int getTotalRuns(int inning);

  void printScoreboard(int inning, int deliveries, int strikeBatsman, int nonStrikeBatsman);

  int getTotalWickets(int inning);

  void matchResult();

  ~Match();

};

#endif
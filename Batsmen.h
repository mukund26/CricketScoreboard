#ifndef BATSMEN_H
#define BATSMEN_H

#include "Player.h"

#include<string>

using namespace std;

class Batsmen: public Player {

  string playerName;
  int totalRuns, ballsFaced, fours, sixes;
  float strikeRate;
  bool isOut;

  public:

    Batsmen();

  Batsmen(string playerName, int teamNo);

  void setTotalRuns(int val);

  void setBallsFaced();

  void setFours();

  void setSixes();

  void setIsOut();

  int getTotalRuns();

  int getBallsFaced();

  int getFours();

  int getSixes();

  float getStrikeRate();

  bool getIsOut();

  ~Batsmen();

};

#endif
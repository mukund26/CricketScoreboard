#ifndef PLAYER_H
#define PLAYER_H

#include<string>

class Player {

  std::string playerName;
  int teamNo;

  public:

  Player();
  Player(std::string name, int teamNo);
  std::string getPlayerName();
  int getTeamNo();

  ~Player();

};

#endif
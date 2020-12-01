#include "Player.h"

Player::Player(): playerName(""), teamNo(-1) {}

Player::Player(std::string playerName, int teamNo): playerName(playerName), teamNo(teamNo) {}

std::string Player::getPlayerName() {
  return playerName;
}

int Player::getTeamNo() {
  return teamNo;
}

Player::~Player() {}
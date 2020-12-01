#include "Batsmen.h"

Batsmen::Batsmen(): Player("", -1), totalRuns(0), ballsFaced(0), sixes(0), fours(0), strikeRate(0.0), isOut(false) {}

Batsmen::Batsmen(string playerName, int teamNo): Player(playerName, teamNo), totalRuns(0), ballsFaced(0), sixes(0), fours(0), strikeRate(0.0), isOut(false) {}

void Batsmen::setTotalRuns(int val) {
  totalRuns += val;
  setBallsFaced();
  if (val == 4) setFours();
  if (val == 6) setSixes();
}

void Batsmen::setBallsFaced() {
  ballsFaced++;
}

void Batsmen::setFours() {
  fours++;
}

void Batsmen::setSixes() {
  sixes++;
}

void Batsmen::setIsOut() {
  isOut = true;
  setBallsFaced();
}

int Batsmen::getTotalRuns() {
  return totalRuns;
}

int Batsmen::getBallsFaced() {
  return ballsFaced;
}

int Batsmen::getFours() {
  return fours;
}

int Batsmen::getSixes() {
  return sixes;
}

float Batsmen::getStrikeRate() {
  if (ballsFaced == 0) {
    return 0.0;
  }
  return (float)(totalRuns * 100.0) / (float)(ballsFaced);
}

bool Batsmen::getIsOut() {
  return isOut;
}

Batsmen::~Batsmen() {}
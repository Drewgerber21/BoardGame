#include "player.h"
#include <iostream>
#include <stdlib.h>
#include <vector>

// List of all spaces that are ladders and where they lead
std::vector<std::vector<int>> ladders = { {1, 38}, {4, 14}, {9, 31}, {28, 84},
                                          {36, 44}, {51, 67}, {71, 91}, {80, 100} };

// List of all spaces that are chutes and where they lead 
std::vector<std::vector<int>> chutes = { {16, 6}, {47, 26}, {49, 11}, {56, 53}, 
                                         {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 78} };

// Returns a random number between 1 and 6
int Roll() {
  return rand() % 6 + 1; 
}

int CheckSpace(int currentSpace) {
  int newSpace = currentSpace;
  
  //Check ladders
  for(int i = 0; i < 8; i++) {
    if(ladders[i][0] == currentSpace) {
      newSpace = ladders[i][1];
    }
  }
  
  //Check Chutes
  for(int i = 0; i < 9; i++) {
    if(chutes[i][0] == currentSpace) {
      newSpace = chutes[i][1];
    }
  }

  return newSpace;
}

void Player::SetSpace(int spaceOnBoard) {
  spaceOnBoard_ = spaceOnBoard;
}

void Player::SetTurn(int numberOfTurns) {
  numberOfTurns_ = numberOfTurns;
}

void Player::Move(int distanceMoved) {
  spaceOnBoard_ += distanceMoved;
}

void Player::TakeTurn() {
  //Roll and move
  int spacesMoved = Roll();
  if(spaceOnBoard_ + spacesMoved > 100) {
    spacesMoved = 0;
  }
  spaceOnBoard_ += spacesMoved;
  
  //Check space
  int newSpace = CheckSpace(spaceOnBoard_);
  
  //move if needed
  spaceOnBoard_ = newSpace;

  // Increase turn counter
  numberOfTurns_++;
}

bool Player::HasWon(){
  if (spaceOnBoard_ == 100) {
    return true;
  } else {
    return false;
  }
}

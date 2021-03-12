#include "player.h"
#include <iostream>

void Player::SetSpace(int spaceOnBoard) {
  spaceOnBoard_ = spaceOnBoard;
}

void Player::SetTurn(int numberOfTurns) {
  numberOfTurns_ = numberOfTurns;
}

void Player::Move(int distanceMoved) {
  spaceOnBoard_ += distanceMoved;
}

#include "player.h"
#include <iostream>
#include <stdlib.h>

int Roll() {
  srand (time(NULL));
  return rand() % 6 + 1; 
}

int main() {
  Player player1(0, 0);
  std::cout <<player1.GetSpace() <<std::endl;
  player1.Move(Roll());
  std::cout <<player1.GetSpace() <<std::endl;
  return 0;
}

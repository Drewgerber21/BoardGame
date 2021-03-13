#include "player.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
//clang++ -std=c++17 main.cc player.cc -o main

void Setup(std::vector<Player>& player, int& numOfPlayers, int&numOfGames) {
  // Gets number of players from 1- 4
  while(true) {
    std::cout << "How many players? (Max of 4): ";
    std::cin >> numOfPlayers;
    if (numOfPlayers < 5 && numOfPlayers > 0) {
      break;
    } 
    std::cout << "Invaild Number of Players" << std::endl;
  }

  // Gets number of games greater than 0
  while(true) {
    std::cout << "How many games? (At least 1): ";
    std::cin >> numOfGames;
    if (numOfGames > 0) {
      break;
    } 
    std::cout << "Invaild Number of Games" << std::endl;
  }

  for(int i = 0; i < numOfPlayers; i++) {
    switch(i) {
      case 0: { Player Player1(0, 0);
                player.push_back(Player1);
                break;
      }
      case 1: { Player Player2(0, 0);
                player.push_back(Player2);
                break;
      }
      case 2: { Player Player3(0, 0);
                player.push_back(Player3);
                break;
      }
      case 3: { Player Player4(0, 0);
                player.push_back(Player4);
                break;
      }    
   }
  }
}

void saveResults(std::vector<int>& data, std::vector<Player> players, int numOfPlayers ,int winner) {
  data.at(winner) += 1;
}

void resetPlayers(std::vector<Player>& players, int numOfPlayers) {
  for (int i = 0; i < numOfPlayers; i++) {
    players.at(i).SetSpace(0);
    players.at(i).SetTurn(0);
  }
}

int play(std::vector<int>& data, std::vector<Player>& players, int numOfPlayers, int gameNumber) {
  bool hasWon = false;
  int winner;
  
  while(!hasWon) {
    //take turn
    for (int i = 0; i < numOfPlayers; i++) {
      players.at(i).TakeTurn();
      if (players.at(i).HasWon() == true) {
        hasWon = true;
        winner = i;
        break;
      }
    }
  }

  saveResults(data, players, numOfPlayers, winner);
  resetPlayers(players, numOfPlayers);
  return winner;
}

int main() {
  // For random number generation
  srand (time(NULL));
  
  // Create Players
  int numOfPlayers = 0;
  int numOfGames = 0;
  std::vector<Player> players;
  std::vector<int> data = {0, 0, 0, 0};
  Setup(players, numOfPlayers, numOfGames);
  
  // Run Game
  for (int i = 0; i < numOfGames; i++) {
    play(data, players, numOfPlayers, i);
  }

  // Print results
  for (int i = 0; i < numOfPlayers; i++) {
    std::cout << "Player " << i + 1 << " won " << data.at(i) << " times. That is " 
              << (double(data.at(i)) / double(numOfGames)) * 100.0 << "% of the games." << std::endl;
  }
  return 0;
}

#include <iostream>

class Player {
 public:
    Player(){};
    Player(int spaceOnBoard, int numberOfTurns) 
          : spaceOnBoard_(spaceOnBoard), numberOfTurns_(numberOfTurns){};
    
    void SetSpace(int spaceOnBoard);

    int GetSpace() { return spaceOnBoard_; }

    void SetTurn(int numberOfTurns);

    int GetTurn() { return numberOfTurns_; }

    void Move(int distanceMoved);
 private:
    int spaceOnBoard_;
    int numberOfTurns_;
};

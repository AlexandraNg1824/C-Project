#include "Snake.h"

class AutonomousSnake : public Snake{
public:
  void steer (char cmd, const GameBoard *board, int candyRow, int candyCol) override;
};
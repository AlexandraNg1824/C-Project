#include "AutonomousSnake.h"

void AutonomousSnake::steer (char cmd, const GameBoard *board, int candyRow, int candyCol){
  if(intersects(head()->row() + 1, head()->col())){
    _dCol = 1;
  }
  else if(intersects(head()->row(), head()->col() + 1)){
    _dRow = 1;
  }
  // //else if (intersects(head()->row() + 1, head()->col() + 1)){
  //}
  else{
    if(head()->col() < candyCol) _dCol = 1;
    else if (head()->col() > candyCol) _dCol = -1;
    else _dCol = 0;
    
    if(head()->row() < candyRow) _dRow = 1;
    else if (head()->row() > candyRow) _dRow = -1;
    else _dRow = 0;
  }
};
//needa avoid to crash 
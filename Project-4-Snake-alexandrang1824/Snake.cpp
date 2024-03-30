#include "Snake.h"


// Starts the snake off at row 5, col 5.  Gives the snake a tail that extends
// from the head to 5,4 and 5,3 (row, col)
Snake::Snake(){
  pushBack(5, 5);
  pushBack(5, 4);
  pushBack(5, 3);
}

// Set the tiles on the gameboard corresponding to each of the snake's nodes.
void Snake::setTiles(GameBoard *board)const{
  // FOR NOW - NG todo fix this later
  // We want a different glyph for the head, and we want the color to be the snake's current color 
  //SOLVE --> check if head? _headGlyph: _glyph
  char glyph = '\0';
  SnakeListNode *curNode = head(); 
  while (curNode != nullptr) {
    // ====> DJH: Love the ternary here!
    // Anoter nice idea is to call your glyph variable nextGlyph, initialize
    // it to _headGlyph, then change it to _glyph after the setTile
    // in the loop (the loop will have the head glyph on the first iteration)
    curNode == head()? glyph = _headGlyph: glyph = _glyph;
    board->setTileAt(curNode->row(), curNode->col(), glyph, _color);
    curNode = curNode->nextNode();
  }
}

// Returns whether or not the snake will "crash". Compute the snake's
// next position using its direction vector and it's current position.
// If that next position collides with the edges of the board or **with
// the snake itself**, then the snake will crash.
bool Snake:: willCrash(const GameBoard *board) const {
  int newRow = head()->row() + _dRow;
  int newCol = head()->col() + _dCol;
  //when out of bound, willCrash is true 
  //if Inbound, willCrash is False
  // ====> DJH: Love the individual bool expressions!
  bool colNotInbound = newCol < 0 || newCol >= board->colCount();
  bool rowNotInbound = newRow < 0 || newRow >= board->rowCount();
  bool itself = intersects(newRow, newCol);
  return colNotInbound || rowNotInbound || itself;
}

// Return whether row,col matches the coordinates of one of the snake's nodes.
bool Snake::intersects(int row, int col) const{
  bool result = false;
  SnakeListNode *curNode = head();
  while (curNode != nullptr){
    if(curNode->row() == row && curNode->col() == col){
      result = true;
      break;
    }
    curNode = curNode->nextNode();
  }
  return result;
}

// Update _dRow, _dCol to indicate the direction of next step.
// Autonomous subclass will override and ignore cmd.
// The default implementation ignores board and candy coords.
void Snake::steer (char cmd, const GameBoard *board, int candyRow, int candyCol){
  switch(cmd){
    case arrowUpKey:
      _dRow = -1;
      _dCol = 0;
      break;
    case arrowDownKey:
      _dRow = 1;
      _dCol = 0;
      break;
    case arrowRightKey:
      _dRow = 0;
      _dCol = 1;
      break;
    case arrowLeftKey:
      _dRow = 0;
      _dCol = -1;
      break;
  }
}

// Moves the head to nextRow,nextCol and adjusts the tail as needed.
void Snake::step(GameBoard *board){
  // We want a different glyph for the head, and we want the color to be the snake's current color ---> solve on line 70, the parameter on function call using variables 
  //head become the body after moving
  board->setTileAt(head()->row(), head()->col(), _glyph, _color);
  //the new direction get a new head @
  int newRow = head()->row() + _dRow;
  int newCol = head()->col() + _dCol;
  pushFront(newRow, newCol);
  board->setTileAt(head()->row(), head()->col(), _headGlyph, _color);
  SnakeListNode* delTail = tail();
  //execution efficient (get the tail just once, so we only walk the list once)
  if(_calories > 0) {
    _calories -= 1;
  } else {
    board->clearTileAt(delTail->row(), delTail->col());
    popBack();
  }
}

void Snake::eat(int calories, Color color){
  _calories = _calories + calories;
  _color = color;
}



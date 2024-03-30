#ifndef __SNAKE__
#define __SNAKE__

#include "SnakeLinkedList.h"
#include "GameBoard.h"

class Snake : public SnakeLinkedList {
public:
  // Starts the snake off at row 5, col 5.  Gives the snake a tail that extends
  // from the head to 5,4 and 5,3 (row, col)
  Snake();

  // Returns whether or not the snake will "crash". Compute the snake's
  // next position using its direction vector and it's current position.
  // If that next position collides with the edges of the board or **with
  // the snake itself**, then the snake will crash.
  bool willCrash(const GameBoard *board) const;

  // Return whether row,col matches the coordinates of one of the snake's nodes.
  bool intersects(int row, int col) const;

  // Set the tiles on the gameboard corresponding to each of the snake's nodes.
  void setTiles(GameBoard *board) const;

  // Update _dRow, _dCol to indicate the direction of next step.
  // Autonomous subclass will override and ignore cmd.
  // The default implementation ignores board and candy coords.
  virtual void steer(char cmd, const GameBoard *board, int candyRow, int candyCol);

// Moves the head to nextRow,nextCol and adjusts the tail as needed.
  void step(GameBoard *board);

  void eat(int calories, Color color);

  bool headIntersects(int row, int col) {
    return head()->row() == row && head()->col() == col;
  }

  int dRow() const { return _dRow; }
  int dCol() const { return _dCol; }

protected:
  int _calories = 0;
  Color _color = defaultColor;
  char _glyph = 'o';
  char _headGlyph = '@';
  int _dRow = 0;
  int _dCol = 1;
};


#endif
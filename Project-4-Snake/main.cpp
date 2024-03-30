#include "GameBoard.h"
#include "Snake.h"
#include "Candy.h"
#include "Utils.h"
#include "AutonomousSnake.h"

static const int kBoardRowCount = 20;
static const int kBoardColCount = 30;

/*****************************************************************************/

/*****************************************************************************/

int main() {
  bool gameOver = false;
  int turnCount = 0;
  bool twitchMode = false;
  string status = "";

  GameBoard board(kBoardRowCount, kBoardColCount);
  board.setDisplayCoords(false);
  board.setDisplayEmptyTileDots(false);

  //Snake snake;
  //snake.setTiles(&board);

  AutonomousSnake snake;
  snake.setTiles(&board);

  /*
  Declare a candy object here. Use Candy::randomCandy() to initialize it.
  Invoke its draw() method
  */
  Candy candy = Candy::randomCandy(snake, kBoardRowCount, kBoardColCount);
  candy.draw(&board);


  while (!gameOver) {
    board.setMessage(Message(status, snake));
    status = "";

    // draw the tiles and status on the console
    board.updateConsole();

    unsigned int timeout = twitchMode ? 1 : 0;
    char cmd = board.nextCommandKey(timeout);

    switch (cmd) {
      case ' ':
        twitchMode = !twitchMode;
        break;
      case 'q':
      case 'Q':
        cout << "Bye" << endl;
        gameOver = true;
        break;
      default:
        snake.steer(cmd, &board, candy.row(), candy.col());
        break;
    }

    LogGameStats(turnCount, cmd, snake); // mse-evil

    if (snake.willCrash(&board)) {
      status = "Ouch, my nose!";
      gameOver = true;
      continue;
    }

    snake.step(&board);

    /*
    Here, determine if the snake's head intersects the candy.
    If so, have the snake eat the candy and redraw so that its
    updated color is visible. Also upon eating, initialize candy
    to a new, random candy, and draw it.
    */
    if(snake.headIntersects(candy.row(), candy.col())){
      snake.eat(candy.calories(), candy.color());
      snake.setTiles(&board);
      candy = Candy::randomCandy(snake, kBoardRowCount, kBoardColCount);
      candy.draw(&board);
    }

    ++turnCount;
  }

  snake.setTiles(&board);
  board.setMessage(Message(status, snake));
  board.updateConsole();

  // LogGameStats(turnCount, cmd, snake); really doesn't make sense to log cmd or snake here
}

/*
WOW, NG! Spot on! And several signs of maturity in your coding style.
Really made me happy to read this!  100/100
*/

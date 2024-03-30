// PLEASE COMPLETE THE NEXT COMMENTS WITH:
// your student id: 20570785
// your last name: Ng
// your first name: Wingyi
// what you prefer to be called: Ng (just the letter, N + G)
// a phonetic spelling of what you prefer to be called:

// WRITE YOUR NAME AFTER THIS COMMENT TO ACKNOWLEDGE THAT YOU HAVE READ AND
// UNDERSTOOD IT: The purpose of 22B programming projects is for me to gain
// understanding and practice as a developer of original software and to provide
// a complete record of that development for evaluation. Understanding this, I
// will not paste code into my 22B projects. I will author code originally, and
// perform editing of my code soley within this IDE. Understood and agreed:
// Wingyi Ng

#include "GameBoard.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// *** Use this function as-is ***
string MessageLine(int turnCount) {
  ostringstream messageBuf;
  messageBuf << "Turn: " << turnCount << " (press 'q' to quit)";
  return messageBuf.str();
}

/***** Modify the switch statement in main so that the player moves around the
board when the arrow keys are pressed.

Note: The console needs keyboard focus in order to receive keystrokes.
Click on the console before trying use the arrow keys.

Hint: GameBoard has a method, clearTileAt, you might find useful. It erases the
specified tile.

*****/

// ====> DJH -0% As we discussed in class, can you see how we don't need
// to return bool literals (true/false)? Just returning the value of
// the conditional expression is simpler to code and to read.
// Please come see me if you're not sure what I mean.
bool isValidPosition(const GameBoard *gameBoard, int row, int col) {
  if (row < 0 || row >= 10 || col < 0 || col >= 20) {
    return false;
  }
  return true;
}
//return (row >= 0 && row < gameBoard -> rowCount()) && (col >= 0 && col < gameBoard -> //colCount());

int main() {
  bool gameOver = false;

  int playerRow = 5;
  int playerCol = 5;
  int turnCount = 0;

  GameBoard board(10, 20);

  while (!gameOver) {
    board.setTileAt(playerRow, playerCol, '@', Color::blue);

    board.setMessage(MessageLine(turnCount));

    board.updateConsole();

    char cmd = board.nextCommandKey();

    board.clearTileAt(playerRow, playerCol);

    // Hint: This code might be helpful for debugging.
    // board.clearTileAt(playerRow, playerCol); (to clear the @)
    // cout << "command key: ";
    // GameBoard::printCommandKey(cmd);
    // if(cmd == '?')
    //{
    // cout << "I am in (" << playerRow << ", " << playerCol << ")";
    // cout << endl;
    //}

    switch (cmd) {
    case arrowUpKey:
      // ***** Move the player up.
      if (isValidPosition(&board, playerRow - 1, playerCol)) {
        playerRow--;
        turnCount++;
      } 
        // ====> DJH: I like the attention to detail on turn count. 
        // Consider though, that undo-ing the future increment with
        // a decrement is a little awkward. A prettier solution would
        // be to remove the decrement from the bottom of the loop, and
        // only increment for valid moves. ***Another idea could be a
        // local bool that you reset here, maybe called...
        // turnWasValid = false;
        // set it to true at the top of the loop, then at the bottom
        // only increment turnCount if turnWasValid
      break;
    case arrowDownKey:
      // ***** Move the player down.
      if (isValidPosition(&board, playerRow + 1, playerCol)) {
        playerRow++;
        turnCount++;
      } 
      break;
    case arrowRightKey:
      // ***** Move the player right.
      if (isValidPosition(&board, playerRow, playerCol + 1)) {
        playerCol++;
        turnCount++;
      }
      break;
    case arrowLeftKey:
      // ***** Move the player down.
      if (isValidPosition(&board, playerRow, playerCol - 1)) {
        playerCol--;
        turnCount++;
      } 
      break;
    case '?':
      board << "Player's current coordinates: (";
      board << playerRow << ", " << playerCol << ")\n";
      break;
    case 'q':
    case 'Q':
      gameOver = true;
      break;
    default:
      // My eyes! The goggles do nothing.
      break;
    }
  }
  // ***** Print the final turnCount and the player position.
  cout << "The turnCout is: " << turnCount - 1 << endl;
  cout << "The player postion is (" << playerRow << ", ";
  cout << playerCol << ")" << endl;
}

/* ====> DJH:
  Very well done. Please come see me if you're uncertain
  about thee comments above. 20/20
*/
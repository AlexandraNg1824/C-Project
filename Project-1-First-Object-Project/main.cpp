#include "GameBoard.h"

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
static const int kInitialPlayerCalories = 120;
static const int kPlayerCaloriesPerMove = 5;
static const int kCalorieGainPerMeal = 60;
static const int restingCalories = 5;

/*****************************************************************************/
// TurnInfo
//
// This struct contains parameters required for a Creature to take its turn.
// In this project, it contains just the board dimensions; but the structure
// allows us the opportunity to change this later without changing method
// signatures.
/*****************************************************************************/

struct TurnInfo {
  int rowCount;
  int colCount;
};

/*****************************************************************************/
// Creature
/*****************************************************************************/

class Creature {
public:
  Creature() = default;

  // Initialize the creature's instance data using values in creatureParams
  // as you've done in the lab.
  Creature(string creatureParams) {
    stringstream ss (creatureParams);
    //name glyph row col dRow dCol calories
    ss >> _name;
    ss >> _glyph;
    ss >> _row;
    ss >> _col;
    ss >> _dRow;
    ss >> _dCol;
    ss >> _calories;
    _initialCalories = _calories;
  }

  // return true if the Creature's position equals the passed position.
  bool positionEquals(int row, int col) {
    //if (row == _row && col == _col)
      //return true;
    //else
      //return false;
    return ((_row == row) && (_col == col));
  }

  // The takeTurn() method is coded for you. It is called by the main loop
  // to prompt the Creature to behave. For now, it simply calls the move()
  // method.
  // Use it as-is in Part A of the project. You will enhance it in Part B.
  void takeTurn(const TurnInfo &turnInfo){
    // am i resting right now?
    // if so, call my rest method
    // else call my move method
    if (_resting)
      rest();
    else
      move(turnInfo);
  }

  void rest(){
    //since i am resting, add my calories
    // have I rested 
    //_resting = false
    //return ((_initialCalories/ _calories) >= cals))
    
    // ====> DJH: A little awkwardly phrased. We know we're resting here
    // because this is only called when _resting is true, so we know that the 
    // calories are insufficient when we get here. It makes a little more sense
    // to increment, then check whether we've recovered.

    _calories = _calories + restingCalories;
    if (_calories >= 0.75*(float)_initialCalories)
      _resting = false;
  }
    
    /*
    if (_calories < 0.75*(float)_initialCalories)
      _calories = _calories + restingCalories;
    else
      _resting = false;
    }
    */
  // move() determines where the Creature will move next, checking that the
  // location is valid (within bounds on the board).
  // Use it as-is in Part A of the project. You will enhance it in Part B.
  void move(const TurnInfo &turnInfo) {
    int candidateRow = _row + _dRow;
    if (candidateRow < 0 || candidateRow >= turnInfo.rowCount) {
      _dRow *= -1;
      candidateRow = _row + _dRow;
    }
    int candidateCol = _col + _dCol;
    if (candidateCol < 0 || candidateCol >= turnInfo.colCount) {
      _dCol *= -1;
      candidateCol = _col + _dCol;
    }
    if (_row != candidateRow || _col != candidateCol) {
      _row = candidateRow;
      _col = candidateCol;
      //Here: we know for sure that the creature has changed position
      //That's a good place to decide that you must expend calories
      //Decrement calories here, if pooped out, to rest mode
      //_resting = true
      _calories = _calories - kPlayerCaloriesPerMove;
      if(_calories <= 0)
        _resting = true;
    }
  }
    // set a tile representing the creature's current state on the game board
  void setTile(GameBoard *board) const {
    board->setTileAt(_row, _col, _glyph, color());
  }
    // clear a tile representing the creature's current state on the game board
  void clearTile(GameBoard *board) const {
    board->clearTileAt(_row, _col);
  }

  // use this method as-is. it provides a formatted string representing the
  // creature's state
  string toString() const{ 
    ostringstream oss;
    oss << left << setw(16) << _name << "(" << _glyph << ") " << setw(16) << _calories;
    return oss.str();
  }

  // Use this method as-is, or feel free to change Creatures' colors to any one
  // of the enum constants defined in GameBoard.h
  Color color() const { return Color::blue; }

  // Part A, step 3: Define getters. These should follow the naming and style
  // standards discussed in class and in labs.

  // e.g.: string name() const { return _name; }
  string name() const {return _name;}
  int row() const {return _row;}
  int col() const {return _col;}
  int dRow() const {return _dRow;}
  int dCol() const {return _dCol;}
  char glyph() const {return _glyph;}
  int calories() const {return _calories;}
//storing the original value of calories
  int initialCalories() const {return _initialCalories;}
  bool resting() const {return _resting;}

  
private:
  // Part A, step 2: Define the instance vars:

  // a string called _name which is the creature's name
  // an int called _row that represents the creature's row on the GameBoard
  // an int called _col that represents the creature's column on the GameBoard
  // two ints called _dRow and _dCol ("d" stands for delta) which can be -1, 0,
  // or +1,
  //   these describe a direction vector. they are added to the Creature's row
  //   and col as it moves, and they are changed as it "bounces" off the walls
  // a char called _glyph which represents the creature's symbol on the
  // GameBoard you will be asked to create a few more variables in Part B

  // e.g.: string _name = "";
  string _name = "";
  int _row = 0;
  int _col = 0;
  int _dRow = 0;
  int _dCol = 0;
  char _glyph = '\0';
  int _calories = 0;
  int _initialCalories = 0;
  bool _resting = false;

  // Part A, step 3: Define the setters. These should follow the naming and
  // style standards discussed in class and in labs.

  // e.g.: void setName(string name) { _name = name; }
  void setName(string name) {_name = name;}
  void setRow(int row) {_row = row;}
  void setCol(int col) {_col = col;}
  void setDRow(int dRow) {_dRow = dRow;}
  void setDCol(int dCol) {_dCol = dCol;}
  void setGlyph(char glyph) {_glyph = glyph;}
  void setCalories(int calories) {_calories = calories;}
  void setInitialCalories(int initialCalories){_initialCalories = initialCalories;}
  void setResting(bool resting) {_resting = resting;}

};

/*****************************************************************************/
// CreatureList
/*****************************************************************************/

class CreatureList {
public:
  // Iterate the _creatures vector, deleting the creature pointers it contains
  ~CreatureList() {
    for(int i = 0; i < creatureCount(); i++)
      delete _creatures[i];
  }
  // Like the lab on this topic, open the file, check that it has opened
  // Read each line, rejecting comment and blank lines.  Use the string
  // found on each line to create a new Creature, adding the resulting pointer
  // to the _creatures vector. Close the file.
  void addCreaturesFromFile(string fileName) {
    ifstream file(fileName);
    if(!file.is_open()){
      cout << "Failed to open file: " << fileName << endl;
      exit(0);
    }
    string line;
    while (getline(file, line)){
      if(line.size() == 0 || line.find("//") == 0) continue;
      Creature* creature = new Creature(line);
      _creatures.push_back(creature);
    }
    file.close();
  }
  // return the size of the _creatures vector.
  int creatureCount() {
    return _creatures.size();
  }
  // Iterate the _creatures vector, invoking the setTile() method on each one.
  void setTiles(GameBoard *board) {
    for(int i = 0; i < creatureCount(); i++){
      Creature* creature = _creatures[i];
      creature->setTile(board);
    }
  }
  // Iterate the _creatures vector, invoking the clearTile() method on each one.
  void clearTiles(GameBoard *board) {
    for(int i = 0; i < creatureCount(); i++){
      Creature* creature = _creatures[i];
      creature->clearTile(board);
    }
  }
  // Iterate the _creatures vector, invoking the takeTurn() method on each one.
  void takeTurns(const TurnInfo &turnInfo) {
    for(int i = 0; i < creatureCount(); i++){
      Creature* creature = _creatures[i];
      creature->takeTurn(turnInfo);
    }
  }
  // Search the _creatures vector for a Creature with matching row and col.
  // If found, return it; otherwise return nullptr.
  Creature *creatureAtPosition(int row, int col){
    //once upon a time
    Creature *result = nullptr;
    for(int i = 0; i < creatureCount(); i++){
      Creature* creature = _creatures[i];
      if (creature->positionEquals(row, col)){
        result = creature;
        break;
        }
      }
    //the end
      return result;
    }
  // Use this method as-is. When a creature is eaten, it must be removed from
  // the _creatures vector. This delete's the pointer before dropping the
  // reference to it so the corresponding Creature will be deallocated from the
  // heap.
  void eraseCreature(Creature *creature) {
    for (int index = 0; index < creatureCount(); index++) {
      if (_creatures[index] == creature) {
        delete _creatures[index];
        _creatures.erase(_creatures.begin() + index);
        break;
      }
    }
  }
  // Iterate the _creatures vector, calling each Creature's toString().
  // Concatenate each string on an osstringstream, placing endl's between
  // them. return the resulting string
  string toString() {
    ostringstream oss;
    for(int i = 0; i < creatureCount(); i++){
      Creature* creature = _creatures[i];
      oss << creature->toString() << endl; 
    }
    return oss.str();
  }

private:
  // Part A, step 5: Define the instance var
  vector<Creature*> _creatures;
};

/*****************************************************************************/
// Utils
/*****************************************************************************/

// Use this function as-is. It formats a complete status message using the
// player's status as well as the CreatureList status string (toString())
// The main loop places this result on the GameBoard, by invoking the board's
// setMessage() method.
string MessageLine(CreatureList *creatureList, int playerCalories,
                   string status = "") {
  ostringstream oss;
  oss << "Player has " << playerCalories << " cals";
  return oss.str();
}

void LogGameStats(int turnCount, char cmd, int playerCalories, int creatureCount) {
  static ofstream logFile("CreatureLogFile.txt");
  string move = "\\" + to_string(cmd);
  switch (cmd) {
    case arrowUpKey:
      move = "up";
      break;
    case arrowDownKey:
      move = "down";
      break;
    case arrowRightKey:
      move = "right";
      break;
    case arrowLeftKey:
      move = "left";
      break;
    case ' ':
      move = "rest";
      break;
}
  logFile << "turn:" << turnCount << " cmd:'" << move << "' calories:" << playerCalories << " creatures:" << creatureCount << endl;
}

/*****************************************************************************/
// main / controller
/*****************************************************************************/

// Use this code as-is in Part A. In Part B, you will make a small edit to it.
int main() {
  bool gameOver = false;
  int turnCount = 0;
  string status = "";

  const int kBoardRowCount = 20;
  const int kBoardColCount = 30;
  GameBoard board(kBoardRowCount, kBoardColCount);
  board.setDisplayCoords(false);

  int playerRow = 5;
  int playerCol = 5;
  int playerCalories = kInitialPlayerCalories;

  CreatureList creatureList;
  creatureList.addCreaturesFromFile("creature-data.txt");
  board.setLogLineCount(creatureList.creatureCount() + 1);

  while (!gameOver) {
    // set board tile for the player, set the board message to the current
    // status
    creatureList.setTiles(&board);
    board.setTileAt(playerRow, playerCol, '@', defaultColor);
    board.setMessage(MessageLine(&creatureList, playerCalories, status));
    board.clearLog();
    board << creatureList.creatureCount() << " creatures:\n";
    board << creatureList.toString();
    status = "";

    // draw the tiles and status on the console
    board.updateConsole();

    board.clearTileAt(playerRow, playerCol);
    creatureList.clearTiles(&board);

    // get user input
    char cmd = board.nextCommandKey();

    bool playerMoved = false;

    switch (cmd) {
    case arrowUpKey:
      if (playerRow > 0) {
        playerMoved = true;
        --playerRow;
      }
      break;
    case arrowDownKey:
      if (playerRow + 1 < board.rowCount()) {
        playerMoved = true;
        ++playerRow;
      }
      break;
    case arrowRightKey:
      if (playerCol + 1 < board.colCount()) {
        playerMoved = true;
        ++playerCol;
      }
      break;
    case arrowLeftKey:
      if (playerCol > 0) {
        playerMoved = true;
        --playerCol;
      }
      break;
    case 'q':
    case 'Q':
      cout << "Bye" << endl;
      gameOver = true;
      break;
    default:
      break;
    }
    if (playerMoved) {
      playerCalories -= kPlayerCaloriesPerMove;
    }

    // here, we're passing a const TurnInfo ref, creating one inline
    // using the "designated initialiation" style which names the member vars
    creatureList.takeTurns({.rowCount=board.rowCount(), .colCount=board.colCount() });

    // the player and creatures may have moved. find out if a creature  occupies
    // the same position as the player. if so, the player will eat that creature
    Creature *creatureToEat =
        creatureList.creatureAtPosition(playerRow, playerCol);
    if (creatureToEat) {
      status = "Ate the " + creatureToEat->name();
      playerCalories += creatureToEat->calories();
      creatureList.eraseCreature(creatureToEat);
      if (creatureList.creatureCount() == 0) {
        status = "Having eaten everything, player wins!";
        gameOver = true;
      }
    }

    if (playerCalories <= 0) {
      status = "Having starved, player dies.";
      gameOver = true;
    }

    LogGameStats(turnCount, cmd, playerCalories, creatureList.creatureCount());
    ++turnCount;
  }
  creatureList.setTiles(&board);
  board.setTileAt(playerRow, playerCol, '@', defaultColor);
  board.setMessage(MessageLine(&creatureList, playerCalories, status));
  board.updateConsole();
}

/*
Excellent, NG!  100/100.  Very glad you sought help. If you get an earlier start on the next
ones, there will be more time in which to get help.
*/
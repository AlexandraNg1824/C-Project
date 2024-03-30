#include "GameBoard.h"
#include "Life.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

static const string figurePath = "figures/";
static const string figures[] = {"basic-figures.txt", "burst.txt", "canada-goose.txt", "glider-gun.txt", "queen-bee.txt"};
static const int figuresCount = sizeof(figures)/sizeof(*figures);

/*****************************************************************************/
// Honors
// In this section of main.cpp, declare and define a function that saves
// strings which represent instances of Life

// Declare and define another function that determines whether a given instnace
// of Life matches one of the saved instances

/*****************************************************************************/


// Utils

// return a user-selected index in the figures array
int PresentStartUI() {
  cout << "To start, specify a figure 1-" << figuresCount << ", and press return:";
  cout << endl << endl;
  for (int i=0; i<figuresCount; i++) {
    cout << i+1 << " load " << figures[i] << endl;
  }
  int figureNumber = 0;
  do {
    cout << "> ";
    cin >> figureNumber;
  } while (figureNumber < 1 || figureNumber > figuresCount);

  return figureNumber - 1;
}

// set the board's message to the simulation status and update 
void PrintStatusMessage(GameBoard *board, long int generation, int totalLiving, string append="") {
  string message = "Generation: " + to_string(generation) +
    "; Living cells: " + to_string(totalLiving) +
    "\nSpace bar toggles play/pause, right arrow steps, q quits.";

  if (append.length()) {
    *board << append << endl;
  }
  board->setMessage(message);
  board->updateConsole();
}

/*****************************************************************************/

int main() {
  // prompt user for a figure index
  int figureIndex = PresentStartUI();
  const string pathFile = figurePath + figures[figureIndex];
  ifstream ifs(pathFile);
  if (!ifs.is_open()) {
    throw std::ios_base::failure("Could not open file: " + pathFile);
  }

  // instantiate Life and a GameBoard with matching dimensions
  Life life(ifs);
  ifs.close();
  GameBoard board(life.rowCount(), life.colCount());
  board.setDisplayEmptyTileDots(false);
  board.setDisplayCoords(false);
  board.setLogLineCount(10);

  // loop variables
  bool stop = false;
  bool paused = true;
  long int generation = 0;
  vector<string> eachGen;
  //
  

  while (!stop) {

    // draw life state
    int totalLiving = life.draw(&board);
    PrintStatusMessage(&board, generation, totalLiving);

    // get user input
    int timeout = paused ? 0 : 2; // paused means wait for key indefinitely
    char cmd = board.nextCommandKey(timeout);

    switch(cmd) {
      case 'q':
      case 'Q':
        stop = true;
        continue; // do not advance life state when quitting
      break;

      case ' ':
        if ((paused = !paused)) {
          continue; // do not advance life state when _starting_ pause
        }
      break;

      case arrowRightKey:
        paused = true;
      break;

      default:
      break;
    }

    // This line uses your Life assignment operator to assign
    // a new instance of Life created by nextLife()
    life = life.nextLife();
    generation++;
    
    string newString = life.toString();
    
    for(int i = 0; i < eachGen.size(); i++){
      if (newString == eachGen[i]){
        board << "found a cycle in generation " << generation << endl;
        stop = true;
        break;
      }
    }
    eachGen.push_back(newString);
  }
}


// =====> DJH 100/100 Good job!
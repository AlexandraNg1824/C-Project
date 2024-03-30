#include "Utils.h"
#include "GameBoard.h"

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

long long MsSinceEpoch() {
  using namespace std::chrono;
  return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

void LogGameStats(int turnCount, char cmd, const Snake &snake) {
  static ofstream logFile("SnakeLogFile.txt");
  string move = " cont";

  static long long lastTime = MsSinceEpoch();
  long long now = MsSinceEpoch();
  long long deltaT = now - lastTime;
  lastTime = now;

  switch (cmd) {
    case arrowUpKey:
      move = "   up";
      break;
    case arrowDownKey:
      move = " down";
      break;
    case arrowRightKey:
      move = "right";
      break;
    case arrowLeftKey:
      move = " left";
      break;
    case 'q':
    case 'Q':
      move = "quit";
      break;
    default:
      move = " cont";
      break;
}
  // mse-evil need to log more shit.
  logFile << turnCount << " cmd:" << move <<  " len: " << snake.length() << " - d(r,c,t): " << snake.dRow() << " ," << snake.dCol() << " ," << deltaT << endl;
}


// return snake length concatenated with some status message 
string Message(string status, const Snake &snake) {
  return "Length: " + to_string(snake.length()) + ". " + status;
}

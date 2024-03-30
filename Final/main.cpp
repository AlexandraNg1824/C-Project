#include <iostream>
using namespace std;


void RunQuestion1();
void RunQuestion2();
void RunQuestion3();
void RunQuestion4();
void RunQuestion5();
void RunQuestion6();

/***
DO NOT WRITE OR CHANGE ANY CODE IN THIS FILE.
CHANGE ONLY THE VALUE OF CURRENT_QUESTION TO THE NUMBER OF THE QUESTION YOU'RE WORKING ON
***/

const int CURRENT_QUESTION = 3;

int main() {
  cout << "running question " << CURRENT_QUESTION << endl;
  switch (CURRENT_QUESTION) {
    case 1:
      RunQuestion1();
      break;
    case 2:
      RunQuestion2();
      break;
    case 3:
      RunQuestion3();
      break;
    case 4:
      RunQuestion4();
      break;
    case 5:
      RunQuestion5();
      break;
    case 6:
      RunQuestion6();
      break;
    default:
      cout << "*** In main.cpp you must set CURRENT_QUESTION to an int from 1-6. ***\n" << endl;
      break;
  }
}

// DJH, provisionally:
// 90 95 85 85 100 100 = 92.5
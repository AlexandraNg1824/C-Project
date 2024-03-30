#include <iostream>
using namespace std;

const int TREE_ROW_COUNT = 6;
const int TREE_COL_COUNT = 9;

const int TreeCounts[TREE_ROW_COUNT][TREE_COL_COUNT] = {
    {1, 0, 2, 3, 1, 2, 5, 1, 0},
    {0, 4, 1, 1, 1, 0, 0, 2, 3},
    {2, 0, 5, 0, 0, 2, 0, 1, 0},
    {0, 5, 5, 0, 2, 0, 1, 0, 0},
    {2, 2, 0, 0, 0, 1, 1, 0, 3},
    {4, 0, 0, 2, 0, 2, 1, 3, 0},
};

int TreeCountAt(int row, int col) {
  bool isCoordValid =
      row >= 0 && row < TREE_ROW_COUNT && col >= 0 && col < TREE_COL_COUNT;
  return isCoordValid ? TreeCounts[row][col] : 0;
}

double FireRiskAt(int row, int col) {
  /*** PROVIDE THIS FUNCTION'S BODY ***/
  /*** Be sure to read the instructions regarding integer vs floating point math ***/
  double result = 0.0;
  for (int r = row - 1; r <= row + 1; r++){
    for (int c = col - 1; c <= col + 1; c++){
      result = result + TreeCountAt(r, c);
    }
  }
  result = (result - TreeCounts[row][col]) / 2 + TreeCounts[row][col];
  return result; // STUB, REPLACE THIS LINE
}

void Riskiest() {
  /*** PROVIDE THIS FUNCTION'S BODY ***/
  double max = -1.0;
  int maxR = -1;
  int maxC = -1;
  for (int r = 0; r < TREE_ROW_COUNT; r++){
    for (int c = 0; c < TREE_COL_COUNT; c++){
      if (max <= FireRiskAt(r, c)){
        max = FireRiskAt(r, c);
        maxR = r;
        maxC = c;
      }
    }
  }
  cout << "The highest fire risk is at: row: " << maxR << " col: " << maxC << endl;
}

void BuildSite(int minTrees, float maxFireRisk) {
  /*** PROVIDE THIS FUNCTION'S BODY ***/
  for(int r = 0; r < TREE_ROW_COUNT; r++){
    for(int c = 0; c < TREE_COL_COUNT; c++){
      if (TreeCountAt(r, c) >= minTrees && FireRiskAt(r, c) <= maxFireRisk)
        cout << "BuildSite at row "<< r << " col: " << c << endl;
    }
  }
}

void RunQuestion1() {
  cout << "FireRiskAt(0, 0) = " << FireRiskAt(0, 0) << endl;
  cout << "FireRiskAt(1, 1) = " << FireRiskAt(1, 1) << endl;
  cout << "FireRiskAt(5, 6) = " << FireRiskAt(5, 6) << endl;

  /*** UNCOMMENT THE CODE BELOW TO CHECK YOUR WORK ***/
  for (int r = 0; r < TREE_ROW_COUNT; ++r) {
    for (int c = 0; c < TREE_COL_COUNT; ++c) {
    cout << "FireRiskAt at " << r << "," << c << " = " << FireRiskAt(r, c) << endl;;
    }
  }

    Riskiest();

    BuildSite(2, 2);
}

// What is the location of the highest fire risk? What is the risk?
// The highest fire risk is at row 3, col 1, the risk is 13

// What is the loation of the build site?
// the location to build site is at row 5, col 3.
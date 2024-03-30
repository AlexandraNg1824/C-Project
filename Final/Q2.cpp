#include <iostream>
using namespace std;

const int PARCEL_ROW_COUNT = 7;
const int PARCEL_COL_COUNT = 9;

const int HouseCounts[PARCEL_ROW_COUNT][PARCEL_COL_COUNT] = {
    {2, 0, 0, 4, 0, 3, 0, 0, 0},
    {0, 0, 3, 0, 0, 0, 2, 0, 0},
    {0, 1, 0, 0, 2, 0, 0, 0, 5},
    {1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 0},
    {0, 2, 0, 2, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 0, 0, 0, 2, 0},
};


//additional function for safety check
int HouseCountAt (int row, int col){
  bool isCoordValid =
      row >= 0 && row < PARCEL_ROW_COUNT && col >= 0 && col < PARCEL_COL_COUNT;
  return isCoordValid ? HouseCounts[row][col] : 0;
}
int HouseCountAround(int row, int col) {
  // PROVIDE THIS FUNCTION'S BODY
  int result = 0;
  for(int r = row - 2; r <= row + 2; r++){
    for(int c = col - 2; c <= col + 2; c++){
      result = result + HouseCountAt(r, c);
    }
  }
  return result;
}

void PrintMostPopulous() {
  // PROVIDE THIS FUNCTION'S BODY
  int mostPopulous = 0;
  int mostR = 0;
  int mostC = 0;
  for (int r = 0; r < PARCEL_ROW_COUNT; r++){
    for (int c = 0; c < PARCEL_COL_COUNT; c++){
      if(mostPopulous <= HouseCountAround(r, c)){
        mostPopulous = HouseCountAround(r, c);
        mostR = r;
        mostC = c;
      }
    }
  }
  cout << "The highest house count location is in row: " << mostR << " col: " << mostC 
    << " which has " << mostPopulous << " houses." << endl;
}

void PrintBuildSites(int maxHouseCount) {
  // PROVIDE THIS FUNCTION'S BODY
  for(int r = 0; r < PARCEL_ROW_COUNT; r++){
    for(int c = 0; c < PARCEL_COL_COUNT; c++){
      if(HouseCountAt(r, c) == 0 && HouseCountAround(r, c) <= maxHouseCount){
        cout << "This is a suitable location in row: " << r << " col: " <<  c << endl;
      }
    }
  }
  // DJH: -5 Should produce output here if no suitable location is found
}

void RunQuestion2() {

  // Disregard the next line. It is included to suppress a compiler warning.
  (void)HouseCounts; 

  cout << "HouseCountAround(3, 4) = " << HouseCountAround(3, 4) << endl;
  cout << "HouseCountAround(5, 8) = " << HouseCountAround(5, 8) << endl;
  cout << "HouseCountAround(0, 0) = " << HouseCountAround(0, 0) << endl;

  PrintMostPopulous();

  PrintBuildSites(4);
}

// DJH: 95
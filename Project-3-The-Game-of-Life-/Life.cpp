#include "Life.h"
#include "GameBoard.h"
#include "fstream"
#include <sstream>
// Construct from a file stream. The file stream must point to an open figure
// file. That format has the rowCount and colCount on the first line, and the
// initial state of cells on the remaining lines (by convention, 'O' represents
// living cells, and dots represent dead cells.
Life::Life(ifstream &ifs){ 
  ifs >> _rowCount >> _colCount >> ws;
  //default to false with {};
  // =====> DJH -0% Should use cellCount()
  _cells = new bool [_rowCount* _colCount]{};
  string line; //row num = num of line
  int row = 0;
  while (getline(ifs, line)){
    for(int col = 0; col < _colCount; col++){
      if (line[col] == 'O'){
        setCellValueAt(row, col, true);
      }
    }
    row++;
  }
}
// Copy constructor. Construct using the state of the passed game of life
// its rowCount, colCount and a deep copy if its cells.
Life::Life(const Life &rhs){
  deepInit(rhs);
}  
// Construct with row and column counts and all dead (==false) cells
Life::Life(int rowCount, int colCount){
  _rowCount = rowCount;
  _colCount = colCount;
  // for(int row = 0; row < _rowCount; row++){
  //   for(int col = 0; col < _colCount; col++){
  //     _cells[row*colCount + col] = false;
  // =====> DJH -0% Should use cellCount()
  _cells = new bool[_rowCount* _colCount]{}; 
}
//dont repeat yourself?!
Life &Life:: operator=(const Life &rhs){
  if (this == &rhs) return *this;
  deepInit(rhs);
  return *this;
}

void Life:: deepInit(const Life &rhs){
  _rowCount = rhs._rowCount;
  _colCount = rhs._colCount;

  delete []_cells;
  _cells = new bool [_rowCount * _colCount];

  // =====> DJH -0% Should use cellCount()
  for(int count = 0; count < _rowCount * _colCount; count++){
    _cells[count] = rhs._cells[count];
  }
}

Life::~Life(){
  delete []_cells;
}

// Return the value of the cell at the specified position
//checks the row, col for being in bounds?!
bool Life:: safeCellValueAt(int row, int col) const{
  bool result = false;
  if (row >= 0 && row < _rowCount && col >= 0 && col < _colCount){
    result = cellValueAt(row, col);
  } 
  return result;
}

bool Life:: cellValueAt(int row, int col) const{
  return  _cells[row * _colCount + col];
}

// Set the value of the cell at the specified position
void Life::setCellValueAt(int row, int col, bool value){
  _cells[row * _colCount + col] = value;
}

// Draw the current state on the given GameBoard, and return
// the total number of living cells
int Life:: draw(GameBoard *board) const{
  int total = 0;
  for(int row = 0; row < _rowCount; row++){
    for(int col = 0; col < _colCount; col++){
      if (cellValueAt(row, col)) {
        //gameboard setTileAt function      
        board->setTileAt(row, col, 'O', red);
        total += 1;
      }
      else {
        board->clearTileAt(row, col);
      }
    }
  }
  return total;
}
// Return a new Life object representing the receiver's state updated according
// to the rules of Conway's Game of Life. In a nutshell:
//
// Non-living cells with exactly 3 live neighbors come to life in the next generation
// Living cells with 2 or 3 live neighbors remain living in the next generation
// Living cells with fewer than 2 live neighbors die of loneliness in the next generation
// Living cells with 4 or more live neighbors die of overcrowding in the next generation
Life Life:: nextLife() const{
  // ====> DJH: these comments are an excellent way to plan!  I commented on your comments below...
  // (terminology point: the reciever is the object upon which this method is invoked. It declares and returns a different Life
  // instance, which you could call the result. Remember: once upon a time...the end)
  //1.make a copy?  (DJH: we don't really want a copy. rather, we want a new instance with the same dimensions as the receiver)
  //solution: call the constructor 
  //2.assign new value to the new copy? (DJH: Yes according to the state of the receiver and the rules)
  //3.delete the old one? (DJH: Not really. The main() hangs on to one life. The delete happens because the main invokes assignment operator)
  //4.return the new one? (DJH: Yes)
  //true = false with 3 neighbors
  //true = true with 2 || 3 neighbors
  Life result(_rowCount, _colCount);
  for(int r = 0; r < _rowCount; r++){
    for(int c = 0; c < _colCount; c++){
      int count = livingNeighbors(r, c);
      bool rule1 = (count == 2 || count == 3) && cellValueAt(r, c);
      bool rule2 = count == 3 && !cellValueAt(r, c);
      if (rule1 || rule2) result.setCellValueAt(r, c, true);
    }
  }
  return result;
}

int Life:: livingNeighbors(int row, int col) const{
  int result = 0;
  for(int r = row - 1; r <= row + 1; r++){
    for(int c = col - 1; c <= col + 1; c++){
      if(safeCellValueAt(r, c)){
        result += 1;
      }
    }
  }
  if(cellValueAt(row, col)) result -= 1;
  return result;
}
// Honors section - Decide how specifically to encode the complete state of
// the receiver and return that encoding as a string
//
// Non-honors - try it for fun, or just return "";
string Life::toString() const{
  ostringstream oss;
  for(int i = 0; i < cellCount(); i++){
    if(_cells[i]){
      oss << i << ",";
    }
  }
  //cout << oss.str() << endl;
  return oss.str();
}
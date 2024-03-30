#include <iostream>
#include <string>

using namespace std;

static const int kWidthAndHeight = 5;

class Matrix5x5 {
public:

  double valueAt(int row, int col);
  void setValueAt(int row, int col, double value);

  void print();

private:
  /*** PROVIDE THIS OBJECT'S DATA MEMBER ***/
  /*** IMPLEMENT WITH A 1D ARRAY ***/
  /*** THIS MATRIX IS FIXED SIZE. IT IS ALWAYS 5x5 ***/
  //from lab 6.6 Object Managing Resources Part 1 - Wrapping a 2D Array
  int _rowCount = 5;
  int _colCount = 5;
  double *_element = new double [_rowCount * _colCount]{};
//office hours demonstrated by mike
//double _values[kWidthAndHeight] = {};

};


double Matrix5x5::valueAt(int row, int col) {
  /*** PROVIDE THIS METHOD'S BODY, THEN REMOVE THE STUBBED CODE ***/
  return _element[row* _colCount + col]; // REMOVE THIS LINE
  //return (row == col)? _values[row] : 0;
}

void Matrix5x5::setValueAt(int row, int col, double value) {
    /*** PROVIDE THIS METHOD'S BODY ***/
  _element[row * _colCount + col] = value;
  //if(row == col){
  //  _values[row] = value;
  //}
}

void Matrix5x5::print() {
    /*** PROVIDE THIS METHOD'S BODY ***/
  for(int r = 0; r < _rowCount; r++){
    for(int c = 0; c < _colCount; c++){
      cout << valueAt(r, c) << " ";
    }
    cout << endl;
  }
  
  //for(int r = 0; r < kWidthAndHeight; ++r){
  //  for(int c = 0; c < kWidthAndHeight; c++){
  //     cout << setw(2) << valueAt(r,c) << " "; 
  //}
  //cout << endl;
  //}
}


void RunQuestion3() {
  Matrix5x5 m;

  cout << "Empty Matrix\n";
  m.print();
  cout << "-----\n";

  m.setValueAt(0, 0, 1.0);
  m.setValueAt(1, 1, 1.1);
  m.setValueAt(2, 2, 1.2);
  m.setValueAt(3, 3, 1.3);
  m.setValueAt(4, 4, 1.4);

  cout << "Diagonals Set\n";
  m.print();
  cout << "-----\n";

  cout << "Another Value Set\n";
  m.setValueAt(3, 1, 99.0);
  m.print();
}
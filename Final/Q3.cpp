#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class LowerTriangleMatrix {
public:
LowerTriangleMatrix(int order);
LowerTriangleMatrix(const LowerTriangleMatrix& other);
~LowerTriangleMatrix();

LowerTriangleMatrix &operator=(const LowerTriangleMatrix& rhs);

int order() const { return _order; }
const double *bottomRowValues() const { return _bottomRowValues; }

double valueAt(int row, int col);
void setValueAt(int row, int col, double value);

void print();

private:
  int _order = 5;
  double *_bottomRowValues = new double [_order]{};
};

LowerTriangleMatrix::LowerTriangleMatrix(int order) {
  // PROVIDE THIS METHOD'S BODY
  // DJH: -10 This should allocate _bottomRowValues the way
  // copy constructor does
  _bottomRowValues[_order] = {};
}

//code from practice exam question 2 
LowerTriangleMatrix::LowerTriangleMatrix(const LowerTriangleMatrix& other) {
  // PROVIDE THIS METHOD'S BODY
  _order = other._order;
  _bottomRowValues = new double [_order];

  for(int count = 0; count < _order; count++){
    _bottomRowValues[count] = other._bottomRowValues[count];
  }
}

LowerTriangleMatrix::~LowerTriangleMatrix() {
  // PROVIDE THIS METHOD'S BODY
  delete []_bottomRowValues;
}

LowerTriangleMatrix &LowerTriangleMatrix::operator=(const LowerTriangleMatrix& rhs) {
  if (this == &rhs) return *this;
  // COMPLETE THIS METHOD'S BODY
  _order = rhs._order;
  
  delete []_bottomRowValues;
  _bottomRowValues = new double [_order];
  
  for(int count = 0; count < _order; count++){
    _bottomRowValues[count] = rhs._bottomRowValues[count];
  }
  return *this;
}

double LowerTriangleMatrix::valueAt(int row, int col) {
  // PROVIDE THIS METHOD'S BODY
  return (row >= col)? _bottomRowValues[col] : 0;
}

void LowerTriangleMatrix::setValueAt(int row, int col, double value) {
  // PROVIDE THIS METHOD'S BODY
  // DJH -5 This tests for _on_ the diagnonal, not lower diagonal. Test used in valueAt is correct.
  if(row >= col){ //change after reading the comment
   _bottomRowValues[col] = value;
  }
}

////code from practice exam question 2 
void LowerTriangleMatrix::print() {
  // PROVIDE THIS METHOD'S BODY
  for(int r = 0; r < _order; r++){
    for(int c = 0; c < _order; c++){
      cout << setw(3) << valueAt(r, c) << " ";
    }
    cout << endl;
  }
}

void RunQuestion3() {
  LowerTriangleMatrix m(5);

  m.print();
  cout << "-----\n";

  m.setValueAt(0, 0, 2.7);
  m.setValueAt(1, 1, 1.5);
  m.setValueAt(2, 2, 6.7);
  m.setValueAt(3, 3, 8.9);
  m.setValueAt(4, 4, 7.4);
m.print();
  cout << "-----\n";

  m.setValueAt(2, 0, 1.0);
  m.print();
  cout << "-----\n";
}

// DJHL 85
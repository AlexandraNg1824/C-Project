#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab builds on the Array2D from the previous lab.

In this lab we're going to allow for changing the elements of a Array2D object.

This _could_ be done with a method. Something like: someArray2D.setElement(row, col, newValue)

But, we're _not_ going to do it that way. Instead, we're going to add
a non-const version of the 'at' method which returns a reference to an integer.

A reference to an integer is a "left hand side" value (abbreviated lhs) which
means it can appear on the left hand side of an assignment statement. More specifically,
it means it can be assigned to.

This will allow writing code like:

   someArray2D.at(2, 3) = 42; // assigns 42 to the element at row 2, col 3
   
It also means that _all_ versions of assignment will work with the at method, += and -=,
as well the -- and ++ operators.
   
This lab requires two very small modifications to Array2D:

1) Declare a version of the 'at' method which is not _const_ and the return type is an
int reference - i.e. int &.

2) Implement this new version of the 'at' method. Hint - it's implemenation can
be exactly the same as the const version no change is needed. You might want to
think about why this is the case.

Leave the current implementation of the const version of the 'at' method in-place.
It's needed so you can access the elements of a const Array2D.

*/

class Array2D {
  public:
    Array2D(int rowCount, int colCount, int *elements);

    ~Array2D();

    int rowCount() const { return _rowCount; }
    int colCount() const { return _colCount; }

    int at(int row, int col) const;
    int& at(int row, int col);

  private:
    int _rowCount;
    int _colCount;
    int *_elements;
};

Array2D::Array2D(int rowCount, int colCount, int *elements)
{
    _rowCount = rowCount;
    _colCount = colCount;
    _elements = new int[rowCount*colCount];

    for (int i = 0; i < rowCount*colCount; ++i) {
      _elements[i] = elements[i];
    }
}

Array2D::~Array2D()
{
  delete [] _elements;
}

int Array2D::at(int row, int col) const
{
  int index = row*_colCount + col;

  return _elements[index];
}
//-------
int& Array2D::at(int row, int col) 
{
  int index = row*_colCount + col;

  return _elements[index];
}
void PrintArray(const Array2D &array)
{
  for (int r = 0; r < array.rowCount(); ++r) {
    for (int c = 0; c < array.colCount(); ++c) {
      cout << array.at(r, c) << " ";
    }
    cout << endl;
  }
}

int main() {
  const int rowCount = 5;
  const int colCount = 7;

  int elements[rowCount*colCount] = {
    0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4,
  };

  Array2D array(rowCount, colCount, elements);

  PrintArray(array);

  for (int r = 0; r < rowCount; ++r) {
    for (int c = 0; c < colCount; ++c) {
      array.at(r, c) += 5;
    }
  }

  cout << "---\n";

  PrintArray(array);

}
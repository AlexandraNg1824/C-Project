#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab builds on the Array2D from the previous lab.

In this lab we're going to add a copy constructor to the Array2D class.

A copy constructor, is a constructor that takes one argument, a const reference to
an object of the class that's being constructed.

Conceptually, a copy constructor contructs a new object of a class from an existing
object of that class

C++ will define a default copy constructor for you. It will simply assign all the
data members using the values of the data members of the object being copied.

In some cases, copying the data members, is all that's all that's needed, but, sometimes
more is needed.

To demonstrate why Array2D needs to do more, try running the lab before adding any
code.

If you look at main you'll see it does the following:
   1) Declares and initializes array1
   2) Declares and initializes array2 from array1 - i.e. array2 should be identical.
   3) It loops over array1 and adds 5 to every element.
   4) It prints out array1 and array2

Consider these question before and after running the code:

- What do you expect the output to be?

- Should both arrays be the same?

- Should the fact that we modifed array1 affect array2?


In this lab it's your job to implement a copy constructor for Array2D.
The array being constructed will use the _rowCount & _colCount from the
Array2D being copied.

**Big Hint** It will need it's own _elements. If you simply assign _elements
from the _elements of the Array2D being copied both Array2Ds will share the
same underlying elements and bad things will happen. E.g. a change to an element
in one Array2D will affect the other.

Once it has its own _elements you can loop over them and initialize them from
the Array2D being copied.

*/

class Array2D {
  public:
    Array2D(int rowCount, int colCount, int *elements);

    ~Array2D();

    int rowCount() const { return _rowCount; }
    int colCount() const { return _colCount; }

    int &at(int row, int col);
    int at(int row, int col) const;
    Array2D(const Array2D &other);   
   
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

Array2D::Array2D(const Array2D &other) {
  _rowCount = other._rowCount;                      // copy the non-pointers
  _colCount = other._colCount;              // copy the non-pointers

  _elements = new int[_rowCount * _colCount]{};            // get a pointer to newly allocated _array

  for (int i=0; i<_rowCount * _colCount; i++) {             // copy other's data 
    _elements[i] = other._elements[i];
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

int &Array2D::at(int row, int col)
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

  Array2D array1(rowCount, colCount, elements);
  Array2D array2(array1);

  for (int r = 0; r < rowCount; ++r) {
    for (int c = 0; c < colCount; ++c) {
      array1.at(r, c) += 5;
    }
  }

  PrintArray(array1);
  cout << "---\n";
  PrintArray(array2);

}
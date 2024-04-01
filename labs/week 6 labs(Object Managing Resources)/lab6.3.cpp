#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab builds on the Array2D from the previous lab.

In this lab we're going to override the assignment operator of the Array2D class.

An assignment operator takes one argument, a const reference to the object on
the right hand side of the assignment. You only need to handle the case of
the right hand side being another Array2D. The return value should be a reference
to an Array2D - specifically, you will return *this.

Conceptually, the assignment operator re-initializes an object using data from an existing
object.

C++ will define a default assignment operator for you. It will simply assign all the
data members using the values of the data members of the object being copied.

In some cases, copying the data members, is all that's that's needed. But, sometimes
more is needed.

To demonstrate why Array2D needs to do more, try running the lab before adding any
code.

If you look at main you'll see it does the following:
   1) Declares and initializes array1
   2) Declares and initializes array2 to be empty.
   2) Uses assignment to set array2 to array1 - i.e. array2 should be identical to array1.
   3) It loops over array1 and adds 5 to every element.
   4) It prints out array1 and array2

Consider these question before and after running the code:

- What do you expect the output to be?

- Should both arrays be the same?

- Should the fact that we modifed array1 affect array2?


In this lab it's your job to implement a assignment operator for Array2D.
The array being assigned to will use the _rowCount & _colCount from the
Array2D on the right hands side (rhs) of the assignment.

**Big Hint** it will need it's own _elements. If you simply assign _elements
from one Array2D to the other, both Array2Ds will share the same underlying
elements and bad things will happen. E.g. a change to an element in one Array2D
will affect _both_ Array2Ds.

Once it has its own _elements you can loop over them and initialize them from
the Array2D being copied.

Remember: if the array being assigned to already has elements, remember to delete them
before creating new elements for it - otherwise you will leak the old elements.

*/

class Array2D {
  public:
    Array2D(int rowCount, int colCount, int *elements);
    Array2D(const Array2D &array);
    Array2D &operator=(const Array2D &rhs);

    ~Array2D();

    int rowCount() const { return _rowCount; }
    int colCount() const { return _colCount; }

    int &at(int row, int col);
    int at(int row, int col) const;

  private:
    int _rowCount;
    int _colCount;
    int *_elements;

  void initFromArray(const Array2D &array);

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
Array2D& Array2D:: operator=(const Array2D &rhs) {
    // don't assign to self
    if (this == &rhs) return *this;        

    _rowCount = rhs._rowCount;                       // copy the non-pointers
    _colCount = rhs._colCount;               // copy the non-pointers

    delete [] _elements;                        // delete my _array
    _elements = new int[_rowCount* _colCount]{};           // get a pointer to newly allocated _array

    for (int i=0; i<_rowCount * _colCount; i++) {            // copy other's data
      _elements[i] = rhs._elements[i];
    }
    return *this;
}


Array2D::Array2D(const Array2D &array)
{
  _rowCount = array._rowCount;
  _colCount = array._colCount;
  _elements = new int[_rowCount*_colCount];

  for (int i = 0; i < _rowCount*_colCount; ++i) {
    _elements[i] = array._elements[i];
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
  Array2D array2(0, 0, nullptr);

  array2 = array1;

  for (int r = 0; r < rowCount; ++r) {
    for (int c = 0; c < colCount; ++c) {
      array1.at(r, c) += 5;
    }
  }

  PrintArray(array1);
  cout << "---\n";
  PrintArray(array2);

}
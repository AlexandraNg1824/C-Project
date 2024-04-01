#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab builds on the idea from the previous lab to make a 2D array class.

Privately, the Array2D class uses a 1D array to hold its elements.

Publicly, the Array2D class provides the method, at, to get the element at a row and col.

You will note that Array2D objects are much more convenient than having to pass functions three
arguments; a 1D array, its rowCount, and its colCount as was done in the previous lab.

However, Array2D still has one BIG limitation. It only holds integers.
What if we want to vary the type of element?
One way to do this is using C++ templates, a feature you'll learn about later in the class.
We will _not_ attempt to address this limitation in this lab.

Also, note that Array2D doesn't follow the "Rule of 3."
A "proper" implementation of Array2D would need to implement a copy constructor and assignment operator.
You do not need to do this in this lab.

*/

class Array2D {
  public:
    Array2D(int rowCount, int colCount, int *elements);
    ~Array2D();

    int rowCount() const { return _rowCount; }
    int colCount() const { return _colCount; }

    int at(int row, int col) const;

  private:
    int _rowCount;
    int _colCount;
    int *_elements;
};

Array2D::Array2D(int rowCount, int colCount, int *elements)
{
   /*
      This constructor should initialize all three data members.
      Use a loop to copy the values from the elements parameter over to its 1D array, _elements.
   */
   _elements = new int [rowCount * colCount];
   _rowCount = rowCount;
   _colCount = colCount;
   for (int count = 0; count < rowCount*colCount; count++)
      _elements[count] = elements[count];
}


Array2D::~Array2D()
{
  delete [] _elements;
}

int Array2D::at(int row, int col) const
{
   /* This is very similar to the ElementAt function you wrote in the previous lab.
   */
   return _elements[row * _colCount + col];
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
}
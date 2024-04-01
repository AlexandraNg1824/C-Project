#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab builds on the Array2D from the previous lab.

Currently, Array2D can only hold ints.

In this lab you will turn Array2D into a template so that it can represent other data types.

In addition, you will turn the function, PrintArray2D, into a templatized function so it can
print Array2Ds representing other data types.

You will need to do the following:

- Add the template declaration (i.e. template<typename T> ) before the class definition.

- Add the template declaration (i.e. template<typename T> ) before each method defined
outside of the class definition.

- Add the template declaration (i.e. template<typename T> ) before PrintArray2D.

- Go through and replace uses of Array2D with Array2D<T>.
   - Uses of the scope operator (i.e. Array2D:: becomes Array2D<T>::)
   - Uses of Array2D as a parameter type or return type (i.e. Array2D becomes Array2D<T>)
   
- Go through the code and replace uses of int with T - the type specified by the template.
Note: You cannot blindly replace all uses of int with T - only the ones related to the type
of data contained in the array. For example, the parameters to 'at', row and col should still
remain as int, whereas the return type of 'at' should be changed from int to T since the array
now contains elements of type T.

*/
template<typename T>
class Array2D {
  public:
    Array2D(int rowCount, int colCount, T *elements);
    Array2D(const Array2D &array);

    ~Array2D();

    Array2D &operator=(const Array2D &rhs);  

    int rowCount() const { return _rowCount; }
    int colCount() const { return _colCount; }

    T &at(int row, int col);
    T at(int row, int col) const;

  private:
    int _rowCount;
    int _colCount;
    T*_elements;

};
template<typename T>
Array2D<T>::Array2D(int rowCount, int colCount, T *elements)
{
    _rowCount = rowCount;
    _colCount = colCount;
    _elements = new T[rowCount*colCount];

    for (int i = 0; i < rowCount*colCount; ++i) {
      _elements[i] = elements[i];
    }
}
template<typename T>
Array2D<T>::Array2D(const Array2D &array)
{
  _rowCount = array._rowCount;
  _colCount = array._colCount;
  _elements = new T[_rowCount*_colCount];

  for (int i = 0; i < _rowCount*_colCount; ++i) {
    _elements[i] = array._elements[i];
  }
}
template<typename T>
Array2D<T>::~Array2D()
{
  delete [] _elements;
}
template<typename T>
Array2D<T> &Array2D<T>::operator=(const Array2D &rhs)
{
   if (this != &rhs) {
      _rowCount = rhs._rowCount;
      _colCount = rhs._colCount;
    
      delete [] _elements;
      _elements = new T[_rowCount*_colCount];

      for (int i = 0; i < _rowCount*_colCount; ++i) {
         _elements[i] = rhs._elements[i];
      }
   }

  return *this;
}

template<typename T>
T Array2D<T>::at(int row, int col) const
{
  int index = row*_colCount + col;

  return _elements[index];
}
template<typename T>
T &Array2D<T>::at(int row, int col)
{
  int index = row*_colCount + col;

  return _elements[index];
}
template<typename T>
void PrintArray(const Array2D<T> &array)
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

  int intElements[rowCount*colCount] = {
    0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4,
  };

  Array2D<int> array1(rowCount, colCount, intElements);
  Array2D<int> array2(0, 0, nullptr);

  array2 = array1;

  for (int r = 0; r < rowCount; ++r) {
    for (int c = 0; c < colCount; ++c) {
      array1.at(r, c) += 5;
    }
  }

  PrintArray(array1);
  cout << "---\n";
  PrintArray(array2);

  cout << "\n---\n\n";


  char charElements[rowCount*colCount] = {
    'a', 'a', 'a', 'a', 'a', 'a', 'a',
    'b', 'b', 'b', 'b', 'b', 'b', 'b',
    'c', 'c', 'c', 'c', 'c', 'c', 'c',
    'd', 'd', 'd', 'd', 'd', 'd', 'd',
    'e', 'e', 'e', 'e', 'e', 'e', 'e',
  };

  Array2D<char> array3(rowCount, colCount, charElements);
  Array2D<char> array4(0, 0, nullptr);

  array4 = array3;

  for (int r = 0; r < rowCount; ++r) {
    for (int c = 0; c < colCount; ++c) {
      array3.at(r, c) += 'A' - 'a';
    }
  }

  PrintArray(array3);
  cout << "---\n";
  PrintArray(array4);

}

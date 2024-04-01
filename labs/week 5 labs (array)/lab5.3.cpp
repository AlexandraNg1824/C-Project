#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

In the previous two labs we passed 2D arrays to functions, but the dimensions of the
array, rowCount and colCount, were global variables.

This is not a great way to do things for a variety of reasons. For example, the functions
only work for 2D arrays of a single size. It would be preferable to be able to write
functions that handle any size 2D array. I.e. pass the function the 2D array
along with its rowCount and colCount.

Unfortunately, C++ requires us to specifiy the dimensions of the 2D array as constants. Actually, it
allows us to leave out rowCount, but it won't allow us to leave out colCount.

One way to work around this is to pass all the elements of the 2D array as one big, 1D array.

E.g. if the array is 3x3 it has 9 elements: 1 2 3 4 5 6 7 8 9.

We can imagine the array as being a 2D array:

1 2 3
4 5 6
7 8 9

It's still just 9 elements, we're just organizing them into rows and cols in our mind.

The element at row 0, col 0 is 1.
The element at row 1, col 1 is 5.
The element at row 1, col 2 is 6.
The element at row 2, col 2 is 9.

This means you have to compute index in the 1D array for the element at a given row and col.

The element at row 0, col 0 is at index 0.
The element at row 1, col 1 is at index 4.
The element at row 1, col 2 is at index 5.
The element at row 2, col 2 is at index 8.


In this lab, you need to figure out how to compute the 1D index for a row and col of
the corresponding 2D Array.

*/


int ElementAt(int array[], int rowCount, int colCount, int r, int c)
{
   /*
      This function returns the element at r,c when you treat array as being a 2D array
      with the specified rowCount and colCount.
   */
   return array[r *colCount + c ];
}

void PrintArray(int array[], int rowCount, int colCount)
{
  for (int r = 0; r < rowCount; ++r) {
    for (int c = 0; c < colCount; ++c) {
      cout << ElementAt(array, rowCount, colCount, r, c) << " ";
    }
    cout << endl;
  }
}

int main() {
  const int rowCount = 5;
  const int colCount = 7;

  int array[rowCount*colCount] = {
    0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4,
  };

  PrintArray(array, rowCount, colCount);
}
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

const int rowCount = 5;
const int colCount = 7;


int NeighborhoodSum(int array[rowCount][colCount], int row, int col){
   int value = 0;
   int sum = 0;
   for (int r = row - 1; r <= row + 1; r++){
      for (int c = col - 1; c <= col + 1; c++){
         if (r >= 0 && r < rowCount && c >= 0 && c < colCount ){
            value = array[r][c];
            sum = sum + value;
         }
      }
   }
   return sum;
}

void PrintNeighborhoodSums(int array[rowCount][colCount])
{
   /*
   
   In the previous lab, you wrote code to iterate the 2D array and print out
   the elements of each row.
   
   In this lab, instead of printing the elements of the array, you need to
   print the sum of the element plus all of its neighbors.
   
   E.g. the element at row 2, col 2, has 8 neighbors: 1, 1, 1, 2, 2, 3, 3, 3.
   The sum of the element plus it's neighbors is 2 + 1 + 1 + 1 + 2 + 2 + 3 + 3 + 3 = 18.
   
   Note, elements at the edges do _not_ have 8 neighbors. Your code that loops over an element's
   neighbors should be careful not to go out of the bounds of the 2D array.
   
   Hint: writing a helper function that sums all the elements around a particular row and col
   will simplify your code.
   
   */
   for(int row = 0; row < rowCount; row++){
      for(int col = 0; col < colCount; col++){
         int sum = NeighborhoodSum(array, row, col);
         cout << sum << " ";
      }
      cout << endl;
   }
}

            

int main() {

  int array[rowCount][colCount] = {
    {0, 0, 0, 0, 0, 0, 0,},
    {1, 1, 1, 1, 1, 1, 1,},
    {2, 2, 2, 2, 2, 2, 2,},
    {3, 3, 3, 3, 3, 3, 3,},
    {4, 4, 4, 4, 4, 4, 4,},
  };

  PrintNeighborhoodSums(array);
}
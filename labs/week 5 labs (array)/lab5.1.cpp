#include <iostream>
#include <sstream>
#include <string>

using namespace std;

const int rowCount = 5;
const int colCount = 7;

void PrintArray(int array[rowCount][colCount])
{
   /*
   Write code here to print out each row of the array on its own line.
   Use a space to separate the elements of a row.
   */
   for(int i = 0; i < rowCount; i++){
      for(int j = 0; j < colCount; j++){
         cout << array[i][j] << " ";
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

  PrintArray(array);
}
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

This lab provides you a simple function, Sort2, which takes two integer pointers,
item1 and item2, and sorts them so that *item1 <= *item2.

The big limitation with this function is that it only works with ints.

Suppose we want to sort chars, or floats, or strings?

The solution is to redeclare Sort using templates so that the template parameter determines the
type of value being sorted. This allows Sort2 to work with any type of data.

In this lab you need to:

1) Redeclare Sort2 as a template. This simply means putting this code immediately before
the class declaration.

template<typename T>

2) Now that Sort2 is a template, it means that the template parameter, T, is available for use
as a type in the function definition. This means instead of writing Sort2 using int, you can
instead use T. When your code is compiled the type specified by the template parameter will be
substituted for T.

You need to go through the function definition and replace int with T.


After you do these two things, the code in main() will be able to compile. It will
call Sort2 using different types to demonstrate that we've fixed the original problem
of Sort2 only working with ints.

*/

template <typename T>
void Sort2(T *item1, T *item2)
{
  if (*item1 > *item2) {
    T temp = *item1;
    *item1 = *item2;
    *item2 = temp;
  }
}

int main() {
 {
  int i1 = 23;
  int i2 = 3;
  cout << i1 << "," << i2 << endl;
  Sort2(&i1, &i2);
  cout << i1 << "," << i2 << endl;
 }

 {
  char i1 = 'z';
  char i2 = 'b';
  cout << i1 << "," << i2 << endl;
  Sort2(&i1, &i2);
  cout << i1 << "," << i2 << endl;
 }

 {
  float i1 = 3.14;
  float i2 = 2.7;
  cout << i1 << "," << i2 << endl;
  Sort2(&i1, &i2);
  cout << i1 << "," << i2 << endl;
 }

 {
  string i1 = "moe";
  string i2 = "curly";
  cout << i1 << "," << i2 << endl;
  Sort2(&i1, &i2);
  cout << i1 << "," << i2 << endl;
 }
}


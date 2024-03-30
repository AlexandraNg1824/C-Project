#include <iostream>
#include <string>

using namespace std;

/*****************************************************************************/
/*
This Television class represents simple television. Use it as-is.
*/
class Television {
public:
  Television(string model, double diagonal, double price) {
    _model = model;
    _diagonal = diagonal;
    _price = price;
  }

  string model() const { return _model; }
  double diagonal() const { return _diagonal; }
  double price() const { return _price; }

private:
  string _model = "";
  double _diagonal = 0;
  double _price = 0;
};

/*****************************************************************************/

/** PART A) WRITE AreTVsSortedByPrice() THAT ANSWERS A BOOL INDICATING IF
    THE GIVEN ARRAY OF TELEVISION POINTERS IS SORTED BY PRICE
**/

//from try Sorting and Search
//dont know why it doesnt work with:
//for(int i = 1; i <= count; i++){
// int oneLess = i - 1;
//  if(tvs[oneLess].price() > tvs[i].price())
//}
bool AreTVsSortedByPrice(Television tvs[], int count) {
  bool result = true;
  for(int i = 0; i < count - 1; i++){
    if(tvs[i].price() > tvs[i + 1].price()){
      result = false;
    }
  }
  return result;  // STUB, REMOVE THIS LINE
}

/*****************************************************************************/
/*
FOR YOUR REFERENCE IN PART B. DO NOT MODIFY OR INVOKE THIS FUNCTION
InsertionSortInts() uses insertion sort to sort a given vector of ints.
*/


void InsertionSortInts(int array[], int count) {
  for (int boundary=1; boundary < count; boundary++) {
    int value = array[boundary];
    int index = boundary-1;
    while (index >= 0 && array[index] > value) {
      array[index+1] = array[index];
      index--;
    }
    array[index+1] = value;
  }
}

/*****************************************************************************/

/** PART B) WRITE InsertionSortTVsByPrice() to sort a given vector of TVs by price
**/
void InsertionSortTVsByPrice(Television tvs[], int count) {
  for (int boundary=1; boundary < count; boundary++) {
    Television value = tvs[boundary];
    int index = boundary-1;
    while (index >= 0 && tvs[index].price() > value.price()) {
      tvs[index+1] = tvs[index];
      index--;
    }
    tvs[index+1] = value;
  }
}

/*****************************************************************************/


void RunQuestion7() {

  Television tvs[] = {
    Television("Vizio", 24.0, 75.00),
    Television("Sony", 65.0, 1700.00),
    Television("Vizio", 44.0, 1200.00),
    Television("LG", 37.0, 650.00),
    Television("Thomson", 67.0, 1800.00),
    Television("Samsung", 72.0, 2500.00),
    Television("Panasonic", 33.0, 500.00)
  };


  /** PART C:
    ADD CODE HERE TO TEST WHETHER THE ARRAY IS SORTED
    ADD CODE HERE TO SORT THE ARRAY
    ADD CODE HERE TO TEST AGAIN WHETHER THE ARRAY IS SORTED
  **/
  cout << "Are the TV's sorted? " << AreTVsSortedByPrice(tvs, 7) << endl;
  // cout << "Are the TV's sorted? " << /* call AreTVsSortedByPrice */ << endl;
  // Call InsertionSortTVsByPrice
  InsertionSortTVsByPrice(tvs, 7);

  // cout << "Now are they sorted? " << /* call AreTVsSortedByPrice */ << endl;
  cout << "now: " << AreTVsSortedByPrice(tvs, 7) << endl;


}

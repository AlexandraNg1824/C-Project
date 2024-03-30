#include <iostream>
#include <string>

using namespace std;

//****************************************************************************

// This Creature class is a simplified version of the class we used
// in Project-1. Use it as-is.

class Creature {
public:
  Creature(string name, int row, int col) {
    _name = name;
    _row = row;
    _col = col;
  }
  string name() const { return _name; }
  int row() const { return _row; }
  int col() const { return _col; }

private:
  string _name = "";
  int _row = 0;
  int _col = 0;
};

//****************************************************************************
// PART A) WRITE IndexOfCreaturePtrLinearSearch() LINEAR SEARCH AN ARRAY OF
//         CREATURE POINTERS FOR THE INDEX OF A POINTER TO A CREATURE WITH A GIVEN NAME

int IndexOfCreaturePtrLinearSearch(Creature *ptrs[], int count, string name) {
  int result = -1;
  for(int i = 0; i < count; i++){
    if(ptrs[i]->name() == name){
      result = i;
      break;
    }
  }
  return result;
}

//****************************************************************************
// FOR YOUR REFERENCE IN PART B. DO NOT MODIFY OR INVOKE THIS FUNCTION
// IndexOfIntBinarySearch() uses binary search to find a target int in an array
// of ints. It returns the index where the target can be found or -1
// if the target is not present

int IndexOfIntBinarySearch(int array[], int count, int target) {
  int start = 0;
  int end = count-1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (array[mid] == target) {
      // We put up with an early return here for simplicity
      return mid;
    }
    if (array[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}

//****************************************************************************
// PART B) WRITE IndexOfCreaturePtrBinarySearch() BINARY SEARCH AN ARRAY OF
//         CREATURE POINTERS FOR THE INDEX OF A POINTER TO A CREATURE WITH A GIVEN NAME

int IndexOfCreaturePtrBinarySearch(Creature *ptrs[], int count, string name) {
  int start = 0;
  int end = count-1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (ptrs[mid]->name() == name) {
      // We put up with an early return here for simplicity
      return mid;
    }
    if (ptrs[mid]->name() < name) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1; 
}

//****************************************************************************

void RunQuestion6() {

  Creature *unsorted[] = {
    new Creature("Rachael", 10, 14),
    new Creature("Ziggy", 10, 14),
    new Creature("Jack", 10, 14),
    new Creature("Charlie", 10, 14),
    new Creature("Young", 10, 14),
    new Creature("Abigail", 10, 14),
    new Creature("Oscar", 10, 14),
    new Creature("Mary", 10, 14)
  };
  const int unsortedCount = sizeof(unsorted)/sizeof(*unsorted);

  Creature *sorted[] = {
    new Creature("Abigail", 10, 14),
    new Creature("Charlie", 10, 14),
    new Creature("Jack", 10, 14),
    new Creature("Mary", 10, 14),
    new Creature("Oscar", 10, 14),
    new Creature("Rachael", 10, 14),
    new Creature("Young", 10, 14),
    new Creature("Ziggy", 10, 14)
  };
  const int sortedCount = sizeof(sorted)/sizeof(*sorted);

  // PART C: CODE HERE TO WRITE THE INDEX OF CREATURES WITH THESE NAMES:
  // Oscar, Wilson, Abigail, Ziggy
  // e.g.
  // cout << "Index of Oscar in unsorted array: " << /* call search */ << endl;
  // etc. for Wilson Abigail, and Ziggy
  cout << "Index of Oscar in unsorted array: " << IndexOfCreaturePtrLinearSearch(unsorted, unsortedCount, "Oscar") << endl;
  cout << "Index of Wilson in unsorted array: " << IndexOfCreaturePtrLinearSearch(unsorted, unsortedCount, "Wilson") << endl;
  cout << "Index of Abigail in unsorted array: " << IndexOfCreaturePtrLinearSearch(unsorted, unsortedCount, "Abigail") << endl;
  cout << "Index of Ziggy in unsorted array: " << IndexOfCreaturePtrLinearSearch(unsorted, unsortedCount, "Ziggy") << endl;

  // PART C: CODE HERE TO WRITE THE INDEX OF CREATURES WITH THESE NAMES:
  // Oscar, Wilson, Abigail, Ziggy
  // e.g.
  // cout << "Index of Oscar in sorted array: " << /* call search */ << endl;
  // etc. for Wilson Abigail, and Ziggy
  cout << "\n\n";

  cout << "Index of Oscar in sorted array: " << IndexOfCreaturePtrBinarySearch(sorted, sortedCount, "Oscar") << endl;
  cout << "Index of Wilson in sorted array: " << IndexOfCreaturePtrBinarySearch(sorted, sortedCount, "Wilson") << endl;
  cout << "Index of Abigail in sorted array: " << IndexOfCreaturePtrBinarySearch(sorted, sortedCount, "Abigail") << endl;
  cout << "Index of Ziggy in sorted array: " << IndexOfCreaturePtrBinarySearch(sorted, sortedCount, "Ziggy") << endl;




  // Delete everything before we're through
  for (int i=0; i<unsortedCount; i++) {
    delete unsorted[i];
  }

  for (int i=0; i<sortedCount; i++) {
    delete sorted[i];
  }
}

// DJH: 100/100
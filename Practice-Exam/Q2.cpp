#include <iostream>
#include <sstream>
#include <string>

using namespace std;

struct Student {
  string name = "";
  int studentID = -1;
};

/*** Use this declaration as-is ***/
class StudentVector {
public:
  // Constructor
  StudentVector();

  // Destructor
  ~StudentVector();


  // The copy constructor must initialize the new vector with a
  // deep copy of its StudentVector parameter. Implement in the cpp.
  StudentVector(const StudentVector &other);

  // The assignment operator must initialize the new vector with a 
  // deep copy of its StudentVector parameter.
  StudentVector &operator=(const StudentVector &rhs);

  // push_back 
  void push_back(Student element);

  // at
  Student& at(int index);

  // getters for size and capacity
  int size() const { return _size; }
  int capacity() const { return _capacity; }

  //part c
  //learnt it from office hour 
  Student& front(){
    if(_size == 0){
      cout << "The first element is empty" << endl;
      exit(-1);
    }
    return _array[0];
  }
  Student& back (){
    if(_size == 0){
      cout << "The first element is empty" << endl;
      exit(-1);
    }
    return _array[size() - 1];
  }


private:
  int _size = 0;
  int _capacity = 0;
  Student *_array = nullptr;

  //remember to have the correct name for the class
  void deepInit(const StudentVector &rhs){
    _size = rhs._size;
    _capacity = rhs._capacity;

    delete []_array;
    _array = new Student [_capacity];

    for(int count = 0; count < _size; count++){
      _array[count] = rhs._array[count];
    }
  }
};


static const int kInitialCapacity = 4;

StudentVector::StudentVector() {
  /*** PROVIDE THIS DEFAULT CONSTRUCTOR'S BODY ***/
  //from TryIts AlmostVector
  _size = 0;
  _capacity = kInitialCapacity;
  _array = new Student[_capacity]{};
}

StudentVector::~StudentVector() {
  /*** PROVIDE THIS DESTRUCTOR'S BODY ***/
  //from TryIts AlmostVector
  delete [] _array;
}

StudentVector::StudentVector(const StudentVector &other) {
  /*** PROVIDE THIS COPY CONSTRUCTOR'S BODY ***/
  //from TryIts Try Rule of 3 DIY Vector
  deepInit(other);
}


StudentVector &StudentVector::operator=(const StudentVector &rhs) {
  if (this == &rhs) return *this;
  /*** COMPLETE THIS METHOD'S BODY ***/
  //from TryIts Try Rule of 3 DIY Vector
  deepInit(rhs);
  return *this;
}


void StudentVector::push_back(Student element) {
  if (_size == _capacity) {
    /*** HANDLE BY DOUBLING CAPACITY ***/
    //from TryIts Try Rule of 3 DIY Vector
    _capacity *= 2;
    Student *temp = new Student[_capacity]{};
    for (int i=0; i<_size; i++) {
      temp[i] = _array[i];
    }
    delete [] _array;
    _array = temp;
  }
    _array[_size++] = element;
}
  /*** COMPLETE THIS METHOD'S BODY ***/

Student& StudentVector::at(int index) {
  /*** COMPLETE THIS METHOD'S BODY ***/
  // if index is out of bounds, print a message and exit
  //from TryIts Try Rule of 3 DIY Vector
  if (index < 0 || index >= _size) {
    cout << "Index out of bounds: " << index << " must be less than " << _size << endl;
    exit(-1);
  }
  return _array[index];
}

void RunQuestion2() {
  // Use these declarations
  StudentVector students;
  
  Student s0 = { "Emily", 874 };
  Student s1 = { "Sophia", 456 };
  Student s2 = { "Olivia", 129 };
  Student s3 = { "Ronny", 932 };
  Student s4 = { "Jacob", 501 };
  Student s5 = { "Michael", 783 };

  students.push_back(s0);
  students.push_back(s1);
  students.push_back(s2);
  students.push_back(s3);
  students.push_back(s4);
  students.push_back(s5);

  /*** AFTER COMPLETING PARTS A & B) WRITE A LOOP THAT ITERATES THE VECTOR ***/
  /*** PRINT EACH STUDENT NAME ON ITS OWN LINE ***/
  for(int count = 0; count < students.size(); count++){
    cout << students.at(count).name << endl;
  }

  /*** AFTER COMPLETING PART C) PRINT THE FIRST AND LAST STUDENTS' NAMES ***/
  cout << "The first student is " << students.front().name << endl;
  cout << "The last student is " << students.back().name << endl;
}


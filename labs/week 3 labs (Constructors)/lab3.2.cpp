#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/* 
This lab adds two static data members to Monster to keep track of how many times a Monster
constructor or destructor is called.

The template below has already done this for the destructor. Specifically it:
   - Declared the static data member, _destructorCallCount, to keep track of destructor calls.
   - Defined the static data member, _destructorCallCount, after the class declaration.
   - Defined a public static method, destructorCallCount, to access _destructorCallCount.
   - Defined a private static method, incrementDestructorCallCount, to increment _destructorCallCount.
   - Called incrementDestructorCallCount from the destructor.
   - Added a line at the end of main to print out the number of calls to the destructor.
   
You need to do the same things to keep track of calls to the constructor.
   - Remember there are three constructors!
   - If any one of the three is called, the number of calls to the constructor needs to be increased.

*/

class Monster {
public:
  Monster();
  Monster(string str);
  Monster(string name, char glyph, int calories);
  
  ~Monster();

  string name() const { return _name; };
  int calories() const { return _calories; };
  char glyph() const { return _glyph; };

  void setName(string name) { _name = name; };
  void setCalories(int calories) { _calories = calories; };
  void setGlyph(char glyph) { _glyph = glyph; };

  void print();
 
  static int destructorCallCount() { return _destructorCallCount; }
  static int constructorCallCount() {return _constructorCallCount;}

private:
  string _name = "Godzilla";
  char _glyph = 'g';
  int _calories = 500;
  
  static int _destructorCallCount;
  static int _constructorCallCount;

  static void incrementDestructorCallCount() { ++_destructorCallCount; }
  static void incrementconstructorCallCount(){++_constructorCallCount;}

};

// This is the definition of _destructorCallCount, it's declaration is above.
// The definition is the place where you can initialize it (defaults to zero).
int Monster::_destructorCallCount = 0;
int Monster::_constructorCallCount = 0;

Monster::Monster() {
   Monster::incrementconstructorCallCount();
}

Monster::Monster(string str) {
  stringstream ss(str);
  ss >> this->_name >> this->_glyph >> this->_calories;
  Monster::incrementconstructorCallCount();
}

Monster::Monster(string name, char glyph, int calories) : _name(name), _glyph(glyph), _calories(calories) {
   Monster::incrementconstructorCallCount();
};

Monster::~Monster() {
  Monster::incrementDestructorCallCount();
}

void Monster::print()
{
  cout << "name: " << this->_name << endl;
  cout << "glyph: " << this->_glyph << endl;
  cout << "calories: " << this->_calories << endl;
}


int main() {
  Monster m1("Frankenstein f 125");
  Monster m2("Dracula", 'd', 200);
  Monster m3;
  
  m1.print();
  m2.print();
  m3.print();

  Monster *m4 = new Monster("Vampire v 222");
  Monster *m5 = new Monster("Mothra", 'm', 77);
  Monster *m6 = new Monster;

  m4->print();
  m5->print();
  m6->print();

  delete m4;
  delete m5;
  delete m6;

  // Modify this line to print the number of times the constructor was called.
  cout << "Number of monsters constructed: " << Monster::constructorCallCount() << endl;
  
  cout << "Number of monsters destructed: " << Monster::destructorCallCount() << endl;
}


#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Monster {
public:
  Monster(string str);

  string name() const { return _name; };
  int calories() const { return _calories; };
  char glyph() const { return _glyph; };

  void setName(string name) { _name = name; };
  void setCalories(int calories) { _calories = calories; };
  void setGlyph(char glyph) { _glyph = glyph; };

  void print();
  
private:
  string _name;
  int _calories;
  char _glyph;
};

Monster::Monster(string str)
{
  stringstream ss(str);
  ss >> this->_name >> this->_glyph >> this->_calories;
}

void Monster::print()
{
  cout << "name: " << this->_name << endl;
  cout << "glyph: " << this->_glyph << endl;
  cout << "calories: " << this->_calories << endl;
}


int main() {
  string monsterData1 = "Frankenstein f 125";
  string monsterData2 = "Dracula d 200";

 // This code creates a locally allcoated Monster, just as you've done previous labs.
  Monster m1(monsterData1);
  m1.print();

  // Follow these steps to dynamically allocate another Monster, m2:

  // 1. Declare a Monster pointer, m2 and use new to initialize it.
  
  // 2. Use the print method to print m2.

  // 3. Use delete to free up the storage for m2, now that's it's no longer needed.
  Monster *m2 = new Monster(monsterData2);
  m2 -> print();
  delete m2;
}


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

  void eat(int calories);
  
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

void Monster::eat(int calories) {
  // Implement this method to increase m's calories by the calories passed as the parameter.
  _calories = _calories + calories;
}

void EatPassingValue(Monster m, int calories)
{
  // Implement this function to increase m's calories by the calories passed as the 2nd parameter.
  m.setCalories(m.calories() + calories);
}

void EatPassingPointer(Monster *m, int calories)
{
  // Implement this function to increase m's calories by the calories passed as the 2nd parameter.
  m->setCalories(m->calories() + calories);
}

void EatPassingReference(Monster &m, int calories)
{
  // Implement this function to increase m's calories by the calories passed as the 2nd parameter.
  m.setCalories(m.calories() + calories);
}



int main() {
  string monsterData = "Frankenstein f 125";

  Monster m(monsterData);

  cout << "Starting state of the monster\n";
  m.print();

  m.eat(10);
  cout << "---\nAfter m.eat(10)\n";
  m.print();

  // Does EatPassingValue succesfully increase m's calories?
  // You should make sure you understand what's going on.
  EatPassingValue(m, 100);
  cout << "---\nAfter EatPassingValue(m, 100)\n";
  m.print();
  
  //  Note the use of the address operator (&) to get the address of m to pass as a pointer.
  EatPassingPointer(&m, 100);
  cout << "---\nAfter EatPassingPointer(&m, 100)\n";
  m.print();

  //  Note that this call looks just like EatPassingValue.
  //  It's not obvious that a reference is being passed or that m will be modified.
  //  This is why EatPassingPointer is the preferred idiom when modifying a struct parameter.
  EatPassingReference(m, 100);
  cout << "---\nAfter EatPassingReference(m, 100)\n";
  m.print();

}


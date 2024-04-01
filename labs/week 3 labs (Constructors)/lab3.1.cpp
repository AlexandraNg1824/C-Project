#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
Add a default constructor to the Monster class that takes no parameters.
A Monster initialized using the default constructor should have:
   - name "Godzilla"
   - calories 500
   - glyph 'g'
*/


/*
Add another constructor to the Monster class that takes name, glyph, & calories.
*/

class Monster {
public:
  Monster(string str);
  Monster():_name("Godzilla"), _calories(500), _glyph('g'){}
  Monster(string name,char glyph,int calories): _name(name), _glyph(glyph), _calories(calories){}

  string name() const { return _name; };
  int calories() const { return _calories; };
  char glyph() const { return _glyph; };

  void setName(string name) { _name = name; };
  void setCalories(int calories) { _calories = calories; };
  void setGlyph(char glyph) { _glyph = glyph; };

  void print();
  
private:
  string _name;
  char _glyph;
  int _calories;
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

  Monster m1("Frankenstein f 125");

  m1.print();

  Monster m2("Dracula", 'd', 200);

  m2.print();

  Monster m3;

  m3.print();
}


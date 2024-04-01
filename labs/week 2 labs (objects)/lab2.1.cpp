#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*

1) Define a class, Monster, which is analogous to the Monster struct (below) you defined in
the struct Labs

struct Monster {
  string name;
  int calories;
  char glyph;
};

It should have data members corresponding to the data members in the Monster struct but,
remember to use the guidelines for naming data members in objects, i.e. they should
start with underscores.

2) Declare a constructor that takes a parameter string and uses it to initialize the Monster.
This is very similar to what you did to initialize Monster structs in Struct Labs Part 1 & 2.

3) Declare getter and setter methods for the three data members.
Remember to use the class guidelines for naming getters and setters, i.e. getters should _not_
start with the prefix "get".

4) Declare a method, print, that prints a Monster.
This is very similar to what you did to print Monster structs in Struct Lab Part 2.

*/
class Monster{
   public:
   Monster() = default;
   void print();
   Monster(string str);
   void setName(string name) {
      _name = name;
   }
   void setCalories(int calories) {
      _calories = calories;
   }
   void setGlyph(char glyph) {
      _glyph = glyph;
   }
   
   string name() const {return _name;}
   int calories() const {return _calories;}
   char glyph() const {return _glyph;}
   
   private:
   string _name;
   int _calories;
   char _glyph;
   
};


Monster::Monster(string str)
{
 // Implement this method to initialize the monster (this) from str.
   stringstream ss(str);
   ss >> _name >> _glyph >> _calories;
}

void Monster::print()
{
 // Implement this method to print the monster's name, glyph and calories.
 // Label each data member with the member name and a colon.
 cout << "Name: " << _name << "glyph: " << _glyph << "calories: " << _calories;
}


int main() {
  string monsterData1 = "Frankenstein f 125";
  string monsterData2 = "Dracula d 200";

  Monster m1(monsterData1);

  m1.print();

  Monster m2(monsterData2);

  m2.print();
}


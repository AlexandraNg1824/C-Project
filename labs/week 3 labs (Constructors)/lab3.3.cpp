#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*

This program calls the function, Test(), which creates a MonsterList and removes the most
caloric Monster. When Test returns, all the monsters it created should have been deleted.

The program prints how many monster were leaked. Your goal is to reduce the number to zero.

*/

class Monster {
public:
  Monster();
  Monster(string str);
  ~Monster();

  string name() const { return _name; };
  int calories() const { return _calories; };
  char glyph() const { return _glyph; };

  void setName(string name) { _name = name; };
  void setCalories(int calories) { _calories = calories; };
  void setGlyph(char glyph) { _glyph = glyph; };

  void print();

  static int constructorCallCount() { return _constructorCallCount; }
  static int destructorCallCount() { return _destructorCallCount; }

private:
  string _name;
  int _calories;
  char _glyph;

  static int _constructorCallCount;
  static int _destructorCallCount;

  static void incrementConstructorCallCount() { ++_constructorCallCount; }
  static void incrementDestructorCallCount() { ++_destructorCallCount; }
};

int Monster::_constructorCallCount = 0;
int Monster::_destructorCallCount = 0;

Monster::Monster() {
  Monster::incrementConstructorCallCount();
}

Monster::Monster(string str)
{
  stringstream ss(str);
  ss >> this->_name >> this->_glyph >> this->_calories;
  Monster::incrementConstructorCallCount();
}

Monster::~Monster()
{
  Monster::incrementDestructorCallCount();
}

void Monster::print()
{
  cout << "name: " << this->_name << endl;
  cout << "glyph: " << this->_glyph << endl;
  cout << "calories: " << this->_calories << endl;
}

class MonsterList {
public:
  MonsterList(string filename);
  ~MonsterList();
  // Notice that MonsterList does _not_ declare a destructor.
  // The destructor would be an obvious place to delete Monsters.

  int count();

  void print();

  int indexOfMostCaloricMonster();
  void removeMostCaloricMonster();

private:
  vector<Monster *> _monsters;
  

};
MonsterList::~MonsterList() {
  // Destructor definition
  for (Monster* monster : _monsters) {
    delete monster;
  }
}
MonsterList::MonsterList(string filename) {
  ifstream file("MonsterData.txt");

  if (!file.is_open()) {
    cout << "Failed to open file\n" ;
    exit(0);
  }

  string line;
  while(getline(file, line)) {
    // Skip empty lines and comments (lines starting with two slashes)
    if (line.size() == 0 || line.find("//") == 0) continue;

    // cout <<  line << endl;
    Monster *m = new Monster(line);

    _monsters.push_back(m);
  }
  
  file.close();
}

int MonsterList::count() {
  return _monsters.size();
}

void MonsterList::print() {
  for (int i = 0; i < count(); ++i) {
    _monsters[i]->print();
  }
}

int MonsterList::indexOfMostCaloricMonster()
{
  if (count() == 0) return -1;

  int result = 0;
  for (int i = 1; i < count(); ++i) {
    if (_monsters[i]->calories() > _monsters[result]->calories()) {
      result = i;
    }
  }

  return result;
}

void MonsterList::removeMostCaloricMonster()
{
   int index = indexOfMostCaloricMonster();
   if (index >= 0) {
      delete _monsters[index];
    _monsters.erase(_monsters.begin() + index);
  } 
}

void CheckForLeaks() {
  int constructorCallCount = Monster::constructorCallCount();
  int destructorCallCount = Monster::destructorCallCount();

  
  cout << "Monsters constructed: " << constructorCallCount << endl;
  cout << "Monsters destructed: " << destructorCallCount << endl;
  cout << "Monsters leaked: ";
  if (destructorCallCount < constructorCallCount) {
    cout << constructorCallCount - destructorCallCount << endl;
  } else if (destructorCallCount == constructorCallCount) {
    cout << "none";
  } else {
    cout << "Weird!" << destructorCallCount - constructorCallCount << " more monsters were destructed than were creaated.";
  }
  cout << endl;
}

void Test()
{
  MonsterList monsters("MonsterData.txt");
  monsters.removeMostCaloricMonster();
}


int main() {

  Test();
  
  CheckForLeaks();
}
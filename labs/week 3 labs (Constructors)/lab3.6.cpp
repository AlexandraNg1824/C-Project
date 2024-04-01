#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

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

class MonsterList {
public:
  MonsterList(string filename);

  int count();

  void print();

  int indexOfMostCaloricMonster();
  void removeMostCaloricMonster();

private:
  vector<Monster *> _monsters;

};

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
     if (_monsters.empty()) {
    return -1; // Return -1 if the vector is empty
  }

  int result = 0;
  for (int i = 1; i < count(); ++i) {
    if (_monsters[i]->calories() > _monsters[result]->calories()) {
      result = i;
    }
  }

  return result;
 // Implement this function to return the index, in _monsters, of the monster with the most calories.
 // If monsters is empty, return -1.
}

void MonsterList::removeMostCaloricMonster()
{
   int index = indexOfMostCaloricMonster();
   if (index >= 0) {
    delete _monsters[index];             // Delete the monster at the found index
    _monsters.erase(_monsters.begin() + index); // Remove the monster from the vector
  }
 // Implement this function to remove the monster, from _monsters, which has the most calories.
 // Hint: Use indexOfMostCaloricMonster in your implementation.
 // Hint: Use the erase vector method to remove an element from a vector.
 //  E.g. To remove the 3rd element you'd write code like: someVector.erase(someVector.begin() + 3);
}

int main() {

  MonsterList monsters("MonsterData.txt");

  monsters.removeMostCaloricMonster();
  
  cout << "Now contains " << monsters.count() << " monsters:\n";
  
  monsters.print();
}
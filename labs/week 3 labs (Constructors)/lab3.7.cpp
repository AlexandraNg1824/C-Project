#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

/*

main() declares a const Monster and a const MonsterList and prints them.

Creating and printing const objects is something we expect to work as it doesn't require
mutating the objects.

However, these classes have been sloppy about declaring non-mutating methods const.
This means you'll get compiler errors for non-const methods that are used on const objects.

Your job is to modify/fix Monster and MonsterList, by adding const to the appropriate methods, so that
the code compiles and runs.

*/

class Monster {
public:
  Monster(string str);

  string name() const { return _name; };
  int calories() const { return _calories; };
  char glyph() const { return _glyph; };

  void setName(string name) { _name = name; };
  void setCalories(int calories) { _calories = calories; };
  void setGlyph(char glyph) { _glyph = glyph; };

  void print()const;
  
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

void Monster::print() const
{
  cout << "name: " << this->_name << endl;
  cout << "glyph: " << this->_glyph << endl;
  cout << "calories: " << this->_calories << endl;
}

class MonsterList {
public:
  MonsterList(string filename);
  ~MonsterList();

  int count()const;

  void print()const;

  int indexOfMostCaloricMonster()const;
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

MonsterList::~MonsterList() {
  for (int i = 1; i < count(); ++i) {
    delete _monsters[i];
  }
}

int MonsterList::count() const{
  return _monsters.size();
}

void MonsterList::print() const{
  for (int i = 0; i < count(); ++i) {
    _monsters[i]->print();
  }
}

int MonsterList::indexOfMostCaloricMonster()const
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

int main() {
   
  // Do _not_ modify main. Fix Monster and MonsterList

  const Monster m("Godzilla g 1225");

  m.print();

  const MonsterList monsters("MonsterData.txt");
  
  cout << "MonsterList contains " << monsters.count() << " monsters:\n";
  
  monsters.print();
 
  cout << "Most caloric monster is at index: " << monsters.indexOfMostCaloricMonster() << endl;
}